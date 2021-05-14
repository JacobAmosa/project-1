#include <vector>
#include "Parser.h"
#include "Token.h"

Parser::Parser(vector<Token*> tokens) {
    myTokens = tokens;
    try{
        parseDatalogProgram(myTokens);
        cout << "Success!" << endl;
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
    parseTerminal(myTokens[index], TokenType::ID);
    parseTerminal(myTokens[index], TokenType::LEFT_PAREN);
    parseTerminal(myTokens[index], TokenType::ID);
    parseIdList(myTokens[index]);
    parseTerminal(myTokens[index], TokenType::RIGHT_PAREN);
}

void Parser::parseIdList(Token *myToken) {
    if (myTokens[index]->tokenType == TokenType::COMMA){
        parseTerminal(myTokens[index], TokenType::COMMA);
        parseTerminal(myTokens[index], TokenType::ID);
        parseIdList(myTokens[index]);
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
    parseTerminal(myTokens[index], TokenType::ID);
    parseTerminal(myTokens[index], TokenType::LEFT_PAREN);
    parseTerminal(myTokens[index], TokenType::STRING);
    parseStringList(myTokens[index]);
    parseTerminal(myTokens[index], TokenType::RIGHT_PAREN);
    parseTerminal(myTokens[index], TokenType::PERIOD);
}

void Parser::parseStringList(Token *myToken) {
    if (myTokens[index]->tokenType == TokenType::COMMA){
        parseTerminal(myTokens[index], TokenType::COMMA);
        parseTerminal(myTokens[index], TokenType::STRING);
        parseStringList(myTokens[index]);
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

void Parser::parseRule(Token *myToken) {
    parseHeadPredicate(myTokens[index]);
    parseTerminal(myTokens[index], TokenType::COLON_DASH);
    parsePredicate(myTokens[index]);
    parsePredicateList(myTokens[index]);
    parseTerminal(myTokens[index], TokenType::PERIOD);
}

void Parser::parseHeadPredicate(Token *myToken) {
    parseTerminal(myTokens[index], TokenType::ID);
    parseTerminal(myTokens[index], TokenType::LEFT_PAREN);
    parseTerminal(myTokens[index], TokenType::ID);
    parseIdList(myTokens[index]);
    parseTerminal(myTokens[index], TokenType::RIGHT_PAREN);
}

void Parser::parsePredicateList(Token *myToken) {
    if (myTokens[index]->tokenType == TokenType::COMMA){
        parseTerminal(myTokens[index], TokenType::COMMA);
        parsePredicate(myTokens[index]);
        parsePredicateList(myTokens[index]);
    }
    else if (myTokens[index]->tokenType == TokenType::PERIOD){
        return;
    }
    else {
        throw myToken->toString();
    }
}

void Parser::parseQuery(Token *myToken) {
    parsePredicate(myTokens[index]);
    parseTerminal(myTokens[index], TokenType::Q_MARK);
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

void Parser::parsePredicate(Token *myToken) {
    parseTerminal(myTokens[index], TokenType::ID);
    parseTerminal(myTokens[index], TokenType::LEFT_PAREN);
    parseParameter(myTokens[index]);
    parseParameterList(myTokens[index]);
    parseTerminal(myTokens[index], TokenType::RIGHT_PAREN);
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

void Parser::parseParameterList(Token *myToken) {
    if (myTokens[index]->tokenType == TokenType::COMMA){
        parseTerminal(myTokens[index], TokenType::COMMA);
        parseParameter(myTokens[index]);
        parseParameterList(myTokens[index]);
    }
    else if (myTokens[index]->tokenType == TokenType::RIGHT_PAREN){
        return;
    }
    else {
        throw myToken->toString();
    }
}