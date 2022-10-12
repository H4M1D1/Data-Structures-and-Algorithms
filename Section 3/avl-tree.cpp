#include "avl-tree.h";
using namespace std;


bool AVLTree::insert(DataType val)
{
    if (!BinarySearchTree::insert(val)) {

        return false;
    }

    Node* root = getRootNode();

    checkBalance(root);

    return true;
}


bool AVLTree::remove(DataType val)
{
    if(!BinarySearchTree::remove(val)) {

        return false;
    }

    Node* root = getRootNode();

    checkBalance(root);

    return true;
}


int AVLTree::findDiff(Node* node) 
{
    int leftTree = 0;
    int rightTree = 0;

    if (node->left != nullptr) {

        updateNodeBalance(node->left);

        leftTree = node->left->avlBalance + 1;
    }

    if (node->right != nullptr) {

        updateNodeBalance(node->right);

        rightTree = node->right->avlBalance + 1;
    }

    return leftTree - rightTree;
}


void AVLTree::checkBalance(Node* node) 
{
    if (node == nullptr) return;

    checkBalance(node->right);
    checkBalance(node->left);

    int primaryHeightDiff = findDiff(node); 

    if (primaryHeightDiff > 1) 
    { 

        int secondaryHeightDiff = findDiff(node->left); 

        if (secondaryHeightDiff >= 0) {

            singleRight(node);

        } else {

            leftRight(node);
        }

    } else if (primaryHeightDiff < -1) {

        int secondaryHeightDiff = findDiff(node->right);
        
        if (secondaryHeightDiff > 0) {

            rightLeft(node);

        } else {

            singleLeft(node);
        }
    }
}


void AVLTree::singleLeft(Node* parent) 
{
    Node* leftNode = new Node(parent->val);

    leftNode->left = parent->left;
    leftNode->right = parent->right->left;

    parent->val = parent->right->val;
    parent->left = leftNode;
    parent->right = parent->right->right;
}

void AVLTree::singleRight(Node* parent) 
{
    Node* rightNode = new Node(parent->val);

    rightNode->right = parent->right;
    rightNode->left = parent->left->right;

    parent->val = parent->left->val;
    parent->right = rightNode;
    parent->left = parent->left->left;
}

void AVLTree::leftRight(Node* parent) 
{
    singleLeft(parent->left);
    singleRight(parent);
}

void AVLTree::rightLeft(Node* parent) 
{
    singleRight(parent->right);
    singleLeft(parent);
}
