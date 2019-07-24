/* 
 * File:   TreeDB.h
 * Author: Crivils
 *
 * Created on 2015年11月8日, 下午11:24
 */

#ifndef TREEDB_H
#define	TREEDB_H
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include "DBentry.h"
#include "TreeNode.h"
using namespace std;

class TreeDB {
 private:

     TreeNode* root ;
     int probesCount ;
     int activeProbes ;
 // You will need to add additional private functions
 
 public:

 // the default constructor, creates an empty database.
 TreeDB() ;
 // the destructor, deletes all the entries in the database.
 ~TreeDB() ;
 // inserts the entry pointed to by newEntry into the database.
 // If an entry with the same key as newEntry's exists
 // in the database, it returns false. Otherwise, it returns true.
 bool insert(DBentry* newEntry) ;
 // searches the database for an entry with a key equal to name.
 // If the entry is found, a pointer to it is returned.
 // If the entry is not found, the NULL pointer is returned.
 // Also sets probesCount
 DBentry* find( string name ) ;
 // deletes the entry with the specified name (key) from the database.
 // If the entry was indeed in the database, it returns true.
 // Returns false otherwise.
 // See Section 6 for the *required* removal method so you match
 // exercise’s output.
 bool remove( string name ) ;
 // deletes all the entries in the database.
 void clear() ;
 // prints the number of probes stored in probesCount
 void printProbes() const ;
 // computes and prints out the total number of active entries
 // in the database (i.e. entries with active==true).
 void countActive () const ;
 // Prints the entire tree, in ascending order of key/name
 // The entries are printed one per line, using the
 // operator<< for DBentry.
 
 void 
 friend ostream& operator<<( ostream& out, const TreeDB& rhs ) ;
} ;
// You *may* choose to implement the function below to help print the
// tree. You do not have to implement this function if you do not wish to.
ostream& operator<<( ostream& out, TreeNode* rhs ) ;

#endif	/* TREEDB_H */

