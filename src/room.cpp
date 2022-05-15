#include "room.h"
using std::cout;

Room::Room()
    : m_numberOfRoom(-1)
{
}

Room::Room(int numberOfRoom, int rows, int cols, vector<Seat> seats)
    : m_numberOfRoom(numberOfRoom)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            m_seats[i * rows + j].setRowOfASeat(i);
            m_seats[i * rows + j].setRowOfASeat(j);
        }
    }
}

bool Room::checkIfSeatIsValid(int row, int col)
{
    if (0 <= row && 0 <= col && row * col <= m_seats.size())
    {
        return true;
    }
    return false;
}

void Room::reserveASeat(int numberOfRow, int numberOfCol)
{
    if (checkIfSeatIsValid(numberOfRow, numberOfCol))
    {
        for (int i = 0; i < m_seats.size(); i++)
        {
            if (m_seats[i].getColOfSeat() == numberOfCol &&
                m_seats[i].getRowOfSeat() == numberOfRow)
            {
                if (m_seats[i].isSeatFree() && !m_seats[i].isSeatReserved())
                {
                    m_seats[i].reserveSeat();
                    cout << "Seat at "<< numberOfRow << ' ' << numberOfCol << " reserved\n";
                }
                else
                {
                    cout << "Seat already taken ";
                }
            }
        }
    }
    else
    {
        cout << "invalid row or seat";
    }
}

void Room::freeASeat(int numberOfRow, int numberOfCol)
{
    if (checkIfSeatIsValid(numberOfRow, numberOfCol))
    {
        for (int i = 0; i < m_seats.size(); i++)
        {
            if (m_seats[i].getColOfSeat() == numberOfCol &&
                m_seats[i].getRowOfSeat() == numberOfRow)
            {
                m_seats[i].freeASeat();
            }
        }
    }
    else
    {
        std::cout << "invalid row or seat";
    }
}

void Room::takeASeat(int numberOfRow, int numberOfCol)
{

    if (checkIfSeatIsValid(numberOfRow, numberOfCol))
    {
        for (int i = 0; i < m_seats.size(); i++)
        {
            if (m_seats[i].getColOfSeat() == numberOfCol &&
                m_seats[i].getRowOfSeat() == numberOfRow)
            {
                m_seats[i].takeASeat();
            }
        }
    }
    else
    {
        std::cout << "invalid row or seat";
    }
}

int Room::getNumberOfRoom() const
{
    return m_numberOfRoom;
}
int Room::getNumberOfSeats() const
{
    return m_seats.size();
}

int Room::getNumberOfFreeTickets() const
{
    int count = 0;
    for (int i = 0; i < m_seats.size(); i++)
    {
        if (m_seats[i].isSeatFree() && !m_seats[i].isSeatReserved())
        {
            count++;
        }
    }
    return count;
}
int Room::getNumberOfReservedTickets() const
{
    int count = 0;
    for (int i = 0; i < m_seats.size(); i++)
    {
        if (m_seats[i].isSeatReserved() && m_seats[i].isSeatFree())
        {
            count++;
        }
    }
    return count;
}
int Room::getNumberOfTakenTickets() const
{
    int count = 0;
    for (int i = 0; i < m_seats.size(); i++)
    {
        if (!m_seats[i].isSeatFree())
        {
            count++;
        }
    }
    return count;
}
int Room::getNumberOfRows() const
{
    return m_seats.back().getRowOfSeat();
}

void Room::setNumberOfRoom(int number)
{
    m_numberOfRoom = number;
}

vector<Seat> Room::getSeats()
{
    return m_seats;
}

Room &Room::operator=(const Room &rhs)
{
    if (this != &rhs)
    {
        m_numberOfRoom = rhs.m_numberOfRoom;
        m_seats = rhs.m_seats;
    }
    return *this;
}

Room::Room(const Room &rhs)
{
    m_numberOfRoom = rhs.m_numberOfRoom;
    m_seats = rhs.m_seats;
}

std::ostream &operator<<(std::ostream &out, const Room &obj)
{
    out << obj.m_numberOfRoom << '\n';
    for (int i = 0; i < obj.m_seats.size(); i++)
    {
        out << obj.m_seats[i].getRowOfSeat() << ' ' << obj.m_seats[i].getColOfSeat() << "  ";
    }
}
