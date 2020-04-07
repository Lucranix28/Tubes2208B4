//scan input paragraf


void readFile(arr[][]){
    FILE *fp;

    int loop = 0;
    int filename[64];
    int temp[1024][1024];
    int index = 0;
    int i_last = 0;
    int j_last = 0;
    int isBreak = 0;

    printf("File: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");

    while(!feof(fp)){
        fgets(temp[loop], 1024, fp);
        loop++;
    }

    while(i_last <= loop){
        for (int i = 0; i < 1024; i++){
            for (int j = 0; j < 1024; j++){
                if (temp[i_last][j + j_last] == ' '){
                    last++;
                    break;
                }
                if (temp[i_last][j + j_last] == '\0'){
                    isBreak = 1;
                    break;
                }
                arr[i][j] = temp[i_last][j + j_last]
                last++;
            }

            if (isBreak == 1){
                break;
            }
        }
        //reset
        isBreak = 0;
        j_last = 0;

        //move 1 index down
        i_last++;
    }
}