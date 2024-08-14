#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "gaant.h"


int finalGAANT(struct task tasks[], int rows){    //george
	const char *monthNames[] = {
			"January", "February", "March", "April", "May", "June",
			"July", "August", "September", "October", "November", "December"
		};

	for (int i = 0; i < 190; i++) {
		printf("_");
	}
	printf("\n|                         | ");

	int maxWidth = 10;
	int numMonths = 12;

	// making even padding between the months
	for (int i = 0; i < numMonths; i++) {
		int nameLength = strlen(monthNames[i]);
		int padding = (maxWidth - nameLength) / 2;
		int extraSpaces = maxWidth - nameLength - padding;

		printf("%*s%s%*s| ", padding, "", monthNames[i], extraSpaces, "");
	}

	printf("  Dependencies   |");

	// printing the table
	for (int i = 0; i < rows; i++) {
		printf("\n");
		for (int j = 0; j < 190; j++) {
			printf("-");
		}
		int pad = 25 - strlen(tasks[i].taskname);
		printf("\n| %s", tasks[i].taskname);		// printing the tasks and some padding
		for (int k = 0; k < pad - 1; k++) {
			printf(" ");
		}
		printf("|");

		for (int l = 1; l <= 12; l++) {	// printing the X's in months where it is required
			if (l >= tasks[i].smonth && l <= tasks[i].emonth) {
				printf("    XXX    |");
			} else {
				printf("           |");
			}


		}
		for (int p = 0; p < tasks[i].depend; p++){
			printf("%i ", tasks[i].dependindexes[p]);		// printing the dependencies for each task
		}



	}
	printf("\n");
	for (int i = 0; i < 190; i++) {
			printf("-");
		}

	return 0;
}

int printChartExample() { //george

	// initialising struct task
	struct taskEG tasking[10];

	// pointer array for months
	const char *monthNames[] = {
		"January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December"
	};

	// pointer array for tasks as example
	const char *taskNames[] = {
		"Task 1",
		"Task 2",
		"Task 3",
		"Task 4",
		"Task 5",
		"Task 6",
		"Task 7",
		"Task 8",
		"Task 9",
		"Task 10"
	};
	// all the dependencies and months where work is to be done is hardcoded as it is only an example
	tasking[0].smonth = 0;
	tasking[0].emonth = 2;
	tasking[1].smonth = 2;
	tasking[1].emonth = 3;
	tasking[2].smonth = 2;
	tasking[2].emonth = 4;
	tasking[3].smonth = 3;
	tasking[3].emonth = 5;
	tasking[4].smonth = -1;
	tasking[4].emonth = -1;
	tasking[5].smonth = 5;
	tasking[5].emonth = 8;
	tasking[6].smonth = 6;
	tasking[6].emonth = 8;
	tasking[7].smonth = 7;
	tasking[7].emonth = 8;
	tasking[8].smonth = 8;
	tasking[8].emonth = 11;
	tasking[9].smonth = 10;
	tasking[9].emonth = 11;


	tasking[0].dependindexes[0] = 0;
	tasking[0].depend = 1;
	tasking[1].dependindexes[0] = 1;
	tasking[1].depend = 1;
	tasking[2].dependindexes[0] = 1;
	tasking[2].depend = 1;
	tasking[3].dependindexes[0] = 2;
	tasking[3].depend = 1;
	tasking[4].dependindexes[0] = 3;
	tasking[4].depend = 1;
	tasking[5].dependindexes[0] = 4;
	tasking[5].depend = 1;
	tasking[6].dependindexes[0] = 5;
	tasking[6].depend = 1;
	tasking[7].dependindexes[0] = 5;
	tasking[7].depend = 1;
	tasking[8].dependindexes[0] = 7;
	tasking[8].depend = 1;
	tasking[9].dependindexes[0] = 7;
	tasking[9].dependindexes[1] = 8;
	tasking[9].depend = 2;



	for (int i = 0; i < 190; i++) {
		printf("_");
	}
	printf("\n|                         | ");

	int maxWidth = 10;
	int numMonths = 12;

	// making even padding between the months
	for (int i = 0; i < numMonths; i++) {
		int nameLength = strlen(monthNames[i]);
		int padding = (maxWidth - nameLength) / 2;
		int extraSpaces = maxWidth - nameLength - padding;

		printf("%*s%s%*s| ", padding, "", monthNames[i], extraSpaces, "");
	}

	printf("  Dependencies   |");

	// printing the table
	for (int i = 0; i < 10; i++) {
		printf("\n");
		for (int j = 0; j < 190; j++) {
			printf("-");
		}
		int pad = 25 - strlen(taskNames[i]);
		printf("\n| %s", taskNames[i]);		// printing the tasks and some padding
		for (int k = 0; k < pad - 1; k++) {
			printf(" ");
		}
		printf("|");

		for (int l = 0; l < 12; l++) {	// printing the X's in months where it is required
			if (l >= tasking[i].smonth && l <= tasking[i].emonth) {
				printf("    XXX    |");
			} else {
				printf("           |");
			}


		}
		for (int p = 0; p < tasking[i].depend; p++){
			printf("%i ", tasking[i].dependindexes[p]);		// printing the dependencies for each task
		}



	}
	printf("\n");
	for (int i = 0; i < 190; i++) {
			printf("-");
		}
	printf("\n");

	return 0;
}

void printdependenttasks(struct task tasks[], int taskindex, int visitedtasks[], int length, int path[] , int circularcheck) { //farid
    printf("%d -> ", taskindex);
    fflush(stdout);

    visitedtasks[taskindex - 1] = 1;      //Decrementing to adjust indexing
    path[length] = taskindex - 1; //path contains the path taken of dependencies, used to check if there is a repeated task
    for (int i = 0; i < tasks[taskindex - 1].depend; i++) {
        int dependenttaskindex = tasks[taskindex - 1].dependindexes[i] - 1; // decrementing to adjust indexing
        if (visitedtasks[dependenttaskindex] == 0) {
            printdependenttasks(tasks, dependenttaskindex + 1, visitedtasks, length + 1, path , circularcheck);
        } else {
            printf("potential circular dependency found \n");
            fflush(stdout);
            for (int j = 0; j <= length; j++) {
                if (path[j] == dependenttaskindex) { // checks if the dependenttaskindex is contained in the path array, this would indicate a circular dependency.
                    circularcheck = 1;
                    break;
                }
            }
            if (circularcheck == 1) {
                printf("circular dependency found!\n"); //once potential circular dependency is found, it is evaluated and returns the result
                fflush(stdout);
            } else if (circularcheck == 0) {
                printf("no circular dependency found!\n");
                fflush(stdout);
            }
                fflush(stdout);
            }
        }

    visitedtasks[taskindex - 1] = 0; // Decrement taskindex to adjust indexing
    }

int inputdetails(struct task tasks[], int maxTasks) { //farid
    int numtasks;
    printf("How many tasks would you like to add? (1 - 10)\n");
    fflush(stdout);
    scanf("%d", &numtasks);
    getchar();
    while(numtasks > 10 || numtasks < 1)
    {
    	printf("invalid option, please try again");
    	fflush(stdout);
    	scanf("%d", &numtasks);
    	getchar();
    }

    for (int i = 0; i < numtasks; i++) { // Adjust loop counter to start from 0
        printf("Enter task name:\n");
        fflush(stdout);
        fgets(tasks[i].taskname, sizeof(tasks[i].taskname), stdin);
        tasks[i].taskname[strcspn(tasks[i].taskname, "\n")] = 0;

        printf("Start month (1-12):\n");
        fflush(stdout);
        scanf("%d", &tasks[i].smonth);
        while(tasks[i].smonth > 12 || tasks[i].smonth < 1)   //making sure theres no wrong inputs
        {
        	printf("invalid option, try again \n");
        	fflush(stdout);
        	scanf("%d" , &tasks[i].smonth);
        }
        printf("End month:\n");
        fflush(stdout);
        scanf("%d", &tasks[i].emonth);
        while(tasks[i].emonth > 12 || tasks[i].emonth < 1)	//making sure theres no wrong inputs
         {
         	printf("invalid option, try again \n");
         	fflush(stdout);
         	scanf("%d" , &tasks[i].emonth);
         }

        printf("Enter how many dependencies this task has:\n");
        fflush(stdout);
        scanf("%d", &tasks[i].depend);
        while(tasks[i].depend < 0 || tasks[i].depend > 9)
        {
        	printf("invalid input, please try again \n");
        	fflush(stdout);
        	scanf("%d", &tasks[i].depend);
        }
        getchar();



        if (tasks[i].depend > 0) {
            printf("Enter the dependent task indexes (separated by space):\n");
            fflush(stdout);
            for (int j = 0; j < tasks[i].depend; j++) {
                scanf("%d", &tasks[i].dependindexes[j]);
            }
            getchar();
        }
    }
    return numtasks; // Return the number of tasks inputed
}

int editdetails(struct task tasks[], int numtasks, char tempname[80]) {
    for (int i = 0; i <= numtasks; i++) {
        if (strcmp(tempname, tasks[i].taskname) == 0) {
            printf("Editing task: %s\n", tasks[i].taskname);
            fflush(stdout);

            printf("Enter new task name or type the old one:\n");
            fflush(stdout);
            fgets(tasks[i].taskname, sizeof(tasks[i].taskname), stdin);
            tasks[i].taskname[strcspn(tasks[i].taskname, "\n")] = 0; // Remove newline character

            printf("Start month:\n");
            fflush(stdout);
            scanf("%d", &tasks[i].smonth);
            getchar(); // Consume the newline character
            while(tasks[i].smonth > 12 || tasks[i].smonth < 1)   //making sure theres no wrong inputs
            {
            	printf("invalid option, try again \n");
            	fflush(stdout);
            	scanf("%d" , &tasks[i].smonth);
            }

            printf("End month:\n");
            fflush(stdout);
            scanf("%d", &tasks[i].emonth);
            getchar(); // Consume the newline character
            while(tasks[i].emonth > 12 || tasks[i].emonth < 1)	//making sure theres no wrong inputs
             {
             	printf("invalid option, try again \n");
             	fflush(stdout);
             	scanf("%d" , &tasks[i].emonth);
             }

            printf("Enter how many dependencies this task has:\n");
            fflush(stdout);
            scanf("%d", &tasks[i].depend);
            getchar(); // Consume the newline character
            while(tasks[i].depend < 0 || tasks[i].depend > 9)
            {
            	printf("invalid option, please try again \n");
            	fflush(stdout);
            	scanf("%d", &tasks[i].depend);
            }

            if (tasks[i].depend > 0) {
                printf("Enter the dependent task indexes (separated by space):\n");
                fflush(stdout);
                for (int j = 0; j < tasks[i].depend; j++) {
                    scanf("%d", &tasks[i].dependindexes[j]);
                }
                getchar(); // Consume the newline character after all dependencies are read
            }
            return 1; // Task found and edited
        }
    }
    return 0; // Task not found
}


