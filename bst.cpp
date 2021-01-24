#include "bst.h"
//Please put your implemenation of required functions here
//
int table::copyToArray(int intArray[]) const
{
    int numberOfItems = 0;
    helperOne(intArray, root, numberOfItems);
    return numberOfItems;
}

void table::helperOne(int intArray[], node * curr, int & numberOfItems) const
{
    if(curr == nullptr)
    {
        return;
    }
    else
    {
        intArray[numberOfItems] = curr->data;
        numberOfItems++;
        helperOne(intArray, curr->left, numberOfItems);
        helperOne(intArray, curr->right, numberOfItems);
    }
}

void table::copyNonLeaf(node *& newRoot)
{
    copyNonLeaf(root, newRoot);
    return; }

void table::copyNonLeaf(node * curr, node *& newRoot)
{
    if(curr)
    {
        if(newRoot == nullptr && (curr->left || curr->right))
        {
            newRoot = new node;
            newRoot->data = curr->data;
            newRoot->left = newRoot->right = nullptr;
            copyNonLeaf(curr->left, newRoot->left);
            copyNonLeaf(curr->right, newRoot->right);
        }
    }
}

void table::displayDuplicate(node * curr) const
{
    if(curr == nullptr)
    {
        return;
    }
    else
    {
        displayDuplicate(curr->left);
        cout << curr->data << " ";
        displayDuplicate(curr->right);
    }
}

void table::deleteList(node * curr)
{
    node * trash = curr;
    if(curr->left){
        deleteList(curr->left);
    }
    if(curr->right){
        deleteList(curr->right);
    }
    delete trash;
}

node *  table::duplicateToList()
{
    node * newNode = new node;
    newNode->data = root->data;
    if(root->left){
        duplicateToList(newNode->left, root->left);
        return newNode;
    }
    else if(root->right){
        duplicateToList(newNode->left, root->right);
        return newNode;
    }
    else{
        return newNode;
    }
}

void table::duplicateToList(node *& newHead, node * curr)
{
    /*if(curr == root)
    {
        newHead = new node;
        newHead->data = curr->data;
        duplicateToList(newHead->left, curr->left);
        duplicateToList(newHead->left, curr->right);
    }*/
    if(curr == nullptr)
    {
        return;
    }
    duplicateToList(newHead->left, curr->left);
    newHead = new node;
    newHead->data = curr->data;
    duplicateToList(newHead->left, curr->right);
}

void table::printList(node * curr)
{
    if(curr == nullptr)
    {
        return;
    }

    printList(curr->left);
    cout << "data: " << curr->data << endl;
    printList(curr->right);
}

int table::maxDepth()
{
    int max = maxDepth(root);
    return max;
}

int table::maxDepth(node * curr)
{
    if(curr == nullptr)
    {
        return 0;
    }
    else
    { 
        int lDepth = maxDepth(curr->left);
        int rDepth = maxDepth(curr->right);
        if(lDepth > rDepth)
        {
            return ++lDepth;
        }
        else
        {
            return ++rDepth;
        }
    }
}

void table::sumLevel(int & sum, int maxDepth)
{
    sumLevel(maxDepth, 0, root, sum);
}

void table::sumLevel(int maxDepth, int currentLocation, node * curr, int & sum)
{
    if(curr == nullptr)
    {
        return;
    }
    if(currentLocation == (maxDepth-2))
    {
        cout << "at maxDepth - 1 " << curr->data << endl;
        sum += curr->data;
        return;
    }
    currentLocation = currentLocation + 1;
    sumLevel(maxDepth, currentLocation, curr->left, sum);
    sumLevel(maxDepth, currentLocation, curr->right, sum);
}

void table::deletion(node *& curr)
{
    if(curr->right == nullptr && curr->left == nullptr)
    {
        delete curr;
        curr = nullptr;
        return;
    }
    else if(curr->right == nullptr)
    {
        node * trash = curr;
        curr = curr->left;
        delete trash;
        return;
    }
    else if(curr->left == nullptr)
    {
        node * trash = curr;
        curr = curr->right;
        delete trash;
        return;
    }
    else
    {
        curr->data = getMin(curr->right);
        remove(curr->right, curr->data);
    }
}

int table::getMin(node * curr)
{
    if(curr->left == nullptr)
    {
        return curr->data;
    }
    getMin(curr->left); 
}

void table::remove(int target)
{
    remove(root, target);
}

void table::remove(node *& curr, int target)
{
    if(curr == nullptr)
    {
        cout << "node not found " << endl;
        return;
    }
    if(target > curr->data)
    {
        remove(curr->right, target);
    }
    else if(target < curr->data)
    {
        remove(curr->left, target);
    }
    else if(curr->data == target)
    {
        deletion(curr);
    }
    else
    {
        cout << "node not found " << endl;
    }
}


