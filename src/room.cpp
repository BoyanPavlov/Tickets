#include "room.h"

Room::Room(int numberOfRoom, int rows, int numberOfSeats, Ticket **tickets)
    : m_numberOfRoom(numberOfRoom), m_numberOfRows(rows),
      m_numberOfSeats(numberOfSeats),
      m_numberOfFreeTickets(numberOfSeats * rows),
      m_numberOfReserved(0), m_numberOfTakenTickets(0)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < numberOfSeats; j++)
        {
            m_tickets[i][j].setRow(i);
            m_tickets[i][j].setSeat(j);
        }
    }
}
Room::Room()
    : m_numberOfRoom(-1), m_numberOfSeats(-1), m_numberOfRows(-1),
      m_numberOfFreeTickets(-1), m_numberOfReserved(-1), m_numberOfTakenTickets(-1),
      m_tickets(nullptr)

{
}

Room::~Room()
{
    for (int i = 0; i < m_numberOfRows; i++)
    {
        delete[] m_tickets[i];
    }
    delete[] m_tickets;
}

bool Room::checkIfSeatIsValid(int row, Seat given_seat)
{
    if (checkIfRowIsValid(row))
    {
        if (0 < given_seat.getNumberOfSeat() &&
            given_seat.getNumberOfSeat() <= m_numberOfSeats)
        {
            return true;
        }
    }
    return false;
}

bool Room::checkIfRowIsValid(int row)
{
    if (m_numberOfRows < row || row < 0)
    {
        return false;
    }
    return true;
}

void Room::reserveASeat(int numberOfSeat, int numberOfRow)
{
    if (checkIfSeatIsValid(numberOfRow, numberOfSeat))
    {
        if (m_tickets[numberOfRow][numberOfSeat].getSeat().isSeatFree())
        {
            m_numberOfFreeTickets--;
            m_numberOfReserved++;

            m_tickets[numberOfRow][numberOfSeat].getSeat().setNumberOfASeat(numberOfSeat);
            m_tickets[numberOfRow][numberOfSeat].getSeat().reserveSeat();
        }
        else
        {
            std::cout << "seat already taken";
        }
    }
    else
    {
        std::cout << "invalid row or seat";
    }
}

void Room::freeASeat(int numberOfSeat, int numberOfRow)
{
    if (checkIfSeatIsValid(numberOfRow, numberOfSeat))
    {
        if (m_tickets[numberOfRow][numberOfSeat].getSeat().isSeatReserved())
        {
            m_numberOfReserved--;
        }
        if (!m_tickets[numberOfRow][numberOfSeat].getSeat().isSeatFree())
        {
            m_numberOfTakenTickets--;
        }
        m_numberOfFreeTickets++;
        m_tickets[numberOfRow][numberOfSeat].getSeat().freeASeat();
    }
    else
    {
        std::cout << "invalid row or seat";
    }
}

void Room::takeASeat(int numberOfSeat, int numberOfRow)
{
    if (checkIfSeatIsValid(numberOfRow, numberOfSeat))
    {
        if (m_tickets[numberOfRow][numberOfSeat].getSeat().isSeatFree())
        {
            m_numberOfFreeTickets--;
            m_numberOfTakenTickets++;
            m_tickets[numberOfRow][numberOfSeat].getSeat().takeASeat();
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
    return m_numberOfSeats;
}
int Room::getNumberOfFreeTickets() const
{
    return m_numberOfFreeTickets;
}
int Room::getNumberOfReservedTickets() const
{
    return m_numberOfReserved;
}
int Room::getNumberOfTakenTickets() const
{
    return m_numberOfTakenTickets;
}
int Room::getNumberOfRows() const
{
    return m_numberOfRows;
}

void Room::setNumberOfRoom(int number)
{
    m_numberOfRoom = number;
}

Ticket **Room::getTickets()
{
    return m_tickets;
}

Room &Room::operator=(const Room &rhs)
{
    if (this != &rhs)
    {
        m_numberOfRoom = rhs.m_numberOfRoom;
        m_numberOfRows = rhs.m_numberOfRows;
        m_numberOfSeats = rhs.m_numberOfSeats;

        m_numberOfFreeTickets = rhs.m_numberOfFreeTickets;
        m_numberOfReserved = rhs.m_numberOfReserved;
        m_numberOfTakenTickets = rhs.m_numberOfTakenTickets;

        ///////////////////////////
        // TODO
        try
        {
            m_tickets = new Ticket *[m_numberOfRows];
            for (int i = 0; i < m_numberOfRows; i++)
            {
                m_tickets[i] = new Ticket[m_numberOfSeats]();
            }
        }
        catch (const std::bad_alloc &e)
        {
            std::cerr << e.what() << '\n';

            delete[] m_tickets;
        }
        ///////////////////////////

        for (int i = 0; i < m_numberOfRows; i++)
        {
            for (int j = 0; j < m_numberOfSeats; j++)
            {
                m_tickets[i][j].setRow(i);
                m_tickets[i][j].getSeat().setNumberOfASeat(i);
                m_tickets[i][j].setRoom(rhs.m_numberOfRoom);
            }
        }
    }
    return *this;
}

Room::Room(const Room &rhs)
    : m_numberOfRoom(rhs.m_numberOfRoom),
      m_numberOfRows(rhs.m_numberOfRows),
      m_numberOfSeats(rhs.m_numberOfSeats),
      m_numberOfFreeTickets(rhs.m_numberOfFreeTickets),
      m_numberOfReserved(rhs.m_numberOfReserved),
      m_numberOfTakenTickets(rhs.m_numberOfTakenTickets)
{

    ///////////////////////////
    // TODO
    try
    {
        m_tickets = new Ticket *[m_numberOfRows];
        for (int i = 0; i < m_numberOfRows; i++)
        {
            m_tickets[i] = new Ticket[m_numberOfSeats]();
        }
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << e.what() << '\n';

        delete[] m_tickets;
    }
    ///////////////////////////

    for (int i = 0; i < m_numberOfRows; i++)
    {
        for (int j = 0; j < m_numberOfSeats; j++)
        {
            m_tickets[i][j].setRow(i);
            m_tickets[i][j].getSeat().setNumberOfASeat(i);
            m_tickets[i][j].setRoom(rhs.m_numberOfRoom);
        }
    }
}
