#include "ConcreteState.h"
#include "EndCommand.h"
#include "FSM.h"
#include "IncrementCommand.h"
#include "Parser.h"
#include "PrintCommand.h"
#include "WaitForInputCommand.h"
#include <numeric>

int main() {
  Parser parser;
  FSM *fsm1 = new FSM();
  parser.setFSM(fsm1);
  fsm1->execute();
  return 0;
}
