#include <stdio.h>
#include <stdlib.h>
#include "conio2.h"
#include "rlyres.h"
#include<string.h>
#include<windows.h>

int main()
{
   int choice,result,ch;
   Passenger*ptr;
   int ticket_no;
   char*pmob_no,ptrain_no;
   int*pticket_no;
   add_trains();
   char user[20];
   char pass[20];
   int i;
   new:
       gotoxy(25,4);
       textcolor(YELLOW);
       for(i=0;i<=36;i++)
       printf("-");
       gotoxy(25,5);
       textcolor(WHITE);
       printf("WELCOME TO RAILWAY RESERVATION SYSTEM");
       gotoxy(25,6);
       textcolor(YELLOW);
       for(i=0;i<=36;i++)
       printf("-");
       gotoxy(30,8);
       textcolor(LIGHTCYAN);
       printf("**********LOGIN**********");
       gotoxy(25,10);
       textcolor(YELLOW);
       printf("ENTER USERNAME: ");
       textcolor(WHITE);
       scanf("%s",user);
       gotoxy(25,11);
       textcolor(YELLOW);
       printf("ENTER PASSWORD: ");
       textcolor(WHITE);
       for(i=0;i<=10;i++)
       {
           pass[i]=getch();
           printf("*");
       }
       pass[i]='\0';
       getch();
       textcolor(WHITE);
       printf("\n\n\n\nVERIFICATION UNDER PROCESS.\nPLEASE WAIT!");
       sleep(10);
       if(strcmp(user,"jpragati05@gmail.com")==0&&strcmp(pass,"pragati@123")==0)
       {

       }
       else
       {
           clrscr();
           textcolor(LIGHTRED);
           printf("\n\n\nINCORRECT PASSWORD!");
           textcolor(WHITE);
           printf("\nPRESS ANY KEY TO CONTINUE!");
           getch();
           clrscr();
           goto new;
       }
       clrscr();
   while(1)
   {
       choice=enterchoice();
       if(choice==9)
        exit(0);
             switch(choice)
       {
       case 1:
            view_trains();
            clrscr();
            break;
       case 2:
        ptr=get_passenger_details();
if(ptr!=NULL)
        {
            ticket_no=book_ticket(* ptr);
            if(ticket_no==-1)
            {
                textcolor(LIGHTRED);
                printf("\n\nBOOKING FAILED!!");
            }
             else{
                 textcolor(WHITE);
                printf("TICKET SUCCESSFULLY BOOKED!\nYOUR TICKET NO. IS %d",ticket_no);
                getch();
             }

}
 textcolor(YELLOW);
            printf("PRESS ANY KEY TO GO BACK TO THE MAIN SCREEN!");
            getch();
            clrscr();
        break;
       case 3:
        clrscr();
        ticket_no=accept_ticket_no();
        if(ticket_no!=0)
        view_ticket(ticket_no);
        textcolor(YELLOW);
        printf("\n\nPRESS ANY KEY TO GO BACK TO THE MAIN SCREEN!");
        getch();
        clrscr();
        break;
       case 4:
        clrscr();
        pmob_no=accept_mob_no();
        if(pmob_no!=NULL)
        {
            pticket_no=get_ticket_no(pmob_no);
            view_all_tickets(pmob_no,pticket_no);
        }
        textcolor(WHITE);
        printf("\nPRESS ANY KEY TO GO TO THE MAIN SCREEN...");
        getch();
        clrscr();
        break;
       case 5:
       clrscr();
       view_all_bookings();
       textcolor(WHITE);
       printf("\nPRESS ANY KEY TO GO BACK TO THE MAIN SCREEN!");
       getch();
       clrscr();
        break;
       case 6:
       clrscr();
       ptrain_no=accept_train_no();
       if(ptrain_no!=0)
       {
         view_booking(ptrain_no);
       }
       textcolor(WHITE);
       printf("\nPRESS ANY KEY TO GO BACK TO THE MAIN SCREEN!");
       getch();
       clrscr();
        break;
       case 7:
        clrscr();
        ticket_no=accept_ticket_no();
        if(ticket_no!=0)
        {
            result=cancel_ticket(ticket_no);
            if(result==0)
            {
                textcolor(LIGHTRED);
                printf("SORRY!NO TICKETS BOOKED AGAINST TICKET NO. %d",ticket_no);
            }
            else if(result==1)
            {
                textcolor(WHITE);
                printf("TICKET NO. %d SUCCESSFULLY CANCELLED",pticket_no);
            }
        }
             textcolor(WHITE);
        printf("\n\n PRESS ANY KEY TO GO BACK!");
       getch();
       clrscr();
        break;
       case 8:
       clrscr();
       ptrain_no=accept_train_no();
       if(ptrain_no!=NULL)
       {
           result=cancel_train(ptrain_no);
           if(result==0)
           {
              textcolor(LIGHTRED);
              printf("\nSORRY!NO TRAINS AGAINST TRAIN NO. %s",ptrain_no);
           }
           else if(result==1)
           {
               textcolor(YELLOW);
               printf("\nTRAIN NO.:");
               textcolor(WHITE);
               printf("%s",ptrain_no);
               printf("SUCCESSFULLY CANCELLED...");
           }
       }
       textcolor(WHITE);
       printf("\nPRESS ANY KEY TO GO BACK TO THE MAIN SCREEN!");
       getch();
       clrscr();
       break;
       default:
        textcolor(LIGHTRED);
        printf("wrong choice!Try again\n");
        getch();
        clrscr();
       }
   }

        getch();
        return 0;

}
