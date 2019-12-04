

#ifndef SIMPLE_DNA_SEQUENCE_SHOAMCO_NUCLEOTID_H
#define SIMPLE_DNA_SEQUENCE_SHOAMCO_NUCLEOTID_H

#include "NucleotideException.h"
#include <iostream>

class Nucleotide {//todo:nested class
public:
    Nucleotide();

    Nucleotide(const char c);

    char GetNucleotide();

    Nucleotide &operator=(const Nucleotide &other);

    Nucleotide &operator=(const char c);

    friend std::ostream &operator<<(std::ostream &os, const Nucleotide nucleotide);


private:
    char m_nucleotide;


};


inline bool isNucleotideValid(const char c) {
    return !(c != 'A' && c != 'G' && c != 'C' && c != 'T' && c != 'a' && c != 'g' && c != 'c' && c != 't') ? true
                                                                                                           : false;
}

inline Nucleotide &Nucleotide::operator=(const char c) {
    if (!isNucleotideValid(c)) {
        throw "invalid nucleotide";
    } else {
        m_nucleotide = c;


    }
    return *this;
}

inline Nucleotide &Nucleotide::operator=(const Nucleotide &other) {
    if (this != &other) {
        m_nucleotide = other.m_nucleotide;

    }
    return *this;
}

inline Nucleotide::Nucleotide(const char c) {
    if (!isNucleotideValid(c)) {
        throw "invalid nucleotide";
    } else {
        m_nucleotide = c;

    }


}

inline char Nucleotide::GetNucleotide() {
    return m_nucleotide;
}

inline Nucleotide::Nucleotide() {

}

inline std::ostream &operator<<(std::ostream &ostream, const Nucleotide nucleotide) {
    return ostream << nucleotide.m_nucleotide << std::endl;
}
//bool operator==(const Nucleotide &nucleotide1, const Nucleotide &nucleotide2);
//
//bool operator!=(const Nucleotide &nucleotide1, const Nucleotide &nucleotide2);
#endif //SIMPLE_DNA_SEQUENCE_SHOAMCO_NUCLEOTID_H
