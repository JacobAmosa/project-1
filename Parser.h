#ifndef PROJECT_1_PARSER_H
#define PROJECT_1_PARSER_H
#include "Token.h"
#include "DatalogProgram.h"
#include "Rule.h"
#include <set>

class Parser {

private:
    vector<Token*> myTokens;
    DatalogProgram datalogProgram;
    set<string> myDomain;
    Rule rule;

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
    void parseHeadPredicate(Token* myToken, Predicate &headPredicate);
    void parsePredicate(Token* myToken, vector<Predicate> &predicate, vector<Parameter> &parameter);
    void parsePredicateList(Token* myToken,vector<Predicate> &predicates ,vector<Parameter> &parameter);
    void parseParameter(Token* myToken);
    void parseParameterList(Token* myToken, vector<Parameter> &parameter);
    void parseStringList(Token* myToken, vector<Parameter> &parameters, set<string> &myDomain);
    void parseIdList(Token* myToken, vector<Parameter> &parameter);

};

#endif //PROJECT_1_PARSER_H
