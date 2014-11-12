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
}BinaryTree;

BinaryTree create_tree();

void Insert(BinaryTree* t, int key, void* value);
void* Find(BinaryTree* t, int key);
void Delete(BinaryTree* t, int key);
void PrintPreOrder(BinaryTree* t);
void PrintInOrder(BinaryTree* t);
void PrintPostOrder(BinaryTree* t);
int DistanceFromRoot(BinaryTree* t, int item);
int TreeHeight(BinaryTree* t);

#endif /* defined(__Binary_Tree__BinaryTree__) */
