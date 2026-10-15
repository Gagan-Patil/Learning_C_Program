#include<stdio.h>
#include<stdlib.h>
int main(){
    int *arr=malloc(5*sizeof(int));
    arr[0]=10;
    arr[1]=20;
    arr[2]=30;
    //arr[3]=50;
    int *temp=realloc(arr,3*sizeof(int));
    arr=temp;
    arr[3]=100;
    arr[4]=50;

    for(int i=0;i<5;i++){
        printf("%d",arr[i]);
    }
    free(arr);
    free(temp);
}