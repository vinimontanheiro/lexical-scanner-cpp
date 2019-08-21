#include <sstream>
#include "LexiconAnalyzer.h"

LexiconAnalyzer::LexiconAnalyzer(){}

LexiconAnalyzer::~LexiconAnalyzer(void){}

void LexiconAnalyzer::analyze(string token, DFA *identifierDFA, DFA *integerDFA, DFA *floatDFA, DFA *stringDFA) {

    string description;
    string filename = "lexLog.txt";

    if (token.length() > 0) {
        if (this->isKeyword(token)) {
            description = "Keyword";
        } else {
            if (this->isIdentifier(token, identifierDFA)) {
                description = "Identifier";
            } else {
                if (this->isInteger(token, integerDFA)) {
                    description = "Integer";
                } else {
                    if (this->isFloat(token, floatDFA)) {
                        description = "Float";
                    } else {
                        if (this->isString(token, stringDFA)) {
                            description = "String Literal";
                        } else {
                            description = "Lexical Error!";
                            this->writeFile("errorLog.txt", token, description);
                        }
                    }
                }
            }
        }
        cout << setw(24) << left << token << right << description << endl;
        this->writeFile(filename, token, description);
    }
}

bool LexiconAnalyzer::isWhitespace(char ch) {
    return ch == ' ' || ch == '\t' || ch == '\n' || ch == ',';
}

bool LexiconAnalyzer::isSymbol(char ch) {
    return ch == '(' || ch == ')' || ch == '{' || ch == '}' || ch ==';' || ch == '[' || ch == ']';
}

bool LexiconAnalyzer::isOperator(char ch) {
    return ch == '+' || ch == '-' || ch == '=' || ch == '/' || ch =='*' || ch =='**' || ch =='%' || ch =='<' || ch=='>';
}

bool LexiconAnalyzer::isKeyword(string token) {
    return token == "for" || token == "while" || token == "if" || token == "else" || token == "int" || token == "float"
        || token == "short" || token == "do" || token == "char" || token == "return" || token == "auto" || token == "struct" || token == "union"
        || token == "break" || token == "long" || token == "double" || token == "const" || token == "unsigned" || token == "switch" || token == "continue"
        || token == "signed" || token == "void" || token == "case" || token == "enum" || token == "register" || token == "typedef" || token == "default"
        || token == "goto" || token == "extern" || token == "static" || token == "endl" || token == "using" || token == "namespace" || token == "std" ||
            token == "#include" || token == "#define" || token == "std::" || token == "cout" || token == "cin";
}

bool LexiconAnalyzer::isIdentifier(string token, DFA *dfa) {
    return dfa->languageCheck(token);
}

bool LexiconAnalyzer::isInteger(string token, DFA *dfa) {
    return dfa->languageCheck(token);
}

bool LexiconAnalyzer::isFloat(string token, DFA *dfa) {
    return dfa->languageCheck(token);
}

bool LexiconAnalyzer::isString(string token, DFA *dfa) {
    return dfa->languageCheck(this->removeSpaces(token));
}

string LexiconAnalyzer::removeSpaces(string str) {
    string noSpaces;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != ' ') {
            noSpaces.push_back(str[i]);
        }
    }
    return noSpaces;
}

void LexiconAnalyzer::writeFile(string filename, string word, string description){

    ofstream log(filename, ios_base::app | ios_base::out);

    if(log.is_open()){
        log.imbue(locale("pt_PT.utf8"));
        log << setw(24) << left << word << right << description << endl;
    }else{
        cerr< "Nao foi possivel abrir o arquivo!";
    }

}

void LexiconAnalyzer::writeCharInFile(string filename, char word, string description){

    ofstream log(filename, ios_base::app | ios_base::out);

    if(log.is_open()){
        log.imbue(locale("pt_PT.utf8"));
        log << setw(24) << left << word << right << description << endl;
    }else{
        cerr< "Nao foi possivel abrir o arquivo!";
    }

}

void LexiconAnalyzer::readFile(string filename){

    string str;
    ifstream file;
    file.open (filename);
    int a=0;
    string previousLine="";

    if(file.is_open()){
        while(a<1)
        {
            getline(file,str);
            if (str != previousLine)
            {
                previousLine=str;
                cout<<str<<endl;
            }

        }

    } else{
        cerr< "Nao foi possivel abrir o arquivo!";
    }
}
