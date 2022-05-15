#include "ticketSeller.h"
#include "utilities.h"
#include <fstream>

void TicketSeller::loadFromFile(char *path) {}

TicketSeller::TicketSeller(vector<Room> given_rooms)
{
    m_rooms = given_rooms;
}

void TicketSeller::addEvent(Date &dateOfEvent, char *nameOfEvent, const Room &roomOfEvent)
{
    int roomTemp = 0;
    Date timeTemp;

    for (int i = 0; i < m_events.size(); i++)
    {
        roomTemp = m_events[i].getRoom().getNumberOfRoom();
        timeTemp = m_events[i].getDate();

        if (roomTemp == roomOfEvent.getNumberOfRoom() &&
            timeTemp == dateOfEvent)
        {
            std::cout << "This room is already taken\n";
            return;
        }
    }

    Event toPush(nameOfEvent, &roomOfEvent, dateOfEvent);
    m_events.push_back(toPush);
}

void TicketSeller::saveInFile(char *path)
{
    if (checkIfPathIsValid(path))
    {
        std::ofstream out(path, std::ios::out | std::ios::app);
        for (int i = 0; i < m_numberOfEvents; i++)
        {
            out << m_events[i];
        }
    }
    else
    {
        std::cout << "Invalid path\n";
    }
}

// print free seats, name of the event (not reserved, neither taken)
void TicketSeller::freeSeats(char *nameOfEvent, const Date &date)
{
    std::cout << "Free seats are: \n";
    Room tempRoom;
    for (size_t i = 0; i < m_events.size(); i++)
    {
        if (strCmp(m_events[i].getName(), nameOfEvent) == 0)
        {
            tempRoom = m_events[i].getRoom();
            for (int i = 0; i < tempRoom.getNumberOfSeats(); i++)
            {
                if (tempRoom.getSeats()[i].isSeatFree() && tempRoom.getSeats()[i].isSeatReserved())
                {
                    std::cout << tempRoom.getSeats()[i];
                }
            }
        }
    }
}

void TicketSeller::cancelReservation(/*some data*/) {}

void TicketSeller::reserveTicket(char *nameOfEvent, Date &dateOfEvent, int row,
                                 int col, char *password, const char *note = nullptr)
{
    Room tempRoom;
    for (size_t i = 0; i < m_events.size(); i++)
    {
        if (strCmp(m_events[i].getName(), nameOfEvent) == 0)
        {
            tempRoom = m_events[i].getRoom();
            for (int i = 0; i < tempRoom.getNumberOfSeats(); i++)
            {
                // TODO
                if (tempRoom.getSeats()[i].getRow() == row && tempRoom.getSeats()[i].getCol() == col)
                {
                    tempRoom.getSeats()[i].reserveSeat();
                    if (note)
                    {
                        // set seat as reserved
                        // create and push back ticket
                        // link event ticket and room
                    }
                    // create and push back ticket
                    std::cout << "Seat reserved";
                }
            }
        }
    }
}

// you can buy ticket only if tickets are not taken or reserved{}
// if seat is reserved - ask for a password
// mark as taken if password is correct
void TicketSeller::buyTicket(char *nameOfEvent, Date &dateOfEvent, int row, int seat, char *password = nullptr)
{
    Ticket *tempTicket = nullptr;

    for (int i = 0; i < m_tickets.size(); i++)
    {
        // evnt > staya > seat > ako e reserve ima tiket > seata go pravim na taken i iskam parola
    }

    for (int i = 0; i < m_events.size(); i++)
    {
        Room tempRoom;
        for (size_t i = 0; i < m_events.size(); i++)
        {
            if (strCmp(m_events[i].getName(), nameOfEvent) == 0)
            {
                tempRoom = m_events[i].getRoom();
                for (int i = 0; i < tempRoom.getNumberOfSeats(); i++)
                {
                    // TODO
                    if (tempRoom.getSeats()[i].getRow() == row && tempRoom.getSeats()[i].getCol() == col)
                    {
                        Seat *tempSeat = &tempRoom.getSeats()[i];
                        if (tempSeat->isSeatReserved())
                        {
                            // create and push back ticket
                            // mark as taken
                            //
                        }
                    }
                }
            }
        }
    }
}

// print all reserved, but not taken seats - printed in report-NAME_DATE.txt
// it can be name of event - print all dates of this event ???
// it can be date - print all events on this date
void TicketSeller::listOfReservations(char *input = nullptr)
{

    for (int i = 0; i < m_tickets.size(); i++)
    {
        // std::ofstream out(report - NAME_DATE.txt);...
        if (m_tickets[i].getSeat().isSeatReserved() && m_tickets[i].getSeat().isSeatFree())
        {
            // out << m_tickets[i].getSeat();
        }
    }
}

void TicketSeller::printBoughtTickets(int from, int to, int room) {}
void TicketSeller::printBoughtTickets(int from, int to, char *room) {}

void TicketSeller::printMostWatchedEvents() {}
void TicketSeller::downloadStatistic10Percent() {}

bool TicketSeller::isThereAlreadyEventInThisRoom()
{
}
Date TicketSeller::extractDate(char *input)
{
}
