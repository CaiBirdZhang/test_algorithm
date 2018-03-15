#include "graph/iterator/MatrixUDG.h"
#include <queue>
#include <iostream>

using namespace std;

namespace iterator_t
{

MatrixUDG::MatrixUDG()
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
MatrixUDG::MatrixUDG(char vexs[], int vlen, char edges[][2], int elen)
{
    int i, p1, p2;

    // 初始化"顶点数"和"边数"
    mVexNum = vlen;
    mEdgNum = elen;
    // 初始化"顶点"
    for (i = 0; i < mVexNum; i++)
        mVexs[i] = vexs[i];

    // 初始化"边"
    for (i = 0; i < mEdgNum; i++)
    {
        // 读取边的起始顶点和结束顶点
        p1 = getPosition(edges[i][0]);
        p2 = getPosition(edges[i][1]);

        mMatrix[p1][p2] = 1;
        mMatrix[p2][p1] = 1;
    }
}

// 返回ch在mMatrix矩阵中的位置
int MatrixUDG::getPosition(char ch)
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

// 返回顶点v的第一个邻接顶点的索引，失败则返回-1
int MatrixUDG::firstVertex(int v)
{
    // 异常值判断
    if (v < 0 || v >= mVexNum)
        return -1;
    // 从一行开始
    for (int i = 0; i < mVexNum; ++i)
    {
        if (mMatrix[v][i] == 1)
        {
            return i;
        }
    }
    return -1;
}

// 返回顶点v相对于w的下一个邻接顶点的索引，失败则返回-1
int MatrixUDG::nextVertex(int v, int w)
{
    // 异常值判断
    if (v < 0 || w < 0 || v >= mVexNum || w >= mVexNum)
        return -1;
    // 从一行的某个位置
    for (int i = w + 1;i < mVexNum; ++i)
    {
        if (mMatrix[v][i] == 1)
        {
            return i;
        }
    }
    return -1;
}

/*
 * 读取一个输入字符
 */
char MatrixUDG::readChar()
{
    char ch;

    do {
        cin >> ch;
    } while(!((ch>='a'&&ch<='z') || (ch>='A'&&ch<='Z')));

    return ch;
}

/*
 * 打印矩阵队列图
 */
void MatrixUDG::print()
{
    int i,j;

    cout << "Martix Graph:" << endl;
    for (i = 0; i < mVexNum; i++)
    {
        for (j = 0; j < mVexNum; j++)
            cout << mMatrix[i][j] << " ";
        cout << endl;
    }
}

// 深度优先搜索遍历图
void MatrixUDG::DFS()
{
    int visited[mVexNum];
    for (int i = 0; i < mVexNum; ++i)
        visited[i] = 0;
    // 防止有不连通的点
    for (int j = 0; j < mVexNum; ++j)
    {
        if (visited[j] == 0)
        {
            DFS(j, visited);
        }
    }
}
// 深度优先搜索遍历图的递归实现
void MatrixUDG::DFS(int i, int *visited)
{
    // 访问标记
    visited[i] = 1;
    cout << mVexs[i] << " ";
    // 从第一个邻接顶点到顶点的下一个顶点
    for (int j = firstVertex(i); j >= 0; j = nextVertex(i, j))
    {
        if (visited[j] == 0)
        {
            DFS(j, visited);
        }
    }
}

// 广度优先搜索（类似于树的层次遍历）
void MatrixUDG::BFS()
{
    if (mVexNum <= 0)
        return;
    // 初始化标记位
    int visited[mVexNum];
    for (int i = 0; i < mVexNum; ++i)
        visited[i] = 0;
    queue<char> qu;
    // 所有顶点
    for (int i = 0; i < mVexNum; ++i)
    {
        if (visited[i] == 0)
        {
            // 一个顶点
            visited[i] = 1;
            cout << mVexs[i] << " ";
            qu.push(mVexs[i]);
        }
        while (!qu.empty())
        {
            char c = qu.front();
            int pos = getPosition(c);
            qu.pop();
            // 顶点的邻接点放入队列
            for (int j = firstVertex(pos); j >= 0; j = nextVertex(pos, j))
            {
                if (visited[j] == 0)
                {
                    visited[j] = 1;
                    cout << mVexs[j] << " ";
                    qu.push(mVexs[j]);
                }
            }
        }
    }
}








}