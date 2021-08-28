#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//< -------------------------- DOMESTIC TICKETING STRUCTURE ---------------------->
struct domestic
{
    char code[20];
    char origin[20];
    char destination[20];
    char date[20];
    char fname[50];
    char lname[50];
    char email[100];
    unsigned long long int mobile;
};

//< -------------------------- INTERNATIONAL TICKETING STRUCTURE ---------------------->

struct international
{
    char code[20];
    char origin[20];
    char destination[20];
    char passport[20];
    char date[20];
    char fname[50];
    char lname[50];
    char nationality[20];
    char email[100];
    unsigned long long int mobile;
};

//< -------------------------- FUNCTIONS DECLARATION -------------------------->
void bookd();

void retrieved();

void displayd();

void canceld();

void booki();

void retrievei();

void displayi();

void canceli();

//< -------------------- MAIN FUNCTION -------------------->
int main()
{
    system("COLOR 06");

    int choiced, choicei, trip;

    system("cls");

retry:
    printf("\n\n\t\t ********************************************************************");
    printf("\n\t\t                       WELCOME TO DEV AIRLINES                   ");
    printf("\n\t\t ********************************************************************");
    printf("\n\t\tPress ANY key to continue....... ");
    getch();
    system("cls");

    char login[50];

    printf("\n\n\t\t ********************************************************************");
    printf("\n\t\t                       WELCOME TO DEV AIRLINES                   ");
    printf("\n\t\t ********************************************************************");
    printf("\n\t\tEnter User ID: ");

    // >>>>>>>>>>>>>>>>>>>>>>>>>>  USER ID: devairlines@gmail.com
    scanf("%s", login);

    char password[128], c;
    int index = 0;

    //>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  PASSWORD: 12345678
    printf("\n\t\tEnter Password : ");
    // 13 is ASCII value of Enter key
    while ((c = getch()) != 13)
    {
        if (index < 0)
            index = 0;
        // 8 is ASCII value of BACKSPACE character
        if (c == 8)
        {
            putch('\b');
            putch('\b');
            index--;
            continue;
        }
        password[index++] = c;
        putch('*');
    }
    password[index] = '\0';

    if (strcmp(login, "devairlines@gmail.com") == 0 && strcmp(password, "12345678") == 0)
    {
        system("cls");
    start:

        printf("\n\n\t\t ********************************************************************");
        printf("\n\t\t                       WELCOME TO DEV AIRLINES                   ");
        printf("\n\t\t ********************************************************************");
        printf("\n\t\tPress 1 for Domestic Flights.\n");
        printf("\t\tPress 2 for International Flights.\n");
        printf("\t\tPress 0 to EXIT.\n\n\n\t\t");
        printf("ENTER YOUR CHOICE:  ");

        scanf("%d", &trip);
        system("cls");

        //DOMESTIC SECTION
        if (trip == 1)
        {
            do
            {
                printf("\n\n\t\t ********************************************************************");
                printf("\n\t\t                       WELCOME TO DEV AIRLINES(DOMESTIC)                   ");
                printf("\n\t\t ********************************************************************");
                printf("\n\n\n\t\t Please enter your choice from below (1-4):");
                printf("\n\n\t\t 1. BOOK TICKET");
                printf("\n\n\t\t 2. RETRIEVE ITINERARY");
                printf("\n\n\t\t 3. DISPLAY RECORDS");
                printf("\n\n\t\t 4. CANCEL ITINERARY");
                printf("\n\n\t\t 5. RETURN TO MAIN MENU");
                printf("\n\n\t\t 0. EXIT");
                printf("\n\n\t\t Enter your choice: ");

                scanf("%d", &choiced);
                system("cls");

                switch (choiced)
                {
                case 1:
                    bookd();
                    break;

                case 2:
                    retrieved();
                    break;

                case 3:
                    displayd();
                    break;

                case 4:
                    canceld();
                    break;

                case 5:
                    goto start;

                case 0:
                    exit(0);
                    break;

                default:
                    printf("\n\n\t SORRY INVALID CHOICE!");
                    printf("\n\n\t PLEASE CHOOSE FROM 1-4");
                }

            } while (choiced != 0);
        }
        //INTERNATIONAL SECTION
        else if (trip == 2)
        {
            do
            {
                printf("\n\n\t\t ********************************************************************");
                printf("\n\t\t                       WELCOME TO DEV AIRLINES(INTERNATIONAL)                   ");
                printf("\n\t\t ********************************************************************");
                printf("\n\n\n\t\t Please enter your choice from below (1-4):");
                printf("\n\n\t\t 1. BOOK TICKET");
                printf("\n\n\t\t 2. RETRIEVE ITINERARY");
                printf("\n\n\t\t 3. DISPLAY RECORDS");
                printf("\n\n\t\t 4. CANCEL ITINERARY");
                printf("\n\n\t\t 5. RETURN TO MAIN MENU");

                printf("\n\n\t\t 0. EXIT");
                printf("\n\n\t\t Enter your choice: ");

                scanf("%d", &choicei);
                system("cls");

                switch (choicei)
                {
                case 1:
                    booki();
                    break;

                case 2:
                    retrievei();
                    break;

                case 3:
                    displayi();
                    break;

                case 4:
                    canceli();
                    break;

                case 5:
                    goto start;

                case 0:
                    exit(0);
                    break;

                default:
                    printf("\n\n\t SORRY INVALID CHOICE!");
                    printf("\n\n\t PLEASE CHOOSE FROM 1-4");
                }

            } while (choicei != 0);
        }

        //EXIT
        else
        {
            exit(0);
        }
    }
    // >>>>>>>>>> IF AUTHENTICATION ERROR OCCURS.
    else
    {
        printf("\n\t\tInvalid Login ID or Password!!\n");
        printf("\n\t\tPlease Try Again!\n");
        getch();
        system("cls");
        goto retry;
    }
}

//<-----------------------FUNCTIONS DEFINITION ------------------>

//**********************************DOMESTIC FUNCTIONS*****************************

// <-----------------------For booking a domestic flight ticket--------------------------->
void bookd()
{
    system("COLOR 06");

    FILE *fpd;
    struct domestic a;

    printf("Enter Ticket Code:  ");
    scanf("%s", &a.code);
    system("cls");

    printf("Enter Passenger's Mobile Number:  ");
    scanf("%llu", &a.mobile);
    system("cls");

    printf("Ticket FROM (Origin):  ");
    scanf("%s", &a.origin);
    system("cls");

    printf("TO (Destination):  ");
    scanf("%s", &a.destination);
    system("cls");

    printf("Enter the Date:  ");
    scanf("%s", &a.date);
    system("cls");

    printf("Enter Passenger's First Name:  ");
    scanf("%s", a.fname);
    printf("Enter Passenger's Last Name:  ");
    scanf("%s", a.lname);
    system("cls");

    printf("Enter e-mail address:  ");
    scanf("%s", &a.email);
    system("cls");

    fpd = fopen("domestic.txt", "a");

    if (fpd == NULL)
    {
        printf("FILE NOT FOUND\n");
    }
    else
    {
        fprintf(fpd, "%s %llu %s %s %s %s %s %s\n", a.code, a.mobile, a.origin, a.destination, a.date, a.fname, a.lname, a.email);
        printf("CONGRATULATIONS! BOOKING SUCCESSFUL\n");
        printf("Ticket Code: %s\n", a.code);
        printf("Passenger's Name: %s %s\n", a.fname, a.lname);
        printf("From: %s\t\t", a.origin);
        printf("To: %s\n", a.destination);
        printf("Date of travel: %s\n", a.date);
        printf("Contact Details:\n Mobile No: %llu\n", a.mobile);
        printf("E-mail Address: %s\n", a.email);
        printf("\n\nPress any key to continue....\n");
        getch();
        system("cls");
    }

    fclose(fpd);
}

// <-----------------------For retreiving a domestic flight ticket ------------------------>
void retrieved()
{
    system("COLOR 06");

    struct domestic a;
    FILE *fpd;

    char ch[5];
    printf("Enter Ticket Code: ");
    scanf("%s", ch);

    fpd = fopen("domestic.txt", "r");
    if (fpd == NULL)
    {
        printf("NO SUCH TICKET PRESENT TO RETRIEVE.\n");
        // exit(1);
    }
    else
    {
        while (getc(fpd) != EOF)
        {
            fscanf(fpd, "%s %llu %s %s %s %s %s %s", a.code, &a.mobile, a.origin, a.destination, a.date, a.fname, a.lname, a.email);
            if (strcmp(a.code, ch) == 0)
            {
                printf("RECORD FOUND!!\n\n");
                printf("Ticket Code: %s\n", a.code);
                printf("Passenger's Name: %s %s\n", a.fname, a.lname);
                printf("From: %s\t\t", a.origin);
                printf("To: %s\n", a.destination);
                printf("Date of travel: %s\n", a.date);
                printf("Contact Details:\n Mobile No: %llu\n", a.mobile);
                printf("E-mail Address: %s\n", a.email);
                printf("\n\nPress any key to continue....\n");
                getch();
                system("cls");

                break;
            }
        }
        if (strcmp(a.code, ch) != 0)
        {
            printf("No such booking available to retreive.\n");
            printf("\n\nPress any key to try again....\n");
            getch();
            system("cls");
        }
    }

    fclose(fpd);
}

// <---------------------- For displaying the records of the domestic flights--------------------------->
void displayd()
{
    system("COLOR 06");

    char ch;
    FILE *fpd;

    fpd = fopen("domestic.txt", "r");

    if (fpd == NULL)
    {
        printf("Not found !");
        printf("\n\nPress any key to continue....\n");
        getch();
        system("cls");

        exit(1);
    }
    else
    {
        while ((ch = fgetc(fpd)) != EOF)
            printf("%c", ch);

        printf("\n\nPress any key to continue....\n");
        getch();
        system("cls");
    }
    fclose(fpd);
}

// <-----------------------For cancelling an Domestic ticket ---------------------->
void canceld()
{
    system("COLOR 06");

    FILE *fpd, *fpd1;
    char def[] = "domestic.txt";
    int delete_line, temp = 1;

    char user_name[100];
    printf("Enter user name: ");

    // >>>>>>>>>>>>>>>>>>>>>>>>>>>>  USERNAME: dev_airlines
    scanf("%s", user_name);

    char password[128], c;
    int index = 0;

    // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  PASSWORD: domestic.txt
    printf("Enter Password : ");
    /* 13 is ASCII value of Enter key */
    while ((c = getch()) != 13)
    {
        if (index < 0)
            index = 0;
        /* 8 is ASCII value of BACKSPACE character */
        if (c == 8)
        {
            putch('\b');
            // putch(NULL);
            putch('\b');
            index--;
            continue;
        }
        password[index++] = c;
        putch('*');
    }
    password[index] = '\0';

    fpd = fopen(password, "a+");

    if (strcmp(password, def) == 0 && strcmp(user_name, "dev_airlines") == 0)
    {
        system("cls");
        char ch;
        ch = getc(fpd);
        while (ch != EOF)
        {
            printf("%c", ch);
            ch = getc(fpd);
        }

        rewind(fpd);
        printf("\n\n ----> Once entered you will not be able to retreive that ticket.<----\n");
        printf("\n\nEnter the ticket number to be cancelled: ");
        scanf("%d", &delete_line);
        delete_line++;
        system("cls");

        fpd1 = fopen("temp.txt", "a+");

        ch = 'A';
        while (ch != EOF)
        {
            ch = getc(fpd);
            if (temp != delete_line)
            {
                putc(ch, fpd1);
            }
            if (ch == '\n')
            {
                temp++;
            }
        }
        fclose(fpd);
        fclose(fpd1);
        remove(password);
        rename("temp.txt", password);

        printf("Ticket Cancelled Successfully!\n");
        printf("Refund will be transfered in your agents account.\n");
        printf("\n\nPress ENTER to return to main menu.\n");
        getch();
    }

    // >>>>>>>>>>>>>> AUTHENTICATION ERROR
    else
    {
        printf("\n\n\nInvalid User ID!\n");
        printf("Enter the correct User ID and try again.\n");
        getch();
    }
}

//************************************INTERNATIONAL FUNCTIONS*********************************

//< --------------------For booking an International flight ticket-------------------->
void booki()
{
    system("COLOR 06");

    FILE *fpi;
    struct international b;

    printf("Enter Ticket Code:  ");
    scanf("%s", &b.code);
    system("cls");

    printf("Enter Passenger's Mobile Number:  ");
    scanf("%llu", &b.mobile);
    system("cls");

    printf("Ticket FROM (Origin):  ");
    scanf("%s", &b.origin);
    system("cls");

    printf("TO (Destination):  ");
    scanf("%s", &b.destination);
    system("cls");

    printf("Enter the Date:  ");
    scanf("%s", &b.date);
    system("cls");

    printf("Enter Passenger's First Name:  ");
    scanf("%s", b.fname);
    printf("Enter Passenger's Last Name:  ");
    scanf("%s", b.lname);
    system("cls");

    printf("Enter Passport No:  ");
    scanf("%s", b.passport);
    system("cls");

    printf("Enter Nationality:  ");
    scanf("%s", b.nationality);
    system("cls");

    printf("Enter e-mail address:  ");
    scanf("%s", &b.email);
    system("cls");

    fpi = fopen("international.txt", "a");

    if (fpi == NULL)
    {
        printf("FILE NOT FOUND\n");
    }
    else
    {
        fprintf(fpi, "%s %llu %s %s %s %s %s %s %s %s\n", b.code, b.mobile, b.origin, b.destination, b.date, b.fname, b.lname, b.email, b.passport, b.nationality);
        printf("CONGRATULATIONS! BOOKING SUCCESSFUL\n");
        printf("Ticket Code: %s\n", b.code);
        printf("Passenger's Name: %s %s\n", b.fname, b.lname);
        printf("From: %s\t\t", b.origin);
        printf("To: %s\n", b.destination);
        printf("Date of travel: %s\n", b.date);
        printf("Passport No: %s\n", b.passport);
        printf("Nationality: %s\n", b.nationality);
        printf("Contact Details:\n Mobile No: %llu\n", b.mobile);
        printf("E-mail Address: %s\n", b.email);
        printf("\n\nPress any key to continue....\n");
        getch();
        system("cls");
    }

    fclose(fpi);
}

//< --------------------For retrieving an International flight ticket-------------------->
void retrievei()
{
    system("COLOR 06");

    struct international b;
    FILE *fpi;

    char chi[5];
    printf("Enter Ticket Code: ");
    scanf("%s", chi);

    fpi = fopen("international.txt", "r");
    if (fpi == NULL)
    {
        printf("NO SUCH TICKET PRESENT TO RETRIEVE.\n");
        // exit(1);
    }
    else
    {
        while (getc(fpi) != EOF)
        {
            fscanf(fpi, "%s %llu %s %s %s %s %s %s %s %s", b.code, &b.mobile, b.origin, b.destination, b.date, b.fname, b.lname, b.email, b.passport, b.nationality);
            if (strcmp(b.code, chi) == 0)
            {
                printf("RECORD FOUND!!\n\n");
                printf("Ticket Code: %s\n", b.code);
                printf("Passenger's Name: %s %s\n", b.fname, b.lname);
                printf("From: %s\t\t", b.origin);
                printf("To: %s\n", b.destination);
                printf("Date of travel: %s\n", b.date);
                printf("Passport No: %s\n", b.passport);
                printf("Nationality: %s\n", b.nationality);
                printf("Contact Details:\n Mobile No: %llu\n", b.mobile);
                printf("E-mail Address: %s\n", b.email);
                printf("\n\nPress any key to continue....\n");
                getch();
                system("cls");

                break;
            }
        }
        if (strcmp(b.code, chi) != 0)
        {
            printf("No such booking available to retreive.\n");
            printf("\n\nPress any key to try again....\n");
            getch();
            system("cls");
        }
    }

    fclose(fpi);
}

//< --------------------For displaying the record of International Flights-------------------->
void displayi()
{
    system("COLOR 06");

    char chi;
    FILE *fpi;

    fpi = fopen("international.txt", "r");

    if (fpi == NULL)
    {
        printf("Not found !");
        printf("\n\nPress any key to continue....\n");
        getch();
        system("cls");

        exit(1);
    }
    else
    {
        while ((chi = fgetc(fpi)) != EOF)
            printf("%c", chi);

        printf("\n\nPress any key to continue....\n");
        getch();
        system("cls");
    }
    fclose(fpi);
}

//< --------------------For cancelling an International ticket.-------------------->
void canceli()
{
    system("COLOR 06");

    FILE *fpi, *fpi1;
    char def[] = "international.txt";
    int delete_line, tempi = 1;

    char user_name[100];
    printf("Enter user name: ");

    // >>>>>>>>>>>>>>>>>>>>>>>>>>>> USERNAME: dev_airlines
    scanf("%s", user_name);

    char password[128], c;
    int index = 0;

    // >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>  PASSWORD: international.txt
    printf("Enter Password : ");
    /* 13 is ASCII value of Enter key */
    while ((c = getch()) != 13)
    {
        if (index < 0)
            index = 0;
        /* 8 is ASCII value of BACKSPACE character */
        if (c == 8)
        {
            putch('\b');
            // putch(NULL);
            putch('\b');
            index--;
            continue;
        }
        password[index++] = c;
        putch('*');
    }
    password[index] = '\0';

    fpi = fopen(password, "a+");

    if (strcmp(password, def) == 0 && strcmp(user_name, "dev_airlines") == 0)
    {
        system("cls");
        char ch;
        ch = getc(fpi);
        while (ch != EOF)
        {
            printf("%c", ch);
            ch = getc(fpi);
        }

        rewind(fpi);
        printf("\n\n ----> Once entered you will not be able to retreive that ticket.<----\n");
        printf("Enter the ticket number to be cancelled: ");
        scanf("%d", &delete_line);
        delete_line++;
        system("cls");

        fpi1 = fopen("tempi.txt", "a+");

        ch = 'A';
        while (ch != EOF)
        {
            ch = getc(fpi);
            if (tempi != delete_line)
            {
                putc(ch, fpi1);
            }
            if (ch == '\n')
            {
                tempi++;
            }
        }
        fclose(fpi);
        fclose(fpi1);
        remove(password);
        rename("tempi.txt", password);

        printf("Ticket Cancelled Successfully!\n");
        printf("Refund will be transfered in your agents account.\n");
        printf("\n\nPress ENTER to return to main menu.\n");

        getch();
    }

    // >>>>>>>>>>>>>>>>>>  AUTHENTICATION ERROR
    else
    {
        printf("\n\n\nInvalid User ID!\n");
        printf("Enter the correct User ID and try again.\n");
        getch();
    }
}
// <-----------------------------------//-- END OF CODE --//------------------------------>
