#ifndef PROJECT_1_PARSER_H
#define PROJECT_1_PARSER_H
#include "Token.h"

class Parser {

private:
    vector<Token*> myTokens;

public:
    Parser(vector<Token*> tokens);
    void parse();
    int index = 0;
    void parseDatalogProgram(vector<Token*> tokens);
    void parseTerminal(Token* myToken, TokenType type);
    void parseSchemeList(Token* myToken);
    void parseFactList(Token* myToken);
    void parseRuleList(Token* myToken);
    void parseScheme(Token* myToken);
    void parseFact(Token* myToken);
    void parseRule(Token* myToken);
    void parseQuery(Token* myToken);
    void parseQueryList(Token* myToken);
    void parseHeadPredicate(Token* myToken);
    void parsePredicate(Token* myToken);
    void parsePredicateList(Token* myToken);
    void parseParameter(Token* myToken);
    void parseParameterList(Token* myToken);
    void parseStringList(Token* myToken);
    void parseIdList(Token* myToken);

};

#endif //PROJECT_1_PARSER_H
