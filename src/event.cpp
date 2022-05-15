#include "event.h"

Event::Event(char *name, Room *room, const Date &date)
{
    m_date = date;
    strDub(m_name, name);
    m_room = room;
}

bool Event::operator==(const Event &rhs)
{
    bool flagName = !(strCmp(m_name, rhs.m_name));
    bool flagRoom = (m_room->getNumberOfRoom() == rhs.m_room->getNumberOfRoom());
    bool flagDate = (m_date == rhs.getDate());
    if (flagName && flagRoom && flagDate)
    {
        return true;
    }
    return false;
}

Event::~Event()
{
    clearString(m_name);
}

void Event::setName(char *name)
{
    clearString(m_name);
    strDub(m_name, name);
}

void Event::setRoom(Room *room)
{
    m_room = room;
}
void Event::setDate(const Date &date)
{
    m_date = date;
}

char *Event::getName() const
{
    return m_name;
}

Room *Event::getRoom()
{
    return m_room;
}

Date Event::getDate() const
{
    return m_date;
}

std::ostream &operator<<(std::ostream &out, Event &obj)
{
    out << obj.getName() << ' ' << *obj.getRoom() << '\n';
    return out;
}
