//
// Created by shoam on 10/29/19.
//

#ifndef SRC_NEWDNASEQUENCE_H
#define SRC_NEWDNASEQUENCE_H

#include "DnaCreatorFactory.h"
/**
            NewCreatorDnaSequence
this class create a dna sequence from a given  string,
 this class is part of Factory Method,is heiress from DnaCreatorFactory(abstract class)
 and implement the function CreateDnaSequence, that create DNA sequence from string
 * **/
class NewCreatorDnaSequence:public DnaCreatorFactory{
public:
    /*virtual*/  DnaSequence* CreateDnaSequence(VectorWords vec);//factory method

};
inline  DnaSequence* NewCreatorDnaSequence::CreateDnaSequence( VectorWords vec){
    return new DnaSequence(vec[1]);
}
#endif //SRC_NEWDNASEQUENCE_H
