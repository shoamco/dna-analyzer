//
// Created by shoam on 12/4/19.
//

#ifndef TEMPDNA_DNARECORD_H
#define TEMPDNA_DNARECORD_H

#include "DnaSequence.h"


class DnaRecord{
public:
    DnaRecord(DnaSequence *dna, std::string name, size_t id);
    friend std::ostream &operator<<(std::ostream &ostream, const DnaRecord dnaRecord);
//    friend std::ostream &operator<<(std::ostream &ostream, const DnaRecord* dnaRecord);
    std::string getName() const;
    size_t  getId() const;
private:
    DnaSequence *dnaSequence;
    std::string name;
    size_t id;

};
DnaRecord::DnaRecord(DnaSequence *dnaSequence, std::string name, size_t id): dnaSequence(dnaSequence), name(name), id(id){}
inline std::ostream &operator<<(std::ostream &ostream, const DnaRecord dnaRecord) {
    ostream << "DnaRecord: \n";
    ostream<<dnaRecord.dnaSequence;
    ostream << "name: "<<dnaRecord.name;
    ostream << "\nid: "<<dnaRecord.id;

    return ostream << std::endl;
}
inline std::ostream &operator<<(std::ostream &ostream, const DnaRecord* dnaRecord){
    return operator<<(ostream,*dnaRecord);
}
inline std::string DnaRecord::getName() const{
    return name;
}
inline size_t  DnaRecord::getId() const{
    return id;

}
#endif //TEMPDNA_DNARECORD_H
