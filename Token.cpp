#include "Token.h"
#include <string>
#include <cctype>
#include <iostream>
using namespace std;

Token::Token(TokenType type, std::string description, int line) {
    // TODO: initialize all member variables
    this->tokenValue = description;
    this->tokenType = type;
    this->lineNumber = line;
}

string Token::toString() {
    string theToken;
    string type = "ERROR1";
    switch (tokenType) {
        case TokenType::COMMA:
            type = "COMMA";
            break;
        case TokenType::PERIOD:
            type = "PERIOD";
            break;
        case TokenType::Q_MARK:
            type = "Q_MARK";
            break;
        case TokenType::LEFT_PAREN:
            type = "LEFT_PAREN";
            break;
        case TokenType::RIGHT_PAREN:
            type = "RIGHT_PAREN";
            break;
        case TokenType::COLON:
            type = "COLON";
            break;
        case TokenType::COLON_DASH:
            type = "COLON_DASH";
            break;
        case TokenType::MULTIPLY:
            type = "MULTIPLY";
            break;
        case TokenType::ADD:
            type = "ADD";
            break;
        case TokenType::SCHEMES:
            type = "SCHEMES";
            break;
        case TokenType::FACTS:
            type = "FACTS";
            break;
        case TokenType::RULES:
            type = "RULES";
            break;
        case TokenType::QUERIES:
            type = "QUERIES";
            break;
        case TokenType::ID:
            type = "ID";
            break;
        case TokenType::STRING:
            type = "STRING";
            break;
        case TokenType::COMMENT:
            type = "COMMENT";
            break;
        case TokenType::UNDEFINED:
            type = "UNDEFINED";
            break;
        case TokenType::EOF_TYPE:
            type = "EOF";
            break;
    }
    theToken = "(" + type + ",\"" + tokenValue + "\"," + to_string(lineNumber) + ")";
    return theToken;
}

const string Token::getTokenValue() const {
    return tokenValue;
}
