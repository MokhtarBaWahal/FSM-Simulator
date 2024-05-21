#include <bits/stdc++.h>
using namespace std;

#define FSM "FSM"
#define VAR "VAR"
#define STATES "STATES"
#define TRANSITIONS "TRANSITIONS"

class Parser {
private:
  vector<string> lines;
  vector<vector<string>> line_tokens;
  std::array<string, 4> section_names = {FSM, VAR, STATES, TRANSITIONS};
  map<string, vector<vector<string>>::iterator> section;
  string machinename;
  vector<string> vars;
  map<string, vector<string>> states;
  map<int, pair<string, string>> transitions;

  // Reads file and returns vector of lines
  void read(const string &filename) {
    ifstream file(filename);
    string line;

    while (getline(file, line, '\n')) {
      if (line.empty()) {
        continue;
      }
      lines.push_back(line);
    }
  }

  vector<string> tokenize(string &line) {
    vector<string> tokens;
    const char *delim = "[,];() >:=";
    const char *print_delim = "()";
    for (auto token = strtok(line.data(), delim); token != NULL;
         token = strtok(NULL, strcmp(token, "PRINT") ? delim : print_delim)) {
      tokens.emplace_back(token);
    }
    return tokens;
  }

  void tokenize() {
    line_tokens.reserve(lines.size()); // This is essential to avoid
    // reallocation of array and potential invalidation of iterators
    for (auto &line : lines) {
      auto tokens = tokenize(line);
      if (tokens.empty()) {
        continue;
      }
      line_tokens.push_back(tokens);
      if (find(section_names.begin(), section_names.end(), tokens[0]) !=
          section_names.end()) {
        section[tokens[0]] = line_tokens.end() - 1;
      }
    }
  }

  void parseMachineName() {
    auto &MachineNameTokens = *section[FSM];
    if (MachineNameTokens.size() < 2) {
      throw runtime_error("Machine name not found");
    }
    machinename = MachineNameTokens[1];
  }

  void parseVars() {
    auto VarTokens = *section[VAR];
    if (VarTokens.size() < 2) {
      throw runtime_error("Variable not found");
    }
    for (size_t i = 1; i < VarTokens.size(); i++) {
      vars.push_back(VarTokens[i]);
    }
  }

  void parseState(vector<string> &line) {
    for (size_t i = 1; i < line.size(); i++) {
      states[line[0]].push_back(line[i]);
    }
  }

  void parseStates() {
    for (auto it = section[STATES] + 1; it != section[TRANSITIONS]; it++) {
      parseState(*it);
    }
  }

  void parseTransition(const vector<string> &line) {
    if (line.size() != 3) {
      throw runtime_error("Transition not found");
    }
    transitions[stoi(line[0])] = {line[1], line[2]};
  }

  void parseTransitions() {
    for (auto it = section[TRANSITIONS] + 1; it != line_tokens.end(); it++) {
      parseTransition(*it);
    }
  }

  void parse() {
    parseMachineName();
    parseVars();
    parseStates();
    parseTransitions();
  }

public:
  Parser(string filename = "fsm.fsm") {
    read(filename);
    tokenize();
    parse();
  }
  const string &getMachineName() const { return machinename; }
  const vector<string> &getVariables() const { return vars; }
  const map<string, vector<string>> &getStates() const { return states; }
  const map<int, pair<string, string>> &getTransitions() const {
    return transitions;
  }
};
