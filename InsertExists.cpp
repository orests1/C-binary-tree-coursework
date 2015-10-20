#include <iostream>
#include <cstdlib>
#include <queue>
#include "BinaryTree.h"
using namespace std;
//compares given value with values in the tree to find out if it already exists.
bool BinaryTree::exists(int d)
{
	//Locate the element
	bool found = false;
	if(isEmpty())
	{
		cout<<" This Tree is empty! "<<endl;
		return found;
	}	
	node* curr;
	node* parent;
	curr = root;	
	while(curr != NULL)
	{
		if(curr->data == d)
		{
			found = true;			
			break;
		}
		else
		{
			parent = curr;
			if(d>curr->data) curr = curr->right;
			else curr = curr->left;
		}
	}
	return found;	
}


// Smaller numbers are left
// larger numbers are right
// function for inserting a value in the tree
void BinaryTree::insert(int d)
{
	node* t = new node;
	node* parent;
	t->data = d;
	t->left = NULL;
	t->right = NULL;
	parent = NULL;	
	//is this a new tree?
	if(isEmpty())
	{root = t;
		cout<<"Tree was empty.Value added as root"<<endl;
	}
	else if (exists(d))
	{ 
		cout << " Value already exists!" <<endl;
		return;
	}
	else
	{
		//all insertions are as leaf nodes
		node* curr;
		curr = root;
		// find the node's parent
		while(curr)
		{
			parent = curr;
			if(t->data > curr->data) curr = curr->right;
			else curr = curr->left;
		}
		
		if(t->data < parent->data)
		{
			cout<<"Value added to left of :"<<parent->data<<endl;
			parent->left = t;			
		}
		else
		{
			cout<<"Value added to right of: "<<parent->data<<endl;
			parent->right = t;			
		}
	}
}