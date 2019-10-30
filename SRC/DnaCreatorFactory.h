//
// Created by shoam on 10/29/19.
//

#ifndef SRC_DNACREATORFACTORY_H
#define SRC_DNACREATORFACTORY_H
#include "DnaSequence.h"

/***
 this class is part of  implement Factory Method,

 this class is abstract class for a Factory
 all class that want to creat a dna sequence need to inherited from this class
 and will need to implement\redefine the Factory Method(CreateDnaSequence)
  in there way-Flexible
 * **/
class DnaCreatorFactory{
    virtual  DnaSequence* CreateDnaSequence( std::string str)=0;//factory method

};

#endif //SRC_DNACREATORFACTORY_H
