
#ifndef SIMPLE_DNA_SEQUENCE_SHOAMCO_DNASEQUENCE_H
#define SIMPLE_DNA_SEQUENCE_SHOAMCO_DNASEQUENCE_H

#include "Nucleotide.h"
#include <string>
#include <iostream>
#include <algorithm>
#include <fstream>

#include <streambuf>

class DnaSequence {
public:
    //todo:CTOR of Nucleotide
    DnaSequence(const std::string str);

    DnaSequence(const DnaSequence &other);

    ~DnaSequence();

    Nucleotide *GetDnaSequence() const;

    friend std::ostream &operator<<(std::ostream &os, const DnaSequence dnaSequence);

    DnaSequence &operator=(const DnaSequence &other);

    DnaSequence &operator=(const std::string str);

    const char operator[](size_t index) const;

    Nucleotide &operator[](size_t index);//

    size_t FindSubsequence(const DnaSequence &subsequence) const;

    void FindAllSubsequence(const DnaSequence &subsequence, size_t *list_subsequence) const;

    size_t CountOccurrencesSubsequence(const DnaSequence &subsequence) const;
    void FindConsensusSequences(size_t *list_consensus_sequences) const;

    DnaSequence getSlice(size_t start, size_t end) const;

    DnaSequence getPairing() const;

    size_t GetSizeDnaSequence() const;


private:

    Nucleotide *m_dna_sequence;
    size_t m_size;

};

inline char complementary(const char c){
    char ans;

    switch(c) {
        case 'a' : ans ='t';break;
        case 'A' : ans ='T';break;
        case 't' : ans ='a';break;
        case 'T' : ans ='A';break;
        case 'G' : ans ='C';break;
        case 'g' : ans ='c';break;
        case 'c' : ans ='g';break;
        case 'C' : ans ='G';break;

    }
    return ans;
}


inline const char DnaSequence::operator[](size_t index) const {

    return m_dna_sequence[index].GetNucleotide();

}

inline Nucleotide &DnaSequence::operator[](size_t index) {
    if (index >= m_size || index < 0) {
        throw "invalid index";
    }
    return m_dna_sequence[index];
}

inline DnaSequence::DnaSequence(const DnaSequence &other) {
    m_size = other.m_size;
    m_dna_sequence = new Nucleotide[m_size];
    for (size_t i = 0; i < other.m_size; ++i) {

        m_dna_sequence[i] = other.m_dna_sequence[i];
    }

}

inline DnaSequence::DnaSequence(std::string str) {
    m_size = str.length();
    m_dna_sequence = new Nucleotide[m_size];

    for (size_t i = 0; i < m_size; ++i) {

        try {
            m_dna_sequence[i] = Nucleotide(str[i]);
        }
        catch (char const *e) {
            delete[]  m_dna_sequence;
            throw;
        }


    }


}


inline size_t DnaSequence::GetSizeDnaSequence() const {
    return m_size;
}

inline Nucleotide *DnaSequence::GetDnaSequence() const {
    return m_dna_sequence;
}

inline std::ostream &operator<<(std::ostream &ostream, const DnaSequence dnaSequence) {
    ostream << "DnaRecord-Sequence: ";
    for (size_t i = 0; i < dnaSequence.m_size; ++i)
        ostream << dnaSequence.m_dna_sequence[i].GetNucleotide();
    return ostream << std::endl;
}

inline bool operator==(const DnaSequence &dna1, const DnaSequence &dna2){
    bool ans = true;
    if (dna1.GetSizeDnaSequence() != dna2.GetSizeDnaSequence()) {
        ans = false;
    } else {
        for (size_t i = 0; i < dna1.GetSizeDnaSequence(); ++i) {
            if (dna1.GetDnaSequence()[i].GetNucleotide() != dna2.GetDnaSequence()[i].GetNucleotide()) {
                ans = false;
                break;
            }
        }
    }
    return ans;

}
//
inline bool operator!=(const DnaSequence &dna1, const DnaSequence &dna2){
    bool ans = false;
    if (dna1.GetSizeDnaSequence() != dna2.GetSizeDnaSequence()) {
        ans = true;
    } else {
        for (size_t i = 0; i < dna1.GetSizeDnaSequence(); ++i) {
            if (dna1.GetDnaSequence()[i].GetNucleotide() != dna2.GetDnaSequence()[i].GetNucleotide()) {
                ans = true;
                break;
            }
        }
    }
    return ans;

}

inline DnaSequence::~DnaSequence()//todo:free all
{

    delete[]  m_dna_sequence;

}

inline DnaSequence DnaSequence::getSlice(size_t start, size_t end) const {

    if (start > end || start < 0 || end > m_size) {
        throw "invalid index";
    } else {
        std::string temp_string;
        for (size_t i = start; i < end; ++i) {
            temp_string += m_dna_sequence[i].GetNucleotide();
        }
        DnaSequence slice(temp_string);
        return slice;
    }
}

inline size_t DnaSequence::FindSubsequence(const DnaSequence &subsequence) const {

    size_t M = subsequence.m_size;
    size_t N = m_size;

    /* A loop to slide pat[] one by one */
    for (size_t i = 0; i <= N - M; ++i) {
        size_t j;

        /* For current index i, check for pattern match */
        for (j = 0; j < M; ++j)
            if (m_dna_sequence[i + j].GetNucleotide() != subsequence.m_dna_sequence[j].GetNucleotide()) {

                break;
            }

        if (j == M) {

            return i;
        }
    }

    return -1;

}

inline size_t DnaSequence::CountOccurrencesSubsequence(const DnaSequence &subsequence) const {
    size_t M = subsequence.m_size;
    size_t N = m_size;
    size_t count = 0;
    /* A loop to slide pat[] one by one */
    for (size_t i = 0; i <= N - M; ++i) {
        size_t j;

        /* For current index i, check for pattern match */
        for (j = 0; j < M; ++j)
            if (m_dna_sequence[i + j].GetNucleotide() != subsequence.m_dna_sequence[j].GetNucleotide()) {

                break;
            }

        if (j == M) {

            ++count;
        }
    }

    return count;


}

inline void DnaSequence::FindAllSubsequence(const DnaSequence &subsequence, size_t *list_subsequence) const {
    size_t M = subsequence.m_size;
    size_t N = m_size;
    size_t k = 0;
    /* A loop to slide pat[] one by one */
    for (size_t i = 0; i <= N - M; ++i) {
        size_t j;

        /* For current index i, check for pattern match */
        for (j = 0; j < M; ++j)
            if (m_dna_sequence[i + j].GetNucleotide() != subsequence.m_dna_sequence[j].GetNucleotide()) {

                break;
            }

        if (j == M) {

            list_subsequence[k++] = i;
        }
    }

}
inline void DnaSequence::FindConsensusSequences(size_t *list_consensus_sequences) const{

}



inline DnaSequence DnaSequence::getPairing() const {
    std::string temp_string;
    for (size_t i = 0; i < m_size; ++i) {
        temp_string += complementary(m_dna_sequence[i].GetNucleotide());
    }
    std::reverse(temp_string.begin(), temp_string.end());
    DnaSequence pairing(temp_string);
    return pairing;
}





inline DnaSequence &DnaSequence::operator=(const DnaSequence &other) {
    if (this != &other) {
        delete[] this->m_dna_sequence;
        m_size = other.m_size;
        m_dna_sequence = new Nucleotide[m_size];
        for (size_t i = 0; i < other.m_size; ++i) {

            m_dna_sequence[i] = other.m_dna_sequence[i];
        }

    }
    return *this;
}
inline DnaSequence &DnaSequence::operator=(const std::string str) {

    delete[] this->m_dna_sequence;
    m_size = str.length();
    m_dna_sequence = new Nucleotide[m_size];
    for (size_t i = 0; i < m_size; ++i) {
        if (!isNucleotideValid(str[i])) {
            delete[]  m_dna_sequence;
            throw "invalid nucleotide";
//            }

            m_dna_sequence[i] = str[i];
        }


        return *this;
    }
}



inline std::string ReadDnaSequenceFromFile(const char *file_name) {
    std::string line, str_file;
    std::ifstream myfile(file_name);
    if (myfile.is_open()) {
        while (getline(myfile, line)) {
            str_file += line;
        }
        myfile.close();
    }
    else
        throw "Unable to open file";

    return str_file;
}
inline void WriteDnaSequenceToFile(const char *file_name,std::string input) {

    std::ofstream  myfile(file_name);
    if (myfile.is_open())
    {
        myfile << input;

        myfile.close();
    }
    else throw "Unable to open file";

}
#endif //SIMPLE_DNA_SEQUENCE_SHOAMCO_DNASEQUENCE_H
