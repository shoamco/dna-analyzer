//
// Created by shoam on 12/4/19.
//

#ifndef TEMPDNA_RUNAPPLICATION_H
#define TEMPDNA_RUNAPPLICATION_H

#include "../View/CLI.h"
//typedef std::pair<std::string, DnaCreatorFactory*> PairCommand;
typedef std::map<std::string, DnaCreatorFactory *> CommandMap;
class RunApplication{
public:
    void run();
private:
    /* map for all command,key-name of command ,value-pointer to function command*/
    static CommandMap s_map_command;
    static CLI s_cli;
};
static CommandMap init_map_command(){
    /**Initialize map of commands */
    CommandMap map;
    map["new"]=new NewCreatorDnaSequence;
    map["dup"]=new DupCreatorDnaSequence;
    return map;
}
CommandMap RunApplication::s_map_command=init_map_command();/*Initialize map of command*/
CLI RunApplication::s_cli=CLI();/*Initialize static  cli object*/

void RunApplication::run(){
    while (1) {
//        std::cout << "enter command ";
        VectorWords vectorWords=s_cli.get_input();
        std::string command=vectorWords[0];
        DnaRecord *dna=s_map_command[command]->CreateDnaSequence(vectorWords);
//        DnaSequence *dna = newCreatorDnaSequence.CreateDnaSequence(vector_words[1]);
        std::cout<<*dna;


//        std::string input_line;
//        getline(std::cin,input_line);
    }
}
#endif //TEMPDNA_RUNAPPLICATION_H
