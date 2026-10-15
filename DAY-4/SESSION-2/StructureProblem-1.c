#include<stdio.h>
struct Address{
    char village[100];
    int pincode;
};
struct Member{
    int id;
    char name[100];
    double shareCapital;
    struct Address address;
};
int main(){
    struct Member array[1000];
    int n;
    double total=0;
    printf("Enter the number of members: \n");
    scanf("%d",&n);
    int maximumShareIndex=0;

    for(int i=0;i<n;i++){
        scanf("%d\n",&array[i].id);
        scanf("%s\n",array[i].name);
        scanf("%lf\n",&array[i].shareCapital);
        scanf("%s\n",array[i].address.village);
        scanf("%d\n",&array[i].address.pincode);

        total=total+array[i].shareCapital;
        if(array[i].shareCapital > array[maximumShareIndex].shareCapital){
            maximumShareIndex=i;
        }
    }

    for(int i=0;i<n;i++){
        printf("%d\n",array[i].id);
        printf("%s\n",array[i].name);
        printf("%lf\n",array[i].shareCapital);
        printf("%s\n",array[i].address.village);
        printf("%d\n",array[i].address.pincode);
    }
    printf("\n\nthe total share holding:%lf\n",total);
    printf("%d %s %lf",array[maximumShareIndex].id,array[maximumShareIndex].name,array[maximumShareIndex].shareCapital);
}