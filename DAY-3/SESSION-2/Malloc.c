#include<stdio.h>
#include<stdlib.h>
int main(){
    //int n=5;
    int *ptr=(int *)malloc(4*sizeof(int));
    ptr[0]=10;
    ptr[1]=20;  
    printf("%d %d",ptr[0],ptr[1]);
    free(ptr);
}