//
// Created by shoam on 11/19/19.
//

#ifndef SRC_DUPDNASEQUENCE_H
#define SRC_DUPDNASEQUENCE_H

#include "../Model/DnaCollection.h"

#include "DnaCreatorFactory.h"
//#include "ReaderDnaSequence.h"
/**
            DupCreatorDnaSequence
this class Duplication a dna sequence from anther dna sequence ,
 this class is part of Factory Method,is heiress from DnaCreatorFactory(abstract class)
 and implement the function CreateDnaSequence, that create DNA sequence from anther dna sequence
 * **/
class DupCreatorDnaSequence : public DnaCreatorFactory {
public:
    /*virtual*/  DnaRecord *CreateDnaSequence(VectorWords vec);//factory method

};

inline DnaRecord *DupCreatorDnaSequence::CreateDnaSequence(VectorWords vec) {
    // dup <seq> [@<new_seq_name>]
    //dup #22
    std::cout << "dna id" << vec[1] << std::endl;
    std::string name = vec[2];
    std::stringstream ss;
    ss << (vec[1]);
    int id;
    ss >> id;


    DnaRecord *dnaRecord = DnaCollection::getDnaRecordById(id);
    return new DnaRecord(new DnaSequence(*(dnaRecord->getDnaSequence())), name, DnaCreatorFactory::s_id++);
    //todo change to return new DnaSequence(other);

}

#endif //SRC_DUPDNASEQUENCE_H
