#include "NumClass.h"

int isArmstrong(int n)
{
    int temp = n, numOfDigits = 0, sum = 0, power, digit;
    while (temp > 0)
    {
        numOfDigits++;
        temp = (int)temp/10;
    }
    temp = n;
    for(int i=0; i<numOfDigits; i++)
    {
        digit = temp % 10;
        power = (int)pow(digit, numOfDigits);
        sum+= power;
        temp = (int)temp/10;
    }
    if(sum==n) return 1;
    return 0;
}

int isPalindrome(int n)
{
    int reversed = 0, temp = n, numOfDigits = 0;
    while (temp > 0)
    {
        numOfDigits++;
        temp = (int)temp/10;
    }
    temp = n;
    for(int i=numOfDigits; i>0; i--)
    {
        reversed += (temp%10)*(int)pow(10, i-1);
        temp = (int)(temp/10);
    }
    if(reversed == n) return 1;
    return 0;
}