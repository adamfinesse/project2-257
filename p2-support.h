// P2 support file that defines infrastucture of the E-mail client.
#define MAILBOX_SIZE 2000
#define ADRESS_SIZE 20
#define SUBJECT_SIZE 200
#define BODY_SIZE 2000
#define NAME_SIZE 20
#define user_email "harmsad@vcu.edu"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//add other define Macro as needed

struct Email
{ char sender[ADRESS_SIZE];
char receiver[ADRESS_SIZE];
char subject[SUBJECT_SIZE];
char body[BODY_SIZE];
int ID;
//add other struct member as needed
//consider adding a nested struct here
	struct sent_date{
	int month;
	int day;
	int year;
	}sent;
};
struct Mailbox
{
	int size;
	struct Email* emails;
	//add other struct members as needed
};
	
/////////////////////////////////////////////////////////////////////
//This is a sample comment for the initalize fuction
//You should include a similar comment for each function declared within the .h file
//
//Function: initalize
//Description: Initializes the database for CMSC257 project #2 by manually entering
//the records using create_email function
//Inputs: struct Mailbox* - pointer to the database
//Outputs: void
void initalize(struct Mailbox *ib);
//////////////////////////////////////////////////////////
//Function: mainMenu
//Description: Displays the mainmenu options for the mailbox.
//Inputs: struct Mailbox* - pointer to the database
//Outputs: void
void mainMenu(struct Mailbox *ib);
//////////////////////////////////////////////////////////
//Function: showInbox
//Description: Displays the inbox of the users Mailbox showing the sender, reciever, subject, date received, and body.
//Inputs: struct Mailbox* - pointer to the database
//Outputs: void
void showInbox(struct Mailbox *ib);
//////////////////////////////////////////////////////////
//Function: showEmailByID
//Description: Displays the email that is associated with the given ID
//Inputs: struct Mailbox* - pointer to the database, int ID - id of the email to search for
//Outputs: void
void showEmailByID(struct Mailbox* ib, int id);
//////////////////////////////////////////////////////////
//Function: sortEmailsBySender
//Description: sorts the Inbox alphabetically
//Inputs: struct Mailbox* - pointer to the database
//Outputs: void
void sortEmailsBySender(struct Mailbox *ib);
//////////////////////////////////////////////////////////
//Function: deleteByID
//Description: deletes the email that is associated with the given ID
//Inputs: struct Mailbox* - pointer to the database, int ID - id of the email to search for
//Outputs: void
void deleteByID(struct Mailbox *ib,int id);
//////////////////////////////////////////////////////////
//Function: compsender
//Description: helper function to help order senders alphabetically, used in sortEmailsBySender
//Inputs: struct Mailbox* - pointer to the database
//Outputs: int
int compsender(const void *first, const void *second);
//////////////////////////////////////////////////////////
//Function: compids
//Description:  helper function to help order senders alphabetically, used in sortEmailsBySender
//Inputs: const void *first, const void *second
//Outputs: int
int compids(const void *first, const void *second);
//////////////////////////////////////////////////////////
//Function: create_email
//Description: creates an email with the given inputs and adds it to the inbox.
//Inputs: har *sender, char* receiver, char *subject, char *body, int month, int day, int year, struct Mailbox *ib
//Outputs: void
void create_email(char *sender, char* receiver, char *subject, char *body, int month, int day, int year, struct Mailbox *ib);
//////////////////////////////////////////////////////////
//Function: sortEmailsByID
//Description: sorts the Inbox by ids from least to largest
//Inputs: struct Mailbox* - pointer to the database
//Outputs: void
void sortEmailsByID(struct Mailbox* ib);
//////////////////////////////////////////////////////////
//Function: searchInboxByKeyword
//Description: displays all emails that include the search term
//Inputs: struct Mailbox* - pointer to the database
//Outputs: void
void searchInboxByKeyword(struct Mailbox* ib, char words[10]);
//////////////////////////////////////////////////////////
//Function: exitInbox
//Description: frees all the emails in the inbox then shuts down the program.
//Inputs: struct Mailbox* ib
//Outputs: void
void exitInbox(struct Mailbox* ib);
