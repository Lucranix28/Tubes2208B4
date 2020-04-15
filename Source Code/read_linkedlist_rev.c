//scan input paragraf

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_WORD 25

struct fileProcess{
    char data[1024];
    struct fileProcess *next;
};

struct node{
    char data[25];
    struct node *next;
};

void readFile(struct node **head);
void inverse_fileProcess(struct fileProcess **head);
void inverse_node(struct node **head);
void processing(struct node *head);

int main(){
    struct node *words;
    readFile(&words); 

    //debug
    int count = 0;
    puts("DEBUGGGGG SLURR");
    struct node *temp_print = words;
    while(temp_print != NULL){
        //printf("%d %d %d %d %d",temp_print->data[0], temp_print->data[1], temp_print->data[2], temp_print->data[3], temp_print->data[4]);
        //printf("-- %d \n",temp_print->data[0]);
        printf("-%s-", temp_print->data);
        printf("\n");
        temp_print = temp_print->next;
    }
    system("pause");
}

void readFile(struct node **head){
    char arr[150][50];
    FILE *fp;

    int loop = 0;
    char filename[64];
    char temp[1024];
    int index = 0;
    int i_last = 0;
    int j_last = 0;

    struct node *word_store;
    struct node *head_new;
    struct node *head_temp;

    struct fileProcess *lines;
    struct fileProcess *lines_new;

    //IO
    /*
    printf("File: ");
    scanf("%s", filename);
    */

    //initialize structs
    lines = malloc(sizeof(struct fileProcess));
    strcpy(lines->data, "START");
    lines->next = NULL;

    word_store = malloc(sizeof(struct node));
    strcpy(word_store->data, "START");
    word_store->next = NULL;

    //read txt
    fp = fopen("APoemFromAFriend.txt", "r");
    while(!feof(fp)){
        lines_new = malloc(sizeof(struct fileProcess));
        fgets(temp, 1024, fp);
        strcpy(lines_new->data,temp);
        lines_new->next = lines;
        lines = lines_new;
    }

    //inverse_fileProcess
    inverse_fileProcess(&lines);
    for (int i = 0; i < 1024; i++){
        temp[i] = 0;
    }
    
    //to words
    int i = 0;
    while(lines != NULL){
        for (int j = 0; j < 100; j++){
            if (lines->data[j] == ' '  || lines->data[j] == 9){
                //puts("a");
                temp[j_last] = '\0';

                head_new = malloc(sizeof(struct node));
                strcpy(head_new->data, temp);
                head_new->next = word_store;
                word_store = head_new;
                for (int i = 0; i < 1024; i++){
                    temp[i] = 0;
                }
                
                //printf("->%s", head_new->data);
                j_last = 0;
            }
            else if (lines->data[j] == '\0' || lines->data[j] == '\n'){
                //puts("b");
                temp[j_last] = '\0';
                
                head_new = malloc(sizeof(struct node));
                strcpy(head_new->data, temp);
                head_new->next = word_store;
                word_store = head_new;
                for (int i = 0; i < 1024; i++){
                    temp[i] = 0;
                }
                
                //printf("->%s", head_new->data);
                j_last = 0;
                break;
            }
            else if (lines->data[j] == -30){
                temp[j_last] = 34;
                j_last++;
            }
            else if (lines->data[j] < 0){
            }
            else{
                //printf("1st index = %d\n", i_last);
                //printf("CHAR = %c\n", temp[i_last][j]);
                temp[j_last] = lines->data[j];
                //printf("PRINTED CHAR = %c\n", arr[i][j_last]);
                j_last++;
            }

            

        }
        lines = lines->next;
    }

    //inverse_node & processing
    inverse_node(&word_store);
    word_store = word_store->next->next; 
    processing(word_store);

    //final assignment
    *head = word_store;

    /*
    //debug
    puts("DEBUGGGGG SLURR");
    struct node *temp_print = word_store;
    while(temp_print != NULL){
        printf("%s",temp_print->data);
        printf("-- %d \n",temp_print->data[0]);
        temp_print = temp_print->next;
    }
    */
}


void inverse_fileProcess(struct fileProcess **head){

    struct fileProcess *p, *q, *r;
 
    p = q = r = *head;
    p = p->next->next;
    q = q->next;
    r->next = NULL;
    q->next = r;
 
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    *head = q;
}

void inverse_node(struct node **head){

    struct node *p, *q, *r;
 
    p = q = r = *head;
    p = p->next->next;
    q = q->next;
    r->next = NULL;
    q->next = r;
 
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    *head = q;
}

void processing(struct node *head){
    struct node *temp = head;
    
    while (temp->next != NULL){
        if (temp->next->data[0] == 0 || temp->next->data[0] == 9 ){
            temp->next = temp->next->next;
        }
        else{
            temp = temp->next;
        }
    }

    
}
