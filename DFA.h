#include <vector>
#include <string>
#include <map>
#include <fstream>

using namespace std;

#ifndef SCANNER_DFA_H
#define SCANNER_DFA_H

/**
 * Classe que representa um automato DFA para verificar se a token informada faz parte da linguagem que usamos
 * @since 08/2014 PUC-GO
 */
class DFA {

private:
    ifstream file;
    string start;
    vector<string> finalStates;
    vector<string> alphabet;
    vector<map<string, string> > transitions;
    vector<string> transitionTokens;
public:
    DFA(string filename);
    ~DFA(void);
    bool languageCheck(string word) const;
    void nextChar(string str, vector<string> &tokens);
    vector<map<string, string> > getTransitions();
;   void showTransitions(vector<map<string,string> > transitions);
};

#endif //SCANNER_DFA_H

