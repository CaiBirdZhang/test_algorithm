#ifndef TEST_H
#define TEST_H

#include "tree/bst.h"
#include "tree/avl.h"
#include "tree/rbTree.h"

#include "sort/sort.h"

#include "graph/iterator/ListUDG.h"
#include "graph/iterator/MatrixUDG.h"

// tree
void test_bst();
void test_avl();
void test_rbTree();

// graph
void test_iterator_listUDG();
void test_iterator_matrixUDG();

// sort
void test_sort();

#endif