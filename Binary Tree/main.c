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
    Insert(&b, 20, "jordan");
    Insert(&b, 42, "james");
    Insert(&b, 32, "jack");
    Insert(&b, 50, (void*)9);
    Insert(&b, 6, (void*)12);
    Insert(&b, 7, (void*)'j');
    Insert(&b, 4, (void*)'x');
    Insert(&b, 1, (void*)'v');
    Insert(&b, 100, "abby");
    Insert(&b, 90, "gabby");
    Insert(&b, 80, "grace");
    Insert(&b, 70, "david");
    Insert(&b, 39, "Chris");
    printf("pre-order\n");
    PrintPreOrder(&b);
    printf("in-order\n");
    PrintInOrder(&b);
    printf("post-order\n");
    PrintPostOrder(&b);
    printf("Distance from root %d\n",DistanceFromRoot(&b, 70));
    printf("tree height %d\n",TreeHeight(&b));
    printf("item: %s\n",Find(&b, 70));
    return 0;
}
