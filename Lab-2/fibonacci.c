#include<stdio.h>

int counter = 0;

int main(){
    int f0 = 1, f1 = 1, f,n;
    printf("Enter positive range: ");
    scanf("%d", &n);
    printf("\t%d\t%d", f0, f1);

    for(int i = 0; i < n-2; i++){
        counter++;
        f = f0 + f1;
        printf("\t%d", f);
        f0 = f1;
        f1 = f;
    }
}