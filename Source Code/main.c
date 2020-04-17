#include <stdio.h>

#include "temp.h" // Copied From NGram_linkedlist_new_1_file.c
#include "menu.h"

int main()
{
    red();
    printf("\t\tHELLO TO TUBES KEL B4\n");
    reset();

    do
    {
        /* code */ 
        Menu();
    } while (state != '0');

    reset();
    printf("Program Ended");
    return 0;
}