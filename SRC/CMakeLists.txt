cmake_minimum_required(VERSION 3.14)
project(tempDNA)

set(CMAKE_CXX_STANDARD 14)

add_executable(tempDNA Main.cpp Model/DnaSequence.h Model/Nucleotide.h Model/NucleotideException.h View/CLI.h Controller/DnaCreatorFactory.h Controller/NewCreatorDnaSequence.h Controller/DupCreatorDnaSequence.h)