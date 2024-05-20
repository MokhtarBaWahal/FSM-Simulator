//
// Created by Mokhtar on 5/19/2024.
//

#ifndef FSM_FSM_H
#define FSM_FSM_H
#include "iostream"
#include "map"
using namespace std;

class FSM {
    std::string name;
    std::map<std::string, int> variables;
    std::map<std::string, State*> states;
    State* currentState;

public:
    FSM(std::string name);
    void addVariable(std::string name, int value);
    void addState(State* state);
    void setState(std::string stateName);
    void handleInput(std::string input);
};



#endif //FSM_FSM_H
