// TransitionTable.h
#pragma once
#include <unordered_map>
#include <string>
#include <map>

class TransitionTable {
private:
    std::unordered_map<std::string, std::map<int, std::string>> table;

public:
    // Add transition with a condition
    void addTransition(const std::string& from, int input, const std::string& to) {
        table[from][input] = to;
    }

    // Check if a transition is valid based on the input condition
    std::string getTransition(const std::string& from, int input) const {
        if (table.find(from) != table.end()) {
            const auto& inputs = table.at(from);
            if (inputs.find(input) != inputs.end()) {
                return inputs.at(input);
            }
        }
        return ""; // Return empty if no valid transition
    }
};
