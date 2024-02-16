#include <stdio.h>
#include <string.h>

#define MAX_DIGITS 100

void addLargeIntegers(char num1[], char num2[], char result[]) 
{
    int carry = 0;
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = (len1 > len2) ? len1 : len2;
    int i = 0;

    for (; i < maxLen || carry; i++) 
    {
        int digit1 = (i < len1) ? (num1[len1 - 1 - i] - '0') : 0;
        int digit2 = (i < len2) ? (num2[len2 - 1 - i] - '0') : 0;
        int sum = digit1 + digit2 + carry;
        result[maxLen - 1 - i] = (sum % 10) + '0';
        carry = sum / 10;
    }

    result[maxLen] = '\0';
}

void subtractLargeIntegers(char num1[], char num2[], char result[]) 
{
    int borrow = 0;
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int maxLen = (len1 > len2) ? len1 : len2;
    int i = 0;

    for (; i < maxLen; i++) 
    {
        int digit1 = (i < len1) ? (num1[len1 - 1 - i] - '0') : 0;
        int digit2 = (i < len2) ? (num2[len2 - 1 - i] - '0') : 0;
        int diff = digit1 - digit2 - borrow;

        if (diff < 0) 
        {
            diff += 10;
            borrow = 1;
        } else 
        {
            borrow = 0;
        }

        result[maxLen - 1 - i] = diff + '0';
    }

    result[maxLen] = '\0';
}

int main() {
    char num1[MAX_DIGITS + 1], num2[MAX_DIGITS + 1], sum[MAX_DIGITS + 2], difference[MAX_DIGITS + 1];

    printf("Enter the first integer (at least 10 digits): ");
    scanf("%s", num1);

    printf("Enter the second integer (at least 10 digits): ");
    scanf("%s", num2);

    addLargeIntegers(num1, num2, sum);
    subtractLargeIntegers(num1, num2, difference);

    printf("Sum: %s\n", sum);
    printf("Difference: %s\n", difference);

    return 0;
}