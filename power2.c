/*

    created by monsherko on 01.01.2018

*/

#include <stdio.h>
#include <stdlib.h>

int compareTwoPower(int elem) {
  return (elem != 0 && !(elem& (elem- 1))) ? 1 : 0;
}

int all_combinations (int max, int n, int* base) {

  int count = 0;

  for (int i = 1, sum = 0; i < max; ++i, sum = 0)
  {
      for (int j=0; j<n; ++j)
          sum += (i >> j & 1) ? base[j] : 0;

      count += compareTwoPower(sum);

  }

  return count;
}

int main() {

  int n;
  scanf("%d", &n);

  int* base =(int*)calloc(n,sizeof(int));

  for(int i = 0; i < n; i++) {
    scanf("%d", &base[i]);
  }


  printf("%d\n", all_combinations(1<<n, n, base));
  free(base);

  return 0;
}
