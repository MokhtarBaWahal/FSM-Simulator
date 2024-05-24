// ConcreteState.cpp
#include "ConcreteState.h"
#include "StateFactory.h"
#include "FSM.h"
#include <iostream>

void ConcreteState::execute(FSM* fsm) {
    for (auto& cmd : commands) {
        cmd->execute(fsm);
    }

}
