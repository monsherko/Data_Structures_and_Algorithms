/*

    created by monsherko on 04.01.2018

*/


#include <stdio.h>
#include <stdlib.h>

typedef struct Node node;
typedef struct Pair pair;

struct Pair
{
    int value;
    unsigned long k;
};

struct Node
{
        int balance, height;
	pair elem;
	node *l, *r;
};


node* InitNode(unsigned int k, int i) {
  node* val = calloc(1,sizeof(struct Node));
  val->balance = 0;
  val->height = 1;
  val->elem = (struct Pair){i, k};
  val->r = val->r = NULL;
  return val;
}

int sign(node* val) {
  return val? val->height : 0;
}

void incHeigh(node* val, int comp) {
  if (comp > 0 ) {
    val->height = sign(val->r) + 1;
  } else {
    val->height = sign(val->l) + 1;
  }
}

//key = 0 - Left ,  1 - right
node* Rotate(node* val, int key) {
  node* tmp;
  if(key == 1) {
    tmp = val->l;
    val->l = tmp->r;
    tmp->r = val;
  } else {
    tmp = val->r;
    val->r = tmp->l;
    tmp->l = val;
  }

  incHeigh(val, sign(val->r) - sign(val->l));
  incHeigh(tmp, sign(tmp->r) - sign(tmp->l));

  return tmp;
}

node* InsertAVL(node* val, unsigned int k, int index) {
  if(!val)
    return InitNode(k, index);

  if( k > val->elem.k ) {
    val->r = InsertAVL(val->r, k, index);

  } else {
    val->l = InsertAVL(val->l, k, index);
  }

  val->balance = sign(val->r) - sign(val->l);
  incHeigh(val, val->balance);

  if(val->balance == 2) {
    if(val->r->balance == -1) {
      val->r = Rotate(val->r, 1);
    }
    return Rotate(val, 0);
  }
  if(val->balance == -2) {
    if(val->l->balance == 1) {
      val->l = Rotate(val->l, 0);
    }
    return Rotate(val, 1);
  }
  return val;
}

node* find(node* avl, unsigned int k) {
  node* tmp = avl;
  for(;tmp != NULL && tmp->elem.k != k; ) {
    if(k < tmp->elem.k) {
      tmp = tmp->l;
    } else {
      tmp = tmp->r;
    }
  }

  return tmp;
}

void freeAVL(struct Node *val)
{
  if (!val) {
    return;
  } else {
    freeAVL(val->l);
    freeAVL (val->r);
    free(val);
  }
}

int main(void) {

  int n, i, index;
  unsigned int hash;

  scanf("%d ", &n);
  char *str = calloc(n+1, sizeof(char));

  gets(str);
  node* avl = NULL;
  node* tmp = NULL;

  for(i = index = 0; str[i]; ++i) {
//enum for ... lol
    if (str[i] == '+') {
      printf("SPEC 0\n");
    } else if (str[i] == '-') {
      printf("SPEC 1\n");
    } else if (str[i] == '*') {
      printf("SPEC 2\n");
    } else if (str[i] == '/') {
      printf("SPEC 3\n");
    } else if (str[i] == '(') {
      printf("SPEC 4\n");
    } else if (str[i] == ')') {
      printf("SPEC 5\n");
    } else if (str[i] < 58 && str[i] > 47) {
      printf("CONST ");
      for(;str[i] < 58 && str[i] > 47;i++) {
        printf("%c", str[i]);
      }
      printf("\n");
      i--;
    } else if (str[i] != ' '){
      hash = 0;
      printf("IDENT ");
      while(str[i] > 47 ) {
         hash += str[i]^32;
         hash = str[i] + (hash << 2) + (hash << 16) - hash;
         i++;
      }
      i--;
      hash &= 0xFFFAAA;
      hash += hash^3;

      if((tmp = find(avl, hash))) {
        printf("%d\n", tmp->elem.value);
      } else {
        printf("%d\n", index);
        avl = InsertAVL(avl, hash, index++);
      }
    } else if( str[i] == ' ');

  }

  freeAVL(avl);
  free(str);

  return 0;
}
