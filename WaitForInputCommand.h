// WaitForInputCommand.h
#pragma once
#include "Command.h"
#include "FSM.h"
#include <iostream>

class WaitForInputCommand : public Command {
public:
  void execute(FSM *fsm) override {
    int input;
    std::cout << "Enter a number for transition: ";
    std::cin >> input; // Capture input from the user

    fsm->setCurrentInput(input); // Set the input in the FSM

    // Attempt to transition based on the input
    std::string nextState = fsm->getTransitionForInput();
    bool validInput = false;
    while (nextState.empty()) {

      std::cout << "No valid transition for input: " << input << std::endl;
      std::cout << "Enter a number for transition: ";
      std::cin >> input; // Capture input from the user

      fsm->setCurrentInput(input); // Set the input in the FSM

      nextState = fsm->getTransitionForInput();
    }
    fsm->changeStateDirectly(nextState);
  }
};
