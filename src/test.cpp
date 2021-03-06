#include "test.h"

using namespace std;
void test_bst()
{
    BSTree<int> bst;
    int arr[] = {3,4,10,12,7,8,9,11,-1,0,2};
    int size = sizeof(arr)/sizeof(int);
    for (int i = 0; i < size; ++i)
    {
        bst.insert(arr[i]);
    }

    cout << "min key = " << bst.minimum() << endl;
    cout << "max key = " << bst.maximum() << endl;

    cout << "print begin" << endl;
    bst.print();
    cout << "print end" << endl;

    cout << "preOrder begin" << endl;
    bst.preOrder();
    cout << endl << "preOrder end" << endl;

    cout << "inOrder begin" << endl;
    bst.inOrder();
    cout << endl << "inOrder end" << endl;

    cout << "postOrder begin" << endl;
    bst.postOrder();
    cout << endl << "postOrder end" << endl;

    bst.remove(3);
    cout << "remove 3" << endl;
    cout << "print begin" << endl;
    bst.print();
    cout << "print end" << endl;

    bst.remove(10);
    cout << "remove 10" << endl;
    cout << "print begin" << endl;
    bst.print();
    cout << "print end" << endl;

}

void test_avl()
{
    AVLTree<int> avl;
    AVLTree<int>* tree = &avl;
    int i,ilen;
    int arr[] = {3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9};
    cout << "== 依次添加: ";
    ilen = sizeof(arr)/sizeof(int);
    for(i=0; i<ilen; i++)
    {
        cout << arr[i] <<" ";
        tree->insert(arr[i]);
    }

    cout << "\n== 前序遍历: ";
    tree->preOrder();

    cout << "\n== 中序遍历: ";
    tree->inOrder();

    cout << "\n== 后序遍历: ";
    tree->postOrder();
    cout << endl;

    cout << "== 高度: " << tree->height() << endl;
    cout << "== 最小值: " << tree->minimum() << endl;
    cout << "== 最大值: " << tree->maximum() << endl;
    cout << "== 树的详细信息: " << endl;
    tree->print();

    i = 8;
    cout << "\n== 删除根节点: " << i;
    tree->remove(i);

    cout << "\n== 高度: " << tree->height() ;
    cout << "\n== 中序遍历: " ;
    tree->inOrder();
    cout << "\n== 树的详细信息: " << endl;
    tree->print();

    i = 4;
    cout << "\n== 删除根节点: " << i;
    tree->remove(i);
    i = 7;
    cout << "\n== 删除根节点: " << i;
    tree->remove(i);
    i = 13;
    cout << "\n== 删除根节点: " << i;
    tree->remove(i);

    cout << "\n== 高度: " << tree->height() ;
    cout << "\n== 中序遍历: " ;
    tree->inOrder();
    cout << "\n== 树的详细信息: " << endl;
    tree->print();
}

void test_rbTree() {
    int a[]= {10, 40, 30, 60, 90, 70, 20, 50, 80};
    int check_insert=0;    // "插入"动作的检测开关(0，关闭；1，打开)
    int check_remove=1;    // "删除"动作的检测开关(0，关闭；1，打开)
    int i;
    int ilen = (sizeof(a)) / (sizeof(a[0])) ;
    RBTree<int>* tree=new RBTree<int>();

    cout << "== 原始数据: ";
    for(i=0; i<ilen; i++)
        cout << a[i] <<" ";
    cout << endl;

    for(i=0; i<ilen; i++)
    {
        tree->insert(a[i]);
        // 设置check_insert=1,测试"添加函数"
        if(check_insert)
        {
            cout << "== 添加节点: " << a[i] << endl;
            cout << "== 树的详细信息: " << endl;
            tree->print();
            cout << endl;
        }

    }

    cout << "== 前序遍历: ";
    tree->preOrder();

    cout << "\n== 中序遍历: ";
    tree->inOrder();

    cout << "\n== 后序遍历: ";
    tree->postOrder();
    cout << endl;

    cout << "== 最小值: " << tree->minimum() << endl;
    cout << "== 最大值: " << tree->maximum() << endl;
    cout << "== 树的详细信息: " << endl;
    tree->print();

    // 设置check_remove=1,测试"删除函数"
    if(check_remove)
    {
        for(i=0; i<ilen; i++)
        {
            tree->remove(a[i]);

            cout << "== 删除节点: " << a[i] << endl;
            cout << "== 树的详细信息: " << endl;
            tree->print();
            cout << endl;
        }
    }

}

void test_sort()
{
    {
        cout << "冒泡排序开始:" << endl;
        int i;
        int a[] = {20,40,30,10,60,50};
        int ilen = (sizeof(a)) / (sizeof(a[0]));

        cout << "before sort:";
        for (i=0; i<ilen; i++)
            cout << a[i] << " ";
        cout << endl;

        bubbleSort1(a, ilen);
        //bubbleSort2(a, ilen);

        cout << "after  sort:";
        for (i=0; i<ilen; i++)
            cout << a[i] << " ";
        cout << endl;
        cout << "冒泡排序结束:" << endl;
    }

    {
        cout << "快速排序开始:" << endl;
        int i;
        int a[] = {30,40,60,10,20,50};
        // int a[] = {10,20,30,40,50,60};
        int ilen = (sizeof(a)) / (sizeof(a[0]));

        cout << "before sort:";
        for (i=0; i<ilen; i++)
            cout << a[i] << " ";
        cout << endl;

        quickSort(a, 0, ilen-1);

        cout << "after  sort:";
        for (i=0; i<ilen; i++)
            cout << a[i] << " ";
        cout << endl;
        cout << "快速排序结束:" << endl;
    }

    {
        cout << "直接插入排序开始:" << endl;
        int i;
        int a[] = {80,30,60,40,20,10,50,70};
        int ilen = (sizeof(a)) / (sizeof(a[0]));

        cout << "before sort:";
        for (i=0; i<ilen; i++)
            cout << a[i] << " ";
        cout << endl;

        insertSort(a, ilen);
        //shellSort2(a, ilen);

        cout << "after  sort:";
        for (i=0; i<ilen; i++)
            cout << a[i] << " ";
        cout << endl;
        cout << "直接插入排序结束:" << endl;
    }

    {
        cout << "希尔排序开始:" << endl;
        int i;
        int a[] = {80,30,60,40,20,10,50,70};
        int ilen = (sizeof(a)) / (sizeof(a[0]));

        cout << "before sort:";
        for (i=0; i<ilen; i++)
            cout << a[i] << " ";
        cout << endl;

        shellSort1(a, ilen);
        //shellSort2(a, ilen);

        cout << "after  sort:";
        for (i=0; i<ilen; i++)
            cout << a[i] << " ";
        cout << endl;
        cout << "希尔排序结束:" << endl;
    }

    {
        cout << "选择排序开始:" << endl;
        int i;
        int a[] = {20,40,30,10,60,50};
        int ilen = (sizeof(a)) / (sizeof(a[0]));

        cout << "before sort:";
        for (i=0; i<ilen; i++)
            cout << a[i] << " ";
        cout << endl;

        selectSort(a, ilen);

        cout << "after  sort:";
        for (i=0; i<ilen; i++)
            cout << a[i] << " ";
        cout << endl;
        cout << "选择排序结束:" << endl;
    }

    {
        cout << "归并排序开始:" << endl;
        int i;
        int a[] = {80,30,60,40,20,10,50,70};
        int ilen = (sizeof(a)) / (sizeof(a[0]));

        cout << "before sort:";
        for (i=0; i<ilen; i++)
            cout << a[i] << " ";
        cout << endl;

        mergeSortUp2Down(a, 0, ilen-1);        // 归并排序(从上往下)
        //mergeSortDown2Up(a, ilen);            // 归并排序(从下往上)

        cout << "after  sort:";
        for (i=0; i<ilen; i++)
            cout << a[i] << " ";
        cout << endl;
        cout << "归并排序结束:" << endl;
    }

    {
        cout << "桶排序开始:" << endl;
        int i;
        int a[] = {80,30,60,40,20,10,50,70};
        int ilen = (sizeof(a)) / (sizeof(a[0]));

        cout << "before sort:";
        for (i=0; i<ilen; i++)
            cout << a[i] << " ";
        cout << endl;

        BucketSort(a, ilen);

        cout << "after  sort:";
        for (i=0; i<ilen; i++)
            cout << a[i] << " ";
        cout << endl;
        cout << "桶排序结束:" << endl;
    }

    {
        cout << "堆排序开始:" << endl;
        int i;
        int a[] = {20,30,90,40,70,110,60,10,100,50,80};
        int ilen = (sizeof(a)) / (sizeof(a[0]));

        cout << "before sort:";
        for (i=0; i<ilen; i++)
            cout << a[i] << " ";
        cout << endl;

        heapSortAsc(a, ilen);            // 升序排列
        //heapSortDesc(a, ilen);        // 降序排列

        cout << "after  sort:";
        for (i=0; i<ilen; i++)
            cout << a[i] << " ";
        cout << endl;
        cout << "堆排序结束:" << endl;
    }
}

// graph
void test_iterator_listUDG()
{
    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char edges[][2] = {
        {'A', 'C'},
        {'A', 'D'},
        {'A', 'F'},
        {'B', 'C'},
        {'C', 'D'},
        {'E', 'G'},
        {'F', 'G'}};
    int vlen = sizeof(vexs)/sizeof(vexs[0]);
    int elen = sizeof(edges)/sizeof(edges[0]);
    iterator_t::ListUDG* pG;

    // 自定义"图"(输入矩阵队列)
    //pG = new ListUDG();
    // 采用已有的"图"
    pG = new iterator_t::ListUDG(vexs, vlen, edges, elen);
    cout << endl;
    pG->print();   // 打印图
    cout << "ListUDG Graph DFS begin: " << endl;
    pG->DFS();     // 深度优先遍历
    cout << "ListUDG Graph DFS end: " << endl;
    cout << "ListUDG Graph BFS begin: " << endl;
    pG->BFS();     // 广度优先遍历
    cout << "ListUDG Graph BFS end: " << endl;
}

void test_iterator_matrixUDG()
{
    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char edges[][2] = {
        {'A', 'C'},
        {'A', 'D'},
        {'A', 'F'},
        {'B', 'C'},
        {'C', 'D'},
        {'E', 'G'},
        {'F', 'G'}};
    int vlen = sizeof(vexs)/sizeof(vexs[0]);
    int elen = sizeof(edges)/sizeof(edges[0]);
    iterator_t::MatrixUDG* pG;

    // 自定义"图"(输入矩阵队列)
    //pG = new MatrixUDG();
    // 采用已有的"图"
    pG = new iterator_t::MatrixUDG(vexs, vlen, edges, elen);
    pG->print();   // 打印图
    cout << "MartixUDG Graph DFS begin: " << endl;
    pG->DFS();     // 深度优先遍历
    cout << endl << "MartixUDG Graph DFS end: " << endl;

    cout << "MartixUDG Graph BFS begin: " << endl;
    pG->BFS();     // 广度优先遍历
    cout << endl << "MartixUDG Graph BFS end: " << endl;
}

void test_iterator_listDG()
{
    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    char edges[][2] = {
        {'A', 'G'},
        {'B', 'A'},
        {'B', 'D'},
        {'C', 'F'},
        {'C', 'G'},
        {'D', 'E'},
        {'D', 'F'}};
    int vlen = sizeof(vexs)/sizeof(vexs[0]);
    int elen = sizeof(edges)/sizeof(edges[0]);
    iterator_t::ListDG* pG;

    // 自定义"图"(输入矩阵队列)
    //pG = new ListDG();
    // 采用已有的"图"
    pG = new iterator_t::ListDG(vexs, vlen, edges, elen);

    pG->print();   // 打印图
    //pG->DFS();     // 深度优先遍历
    //pG->BFS();     // 广度优先遍历
    cout << "listDG Graph topologicalSort begin: " << endl;
    pG->topologicalSort();     // 拓扑排序
    cout << "listDG Graph topologicalSort end: " << endl;
}

void test_dijkstra_listUDG()
{
    int prev[100] = {0};
    int dist[100] = {0};
    // 顶点
    char vexs[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G'};
    // 边
    dijkstra::EData *edges[] = {
               // 起点 终点 权
        new dijkstra::EData('A', 'B', 12),
        new dijkstra::EData('A', 'F', 16),
        new dijkstra::EData('A', 'G', 14),
        new dijkstra::EData('B', 'C', 10),
        new dijkstra::EData('B', 'F',  7),
        new dijkstra::EData('C', 'D',  3),
        new dijkstra::EData('C', 'E',  5),
        new dijkstra::EData('C', 'F',  6),
        new dijkstra::EData('D', 'E',  4),
        new dijkstra::EData('E', 'F',  2),
        new dijkstra::EData('E', 'G',  8),
        new dijkstra::EData('F', 'G',  9),
    };
    int vlen = sizeof(vexs)/sizeof(vexs[0]);
    int elen = sizeof(edges)/sizeof(edges[0]);
    dijkstra::ListUDG* pG;

    // 自定义"图"(输入矩阵队列)
    //pG = new ListUDG();
    // 采用已有的"图"
    pG = new dijkstra::ListUDG(vexs, vlen, edges, elen);

    //pG->print();   // 打印图
    //pG->DFS();     // 深度优先遍历
    //pG->BFS();     // 广度优先遍历
    cout << "ListUDG Graph prim begin: " << endl;
    pG->prim(0);   // prim算法生成最小生成树
    cout << "ListUDG Graph prim end: " << endl << endl;

    cout << "ListUDG Graph kruskal begin: " << endl;
    pG->kruskal(); // Kruskal算法生成最小生成树
    cout << "ListUDG Graph kruskal end: " << endl << endl;

    cout << "ListUDG Graph dijkstra begin: " << endl;
    // dijkstra算法获取"第4个顶点"到其它各个顶点的最短距离
    pG->dijkstra(3, prev, dist);
    cout << "ListUDG Graph dijkstra end: " << endl << endl;
}

void test_kmp()
{
    char text[] = "abcderghaoirdjgyabcgkgerowgkeogkewowgkerwgkeegfeoojfnbqotyhg";
    char target[] = "gkerwgkeegf";
    cout << "current text = " << text << endl;
    cout << "target text = " << target << endl;
    int pos = kmp(text, target);
    cout << "matched pos = " << pos << endl;
}
