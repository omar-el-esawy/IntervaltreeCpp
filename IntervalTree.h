//
// Created by Esawy on 5/23/2023.
//

#ifndef UNTITLED5_INTERVALTREE_H
#define UNTITLED5_INTERVALTREE_H

#include "Node.h"
#include "Interval.h"

class IntervalTree {
private:
    Node *root;
    int size;
    int cnt;
    Interval *IO;

public:
    //default constructor
    IntervalTree();

    //insert new Interval
    Node *InsertInterval(Interval it);

    Node *DeleteInterval(Interval it);

    // searching for the overlapping Intervals
    void *SearchInterval(Interval it);

    void inorder();

};

#endif //UNTITLED5_INTERVALTREE_H
