#include <iostream>
#ifndef _SEAT_
#define _SEAT_

class Seat
{
private:
    int m_row;
    int m_col;
    bool m_isFree;
    bool m_isReserved;

public:
    Seat();

    Seat(int row, int mol, bool isFree, bool isReserved);

    bool operator==(const Seat &rhs);

    void reserveSeat();
    void takeASeat();
    void freeASeat();

    void setColOfASeat(int);
    void setRowOfASeat(int);

    int getColOfSeat() const;
    int getRowOfSeat() const;
    bool isSeatFree() const;
    bool isSeatReserved() const;

    friend std::ostream &operator<<(std::ostream &out, const Seat &obj);
};

#endif //_SEAT_