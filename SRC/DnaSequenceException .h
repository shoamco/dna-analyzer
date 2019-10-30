//
// Created by shoam on 10/29/19.
//

#ifndef SRC_DNASEQUENCEEXCEPTION_H
#define SRC_DNASEQUENCEEXCEPTION_H


#include <iostream>
class DNAException : public std::runtime_error
{
public:
    DNAException(const std::string& message) : std::runtime_error(message) {}
};
class ValidationDNAException : public DNAException
{
public:
    ValidationDNAException() : DNAException("The sequence is invalid!") {}
};
class IndexDNAException : public DNAException
{
public:
    IndexDNAException() : DNAException("The index out of rang.") {}
};
class ValidationNucleotideException : public DNAException
{
public:
    ValidationNucleotideException() : DNAException("The nucleotide is invalid!") {}
};
#endif //SRC_DNASEQUENCEEXCEPTION_H
