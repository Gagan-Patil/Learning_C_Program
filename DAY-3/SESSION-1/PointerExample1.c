#include<stdio.h>
int main(){
    int n=10;
    int *ptr=&n;
    int *ptr2=NULL;
    printf("%d",n);
    //printf("%p",(void *)&n);
    printf("%d",ptr2);
}