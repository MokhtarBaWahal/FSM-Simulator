// Command.h
#include "FSM.h"
#pragma once

class Command {
public:
    virtual ~Command() {}
    virtual void execute(FSM* fsm) = 0;
};


