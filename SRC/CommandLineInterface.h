//
// Created by shoam on 10/28/19.
//

#ifndef SRC_GETCOMMANDLINE_H
#define SRC_GETCOMMANDLINE_H

#include "CommandLineInterface.h"
#include <sstream>
#include <iostream>
#include "DnaSequence.h"
#include <string>
#include <vector>
#include <map>
#include "DnaCreatorFactory.h"
#include "NewCreatorDnaSequence.h"
#include "vector"
/**
 *                   Command Line Interface
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

 * **/
class CommandLineInterface {
public:
    void CommandParser();

    void GetCommand();
    void RunAnalysisCommand();

private:
    std::string command;

};
inline void CommandLineInterface::RunAnalysisCommand(){

}
inline void CommandLineInterface::GetCommand() {
    std::string cmd;
    bool flag_quit = false;
    std::map< std::string, int> map_command;
    /** map for all command,key-name of command ,value-pointer to function command**/

//    map_command.insert( std::pair<std::string,NewCreatorDnaSequence>( std::string("new"),new NewCreatorDnaSequence));

    while (!flag_quit) {
        std::cout << "enter command ";
      std::string input_line;
        getline(std::cin,input_line);
        std::cout << "cmd:  " << cmd << std::endl;
        std::string tmp;
        std::vector<std::string> vector_words;
        std::stringstream ss(input_line); // Turn the string into a stream.
        while(getline(ss, tmp,' ')){
            if (tmp.compare(""))
                vector_words.push_back(tmp);
        }

//        std::cout <<"vector_words[0] "<<vector_words[0]<<std::endl;
//        std::cout <<"vector_words[1] "<<vector_words[1]<<std::endl;

        if (vector_words[0] == std::string("new")) {//cmd >>> new <sequence> [@<sequence_name>]
//            std::cout << "new command\n";
//            parser.add(details);
//            std::cout << vector_words;
            std::cout << vector_words[1];
            NewCreatorDnaSequence newCreatorDnaSequence;
            DnaSequence *dna = newCreatorDnaSequence.CreateDnaSequence(vector_words[1]);
            std::cout<<*dna;





        }
        if (vector_words[0] == "load") {
//            parser.load(details);
            std::cout << "load command\n";

        }
    }
}
//inline void CommandLineInterface::CommandParser() {
//    try
//    {
//        Parser parser;
//        std::string cmd, details;
//        while (cmd != "quit")
//        {
//            cout << "> cmd >>>";
//            cin >> cmd;
//            std::getline(cin, details);
//            if(cmd == "new")
//            {
//                parser.add(details);
//            }
//            if(cmd == "load")
//            {
//                parser.load(details);
//            }
//        }
//    }
//    catch (const std::exception& e)
//    {
//        e.what();
//    }
//}

//inline void add(std::string &cmdInput)
//{
//    std::string seq, name;
//    seq = parseNewSeq(cmdInput);
//    name = parseNewName(cmdInput);
//    DNA_Record record(seq, name);
//    m_DB.add_record_to_db(&record);
//    show(record);
//}
//inline void load(std::string &cmdInput)
//{
//    std::string fileName, seq, name;
//    fileName = parseLoadFileName(cmdInput);
//    seq = m_reader.readSequenceFile(fileName);
//    name = parseLoadName(cmdInput);
//    DNA_Record record(seq, name);
//    m_DB.add_record_to_db(&record);
//    show(record);
//}
//inline std::string parseNewName(std::string &cmdInput) {
//    if(cmdInput.find('@') != std::string::npos)
//    {
//        return cmdInput.substr(cmdInput.find('@') + 1, cmdInput.length());
//    }
//    else
//    {
//        std::ostringstream ss;
//        ss << ++m_newCounter;
//        return "seq" + ss.str();
//    }
//}
//inline std::stringparseNewSeq(std::string &cmdInput)
//{
//    if(cmdInput.find('@') != std::string::npos)
//    {
//        return cmdInput.substr(1, cmdInput.find('@') - 2);
//    }
//    else
//    {
//        return cmdInput.substr(1, cmdInput.length());
//    }
//}
//inline std::string Parser::parseLoadFileName(std::string &cmdInput)
//{
//    if(cmdInput.find('@') != std::string::npos)
//    {
//        return cmdInput.substr(1, cmdInput.find('@') - 2);
//    }
//    else
//    {
//        return cmdInput.substr(1, cmdInput.length());
//    }
//}
//inline std::string parseLoadName(std::string &cmdInput)
//{
//    if(cmdInput.find('@') != std::string::npos)
//    {
//        return cmdInput.substr(cmdInput.find('@') + 1, cmdInput.length());
//    }
//    else
//    {
//        parseLoadFileName(cmdInput);
//    }
//}
//inline void Parser::show(DNA_Record &record) {
//    std::cout << "[" << record.getID() << "] " << record.getName() << " " << record.getSeq() << std::endl;
//}
#endif //SRC_GETCOMMANDLINE_H
