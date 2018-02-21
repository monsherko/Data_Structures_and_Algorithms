/*

    created by monsherko on 03.01.2018

*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>


#define SIZE_STRING 128
#define CONST_SIZE 4
#define DELIM " \0"

void csort(char* , char*);
void secondStep(char*, int*,int*, int);
void firstStep(char*, int* , int);
void clearArr(int**, int);
int** init(int, int);
int wcount(char*);





int main(void) {

    char* src = (char*) calloc(SIZE_STRING, sizeof(char));
    char* dest = (char*) calloc(SIZE_STRING, sizeof(char));
    gets(src);
    csort(src, dest);
    puts(dest);
    free(src);
    free(dest);
    return 0;
}




void csort(char *src, char *dest) {

  strcpy(dest,src);

  int word_count = wcount(dest);

  memset(dest,0,SIZE_STRING);

  int len = strlen(src);

  int** count =  init(CONST_SIZE, len);

  firstStep(src, count[0], len);

  secondStep(src, count[0], count[1], len);

  for(int i = 0; i < word_count; i++)
    for(int j = i; j < word_count; j++)
      count[0][i] > count[0][j] ?  count[2][i]++ :  count[2][j]++;


  for(int i = 0; i < word_count; count[3][count[2][i]] = count[1][i++])
                            ;

  for(int i = 1, k = 0, j = 0; i  <= word_count;dest[j++] = ' ',i++)
    for(k = count[3][i];src[k] != ' ' && src[k] != '\0'; dest[j++] = src[k++])
                            ;
  clearArr(count, CONST_SIZE);
}

int wcount(char * s) {
    return ( strtok(s, DELIM) ) ? 1 + wcount(NULL) : 0;
}

int** init(int const_size, int len) {
  int** count = (int**) calloc(const_size, sizeof(int*));
  for(int i = 0; i < const_size; i++) {
    count[i] = (int*) calloc(len, sizeof(int));
  }
  return count;
}

void clearArr(int** base, int size) {
  for(int i = 0; i < size; free(base[i++]))
              ;
  free(base);
}

void firstStep(char* src, int* count, int len) {
  for(int i = 0, k = 0; i < len; i++)
    if(src[i] != ' ') {
      count[k]++;
      k = src[i+1] == ' ' ? k + 1: k;
    }
}

void secondStep(char* src, int* countOne,int* countTwo, int len) {
  for(int j = 0, t = 0; j < len;j++)
        if(src[j] != ' ') {
              countTwo[t] = j;
              j+=countOne[t++];
        }
}
