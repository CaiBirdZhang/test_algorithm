#include "graph/iterator/ListUDG.h"

#include <iostream>

namespace iterator_t
{

ListUDG::ListUDG()
{

}

/*
 * 创建图(用已提供的矩阵)
 *
 * 参数说明：
 *     vexs  -- 顶点数组
 *     vlen  -- 顶点数组的长度
 *     edges -- 边数组
 *     elen  -- 边数组的长度
 */
ListUDG::ListUDG(char vexs[], int vlen, char edges[][2], int elen)
{
    mVexNum = vlen;
    mEdgNum = elen;




}

// 读取一个输入字符
char ListUDG::readChar()
{
    char ch;

    do {
        cin >> ch;
    } while(!((ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z')));

    return ch;
}

// 返回ch的位置
int ListUDG::getPosition(char ch)
{
    for (int i = 0; i < mVexNum; ++i)
    {
        // 找到char
        if (ch == mVexs[i])
        {
            return i;
        }
    }
    return -1;
}

// 将node节点链接到list的最后
void ListUDG::linkLast(ENode *list, ENode *node)
{

}

// 深度优先搜索遍历图
void ListUDG::DFS()
{

}
// 深度优先搜索遍历图的递归实现
void ListUDG::DFS(int i, int *visited)
{

}

// 广度优先搜索（类似于树的层次遍历）
void ListUDG::BFS()
{

}

// 打印邻接表图
void ListUDG::print()
{

}



}
