

#include <gtest/gtest.h>

#include "TestDnaSequence.h"

/*

g++ -ansi -pedantic -Wall -Wconversion  Main.cpp DnaSequence.h Nucleotide.h TestDnaSequence.cpp TestDnaSequence.h DnaCreatorFactory.h NewCreatorDnaSequence.h CommandLine.h -lgtest -lgtest_main -pthread -o test


 */



int main(int argc, char *argv[]) {
    test_dna();
    testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}