#include "ConcreteState.h"
#include "EndCommand.h"
#include "FSM.h"
#include "IncrementCommand.h"
#include "Parser.h"
#include "PrintCommand.h"
#include "WaitForInputCommand.h"
#include <numeric>

int main(int argc, char *argv[]) {
  Parser parser(argc > 1 ? argv[1] : "fsm.fsm");
  FSM *fsm1 = new FSM();
  parser.setFSM(fsm1);
  fsm1->execute();
  return 0;
}
