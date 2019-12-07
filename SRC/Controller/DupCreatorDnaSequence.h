//
// Created by shoam on 11/19/19.
//

#ifndef SRC_DUPDNASEQUENCE_H
#define SRC_DUPDNASEQUENCE_H

#include "DnaCreatorFactory.h"
//#include "ReaderDnaSequence.h"
/**
            DupCreatorDnaSequence
this class Duplication a dna sequence from anther dna sequence ,
 this class is part of Factory Method,is heiress from DnaCreatorFactory(abstract class)
 and implement the function CreateDnaSequence, that create DNA sequence from anther dna sequence
 * **/
class DupCreatorDnaSequence :public DnaCreatorFactory {
public:
    /*virtual*/  DnaRecord *CreateDnaSequence( VectorWords vec);//factory method

};

inline  DnaRecord* DupCreatorDnaSequence::CreateDnaSequence( VectorWords vec){

    std::string name=vec[2];
//    std::string name=vec[3];

    return  new DnaRecord( new  DnaSequence(vec[1]),name,2);//todo change to return new DnaSequence(other);

}
#endif //SRC_DUPDNASEQUENCE_H
