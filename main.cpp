#include "bst.h"
//Please place your name here:
//
//

int main()
{
    table object;
    object.build(); 	//builds a BST
    object.display();	//displays a BST

    /*  PLACE YOUR FUNCTION CALL HERE */
    /*int arrayOne[100];
    int size = object.copyToArray(arrayOne);
    cout << "size of array/BST: " << size << endl;
    for(int i = 0; i < size; i++)
    {
        cout << arrayOne[i] << " " << endl;
    }
    node * newRoot = nullptr;
    cout << " " << endl;
    cout << "creating new bst with non leaf's" << endl;
    object.copyNonLeaf(newRoot);
    cout << "here is new bst with non leaf's" << endl;
    object.displayDuplicate(newRoot); */
    //node * newHead = object.duplicateToList();
    //cout << "new list" << endl;
    //object.printList(newHead);
    object.remove(22);
    int maxDepth = object.maxDepth();  
    int sum = 0;
    object.sumLevel(sum, maxDepth);
    cout << "sum: " << sum << " maxDepth-1: " << maxDepth-1 << endl;
    object.display();	//displays again after!
    //object.deleteList(newRoot); 
    return 0;
}
