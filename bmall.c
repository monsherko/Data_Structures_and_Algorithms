/*

    created by monsherko on 7.01.2018

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* prefixFunc(char* str)
{

  int len = strlen(str);
  int* base = (int*)calloc(len, sizeof(int));

  for(int t = 0, i = 1; i < len; ++i )
  {
    for(;t > 0 && str[i] != str[t]; t = base[t-1])
    {}

    t += (str[i] == str[t]) ? 1 : 0;

    base[i] = t;
  }

  return base;
}

int main(int argc, char** argv) {

  int lenFirst = strlen(argv[1]);
  int lenSecond = strlen(argv[2]);
  char* str = (char*) calloc(lenFirst+1, sizeof(char));

  for(int i = 0; i < lenFirst; i++) {
    str[i] = argv[1][i];
  }

  int* prefArr = prefixFunc(str);

  for(int q = 0, k = 0; k < lenSecond; k++) {
    for(;q > 0 && argv[1][q] != argv[2][k]; q = prefArr[q-1])
      ;
    if(argv[1][q] == argv[2][k]) {
      ++q;
    }
    if(q == lenFirst) {
      k = k - lenFirst + 1;
      q = 0;
      printf("%d\n",k );
    }

  }

  free(prefArr);
  free(str);

  return 0;
}
