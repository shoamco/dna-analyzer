//
// Created by shoam on 11/26/19.
//

#ifndef DNA_ANALYZER_DESIGN_SHOAMCO_DNARECORDS_H
#define DNA_ANALYZER_DESIGN_SHOAMCO_DNARECORDS_H

#include <string>
#include <iostream>
#include "DnaSequence.h"

class DnaRecords {
public:
    DnaRecords(DnaSequence *dna_sequence, int dna_id, std::string dna_name);


public://todo private  and get/set
    DnaSequence *dna_sequence;
    int dna_id;
    std::string dna_name;


};

inline DnaRecords::DnaRecords(DnaSequence *dna_sequence1,int dna_id1, std::string dna_name1):

dna_sequence (dna_sequence1), dna_id(dna_id1), dna_name(dna_name1) {}
#endif //DNA_ANALYZER_DESIGN_SHOAMCO_DNARECORDS_H
