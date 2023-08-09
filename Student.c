#include "Student.h"
#include "checks.h"
#include <stdio.h>

// Recieves data for student struct.
struct Student receive_info(struct Student arr[]){
    struct Student s;

    printf("Please Enter Student Name:\n");
    do {
        fflush(stdin);
        fgets(s.name, ARR_SIZE, stdin);
    } while (!isValidName(s.name));

    printf("Please Enter Student ID:\n");
    do {
        scanf("%d", &s.studentID);
    } while (!(isValidStudentId(s.studentID) && isNotTakenID(s.studentID, arr)));

    printf("Please Enter gender:\n");
    do {
        fflush(stdin);
        scanf("%c", &s.gender);
    } while (!isValidGender(s.gender));

    printf("Please Enter Academic Year:\n");
    do {
        scanf("%d", &s.academicYear);
    } while (!isValidYear(s.academicYear));

    printf("Please Enter GPA:\n");
    do {
        scanf("%lf", &s.GPA);
    } while (!isValidGPA(s.GPA));
    return s;
};

// Adds Student to first empty index in array.
void add_student(struct Student arr[], struct Student s){
    for (int i = 0; i < ARR_SIZE; ++i) {
        if (arr[i].name[0] == '\0') {
            arr[i] = s;
            printf("Student %s Added Successfully to index %d in Student Array\n", arr[i].name, i);
            break;
        }}};

// Removes student from array according to ID.
void remove_student(struct Student arr[]){
    int id;
    printf("Please Enter Desired student ID to be removed.\n");
    scanf("%d", &id);
    if(isValidStudentId(id)){
        for (int i = 0; i < ARR_SIZE; ++i) {
            if (arr[i].studentID == id){
                arr[i].name[0] = '\0';
                arr[i].studentID = 0;
                arr[i].gender = '\0';
                arr[i].academicYear = 0;
                arr[i].GPA = 0;
                printf("Student with ID %d Removed Successfully\n", id);
                return;
            }
        }
        printf("ID Not found within Records\n");
        return;
    }};

