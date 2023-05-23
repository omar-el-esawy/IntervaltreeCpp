//
// Created by Esawy on 5/23/2023.
//

#ifndef UNTITLED5_NODE_H
#define UNTITLED5_NODE_H

#include <iostream>
#include "Interval.h"

//interval tree node (based on BST)
class Node {
    Interval *it; //node Interval
    int maximum; //maximum
    Node *left, *right; //children
/*    int cnt;
    Interval *IO;*/
public:
    Node(Interval i) ;

    //insert new node in root node
    Node *InsertInterval(Node *root, Interval it) ;

    //function returns maximum of two numbers (used in setting the maximum value)
    int getMax(int it1, int it2) ;

    //get inorder successor of node (least child low in left subtree)
    Node *minInterval(Node *node);

    //this function re-adjust the maximum values for each node in tree
    //to be updated after deletion
    Node *adjustMax(Node *node);

    //Deleting a node
    Node *DeleteInterval(Node *root, Interval keyIt);

// printing the content of the tree
    void inorder(Node *node);

    //this function checks if two Intervals overlap
    bool overlap(Interval i1, Interval i2);

    Interval* search(Node* root,Interval it);

};


#endif //UNTITLED5_NODE_H
