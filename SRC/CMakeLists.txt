cmake_minimum_required(VERSION 3.14)
project(SRC)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(SRC
        DnaSequence.h
        Main.cpp
        Nucleotide.h
        NucleotideException.h
        TestDnaSequence.cpp
        TestDnaSequence.h
       )
