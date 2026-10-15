#include<stdio.h>
#include<stdlib.h>
int main(){
    int *ptr=malloc(sizeof(int));
    *ptr=100;
    printf("%d\n\n",*ptr);
    free(ptr);
    printf("%p",*ptr);
}