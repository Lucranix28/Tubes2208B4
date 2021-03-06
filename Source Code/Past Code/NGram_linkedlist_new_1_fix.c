#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct node{
    char data[1024];
    struct node *next;
}node;

struct fileProcess{
    char data[1024];
    struct fileProcess *next;
};

typedef struct value_node{
    node* value;
    struct value_node *nexts;
}value_node;

// Naoko Punya 
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

void readFile(struct node **head){
    FILE *fp;
    char filename[64];
    char temp[1024];
    int j_last = 0;

    struct node *word_store;
    struct node *head_new;

    struct fileProcess *lines;
    struct fileProcess *lines_new;

    //IO
    printf("File: ");
    scanf("%s", filename);

    //initialize structs
    lines = malloc(sizeof(struct fileProcess));
    strcpy(lines->data, "START");
    lines->next = NULL;

    word_store = malloc(sizeof(struct node));
    strcpy(word_store->data, "START");
    word_store->next = NULL;

    //read txt
    fp = fopen(filename, "r");
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
    while(lines != NULL){
        for (int j = 0; j < 1024; j++){
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
                
                j_last = 0;
            }
            else if (lines->data[j] == '\0' || lines->data[j] == '\n'){
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
                temp[j_last] = lines->data[j];
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

}

//Ian Punya 
int check (node *check, char data[]){
	node *temp_check = check;
	while (temp_check!=NULL){
		if (strcmp(data,temp_check->data) == 0){
			return (0); // Ditemukan ada yang sama
		}
		else{
			temp_check = temp_check->next;
		}
	}
	return (1); // Tidak ada yang sama
}

int key_valid (node *key, int n_gram){
	int i = 0;
	while ((i<n_gram) && (key != NULL)){
		key = key->next;
		i++;
	}
	if (key == NULL) {
		return(0);
	}
	else {
		return(1);
	}
}

void display (node* head){
	while (head != NULL){
		printf("%s\n", head->data);
		head = head->next;
	}
}

void display_value (node* head){
	while (head != NULL){
		if (head->next == NULL){
			printf(" %s ",head->data);
		}
		else {
			printf(" %s ,",head->data);
		}
		head = head->next;
	}
}


void display_LUT (node* key, value_node *value){
	int counter = 0;
	printf("|\tKey  %-15s|\tValue\n","");
	while (key != NULL){
		printf("%d|\t%-20s|\t{", counter, key->data);
		display_value(value->value);
		value = value->nexts;
		printf("}\n");
		key = key->next;
		counter += 1;
	}
}

node* link_gram(node *head, int n_gram){
	char temp_2[1000];
	node *temp = NULL;
	node *new_node;
	node *prev;
	node *temp_head = head;
	node *tempo;
	strcpy(temp_2,"");
	while (temp_head != NULL){
		tempo = temp_head;
		for (int y = 0; (y<n_gram) && (tempo != NULL); y++){
			strcat(temp_2,tempo->data);
			strcat(temp_2," ");
			tempo = tempo->next;
		}
		new_node = (node*)malloc(sizeof(node));
		strcpy(new_node->data,temp_2);
		if(temp == NULL){
			temp = (node*)malloc(sizeof(node));
			strcpy(temp->data,new_node->data);
			temp->next = NULL;
			prev = temp;
		}
		else{
			new_node->next = NULL;
			prev->next = new_node;
			prev = prev->next;
		}
		strcpy(temp_2,"");
		temp_head = temp_head->next;
	}
	return(temp);
}

node* link_key (node *head, node *gram, int n_gram){
	char temp_2[1000];
	node *temp = NULL;
	node *new_node;
	node *prev;
	node *temp_head = head;
	node *tempo;
	strcpy(temp_2,"");
	while (temp_head != NULL){
		tempo = temp_head;
		for (int y = 0; (y<n_gram) && (tempo != NULL); y++){
			strcat(temp_2,tempo->data);
			strcat(temp_2," ");
			tempo = tempo->next;
		}
		new_node = (node*)malloc(sizeof(node));
		strcpy(new_node->data,temp_2);
		if ((check(temp,temp_2)>0) && (key_valid(temp_head,(n_gram))==1)){
			if(temp == NULL){
				temp = (node*)malloc(sizeof(node));
				strcpy(temp->data,new_node->data);
				temp->next = NULL;
				prev = temp;
			}
			else{
				new_node->next = NULL;
				prev->next = new_node;
				prev = prev->next;
			}
		}
		strcpy(temp_2,"");
		temp_head = temp_head->next;
	}
	return(temp);
}

value_node* link_value (node *key_head, node* link_gram_head, int n_gram){
	char temp_gram[1000];
	char temp_gram_next[1000];
	char *temp_tok;
	node* temp1 = key_head;
	node* temp2 = link_gram_head;
	value_node* temp_value = NULL;
	value_node* tempo;
	value_node* tempo_prev;
	node *new_node;
	node *prev;
	while (temp1!=NULL){
		temp2 = link_gram_head;
		tempo = (value_node*)malloc(sizeof(value_node));
		tempo->value = NULL;
		while (temp2->next!=NULL){
			strcpy(temp_gram,temp2->data);		
			strcpy(temp_gram_next,temp2->next->data);
			if (strcmp(temp1->data,temp_gram)==0){
				temp_tok = strtok(temp_gram_next," ");
				for (int i =0; i<(n_gram-1);i++){
					if (temp_tok!=NULL){
						temp_tok=strtok(NULL," ");
					}	
				}
				if (temp_tok != NULL){
					new_node = (node*)malloc(sizeof(node));
					strcpy(new_node->data,temp_tok);
					if (tempo->value == NULL){
						tempo->value = (node*)malloc(sizeof(node));
						strcpy(tempo->value->data,new_node->data);
						tempo->value->next = NULL;
						prev = tempo->value;
					}
					else {
						new_node->next = NULL;
						prev->next = new_node;
						prev = prev->next;
					}
				}
			}
			temp2 = temp2->next;
		}
		if(temp_value == NULL){
			temp_value = (value_node*)malloc(sizeof(value_node));
			temp_value->value = tempo->value;
			temp_value->nexts = NULL;
			tempo_prev = temp_value;
		}
		else{
			tempo->nexts = NULL;
			tempo_prev->nexts = tempo;
			tempo_prev = tempo_prev->nexts;
		}
		temp1 = temp1->next;
	}
	return (temp_value);
}


// Raka Punya
void st_wordRemove(char *s,char *w)
{
    int n,a[1000],i,j,k=0,l,t=0;
 
    for(i=0;s[i];i++)
    {
    	if(s[i]==' ')
    	{
    		a[k++]=i;
		}
	}
	a[k++]=i;
	j=0;
	for(i=0;i<k;i++)
	{
		n=a[i]-j;
		if(n==strlen(w))
		{
			t=0;
			for(l=0;w[l];l++)
			{
				if(s[l+j]==w[l])
				{
					t++;
				}
			}
			if(t==strlen(w))
		    {
               break;				 
		    }
		}	
		j=a[i]+1;
	}
	l=0;
	i=j+t+1;
	while(s[j+l])
	{
		s[j+l]=s[j+t+l+1];
		l++;
	}
}


int printRandoms(int upper){ // ----> Raka
	int rand_num = (rand() % (upper + 1)); 
	return rand_num;
}

void output(char **key, char ***value, int arr[], int range, int Ngram){ // ----> Raka
	int num_words, counter, choosen_value, choosen_key, choosen_to_key, same_1_word = 0, i, end = 0;
	int index_selected[range];
	char *token, str[100];

	printf("\nMasukkan jumlah kata yang ingin ditampilkan :");
	scanf("%d", &num_words);

	printf("\n...");

	char **key_temp = (char**) malloc(range*sizeof(char*));
	for (int i = 0; i < range; i++)
	{
		key_temp[i] = (char*) malloc(100*sizeof(char));
	}	

	for (int i = 0; i < range; i++)
	{
		strcpy(key_temp[i], key[i]);
	}

	char **words = (char**) malloc(num_words*sizeof(char*));
	for (int i = 0; i < num_words; i++)
	{
		words[i] = (char*) malloc(100*sizeof(char));
		words[i] = '\0';
	}
	
	srand(time(0));
	choosen_key = printRandoms(range);
	
	printf("%s", key_temp[choosen_key]);

	counter = Ngram;
	

	while ((counter < num_words) && (end != 1))
	{

		choosen_value = printRandoms(arr[choosen_key] - 1);

		printf("%s ", value[choosen_key][choosen_value]);

		strcpy(str, key_temp[choosen_key]);
		token = strtok(key[choosen_key], " ");
		st_wordRemove(str,token);

		strcat(str, value[choosen_key][choosen_value]);
		strcat(str, " ");

		i = 0;
		while (same_1_word != 1)
		{
			if (strcmp(key_temp[i], str) == 0)
			{
				index_selected[same_1_word] = i;
				same_1_word = 1;
			}
			i += 1;
		}
		
		choosen_to_key = printRandoms(same_1_word - 1);
		// printf("\nchoosen to key : %d", choosen_to_key);
		choosen_key = index_selected[choosen_to_key];
		same_1_word = 0;

		if (i == range)
		{
			counter = range;
			end = 1;
		}
		
		counter += 1;
	}

	if (end == 1)
	{
		printf("\nThis is the end of a texts");
	}
	else
	{
		printf("...");
	}
}

int count_key (node* key, value_node *value){
	int range_key = 0;

	while (key != NULL){
		value = value->nexts;
		key = key->next;
		range_key += 1;
	}

	return range_key;
} 

void count_value (node* key, value_node *value, int range_value[]){
	int count = 0;
	while (key != NULL){
		range_value[count] = 0;
		while (value->value != NULL){
			range_value[count] += 1;
			value->value = value->value->next;
		}
		value = value->nexts;
		key = key->next;
		count += 1;
	}
} 

int max_value(int range_value[], int range){
	int maksimum = 0;
	for (int i = 0; i < range; i++)
	{
		if(maksimum < range_value[i]){
			maksimum = range_value[i];
		}
	}
	return maksimum;
}

void arrBuild(node* key, value_node* value, char **arr_key, char ***arr_value){
	int counter = 0, i;
	while (key != NULL){
		strcpy(arr_key[counter], key->data);
		i = 0;
		while (value->value != NULL){
			if (value->value->next == NULL){
				strcpy(arr_value[counter][i], value->value->data);
			}
			else {
				strcpy(arr_value[counter][i], value->value->data);
			}
			i += 1;
			value->value = value->value->next;
		}
		value = value->nexts;
		key = key->next;
		counter += 1;
	}
}

int main(){
    node *words;
    node *linked_list;
    node *key, *key1, *key2;
    value_node *value, *value1, *value2;
    int ngram, range_key, maksimum = 0;
    readFile(&words);
    printf("Input N-gram : ");
    scanf("%d",&ngram);
    linked_list = link_gram(words, ngram);
    key = link_key(words, linked_list, ngram);
    value = link_value(key, linked_list, ngram);

	display_LUT(key, value);

    key1 = link_key(words, linked_list, ngram);
    value1 = link_value(key, linked_list, ngram);

    key2 = link_key(words, linked_list, ngram);
    value2 = link_value(key, linked_list, ngram);

	range_key = count_key(key, value);
	printf("\nrange : %d", range_key);

	int *range_value = (int*)malloc(range_key*sizeof(int));

	count_value(key1,value1, range_value);
	maksimum = max_value(range_value, range_key);
	printf("\nMaksimum_value : %d", maksimum);

	char **arrKey = (char**) malloc(range_key*sizeof(char*));
	for (int i = 0; i < range_key; i++)
	{
		arrKey[i] = (char*) malloc(100*sizeof(char));
	}

	char **arrKey_temp = (char**) malloc(range_key*sizeof(char*));
	for (int i = 0; i < range_key; i++)
	{
		arrKey_temp[i] = (char*) malloc(100*sizeof(char));
	}

	char ***arrValue = (char***) malloc(range_key*sizeof(char**));
	for (int i = 0; i < range_key; i++)
	{
		arrValue[i] = (char**) malloc(range_value[i]*sizeof(char*));
		for (int j = 0; j < range_value[i]; j++)
		{
			arrValue[i][j] = (char*) malloc(100*sizeof(char));
		}
	}

	arrBuild(key2, value2, arrKey, arrValue);
	output(arrKey, arrValue, range_value, range_key, ngram);
}
