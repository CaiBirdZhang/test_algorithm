#include "graph/iterator/ListDG.h"
#include <queue>
#include <iostream>

using namespace std;

namespace iterator_t
{

ListDG::ListDG()
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
ListDG::ListDG(char vexs[], int vlen, char edges[][2], int elen)
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
    }
}

// 返回ch的位置
int ListDG::getPosition(char ch)
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
void ListDG::linkLast(ENode *list, ENode *node)
{
    ENode *p = list;
    while (p->nextEdge != NULL)
    {
        p = p->nextEdge;
    }
    p->nextEdge = node;
}

// 打印邻接表图
void ListDG::print()
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

/*
 * 拓扑排序
 *
 * 返回值：
 *     -1 -- 失败(由于内存不足等原因导致)
 *      0 -- 成功排序，并输入结果
 *      1 -- 失败(该有向图是有环的)
 */
int ListDG::topologicalSort()
{
    // 入度数组
    int *inDegree= new int[mVexNum] ();
    // 中间队列
    queue<VNode> qu;
    // 结果
    char sortResult[mVexNum];
    int resNum = 0;
    // 统计每个顶点的入度数
    for (int i = 0; i < mVexNum; ++i)
    {
        ENode* node = mVexs[i].firstEdge;
        // 每个顶点的每条链表
        while (node != NULL)
        {
            ++inDegree[node->ivex];
            node = node->nextEdge;
        }
    }
    // 将所有入度为0的顶点入队列
    for (int i = 0; i < mVexNum; ++i)
    {
        if (inDegree[i] == 0)
        {
            // 入栈
            qu.push(mVexs[i]);
            sortResult[resNum] = mVexs[i].data;
            ++resNum;
        }
    }
    // 队列非空
    while (!qu.empty())
    {
        VNode vnode = qu.front();
        qu.pop();
        ENode *enode = vnode.firstEdge;
        // 关联的节点的入度减1
        // 若减1之后，该节点的入度为0；则将该节点添加到队列中
        for (; enode != NULL; enode = enode->nextEdge)
        {
            --inDegree[enode->ivex];
            if (inDegree[enode->ivex] == 0)
            {
                // 入栈
                qu.push(mVexs[enode->ivex]);
                sortResult[resNum] = mVexs[enode->ivex].data;
                ++resNum;
            }
        }
    }
    delete[] inDegree;
    // 判断是否可以形成topologicalSort
    if (resNum != mVexNum)
    {
        cout << "get topologicalSort num different, get num = " << resNum << ", all num = " << mVexNum << endl;
        return 1;
    }
    // 可以形成topologicalSort
    cout << "topologicalSort result = " << sortResult << endl;
    return 0;
}



}
