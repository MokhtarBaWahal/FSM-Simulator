// FSM.h
#pragma once
#include "Parameters.h"
#include "State.h"
#include "StateFactory.h"
#include "TransitionTable.h"
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class FSM {
private:
  std::vector<std::unique_ptr<State>> states; // Stores all state objects
  std::string startStateName;
  State *currentState; // Current active state
  bool running = true; // Index of the current state
  Parameters parameters;
  TransitionTable transitions;
  int currentInput; // Stores the current condition for transitions
  std::string machineName;

public:
  FSM() : currentState(nullptr) {}

  void setMachineName(const std::string &machineName) {
    FSM::machineName = machineName;
  }
  void addState(State *state) {
    states.emplace_back(state);
    if (currentState == nullptr) {
      currentState = state;
      startStateName = state->getName();
    }
  }
  const std::string &getStartStateName() const { return startStateName; }
  void setCurrentInput(int input) { currentInput = input; }
  void setRunningFlag(bool input) { running = input; }
  void addTransition(const std::string &from, int input,
                     const std::string &to) {
    transitions.addTransition(from, input, to);
  }
  std::string getTransitionForInput() {

    return transitions.getTransition(currentState->getName(), currentInput);
  }
  bool canTransitionTo(const std::string &nextStateName) {
    std::string validState =
        transitions.getTransition(currentState->getName(), currentInput);
    return !validState.empty() && validState == nextStateName;
  }

  void changeStateDirectly(const std::string &nextStateName) {
    for (size_t i = 0; i < states.size(); i++) {
      if (states[i]->getName() == nextStateName &&
          canTransitionTo(nextStateName)) {
        currentState = states[i].get();
        std::cout << "Transitioned to " << nextStateName << std::endl;
        return;
      }
    }
    std::cout << "Invalid transition to " << nextStateName << std::endl;
  }

  int execute() {
    while (running && currentState) {
      currentState->execute(this);
    }
    exit(0);
  }

  Parameters &getParameters() { return parameters; }
};
