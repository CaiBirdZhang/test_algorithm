#ifndef KMP_H
#define KMP_H

void getNext(const char* targetStr, const int length, int* next);
int kmp(const char* text, const char* targetStr);

#endif