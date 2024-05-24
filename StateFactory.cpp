// StateFactory.cpp
#include "StateFactory.h"
#include "ConcreteState.h"

State* StateFactory::createState(const std::string& type) {
    if (type == "Initial") {
        return new ConcreteState("Starting FSM...");
    } else if (type == "Next") {
        return new ConcreteState("Switching to a new state...");
    }
    return nullptr;
}
