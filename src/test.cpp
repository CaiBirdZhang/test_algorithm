#include "test.h"

using namespace std;
void test_bst()
{
    BSTree<int> bst;
    bst.insert(3);
    bst.insert(4);
    bst.insert(10);
    bst.insert(12);
    bst.insert(7);
    bst.insert(8);
    bst.insert(9);
    bst.insert(11);
    bst.insert(-1);
    bst.insert(0);
    bst.insert(2);

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



