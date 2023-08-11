#include "globals.h"

#ifndef STUDENT_H
#define STUDENT_H

struct Student {
    char name[ARR_SIZE];
    int studentID;
    char gender;
    int academicYear;
    double GPA;};



struct Student receive_info(struct Student arr[]);
void add_student(struct Student arr[], struct Student s);
void remove_student(struct Student arr[]);
void update_GPA(int id, double gpa, struct Student arr[]);
void update_year(int id, int year, struct Student arr[]);



#endif