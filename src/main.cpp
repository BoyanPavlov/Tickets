#include <iostream>
#include "ticketSeller.h"
#include "room.h"

int main()
{
    // Room(int numberOfRoom, int rows, int cols, vector<Seat> seats);
    // Seat(int row, int col)
    vector<Seat> seats;
    vector<Room> rooms;

    Seat s1_1(0, 1);
    seats.push_back(s1_1);
    Seat s1_2(0, 2);
    seats.push_back(s1_2);
    Seat s1_3(0, 3);
    seats.push_back(s1_3);

    Seat s2_1(1, 1);
    seats.push_back(s2_1);
    Seat s2_2(1, 2);
    seats.push_back(s2_2);
    Seat s2_3(1, 3);
    seats.push_back(s2_3);

    Room r1(200, 3, 2, seats);
    Room r2(100, 3, 2, seats);
    rooms.push_back(r1);
    rooms.push_back(r2);

    TicketSeller(rooms);

    return 0;
}
