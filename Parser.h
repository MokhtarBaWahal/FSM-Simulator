#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <string>
#include <array>
#include <algorithm>
#include <cstring>
#include "FSM.h"
using namespace std;

#define FSM_E "FSM"
#define VAR "VAR"
#define STATES "STATES"
#define TRANSITIONS "TRANSITIONS"

class Parser {
private:
    vector<string> lines;
    vector<vector<string>> line_tokens;
    array<string, 4> section_names = {FSM_E, VAR, STATES, TRANSITIONS};
    map<string, vector<vector<string>>::iterator> section;
    string machinename;
    vector<string> vars;
    map<string, vector<string>> states;
    map<int, pair<string, string>> transitions;

    // Reads file and returns vector of lines
    void read(const string &filename) {
        ifstream file(filename);
        string line;
        while (getline(file, line)) {
            if (!line.empty()) {
                lines.push_back(line);
            }
        }
    }

    vector<string> tokenize(string &line) {
        vector<string> tokens;
        const char *delim = "[,]; >:=";
        const char *print_delim = ";";
        for (auto token = strtok(line.data(), delim); token != NULL;
             token = strtok(NULL, strcmp(token, "PRINT") ? delim : print_delim)) {
            tokens.emplace_back(token);
        }
        return tokens;
    }

    void tokenizeLines() {
        line_tokens.reserve(lines.size());
        for (auto &line : lines) {
            auto tokens = tokenize(line);

            if (!tokens.empty()) {
                line_tokens.push_back(tokens);
                if (find(section_names.begin(), section_names.end(), tokens[0]) != section_names.end()) {
                    section[tokens[0]] = prev(line_tokens.end());
                }
            }
        }
    }

    void parseMachineName() {
        auto &MachineNameTokens = *section[FSM_E];
        if (MachineNameTokens.size() < 2) {
            throw runtime_error("Machine name not found");
        }
        machinename = MachineNameTokens[1];
    }

    void parseVars() {
        auto VarTokens = *section[VAR];
        for (size_t i = 1; i < VarTokens.size(); i++) {
            vars.push_back(VarTokens[i]);
        }
    }

    void parseStates() {
        for (auto it = next(section[STATES]); it != section[TRANSITIONS]; ++it) {
            for (size_t i = 1; i < it->size(); i++) {
                states[it->at(0)].push_back(it->at(i));
            }
        }
    }

    void parseTransitions() {
        for (auto it = next(section[TRANSITIONS]); it != line_tokens.end(); ++it) {
            if (it->size() == 3) {
                transitions[stoi(it->at(0))] = {it->at(1), it->at(2)};
            }
        }
    }

public:
    Parser(const string& filename = "fsm.fsm") {
        read(filename);
        tokenizeLines();
        parseMachineName();
        parseVars();
        parseStates();
        parseTransitions();
    }

    void setMachineName(FSM* fsm) const {
        fsm->setMachineName(machinename);
        cout << "Machine Name: " << machinename << endl;
    }

    void setVariables(FSM* fsm) const {

        cout << "Variables: ";
        for (const auto& var : vars) {
            fsm->getParameters().set(var, 0);
            cout << var << " ";
        }
        cout << endl;
    }

    void printStates() const {
        cout << "States:" << endl;
        for (const auto& state : states) {
            cout << state.first << ": ";
            ConcreteState state_name (state.first);
            for (const auto& s : state.second) {
                cout << s << " \n";
            }
            cout << endl;
        }
    }

    void printTransitions() const {
        cout << "Transitions:" << endl;
        for (const auto& transition : transitions) {
            cout << transition.first << " -> " << transition.second.first << " " << transition.second.second << endl;
        }
    }
};
