#include <stdio.h>

#include "temp.h" // Copied From NGram_linkedlist_new_1_file.c

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

//Function 
void Menu();
void Print_menu();

int main()
{
    reset();
    red();
    printf("\t\tHELLO TO TUBES KEL B4\n");
    yellow();

    do
    {
        /* code */ 
        Menu();
    } while (state != 0);

    reset();
    printf("Program Ended");
    return 0;
}

void Menu()
{
    yellow();
    Print_menu();

    blue();
    printf("Input pilihan menu : ");
    reset();

    scanf(" %d", &state);

    switch (state)
    {
    case 0:
        break;
    case 1:
        readFile(&words);
        break;
    case 2:
        printf("Input N-gram : ");
        scanf("%d", &ngram);
        break;
    case 3:
        break;
    case 4:
        printf("\nLinking Gram\n");
        linked_list = link_gram(words, ngram);
        key = link_key(words, linked_list, ngram);
        value = link_value(key, linked_list, ngram);

        printf("\nLinking Key 1\n");
        key1 = link_key(words, linked_list, ngram);
        value1 = link_value(key, linked_list, ngram);

        printf("\nLinking Key 2\n");
        key2 = link_key(words, linked_list, ngram);
        value2 = link_value(key, linked_list, ngram);

        range_key = count_key(key, value);
        printf("\nRange : %d", range_key);
        break;
    case 5:
        display_LUT(key, value);
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

