/*

    created by monsherko on 02.01.2018

*/


#include <stdio.h>
#include <stdlib.h>

struct Task {
    int low, high;
};

struct Stack {
    struct Task* arr;
    int top;
};

struct Stack InitStack(int n) {
    struct Stack s;
    s.arr = (struct Task*)calloc(n, sizeof(struct Task));
    s.top = 0;
    return s;
}

void push(struct Stack* s, struct Task tmp) {
    s->arr[s->top++] = tmp;
}

struct Task pop(struct Stack* s) {
    return s->arr[--s->top];
}

void swap(int *a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}



int partition(int* arr, int l, int r) {
    int i = l - 1;
    while(l++ < r) {
        if(arr[l] <= arr[r]) {
            swap(arr+(++i),arr+l);
        }
    }
    swap(arr+i+1 ,arr+r);
    return i+1;
}



 void QuickSort(struct Stack* s, int* arr, int n) {

   push(s, (struct Task){0, n-1});

   for(int sign;s->top;) {

     struct Task tmp = pop(s);

     if (tmp.low < tmp.high) {
          push(s, (struct Task) {(sign = partition(arr, tmp.low, tmp.high))+1, tmp.high});
          push(s, (struct Task){tmp.low, sign-1});
      }
   }
}

int main(void) {

    int n;
    scanf("%d", &n);

    int* arr = (int*)calloc(n,sizeof(int));

    for(int i = 0; i < n; i++) {
        scanf("%d", arr+i);
    }

    struct Stack s = InitStack(n);

    QuickSort(&s, arr, n);

    free(s.arr);

    for(int i = 0; i < n; i++) {
        printf("%d ", *(arr+i));
    }

    free(arr);

    return 0;
}
