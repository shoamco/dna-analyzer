//
// Created by shoam on 11/19/19.
//

#ifndef SRC_DUPDNASEQUENCE_H
#define SRC_DUPDNASEQUENCE_H

#include "DnaCreatorFactory.h"
#include "ReaderDnaSequence.h"
/**
            DupCreatorDnaSequence
this class Duplication a dna sequence from anther dna sequence ,
 this class is part of Factory Method,is heiress from DnaCreatorFactory(abstract class)
 and implement the function CreateDnaSequence, that create DNA sequence from anther dna sequence
 * **/
class DupCreatorDnaSequence : DnaCreatorFactory {
public:
    /*virtual*/  DnaSequence *CreateDnaSequence(const DnaSequence &other);//factory method

};

inline DnaSequence *DupCreatorDnaSequence::CreateDnaSequence(const DnaSequence &other) {

    return new DnaSequence(other);

}

#endif //SRC_DUPDNASEQUENCE_H
