#pragma once
#include "Command.h"
#include "FSM.h"
#include <functional>
#include <numeric>
#include <string>

using namespace std;

class IncrementCommand : public Command {
private:
  std::string variableName;
  std::function<int(int, int)> operation; // Function to perform the operation
  std::vector<string> vec;
  int getVal(FSM *fsm, const std::string &varName) {
    if (fsm->getParameters().exists(varName)) {
      return fsm->getParameters().get<int>(varName);
    } else if (isdigit(varName[0])) {
      return std::stoi(varName);
    } else {
      throw std::runtime_error("Variable does not exist: " + varName);
    }
  }

public:
  IncrementCommand(const std::string &varName, std::vector<string> vec,
                   std::function<int(int, int)> op)
      : variableName(varName), operation(op), vec(vec) {}

  void execute(FSM *fsm) override {
    if (fsm->getParameters().exists(variableName)) {
      vector<int> vals(vec.size());
      for (auto &v : vec) {
        vals.push_back(getVal(fsm, v));
      }
      int result = std::accumulate(vals.begin(), vals.end(), 0, operation);
      fsm->getParameters().set(variableName, result);
      std::cout << "new result for " << variableName << ": " << result
                << std::endl;
    } else {
      throw std::runtime_error("Variable does not exist: " + variableName);
    }
  }
};
