//
// Created by shoam on 11/19/19.
//

#ifndef SRC_LOADCREATORDNASEQUENCE_H
#define SRC_LOADCREATORDNASEQUENCE_H

#include "DnaCreatorFactory.h"
//#include "ReaderDnaSequence.h"
/**
            LoadCreatorDnaSequence
this class create a dna sequence from file,
 this class is part of Factory Method,is heiress from DnaCreatorFactory(abstract class)
 and implement the function CreateDnaSequence, that create DNA sequence from file
 * **/
class LoadCreatorDnaSequence : DnaCreatorFactory {
public:
    /*virtual*/  DnaSequence *CreateDnaSequence(std::string str);//factory method

};

inline DnaSequence *LoadCreatorDnaSequence::CreateDnaSequence(std::string file_name) {
//    std::string str = DnaSequence::(file_name);//read dna from file
//    DnaSequence dna_file(ReadDnaSequenceFromFile(file_name));
    return new DnaSequence(file_name);
//    return  &dna_file;
}

#endif //SRC_LOADCREATORDNASEQUENCE_H
