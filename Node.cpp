//
// Created by Esawy on 5/23/2023.
//

#include "Node.h"
#include <iostream>
#include "Interval.h"

Node::Node(Interval i) {
//initialize node with its passed Interval
    this->it = new Interval(i);
    maximum = it->high;
    left = right = nullptr;
}

//insert new node in root node
Node *Node::InsertInterval(Node *root, Interval it) {
    //base case
    if (root == NULL) {
        root = new Node(it);
        return root;
    }
        //if new node's low value is less than root's low
        //it will be inserted in it's left subtree
    else if (it.low < root->it->low) {
        root->left = InsertInterval(root->left, it);
    }
        //if new node's low value is more than root's low
        //it will be inserted in its right subtree
    else {
        root->right = InsertInterval(root->right, it);
    }
    //if the node's high value is greater than the
    //maximum of root node, the maximum will be equal to high
    if (root->maximum < it.high) {
        root->maximum = it.high;
    }
    return root;
}

//function returns maximum of two numbers (used in setting the maximum value)
int Node::getMax(int it1, int it2) {
    if (it1 > it2) {
        return it1;
    } else {
        return it2;
    }
}

//get inorder successor of node (least child low in left subtree)
Node *Node::minInterval(Node *node) {
    Node *current = node;
    while (current && current->left != NULL) {
        current = current->left;
    }
    return current;
}

//this function re-adjust the maximum values for each node in tree
//to be updated after deletion
Node *Node::adjustMax(Node *node) {
    //base case

    if (node == NULL) {
        return node;
    }
    //if the node has no children
    if (node->right == NULL && node->left == NULL) {
        //node's maximum is its high
        node->maximum = node->it->high;
        return node;
    }
        //if the node has no right child
    else if (node->right == NULL) {
        //the node's maximum is the greater between the
        //left child's maximum value and it's high value
        node->maximum = getMax(node->it->high, node->left->maximum);
    }
        //if the node has no left child
    else if (node->left == NULL) {
        //the node's maximum is the greater between the
        //right child's maximum value and it's high value
        node->maximum = getMax(node->it->high, node->right->maximum);
    }
        //if it has 2 children
    else {
        //the node's maximum is the greater among the right child's maximum,
        //left child's maximum, and its high value
        node->maximum = getMax(node->it->high, getMax(node->left->maximum, node->right->maximum));
    }
}

//Deleting a node
Node *Node::DeleteInterval(Node *root, Interval keyIt) {
    // base case
    if (root == NULL) return root;

    //search for Interval to be deleted
    //if low is less than root's low, delete in its left subtree
    if (keyIt.low < root->it->low) {
        root->left = DeleteInterval(root->left, keyIt);
    }
        //if low is more than root's low, delete in its right subtree
    else if (keyIt.low > root->it->low) {
        root->right = DeleteInterval(root->right, keyIt);
    }
        //at node with Interval to be deleted
    else {
        // node has only one right child
        if (root->left == NULL) {
            Node *temp = root->right;
            free(root); //delete node
            return temp; //return its child
        }
            // node has only one left child
        else if (root->right == NULL) {
            Node *temp = root->left;
            free(root); //delete node
            return temp; //return its child
        }

        //get the inorder successor
        Node *temp = minInterval(root->right);

        //replace it with node to be deleted
        root->it = temp->it;

        //Delete the node
        root->right = DeleteInterval(root->right, *temp->it);

    }
    adjustMax(root);
    return root;
}

// printing the content of the tree


void Node::inorder(Node *node) {
    // if the tree doesn't exist
    if (node == NULL) return;

    std::cout << "[" << node->it->low << ", " << node->it->high << "]"
              << " max = " << node->maximum << "\n";
    //recursively print each node of the left subtree
    inorder(node->left);
    //recursively print each node of the right subtree
    inorder(node->right);


}

//this function checks if two Intervals overlap


bool Node::overlap(Interval i1, Interval i2) {
    //two Intervals overlap if the first's low is less than the
    //second's high and the second's high is less than the first's low
    if (i1.low <= i2.high && i2.low <= i1.high) {
        return true;
    }
    return false;
}

Interval *Node::search(Node *root, Interval it) {
    // Base Case, tree is empty
    if (root == NULL) return NULL;

    // If it overlaps with root
    if (overlap(*(root->it), it))
        return root->it;
    // assign root node to its left subtree if it applies to the condition
    if (root->left != nullptr && it.low <= root->left->maximum)
        //search for the Interval in the left subtree to the root
        return search(root->left, it);
    //search for the Interval in the right subtree to the root
    return search(root->right, it);
}