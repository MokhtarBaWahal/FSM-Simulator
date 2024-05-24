// EndCommand.h
#pragma once
#include "Command.h"
#include <chrono>
#include <thread>

class EndCommand : public Command {

public:
    void execute(FSM* fsm) override {
        fsm->setRunningFlag(false);
    }
};