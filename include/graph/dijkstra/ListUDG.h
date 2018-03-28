#ifndef DIJKSTRA_LISTUDG_H
#define DIJKSTRA_LISTUDG_H

namespace dijkstra
{

// 示例类：边的结构体(用来演示)
class EData
{
public:
    char start; // 边的起点
    char end;   // 边的终点
    int weight; // 边的权重

public:
    EData(){}
    EData(char s, char e, int w):start(s),end(e),weight(w){}
};

// 邻接表
class ListUDG
{
public:
    static const int MAX = 100;
    static const int INF = (~(0x1<<31)); // 最大值(即0X7FFFFFFF)

private: // 内部类
    // 邻接表中表对应的链表的顶点
    class ENode
    {
        int ivex;           // 该边所指向的顶点的位置
        int weight;         // 该边的权
        ENode *nextEdge;    // 指向下一条弧的指针
        friend class ListUDG;
    };

    // 邻接表中表的顶点
    class VNode
    {
        char data;          // 顶点信息
        ENode *firstEdge;   // 指向第一条依附该顶点的弧
        friend class ListUDG;
    };

private: // 私有成员
    int mVexNum;             // 图的顶点的数目
    int mEdgNum;             // 图的边的数目
    VNode mVexs[MAX];

public:
    // 创建邻接表对应的图(自己输入)
    ListUDG() {}
    // 创建邻接表对应的图(用已提供的数据)
    ListUDG(char vexs[], int vlen, EData *edges[], int elen);
    ~ListUDG() {}

    // 深度优先搜索遍历图
    void DFS();
    // 广度优先搜索（类似于树的层次遍历）
    void BFS();
    // 打印邻接表图
    void print();
    // prim最小生成树
    void prim(int start);
    // 克鲁斯卡尔（Kruskal)最小生成树
    void kruskal();
    // Dijkstra最短路径
    void dijkstra(int vs, int vexs[], int dist[]);

private:
    // 读取一个输入字符
    char readChar();
    // 返回ch的位置
    int getPosition(char ch);
    // 深度优先搜索遍历图的递归实现
    void DFS(int i, int *visited);
    // 将node节点链接到list的最后
    void linkLast(ENode *list, ENode *node);
    // 获取边<start, end>的权值；若start和end不是连通的，则返回无穷大。
    int getWeight(int start, int end);
    // 获取图中的边
    EData* getEdges();
    // 对边按照权值大小进行排序(由小到大)
    void sortEdges(EData* edges, int elen);
    // 获取i的终点
    int getEnd(int vends[], int i);
};

}

#endif