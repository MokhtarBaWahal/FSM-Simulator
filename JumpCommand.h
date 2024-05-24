// JumpCommand.h
#pragma once
#include "Command.h"
#include "FSM.h"
#include <iostream>

class JumpCommand : public Command {
private:
    std::string targetState;

public:
    JumpCommand(const std::string& target) : targetState(target) {}

    void execute(FSM* fsm) override {
        if (fsm->canTransitionTo(targetState)) {
            fsm->changeStateDirectly(targetState);
        } else {
            std::cout << "Invalid transition to " << targetState << std::endl;
        }
    }
};

class JumpToStartCommand : public Command {
public:
    void execute(FSM* fsm) override {
        fsm->changeStateDirectly(fsm->getStartStateName());
    }
};
