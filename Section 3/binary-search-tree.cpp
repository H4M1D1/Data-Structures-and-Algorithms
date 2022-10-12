#include "binary-search-tree.h"
#include "iostream"
using namespace std;

BinarySearchTree::Node::Node(DataType newval)
{
    val = newval;

    left = nullptr;

    right = nullptr;

    avlBalance = 0;
}

void BinarySearchTree::updateNodeBalance(Node *n) {

    n->avlBalance = getNodeDepth(n);
}

int BinarySearchTree::getNodeDepth(Node* n) const
{
    if(n == nullptr) {
        return -1;
    }

    int left = getNodeDepth(n->left);
    int right = getNodeDepth(n->right);

    return (left > right) ? left + 1 : right + 1;
}

BinarySearchTree::BinarySearchTree()
{
    size_ = 0;

    root_ = nullptr;
}

void deleteTree(BinarySearchTree::Node* node) {

    if (node != nullptr) {

        deleteTree(node->left);
        deleteTree(node->right);

        delete node;
    }
}

BinarySearchTree::~BinarySearchTree()
{
    deleteTree(root_);
}


unsigned int BinarySearchTree::size() const
{
    return size_;
}


BinarySearchTree::DataType BinarySearchTree::max() const
{
    Node* node = root_;

    while (node) {

        if (node->right == nullptr) {

            return node->val;
        }

        node = node->right;
    }
}

BinarySearchTree::DataType BinarySearchTree::min() const
{
    Node* node = root_;

    while (node) {

        if (node->left == nullptr) {

            return node->val;
        }

        node = node->left;
    }
}

unsigned int BinarySearchTree::depth() const
{
    return getNodeDepth(root_);
}

void printTree(BinarySearchTree::Node* node) {
    if (node == nullptr) {
        return;
    }

    printTree(node->left);

    cout << node->val << ", ";

    printTree(node->right);
}

void BinarySearchTree::print() const
{
    printTree(root_);

    cout << endl;
}

bool BinarySearchTree::exists(DataType val) const
{
    Node* node = root_;
    while (node) {
        if (val == node->val) {
            return true;

        } else if (val > node->val) {
            node = node->right;

        } else {
            node = node->left;
        }
    }

    return false;
}

BinarySearchTree::Node* BinarySearchTree::getRootNode()
{
    return root_;
}

BinarySearchTree::Node** BinarySearchTree::getRootNodeAddress()
{
    return &root_;
}


void insertNode(BinarySearchTree::Node* node, BinarySearchTree::Node* newNode) {
    if (newNode->val > node->val && node->right == nullptr) {

        node->right = newNode;

    } else if (newNode->val < node->val && node->left == nullptr) {

        node->left = newNode;

    } else if (newNode->val > node->val) {

        insertNode(node->right, newNode);

    } else if (newNode->val < node->val) {

        insertNode(node->left, newNode);
    }
}

bool BinarySearchTree::insert(DataType val)
{
    Node* newNode = new Node(val);

    if (root_ == nullptr) {

        root_ = newNode;
        size_++;

        return true;
    }

    insertNode(root_, newNode);

    if(exists(val)) {

        size_++;

        return true;
    }

    return false;
}

BinarySearchTree::Node* getPredecessor(BinarySearchTree::Node* node) {

    if (node->right == nullptr) {

        return node;
    }

    return getPredecessor(node->right);
}

BinarySearchTree::Node* removeNode(BinarySearchTree::Node* node, BinarySearchTree::DataType val) {

    if (node == nullptr) {

        return nullptr;
    }

    if(node->val == val) {

        if(node->left == nullptr && node->right == nullptr) {

            return nullptr;

        } else if (node->right == nullptr) {

            return node->left;

        } else if (node->left == nullptr) {

            return node->right;
        }

        BinarySearchTree::Node* replacementNode = getPredecessor(node->left);

        node->val = replacementNode->val;
        node->left = removeNode(node->left, replacementNode->val);

    } else if (val > node->val) {

        node->right = removeNode(node->right, val);

    } else {

        node->left = removeNode(node->left, val);
    }

    return node;
}

bool BinarySearchTree::remove(DataType val)
{
    if(!exists(val)) {

        return false;
    }

    root_ = removeNode(root_, val);

    if(!exists(val)) {

        size_--;

        return true;
    }
    
    return false;
}
