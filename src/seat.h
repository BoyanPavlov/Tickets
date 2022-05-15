#ifndef _SEAT_
#define _SEAT_

class Seat
{
private:
    int m_numberOfSeat;
    bool m_isFree;
    bool m_isReserved;

public:
    Seat();

    Seat(int numberOfSeat, bool isFree, bool isReserved);
    Seat(int numberOfSeat);

    bool operator==(const Seat &rhs);

    void reserveSeat();
    void takeASeat();
    void freeASeat();

    void setNumberOfASeat(int);
    
    int getNumberOfSeat() const;
    bool isSeatFree() const;
    bool isSeatReserved() const;
};

#endif //_SEAT_