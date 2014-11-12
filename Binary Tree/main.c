//
//  main.c
//  Binary Tree
//
//  Created by Jordan Thomas on 10/24/14.
//  Copyright (c) 2014 Jordan Thomas. All rights reserved.
//

#include <stdio.h>
#include "BinaryTree.h"

int main(int argc, const char * argv[]) {
    BinaryTree b= create_tree();
    Insert(&b, 20);
    Insert(&b, 42);
    Insert(&b, 32);
    Insert(&b, 50);
    Insert(&b, 6);
    Insert(&b, 7);
    Insert(&b, 4);
    Insert(&b, 1);
    Insert(&b, 100);
    Insert(&b, 90);
    Insert(&b, 80);
    Insert(&b, 70);
    Insert(&b, 39);
    printf("pre-order\n");
    PrintPreOrder(&b);
    printf("in-order\n");
    PrintInOrder(&b);
    printf("post-order\n");
    PrintPostOrder(&b);
    printf("Distance from root %d\n",DistanceFromRoot(&b, 70));
    printf("tree height %d\n",TreeHeight(&b));
    return 0;
}
