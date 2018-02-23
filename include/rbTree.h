#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>
#include <iomanip>

enum RBTColor{RED, BLACK};

template <class T>
class RBTNode{
    public:
        RBTColor color;    // 颜色
        T key;            // 关键字(键值)
        RBTNode *left;    // 左孩子
        RBTNode *right;    // 右孩子
        RBTNode *parent; // 父结点

        RBTNode(T value, RBTColor c, RBTNode *p, RBTNode *l, RBTNode *r):
            key(value),color(c),parent(p),left(l),right(r) {}
};

template <class T>
class RBTree {
    private:
        RBTNode<T> *mRoot;    // 根结点

    public:
        RBTree() { mRoot = NULL; }
        ~RBTree() {}

        // 前序遍历"红黑树"
        void preOrder();
        // 中序遍历"红黑树"
        void inOrder();
        // 后序遍历"红黑树"
        void postOrder();

        // (递归实现)查找"红黑树"中键值为key的节点
        RBTNode<T>* search(T key);
        // (非递归实现)查找"红黑树"中键值为key的节点
        RBTNode<T>* iterativeSearch(T key);

        // 查找最小结点：返回最小结点的键值。
        T minimum();
        // 查找最大结点：返回最大结点的键值。
        T maximum();

        // 找结点(x)的后继结点。即，查找"红黑树中数据值大于该结点"的"最小结点"。
        RBTNode<T>* successor(RBTNode<T> *x);
        // 找结点(x)的前驱结点。即，查找"红黑树中数据值小于该结点"的"最大结点"。
        RBTNode<T>* predecessor(RBTNode<T> *x);

        // 将结点(key为节点键值)插入到红黑树中
        void insert(T key);

        // 删除结点(key为节点键值)
        void remove(T key);

        // 销毁红黑树
        void destroy();

        // 打印红黑树
        void print();
    private:
/*        // 前序遍历"红黑树"
        void preOrder(RBTNode<T>* tree) const;
        // 中序遍历"红黑树"
        void inOrder(RBTNode<T>* tree) const;
        // 后序遍历"红黑树"
        void postOrder(RBTNode<T>* tree) const;*/

        // (递归实现)查找"红黑树x"中键值为key的节点
        RBTNode<T>* search(RBTNode<T>* x, T key) const;
        // (非递归实现)查找"红黑树x"中键值为key的节点
        RBTNode<T>* iterativeSearch(RBTNode<T>* x, T key) const;

        // 查找最小结点：返回tree为根结点的红黑树的最小结点。
        RBTNode<T>* minimum(RBTNode<T>* tree);
        // 查找最大结点：返回tree为根结点的红黑树的最大结点。
        RBTNode<T>* maximum(RBTNode<T>* tree);

        // 左旋
        void leftRotate(RBTNode<T>* &root, RBTNode<T>* x);
        // 右旋
        void rightRotate(RBTNode<T>* &root, RBTNode<T>* y);
        // 插入函数
        void insert(RBTNode<T>* &root, RBTNode<T>* node);
        // 插入修正函数
        void insertFixUp(RBTNode<T>* &root, RBTNode<T>* node);
        // 删除函数
        void remove(RBTNode<T>* &root, RBTNode<T> *node);
        // 删除修正函数
        void removeFixUp(RBTNode<T>* &root, RBTNode<T> *node, RBTNode<T> *parent);

        // 销毁红黑树
        void destroy(RBTNode<T>* &tree);

        // 打印红黑树
        void print(RBTNode<T>* tree, T key, int direction);

#define rb_parent(r)   ((r)->parent)
#define rb_color(r) ((r)->color)
#define rb_is_red(r)   ((r)->color==RED)
#define rb_is_black(r)  ((r)->color==BLACK)
#define rb_set_black(r)  do { (r)->color = BLACK; } while (0)
#define rb_set_red(r)  do { (r)->color = RED; } while (0)
#define rb_set_parent(r,p)  do { (r)->parent = (p); } while (0)
#define rb_set_color(r,c)  do { (r)->color = (c); } while (0)
};

// 前序遍历"二叉树"
template <class T>
void RBTree<T>::preOrder() {
    RBTNode<T>* tmp = mRoot;
    stack<RBTNode<T>*> st;
    //st.push(tmp);
    while ((tmp != NULL) || (!st.empty())) {
        // get left children until end
        while (tmp != NULL) {
            cout << tmp->key << "  ";
            st.push(tmp);
            tmp = tmp->left;
        }
        // get a right child
        if (!st.empty()) {
            RBTNode<T>* parent = st.top();
            st.pop();
            tmp = parent->right;
        }
    }
}

// 中序遍历"二叉树"
template <class T>
void RBTree<T>::inOrder() {
    RBTNode<T>* tmp = mRoot;
    stack<RBTNode<T>*> st;
    //st.push(tmp);
    while ((tmp != NULL) || (!st.empty())) {
        // get left children until end
        while (tmp != NULL) {
            st.push(tmp);
            tmp = tmp->left;
        }
        // get a right child
        if (!st.empty()) {
            RBTNode<T>* parent = st.top();
            st.pop();
            cout << parent->key << "  ";
            tmp = parent->right;
        }
    }
}

// 后序遍历"二叉树"
template <class T>
void RBTree<T>::postOrder() {
    RBTNode<T>* cur = mRoot;
    RBTNode<T>* pre = NULL;
    stack<RBTNode<T>*> st;
    st.push(cur);
    while (!st.empty()) {
        cur = st.top();
        // no children or already access the children
        if ((cur->left == NULL && cur->right == NULL) ||
            (pre != NULL && (pre == cur->left || pre == cur->right))) {
            cout << cur->key << "  ";
            st.pop();
            pre = cur;
        } else {
            // put right and left child
            if (cur->right != NULL) {
                st.push(cur->right);
            }
            if (cur->left != NULL) {
                st.push(cur->left);
            }
        }
    }
}

/*
 * (递归实现)查找"红黑树x"中键值为key的节点
 */
template <class T>
RBTNode<T>* RBTree<T>::search(RBTNode<T>* x, T key) const
{
    if (x==NULL || x->key==key)
        return x;

    if (key < x->key)
        return search(x->left, key);
    else
        return search(x->right, key);
}

template <class T>
RBTNode<T>* RBTree<T>::search(T key)
{
    search(mRoot, key);
}

/*
 * (非递归实现)查找"红黑树x"中键值为key的节点
 */
template <class T>
RBTNode<T>* RBTree<T>::iterativeSearch(RBTNode<T>* x, T key) const
{
    while ((x!=NULL) && (x->key!=key))
    {
        if (key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    return x;
}

template <class T>
RBTNode<T>* RBTree<T>::iterativeSearch(T key)
{
    iterativeSearch(mRoot, key);
}

/*
 * 查找最小结点：返回tree为根结点的红黑树的最小结点。
 */
template <class T>
RBTNode<T>* RBTree<T>::minimum(RBTNode<T>* tree)
{
    if (tree == NULL)
        return NULL;

    while(tree->left != NULL)
        tree = tree->left;
    return tree;
}

template <class T>
T RBTree<T>::minimum()
{
    RBTNode<T> *p = minimum(mRoot);
    if (p != NULL)
        return p->key;

    return static_cast<T>(NULL);
}

/*
 * 查找最大结点：返回tree为根结点的红黑树的最大结点。
 */
template <class T>
RBTNode<T>* RBTree<T>::maximum(RBTNode<T>* tree)
{
    if (tree == NULL)
        return NULL;

    while(tree->right != NULL)
        tree = tree->right;
    return tree;
}

template <class T>
T RBTree<T>::maximum()
{
    RBTNode<T> *p = maximum(mRoot);
    if (p != NULL)
        return p->key;

    return static_cast<T>(NULL);
}

/*
 * 打印"二叉查找树"
 *
 * key        -- 节点的键值
 * direction  --  0，表示该节点是根节点;
 *               -1，表示该节点是它的父结点的左孩子;
 *                1，表示该节点是它的父结点的右孩子。
 */
template <class T>
void RBTree<T>::print(RBTNode<T>* tree, T key, int direction)
{
    if(tree != NULL)
    {
        if(direction==0)    // tree是根节点
            cout << setw(2) << tree->key << "(B) is root" << endl;
        else                // tree是分支节点
            cout << setw(2) << tree->key <<  (rb_is_red(tree)?"(R)":"(B)") << " is " << setw(2) << key << "'s "  << setw(12) << (direction==1?"right child" : "left child") << endl;

        print(tree->left, tree->key, -1);
        print(tree->right,tree->key,  1);
    }
}

template <class T>
void RBTree<T>::print()
{
    if (mRoot != NULL)
        print(mRoot, mRoot->key, 0);
}

/*// 找结点(x)的后继结点。即，查找"红黑树中数据值大于该结点"的"最小结点"。
RBTNode<T>* successor(RBTNode<T> *x);
// 找结点(x)的前驱结点。即，查找"红黑树中数据值小于该结点"的"最大结点"。
RBTNode<T>* predecessor(RBTNode<T> *x);

// 左旋
void leftRotate(RBTNode<T>* &root, RBTNode<T>* x);
// 右旋
void rightRotate(RBTNode<T>* &root, RBTNode<T>* y);

// 将结点(key为节点键值)插入到红黑树中
void insert(T key);
// 插入函数
void insert(RBTNode<T>* &root, RBTNode<T>* node);
// 插入修正函数
void insertFixUp(RBTNode<T>* &root, RBTNode<T>* node);

// 删除结点(key为节点键值)
void remove(T key);
// 删除函数
void remove(RBTNode<T>* &root, RBTNode<T> *node);
// 删除修正函数
void removeFixUp(RBTNode<T>* &root, RBTNode<T> *node, RBTNode<T> *parent);*/



#endif
