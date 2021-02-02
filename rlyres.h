#ifndef RLYRES_H_INCLUDED
#define RLYRES_H_INCLUDED
struct Train
{
    char train_no[10];
    char train_name[20];
    char from[10];
    char to[10];
    int fac_fare;
    int sac_fare;
};
struct Passenger
{
    char p_name[20];
    char gender;
    char train_no[10];
    char p_class;
    char address[30];
    int age;
    int ticketno;
    char mob_no[11];
};
struct login
{
    char user[20];
    char pass[20];
    char fname[20];
    char lname[20];
};
typedef struct Train Train;
typedef struct Passenger Passenger;
int enterchoice();
void add_trains();
void view_trains();
void reg();
void login();
int book_ticket(Passenger);
int *get_ticket_no(char*);
void view_ticket(int);
void view_all_bookings();
void view_booking(char*);
int cancel_ticket(int);
int cancel_train(char*);
Passenger *get_passenger_details();
int check_train_no(char*);
int get_booked_ticket_count(char*,char);
int last_ticket_no();
int check_mob_no(char*);
void view_all_tickets(char*,int*);
char*accept_train_no();
int accept_ticket_no();
char*accept_mob_no();

#endif // RLYRES_H_INCLUDED
