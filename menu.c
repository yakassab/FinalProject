#include "menu.h"
#include "checks.h"
#include "string.h"
#include <stdio.h>


//Prints Menu Options.
void print_menu(){

    printf("/********************************************/ \n");
    printf("\tStudent Management System\n");
    printf("/********************************************/ \n");

    printf("Choose Your operation: \n\n");
    printf("\t1- Add a new student\n");
    printf("\t2- Remove a student\n");
    printf("\t3- Retrieve student's data\n");
    printf("\t4- Update student's data\n");

};

/* Sets variable to desired operation number
   and Checks if the number entered is valid. */
int choose_operation(){
    int num;
    scanf("%d", &num);
    while (!(num >= 1 && num <= 4)){
        printf("Invalid Number, Please Try Again.\n");
        scanf("%d", &num);};
    return num;

};

//Asks Whether to Retrieve Data using ID or Name.
int ret_data(){
    int num;
    printf("Please Enter Which Method You'd like to search for a student with:\n");
    printf("\t1-Search By ID.\n");
    printf("\t2-Search by name.\n");
    scanf("%d", &num);
    while (num != 1 && num != 2){
        printf("Invalid number entered.\n");
        scanf("%d", &num);};
    return num;};

//Prints Student Data searched for with id.
void print_data_ID(struct Student arr[]){
    int id;
    printf("Please Enter ID:\n");
    scanf("%d", &id);
    while (isValidStudentId(id)) {
        for (int i = 0; i < ARR_SIZE; ++i) {
            if (arr[i].studentID == id) {
                printf("Name: %s\n", arr[i].name);
                printf("ID: %d\n", arr[i].studentID);
                printf("Gender: %c\n", arr[i].gender);
                printf("Year: %d \n", arr[i].academicYear);
                printf("GPA: %lf \n", arr[i].GPA);
                return;
            }
        }
        printf("Student with ID %d not found", id);
        return;
    }
};

//Prints Student Data searched for with name.
void print_data_name(struct Student arr[]){
    int counter = 0;
    char text[ARR_SIZE];
    printf("Please Enter Student's name:\n");
    fflush(stdin);
    fgets(text, ARR_SIZE, stdin);
    text[strlen(text) - 1] = 0;
    while (isValidName(text)) {
        for (int i = 0; i < ARR_SIZE; ++i) {
            if (strcmp(arr[i].name, text) == 0) {
                printf("Name: %s\n", arr[i].name);
                printf("ID: %d\n", arr[i].studentID);
                printf("Gender: %c\n", arr[i].gender);
                printf("Year: %d \n", arr[i].academicYear);
                printf("GPA: %lf \n\n\n", arr[i].GPA);
                counter++;

            }
        }
        if(counter == 0){
            printf("Student with name %s not found", text);
            return;
        } else if (counter >= 1){
            return;
        }
    }
};

//Updates Student Data.
void update_data(struct Student arr[]){
    int id, oper, year;
    double gpa;
    printf("Please Enter Student ID:\n");
    fflush(stdin);
    scanf("%d", &id);
    if (isValidStudentId(id)){
        printf("Which Data would you like to update:\n");
        printf("\t1- Academic Year.\n");
        printf("\t2-Student GPA.\n");
        fflush(stdin);
        scanf("%d", &oper);
        if (oper == 1){
            printf("Please Enter new Academic Year:\n");
            do {
                scanf("%d", &year);
            } while (!isValidYear(year));
            update_year(id, year, arr);
            return;
        } else if (oper == 2){
            printf("Please Enter new Student GPA:\n");
            do {
                scanf("%lf", &gpa);
            } while (!isValidGPA(gpa));
            update_GPA(id, gpa, arr);
            return;
        }
    };
};

//Keeps or breaks main loop.
int start_over(int num){
    printf("\nChoose one of the following:\n");
    printf("\t1-Return to Main Menu.\n");
    printf("\t2-End Program.\n");
    scanf("%d", &num);
    if (num == 2){num = 0;};
    return num;
};


