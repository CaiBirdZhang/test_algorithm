#include "test.h"

//#define _BST_
#define _AVL_
using namespace std;
int main()
{
#ifdef _BST_
    cout << "test bst begin....................................................." << endl;
    test_bst();
    cout << "test bst end....................................................." << endl;
#endif
#ifdef _AVL_
    cout << "test avl begin....................................................." << endl;
    test_avl();
    cout << "test avl end....................................................." << endl;
#endif

	return 0;
}
