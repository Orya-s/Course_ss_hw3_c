#include <stdio.h>
#include <string.h>
#include "txtfind.h"

#define LINE 256*250
#define WORD 30


int main() {

    char stringInput[LINE];
    char keyWord[WORD];
    char optionA = 'a';
    char optionB = 'b';
    char state = ' ';
    char txt[LINE];


    char *first = (fgets(stringInput, LINE, stdin));
    char s = ' ';
    int counter = 0;
    while ((first[counter]) != s) {
        keyWord[counter] = first[counter];
        counter++;
    }
    if ((first[counter]) == s) {
        if (first[counter + 1] == optionA) {
            state = optionA;
        }
        if (first[counter + 1] == optionB) {
            state = optionB;
        }
    }


    fgets(stringInput,LINE,stdin);
    int i= 0;
    while(fgets(stringInput,LINE,stdin)){
        char *temp= stringInput;
        counter= 0;
        while (*(temp+counter) != '\n'){
            txt[i]= *(temp+counter);
            i++;
            counter++;
        }
        txt[i]= '.';
        i++;
    }

    if (state==optionA){
        optionAfunc(txt,keyWord);
    }
    else{
        optionBfunc(txt,keyWord);
    }
    return 0;
}


void optionAfunc(char* txt,char* keyWord){
    char *pointer = strtok(txt,".");

    while (pointer != NULL) {
        if (strstr(pointer, keyWord) != NULL)
            printf("%s\n", pointer);

        pointer = strtok(NULL,".");
    }
}


void optionBfunc(char* txt,char* keyWord){
    char *word = strtok(txt,". \t\r");
    while (word != NULL) {
        if (strlen(word) == strlen(keyWord) || strlen(word) == (strlen(keyWord)+1)){
            if(similar(word,keyWord)){
                printf("%s\n",word);
            }
        }
        word = strtok(NULL,". \t\r");
    }
}

int similar(char* word, char* keyWord){
    int dealBreaker = 0;
    int j = 0;
    for(int i=0; i< strlen(word); i++){

        if(word[i] == keyWord[j]) {
            j++;
            if(j == strlen(keyWord)) {
                return 1;
            }
        }
        else {
            if(dealBreaker == -1) {
                return 0;
            }
            dealBreaker = -1;
        }
    }

    return 0;
}
