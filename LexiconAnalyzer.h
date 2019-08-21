#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "DFA.h"
#include <iomanip>

using namespace std;

#ifndef SCANNER_LEXICONANALYZER_H
#define SCANNER_LEXICONANALYZER_H


class LexiconAnalyzer {
public:
    LexiconAnalyzer();
    ~LexiconAnalyzer(void);
    void analyze(string token, DFA *identifierDFA, DFA *integerDFA, DFA *floatDFA, DFA *stringDFA);
    bool isWhitespace(char ch);
    bool isSymbol(char ch);
    bool isOperator(char ch);
    bool isKeyword(string token);
    bool isIdentifier(string token, DFA *dfa);
    bool isInteger(string token, DFA *dfa);
    bool isFloat(string token, DFA *dfa);
    bool isString(string token, DFA *dfa);
    string removeSpaces(string str);
    void writeFile(string filename,string word,string message);
    void writeCharInFile(string filename, char word, string description);
    void readFile(string filename);
};

#endif //SCANNER_LEXICONANALYZER_H



