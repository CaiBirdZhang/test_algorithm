#ifndef BST_H
#define BST_H

#include <iostream>
#include <stack>

using namespace std;
template <class T>
class BSTNode{
public:
    T key;            // 关键字(键值)
    BSTNode *left;    // 左孩子
    BSTNode *right;    // 右孩子
    BSTNode *parent;// 父结点

    BSTNode(T value, BSTNode *p, BSTNode *l, BSTNode *r):
        key(value),parent(),left(l),right(r) {}
};

template <class T>
class BSTree {
private:
    BSTNode<T> *mRoot;    // 根结点

public:
    BSTree() {}
    ~BSTree() {}

    // 前序遍历"二叉树"
    void preOrder();
    // 中序遍历"二叉树"
    void inOrder();
    // 后序遍历"二叉树"
    void postOrder();

    // (递归实现)查找"二叉树"中键值为key的节点
    BSTNode<T>* search(T key);
    // (非递归实现)查找"二叉树"中键值为key的节点
    BSTNode<T>* iterativeSearch(T key);

    // 查找最小结点：返回最小结点的键值。
    T minimum();
    // 查找最大结点：返回最大结点的键值。
    T maximum();

    // 找结点(x)的后继结点。即，查找"二叉树中数据值大于该结点"的"最小结点"。
    BSTNode<T>* successor(BSTNode<T> *x);
    // 找结点(x)的前驱结点。即，查找"二叉树中数据值小于该结点"的"最大结点"。
    BSTNode<T>* predecessor(BSTNode<T> *x);

    // 将结点(key为节点键值)插入到二叉树中
    void insert(T key);

    // 删除结点(key为节点键值)
    void remove(T key);

    // 销毁二叉树
    void destroy();

    // 打印二叉树
    void print();
private:
/*    // 前序遍历"二叉树"
    void preOrder(BSTNode<T>* tree) const;
    // 中序遍历"二叉树"
    void inOrder(BSTNode<T>* tree) const;
    // 后序遍历"二叉树"
    void postOrder(BSTNode<T>* tree) const;*/

    // (递归实现)查找"二叉树x"中键值为key的节点
    BSTNode<T>* search(BSTNode<T>* x, T key) const;
    // (非递归实现)查找"二叉树x"中键值为key的节点
    BSTNode<T>* iterativeSearch(BSTNode<T>* x, T key) const;

    // 查找最小结点：返回tree为根结点的二叉树的最小结点。
    BSTNode<T>* minimum(BSTNode<T>* tree);
    // 查找最大结点：返回tree为根结点的二叉树的最大结点。
    BSTNode<T>* maximum(BSTNode<T>* tree);

    // 将结点(z)插入到二叉树(tree)中
    void insert(BSTNode<T>* &tree, BSTNode<T>* z);

    // 删除二叉树(tree)中的结点(z)，并返回被删除的结点
    BSTNode<T>* remove(BSTNode<T>* &tree, BSTNode<T> *z);

    // 销毁二叉树
    void destroy(BSTNode<T>* &tree);

    // 打印二叉树
    void print(BSTNode<T>* tree, T key, int direction);
};

// 前序遍历"二叉树"
template <class T>
void BSTree<T>::preOrder() {
    BSTNode<T>* tmp = mRoot;
    stack<BSTNode<T>*> st;
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
            BSTNode<T>* parent = st.top();
            st.pop();
            tmp = parent->right;
        }
    }
}

// 中序遍历"二叉树"
template <class T>
void BSTree<T>::inOrder() {
    BSTNode<T>* tmp = mRoot;
    stack<BSTNode<T>*> st;
    //st.push(tmp);
    while ((tmp != NULL) || (!st.empty())) {
        // get left children until end
        while (tmp != NULL) {
            st.push(tmp);
            tmp = tmp->left;
        }
        // get a right child
        if (!st.empty()) {
            BSTNode<T>* parent = st.top();
            st.pop();
            cout << parent->key << "  ";
            tmp = parent->right;
        }
    }
}

// 后序遍历"二叉树"
template <class T>
void BSTree<T>::postOrder() {
    BSTNode<T>* cur = mRoot;
    BSTNode<T>* pre = NULL;
    stack<BSTNode<T>*> st;
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

// (递归实现)查找"二叉树"中键值为key的节点
template <class T>
BSTNode<T>* BSTree<T>::search(BSTNode<T>* x, T key) const
{
    if (x == NULL || x->key == key)
        return x;

    if (key < x->key)
        return search(x->left, key);
    else
        return search(x->right, key);
}
template <class T>
BSTNode<T>* BSTree<T>::search(T key)
{
    return search(mRoot, key);
}

// (非递归实现)查找"二叉树x"中键值为key的节点
template <class T>
BSTNode<T>* BSTree<T>::iterativeSearch(BSTNode<T>* x, T key) const {
    while (x != NULL) {
        if (key < x->key) {
            x = x->left;
        } else if (key > x->key) {
            x = x->right;
        } else {
            break;
        }
    }
    return x;
}
template <class T>
BSTNode<T>* BSTree<T>::iterativeSearch(T key) {
    return iterativeSearch(mRoot, key);
}

// 查找最小结点：返回tree为根结点的二叉树的最小结点。
template <class T>
BSTNode<T>* BSTree<T>::minimum(BSTNode<T>* tree) {
    if (tree == NULL) {
        return NULL;
    }
    while (tree->left != NULL) {
        tree = tree->left;
    }
    return tree;
}
// 查找最小结点：返回最小结点的键值。
template <class T>
T BSTree<T>::minimum() {
    BSTNode<T>* tmp = minimum(mRoot);
    if (tmp != NULL) {
        return tmp->key;
    }
    return static_cast<T>(0);
}

// 查找最大结点：返回tree为根结点的二叉树的最大结点。
template <class T>
BSTNode<T>* BSTree<T>::maximum(BSTNode<T>* tree) {
    if (tree == NULL) {
        return NULL;
    }
    while (tree != NULL) {
        tree = tree->right;
    }
    return tree;
}
// 查找最大结点：返回最大结点的键值。
template <class T>
T BSTree<T>::maximum() {
    BSTNode<T>* tmp = maximum(mRoot);
    if (tmp != NULL) {
        return tmp->key;
    }
    return static_cast<T>(0);
}

// 找结点(x)的后继结点。即，查找"二叉树中数据值大于该结点"的"最小结点",ceil。
template <class T>
BSTNode<T>* BSTree<T>::successor(BSTNode<T> *x) {
    if (x->right != NULL) {
        return minimum(x->right);
    }
    BSTNode<T> parent = x->parent;
    while (parent != NULL && parent->right == x) {
        x = parent;
        parent = x->parent;
    }
    return parent;
}

// 找结点(x)的前驱结点。即，查找"二叉树中数据值小于该结点"的"最大结点",floor。
template <class T>
BSTNode<T>* BSTree<T>::predecessor(BSTNode<T> *x) {
    if (x->left != NULL) {
        return maximum(x->left);
    }
    BSTNode<T> parent = x->parent;
    while (parent != NULL && parent->left == x) {
        x = parent;
        parent = x->parent;
    }
    return parent;
}

/*
 * 将结点插入到二叉树中
 *
 * 参数说明：
 *     tree 二叉树的根结点
 *     z 插入的结点
 */
template <class T>
void BSTree<T>::insert(BSTNode<T>* &tree, BSTNode<T>* z)
{
    BSTNode<T> *y = NULL;
    BSTNode<T> *x = tree;

    // 查找z的插入位置
    while (x != NULL)
    {
        y = x;
        if (z->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    z->parent = y;
    if (y == NULL)
        tree = z;
    else if (z->key < y->key)
        y->left = z;
    else
        y->right = z;
}
/*
 * 将结点(key为节点键值)插入到二叉树中
 *
 * 参数说明：
 *     tree 二叉树的根结点
 *     key 插入结点的键值
 */
template <class T>
void BSTree<T>::insert(T key)
{
    BSTNode<T> *z=NULL;

    // 如果新建结点失败，则返回。
    if ((z = new BSTNode<T>(key,NULL,NULL,NULL)) == NULL)
        return ;

    insert(mRoot, z);
}

/*
 * 删除结点(z)，并返回被删除的结点
 *
 * 参数说明：
 *     tree 二叉树的根结点
 *     z 删除的结点
 */
template <class T>
BSTNode<T>* BSTree<T>::remove(BSTNode<T>* &tree, BSTNode<T> *z) {

}
// 删除结点(key为节点键值)
template <class T>
void BSTree<T>::remove(T key) {

}

// // 销毁二叉树
// void destroy();

// // 打印二叉树
// void print();




#endif
