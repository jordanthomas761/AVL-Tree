//
//  BinaryTree.c
//  Binary Tree
//
//  Created by Jordan Thomas on 10/24/14.
//  Copyright (c) 2014 Jordan Thomas. All rights reserved.
//

#include "BinaryTree.h"
#include <stdlib.h>

typedef struct list_node
{
	int key;
	void* value;
	struct list_node* parent;
	struct list_node* left;
	struct list_node* right;
	int left_height;
	int right_height;
}node;



int max(int a, int b)
{
	if(a>b)
		return a;
	else
		return b;
}

void update_height(node* n)
{
	if(n->parent != NULL && n->parent->key < n->key)
	{
		if (n->parent->right_height <= max(n->left_height, n->right_height) )
		{
			n->parent->right_height = max(n->left_height, n->right_height) + 1;
			update_height(n->parent);
		}
	}
	else if(n->parent != NULL && n->parent->key > n->key)
	{
		if (n->parent->left_height <= max(n->left_height, n->right_height) )
		{
			n->parent->left_height = max(n->left_height, n->right_height) + 1;
			update_height(n->parent);
		}
	}
}

void rotate_right(node* n)
{
	if (n->parent !=NULL)
	{
		n->left->parent= n->parent;
		if(n->left->key > n->parent->key)
			n->parent->right=n->left;
		else
			n->parent->left=n->left;
	}
	else
		n->left->parent =NULL;
	n->parent=n->left;
	if(n->parent->right != NULL)
	{
		n->left=n->parent->right;
		n->left->parent=n;
	}
	else
		n->left=NULL;
	n->parent->right =n;
	
	if(n->left!=NULL)
	{
		n->left_height=0;
		update_height(n->left);
	}
	else
	{
		n->left_height=0;
		update_height(n);
		if(n->parent->left!= NULL)
			update_height(n->parent->left);
	}
}

void rotate_left(node* n)
{
	if (n->parent !=NULL)
	{
		n->right->parent= n->parent;
		if(n->right->key < n->parent->key)
			n->parent->left=n->right;
		else
			n->parent->right=n->right;
	}
	else
		n->right->parent =NULL;
	n->parent=n->right;
	if(n->parent->left != NULL)
	{
		n->right=n->parent->left;
		n->right->parent=n;
	}
	else
		n->right=NULL;
	n->parent->left =n;
	
	if(n->right!=NULL)
	{
		n->right_height=0;
		update_height(n->right);
	}
	else
	{
		n->right_height=0;
		update_height(n);
		if(n->parent->right!= NULL)
			update_height(n->parent->right);
	}
	
}

void balance_tree(node* n)
{
	if (n!=NULL)
	{
		if(n->right_height - n->left_height >1)
		{
			if(n->right->right_height - n->right->left_height <0)
				rotate_right(n->right);
			rotate_left(n);
			balance_tree(n->parent);
		}
		else if(n->right_height - n->left_height <-1)
		{
			if(n->left->right_height - n->left->left_height >0)
				rotate_left(n->left);
			rotate_right(n);
			balance_tree(n->parent);
		}
		else
		{
			balance_tree(n->parent);
		}
	}
}

void InsertNode(node* n, int item, void* value)
{
    if(n== NULL)
    {
        n= malloc(sizeof(node));
        n->key = item;
    }
    else if(n->key > item)
    {
        if(n->left == NULL)
        {
			n->left= malloc(sizeof(node));
			n->left->key =item;
			n->left->value =value;
            n->left->parent= n;
            n->left->left=NULL;
            n->left->right=NULL;
			n->left->left_height = 0;
			n->left->right_height = 0;
			update_height(n->left);
			balance_tree(n->left);
        }
        else
        {
            InsertNode(n->left, item, value);
        }
    }
    else if(n->key < item)
    {
        if(n->right == NULL)
        {
			n->right= malloc(sizeof(node));
			n->right->key =item;
			n->right->value=value;
            n->right->parent= n;
            n->right->left=NULL;
            n->right->right=NULL;
			n->right->left_height = 0;
			n->right->right_height = 0;
			update_height(n->right);
			balance_tree(n->right);
        }
        else
        {
            InsertNode(n->right, item, value);
        }
    }
    else
    {
        printf("error item already in tree\n");
    }
}

node* searchfornode(node* n, int item)
{
    node* temp = NULL;
    if (n != NULL)
	{
        if (n->key > item)
        {
            temp =searchfornode(n->left, item);
        }
        else if (n->key < item)
        {
            temp =searchfornode(n->right, item);
        }
        else
        {
            temp = n;
        }
	}
	return temp;
}

int node_distancefromroot(node* n)
{
	if (n->parent == NULL)
	{
		return 0;
	}
	else
	{
		return node_distancefromroot(n->parent) + 1;
	}
}

void node_preorder(node* n)
{
    printf("%d\n",n->key);
    if (n->left != NULL)
        node_preorder(n->left);
    if (n->right != NULL)
        node_preorder(n->right);
}

void node_inorder(node* n)
{
    if (n->left != NULL)
        node_inorder(n->left);
    printf("%d\n",n->key);
    if (n->right != NULL)
        node_inorder(n->right);
}

void node_postorder(node* n)
{
    if (n->left != NULL)
        node_postorder(n->left);
    if (n->right != NULL)
        node_postorder(n->right);
    printf("%d\n",n->key);
}

BinaryTree create_tree()
{
	BinaryTree b;
	b.root=NULL;
	return b;
}

void Insert(BinaryTree* t, int key, void* value)
{
    if(t->root == NULL)
    {
		t->root = malloc(sizeof(node));
		t->root->key= key;
		t->root->value = value;
        t->root->parent=NULL;
        t->root->left=NULL;
        t->root->right=NULL;
		t->root->left_height=0;
		t->root->right_height=0;
    }
    else
    {
        InsertNode(t->root, key, value);
		if (t->root->parent !=NULL)
			t->root=t->root->parent;
    }
}

void* Find(BinaryTree* t, int key)
{
	node* temp = searchfornode(t->root, key);
	return temp->value;
}

void Delete(BinaryTree* t, int key)
{
	
}


void PrintPreOrder(BinaryTree* t)
{
    node_preorder(t->root);
}

void PrintInOrder(BinaryTree* t)
{
    node_inorder(t->root);
}

void PrintPostOrder(BinaryTree* t)
{
    node_postorder(t->root);
}

int DistanceFromRoot(BinaryTree* t, int item)
{
	node* temp = searchfornode(t->root, item);
	int a= -1;
	if (temp == NULL)
	{
		printf("item not in tree\n");
	}
	else
	{
		a = node_distancefromroot(temp);
	}
    return a;
}

int TreeHeight(BinaryTree* t)
{
	return max(t ->root->left_height, t ->root->right_height);
}


