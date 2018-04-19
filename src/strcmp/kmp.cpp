#include "strcmp/kmp.h"
#include <iostream>
#include <cstring>

using namespace std;

void getNext(const char* targetStr, const int length, int* next)
{
    next[0] = 0;
    int curMatchCnt = 0;
    for (int i = 1; i < length; ++i)
    {
        // 找到字符串最大匹配数
        while (curMatchCnt > 0 && targetStr[i] != targetStr[curMatchCnt])
        {
            curMatchCnt = next[curMatchCnt];
        }
        // 确认字符串相同的个数
        if (targetStr[i] == targetStr[curMatchCnt])
        {
            ++curMatchCnt;
        }
        // 赋值
        next[i] = curMatchCnt;
    }
    for (int i = 0; i < length; ++i)
    {
        cout << next[i];
    }
}

int kmp(const char* text, const char* targetStr)
{
    // 返回值
    int ret_pos = -1;
    // 获取长度
    int textLength = strlen(text);
    int targetLength = strlen(targetStr);
    int* next = new int[targetLength+1] ();
    // 获取next数组
    getNext(targetStr, targetLength, next);
    int curMatchCnt = 0;
    for (int i = 0; i < textLength; ++i)
    {
        // 找到字符串最长匹配数
        while (curMatchCnt > 0 && text[i] != targetStr[curMatchCnt])
        {
            curMatchCnt = next[curMatchCnt];
        }
        // 确认字符串相同的个数
        if (text[i] == targetStr[curMatchCnt])
        {
            ++curMatchCnt;
        }
        if (curMatchCnt == targetLength)
        {
            // 从1开始
            ret_pos = i - curMatchCnt + 1;
        }
    }
    delete[] next;
    return ret_pos;
}
