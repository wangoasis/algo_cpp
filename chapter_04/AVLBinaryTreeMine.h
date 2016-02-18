/*
    without test
*/
#ifndef AVLBinaryTreeMine_H
#define AVLBinaryTreeMine_H
#include <iostream>
#include <stdio.h>
using namespace std;

template <typename Comparable>
class AVLBinaryTreeMine {

private:
    struct AVLBinaryNode
    {
        Comparable data;
        AVLBinaryNode* left;
        AVLBinaryNode* right;
        int height;

        AVLBinaryNode(const Comparable & obj, AVLBinaryNode* l, AVLBinaryNode* r)
        : data(obj), left(l), right(r) {}
    };

public:
    AVLBinaryTreeMine () {
        root = NULL;
    }

    AVLBinaryNode* root;

    AVLBinaryTreeMine (const AVLBinaryTreeMine & rhs) {
        if(this != rhs)
            *this = rhs;
    }

    const AVLBinaryTreeMine & operator = (const AVLBinaryTreeMine & rhs) {
        if(this != &rhs) {
            makeEmpty();
            root = clone(rhs.root);
        }
        return *this;
    }

    ~AVLBinaryTreeMine () {
        makeEmpty();
    }

    bool contains(const Comparable & x) const {
        return contains(x, root);
    }

    const Comparable & findMin() const {
        AVLBinaryNode* node = findMin(root);
        if(node)
            return node->data;
        else 
            return NULL;
    }

    const Comparable & findMax() const {
        AVLBinaryNode* node = findMax(root);
        if(node)
            return node->data;
        else 
            return NULL;
    }

    bool isEmpty() const {
        return root == NULL;
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

    void printTree(ostream & out = cout) const {
        if(isEmpty())
            out << "empty tree!" << endl;
        else
            printTree(root, out);
    }

private:
    int height(AVLBinaryNode* node) const {
        return node == NULL ? -1 : node->height;
    }

    void insert(const Comparable & x, AVLBinaryNode * & node) {
        if(node == NULL)
            node = new AVLBinaryNode(x, NULL, NULL);
        else if(x < node->data) {
            insert(x, node->left);
            if(height(node->left) - height(node->right) == 2) {
                if(x < node->left->data) 
                    rotateWithLeftChild(node);
                else
                    doubleWithLeftChild(node);
            }
        }
        else if(x > node->data) {
            insert(x, node->right);
            if(height(node->right) - height(node->left) == 2) {
                if(x > node->right->data)
                    rotateWithRightChild(node);
                else
                    doubleWithRightChild(node);
            }
        }
        else ;

        node->height = max(height(node->left), height(node->right)) + 1;
    }

    void rotateWithLeftChild(AVLBinaryNode * & k2) {
        AVLBinaryNode* k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2 = k1;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k1->height = max(height(k1->left), k2->height) + 1;
    }

    void rotateWithRightChild(AVLBinaryNode * & k2) {
        AVLBinaryNode* k1 = k2->right;
        k2->right = k1->left;
        k1->left = k2;
        k2 = k1;
        k2->height = max(height(k2->left), height(k2->right)) + 1;
        k1->height = max(height(k1->right), k2->height) + 1;
    }

    void doubleWithLeftChild(AVLBinaryNode * & k3) {
        rotateWithRightChild(k3->left);
        rotateWithLeftChild(k3);
    } 

    void doubleWithRightChild(AVLBinaryNode * & k3) {
        rotateWithLeftChild(k3->right);
        rotateWithRightChild(k3);
    }

    void remove(const Comparable & x, AVLBinaryNode * & node) {

    }

    AVLBinaryNode* clone(AVLBinaryNode * node) {
        if(node == NULL)
            return NULL;

        return new node(node->data, clone(node->left), clone(node->right));
    }

    bool contains(const Comparable & x, AVLBinaryNode * node) {
        if(node == NULL)
            return false;
        if(x < node->data)
            return contains(x, node->left);
        else if(x > node->data) 
            return contains(x, node->right);
        else
            return true;
    }

    AVLBinaryNode* findMin(AVLBinaryNode* node) {
        if(node == NULL)
            return NULL;
        if(node->left == NULL)
            return node;
        return findMin(node->left);
    }

    AVLBinaryNode* findMax(AVLBinaryNode* node) {
        if(node == NULL)
            return NULL;
        if(node->right == NULL)
            return node;
        return findMax(node->right);
    }

    void printTree(AVLBinaryNode* node, ostream & out) const {
        if(node != NULL) {
            printTree(node->left, out);
            out << node->data << endl;
            printTree(node->right, out);
        }
    }

    void makeEmpty(AVLBinaryNode* node) {
        if(node != NULL) {
            makeEmpty(node->left);
            makeEmpty(node->right);
            delete node;
        }
        node = NULL;
    }
};
#endif
