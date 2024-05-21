//
// Created by Mokhtar on 5/19/2024.
//

#ifndef FSM_FSM_H
#define FSM_FSM_H
#include "iostream"
#include "map"
using namespace std;

class FSM
{
    string name;
    map<string, int> variables;
    map<string, State *> states;
    State *currentState;

public:
    FSM(string name);
    void addVariable(string name, int value);
    void addState(State *state);
    void setState(string stateName);
    void handleInput(string input);
};

#endif // FSM_FSM_H
