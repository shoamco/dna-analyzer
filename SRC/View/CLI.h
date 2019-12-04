//
// Created by shoam on 12/4/19.
//

#ifndef TEMPDNA_CLI_H
#define TEMPDNA_CLI_H

#include "../Controller/DnaCreatorFactory.h"
#include "../Controller/NewCreatorDnaSequence.h"
#include "../Controller/DupCreatorDnaSequence.h"


/**
           Command Line Interface
 The command line interface allows interaction with the user.Throughout that interface,
the user can enter their input and see the application's output.

 The prompt of the CLI is :
 > cmd >>>
 Sequence Creation Commands:
 new:
    > cmd >>> new <sequence> [@<sequence_name>]
 load:
    > cmd >>> load <file_name> [@<sequence_name>]
 dup:
    > cmd >>> dup <seq> [@<new_seq_name>]
 Sequence Manipulation Commands:
 replace:
    > cmd >>> replace <seq> <index> <new_letter> [:[@<new_seq_name>|@@]]
 concat:
     > cmd >>> concat <seq_1> <seq_2> [: [@<new_seq_name>|@@]]
 pair:
    > cmd >>> pair <seq> [: [@<new_seq_name>|@@]]
 Sequence Management Commands:
 rename:
     > cmd >>> rename <seq> @<new_name>
 reenum
    > cmd >>> reenum
 save:
    > cmd >>> save <seq> [<filename>]
 del:
    > cmd >>> del <seq>
 Sequence Analysis Commands:
 len:
    > cmd >>> len <seq_id>
 find:
    > cmd >>> find <seq_to_find_in> <seq_to_be_found>
    > cmd >>> find <seq> <expressed_sub_seq>
 count:
    > cmd >>> count <seq> <expressed_sub_seq>
    > cmd >>> count <seq_to_find_in> <seq_to_be_found>
 findall:
    > cmd >>> findall <seq> <expressed_sub_seq>
    > cmd >>> findall <seq_to_find_in> <seq_to_be_found>
Control Commands:
 help:
    > cmd >>> help [<command>]
 list:
    > cmd >>> list
 show:
    > cmd >>>show `<seq>` [<num_chars>]
 quit:
    > cmd >>> quit
 Command Results Labels:
 Show Labels:
    cmd >>> labels
    ....

 * */
#include <map>
#include <vector>
#include "Parser.h"
#include <sstream>
#include <iostream>

//typedef std::pair<std::string, DnaCreatorFactory*> PairCommand;
typedef std::map<std::string, DnaCreatorFactory *> CommandMap;
typedef std::vector<std::string> VectorWords;

class CLI {
public:
    void print_input(std::string);

    VectorWords get_input();


};

VectorWords CLI::get_input() {
    std::cout << "enter command ";
    std::string input_line;
    getline(std::cin,input_line);

    std::string tmp;
    std::vector<std::string> vector_words;
    std::stringstream ss(input_line); // Turn the string into a stream.
    while(getline(ss, tmp,' ')){
        if (tmp.compare(""))
            vector_words.push_back(tmp);
    }
    return vector_words;

}

#endif //TEMPDNA_CLI_H
