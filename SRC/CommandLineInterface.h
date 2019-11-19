//
// Created by shoam on 10/28/19.
//

#ifndef SRC_GETCOMMANDLINE_H
#define SRC_GETCOMMANDLINE_H

#include "CommandLine.h"
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

 * **/
class CommandLine {
public:
    void CommandParser();

    void GetCommand();
    void RunAnalysisCommand();

private:
    std::string command;

};
inline void CommandLine::RunAnalysisCommand(){

}
inline void CommandLine::GetCommand() {
    std::string cmd;
    bool flag_quit = false;
    std::map< std::string, int> map_command;
    map_command.insert ( std::pair<std::string,int>( std::string("new"),100) );
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

        std::cout <<"vector_words[0] "<<vector_words[0]<<std::endl;
        std::cout <<"vector_words[1] "<<vector_words[1]<<std::endl;

        if (vector_words[0] == std::string("new")) {//cmd >>> new <sequence> [@<sequence_name>]
            std::cout << "new command\n";
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
//inline void CommandLine::CommandParser() {
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
