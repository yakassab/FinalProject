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

    int oper;




    struct Student s_new = {"Ali Gabr",1000004,'M',2023,2.32};


    print_data_name("Youssef kassab hello", students);






    /*print_menu();
    oper = choose_operation();

     switch (oper){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
    };










*/
    return 0;
}
