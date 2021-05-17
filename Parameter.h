#ifndef PROJECT_1_PARAMETER_H
#define PROJECT_1_PARAMETER_H
#include <string>
#include "Token.h"
using namespace std;


class Parameter {
private:
    string parameter;
    TokenType type;

public:
    Parameter(string parameter, TokenType type);

    string getParameter();

    void setParameter(string parameter);

    TokenType getType();

    void setType(TokenType type);

};


#endif //PROJECT_1_PARAMETER_H

