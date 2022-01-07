//add program description, author name, last edit date as in the project1
//Author: Adam harms
//Program description: Initalizes the email client with the default main menu
//Last edit: 4/15/2021
//Do not modify anything below this line
#include <stdio.h>
#include <stdlib.h>
#include "p2-support.h"
int main(){
	struct Mailbox* ib;
	ib = (struct Mailbox*) malloc(sizeof(struct Mailbox));
	initialize(ib);
	mainMenu(ib);
	free(ib);
	return 0;
}
