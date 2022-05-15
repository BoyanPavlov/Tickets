#include "date.h"
#include "utilities.h"
#include "seat.h"
#ifndef _TICKET_
#define _TICKET_

class Ticket
{
private:
    char *m_nameOfEvent = nullptr;
    int m_roomNumber = -1;
    int m_row = -1;
    Seat m_seat;
    char *m_password = nullptr;
    Date m_date;

public:
    Ticket();

    Ticket(char *name, const Date &date, int row, const Seat &seat);
    Ticket(char *name, const Date &date, int row, const Seat &seat, char *password);

    Ticket(const Ticket &rhs);
    Ticket &operator=(const Ticket &rhs);

    ~Ticket();

    void reserveATicket(char *password);
    void FreeATicket();
    void TakeATicket();

    void setName(const char *nameOfEvent);
    void setDate(const Date &date);
    void setRow(const int row);
    void setSeat(const Seat &seat);
    void setPassword(const char *pass);
    void setRoom(int room);

    char *getName() const;
    const Date &getDate() const;
    int getRow() const;
    Seat &getSeat();
    char *getPassword() const;
};

#endif // _TICKET_