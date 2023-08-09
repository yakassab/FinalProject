#include <stdio.h>
#include "menu.h"
#include "checks.h"
#include "globals.h"
#include "Student.h"


int main() {

    struct Student students[ARR_SIZE] = {
            {"Seif Khuelif",1000002,'M',2023,4},
            {"Ahmed Ayman",1000001,'M',2023,3.53},
            {"Youssef Kassab",1000000,'M',2023,3.03},
            {"Rogeh Hany",2310386,'M',2023,3.3}};

    print_menu();
    int oper = choose_operation();

    if (oper == 1){
        struct  Student s = receive_info(students);
        add_student(students, s);
    }
    else if (oper == 2){
        remove_student(students);
    }
    else if (oper == 3){

    }












    return 0;
}
