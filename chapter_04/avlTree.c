#include "avlTree.h"
#include "fatal.h"
#include <stdlib.h>
#include <stdio.h>

struct avlNode {
    
    elementType element;
    avlTree leftChild;
    avlTree rightChild;
    int height;    
};

avlTree makeEmpty(avlTree tree) {
    
    if(!tree) {
        
        makeEmpty(tree->leftChild);
        makeEmpty(tree->rightChild);
        free(tree);
    }
    return NULL;
}

position findMin(avlTree tree) {
    
    if(tree) {
    
        if(tree->leftChild)
            return findMin(tree->leftChild);
        else
            return tree;
    }
    return NULL;
}

position findMax(avlTree tree) {
    
    if(tree) {
    
        if(tree->rightChild)
            return findMax(tree->rightChild);
        else
            return tree;
    }
    return NULL;
}

elementType retrieve(position p) {
    
    if(!p)
        return p->element;
    return 0;
}

static int height (avlTree tree) {
    
    return tree ? tree->height : -1;
}

static elementType max(elementType e1, elementType e2) {
    
    return e1 > e2 ? e1 : e2;
}

static avlTree rotateWithLeftChild(position k2) {
    
    position k1 = k2->leftChild;
    k2->leftChild = k1->rightChild;
    k1->rightChild = k2;
    k2 = k1;
    k2->height = max(height(k2->leftChild), height(k2->rightChild)) + 1;
    k1->height = max(height(k1->leftChild), k2->height) + 1;

    return k2;
}

static avlTree rotateWithRightChild(position k2) {
    
    position k1 = k2->rightChild;
    k2->rightChild = k1->leftChild;
    k1->leftChild = k2;
    k2 = k1;
    k2->height = max(height(k2->leftChild), height(k2->rightChild)) + 1;
    k1->height = max(height(k1->rightChild), k2->height) + 1;

    return k2;
}

static avlTree doubleWithLeftChild(avlTree k3) {
    
    k3->leftChild = rotateWithRightChild(k3->leftChild);
    k3 = rotateWithLeftChild(k3);
}

static avlTree doubleWithRightChild(avlTree k3) {

    k3->rightChild = rotateWithLeftChild(k3->rightChild);
    k3 = rotateWithRightChild(k3);
}

avlTree insert(elementType value, avlTree tree) {
    
    if(!tree) {
        tree = malloc(sizeof(struct avlNode));
        if(!tree) 
            Error("out of memory: insert");

        tree->element = value;
        tree->leftChild = tree->rightChild = NULL;
        tree->height = 0;
        return tree;
    } else {

        if(value < tree->element) {

            tree->leftChild = insert(value, tree->leftChild);
            if(height(tree->leftChild) - height(tree->rightChild) == 2) {
                if(value < tree->leftChild->element)
                    tree = rotateWithLeftChild(tree);
                else
                    tree = doubleWithLeftChild(tree);
            }
        }
        else if(value > tree->element) {

            tree->rightChild = insert(value, tree->rightChild);
            if(height(tree->rightChild) - height(tree->leftChild) == 2) {
                if(value > tree->rightChild->element)
                    tree = rotateWithRightChild(tree);
                else
                    tree = doubleWithRightChild(tree);
            }
        }
        else; // value exists in the tree, needn't do anything

        tree->height = max(height(tree->leftChild), height(tree->rightChild));
        return tree;
    }
}

void inOrder(avlTree tree) {
    
    if(tree) {
    
        inOrder(tree->leftChild);
        printf("%d ", tree->element);
        inOrder(tree->rightChild);
    }
}
