#include <iostream>
#include <vector>
using std::vector;

#ifndef _ROOM_
#define _ROOM_

#include "ticket.h"

class Room
{
private:
    int m_numberOfRoom;
    vector<Seat> m_seats;

    bool checkIfSeatIsValid(int row, int col);

public:
    Room();

    Room &operator=(const Room &);
    Room(const Room &);

    Room(int numberOfRoom, int rows, int cols, vector<Seat> seats);

    void reserveASeat(int numberOfSeat, int numberOfRow);
    void freeASeat(int numberOfSeat, int numberOfRow);
    void takeASeat(int numberOfSeat, int numberOfRow);

    int getNumberOfRoom() const;
    int getNumberOfSeats() const;
    int getNumberOfRows() const;
    int getNumberOfCols() const;

    int getNumberOfFreeTickets() const;
    int getNumberOfReservedTickets() const;
    int getNumberOfTakenTickets() const;

    vector<Seat> getSeats();

    void setNumberOfRoom(int number);

    friend std::ostream &operator<<(std::ostream &out, const Room &obj);
};

#endif //_ROOM_
