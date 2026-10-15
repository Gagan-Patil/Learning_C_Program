#include<stdio.h>
int main(){
    char text[]="REVA";
    char *ptr=text;
    printf("%s\n",*ptr);
    printf("%s\n",text);
    while(*ptr!='\0'){
        printf("%s\n",*ptr);
        ptr++;
    }
    return 0;
}