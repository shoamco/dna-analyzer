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
    friend std::ostream &operator<<(std::ostream &ostream, const DnaCollection dnaCollection);

    DnaRecord * getDnaRecordByName(std::string);
    DnaRecord * getDnaRecordById(size_t);

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
inline std::ostream &operator<<(std::ostream &ostream, const DnaCollection dnaCollection){
    ostream << "Dna Collection: \n";
    for(std::map<std::string,DnaRecord * >::const_iterator it = dnaCollection.map_dna_name.begin();
            it !=  dnaCollection.map_dna_name.end(); ++it)
    {
        ostream  <<  it->first<<it->second<<std::endl;
    }
    return  ostream <<std::endl;
}

#endif //TEMPDNA_DNACOLLECTION_H
