#include <vector>
#include <set>
#include "Parser.h"
#include "Token.h"
#include "Predicate.h"
#include "Parameter.h"
#include "DatalogProgram.h"

Parser::Parser(vector<Token*> tokens) {
    myTokens = tokens;
    try{
        parseDatalogProgram(myTokens);
        cout << "Success!" << endl;
        datalogProgram.toString();
    }
    catch(string error){
        cout << "Failure!" << endl << error;
    }
}

//Calling each terminal and nonterminal in the datalog grammar.
void Parser::parseDatalogProgram(vector<Token*> tokens) {
    parseTerminal(tokens[index], TokenType::SCHEMES);
    parseTerminal(tokens[index], TokenType::COLON);
    parseScheme(tokens[index]);
    parseSchemeList(tokens[index]);
    parseTerminal(tokens[index], TokenType::FACTS);
    parseTerminal(tokens[index], TokenType::COLON);
    parseFactList(tokens[index]);
    parseTerminal(tokens[index], TokenType::RULES);
    parseTerminal(tokens[index], TokenType::COLON);
    parseRuleList(tokens[index]);
    parseTerminal(tokens[index], TokenType::QUERIES);
    parseTerminal(tokens[index], TokenType::COLON);
    parseQuery(tokens[index]);
    parseQueryList(tokens[index]);
    parseTerminal(tokens[index], TokenType::EOF_TYPE);
}

void Parser::parseTerminal(Token* myToken, TokenType type){
    if (myToken->tokenType == type){
        index++;
    }
    else{
        throw myToken->toString();
    }
}

void Parser::parseScheme(Token *myToken) {
    Predicate predicate;
    vector<Parameter> parameters;

    predicate.setIdName(myTokens[index]->getTokenValue());
    parseTerminal(myTokens[index], TokenType::ID);
    parseTerminal(myTokens[index], TokenType::LEFT_PAREN);
    Parameter parameter(myTokens[index]->getTokenValue(), TokenType::ID);    //setting the first parameter and adding it to parameter vector.
    parameters.push_back(parameter);
    parseTerminal(myTokens[index], TokenType::ID);
    parseIdList(myTokens[index], parameters);
    parseTerminal(myTokens[index], TokenType::RIGHT_PAREN);
    predicate.setParameters(parameters);                                                    //setting paramters and pushing the object to datalog scheme vector.
    datalogProgram.schemes.push_back(predicate);
}

void Parser::parseIdList(Token *myToken, vector<Parameter> &parameters) {
    if (myTokens[index]->tokenType == TokenType::COMMA){
        parseTerminal(myTokens[index], TokenType::COMMA);
        Parameter parameter(myTokens[index]->getTokenValue(), TokenType::ID);   //Adding each new parameter.
        parameters.push_back(parameter);
        parseTerminal(myTokens[index], TokenType::ID);
        parseIdList(myTokens[index], parameters);
    }
    else if(myTokens[index]->tokenType == TokenType::RIGHT_PAREN){
        return;
    }
    else {
        throw myToken->toString();
    }
}

void Parser::parseSchemeList(Token *myToken) {
    if (myTokens[index]->tokenType == TokenType::ID){
        parseScheme(myTokens[index]);
        parseSchemeList(myTokens[index]);
    }
    else if (myTokens[index]->tokenType == TokenType::FACTS){
        return;
    }
    else {
        throw myToken->toString();
    }
}

void Parser::parseFactList(Token *myToken) {
    if (myTokens[index]->tokenType == TokenType::ID){
        parseFact(myTokens[index]);
        parseFactList(myTokens[index]);
    }
    else if (myTokens[index]->tokenType == TokenType::RULES){
        return;
    }
    else {
        throw myToken->toString();
    }
}

void Parser::parseFact(Token *myToken) {
    Predicate predicate;
    vector<Parameter> parameters;

    predicate.setIdName(myTokens[index]->getTokenValue());
    parseTerminal(myTokens[index], TokenType::ID);
    parseTerminal(myTokens[index], TokenType::LEFT_PAREN);
    Parameter parameter(myTokens[index]->getTokenValue(), TokenType::ID);    //creating a parameter object and adding it to parameter vector.
    parameters.push_back(parameter);
    myDomain.insert(myTokens[index]->getTokenValue());                                     //Adding each string to Domain set.
    parseTerminal(myTokens[index], TokenType::STRING);
    parseStringList(myTokens[index], parameters, myDomain);
    parseTerminal(myTokens[index], TokenType::RIGHT_PAREN);
    parseTerminal(myTokens[index], TokenType::PERIOD);
    predicate.setParameters(parameters);                                                    //setting paramters and pushing the object to datalog scheme vector.
    datalogProgram.facts.push_back(predicate);
    datalogProgram.setDomain(myDomain);
}

void Parser::parseStringList(Token *myToken, vector<Parameter> &parameters, set<string> &myDomain) {
    if (myTokens[index]->tokenType == TokenType::COMMA){
        parseTerminal(myTokens[index], TokenType::COMMA);
        Parameter parameter(myTokens[index]->getTokenValue(), TokenType::ID);   //Adding each new parameter.
        parameters.push_back(parameter);
        myDomain.insert(myTokens[index]->getTokenValue());
        parseTerminal(myTokens[index], TokenType::STRING);
        parseStringList(myTokens[index], parameters, myDomain);
    }
    else if (myTokens[index]->tokenType == TokenType::RIGHT_PAREN){
        return;
    }
    else {
        throw myToken->toString();
    }
}

void Parser::parseRuleList(Token *myToken) {
    if (myTokens[index]->tokenType == TokenType::ID){
        parseRule(myTokens[index]);
        parseRuleList(myTokens[index]);
    }
    else if (myTokens[index]->tokenType == TokenType::QUERIES){
        return;
    }
    else {
        throw myToken->toString();
    }
}

void Parser::parseHeadPredicate(Token *myToken, Predicate &headPredicate) {
    vector<Parameter> parameters;

    headPredicate.setIdName(myTokens[index]->getTokenValue());
    parseTerminal(myTokens[index], TokenType::ID);
    parseTerminal(myTokens[index], TokenType::LEFT_PAREN);
    Parameter parameter(myTokens[index]->getTokenValue(), TokenType::ID);   //Adding each new parameter.
    parameters.push_back(parameter);
    parseTerminal(myTokens[index], TokenType::ID);
    parseIdList(myTokens[index], parameters);
    parseTerminal(myTokens[index], TokenType::RIGHT_PAREN);
    headPredicate.setParameters(parameters);
    //rule.setHeadPredicate(headPredicate);
}

void Parser::parseQuery(Token *myToken) {
    Predicate predicate;
    vector<Predicate> predicates;
    vector<Parameter> parameter;

    predicate.setIdName(myTokens[index]->getTokenValue());
    parsePredicate(myTokens[index], predicates, parameter);
    parseTerminal(myTokens[index], TokenType::Q_MARK);
    predicate.setParameters(parameter);                                      //setting paramters and pushing the object to datalog scheme vector.
    datalogProgram.queries.push_back(predicate);
}

void Parser::parseQueryList(Token *myToken) {
    if (myTokens[index]->tokenType == TokenType::ID){
        parseQuery(myTokens[index]);
        parseQueryList(myTokens[index]);
    }
    else if (myTokens[index]->tokenType == TokenType::EOF_TYPE){
        return;
    }
    else {
        throw myToken->toString();
    }
}

void Parser::parseRule(Token *myToken) {
    Rule rule;
    Predicate headPredicate;
    vector<Predicate> predicates;
    vector<Parameter> parameters;

    headPredicate.setIdName(myTokens[index]->getTokenValue());
    parseHeadPredicate(myTokens[index], headPredicate);
    parseTerminal(myTokens[index], TokenType::COLON_DASH);
    parsePredicate(myTokens[index], predicates, parameters);
    parsePredicateList(myTokens[index], predicates,parameters);
    parseTerminal(myTokens[index], TokenType::PERIOD);
    rule.setHeadPredicate(headPredicate);
    rule.setBodyPredicates(predicates);
    datalogProgram.rules.push_back(rule);
}

void Parser::parsePredicateList(Token *myToken, vector<Predicate> &predicates, vector<Parameter> &parameter) {
    if (myTokens[index]->tokenType == TokenType::COMMA){
        parseTerminal(myTokens[index], TokenType::COMMA);
        parsePredicate(myTokens[index], predicates, parameter);
        parsePredicateList(myTokens[index], predicates, parameter);
    }
    else if (myTokens[index]->tokenType == TokenType::PERIOD){
        return;
    }
    else {
        throw myToken->toString();
    }
}

void Parser::parsePredicate(Token *myToken, vector<Predicate> &predicate, vector<Parameter> &parameter) {
    Predicate bodyPredicate;
    bodyPredicate.setIdName(myTokens[index]->getTokenValue());
    parseTerminal(myTokens[index], TokenType::ID);
    parseTerminal(myTokens[index], TokenType::LEFT_PAREN);
    Parameter parameters(myTokens[index]->getTokenValue(), TokenType::ID);
    parameter.push_back(parameters);
    parseParameter(myTokens[index]);
    parseParameterList(myTokens[index], parameter);
    parseTerminal(myTokens[index], TokenType::RIGHT_PAREN);
    bodyPredicate.setParameters(parameter);
    predicate.push_back(bodyPredicate);
}

void Parser::parseParameter(Token *myToken) {
    if (myTokens[index]->tokenType == TokenType::STRING){
        parseTerminal(myTokens[index], TokenType::STRING);
    }
    else if (myTokens[index]->tokenType == TokenType::ID){
        parseTerminal(myTokens[index], TokenType::ID);
    }
    else {
        throw myToken->toString();
    }
}

void Parser::parseParameterList(Token *myToken, vector<Parameter> &parameter) {
    if (myTokens[index]->tokenType == TokenType::COMMA){
        parseTerminal(myTokens[index], TokenType::COMMA);
        Parameter parameters(myTokens[index]->getTokenValue(), TokenType::ID);
        parameter.push_back(parameters);
        parseParameter(myTokens[index]);
        parseParameterList(myTokens[index], parameter);
    }
    else if (myTokens[index]->tokenType == TokenType::RIGHT_PAREN){
        return;
    }
    else {
        throw myToken->toString();
    }
}