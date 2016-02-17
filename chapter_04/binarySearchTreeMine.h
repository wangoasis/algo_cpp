#ifndef binarySearchTreeMine_H
#define binarySearchTreeMine_H
#include <stdio.h>
#include <iostream>
using namespace std;

/*
    notes:
    1. to process a tree, the most important prior is that whether whis tree is existing or not,
    therefore, every function should be cautios to check root == NULL ?
*/

template <typename Comparable>
class binarySearchTreeMine {
public:
    binarySearchTreeMine () {
        root = NULL;
    }

    binarySearchTreeMine (const binarySearchTreeMine & rhs) {
        if(this != &rhs)
            *this = rhs;
    }

    const binarySearchTreeMine & operator = (const binarySearchTreeMine & rhs) {
        if(this != &rhs) {
            makeEmpty();
            root = clone(rhs.root);
        }
        return *this;
    }

    ~binarySearchTreeMine () {
        makeEmpty();
    }

    const Comparable & findMax () const {
        binaryNode* node = findMax(root);
        return node->data;
    }

    const Comparable & findMin () const {
        binaryNode* node = findMin(root);
        return node->data;
    }

    bool contains(const Comparable & x) const {
        return contains(x, root);
    }

    bool isEmpty() const {
        return root == NULL;
    }

    void printTree (ostream & out = cout) const {
        // check whether the tree is empty
        if(isEmpty())
            out << "empty tree!" << endl;
        else 
            printTree(root, out);
    }

    void makeEmpty() {
        makeEmpty(root);
    }

    void insert(const Comparable & x) {
        insert(x, root);
    }

    void remove(const Comparable & x) {
        remove(x, root);
    }

private:
    struct binaryNode
    {
        Comparable data;
        binaryNode* left;
        binaryNode* right;

        binaryNode(const Comparable & x, binaryNode* l, binaryNode* r)
        : data(x), left(l), right(r) {}
    };

    binaryNode* root;

    void insert(const Comparable & x, binaryNode * & node) {
        // notice that: we use binaryNode* & node here, not binaryNode* node
        // the reason for this parameter is: 
        // if we use binaryNode*, it's just passing the value, although the value is a pointer.
        // if we change the value of node inside the function, it doesn't impact the argument.
        // However, here we need to create a new node. 
        if(node == NULL)
            node = new binaryNode(x, NULL, NULL);
        else if(x < node->data)
            insert(x, node->left);
        else if(x > node->data)
            insert(x, node->right);
        else ;
    }

    void remove(const Comparable & x, binaryNode * & node) {
        if(node == NULL)
            return;
        else if(x < node->data)
            remove(x, node->left);
        else if(x > node->data)
            remove(x, node->right);
        else if(node->left != NULL && node->right != NULL) {
            node->data = findMin(node->right)->data;
            remove(node->data, node->right);
        }
        else if(!node->left && !node->right)
            delete node;
        else { 
            // only one of node->left and node->right equals NULL
            binaryNode* old = node;
            node = node->left == NULL ? node->right : node->left;
            delete old;
        }
    }

    binaryNode* findMin(binaryNode* node) const {
        if(node == NULL)
            return NULL;
        if(node->left == NULL)
            return node;
        return findMin(node->left);
    }

    binaryNode* findMax(binaryNode* node) const {
        if(t == NULL)
            return NULL;
        if(t->right == NULL)
            return t;
        return findMax(t->right);
    }

    bool contains(const Comparable & x, binaryNode* node) const {
        if(node == NULL)
            return false;
        if(x < node->data)
            return contains(x, node->left);
        else if(x > node->data)
            return contains(x, node->right);
        else
            return true;
    }

    void makeEmpty(binaryNode* & node) {
        if(node != NULL) {
            makeEmpty(node->left);
            makeEmpty(node->right);
            delete node;
        }
        node = NULL;
    }

    void printTree(binaryNode* node, ostream & out) const {
        if(node != NULL) {
            printTree(node->left, out);
            out << node->data << endl;
            printTree(node->right, out);
        }
    }

    binaryNode* clone(binaryNode* node) {
        if(node == NULL)
            return NULL;

        return new binaryNode(node->data, clone(node->left), clone(node->right));
    }
};
#endif
