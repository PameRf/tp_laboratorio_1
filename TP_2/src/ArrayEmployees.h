/*
 * ArrayEmployees.h
 *
 *  Created on: 15 oct. 2021
 *      Author: pamel
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define TRUE 0
#define FALSE 1
#define ELEMENTS 5

struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;

int initEmployees(Employee list[], int len);


#endif /* ARRAYEMPLOYEES_H_ */
