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
#include <iostream>
#include <sstream>
#include <string>

class DnaCreatorFactory{
public:
//     DnaCreatorFactory();
    virtual  DnaRecord *CreateDnaSequence( VectorWords vec)=0;//factory method
    std::string getDefaultName();
//    virtual ~DnaCreatorFactory(){}
//private:
    static size_t s_id;

};
inline std::string  DnaCreatorFactory::getDefaultName(){
    std::ostringstream ostr;
    ostr << DnaCreatorFactory::s_id ;

    std::string id = ostr.str();
    return  std::string("str")+id;
}

size_t DnaCreatorFactory::s_id=0;
#endif //SRC_DNACREATORFACTORY_H
