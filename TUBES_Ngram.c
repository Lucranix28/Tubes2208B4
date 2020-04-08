// Coba-Coba Punya Ian
// Testing dari Luck
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int check (char str[], char (*arr)[100], int i){
	int result = -1;
	for (int a = 0; a<i; a++){
		if (strcmp(str,arr[a]) == 0){
			result = a;
		}
	}
	return (result);
}

void display (char key[1000][100], char value[1000][10][100], int i, int arr[], int gram){
	printf("|\tKey  %-15s|\tValue\n","");
	for (int num = 0; num<i-gram; num++){
		printf("|\t%-20s|\t{",key[num]);
		for (int x = 0; x<arr[num];x++){
			if (x==(arr[num]-1)){
				printf(" %s ",value[num][x]);
			}
			else {
				printf(" %s ,",value[num][x]);
			}
		}
		printf("}\n");
	}
}

int main(){
	FILE *filebaca;
	int i, len, n, index, index_value;
	char input[100];
	char temp[100];
	char temp_2[1000];
	char arr_gram[1000][100];
	char temp_gram[100];
	char temp_gram_next[100];
	char key[1000][100];
	char value[1000][10][100];
	int arr_index_value[1000];
	char arr_string[1000][100];
	char *token;
	char *temp_tok;
	printf("Masukkan file external sebagai referensi: ");
    gets(input);
	filebaca = fopen(input,"r");
	i = 0;
	printf("\n");
	while (fgets(temp,100,filebaca) != NULL){
		printf("%s",temp);
		token = strtok(temp," ");
		while (token!=NULL){
			len=strlen(token);
			if(token[len-1]=='\n'){
				token[len-1]='\0';
			}
			strcpy(arr_string[i],token);
			token=strtok(NULL," ");
			i++;
		}	
	}
	printf("\n\nMasukkan n untuk n-gram : ");
	scanf("%d",&n);
	
	index=0;
	for(int x = 0; x<i; x++){
		strcpy(temp_2,"");
		for (int y = x; y<(x+n); y++){
			strcat(temp_2,arr_string[y]);
			strcat(temp_2," ");
		}
		strcpy(arr_gram[x],temp_2);
		if (check(temp_2,arr_gram,index-1)<0){
			strcpy(key[index],temp_2);
			index++;
		}
	}
	
	printf("\n");
	index_value = 0;
	for (int y=0; y<index; y++){
		for (int z=0; z<i-n; z++){
			strcpy(temp_gram,arr_gram[z]);
			
			strcpy(temp_gram_next,arr_gram[z+1]);
			
			if (strcmp(key[y],temp_gram)==0){
				temp_tok = strtok(temp_gram_next," ");
				for (int i =0; i<(n-1);i++){
					if (temp_tok!=NULL){
						temp_tok=strtok(NULL," ");
					}	
				}
				strcpy(value[y][index_value],temp_tok);
				index_value++;
			}
		}
		arr_index_value[y] = index_value;
		index_value = 0;
	}
	display(key,value,index,arr_index_value,n);
	return(0);
}
