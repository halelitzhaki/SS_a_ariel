#include "NumClass.h"

int main()
{
    int num1, num2;
    scanf("%d", &num1);
    scanf("%d", &num2);

    //is Armstrong
    printf("The Armstrong numbers are: ");
    for(int i=num1; i<=num2; i++)
    {
        if(isArmstrong(i)==1)
            printf("%d ", i);
    }
    printf("\n");

    //is palindrom
    printf("The Palindrom numbers are: ");
    for(int i=num1; i<=num2; i++)
    {
        if(isPalindrome(i)==1)
            printf("%d ", i);
    }
    printf("\n");

    //is prime
    printf("The Prime numbers are: ");
    for(int i=num1; i<=num2; i++)
    {
        if(isPrime(i)==1)
            printf("%d ", i);
    }
    printf("\n");

    //is strong
    printf("The Strong numbers are: ");
    for(int i=num1; i<=num2; i++)
    {
        if(isStrong(i)==1)
            printf("%d ", i);
    }
    printf("\n");

    return 0;
}