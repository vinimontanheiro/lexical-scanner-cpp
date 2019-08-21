#include "DFA.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <iomanip>

DFA::DFA(string filename)
{
    this->file.open(filename);
    if (this->file.is_open()) {
        string line;
        string alpha;
        string from;
        string to;
        int index;

        getline(this->file, this->start);
        getline(this->file, line);
        nextChar(line, this->finalStates);
        getline(this->file, line);
        nextChar(line, this->alphabet);
        this->transitions.resize(this->alphabet.size());

        while (getline(this->file, line)) {
            this->transitionTokens.clear();
            nextChar(line, this->transitionTokens);
            from = this->transitionTokens[0];
            alpha = this->transitionTokens[1];
            to = this->transitionTokens[2];

            for (int i = 0; i < this->alphabet.size(); ++i) {
                if (this->alphabet[i] == alpha) {
                    index = i;
                    break;
                }
            }

            this->transitions[index].insert(pair<string,string>(from, to));
        }

        this->file.close();
    } else {
        cerr << "Erro ao abrir " << filename << endl;
    }
}

DFA::~DFA(void){}

void DFA::nextChar(string str, vector<string> &tokens) {
    istringstream ss(str);
    while (!ss.eof()) {
        string x;
        getline( ss, x, ' ' );
        tokens.push_back(x);
    }
}

bool DFA::languageCheck(string word) const {
    bool valid = true;
    string currentState = this->start;
    int index = 0;

    for (int i = 0; i < word.length(); ++i) {
        auto it = find(this->alphabet.begin(), this->alphabet.end(), string(1, word[i]));
        if (it != this->alphabet.end()) {
            index = it - this->alphabet.begin();
            if (this->transitions[index].find(currentState) != this->transitions[index].end()) {
                currentState = this->transitions[index].at(currentState);
            } else {
                valid = false;
            }
        }
        else {
            valid = false;
        }
    }

    if (valid) {

        auto it2 = find(this->finalStates.begin(), this->finalStates.end(), currentState);
        if (it2 != this->finalStates.end()) {
            valid = true;
        } else {
            valid = false;
        }

    } else {
        valid = false;
    }

    return valid;
}

vector<map<string, string>> DFA::getTransitions(){
    return this->transitions;
};

void DFA::showTransitions(vector<map<string, string>> transitions) {

    for(int i = 0; i <= transitions.size();i++){
        for (auto pair : transitions[i]) {
            cout <<setw(8)<< "{" << pair.first << ", " << pair.second << "}, ";
            cout << "\n";
        }
    }
}