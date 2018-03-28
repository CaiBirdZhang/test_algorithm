#include "test.h"

//#define TEST_BSTREE
//#define TEST_AVLTREE
//#define TEST_RBTREE
//#define TEST_SORT
#define TEST_GRAPH
using namespace std;
int main()
{
#ifdef TEST_BSTREE
    cout << "test bstree begin....................................................." << endl;
    test_bst();
    cout << "test bstree end....................................................." << endl;
#endif
#ifdef TEST_AVLTREE
    cout << "test avltree begin....................................................." << endl;
    test_avl();
    cout << "test avltree end....................................................." << endl;
#endif

#ifdef TEST_RBTREE
    cout << "test rbtree begin....................................................." << endl;
    test_rbTree();
    cout << "test rbtree end....................................................." << endl;
#endif

#ifdef TEST_SORT
    cout << "test sort begin....................................................." << endl;
    test_sort();
    cout << "test sort end....................................................." << endl;
#endif

#ifdef TEST_GRAPH
    cout << "test graph begin....................................................." << endl;
    //test_iterator_matrixUDG();
    //test_iterator_listUDG();
    test_dijkstra_listUDG();
    cout << "test graph end....................................................." << endl;
#endif

	return 0;
}
