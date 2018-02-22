#include "test.h"

using namespace std;
void test_bst()
{
    BSTree<int> bst;
    int arr[] = {3,4,10,12,7,8,9,11,-1,0,2};
    int size = sizeof(arr)/sizeof(int);
    for (int i = 0; i < size; ++i) {
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

void test_avl() {
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

