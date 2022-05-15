#include "date.h"
#include "room.h"
#include "ticket.h"
#include "utilities.h"

#ifndef _EVENT_
#define EVENT_

class Event
{
private:
    char *m_name = nullptr;
    Room m_room;
    Date m_date;

public:
    Event() = default;

    Event(const Event &) = delete;
    Event &operator=(const Event &) = delete;

    ~Event();

    Event(char *name, Room *room, const Date &date);
    bool operator==(const Event &rhs);

    void setName(char *name);
    void setRoom(const Room &room);
    void setDate(const Date &date);

    char *getName() const;
    Room *getRoom();
    Date getDate() const;
};

#endif //_EVENT_