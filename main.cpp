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
  /* Parser prs; */
  /* FSM fsm1; */
  /* prs.setMachineName(&fsm1); */
  /* prs.setVariables(&fsm1); */
  /* prs.printStates(); */
  /* // Define states and their actions using ConcreteState */
  /* ConcreteState stateA("State A"), stateB("State B"), stateC("State C"); */
  /* stateA.addCommand(new PrintCommand("State A\n")); */
  /* std::vector<int> vec; */
  /* vec.push_back(1); */
  /**/
  /* IncrementCommand *incrementX = */
  /*     new IncrementCommand("X", vec, [](int a, int b) { return a + b; }); */
  /* stateA.addCommand(incrementX); */
  /* stateA.addCommand(new WaitForInputCommand()); */
  /**/
  /* stateB.addCommand(new PrintCommand("State B\n")); */
  /* std::vector<int> vec1; */
  /* vec1.push_back(1); */
  /* vec1.push_back(5); */
  /* IncrementCommand *incrementY = */
  /*     new IncrementCommand("Y", vec1, [](int a, int b) { return a + b; }); */
  /* stateB.addCommand(incrementY); */
  /* stateB.addCommand(new WaitForInputCommand()); */
  /**/
  /* stateC.addCommand(new PrintCommand("Thank you for using fsm1 \n")); */
  /* stateC.addCommand(new PrintCommand("Final X : ")); */
  /* stateC.addCommand(new PrintCommand("Final Y : ")); */
  /* stateC.addCommand(new EndCommand()); */
  /**/
  /* // adding the states to fsm1 */
  /* fsm1.addState(&stateA); */
  /* fsm1.addState(&stateB); */
  /* fsm1.addState(&stateC); */
  /**/
  /* fsm1.addTransition("State A", 1, "State B"); */
  /* fsm1.addTransition("State B", 2, "State A"); */
  /* fsm1.addTransition("State A", 2, "State A"); */
  /* fsm1.addTransition("State B", 1, "State B"); */
  /* fsm1.addTransition("State B", 3, "State C"); */
  /**/
  /* // Run FSM based on transitions defined */
  /* std::cout << "FSM constructed!\n"; */
  /* fsm1.execute(); */
  /**/
  /* return 0; */
}
