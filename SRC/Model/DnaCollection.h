//
// Created by shoam on 12/4/19.
//

#ifndef TEMPDNA_DNACOLLECTION_H
#define TEMPDNA_DNACOLLECTION_H

#include <map>
#include "DnaRecord.h"

class DnaCollection {
public:
    void add_dna_to_map_name(DnaRecord *dnaRecord);

    void add_dna_to_map_id(DnaRecord *dnaRecord);

    void add_dna_to_maps(DnaRecord *dnaRecord);

private:
    std::map<std::string, DnaRecord *> map_dna_name;
    std::map<size_t, DnaRecord *> map_dna_id;


};
//dnaCollection.map_dna_name[dnaRecord->getName()]=dnaRecord;//enter dna record to map collection
//dnaCollection.map_dna_id[dnaRecord->getId()]=dnaRecord;

void DnaCollection::add_dna_to_maps(DnaRecord *dnaRecord) {
    add_dna_to_map_name(dnaRecord);
    add_dna_to_map_id(dnaRecord);
}

void DnaCollection::add_dna_to_map_name(DnaRecord *dnaRecord) {
    map_dna_name[dnaRecord->getName()] = dnaRecord;//enter dna record to map collection
}

void DnaCollection::add_dna_to_map_id(DnaRecord *dnaRecord) {
    map_dna_id[dnaRecord->getId()] = dnaRecord;
}

#endif //TEMPDNA_DNACOLLECTION_H
