#include <stdio.h>
#include "menu.h"
#include "checks.h"
#include "globals.h"
#include "Student.h"

const char* STU_FORMAT_IN = "(%[^,],%d,%c,%d,%lf)";
const char* STU_FORMAT_OUT = "(%s,%d,%c,%d,%lf)";



int main() {

    struct Student students[ARR_SIZE];

    FILE* file = fopen("students.txt", "r+");
    for (int i = 0; i < ARR_SIZE; ++i) {fscanf(file, STU_FORMAT_IN, students[i].name,
                &students[i].studentID, &students[i].gender, &students[i].academicYear, &students[i].GPA);}
    fclose(file);





    int keep = 1;

    while (keep) {

        print_menu();
        int oper = choose_operation();
//  ADDING STUDENT:
        if (oper == 1) {
            struct Student s = receive_info(students);
            add_student(students, s);
            keep = start_over(keep);
        }

//  REMOVING STUDENT:
        else if (oper == 2) {
            remove_student(students);
            keep = start_over(keep);
        }

//  RETRIEVING DATA:
        else if (oper == 3) {
            int num = ret_data();
            if (num == 1) {
                print_data_ID(students);
            } else if (num == 2) {
                print_data_name(students);
            }
            keep = start_over(keep);
        }

//  UPDATING DATA:
        else if (oper == 4) {
            update_data(students);
            keep = start_over(keep);
        }


    }



    FILE* fpw = fopen("students.txt", "w+");
    for (int i = 0; i < ARR_SIZE; i++) {
        if(isValidName_c(students[i].name)&&(students[i].name[0]!='\0')) {
            fprintf(fpw, STU_FORMAT_OUT, students[i].name, students[i].studentID,
                    students[i].gender,students[i].academicYear, students[i].GPA);
        }
    }
    fclose(fpw);







    return 0;
}
