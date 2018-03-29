#ifndef ITERATOR_LISTDG_H
#define ITERATOR_LISTDG_H
/**
 * C++: 无回路有向图(Directed Acyclic Graph)的拓扑排序
 *      该DAG图是通过邻接表实现的。
 */
namespace iterator_t
{
// 邻接表
class ListDG
{
public:
    static const int MAX = 100;
private: // 内部类
    // 邻接表中表对应的链表的顶点
    class ENode
    {
        public:
            int ivex;           // 该边所指向的顶点的位置
            ENode *nextEdge;    // 指向下一条弧的指针
    };

    // 邻接表中表的顶点
    class VNode
    {
        public:
            char data;          // 顶点信息
            ENode *firstEdge;   // 指向第一条依附该顶点的弧
    };

private: // 私有成员
    int mVexNum;             // 图的顶点的数目
    int mEdgNum;             // 图的边的数目
    VNode mVexs[MAX];

public:
    // 创建邻接表对应的图(自己输入)
    ListDG();
    // 创建邻接表对应的图(用已提供的数据)
    ListDG(char vexs[], int vlen, char edges[][2], int elen);
    ~ListDG() {}

    // 深度优先搜索遍历图
    void DFS();
    // 广度优先搜索（类似于树的层次遍历）
    void BFS();
    // 打印邻接表图
    void print();
    // 拓扑排序
    int topologicalSort();

private:
    // 读取一个输入字符
    char readChar();
    // 返回ch的位置
    int getPosition(char ch);
    // 深度优先搜索遍历图的递归实现
    void DFS(int i, int *visited);
    // 将node节点链接到list的最后
    void linkLast(ENode *list, ENode *node);
};

}

#endif