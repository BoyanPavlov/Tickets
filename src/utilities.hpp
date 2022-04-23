#ifndef _UTILITIES_
#define _UTILITIES_

void strCpy(char *dest, const char *src);

int strLen(const char *str);

int strCmp(const char *text1, const char *text2);

int stoi_my(const char *text);

bool isNum(char c);

void clearString(char *&str);

void strDub(char *dest, const char *src);

char *allocateStr(int size);
#endif // _UTILITIES_