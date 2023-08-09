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
        printf("Invalid\n");
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
void print_data_ID(int id, struct Student arr[]){

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
void print_data_name(char text[], struct Student arr[]){
    int counter = 0;
    while (isValidName(text)) {
        for (int i = 0; i < ARR_SIZE; ++i) {
            if (!strcmp(arr[i].name, text)) {
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
