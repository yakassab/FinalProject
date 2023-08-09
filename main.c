#include <stdio.h>
#include "menu.h"
#include "checks.h"
#include "globals.h"
#include "Student.h"


int main() {

    struct Student students[ARR_SIZE] = {
            {"seif khuelif",1000002,'M',2023,4},
            {"ahmed ayman",1000001,'M',2023,3.53},
            {"youssef kassab",1000000,'M',2023,3.03},
            {"rogeh hany",2310386,'M',2023,3.3},
            {"ahmed ayman",1000055,'M',2020,1.23}};

    print_menu();
    int oper = choose_operation();

//  ADDING STUDENT:
    if (oper == 1){
        struct  Student s = receive_info(students);
        add_student(students, s);
    }

//  REMOVING STUDENT:
    else if (oper == 2){
        remove_student(students);
    }

//  RETRIEVING DATA:
    else if (oper == 3){
        int num = ret_data();
        if (num == 1){
            print_data_ID(students);
        } else if (num == 2){
            print_data_name(students);}
//  UPDATING DATA:

        } else if (oper == 4){


    }














    return 0;
}
