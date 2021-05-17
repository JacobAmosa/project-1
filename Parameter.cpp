#include "Parameter.h"

 string Parameter::getParameter()  {
    return parameter;
}

void Parameter::setParameter(string parameter) {
    Parameter::parameter = parameter;
}

TokenType Parameter::getType() {
    return type;
}

void Parameter::setType(TokenType type) {
    Parameter::type = type;
}

Parameter::Parameter(string parameter, TokenType type) : parameter(parameter), type(type) {}
