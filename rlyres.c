#include<stdio.h>
#include "conio2.h"
#include "rlyres.h"
#include<ctype.h>
#include<windows.h>
#include<string.h>

int enterchoice()
{
    int choice,i;
    clrscr();
textcolor(YELLOW);
    gotoxy(28,1);
    printf("WELCOME TO RAILWAY RESERVATION SYSTEM\n");
    for(i=0;i<80;i++)
     {
          printf("-");
     }
        printf("\nSelect an option");
        printf("\n1-View Trains");
        printf("\n2-Book Ticket");
        printf("\n3-View Ticket");
        printf("\n4-Search Ticket no.");
        printf("\n5-View all bookings");
        printf("\n6-View Train Bookings");
        printf("\n7-Cancel Ticket");
        printf("\n8-Cancel Train");
        printf("\n9-Quit");
        printf("\n\nEnter choice:");
        scanf("%d",&choice);
        return choice;
        getch();
}
void add_trains()
{
    FILE*fp;
    fp=fopen("d:\\railway reservation system\\alltrains.txt","rb");
    if(fp==NULL)
    {   Train alltrains[3]=
    {
            {"2213","MAHAMANA EXPRESS","BPL","GWL",2100,1500},
            {"22164","MAHAMANA EXPRESS","BPL","DEL",3500,2240},
            {"22691","RAJDHANI EXPRESS","HBJ","AGR",1560,1135}
        };
         fp=fopen("d:\\railway reservation system\\alltrains.txt","wb");
        fwrite(alltrains,3*sizeof(Train),1,fp);
        printf("file saved successfully\n");
        fclose(fp);
    }
    else

    fclose(fp);

}
void view_trains()
{
    int i;
    clrscr();
    textcolor(YELLOW);
    printf("\nTRAIN NO.\tTRAIN NAME\tFROM\tTO\tFIRST AC FARE\tSECOND AC FARE\n");
    for(i=0;i<80;i++)
    printf("-");
    FILE*fp=fopen("d:\\railway reservation system\\alltrains.txt","rb");
    Train tr;
    while(fread(&tr,sizeof(tr),1,fp)==1)
        printf("\n%s\t%s\t%s\t%s\t%d\t\t%d",tr.train_no,tr.train_name,tr.from,tr.to,tr.fac_fare,tr.sac_fare);
    printf("\n\n\n\nPress any key to go back to the menu");
    fclose(fp);
    getch();
    clrscr();
}
int check_train_no(char*trainno)
{
    Train tr;
    FILE*fp= fopen("d:\\railway reservation system\\alltrains.txt","rb");
    while(fread(&tr,sizeof(tr),1,fp)==1)
    {
        if(strcmp(tr.train_no,trainno)==0)
        {
            fclose(fp);
            return 1;
        }
    }
    fclose(fp);
    return 0;
}
Passenger*get_passenger_details()
{
    clrscr();
    gotoxy(60,1);
    textcolor(LIGHTBLUE);
    printf("Press 0 to exit!");
    gotoxy(1,1);
    textcolor(YELLOW);
    static Passenger psn;
    printf("Enter passenger name:");
    fflush(stdin);
    fgets(psn.p_name,20,stdin);
    char*pos;
    pos=strchr(psn.p_name,'\n');
    *pos='\0';
    if(strcmp(psn.p_name,"0")==0)
    {
        textcolor(LIGHTRED);
        gotoxy(1,25);
        printf("RESERVATION CANCELLED!!");
        getch();
        textcolor(YELLOW);
        return NULL;
    }
    int valid;
    textcolor(YELLOW);
    printf("Enter gender(M/F):");
    do
    {
        valid=1;
        fflush(stdin);
        scanf("%c",&psn.gender);
        if(psn.gender=='0')
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("RESERVATION CANCELLED!!");
            getch();
            textcolor(YELLOW);
            return NULL;
        }
        if(psn.gender!='M'&&psn.gender!='F')
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Error!gender should be M or F(in uppercase):");
            valid=0;
            getch();
            gotoxy(19,2);
            printf("\t\t\t\t");
            gotoxy(19,2);

        }
    } while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t\t\t\t");

    gotoxy(1,3);
    textcolor(YELLOW);
    printf("Enter train number:");
    do
    {
        fflush(stdin);
        scanf("%s",psn.train_no);
        if(strcmp(psn.train_no,"0")==0)
        {

            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("RESERVATION CANCELLED!!");
            return NULL;
        }
        valid=check_train_no(psn.train_no);
        if(valid==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Error!!Invalid train number");
            getch();
            gotoxy(20,3);
            printf("\t\t\t\t\t\t\t");
            gotoxy(20,3);
        }
    } while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t");

    gotoxy(1,4);
    textcolor(YELLOW);
    printf("Enter traveling class(FIRST AC-F,SECOND AC-S):");
    do
    {
        valid=1;
        fflush(stdin);
        scanf("%c",&psn.p_class);
        if(psn.p_class=='0')
        {
             textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("RESERVATION CANCELLED!!");
            return NULL;
        }
        if(psn.p_class!='F'&&psn.p_class!='S')
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Error!!Traveling class should be F or S(in uppercase):");
            valid=0;
            getch();
            gotoxy(48,4);
            printf("\t\t\t\t");
            gotoxy(48,4);

        }
    }while(valid==0);
    gotoxy(1,25);
    printf("\t\t\t\t\t\t\t");

    gotoxy(1,5);
    textcolor(YELLOW);
    printf("Enter address:");
    fflush(stdin);
    fgets(psn.address,30,stdin);
    pos=strchr(psn.address,'\n');
    *pos='\0';
    if(strcmp(psn.address,"0")==0)
    {
        textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("RESERVATION CANCELLED!!");
            return NULL;
    }
    gotoxy(1,6);
    textcolor(YELLOW);
    printf("Enter age:");
    do
    {

        valid=1;
        fflush(stdin);
        scanf("%d",&psn.age);
        if(psn.age==0)
        {
             textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("RESERVATION CANCELLED!!");
            return NULL;
        }
        if(psn.age<=0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("Error!!Invalid age");
            valid=0;
            getch();
            gotoxy(11,6);
            printf("\t\t\t\t\t\t\t");
            gotoxy(11,6);
            textcolor(YELLOW);
        }
    }while(valid==0);
gotoxy(1,25);
printf("\t\t\t\t\t\t\t");

gotoxy(1,7);
textcolor(YELLOW);
printf("Enter mobile no.:");
do
{
    fflush(stdin);
    scanf("%s",psn.mob_no);
    if(strcmp(psn.mob_no,"0")==0)
    {
        textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("RESERVATION CANCELLED!!");
            getch();
            textcolor(YELLOW);
            return NULL;
    }
   valid=check_mob_no(psn.mob_no);
   if(valid==0)
   {
       textcolor(LIGHTRED);
       gotoxy(1,25);
       printf("\t\t\t\t\t\t\t\t");
       gotoxy(1,25);
       printf("Error!!invalid mobile number");
       getch();
       gotoxy(21,7);
       printf("\t\t\t\t\t\t\t");
       gotoxy(21,7);

   }
}while(valid==0);
gotoxy(1,25);
printf("\t\t\t\t\t\t\t\t\t");
gotoxy(1,10);
textcolor(LIGHTBLUE);
printf("PLEASE WAIT!TICKET BOOKING IS UNDER PROCESS");
getch();
return &psn;
}
int check_mob_no(char *p_mob)
{
    if(strlen(p_mob)!=10)
    return 0;
    while(*p_mob!='\0')
    {
        if(isdigit(*p_mob)==0)
            return 0;
        p_mob++;
    }
    return 1;
}
int book_ticket(Passenger p)
{
    int ticket_count=get_booked_ticket_count(p.train_no,p.p_class);
    if(ticket_count==30)
    {
        textcolor(LIGHTRED);
        printf("ALL SEATS IN TRAIN NO. %s and class %c ARE FULL!!",p.train_no,p.p_class);
        return -1;
    }
    int ticket_no=last_ticket_no()+1;
    p.ticketno=ticket_no;
    FILE*fp=("d:\\railway reservation system\\allbookings.txt","ab");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("SERVER DOWN PLEASE TRY AFTER SOME TIME!!");
        return -1;
    }
    fwrite(&p,sizeof(p),1,fp);
    fclose(fp);
    return ticket_no;
}

int get_booked_ticket_count(char* train_no,char c)
{
    Passenger pr;
    int count=0;
    FILE*fp=fopen("d:\\railway reservation system\\allbookings.txt","rb");
    if(fp==NULL)
    {
        return 0;
    }
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
     if(strcmp(pr.train_no,train_no)==0&&pr.p_class==c)
            count++;
    }
     fclose(fp);
    return count;
}
int last_ticket_no()
{
    Passenger pr;
    FILE*fp=fopen("d:\\railway reservation system\\allbookings.txt","rb");
    if(fp==NULL)
    {
        return 0;
    }
        fseek(fp,-1*sizeof(pr),SEEK_END);
        fread(&pr,sizeof(pr),1,fp);
        fclose (fp);
        return pr.ticketno;
}
int accept_ticket_no()
{
    gotoxy(55,1);
    textcolor(YELLOW);
    printf("PRESS 0 TO EXIT");
    gotoxy(1,1);
    textcolor(YELLOW);
    printf("Enter ticket no.:");
    int valid;
    int ticket_no;
    do
    {
        textcolor(YELLOW);
        scanf("%d",&ticket_no);
        valid=1;
        if(ticket_no==0)
        {
            textcolor(LIGHTRED);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("CANCELLING INPUT....");
            return 0;
        }
        if(ticket_no<0)
        {
            textcolor(YELLOW);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("ERROR!Ticket number should be positive");
            valid=0;
            getch();
            gotoxy(17,1);
            printf("\t\t\t");
            gotoxy(17,1);
        }
    }while(valid==0);
        return ticket_no;
        clrscr();
}
void view_ticket(int ticket_no)
{
    clrscr();
    FILE*fp=fopen("d:\\railway reservation system\\allbookings.txt","rb");
    FILE*fp1=fopen("d:\\railway reservation system\\alltrains.txt","rb");
    if(fp==NULL)
    {

        textcolor(LIGHTRED);
        printf("\nNO BOOKINGS DONE YET!");
        return;
    }
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNO TRAINS DONE YET");
        return;
    }
    Passenger pr;
    Train tr;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(ticket_no==pr.ticketno)
        {
            textcolor(YELLOW);
            printf("Details of ticket no.:");
            textcolor("WHITE");
            printf("%d\n",pr.ticketno);
            textcolor(YELLOW);
            printf("\nPassenger name:");
            textcolor(WHITE);
            printf("%s",pr.p_name);
            textcolor(YELLOW);
            printf("\nPassenger gender:");
            textcolor(WHITE);
            printf("%c",pr.gender);
            textcolor(YELLOW);
            printf("\nTrain no.:");
            textcolor(WHITE);
            printf("%s",pr.train_no);
            textcolor(YELLOW);
            printf("\nClass:");
            textcolor(WHITE);
            printf("%c",pr.p_class);
            textcolor(YELLOW);
            printf("Passenger's address:");
            textcolor(WHITE);
            printf("%s",pr.address);
            textcolor(YELLOW);
            printf("\nAge:");
            textcolor(WHITE);
            printf("%d",pr.age);
            textcolor(YELLOW);
            printf("\nPassenger's mobile no.:");
            textcolor("WHITE");
            printf("%s",pr.mob_no);
            textcolor(YELLOW);
            printf("\nTicket no.:");
            textcolor(WHITE);
            printf("%d",pr.ticketno);
            while(fread(&tr,sizeof(tr),1,fp1)==1)
            {
                if(strcmp(pr.train_no,tr.train_no)==0)
                {
                    textcolor(YELLOW);
                    printf("\nTrain no.:");
                    textcolor(WHITE);
                    printf("%s",tr.train_no);
                    textcolor(YELLOW);
                    printf("\nTRAIN NAME: ");
                    textcolor(WHITE);
                    printf("%s",tr.train_name);
                    textcolor(YELLOW);
                    printf("\nFrom:");
                    textcolor(WHITE);
                    printf("%s",tr.from);
                    textcolor(YELLOW);
                    printf("\nTo:");
                    textcolor(WHITE);
                    printf("%s",tr.to);
                    if(pr.p_class=='F')
                    {
                        textcolor(YELLOW);
                        printf("\nFare:");
                        textcolor("WHITE");
                        printf("%d",tr.fac_fare);
                    }
                    else
                    {
                        textcolor(YELLOW);
                        printf("\nFare:");
                        textcolor(WHITE);
                        printf("%d",tr.sac_fare);
                    }
                }
            }
             printf("\n\n");
                return;
        }
    }
    textcolor(LIGHTRED);
    printf("\nNo details of ticket no.:");
    textcolor(WHITE);
    printf("%d",ticket_no);
    textcolor(LIGHTRED);
    printf("FOUND!\n\n");
    fclose(fp);
}
char*accept_mob_no()
{
    static char mob_no[11];
    int valid;
    gotoxy(55,1);
    textcolor(LIGHTBLUE);
    printf("PRESS 0 TO EXIT!");
    gotoxy(1,1);
    textcolor(YELLOW);
    printf("\nEnter mobile no.:");
    do
    {
        textcolor(WHITE);
        fflush(stdin);
        scanf("%s",mob_no);
        if(strcmp(mob_no,"0")==0)
        {
            textcolor(WHITE);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("CANCELLING INPUT....");
            return NULL;
        }
        valid=check_mob_no(mob_no);
        if(valid==0)
        {
          textcolor(LIGHTRED);
          gotoxy(1,25);
          printf("\nERROR!INVALID MOBILE NO.");
          getch();
          gotoxy(21,1);
          printf("\t\t\t\t\t");
          gotoxy(21,1);
        }
    }while(valid==0);
    clrscr();
    return mob_no;

}
char*accept_train_no()
{
    static char train_no[10];
    int valid;
    gotoxy(60,1);
    textcolor(LIGHTBLUE);
    printf("PRESS 0 TO EXIT!");
    gotoxy(1,1);
    textcolor(YELLOW);
    printf("\nENTER TRAIN NO.:");
    do
    {
        fflush(stdin);
        scanf("%s",train_no);
        if(strcmp(train_no,"0")==0)
        {
             textcolor(WHITE);
            gotoxy(1,25);
            printf("\t\t\t\t\t\t\t");
            gotoxy(1,25);
            printf("CANCELLING INPUT....");
            return NULL;
        }
        valid=check_train_no(train_no);
        if(valid==0)
        {
             textcolor(LIGHTRED);
       gotoxy(1,25);
       printf("\t\t\t\t\t\t\t\t");
       printf("Error!!invalid train no.");
       getch();
       gotoxy(20,1);
       printf("\t\t\t\t\t\t\t");
       gotoxy(20,1);
       textcolor(YELLOW);
        }
    }while(valid==0);
    clrscr();
    return train_no;
}
void view_booking(char*train_no)
{
    int found=0;
    FILE*fp=fopen("d:\\railway reservation system\\allbookings.txt","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("SORRY!file cannot be opened.");
        return;
    }
    Passenger pr;
    printf("TICKET NO\tTRAIN NAME\t\tCLASS\tNAME\t\tGENDER\tAGE\tMOBILE NO\n");
    for(int i=0;i<80;i++)
    {
        printf("-");
    }
    int row=3;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.train_no,train_no)==0)
        {
            printf("%d\t\t%c\t%s",pr.ticketno,pr.p_class,pr.p_name);
            gotoxy(41,row++);
            printf("%c\t%d\t%s\n",pr.gender,pr.age,pr.mob_no);
            found=1;
        }
    }
       if(!found)
       {
           clrscr();
           textcolor(LIGHTRED);
           printf("\nNO DETAILS IN TRAIN NO %s NOT FOUND!",train_no);
           textcolor(YELLOW);
           printf("FOUND!");

       }
       textcolor(WHITE);
       printf("\n\nPRESS ANY KEY TO CONTINUE");
       fclose(fp);
       }

int cancel_ticket(int ticket_no)
{
    FILE*fp1=fopen("d:\\railway reservation system\\allbookings.txt","rb");
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNO BOOKINGS DONE YET!");
        return -1;
    }
    FILE*fp2=fopen("d:\\railway reservation system\\train.txt","wb");
    Passenger pr;
    int found=0;
    while(fread(&pr,sizeof(pr),1,fp1)==1)
    {
        if(pr.ticketno!=ticket_no)
        {
            fwrite(&pr,sizeof(pr),1,fp2);
        }
        else{
           found=1;
        }
    }
    fclose(fp1);
    fclose(fp2);
    if(found==0)
    {
        remove("d:\\railway reservation system\\train.txt");
    }
    else
    {
        remove("d:\\railway reservation system\\allbookings.txt");
        rename("d:\\railway reservation system\\train.txt","d:\\railway reservation system\\allbookings.txt");
    }
    return found;
    clrscr();
}
int*get_ticket_no(char*p_mob_no)
{
    int count=0;
    FILE*fp=fopen("d:\\railway reservation system\\allbookings.txt","rb");
    if(fp==NULL)
    {
        return NULL;
    }
    Passenger pr;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.mob_no,p_mob_no)==0)
        {
            ++count;
        }
    }
    if(count==0)
    {
        fclose(fp);
        return NULL;
    }
    rewind(fp);
    int*p=(int*) malloc((count+1)*sizeof(int));
    int i=0;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        if(strcmp(pr.mob_no,p_mob_no)==0)
        {
            *(p+i)=pr.ticketno;
            i++;
        }
    }
    *(p+i)=-1;
    fclose(fp);
    return p;
}
void view_all_tickets(char*pmob_no,int*pticket_no)
{
    if(pticket_no==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nSORRY!NO TICKETS BOOKED AGAINST MOBILE NO.:");
        textcolor(WHITE);
        printf("%s\n\n",pmob_no);
        return;
    }
    textcolor(YELLOW);
    printf("\nFOLLOWING TICKETS ARE BOOKED FOR MOBILE NO.");
    textcolor(WHITE);
    printf("%s",pmob_no);
    int i;
    textcolor(YELLOW);
    printf("\n\nTICKET NO.:\n");
    textcolor(WHITE);
    printf("-------------");
    textcolor(YELLOW);
    for(i=0;*(pticket_no+i)!=-1;i++)
    {
        printf("\n%d",*(pticket_no+i));
    }
    printf("\n\n");
    free(pticket_no);
}
void view_all_bookings()
{
    int i;
    FILE*fp=fopen("d:\\railway reservation system\\allbookings.txt","rb");
    if(fp==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNO BOOKINGS DONE YET!\n");
        return;
    }
    Passenger pr;
    textcolor(YELLOW);
    printf("TRAIN NO\tTICKET NO\tCLASS\tNAME\tAGE\tMOBILE NO\n");
    textcolor(WHITE);
    for(i=0;i<=80;i++)
    printf("-");
    int row=3;
    while(fread(&pr,sizeof(pr),1,fp)==1)
    {
        textcolor(WHITE);
        printf("%s\t\t%d\t\t%c\t%s",pr.train_no,pr.ticketno,pr.p_class,pr.p_name);
        gotoxy(57,row++);
        printf("%d\t%s\n",pr.age,pr.mob_no);
    }
    textcolor(YELLOW);
    for(i=0;i<=80;i++)

        printf("-");
        printf("\n");
        fclose(fp);
}
int cancel_train(char*train_no)
{
    FILE*fp1=fopen("d:\\railway reservation system\\allbookings.txt","rb");
    if(fp1==NULL)
    {
        textcolor(LIGHTRED);
        printf("\nNO TRAINS DONE YET");
        return -1;
    }
    FILE*fp2=fopen("d:\\railway reservation system\\alltrains.txt","wb+");
 Passenger pr;
 int found=0;
 while(fread(&pr,sizeof(pr),1,fp1)==1)
 {
     if(strcmp(pr.train_no,train_no)==0)
     {
         fwrite(&pr,sizeof(pr),1,fp2);
     }
     else
     {
         found=1;
     }
 }
 fclose(fp1);
 fclose(fp2);
 if(found==0)
 {
     remove("d:\\railway reservation system\\allbookings.txt");
     rename("d:\\railway reservation system\\alltrains.txt","d:\\railway reservation system\\allbookings.txt");
 }
 return found;
 clrscr();
}
