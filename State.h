// State.h
#pragma once
#include <string>
class FSM;  // Forward declaration

class State {
public:
    virtual ~State() {}
    virtual void execute(FSM* fsm) = 0;
    virtual std::string getName() const = 0;
};
