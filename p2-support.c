//Add program description
//Author: Adam harms
//P2 support file that has the infrastucture of the E-mail client.
//Last edit: 4/15/2021
//add necessary include statements
#include <stdio.h>
#include <stdlib.h>
#include "p2-support.h"
#include <string.h>
void initialize (struct Mailbox *ib){
	//allocate memory for 2000 emails
	ib->emails = malloc (sizeof(struct Email) * MAILBOX_SIZE);
	ib->size=0;
	create_email("asonmez@mail.com", user_email, "Welcome to your inbox.", "Welcome to your inbox, just wanted to say hi. Here's hoping you get all your code done.", 11,20,2020, ib);
	create_email("mmartinez@mail.com", user_email, "Padding out your inbox.", "Yet another email just to pad out your inbox, have fun!",11,30,2020, ib);
	create_email("dboyle@mail.com", user_email, "3rd email!","Alright, time for another email for your inbox. Not going too lie, it's a bit of a pain coming up with stuff for these strings. Anyways, have fun with your code!", 12,2,2020, ib);
	create_email("cbluer@mail.com", user_email, "4th email!","Content of fourth email. More coding, more fun!",12,8,2020, ib);
	create_email("cboyle@mail.com", user_email, "5th email!","Content of fifth email. Coding is fun-tastic!",12,18,2020, ib);
	create_email("sblack@mail.com", user_email, "6th email!","Content of fifth email. Coding is fun-tastic!",1,1,2021, ib);
	create_email("sblack@mail.com", user_email, "7th email!","Body of sixth email. Coding is fun-tastic!",1,5,2021, ib);
	create_email("sblack@mail.com", user_email, "8th email!","Body of eighth email. Coding is fun-tastic!",2,15,2021, ib);
	create_email("sblack@mail.com", user_email, "9th email!","Body of ninth email. Coding is fun-tastic!",2,25,2021, ib);
	create_email("dboyle@mail.com", user_email, "Last email!","Body of tentth email. Coding is fun-tastic!",3,15,2021, ib);
}
void mainMenu(struct Mailbox* ib){
	int num;
	int input;
	char input2[10];
	int id;
	while(1){
	printf("\n***************   HARMSAD INBOX   ***************\n*************** Total Inbox: %04d ***************\n",ib->size );
	printf("\n1. Show Inbox\n2. Show Email by ID\n3. Sort Inbox by Sender\n4. Sort Inbox by ID\n5. Search Inbox by Keyword\n6. Delete\n7. Exit Inbox\n");
		scanf("%d",&num);
		switch(num){
			case 1:
				showInbox(ib);
				break;
			case 2:
				printf("Enter the ID of the email you want to read:\n");
				scanf("%d",&input);
 				showEmailByID(ib,input);
 				break;
 			case 3:
 				sortEmailsBySender(ib);
 				break;
 			case 4:
			 	sortEmailsByID(ib);
 				break;
			case 5:
				printf("Enter the word inside the email(s) you want to read:\n");
				scanf("%s",&input2);
				searchInboxByKeyword(ib,input2);
				break;
			case 6:
				printf("Enter the ID of the email you want to delete:\n");
				scanf("%d",&id);
				deleteByID(ib,id);
				break;
			case 7:
				exitInbox(ib);
				return;

 			default:
 				break;
 			}
 	//mainMenu(ib);
 	printf("\n");
 	}
 }
 void showInbox(struct Mailbox* ib){
 	 printf("\nID   SENDER--------------  MM/DD/YYYY  SUBJECT--------\n");
	 printf("--   --------------------  --/--/----  ---------------\n");
 	int c;
 	for(c =0; c<ib->size;c++){
 		printf("%02d - %-19s - %02d/%02d/%d - %.15s\n", ib->emails[c].ID, ib->emails[c].sender,ib->emails[c].sent.month,ib->emails[c].sent.day, ib->emails[c].sent.year, ib->emails[c].subject);
 	}
 }
 void showEmailByID(struct Mailbox* ib, int id){
 	 int i;
	 int found =0;
 	for(i=0;i<ib->size;i++){
 		if(ib->emails[i].ID == id){
 		found = 1;
 		printf("\n%s - %s\nEmail Received on: %d/%d/%d\n\n%s",ib->emails[i].sender,ib->emails[i].subject,ib->emails[i].sent.month,ib->emails[i].sent.day,ib->emails[i].sent.year,ib->emails[i].body);
 		}
 	}
 	if(found == 0){
 	printf("\nno email was found with that ID");
 	}
 }
 void sortEmailsBySender(struct Mailbox* ib){
 	qsort(ib->emails,ib->size,sizeof(struct Email),compsender);
 }
 void sortEmailsByID(struct Mailbox* ib){
	qsort(ib->emails,ib->size,sizeof(struct Email),compids);
 }
 void searchInboxByKeyword(struct Mailbox* ib, char words[10]){
	 int i;
	 printf("\nID   SENDER--------------  MM/DD/YYYY   SUBJECT--------\n");
	 printf("--   --------------------  --/--/----   ---------------\n");
	 	for(i=0;i<ib->size;i++){
			if(strstr(ib->emails[i].sender,words) ||strstr(ib->emails[i].subject,words) || strstr(ib->emails[i].body,words)){
				printf("%02d - %-19s - %02d/%02d/%d - %.15s\n", ib->emails[i].ID, ib->emails[i].sender,ib->emails[i].sent.month,ib->emails[i].sent.day, ib->emails[i].sent.year, ib->emails[i].subject);
			}
		 }
 }
void deleteByID(struct Mailbox* ib, int id){
  	int i;
  	for(i=0;i<ib->size;i++){
  		if(ib->emails[i].ID==id){
  			printf("Email with ID = %d is deleted",id);
  			int k;
  			for(k=i;k<ib->size-1;k++){
  				ib->emails[k]=ib->emails[k+1];
  			}
  		ib->size--;
 		}
 	}
	 return;
 }
int compsender(const void *first, const void *second) {
	char *s1 = (char*) first;
	char *s2 = (char*) second;
	return strcmp(s1,s2);
}
int compids(const void *first, const void *second){
	struct Email *email1 = (struct Email*) first;
    struct Email *email2 = (struct Email*) second;
    return (email1->ID - email2->ID);
}
void create_email(char *sender, char* receiver, char *subject, char *body, int month, int day, int year, struct Mailbox* ib){
	strcpy(ib->emails[ib->size].sender, sender);
	strcpy(ib->emails[ib->size].receiver, receiver);
	strcpy(ib->emails[ib->size].subject, subject);
	strcpy(ib->emails[ib->size].body, body);
	ib->emails[ib->size].sent.month = month;
	ib->emails[ib->size].sent.day = day;
	ib->emails[ib->size].sent.year = year;
	ib->emails[ib->size].ID = ib->size;
	ib->size++;
}
void exitInbox(struct Mailbox* ib){
	free(ib->emails);
	printf("Exiting e-mail client - Good Bye!\n");
}
