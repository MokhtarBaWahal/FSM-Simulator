#pragma once
#include "Command.h"
#include <iostream>
#include <string>
#include <sstream>
#include <string>

class PrintCommand : public Command {
private:
    std::string message;
public:
    PrintCommand(const std::string& msg) : message(msg) {}
    void execute(FSM* fsm) override {
        std::cout << message;
        std::istringstream iss(message);
        std::string firstWord;
        iss >> firstWord; // This extracts the first word based on whitespace
        if(firstWord=="Final"){
            std::string secondWord;
            iss >> secondWord;
            std::cout<<std::to_string(fsm->getParameters().get<int>(secondWord))<<std::endl;
        }

    }
};