// Command.h
#pragma once
#include "FSM.h"

class Command {
public:
  virtual ~Command() {}
  virtual void execute(FSM *fsm) = 0;
};
