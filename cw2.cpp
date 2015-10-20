//Binary Tree CW2 
//Orestis Christou
//Edinburgh Napier University 2015
//---------------------------------
#include <vector>
#include <fstream>
#include <iterator>
#include <string>
#include <iostream>
#include <cstdlib>
#include <queue>
#include "BinaryTree.h"
using namespace std;
//------------------------------------MAIN OPERATION---------------------------
int main()
{ 
	
	BinaryTree b;		
	int size=0;
	int i;   
	int x;
	int temp=0;
    int ch1,ch2,ch3,ch4,ch5,ch6,ch7,ch8,ch9,temp2,temp3;
	bool answr;
	string file_name,file_name1,file_name2;
	ifstream infile;
	vector<int> list;
	ofstream outFile;
	ifstream inData;
	ofstream outData;	
	
	while(1)
    {
		cout<<endl<<endl;
		cout<<" Binary Tree Operations "<<endl;
		cout<<" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ "<<endl;		
		cout<<"| 1. Tree Functions               |"<<endl;
		cout<<"| 2. Printing options             |"<<endl;		   
		cout<<"| 3. Removal                      |"<<endl;
		cout<<"| 4. Search                       |"<<endl;
		cout<<"| 5. Exit                         |"<<endl;
		cout<<" ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ "<<endl;
		cout<<" Enter your choice  : \n";		
		cin>>ch1;
		switch(ch1)
		{			
			case 1 :
			{
				ch2=0;
				while (ch2!=8)
				{
					cout<<" ----------------------------------------------------------- "<<endl;
					cout<<"| 0. Continue the previous tree from STDIN.                 |"<<endl;
					cout<<"| 1. Create a tree with an initial value.                   |"<<endl;
					cout<<"| 2. Create a new tree from STDIN.(Can be saved to .txt)    |"<<endl;
					cout<<"| 3. Create a new tree from STDIN.(Cannot be saved to .txt) |"<<endl;
					cout<<"| 4. Load an existing tree from a txt.                      |"<<endl;
					cout<<"| 5. Save existing tree to a txt .                          |"<<endl;
					cout<<"| 6. Deep copy a tree.                                      |"<<endl;
					cout<<"| 7. Check if 2 trees are the same.                         |"<<endl;
					cout<<"| 8. Go back.                                               |"<<endl;
					cout<<" ----------------------------------------------------------- "<<endl;
					cout<<" Enter your choice  : \n";
					cin>>ch2;
					switch(ch2)
					{	
						//case continue previous tree
						case 0:
						temp=0;
						while (temp!=-1)
						{   if (size==0)
							{
								cout<<"Tree is empty!!"<<endl;
								break;
							}
							else if (size=!0){						
								cout<<" Enter Number to be inserted(-1 to terminate) : ";				
								cin>>temp;	
								if (temp!=-1)
								{
									
									list.push_back(temp);				
									b=b+list[i];
									i++;
									size++;
								}
							}
						}
						break;
						//case create a new tree with an initial value
						case 1:
						{
							b.clear();
							list.clear();
							cout<<"Enter the initial value to store :" ;
							cin>>temp;
							list.push_back(temp);
							i=0;
							BinaryTree initialTree(list[i]);
							i++;
							size=1;
							
							cout<<" ------------------------------------------- "<<endl;
					        cout<<"| 1. Print it.                              |"<<endl;
					        cout<<"| 2. Save it.                               |"<<endl;
					        cout<<"| 3. Go to main menu.                       |"<<endl;
							cout<<" ------------------------------------------- "<<endl;
							cout<<" Enter your choice  : \n";
					        cin>>ch9;
							switch (ch9)
							{
								//case print it
								case 1:
								{								    
									cout<<endl;
									cout<<" Printing "<<endl;
									cout<<" --------------------"<<endl;	
									initialTree.print_inorder();
									cout<<endl;
									cout<<endl;
									initialTree.clear();
								}
								break;
								//case save it to a file
								case 2:
								{
									cout<<" Enter a name for the tree : ";
									cin>>file_name;	
									outFile.open(file_name);
									for (int i=0;i<size;i++)
									{
										outFile<<list[i]<<" ";
									}
									outFile.close();
									cout<<endl<<endl;
									cout<<" Saving............"<<endl;
									cout<<endl<<endl;
									cout<<" Tree saved successfully! "<<endl;										
								}
								break;
								case 3:
								break;								
							}							
						}
						break;
						//case create a new tree from STDIN (can be saved to .txt)
						case 2:
						{						
							list.clear();
							b.clear();
							i=0;
							size=0;	
							temp=0;
							while (temp!=-1)
							{
								cout<<" Enter Number to be inserted(-1 to terminate) : ";				
								cin>>temp;	
								if (temp!=-1)
								{
									list.push_back(temp);	
									
									i++;
									size++;									
								}								
							}	
							BinaryTree c(list); // Calling the binaryTree with vector  constructor
							b=c;			    // Copying it to b because we are using only the b to print.
							c.clear();
						}
						break;
						//case create a new tree from STDIN (can Not be saved to .txt)
						case 3:
						{
							b.clear();
							list.clear();												
							cout<<" Start inserting numbers and enter -1 to stop: ";				
							cin>>b;							 // Overloaded operator >> is called 
						}				
						break;
						//case load an existing tree from a .txt file
						case 4:
						list.clear();
						b.clear();
						size=0;
						cout << " Enter the name of the file you wish to open: "<<endl;				
						cin>>file_name;				
						infile.open(file_name.c_str( ));				
						while (infile>>x)
						{
							list.push_back(x);
						}
						infile.close();
						for (int i=0;i<list.size();i++)
						{
							b=b+list[i];   // Overloaded operator + is called.
							size++;
						}			
						break;
						// case save existing tree to a .txt file
						case 5 :
						cout<<" Enter a name for the tree : ";
						cin>>file_name;	
						outFile.open(file_name);
						for (int i=0;i<size;i++)
						{
							outFile<<list[i]<<" ";
						}
						outFile.close();
						cout<<endl<<endl;
						cout<<" Saving............"<<endl;
						cout<<endl<<endl;
						cout<<" Tree saved successfully! "<<endl;				
						break; 
						//case Deep copy a tree
						case 6:
						{
							cout<<" ------------------------------------------- "<<endl;				
							cout<<"|ENTER TREE INPUT :                         |"<<endl;				
							cout<<"| 1. Enter new tree from STDIN.             |"<<endl;
							cout<<"| 2. Insert an existing tree from a txt.    |"<<endl;	
							cout<<"| 3. Go back.                               |"<<endl;	
							cout<<" ------------------------------------------- "<<endl;									
							cout<<" Enter your choice  : \n";
							cin>>ch7;
							BinaryTree original;							
							switch (ch7)
							{
								//case enter new tree from STDIN
								case 1:
								{
									list.clear();
									i=0;
									size=0;	
									temp=0;
									while (temp!=-1)
									{
										cout<<" Enter Number to be inserted(-1 to terminate) : ";				
										cin>>temp;	
										if (temp!=-1)
										{
											list.push_back(temp);				
											original=original+list[i];	  // Overloaded operator + is called.
											i++;
											size++;
										}
									}			
								}
								break;
								//case insert an existing tree from a .txt file
								case 2:
								{
									list.clear();
									temp=0;
									size=0;
									cout << " Enter the name of the file you wish to copy: "<<endl;				
									cin>>file_name;				
									infile.open(file_name.c_str( ));				
									while (infile>>x)
									{
										list.push_back(x);
									}
									infile.close();
									for (int i=0;i<list.size();i++)
									{
										original=original+list[i];    // Overloaded operator + is called.
										size++;
									}			
								}
								break;
								case 3:
								break;
							}
							cout<<" ------------------------------------------- "<<endl;									
							cout<<"| 1. Copy tree and save it.                 |"<<endl;
							cout<<"| 2. Copy tree and print it inorder         |"<<endl;	
							cout<<"| 3. Go back.                               |"<<endl;	
							cout<<" ------------------------------------------- "<<endl;									
							cout<<" Enter your choice : \n";
							cin>>ch8;
							BinaryTree copied;							
							switch (ch8)
							{
								//case Copy tree and save.
								case 1:
								{
									copied=original;		// is calling the operator overload = and applies deep copy
									cout<<" Enter a name for the tree : ";
									cin>>file_name;	
									outFile.open(file_name);
									for (int i=0;i<size;i++)
									{
										outFile<<list[i]<<" ";
									}
									outFile.close();
									cout<<endl<<endl;
									cout<<" Saving............"<<endl;
									cout<<endl<<endl;
									cout<<" Tree saved successfully! "<<endl;		
								}
								break;
								//case Copy tree and print inorder.
								case 2:
								{
									copied=original;		// is calling the operator overload = and applies deep copy
									cout<<"Printing copied tree inorder:\n"<<copied<<endl; // is calling the operator overload <<
								}
								break;
								case 3:
								break;		
							}
						}
						break;	
						//case check if two trees are equal
						case 7:	
						{   
							BinaryTree first;
							BinaryTree second;
							ch3=0;
							while (ch3!=6)
							{
								cout<<" ------------------------------------------- "<<endl;				
								cout<<"|ENTER THE FIRST TREE INPUT :               |"<<endl;				
								cout<<"| 1. Enter new tree from STDIN.             |"<<endl;
								cout<<"| 2. Insert an existing tree from a txt.    |"<<endl;	
								cout<<" ------------------------------------------- "<<endl;									
								cout<<" Enter your choice  : \n";
								cin>>ch3;
								switch(ch3)
								{	//case new tree from STDIN				
									case 1 :
									{ 	
										list.clear();
										temp=0;
										i=0;
										size=0;				
										while (temp!=-1)
										{
											cout<<" Enter Number to be inserted (-1 to terminate) : ";				
											cin>>temp;	
											if (temp!=-1)
											{
												list.push_back(temp);				
												first=first+list[i];	  // Overloaded operator + is called.
												i++;
												size++;
											}
										}	
										cout<<"First tree was successfully inserted!"<<endl;
										cout<<"first is:"<<first<<endl;
									}
									break;	
									//case existing tree from .txt file
									case 2:
									{
										list.clear();
										//BinaryTree first;
										size=0;
										cout << " Enter the name of the file you wish to open: "<<endl;				
										cin>>file_name;				
										infile.open(file_name.c_str( ));				
										while (infile>>x)
										{
											list.push_back(x);
										}
										infile.close();
										for (int i=0;i<list.size();i++)
										{
											first=first+list[i];   // Overloaded operator + is called.
											//size++;
										}
										cout<<"First tree was successfully inserted!"<<endl;
										cout<<"first is:"<<first<<endl;
									}
									break;
								}	
								cout<<" ------------------------------------------- "<<endl;	
								cout<<"|ENTER THE SECOND TREE INPUT :              |"<<endl;				
								cout<<"| 1. Enter new tree from STDIN.             |"<<endl;
								cout<<"| 2. Insert an existing tree from a txt.    |"<<endl;
								cout<<" ------------------------------------------- "<<endl;
								cout<<" Enter your choice : \n";
								cin>>ch4;
								switch(ch4)
								{
									//case second tree from STDIN
									case 1:
									{ 
										list.clear();
										//BinaryTree second;
										i=0;
										size=0;		
										temp=0;
										while (temp!=-1)
										{
											cout<<" Enter Number to be inserted(-1 to terminate) : ";				
											cin>>temp;	
											if (temp!=-1)
											{
												list.push_back(temp);				 
												second = second + list[i];	   // Overloaded operator + is called.
												i++;
												size++;
											}
										}
										cout<<"Second tree was successfully inserted!"<<endl;
										cout<<"second is:"<<second<<endl;
									}
									break;	
									//case second tree from .txt file
									case 2:
									{
										list.clear();
										//BinaryTree second;
										size=0;
										cout <<" Enter the name of the file you wish to open: "<<endl;				
										cin>>file_name;				
										infile.open(file_name.c_str( ));				
										while (infile>>x)
										{
											list.push_back(x);
										}
										infile.close();
										for (int i=0;i<list.size();i++)
										{
											second = second + list[i];	   // Overloaded operator + is called.
											//size++;
										}	
										cout<<"Second tree was successfully inserted!"<<endl;
										cout<<"second is:"<<second<<endl;
									}
									break;
								}
								cout<<" ------------------------------------------- "<<endl;
								cout<<"| 1. COMPARE !!                             |"<<endl;						
								cout<<"| 2. Go to main menu                        |"<<endl;						
								cout<<" ------------------------------------------- "<<endl;
								cout<<" Enter your choice : \n";
								cin>>ch5;
								switch(ch5)
								{	
									//case compare
									case 1:
									{										
										first==second;	// is calling the equality overloaded operator ==						
									}
									break;	
									case 2:									
									break;									
								}
								break;
							}
						}						
						break;
						
					}
					
				}
			}			
			break;
			//case print options
			case 2 :
			{
				cout<<endl<<endl;
				cout<<" Binary Tree Operations "<<endl;
				cout<<" --------------------------------- "<<endl;			
				cout<<"| 1. Print inorder                |"<<endl;
				cout<<"| 2. Print postorder              |"<<endl;
				cout<<"| 3. Print preorder               |"<<endl;	   		
				cout<<"| 4. Go back                      |"<<endl;
				cout<<" --------------------------------- "<<endl;
				cout<<" Enter your choice: \n";		
				cin>>ch6;
				switch(ch6)
				{
					//inorder
					case 1:
					{
						cout<<endl;
						cout<<" Printing "<<endl;
						cout<<" --------------------"<<endl;						
						cout<<b;
					}
					break;
					//postorder
					case 2:
					{
						cout<<endl;
						cout<<" Printing "<<endl;
						cout<<" --------------------"<<endl;
						b.print_postorder();
					}
					break;
					//preorder
					case 3:
					{
						cout<<endl;
						cout<<" Printing "<<endl;
						cout<<" --------------------"<<endl;
						b.print_preorder();
					}
					break;
					case 4:
					break;					
				}
				break;	
			}
			//case removal
			case 3 : 
			cout<<" Enter data to be deleted : ";
			cin>>temp2;			
			b=b-temp2; //operator - overloaded
			break;
			//case Exists
			case 4 :
			{
				cout<<" Enter Number to search : ";
				cin>>temp3;			
				answr=b.exists(temp3);
				if (answr)			
				cout << "True!" << endl;
				else
				cout << "False!" <<endl;
			}
			break;
			case 5:
			return 0;
			default :
			cout<<"Please insert a valid choice"<<endl;
			break;			
		}
	}
}				