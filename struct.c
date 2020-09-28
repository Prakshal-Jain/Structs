#include <stdio.h>
#include <string.h>

struct keyword{
    char *word;
    int occur;
};

struct keyword keys[5] = {
    {"while", 0},
    {"for", 0},
    {"int", 0},
    {"if", 0},
    {"else", 0},
};

void search(char *str){
    printf("%s\n", str);
    for(int i = 0; i <= 5; ++i){
        if(strcmp(str, keys[i].word)){
            ++(keys[i].occur);
            break;
        }
    }
}

void check(char *str){
    char word[50];
    for(int t = 0; word[t] != '\0'; ++t){
        word[t] = '\0';
    }
    int i = 0;
    while(++str){
        if(*str == ' '){
            ++i;
            word[i] = '\0';
            search(word);
            for(int t = 0; word[t] != '\0'; ++t){
                word[t] = '\0';
            }
            i = 0;
        }
        else if(*str == '\0'){
            break;
        }
        else{
            word[i] = *str;
            ++i;
        }
    }
}

int main(){
    char samplestr[300] = "He is a good boy, while he like playing if he want.";
    check(samplestr);
    for(int i = 0; i <= 5; ++i){
        printf("(%s -> %d)\n", keys[i].word, keys[i].occur);
    }
}
