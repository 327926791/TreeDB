#include "DBentry.h"
#include "TreeDB.h"
#include "TreeNode.h"

void TreeDB::clear() {
    TreeNode* treeNodePtr = root;
    if (treeNodePtr != NULL) {
        treeNodePtr->deleteAll();
         delete treeNodePtr ;
    }
    root = NULL ;
    activeProbes = 0 ;
    probesCount = 0 ;
}

void TreeDB::countActive() const {
    int activeProbes = 0 ;
    
    if (root != NULL)
        root->countActive(activeProbes) ;
    
    cout << activeProbes<< endl ;    
}

void TreeDB::printProbes() const {
    cout << probesCount << endl;
}

bool TreeDB::insert(DBentry *ptr) {
    
    if (root == NULL) { 
        root = new TreeNode(ptr);
        if (ptr->getActive())
          activeProbes ++ ;
        return true;
    } 
    else {
        if (root->insert(ptr) ) {
          if (ptr->getActive())
              activeProbes ++ ;
          return true ;
        }
        else
            return false ;
    }   
}

bool TreeDB::remove(string name) {

}

TreeDB::~TreeDB() {
    delete root;
}

TreeDB::TreeDB() {
    root = NULL;
    probesCount = 0;
    activeProbes = 0 ;
}

DBentry* TreeDB::find(string name) {
    probesCount = 0;
    
    if (root == NULL) {
        return NULL;
    }
    return root->search(name, probesCount);
}

/*void TreeDB::addProbes(){
    probesCount++;
}

void TreeDB::deleteProbes(){
    probesCount--;
}*/

