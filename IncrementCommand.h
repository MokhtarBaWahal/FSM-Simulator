#include "Command.h"
#include "FSM.h"
#include <functional>
#include <string>
#include <numeric>

class IncrementCommand : public Command {
private:
    std::string variableName;
    std::function<int(int,int)> operation;  // Function to perform the operation
    std::vector<int> vec;

public:
    IncrementCommand(const std::string& varName, std::vector<int> vec, std::function<int(int,int)> op)
            : variableName(varName), vec(vec), operation(op) {}

    void execute(FSM* fsm) override {
        if (fsm->getParameters().exists(variableName)) {
            int currentValue = fsm->getParameters().get<int>(variableName);
            vec.push_back(fsm->getParameters().get<int>(variableName));
//            for (int elem : vec) {
//                std::cout << elem << " ";
//            }
            int result = std::accumulate(vec.begin(), vec.end(), 0, operation);
            fsm->getParameters().set(variableName, result);
            vec.pop_back();
            std::cout<<"new result for "<<variableName<< ": "<<result<<std::endl;
        } else {
            throw std::runtime_error("Variable does not exist: " + variableName);
        }
    }
};
