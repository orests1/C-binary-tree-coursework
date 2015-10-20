#include <iostream>
#include <cstdlib>
#include <queue>
#include "BinaryTree.h"
using namespace std;

BinaryTree& BinaryTree:: operator= ( const BinaryTree &sourceTree )
// Sets a tree to be equivalent to the tree "source".
{	
    // Avoid accidentally trying to set object to itself.
    // Calling clear() on an object, then copying the deleted data doesn't work.
    if( this != &sourceTree ) 
    {
		clear();
		copyTree(sourceTree);
		return *this;
	}
    else
    {
        return *this;
	}
}


void BinaryTree::copyTree(const BinaryTree &sourceTree)
// Sets a tree to be equivalent to the tree "source".
{	
    copyTreeHelper(root,sourceTree.root);
}

void BinaryTree::copyTreeHelper(node * &p,const node * sourcePtr)
// Recursive helper function that helps set a tree to be equivalent to another tree.
{
	if (sourcePtr==NULL)
	{
		p=NULL;
	}
	else{		
		p =new node;			
		p->data=sourcePtr->data;		
		copyTreeHelper( p->left, sourcePtr->left );
		copyTreeHelper( p->right, sourcePtr->right );		
	}	
}

void BinaryTree:: clear ()
// Removes all the nodes from a tree.
{
	cout<<"Removing all the nodes from the tree."<<endl;
    clearHelper(root);
    root = 0;
}
//-----------------------------------------------------------------
void BinaryTree:: clearHelper(node *p)
// Recursive helper for clear. Clears the subtree pointed to by p.
{	
    if (p != 0)
    {
		// Use post-order traversal. Otherwise get into trouble by
		// referencing p->left and/or p->right after p had been deallocated.
		clearHelper(p->left);
		clearHelper(p->right);
		delete p;
	}
}
//overloaded >> operator for inserting a value in the tree
istream& operator>>(istream& input,  BinaryTree &t)
{
	int d;
	cout<<">> overloaded"<<endl;	
	input>>d;
	while (d!=-1){
		t.insert(d);
		input>>d;
	}
	cout<<"Input stopped!"<<endl;
	return input;
	
}
//overloaded << operator for printing the values inorder
ostream & operator<<(ostream &ost, const BinaryTree &t)
{			
	t.print(ost,t.root);
	return ost;
}

//-----------------------------------------------------------------
//-----------------------------------------------------------------
// inorder print function for operator overload
void BinaryTree::print(ostream & ost,node* p) const
{	
	if(p!=NULL)
	{			
		if(p->left)	print(ost,p->left);
		ost<<" "<<p->data<<"\n";				
		if(p->right) print(ost,p->right);				
	}
	else
	{
	ost<<"Tree is empty!?";		
	}
}
//-----------------------------------------------------------------
// overloaded operator for inserting a value on the tree
BinaryTree& BinaryTree:: operator+ (const int key)
// Sets a tree to be equivalent to the tree "source".
{		   
	this->insert(key);	
	return *this;
}

//-----------------------------------------------------------------
// overloaded operator for deleting a value from the tree
BinaryTree& BinaryTree:: operator- (const int key)
// Sets a tree to be equivalent to the tree "source".
{		
	this->removeR(key);	
	return *this;
}	