//
// Created by shoam on 10/29/19.
//

#ifndef SRC_NEWDNASEQUENCE_H
#define SRC_NEWDNASEQUENCE_H

#include "DnaCreatorFactory.h"

class NewCreatorDnaSequence:DnaCreatorFactory{
public:
    /*virtual*/  DnaSequence* CreateDnaSequence( std::string str);//factory method

};
inline  DnaSequence* NewCreatorDnaSequence::CreateDnaSequence( std::string str){
    return new DnaSequence(str);
}
#endif //SRC_NEWDNASEQUENCE_H
