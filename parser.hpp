#include <bits/stdc++.h>
using namespace std;

class Parser
{
private:
    string machinename;
    vector<string> vars;
    map<string, vector<string>> states;
    map<int, pair<string, string>> transitions;

    vector<string> read(const string &filename)
    {
        vector<string> lines;
        ifstream file(filename);
        string line;

        while (getline(file, line, '\n'))
        {
            if (line.empty())
            {
                continue;
            }
            lines.push_back(line);
        }
        return lines;
    }
    vector<string> tokenize(string &line)
    {
        vector<string> tokens;
        const char *delim = "[,];() >:";
        const char *print_delim = "()";
        for (auto token = strtok(line.data(), delim);
             token != NULL;
             token = strtok(NULL, strcmp(token, "PRINT") ? delim : print_delim))
        {
            tokens.emplace_back(token);
        }
        return tokens;
    }
    vector<vector<string>> parse(vector<string> &lines)
    {
        vector<vector<string>> parsed;
        for (auto &line : lines)
        {
            vector<string> tokens = tokenize(line);
            if (!tokens.empty())
            {
                parsed.push_back(tokens);
            }
        }
        return parsed;
    }
    void parseMachineName(const vector<string> tokens)
    {
        if (tokens.size() < 2)
        {
            throw runtime_error("Machine name not found");
        }
        machinename = tokens[1];
    }
    void parseVars(const vector<string> tokens)
    {
        if (tokens.size() < 2)
        {
            throw runtime_error("Variable not found");
        }
        for (size_t i = 1; i < tokens.size(); i++)
        {
            vars.push_back(tokens[i]);
        }
    }
    void parseState(const vector<string> &tokens)
    {
        if (tokens.size() < 2)
        {
            throw runtime_error("State not found");
        }
        states[tokens[0]] = vector<string>(tokens.begin() + 1, tokens.end());
    }
    void parseTransition(const vector<string> &tokens)
    {
        if (tokens.size() < 3)
        {
            throw runtime_error("Transition not found");
        }
        transitions[stoi(tokens[0])] = {tokens[1], tokens[2]};
    }

    string getMachineName() const { return machinename; }
    vector<string> getVariables() const { return vars; }
    map<string, vector<string>> getStates() const { return states; }
    map<int, pair<string, string>> getTransitions() const { return transitions; }

public:
    Parser(string filename = "fsm.fsm")
    {
        vector<string> lines = read(filename);
        auto parsed = parse(lines);
        parseMachineName(parsed[0]);
        parseVars(parsed[1]);
        for (size_t i = 2; i < parsed.size(); i++)
        {
            states[parsed[i][0]] = vector<string>(parsed[i].begin() + 1, parsed[i].end());
        }
    }
};