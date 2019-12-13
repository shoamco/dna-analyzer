//
// Created by shoam on 12/4/19.
//

#ifndef TEMPDNA_DNACOLLECTION_H
#define TEMPDNA_DNACOLLECTION_H

#include <map>
#include "DnaRecord.h"

class DnaCollection {
public:
    static void add_dna_to_map_name(DnaRecord *dnaRecord);

    static void add_dna_to_map_id(DnaRecord *dnaRecord);

    static void add_dna_to_maps(DnaRecord *dnaRecord);

    friend std::ostream &operator<<(std::ostream &ostream, const DnaCollection dnaCollection);

    static DnaRecord *getDnaRecordByName(std::string);

    static DnaRecord *getDnaRecordById(size_t);

private:
    static std::map<std::string, DnaRecord *> map_dna_name;//todo:static
    static std::map<size_t, DnaRecord *> map_dna_id;


};



inline std::map<std::string, DnaRecord *> init_map() {
    std::map<std::string, DnaRecord *> map;

    return map;
}

inline std::map<std::string, DnaRecord *>DnaCollection::map_dna_name = init_map();
inline std::map<size_t, DnaRecord *> DnaCollection::map_dna_id;

inline DnaRecord *DnaCollection::getDnaRecordByName(std::string name) {
    return map_dna_name[name];
}

inline DnaRecord *DnaCollection::getDnaRecordById(size_t id) {
    return map_dna_id[id];
}

inline void DnaCollection::add_dna_to_maps(DnaRecord *dnaRecord) {
    DnaCollection:: add_dna_to_map_name(dnaRecord);
    DnaCollection:: add_dna_to_map_id(dnaRecord);
}

inline void DnaCollection::add_dna_to_map_name(DnaRecord *dnaRecord) {

    map_dna_name[dnaRecord->getName()] = dnaRecord;//enter dna record to map collection

}

inline void DnaCollection::add_dna_to_map_id(DnaRecord *dnaRecord) {
    map_dna_id[dnaRecord->getId()] = dnaRecord;
}

inline std::ostream &operator<<(std::ostream &ostream, const DnaCollection dnaCollection) {
    ostream << "\n*****Dna Collection: *****\n\n";
    for(std::map<std::string,DnaRecord * >::const_iterator it = dnaCollection.map_dna_name.begin();
            it !=  dnaCollection.map_dna_name.end(); ++it)
    {
        ostream  <<  it->first<<it->second<<std::endl;
    }
    return ostream << std::endl;
}

#endif //TEMPDNA_DNACOLLECTION_H
