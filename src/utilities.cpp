#include "utilities.hpp"
#include <iostream>

void strCpy(char *dest, const char *src)
{
    while (*src)
    {
        *dest++ = *src++;
    }
    *dest = '\0';
}

int strLen(const char *str)
{
    int counter = 0;
    while (*str)
    {
        counter++;
        str++;
    }
    return counter;
}

int strCmp(const char *text1, const char *text2)
{
    if (text1 == text2)
    {
        return 0;
    }

    if (!text1 || !text2)
    {
        return -1;
    }

    while (*text1 && *text1 == *text2)
    {
        text1++;
        text2++;
    }
    return *text1 - *text2;
}

bool isNum(char c)
{
    if ('0' <= c && c <= '9')
    {
        return true;
    }
    return false;
}

int stoi_my(const char *text)
{
    int num = 0;
    int sign = 1;
    if (*text == '-')
    {
        sign = -1;
        text++;
    }
    if (*text == '+')
    {
        text++;
    }

    while (*text)
    {
        if (isNum(*text))
        {
            num = num * 10 + (*text - '0');
            text++;
        }
        else
        {
            throw std::invalid_argument("given text, not a number\n");
        }
    }

    return num * sign;
}