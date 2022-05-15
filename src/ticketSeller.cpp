#include "ticketSeller.h"

void TicketSeller::loadFromFile(char *path) {}
void TicketSeller::saveInFile(char *path) {}
// adds event - if room is taken - do NOT add - throw exception or text

// Въвежда дата, име на представлението и зала и добавя ново представление
// с въведената информация.Ако в тази зала вече има друго представление на същата дата,
// добавянето да не се извършва и да се изведе грешка.

void TicketSeller::addEvent(Date &dateOfEvent, char *nameOfEvent, const Room &roomOfEvent)
{
    
}
// print free seats, name of the event (not reserved, neither taken)
void TicketSeller::freeSeats() {}
void TicketSeller::cancelReservation(/*some data*/) {}
void TicketSeller::reserveTicket(char *nameOfEvent, Date &dateOfEvent, int row, int seat, char *password) {}
void TicketSeller::reserveTicket(char *nameOfEvent, Date &dateOfEvent, int row, int seat, char *password, char *note) {}

// you can buy ticket only if tickets are not taken or reserved{}
// if seat is reserved - ask for a password
// mark as taken if password is correct
void TicketSeller::buyTicket(char *nameOfEvent, Date &dateOfEvent, int row, int seat) {}
// print all reserved, but not taken seats - printed in report-NAME_DATE.txt
// it can be name of event - print all dates of this event ???
// it can be date - print all events on this date
void TicketSeller::listOfReservations(char *input) {}

void TicketSeller::printBoughtTickets(int from, int to, int room) {}
void TicketSeller::printBoughtTickets(int from, int to, char *room) {}

void TicketSeller::printMostWatchedEvents() {}
void TicketSeller::downloadStatistic10Percent() {}

TicketSeller::~TicketSeller()
{
    delete[] m_events;
}

bool TicketSeller::isThereAlreadyEventInThisRoom()
{
}
Date TicketSeller::extractDate(char *input)
{
}
