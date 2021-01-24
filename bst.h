#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

struct node
{
    int data;   //some questions use char * data;
    node * left;
    node * right;
};

class table
{
    public:
    	//These functions are supplied already
    	table();			//supplied
    	~table();			//supplied
        void build(); 		//supplied
        void display(); 	//supplied


/* ************** PLACE YOUR PROTOTYPE HERE ***************** */
        int copyToArray(int intArray[])const;
        void helperOne(int intArray[], node * curr, int & numberOfItems)const;
        void copyNonLeaf(node *& newRoot);
        void copyNonLeaf(node * curr, node *& newRoot);
        void displayDuplicate(node * curr) const;
        void deleteList(node * curr); 
        node * duplicateToList();
        void printList(node * curr);
        void duplicateToList(node *& newHead, node * curr);
        int maxDepth();
        int maxDepth(node * curr); 
        void deletion(node *& curr);
        int getMin(node * curr);
        void remove(int target);
        void remove(node *& curr, int target);
        void sumLevel(int maxDepth, int currentLocation, node * curr, int & sum);
        void sumLevel(int & sum, int maxDepth); 
 	private:
 		node * root;
};
  

