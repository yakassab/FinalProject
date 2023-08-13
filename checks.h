#include "Student.h"

#ifndef CHECKS_H
#define CHECKS_H

int isValidName(char name[]);
int isValidName_c(char name[]);
int isValidStudentId(int id);
int isNotTakenID(int id, struct Student arr[]);
int isValidGender(char c);
int isValidYear(int num);
int isValidGPA(float num);

#endif