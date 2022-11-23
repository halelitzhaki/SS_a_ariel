#include "NumClass.h"

int isPrime(int n)
{
    if(n <= 0) return 0;
    if (n == 2 || n == 1) return 1;
    for(int i = 2; i < n; i++)
    {
        if(n%i == 0) return 0;
    }
    return 1;
}

int isStrong(int n)
{
    int sum = 0, temp = n;
    while(temp>0)
    {
        int digit = temp % 10;
        int fact = 1;
        for(int j = 1; j<=digit; j++)
        {
            fact = fact * j;
        }
        sum+=fact;
        temp = (int)temp/10;
    }
    if(sum == n) return 1;
    return 0;
}