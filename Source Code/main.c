#include <stdio.h>

// #include "TUBES_Ngram.c"

int state = 0;
/*
1. Input Text
2. Input (N)-Gram
3. Print Text
4. Process Key and Value
5. Print Key and Value
6. Generate N-Gram-ed Text
7. Print N-Gram-ed Text

0. Exit Program
*/

void Menu();
void Print_menu();



int main()
{
    printf("\033[1;31m");
    printf("\t\tHELLO TO TUBES KEL B4\n");
    printf("\033[0m");

    do
    {
        /* code */ 
        Menu();
    } while (state != 0);
    printf("Program Ended");
    return 0;
}

void Menu()
{
    Print_menu();
    printf("Input pilihan menu : ");
    scanf(" %d", &state);

    switch (state)
    {
    case 0:
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    case 5:
        break;
    case 6:
        break;
    case 7:
        break;
    case 8:
        break;
    default:
        printf("--Input Menu Keliru--\n");
        Menu();
        break;
    }
}

void Print_menu()
{
    printf("\n Menu :\n");
    printf("\t1. Input Text \n");
    printf("\t2. Input(N) - Gram \n");
    printf("\t3. Print Text \n");
    printf("\t4. Process Key and Value \n");
    printf("\t5. Print Key and Value \n");
    printf("\t6. Generate N-Gram-ed Text \n");
    printf("\t7. Print Result Text \n");
    printf("\t0. Exit \n");
}