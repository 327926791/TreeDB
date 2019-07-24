#include "DBentry.h"
#include "TreeDB.h"
#include "TreeNode.h"

void TreeNode::setLeft(TreeNode* newLeft) {
    left = newLeft;
}

void TreeNode::setRight(TreeNode* newRight) {
    right = newRight;
}

TreeNode* TreeNode::getLeft() const {
    return left;
}

TreeNode* TreeNode::getRight() const {
    return right;
}

DBentry* TreeNode::getEntry() const {
    return entryPtr;
}

TreeNode::TreeNode(DBentry* _entryPtr) {
    entryPtr = _entryPtr;
    left = NULL;
    right = NULL;
}

TreeNode::~TreeNode() {
    delete entryPtr ;
}

//private member functions
DBentry* TreeNode::search(string name, int & probesCount) {

    probesCount++;
    if (entryPtr->name == name)
        return this->entryPtr;
    if (name < entryPtr->name) {
        if (left == NULL)
            return NULL;
        return left->search(name,probesCount);
    } else {
        if (right == NULL)
            return NULL;
        return right->search(name, probesCount);
    }
}

bool TreeNode::insert(DBentry *_entryPtr) {
//bool TreeNode::insert(string _name, unsigned int _IPaddress, bool _active) {
  //  DBentry* _entryPtr;
  //  _entryPtr = new DBentry(_name, _IPaddress, _active);
      
    if (entryPtr->name ==_entryPtr->name) {
        cout << "Error: entry already exists" << endl;
        //delete _entryPtr;
        return false;
    }
    if (_entryPtr->name < entryPtr->name) {
        if (left == NULL) {
            left = new TreeNode(_entryPtr);
            return true;
        } else
            return left->insert(_entryPtr);
    }
    if (_entryPtr->name > entryPtr->name) {
        if (right == NULL) {
            right = new TreeNode(_entryPtr);
            return true;
        } else
            return right->insert(_entryPtr);
    }
}

/*
void TreeNode::deleteN(DBentry* _entryPtr, TreeNode*& pp) {

}
*/

void TreeNode::deleteAll() {   
    //cout << entryPtr->name << endl ;
    
    if (left == NULL && right == NULL)
        return ;
    
    if (left != NULL) {
        //cout << "go left"<< endl ;
        left->deleteAll() ;
        //cout << "return from left then delete: "<<left->entryPtr->name<<endl ;
        delete left ;
        left = NULL ;
    }
    if (right != NULL) {
        //cout << "go right" << endl ;
        right->deleteAll() ;
        //cout << "delete: "<<right->entryPtr->name<<endl ;
        //delete right->entryPtr ;
        delete right ;
        right = NULL ;
    }
}

/*
TreeNode* TreeNode::min(){
    if(left==NULL)
        return this;
    return left->min();
}
*/

void TreeNode::countActive(int & num) {

    if (left != NULL) {
        left->countActive(num) ;
        if (entryPtr->getActive())
            num++ ;
    }
    else {
        if (entryPtr->getActive())
            num++ ;
        return ;
    }
    
    if (right != NULL)
        right->countActive(num) ;
    else
        return ;       
}