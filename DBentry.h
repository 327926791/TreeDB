/* 
 * File:   DBentry.h
 * Author: Crivils
 *
 * Created on 2015年11月8日, 下午11:23
 */

#ifndef DBENTRY_H
#define	DBENTRY_H
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>


using namespace std;


class DBentry {
 private:
     string name ;
     unsigned int IPaddress ;
     bool active ;
public:
    friend class TreeNode ;   //TreeNode member function can access DBentry's private member
    
 // constructors
     DBentry() ;
     DBentry( string _name, unsigned int _IPaddress, bool _active ) ;
 // the destructor
     ~DBentry() ;
 // sets the domain name, which we will use as a key.
     void setName( string _name ) ;
 // sets the IPaddress data.
     void setIPaddress( unsigned int _IPaddress ) ;
 // sets whether or not this entry is active.
     void setActive( bool _active ) ;
 // returns the name.
     string getName() const ;
 // returns the IPaddress data.
     unsigned int getIPaddress() const ;
 // returns whether or not this entry is active.
     bool getActive() const ;
 // prints the entry in the format
 // name : IPaddress : active followed by newline
 // active is printed as a string (active or inactive)
 friend ostream& operator<<( ostream& out, const DBentry& rhs ) ;
} ;

#endif	/* DBENTRY_H */

