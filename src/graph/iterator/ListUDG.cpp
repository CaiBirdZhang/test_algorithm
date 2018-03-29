#include "graph/iterator/ListUDG.h"
#include <queue>
#include <iostream>

using namespace std;

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
    // 初始化"顶点数"和"边数"
    mVexNum = vlen;
    mEdgNum = elen;
     // 初始化"邻接表"的顶点
    for (int i = 0; i < mVexNum; ++i)
    {
        mVexs[i].data = vexs[i];
        mVexs[i].firstEdge = NULL;
    }
    // 初始化"邻接表"的边
    for (int j = 0; j < mEdgNum; ++j)
    {
        int p1 = getPosition(edges[j][0]);
        int p2 = getPosition(edges[j][1]);

        ENode *node1 = new ENode;
        node1->ivex = p2;
        // 将node1链接到"p1所在链表的末尾"
        if(mVexs[p1].firstEdge == NULL)
            mVexs[p1].firstEdge = node1;
        else
            linkLast(mVexs[p1].firstEdge, node1);

        ENode *node2 = new ENode;
        node2->ivex = p1;
        // 将node2链接到"p2所在链表的末尾"
        if(mVexs[p2].firstEdge == NULL)
            mVexs[p2].firstEdge = node2;
        else
            linkLast(mVexs[p2].firstEdge, node2);
    }
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
        if (ch == mVexs[i].data)
        {
            return i;
        }
    }
    return -1;
}

// 将node节点链接到list的最后
void ListUDG::linkLast(ENode *list, ENode *node)
{
    ENode *p = list;
    while (p->nextEdge != NULL)
    {
        p = p->nextEdge;
    }
    p->nextEdge = node;
}

// 深度优先搜索遍历图
void ListUDG::DFS()
{
    int visited[mVexNum];
    for (int j = 0; j < mVexNum; ++j)
    {
        visited[j] = 0;
    }
    // 所有的顶点，防止有非连通的
    for (int i = 0; i < mVexNum; ++i)
    {
        if (visited[i] == 0)
        {
            DFS(i, visited);
        }
    }
    cout << endl;
}
// 深度优先搜索遍历图的递归实现
void ListUDG::DFS(int i, int *visited)
{
    visited[i] = 1;
    cout << mVexs[i].data << " ";
    ENode* node = mVexs[i].firstEdge;
    for (; node != NULL; node = node->nextEdge)
    {
        // 下一个顶点是否没访问
        if (visited[node->ivex] == 0)
        {
            DFS(node->ivex, visited);
        }
    }
}

// 广度优先搜索（类似于树的层次遍历）
void ListUDG::BFS()
{
    int visited[mVexNum];
    for (int j = 0; j < mVexNum; ++j)
    {
        visited[j] = 0;
    }
    queue<VNode> qu;
    // 所有的顶点，防止有非连通的
    for (int i = 0; i < mVexNum; ++i)
    {
        // 入栈是打印
        if (visited[i] == 0)
        {
            visited[i] = 1;
            cout << mVexs[i].data << " ";
            qu.push(mVexs[i]);
        }
        while (!qu.empty())
        {
            VNode vnode = qu.front();
            qu.pop();
            ENode *enode = vnode.firstEdge;
            // 所有邻接点
            for (; enode != NULL; enode = enode->nextEdge)
            {
                if (visited[enode->ivex] == 0)
                {
                    visited[enode->ivex] = 1;
                    cout << mVexs[enode->ivex].data << " ";
                    qu.push(mVexs[enode->ivex]);
                }
            }
        }
    }
    cout << endl;
}

// 打印邻接表图
void ListUDG::print()
{
    int i;
    ENode *node;

    cout << "List Graph:" << endl;
    for (i = 0; i < mVexNum; ++i)
    {
        cout << i << "(" << mVexs[i].data << "): ";
        node = mVexs[i].firstEdge;
        while (node != NULL)
        {
            cout << node->ivex << "(" << mVexs[node->ivex].data << ") ";
            node = node->nextEdge;
        }
        cout << endl;
    }
}


}
