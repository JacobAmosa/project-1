#ifndef TOKEN_H
#define TOKEN_H
#include <string>
#include <cctype>
#include <iostream>
using namespace std;

enum TokenType {
    COLON,
    COLON_DASH,
    STRING,
    COMMA,
    PERIOD,
    Q_MARK,
    LEFT_PAREN,
    RIGHT_PAREN,
    MULTIPLY,
    ADD,
    SCHEMES,
    FACTS,
    RULES,
    QUERIES,
    ID,
    COMMENT,
    EOF_TYPE,
    UNDEFINED
};

class Token
{
private:
    // TODO: add member variables for information needed by Token

public:
    TokenType tokenType;
    int lineNumber;
    string tokenValue = "";

    Token(TokenType type, std::string description, int line);
    string toString();  //Creates A string of the token type.

};

#endif // TOKEN_H

