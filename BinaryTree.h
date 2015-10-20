#include <iostream>
#include <cstdlib>
#include <queue>
#include <string>
using namespace std;

class BinaryTree
{
	private:
	struct node
	{
		node* parent;
		node* left;
		node* right;
		int data;		
	}; 
	node* root;	 
	//helpers
	void removePrivate(int key,node* parent);
	void RemoveRootMatch();
	int FindSmallestPrivate(node* parent); // find smallest value
	void RemoveMatch(node* parent,node* match,bool left);
	void print(ostream &, node*) const;
	void clearHelper(node* p);	
    void copyTreeHelper(node* &p, const node *otherPtr);	
	
	public:	
	bool operator==( const BinaryTree & rhs)
	{
		cout << "operator overloaded == " <<endl;		
		if ((treeCompare(this->root,rhs.root))==true) 
		{
			cout<<"Trees are equal!"<<endl;			
			return true;
		}
		else
		{
			cout<<"Trees are NOT equal!"<<endl;	
			return false;
		}				
	}
	bool treeCompare(const node* tree1 ,const node* tree2)
	{		
		if(tree1==NULL && tree2==NULL) return(true);
		else if (tree1 !=NULL && tree2 !=NULL) {
			return(tree1->data == tree2->data &&   
			treeCompare(tree1->left, tree2->left) && 
			treeCompare(tree1->right, tree2->right)
			);			
		}
		//one is null and one is not, so they're not the same.
		else return(false);		
	}
	void copyTree(const BinaryTree &otherTree);
	void clear ();            // Clear tree
	void removeR(int key);			
	bool isEmpty() const { return root==NULL; }
	void print_inorder();	
	void inorder(node*);		
	void print_preorder();
	void preorder(node*);
	void print_postorder();
	void postorder(node*);
	void insert(int);
	void remove(int);
	bool exists(int);
	void myRemove(int);
	int FindSmallest();	
	BinaryTree()  // Constructor to make an empty binary tree
	{		
		root = NULL;
	}
	BinaryTree(int value) // Creates a binary tree with an initial value to store
	{	
		root = NULL ;
		insert(value);
	}
	
	BinaryTree(const vector<int> &values) // Creates a binary tree from a collection of values.	
	{
		root=NULL;
		for (int i=0;i<values.size();i++)
		insert(values[i]);
	}
	
	BinaryTree(const BinaryTree& other );   // Copy constructor
	~BinaryTree()  // Destructor
	{
		cout << "Resources freed successfully!" << endl;
	}
	friend ostream & operator<<(ostream &, const BinaryTree &);  //BINARY TREE OUTPUT OVERLOAD	
	friend istream & operator>>(istream &,BinaryTree & );   //BINARY TREE INPUT OVERLOAD
	BinaryTree& operator= ( const BinaryTree& other );  // Overloaded assignment operator
	BinaryTree& operator+(const int);  // + overload
	BinaryTree& operator-(const int);  // - overload
};