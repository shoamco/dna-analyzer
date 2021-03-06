//
// Created by shoam on 12/4/19.
//

#ifndef TEMPDNA_RUNAPPLICATION_H
#define TEMPDNA_RUNAPPLICATION_H

#include "../View/CLI.h"
#include "../Model/DnaCollection.h"

//typedef std::pair<std::string, DnaCreatorFactory*> PairCommand;
typedef std::map<std::string, DnaCreatorFactory *> CommandMap;

class RunApplication {
public:
    void run();

private:
    /* map for all command,key-name of command ,value-pointer to function command*/
    static CommandMap s_map_command;
    static CLI s_cli;
};

static CommandMap init_map_command() {
    /**Initialize map of commands */
    CommandMap map;
    map["new"] = new NewCreatorDnaSequence;
    map["dup"] = new DupCreatorDnaSequence;
    map["dup"] = new DupCreatorDnaSequence;
    return map;
}

CommandMap RunApplication::s_map_command = init_map_command();/*Initialize map of command*/
CLI RunApplication::s_cli = CLI();/*Initialize static  cli object*/

void RunApplication::run() {
    VectorWords vectorWords;
    std::string command;
    DnaCollection dnaCollection;
    CLI cli;

    while (1) {
        vectorWords = s_cli.get_input();//get input from CLI=vectorWords[0];//name of command
        command = vectorWords[0];
        if (s_map_command.find(command) != s_map_command.end()) {
            DnaRecord *dnaRecord = s_map_command[command]->CreateDnaSequence(vectorWords);//creat dnaRecord
            std::cout << *dnaRecord;

            DnaCollection::add_dna_to_maps(dnaRecord);


            std::cout << dnaCollection;


        } else {
            cli.print_input("command not found");
        }
    }
}

#endif //TEMPDNA_RUNAPPLICATION_H
