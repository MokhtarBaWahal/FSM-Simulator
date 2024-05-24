// ConcreteState.h
#pragma once
#include "State.h"
#include <vector>
#include <string>
#include <memory>
#include "Command.h"

class ConcreteState : public State {
private:
    std::string name;
    std::vector<std::unique_ptr<Command>> commands;


public:
    ConcreteState(const std::string& name) : name(name) {}  // Constructor takes a std::string.
    void addCommand(Command* command) {
        commands.emplace_back(command);
    }
    std::string getName() const override {
        return name;
    }

    void execute(FSM* fsm) override;
};
