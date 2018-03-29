#include "graph/dijkstra/ListUDG.h"
#include <iostream>
#include <queue>
#include <vector>
#include <iomanip>

using namespace std;

namespace dijkstra
{

/*
 * 创建邻接表对应的图(用已提供的数据)
 */
ListUDG::ListUDG(char vexs[], int vlen, EData *edges[], int elen)
{
    char c1, c2;
    int i, p1, p2;
    int weight;
    ENode *node1, *node2;

    // 初始化"顶点数"和"边数"
    mVexNum = vlen;
    mEdgNum = elen;
    // 初始化"邻接表"的顶点
    for(i = 0; i < mVexNum; ++i)
    {
        mVexs[i].data = vexs[i];
        mVexs[i].firstEdge = NULL;
    }

    // 初始化"邻接表"的边
    for(i = 0; i < mEdgNum; ++i)
    {
        // 读取边的起始顶点和结束顶点
        c1 = edges[i]->start;
        c2 = edges[i]->end;
        weight = edges[i]->weight;

        p1 = getPosition(c1);
        p2 = getPosition(c2);
        // 初始化node1
        node1 = new ENode();
        node1->ivex = p2;
        node1->weight = weight;
        // 将node1链接到"p1所在链表的末尾"
        if(mVexs[p1].firstEdge == NULL)
          mVexs[p1].firstEdge = node1;
        else
            linkLast(mVexs[p1].firstEdge, node1);
        // 初始化node2
        node2 = new ENode();
        node2->ivex = p1;
        node2->weight = weight;
        // 将node2链接到"p2所在链表的末尾"
        if(mVexs[p2].firstEdge == NULL)
          mVexs[p2].firstEdge = node2;
        else
            linkLast(mVexs[p2].firstEdge, node2);
    }
}

/*
 * 将node节点链接到list的最后
 */
void ListUDG::linkLast(ENode *list, ENode *node)
{
    ENode *p = list;

    while(p->nextEdge)
        p = p->nextEdge;
    p->nextEdge = node;
}

/*
 * 返回ch的位置
 */
int ListUDG::getPosition(char ch)
{
    int i;
    for(i = 0; i < mVexNum; ++i)
        if(mVexs[i].data == ch)
            return i;
    return -1;
}

/*
 * 获取边<start, end>的权值；若start和end不是连通的，则返回无穷大。
 */
int ListUDG::getWeight(int start, int end)
{
    ENode *node;

    if (start == end)
        return 0;

    node = mVexs[start].firstEdge;
    while (node != NULL)
    {
        if (end == node->ivex)
            return node->weight;
        node = node->nextEdge;
    }

    return INF;
}

/*
 * Dijkstra最短路径。
 * 即，统计图中"顶点vs"到其它各个顶点的最短路径。
 *
 * 参数说明：
 *       vs -- 起始顶点(start vertex)。即计算"顶点vs"到其它顶点的最短路径。
 *     prev -- 前驱顶点数组。即，prev[i]的值是"顶点vs"到"顶点i"的最短路径所经历的全部顶点中，位于"顶点i"之前的那个顶点。
 *     dist -- 长度数组。即，dist[i]是"顶点vs"到"顶点i"的最短路径的长度。
 */
void ListUDG::dijkstra(int vs, int prev[], int dist[])
{
    // 每个顶点是否已经找到最短
    int* flag = new int[mVexNum] ();
    // 初始化权值
    for (int i = 0; i < mVexNum; ++i)
    {
        dist[i] = getWeight(vs, i);
    }
    // 起始点
    flag[vs] = 1;
    dist[vs] = 0;
    // 所有顶点
    int min = INF;
    int tmpIndex;
    for (int i = 1; i < mVexNum; ++i)
    {
        min = INF;
        // 每次获取T(未排序)中最小的距离
        for (int j = 0; j < mVexNum; ++j)
        {
            if (flag[j] == 0 && dist[j] < min)
            {
                min = dist[j];
                tmpIndex = j;
            }
        }
        // 标记"顶点tmpIndex"为已经获取到最短路径
        flag[tmpIndex] = 1;
        //                                     min                getWeight
        // 更新最短路径信息，dis(vs, j) > dis(vs, tmpIndex) + dis(tmpIndex, j)
        for (int j = 0; j < mVexNum; ++j)
        {
            int tmp = getWeight(tmpIndex, j);
            tmp = (tmp == INF ? INF : (min + tmp)); // 防止溢出
            if (flag[j] == 0 && dist[j] > tmp)
            {
                dist[j] = tmp;
            }
        }
    }
    // 打印信息
    cout << "vertex(" << mVexs[vs].data << ") to other vertexs distance:" << endl;
    for (int i = 0; i < mVexNum; ++i)
    {
        cout << mVexs[vs].data << " => " << mVexs[i].data << " (" << dist[i] << ")" << endl;
    }
}





}