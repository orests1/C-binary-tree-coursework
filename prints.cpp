#include <iostream>
#include <cstdlib>
#include <queue>
#include "BinaryTree.h"
using namespace std;
//--------------------------------INORDER OPERATION---------------------------
void BinaryTree::print_inorder()
{	
	inorder(root);
}
void BinaryTree::inorder(node* p)
{  	
	if(p != NULL)
	{	
		if(p->left)	inorder(p->left);
		cout<<" "<<p->data<<"\n";			
		if(p->right) inorder(p->right);				
	}
	else return;
}
//--------------------------------PREORDER OPERATION---------------------------
void BinaryTree::print_preorder()
{
	preorder(root);
}

void BinaryTree::preorder(node* p)
{
	if(p != NULL)
	{
		cout<<" "<<p->data<<"\n";
		if(p->left) preorder(p->left);		
		if(p->right) preorder(p->right);
	}
	else return;
}
//--------------------------------POSTORDER OPERATION---------------------------
void BinaryTree::print_postorder()
{
	postorder(root);
}

void BinaryTree::postorder(node* p)
{
	if(p != NULL)
	{
		if(p->left) postorder(p->left);	  
		if(p->right) postorder(p->right);
		cout<<" "<<p->data<<"\n";		
	}
	else return;
}