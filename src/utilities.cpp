#include "utilities.h"
#include <iostream>
#include <fstream>

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

void clearString(char *&str)
{
    delete[] str;
    str = nullptr;
}

char *allocateStr(int size)
{
    try
    {
        char *str = new char[size];
        return str;
    }
    catch (const std::bad_alloc &e)
    {
        std::cerr << e.what() << '\n';
    }
    return nullptr;
}

void strDub(char *&dest, const char *src)
{
    clearString(dest);
    if (!src)
    {
        std::cout << "null ptr given\n";
        return;
    }
    dest = allocateStr(strLen(src) + 1);
    strCpy(dest, src);
}

bool checkIfPathIsValid(char *path)
{
    std::ifstream in(path, std::ios::in);
    if (!in)
    {
        return false;
    }
    return true;
}

char *strCat(char *text1, char *text2)
{
    int len1 = strLen(text1);
    int len2 = strLen(text2);
    int len = len1 + len2;
    char *temp = new char[len + 1]();
    int i = 0;
    for (i = 0; i < len1; i++)
    {
        temp[i] = text1[i];
    }
    for (int j = 0; j < len2; j++)
    {
        temp[i] = text2[j];
        i++;
    }
    return temp;
}