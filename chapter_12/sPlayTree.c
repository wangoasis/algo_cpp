<<<<<<< HEAD
#include "sPlayTree.h"
#include "fatal.h"
#include <stdio.h>
#include <stdlib.h>

struct sPlayNode {

    elementType element;
    sPlayTree left;
    sPlayTree right;
};

static struct sPlayNode* nullNode = NULL;

// initialize nullNode
sPlayTree init(void) {

    if(!nullNode) {

        nullNode = malloc(sizeof(struct sPlayNode));
        if(!nullNode)
            Error("out of space");

        nullNode->left = nullNode->right = nullNode;
    }

    return nullNode;
}

sPlayTree makeEmpty(sPlayTree tree) {

    if(tree != nullNode) {    //-------------------------------------------------------

        makeEmpty(tree->left);
        makeEmpty(tree->right);
        free(tree);
    }

    return nullNode;
}

void inOrder(sPlayTree tree) {

    if(tree != nullNode) {

        inOrder(tree->left);
        printf("%d, ", tree->element);
        inOrder(tree->right);
    }
}

static sPlayTree singleRotateWithLeft(struct sPlayNode* k2) {

    struct sPlayNode* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    return k1;
}

static sPlayTree singleRotateWithRight(struct sPlayNode* k2) {

    struct sPlayNode* k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;

    return k1;
}

static sPlayTree sPlay(elementType value, sPlayTree tree) {

    nullNode->element = value;

    struct sPlayNode *rightTreeMin, *leftTreeMax;
    struct sPlayNode header;

    header.left = header.right = nullNode;
    leftTreeMax = rightTreeMin = &header;

    while(value != tree->element) {

        if(value < tree->element) {

            if(value < tree->left->element)
                tree = singleRotateWithLeft(tree);
            if(tree->left == nullNode)
                break;
            rightTreeMin->left = tree;
            rightTreeMin = rightTreeMin->left;
            tree = tree->left;
        } else {

            if(value > tree->right->element)
                tree = singleRotateWithRight(tree);
            if(tree->right == nullNode)
                break;
            leftTreeMax->right = tree;
            leftTreeMax = leftTreeMax->right;
            tree = tree->right;
        }
    }

    leftTreeMax->right = tree->left;
    rightTreeMin->left = tree->right;
    tree->left = header.right;    // header's right points to L
    tree->right = header.left;    // header's left points to R

    return tree;
}

sPlayTree insert(elementType value, sPlayTree tree) {

    struct sPlayNode* newNode;
    newNode = malloc(sizeof(struct sPlayNode));
    if(!newNode)
        Error("out of space");
    newNode->element = value;

    if(tree == nullNode) {

        newNode->left = newNode->right = nullNode;
        tree = newNode;
    } else {

        tree = sPlay(value, tree);

        if(value < tree->element) {

            newNode->left = tree->left;
            newNode->right = tree;
            tree->left = nullNode;
            tree = newNode;
        } else if(tree->element < value) {

            newNode->right = tree->right;
            newNode->left = tree;
            tree->right = nullNode;
            tree = newNode;
        } else ;    // tree->element == value

    }

    return tree;
}

elementType retrieve(sPlayTree tree) {

    return tree->element;
}

sPlayTree find(elementType value, sPlayTree tree) {

    return sPlay(value, tree);
}

sPlayTree findMax(sPlayTree tree) {

    return sPlay(infinity, tree);
}

sPlayTree findMin(sPlayTree tree) {

    return sPlay(negInfinity, tree);
}

sPlayTree delete(elementType value, sPlayTree tree) {

    sPlayTree newTree;

    if(tree != nullNode) {

        tree = sPlay(value, tree);
        if(value == tree->element) {

            if(tree->left == nullNode)
                newTree = tree->right;
            else {
                newTree = tree->left;
                newTree = sPlay(value, newTree);
                newTree->right = tree->right;
            }

            free(tree);
            tree = newTree;
        }
    }

    return tree;
}
=======
#include "sPlayTree.h"
#include "fatal.h"
#include <stdio.h>
#include <stdlib.h>

struct sPlayNode {

    elementType element;
    sPlayTree left;
    sPlayTree right;
};

static struct sPlayNode* nullNode = NULL;

// initialize nullNode
sPlayTree init(void) {

    if(!nullNode) {

        nullNode = malloc(sizeof(struct sPlayNode));
        if(!nullNode)
            Error("out of space");

        nullNode->left = nullNode->right = nullNode;
    }

    return nullNode;
}

sPlayTree makeEmpty(sPlayTree tree) {

    if(tree != nullNode) {    //-------------------------------------------------------

        makeEmpty(tree->left);
        makeEmpty(tree->right);
        free(tree);
    }

    return nullNode;
}

void inOrder(sPlayTree tree) {

    if(tree != nullNode) {

        inOrder(tree->left);
        printf("%d, ", tree->element);
        inOrder(tree->right);
    }
}

static sPlayTree singleRotateWithLeft(struct sPlayNode* k2) {

    struct sPlayNode* k1 = k2->left;
    k2->left = k1->right;
    k1->right = k2;

    return k1;
}

static sPlayTree singleRotateWithRight(struct sPlayNode* k2) {

    struct sPlayNode* k1 = k2->right;
    k2->right = k1->left;
    k1->left = k2;

    return k1;
}

static sPlayTree sPlay(elementType value, sPlayTree tree) {

    nullNode->element = value;

    struct sPlayNode *rightTreeMin, *leftTreeMax;
    struct sPlayNode header;

    header.left = header.right = nullNode;
    leftTreeMax = rightTreeMin = &header;

    while(value != tree->element) {

        if(value < tree->element) {

            if(value < tree->left->element)
                tree = singleRotateWithLeft(tree);
            if(tree->left == nullNode)
                break;
            rightTreeMin->left = tree;
            rightTreeMin = rightTreeMin->left;
            tree = tree->left;
        } else {

            if(value > tree->right->element)
                tree = singleRotateWithRight(tree);
            if(tree->right == nullNode)
                break;
            leftTreeMax->right = tree;
            leftTreeMax = leftTreeMax->right;
            tree = tree->right;
        }
    }

    leftTreeMax->right = tree->left;
    rightTreeMin->left = tree->right;
    tree->left = header.right;    // header's right points to L
    tree->right = header.left;    // header's left points to R

    return tree;
}

sPlayTree insert(elementType value, sPlayTree tree) {

    struct sPlayNode* newNode;
    newNode = malloc(sizeof(struct sPlayNode));
    if(!newNode)
        Error("out of space");
    newNode->element = value;

    if(tree == nullNode) {

        newNode->left = newNode->right = nullNode;
        tree = newNode;
    } else {

        tree = sPlay(value, tree);

        if(value < tree->element) {

            newNode->left = tree->left;
            newNode->right = tree;
            tree->left = nullNode;
            tree = newNode;
        } else if(tree->element < value) {

            newNode->right = tree->right;
            newNode->left = tree;
            tree->right = nullNode;
            tree = newNode;
        } else ;    // tree->element == value

    }

    return tree;
}

elementType retrieve(sPlayTree tree) {

    return tree->element;
}

sPlayTree find(elementType value, sPlayTree tree) {

    return sPlay(value, tree);
}

sPlayTree findMax(sPlayTree tree) {

    return sPlay(infinity, tree);
}

sPlayTree findMin(sPlayTree tree) {

    return sPlay(negInfinity, tree);
}

sPlayTree delete(elementType value, sPlayTree tree) {

    sPlayTree newTree;

    if(tree != nullNode) {

        tree = sPlay(value, tree);
        if(value == tree->element) {

            if(tree->left == nullNode)
                newTree = tree->right;
            else {
                newTree = tree->left;
                newTree = sPlay(value, newTree);
                newTree->right = tree->right;
            }

            free(tree);
            tree = newTree;
        }
    }

    return tree;
}
>>>>>>> origin/master
