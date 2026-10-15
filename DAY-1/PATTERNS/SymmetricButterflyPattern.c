#include<stdio.h>
int main(){
    int N=5;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=i;j++){
            printf("*");
        }
        for(int j=1;j<=2*(N-i);j++){
            printf(" ");
        }
        for(int j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }

    for(int i=N;i>=1;i--){
        for(int j=1;j<=i;j++){
            printf("*");
        }
        for(int j=1;j<=2*(N-i);j++){
            printf(" ");
        }
        for(int j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }
}