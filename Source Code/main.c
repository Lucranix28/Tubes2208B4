#include <stdio.h>

#include "temp.h" // Copied From NGram_linkedlist_new_1_file.c

char state = '0';
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

//Function 
void Menu();
void Print_menu();

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

void Menu()
{
    yellow();
    Print_menu();
    reset();

    blue();
    printf("Input pilihan menu : ");
    reset();

    scanf(" %s", &state);

    switch (state)
    {
    case '0':
        break;
    case '1':
        readFile(&words);
        break;
    case '2':
        printf("Input N-gram : ");
        scanf("%d", &ngram);
        break;
    case '3' :
        print_text("LUT");
        break;
    case '4' :
        process();
        break;
    case '5':
        save_LUT(key, value);
        break;
    case '6':
        display_LUT(key, value);
        break;
    case '7':
        output(arrKey, arrValue, range_value, range_key, ngram);
        break;
    case '8':
        print_text("OUT");
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
    printf("\t5. Save Key and Value \n");
    printf("\t6. Print Key and Value \n");
    printf("\t7. Generate N-Gram-ed Text \n");
    printf("\t8. Print Result Text \n");
    printf("\t0. Exit \n");
}

