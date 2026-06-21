#include <stdio.h>
#include<math.h>

int main(){

    printf("What are you upto today?\n"); //this is the first thing that should pop up when user opens calc.

    int a, b, sum;
    printf("Enter your first number:  ");
    scanf("%d", &a);

    printf("Enter your second number: ");
    scanf("%d", &b);

    sum = a+b;

    printf("Sum of them is:%d\n", sum);

    return 0;
}



    