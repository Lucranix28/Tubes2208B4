
char state = '0';
/*
1. Input Text
2. Input (N)-Gram
3. Print Text
4. Process Key and Value
5. Save Key and Value
6. Print Key and Value
7. Generate N-Gram-ed Text
8. Print N-Gram-ed Text

0. Exit Program
*/

//Function
void Menu();
void Print_menu();

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
    case '3':
        print_text("lut");
        break;
    case '4':
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
        print_text("out");
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
