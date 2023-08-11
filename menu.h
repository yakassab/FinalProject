#include "Student.h"

#ifndef MENU_H
#define MENU_H

void print_menu();
int choose_operation();
int ret_data();
void print_data_ID(struct Student arr[]);
void print_data_name(struct Student arr[]);
void update_data(struct Student arr[]);
int start_over(int num);



#endif