/*
 * gaant.h
 *
 *  Created on: 10 Mar 2024
 *      Author: farid
 */

#ifndef GAANT_H_
#define GAANT_H_
struct task {
    char taskname[80];
    int smonth;
    int emonth;
    int depend;
    int dependindexes[10];
};
struct taskEG {
	int smonth;
	int emonth;
	int depend;
	int dependindexes[10];
};
int finalGAANT(struct task tasks[] , int numtasks);
void printdependenttasks(struct task tasks[] , int taskindex , int visitedtasks[] , int length ,int path[] , int circularcheck);
int inputdetails(struct task tasks[], int maxTasks);
int editdetails(struct task tasks[], int numtasks, char tempname[80]);
int printChartExample();

#endif /* GAANT_H_ */
