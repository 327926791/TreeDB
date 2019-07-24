/* 
 * File:   TreeNode.h
 * Author: Crivils
 *
 * Created on 2015年11月8日, 下午11:23
 */

#ifndef TREENODE_H
#define	TREENODE_H

#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include "DBentry.h"



using namespace std;

class TreeNode {
private:
    DBentry* entryPtr;
    TreeNode* left;
    TreeNode* right;

    //bool insert(string _name, unsigned int _IPaddress, bool _active);
    bool insert(DBentry *ptr) ;
    DBentry* search(string name, int & probesCount);
    //void deleteN(DBentry* _entryPtr, TreeNode* & pp);
    void deleteAll();
    //TreeNode* min();
    void countActive(int & num) ;

public:
    friend class TreeDB ; //let TreeDB's member function to access TreeNode's private member

    // A useful constructor
    TreeNode(DBentry* _entryPtr);
    // the destructor
    ~TreeNode();
    // sets the left child of the TreeNode.
    void setLeft(TreeNode* newLeft);

    // sets the right child of the TreeNode
    void setRight(TreeNode* newRight);
    // gets the left child of the TreeNode.
    TreeNode* getLeft() const;
    // gets the right child of the TreeNode
    TreeNode* getRight() const;
    // returns a pointer to the to the DBentry the TreeNode contains.
    DBentry* getEntry() const;
    
    friend ostream& operator << (ostream& out, TreeNode *rhs) ;
};

#endif	/* TREENODE_H */

