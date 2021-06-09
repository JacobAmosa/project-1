#include "Tuple.h"
#include <iostream>
using namespace std;

vector<string> Tuple::getValues(){
    return values;
}

void Tuple::setValues(vector<string> values) {
    Tuple::values = values;
}

void Tuple::addValue(string value){
    values.push_back(value);
}

string Tuple::getValue(int index) {
    return values.at(index);
}

void Tuple::toString(Header header) {
    int counter = 0;
    for (unsigned int i = 0; i < values.size(); ++i){
        if (values.size() > i + 1){
            cout << header.getAttributes()[i] << "=" << values[i] << ",";
            counter++;
        }
        else {
            cout << header.getAttributes()[i] << "=" << values[i];
            counter++;
        }
    }
}