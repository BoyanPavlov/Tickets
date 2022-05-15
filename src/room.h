#include <iostream>
#ifndef _ROOM_
#define _ROOM_

#include "ticket.h"

class Room
{
private:
    int m_numberOfRoom;
    int m_numberOfSeats;
    int m_numberOfRows;
    Ticket **m_tickets;

    int m_numberOfFreeTickets;
    int m_numberOfReserved;
    int m_numberOfTakenTickets;

    bool checkIfSeatIsValid(int row, Seat given_seat);
    bool checkIfRowIsValid(int row);

public:
    Room();

    Room &operator=(const Room &);
    Room(const Room &);

    Room(int numberOfRoom, int rows, int numberOfSeats, Ticket **tickets);
    ~Room();

    void reserveASeat(int numberOfSeat, int numberOfRow);
    void freeASeat(int numberOfSeat, int numberOfRow);
    void takeASeat(int numberOfSeat, int numberOfRow);

    int getNumberOfRoom() const;
    int getNumberOfSeats() const;
    int getNumberOfRows() const;
    int getNumberOfFreeTickets() const;
    int getNumberOfReservedTickets() const;
    int getNumberOfTakenTickets() const;
    Ticket **getTickets();

    void setNumberOfRoom(int number);
};

#endif //_ROOM_
