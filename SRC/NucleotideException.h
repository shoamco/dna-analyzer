//
// Created by shoam on 10/3/19.
//

#ifndef SIMPLE_DNA_SEQUENCE_SHOAMCO_NUCLEOTIDEXCEPTION_H
#define SIMPLE_DNA_SEQUENCE_SHOAMCO_NUCLEOTIDEXCEPTION_H

class NucleotideException
{
public:
    void invalidNucleotide() const throw(const char*)
    {
        throw "invalid nucleotide";
    }
} ;
#endif //SIMPLE_DNA_SEQUENCE_SHOAMCO_NUCLEOTIDEXCEPTION_H
