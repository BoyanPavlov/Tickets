#include "seat.h"

Seat::Seat(int numberOfSeat, bool isFree, bool isReserved)
    : m_numberOfSeat(numberOfSeat), m_isFree(isFree), m_isReserved(isReserved)
{
}

Seat::Seat(int numberOfSeat)
    : m_numberOfSeat(numberOfSeat), m_isFree(true), m_isReserved(false)
{
}

Seat::Seat()
    : m_numberOfSeat(-1), m_isFree(true), m_isReserved(false)
{
}

void Seat::setNumberOfASeat(int numberOfSeat)
{
    m_numberOfSeat = numberOfSeat;
}

void Seat::reserveSeat()
{
    m_isFree = false;
    m_isReserved = true;
}
void Seat::takeASeat()
{
    m_isFree = false;
    m_isReserved = true;
}
void Seat::freeASeat()
{
    m_isFree = true;
    m_isReserved = false;
}

bool Seat::operator==(const Seat &rhs)
{
    if (this->m_numberOfSeat == rhs.m_numberOfSeat)
    {
        return true;
    }
    return false;
}

int Seat::getNumberOfSeat() const
{
    return m_numberOfSeat;
}
bool Seat::isSeatFree() const
{
    return m_isFree;
}
bool Seat::isSeatReserved() const
{
    return m_isReserved;
}