//
// Created by shoam on 12/4/19.
//

#ifndef TEMPDNA_DNARECORD_H
#define TEMPDNA_DNARECORD_H

#include "DnaSequence.h"

class DnaRecord{
public:
    DnaRecord(DnaSequence dna, std::string name, size_t id);
    friend std::ostream &operator<<(std::ostream &ostream, const DnaRecord dnaRecord);
private:
    DnaSequence dnaSequence;
    std::string name;
    size_t id;

};
DnaRecord::DnaRecord(DnaSequence dnaSequence, std::string name, size_t id): dnaSequence(dnaSequence), name(name), id(id){}
inline std::ostream &operator<<(std::ostream &ostream, const DnaRecord dnaRecord) {
    ostream << "DnaRecord: ";
    ostream<<dnaRecord.dnaSequence;
    ostream << "name: "<<dnaRecord.name;
    ostream << "\nid: "<<dnaRecord.id;

    return ostream << std::endl;
}

#endif //TEMPDNA_DNARECORD_H
