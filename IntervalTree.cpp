//
// Created by Esawy on 5/23/2023.
//

#include "IntervalTree.h"


IntervalTree::IntervalTree() {
    root = nullptr;
    size = 0;
}

//insert new Interval
Node *IntervalTree::InsertInterval(Interval it) {
    size++;
    root = root->InsertInterval(root, it); //insert it into root of tree
}

Node *IntervalTree::DeleteInterval(Interval it) {
    root = root->DeleteInterval(root, it); //delete it from root of tree
}

// searching for the overlapping Intervals
void *IntervalTree::SearchInterval(Interval it)
{
    IO=new Interval[size]; // array of type Interval to store the overlapping Intervals
    cnt=0;// count of overlapping Intervals
    Interval* temp;
    bool x=1;
    while(x)
    {
        // assign temp Interval to the return of the search function
        temp=root->search(root,it);
        // if there is overlapping Interval/s returned
        if(temp!= nullptr)
        {
            size++; // increase the size of the array
            IO[cnt]=*temp; //  store the return of the search function in the array
            cnt++; // increase count of Intervals found
            root=root->DeleteInterval(root,*temp); // change the root node after the deletion
        }
        else{
            // break from the loop
            x=false;
        }
    }
    std::cout<<"searching Interval ["<<it.low<<","<<it.high<<"]\n";
    // printing the overlapping Intervals
    for(int i=0 ; i<cnt;i++)
    {
        std::cout<<"["<<IO[i].low<<","<<IO[i].high<<"]\n"; // print each Interval
    }
    // inserting the deleted Intervals again
    for(int i=0 ; i<cnt;i++)
    {
        // insert each Interval in the array
        InsertInterval(IO[i]);
    }
}

void IntervalTree::inorder() {
    return (root->inorder(root)); //print the tree
}