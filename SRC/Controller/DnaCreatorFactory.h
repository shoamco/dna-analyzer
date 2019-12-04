//
// Created by shoam on 10/29/19.
//

#ifndef SRC_DNACREATORFACTORY_H
#define SRC_DNACREATORFACTORY_H
#include "../Model/DnaSequence.h"
#include <vector>
typedef std::vector<std::string> VectorWords;


/***
 this class is part of  implement Factory Method,

 this class is abstract class for a Factory
 all class that want to creat a dna sequence need to inherited from this class
 and will need to implement\redefine the Factory Method(CreateDnaSequence)
  in there way-Flexible
 * **/

class DnaCreatorFactory{
public:
//     DnaCreatorFactory();
    virtual  DnaSequence* CreateDnaSequence( VectorWords vec)=0;//factory method
//    virtual ~DnaCreatorFactory(){}

};

#endif //SRC_DNACREATORFACTORY_H
