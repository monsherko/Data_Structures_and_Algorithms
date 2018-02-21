/*

    created by monsherko on 26.12.2017

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE_WORD 16

struct s_table
{
    int i, v;
    struct s_table *next;
};

struct s_table* init(int i, int v)
{
  struct s_table* elem = calloc(1, sizeof(struct s_table));
  elem->i = i;
  elem->v = v;
  return elem;
}

struct s_table** init_table(int m)
{
  struct s_table** arr = calloc(m, sizeof(struct s_table*));
  return arr;
}

int find(struct s_table* arr, int index)
{
  struct s_table* elem = arr;
  for(; elem != NULL && elem->i != index; elem = elem->next)
  {}
  return elem == NULL ? 0 : elem->v;
}

void free_list(struct s_table* elem)
{
  elem != NULL ? free_list(elem->next) : free(elem);
}

void free_table(struct s_table** t, int size) {
  for(int j = 0; j < size; j++) {
    free_list(t[j]);
  }
  free(t);
}


int main()
{
  int i, m, index, value;
  scanf("%d%d", &i, &m);


  struct s_table** t = init_table(m);
  char* word         = calloc(SIZE_WORD, sizeof(char));

  for(int j = 0; j < i; ++j) {
    scanf("%s", word);
    if(!strcmp(word, "ASSIGN")) {
      scanf("%d%d", &index, &value);
      struct s_table* elem = init(index, value);
      elem->next = t[index % m];
      t[index % m] = elem;
    } else if (!strcmp(word, "AT"))
    {
      scanf("%d",&index);
      printf("%d\n", find(t[index % m], index));
    }
  }

  free_table(t, m);

  free(word);

  return 0;
}
