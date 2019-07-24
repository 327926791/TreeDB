#include "DBentry.h"
#include <stdio.h>
#include <stdlib.h>


bool DBentry::getActive() const{
    return active;
}

unsigned int DBentry ::getIPaddress() const{
    return IPaddress;
}

string DBentry::getName() const{
    return name;
}

void DBentry::setActive(bool _active){
    active=_active;
}
    
void DBentry::setIPaddress(unsigned int _IPaddress){
    IPaddress=_IPaddress;
}

void DBentry::setName(string _name){
    name=_name;
}

DBentry::DBentry(){
    
}

DBentry::DBentry(string _name, unsigned int _IPaddress, bool _active){
    name = _name ;
    IPaddress = _IPaddress ;
    active = _active ; 
}


DBentry::~DBentry(){
    
}

ostream& operator<<( ostream& out, const DBentry& rhs ) {
    char ss[50] ;
    string status ;
    
    sprintf(ss,"%d", rhs.IPaddress) ;
    
    if (rhs.active == true) 
        status = "active" ;
    else
        status = "inactive" ;
    
    cout << rhs.name << " : " << ss << " : " << status << endl ;
}