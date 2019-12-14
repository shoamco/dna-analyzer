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
    /*virtual*/  DnaRecord *CreateDnaSequence(VectorWords vec);//factory method

};
inline  DnaRecord* NewCreatorDnaSequence::CreateDnaSequence( VectorWords vec){
    //name of dna ,if not given a name ,enter default name (str+id)



    std::string name= vec.size()>2 ? vec[2]:getDefaultName() ;


    return  new DnaRecord(new DnaSequence(vec[1]) ,name,DnaCreatorFactory::s_id++);

}
#endif //SRC_NEWDNASEQUENCE_H
