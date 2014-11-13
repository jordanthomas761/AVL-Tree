//
//  BinaryTree.h
//  Binary Tree
//
//  Created by Jordan Thomas on 10/24/14.
//  Copyright (c) 2014 Jordan Thomas. All rights reserved.
//

#ifndef __Binary_Tree__BinaryTree__
#define __Binary_Tree__BinaryTree__

#include <stdio.h>



typedef struct list_node node;

typedef struct binary_tree
{
    node* root;
}AVLTree;

AVLTree create_tree();

void Insert(AVLTree* t, int key, void* value);
void* Find(AVLTree* t, int key);
void Delete(AVLTree* t, int key);//Not Implmented yet
void PrintPreOrder(AVLTree* t);
void PrintInOrder(AVLTree* t);
void PrintPostOrder(AVLTree* t);
int DistanceFromRoot(AVLTree* t, int item);
int TreeHeight(AVLTree* t);

#endif /* defined(__Binary_Tree__BinaryTree__) */
