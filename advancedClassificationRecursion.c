#include "NumClass.h"

int numOfDigits(int n);
int isArmHelp(int n, int numOfDigits);
int reversed(int n);

int numOfDigits(int n)
{
    if(n==0)
        return 0;
    return numOfDigits((int)n/10)+1;
}

int isArmstrong(int n)
{
    if(n==isArmHelp(n, numOfDigits(n))) return 1;
    return 0;
}

int isArmHelp(int n, int numOfDigits)
{
    if((int)n/10==0)
        return (int)pow(n%10, numOfDigits);
    return isArmHelp((int)n/10, numOfDigits)+(int)pow(n%10, numOfDigits);
}

int isPalindrome(int n)
{
    if(n==reversed(n)){
        return 1;
    }
    return 0;
}

int reversed(int n)
{
    if(n == 0) 
        return 0;
    else
        return (n%10 * (int)pow(10, numOfDigits(n)-1) + reversed((int)n/10));
}