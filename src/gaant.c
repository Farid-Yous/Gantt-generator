#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "gaant.h"

int main() { //farid and george
    struct task tasks[10];
    int choice, numtasks = 0;

    printf("Welcome to the Gantt generator\nWould you like to use the test example or create your own Gantt from scratch? (1 for example, 2 for scratch)\n");
    fflush(stdout);
    scanf("%d", &choice);
    getchar(); // consume the newline character
    while(choice > 2 || choice < 1)
    {
    	printf("invalid option, try again");
    	fflush(stdout);
    	scanf("%d" , &choice);
    }
    if (choice == 1) {
        printf("Predefined\n");
        fflush(stdout);
        printChartExample(); //g
    } else if (choice == 2) {
        numtasks = inputdetails(tasks, 10); // pass the array and its max size


    finalGAANT(tasks, numtasks);

    char editchoice[80];
        printf("\nIf you wish to edit the gantt chart, type 'edit'\n");
        fflush(stdout);
        fgets(editchoice, sizeof(editchoice), stdin);
        editchoice[strcspn(editchoice, "\n")] = 0; //remove newline character
        if (strcmp(editchoice, "edit") == 0)
        {
			while (strcmp(editchoice, "edit") == 0) {
				char tempname[80];

				printf("Enter the name of the task you want to edit:\n");
				fflush(stdout);
				fgets(tempname, sizeof(tempname), stdin);
				tempname[strcspn(tempname, "\n")] = 0; // remove newline character

				if (!editdetails(tasks, numtasks, tempname)) {
						printf("Task not found.\n");
						fflush(stdout);
				}

			printf("If you wish to edit another task, type 'edit'\n");
			fflush(stdout);
			fgets(editchoice, sizeof(editchoice), stdin);
			editchoice[strcspn(editchoice, "\n")] = 0; // remove newline character
			}

		printf("Updated GAANT Chart:\n");
		fflush(stdout);
		finalGAANT(tasks, numtasks);
    }
    printf("\nIf you would like to test for circular dependencies type 'yes'\n");
    fflush(stdout);
    fgets(editchoice , sizeof(editchoice) , stdin);
    editchoice[strcspn(editchoice, "\n")] = 0;
    if(strcmp(editchoice , "yes") == 0)
    {

		printf("Enter the task index you want to check for circular dependency:\n ");
		fflush(stdout);
		int taskindex;
		scanf("%d", &taskindex);
		int circularcheck = 0;
		int visitedtasks[10] = {0}, length = 0, path[10] = {0};
		printdependenttasks(tasks, taskindex, visitedtasks, length, path , circularcheck);

    }
    }
    printf("thank you for using the gantt generator");
	return 0;
	}

