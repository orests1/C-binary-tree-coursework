#include <iostream>
#include <cstdlib>
#include <queue>
#include "BinaryTree.h"
using namespace std;
//Remove function
void BinaryTree::RemoveMatch(node* parent,node* match,bool left)
{
	if (root!=NULL)
	{
		node* del;
		int matchKey = match->data;
		int smallestInRightSubtree;		
		//case 0 - 0children		
		if (match->left == NULL && match->right==NULL)
		{
			del=match;
			left==true ? parent->left=NULL : parent->right=NULL;
			delete del;
			cout<<"the node was removed"<<endl;			
		}		
		//case 1 1 child
		else if(match->left == NULL && match->right!=NULL)
		{
			left==true ? parent->left=match->right : parent->right=match->right;
			match->right=NULL;
			del=match;
			delete del;
			cout<<"the node was deleted"<<endl;			
		}
		else if(match->left != NULL && match->right==NULL)
		{
			left==true ? parent->left=match->left : parent->right=match->left;
			match->left=NULL;
			del=match;
			delete del;
			cout<<"the node was deleted"<<endl;					
		}
		// case 2  2 children
		else
		{
			smallestInRightSubtree=FindSmallestPrivate(match->right);
			removePrivate(smallestInRightSubtree,match);
			match->data =smallestInRightSubtree;
		}		
	}
	else
	{
		cout<<"The tree is empty"<<endl;	
	}	
}

int BinaryTree::FindSmallest()
{
	return FindSmallestPrivate(root);	
}
int BinaryTree::FindSmallestPrivate(node* parent)
{
	if (root==NULL)
	{
		cout<<"The tree is empty"<<endl;
		return 0;
	}
	else
	{
		if (parent->left!=NULL)
		{
			return FindSmallestPrivate(parent->left);
		}
		else
		{
			return parent->data;				
		}		
	}
}
//--------------------------------------------------------------
void BinaryTree::removeR(int key)
{
	removePrivate(key,root);	
}
void BinaryTree::removePrivate(int key,node* parent)
{
	if (root!=NULL)
	{
		if (root->data ==key) //if we have  a match
		{
			RemoveRootMatch(); 			
		}
		else
		{ // If not look to the left child
			if (key<parent->data && parent->left!=NULL)
			{
				if (parent->left->data==key)
				{					
					RemoveMatch(parent,parent->left,true); 
				}
				else
				removePrivate(key,parent->left);				
			}
			else if (key>parent->data && parent->right!=NULL)
			{
				if (parent->right->data==key)
				{					
					RemoveMatch(parent,parent->right,false); 
				}
				else
				removePrivate(key,parent->right);					
			}
			else
			{
				cout<<"The key"<<key<<"was not found in the tree"<<endl;
			}	
		}		
	}
	else 
	{
		cout<<"Tree is empty"<<endl;
	}	
}
//--------------------------------------------------------------
void BinaryTree::RemoveRootMatch()
{
	if (root!=NULL)
	{
		node* del=root;
		int rootKey=root->data;
		int smallestInRightSubtree;		
		// case 0 0- children
		if (root->left==NULL && root->right==NULL)
		{
			root=NULL;
			delete del;
		}
		//case 1 - 1 child
		else if (root->left==NULL && root->right!=NULL)
		{
			root=root->right;
			del->right=NULL; // can be removed.
			delete del;			
		}
		else if (root->left!=NULL && root->right==NULL)
		{
			root=root->left;
			del->left=NULL; // can be removed.
			delete del;			
		}		
		//case 2			
		else
		{
			smallestInRightSubtree=FindSmallestPrivate(root->right); // TODO
			removePrivate(smallestInRightSubtree,root);
			root->data=smallestInRightSubtree;			
		}		
	}	
	else
	{		
		cout<<"cannot remove root.The tree is empty"<<endl;
	}
}

