#include <iostream>

using namespace std;

#include "LexiconAnalyzer.h"


int main() {
    string filename;
    LexiconAnalyzer lex;

    cout << "Informe o nome do arquivo: " << endl;
    cin >> filename;

    ifstream file(filename);

    DFA identifierDFA("identifiers.txt");
    DFA integerDFA("whoneNumbers.txt");
    DFA floatDFA("realNumbers.txt");
    DFA stringDFA("strings.txt");

    if (file.is_open()) {
        string line;
        string token;
        char nextChar;

        while (getline(file, line)) {

            for (int i = 0; i < line.length(); i++) {
                nextChar = line[i];
                if (lex.isWhitespace(nextChar)) {
                    lex.analyze(token, &identifierDFA, &integerDFA, &floatDFA, &stringDFA);
                    token.clear();
                }
                else if (lex.isSymbol(nextChar)) {
                    lex.analyze(token, &identifierDFA, &integerDFA, &floatDFA, &stringDFA);
                    token.clear();
                    cout << setw(24) << left << nextChar << right << "Symbol" << endl;
                    lex.writeCharInFile("lexLog.txt",nextChar,"Symbol");
                }
                else if (lex.isOperator(nextChar)) {
                    lex.analyze(token, &identifierDFA, &integerDFA, &floatDFA, &stringDFA);
                    token.clear();
                    cout << setw(24) << left << nextChar << right << "Operator" << endl;
                    lex.writeCharInFile("lexLog.txt",nextChar,"Operator");
                }
                else if (nextChar == '"'){
                    lex.analyze(token, &identifierDFA, &integerDFA, &floatDFA, &stringDFA);
                    token.clear();

                    token.push_back(nextChar);
                    i++;
                    nextChar = line[i];

                    while(nextChar != '"') {
                        token.push_back(nextChar);
                        i++;
                        nextChar = line[i];
                    }

                    token.push_back(nextChar);
                }

                else {
                    token.push_back(nextChar);
                }
            }
        }

    } else {
        cout << "Erro ao abrir arquivo " << filename << endl;
    }
    return 0;
}

