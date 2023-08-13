#include "checks.h"
#include "stdio.h"
#include "globals.h"
#include "ctype.h"

// Checks for Name Validity.
int isValidName(char name[]){
    int counter = 0;
    for (int i = 0; i < ARR_SIZE; ++i) {if (name[i] == ' '){counter++;}}
    if (counter != 1){
        printf("Invalid Name\n");
        return 0;
    } else {return 1;}};

//Different version of previous function but modified for other use in terminating program.
int isValidName_c(char name[]){
    int counter = 0;
    for (int i = 0; name[i] != '\0'; ++i) {
        if (name[i] == ' '){counter++; continue;}
        if (!isalpha(name[i])){return 0;}
    }

    if (counter != 1){
        return 0;
    } else {return 1;}};

//Checks for id validity.
int isValidStudentId(int id) {
    // Check if the student ID is 7 digits long.
    if (id < 1000000 || id > 9999999) {
        printf("Invalid ID, Not 7 digits long\n");
        return 0;}

    return 1;}

//Checks that id doesn't already exist.
int isNotTakenID(int id, struct Student arr[]){
    for (int i = 0; i < ARR_SIZE; ++i) {
        if (arr[i].studentID == id){
            printf("ID Already exists\n");
            return 0;}}
    return 1;};


//Checks for gender validity.
int isValidGender(char c){
    if (c == 'M' || c == 'F') {
        return 1;
    } else {
        printf("Invalid Gender\n");
        return 0;}};

// Checks for Academic Year Validity.
int isValidYear(int num){
    if (num < 1 || num > FACULTY_MAX_ACADEMIC_YEAR) {
        printf("Invalid Academic Year\n");
        return 0;}
    else {return 1;}};

// Checks for GPA Validity.
int isValidGPA(float num){

    if (num < 1.0 || num > 4.0) {
        printf("Invalid GPA\n");
        return 0;}
    else {return 1;}};

