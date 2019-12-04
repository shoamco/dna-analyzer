#include <iostream>
#include "Model/DnaRecord.h"
#include "Model/DnaSequence.h"
#include "View/CLI.h"
#include "Controller/RunApplication.h"
int main() {
//    DnaSequence dnaSequence("ATAAT");
//    DnaRecord dnaRecord(dnaSequence, "shoam", 9383747);
//    std::cout<<dnaRecord;
RunApplication runApplication;
runApplication.run();

    return 0;
}