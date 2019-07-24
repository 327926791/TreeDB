/* 
 * File:   Main.cpp
 * Author: Crivils
 *
 * Created on 2015年11月8日, 下午11:23
 */

#include <cstdlib>

#include "DBentry.h"
#include "TreeDB.h"
#include "TreeNode.h"

using namespace std;
void printAll(TreeNode *ptr) ;

int main(int argc, char** argv) {
    string line;
    string commend;
    TreeDB* treePtr;
    treePtr = new TreeDB();   // create a Tree object
    
    while (1) {
        cout << "> ";         // waiting for input
        getline(cin, line,'#');

        if (cin.eof()) {      // if nothing input but enter, then quit
            break;
        }
        stringstream ss(line);
        ss>>commend;
        
        // if insert, assign parameter to Tree object
        if (commend == "insert") {
            string _name;
            unsigned int _IPaddress;
            bool _active;
            DBentry *entryPtr ;
            
            string active;
            ss>>_name;
            ss>>_IPaddress;
            ss>>active;
            if (active == "active")
                _active = true;
            else
                _active = false;
            
            entryPtr = new DBentry(_name, _IPaddress, _active) ;
            if(treePtr->insert(entryPtr)) {             
                cout << "Success" << endl;
            }
            else {
                delete entryPtr ;    
            }
        } 
        else if (commend == "find") {
            string _name;
            //TreeNode* treeNodePtr;
            DBentry *entryPtr ;
            
            ss>>_name;
            //treeNodePtr = treePtr->find(_name);
            entryPtr = treePtr->find(_name) ;
            
            if (entryPtr == NULL)
            //if (treeNodePtr == NULL)
                cout << "Error: entry does not exist" << endl;
            else {
                string active;
                cout << *entryPtr ;
            }
        }
        else if (commend == "remove") {
            string _name;
            //TreeNode* treeNodePtr;
            DBentry *entryPtr ;
            
            ss>>_name;
            //treeNodePtr = treePtr->find(_name);
            //entryPtr = treePtr->find(_name) ;
            treePtr->remove(_name) ;
            
        }
        else if (commend == "removeall") {
            treePtr->clear() ;
            cout<<"Success"<<endl;
        } 
        else if (commend == "printall") {
            cout << *treePtr;           
        }
        else if (commend == "quit") {
            break ;
        }
        else if (commend == "printprobes") {
            string _name;
            //TreeNode* treeNodePtr;
            DBentry *entryPtr ;
            
            ss>>_name;
            //treeNodePtr = treePtr->find(_name);
            entryPtr = treePtr->find(_name) ;
            
            if (entryPtr == NULL)
            //if (treeNodePtr == NULL)
                cout << "Error: entry does not exist" << endl;
            else {
                treePtr->printProbes() ;
            }
        }
        else if (commend == "countactive") {
            treePtr->countActive() ;
        } 
        else if (commend == "updatestatus") {
            string name;
            string _active;
            bool active;
            DBentry *entryPtr;
            
            ss>>name;
            ss>>_active ;
            entryPtr = treePtr->find(name);
            if (entryPtr == NULL)
                cout << "Error: entry does not exist" << endl;
            else{
                if(_active=="active") 
                    active=true;  
                else
                    active=false;
                entryPtr->setActive(active);
                cout<<"Success"<<endl;
            }
        } 
        else {
            cout << "Error: invalid commend";
        }
    }
    treePtr->clear() ;
    delete treePtr ;
    
    return 0;
}

ostream& operator<<( ostream& out, const TreeDB& rhs ) {
    TreeNode *nodeptr ;
    
    //cout << "print...."<<endl ;
    
    nodeptr = rhs.root;
    
    if (nodeptr != NULL)
         printAll(nodeptr) ; 
    
}

void printAll(TreeNode *ptr) {
    TreeNode *left_ptr, *right_ptr ;
    
    
    left_ptr = ptr->getLeft() ;
    right_ptr = ptr->getRight() ;
    
    if (left_ptr != NULL) {
        printAll(left_ptr) ;
        cout << *(ptr->getEntry()) ;
      
    }
    else {
        cout << *(ptr->getEntry()) ;
        //cout << (ptr->getEntry())->getName() <<" : "<<ptr->getEntry()->getIPaddress <<" : "<<(ptr->genEntry())->getActive << endl ;
    }
    
    if (right_ptr != NULL) {
        //cout << "go right" << endl ;
        printAll(right_ptr) ;
        //cout << "return from right" <<endl ;
    }
}
