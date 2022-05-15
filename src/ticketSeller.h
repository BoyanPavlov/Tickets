#ifndef _TICKETSELLER_
#define _TICKETSELLER_
#include "event.h"
#include "date.h"
#include "room.h"
#include <vector>
using std::vector;

struct eventLinker
{
    char *nameOfEvent;
    int numberOfRoom;
};

class TicketSeller
{
private:
    int m_numberOfEvents = 0;

    vector<eventLinker> m_linked_events_and_rooms;

    vector<Event> m_events;
    vector<Room> m_rooms;
    vector<Ticket> m_tickets;

    int allTickets;

    bool isThereAlreadyEventInThisRoom();
    Date extractDate(char *input);

public:
    TicketSeller();

    TicketSeller(vector<Room> given_rooms);

    void loadFromFile(char *path);
    void saveInFile(char *path);

    /// adds event - if room is taken - do NOT
    void addEvent(Date &dateOfEvent, char *nameOfEvent, const Room &roomOfEvent);

    // print free seats, name of the event (not reserved, neither taken)
    void freeSeats(char *nameOfEvent, const Date &date);
    void cancelReservation(/*some data*/);
    void reserveTicket(char *nameOfEvent, Date &dateOfEvent, int row,
                       int seat, char *password, const char *note = nullptr);

    // you can buy ticket only if tickets are not taken or reserved;
    // if seat is reserved - ask for a password
    // mark as taken if password is correct
    void buyTicket(char *nameOfEvent, Date &dateOfEvent, int row, int seat, char *password = nullptr);
    // print all reserved, but not taken seats - printed in report-NAME_DATE.txt
    // it can be name of event - print all dates of this event ???
    // it can be date - print all events on this date
    void listOfReservations(char *input = nullptr);

    void printBoughtTickets(int from, int to, int room);
    void printBoughtTickets(int from, int to, char *room);

    void printMostWatchedEvents();
    void downloadStatistic10Percent();
};

#endif //_TICKETSELLER_