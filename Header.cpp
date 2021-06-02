#include "Header.h"

Header::Header(vector<string> parameters) {
    attributes = parameters;
}

Header::Header(){
    //Does nothing.
}

vector<string> Header::getAttributes(){
    return attributes;
}

void Header::setAttributes(vector<string> attributes) {
    Header::attributes = attributes;
}
