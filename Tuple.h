#ifndef PROJECT_1_TUPLE_H
#define PROJECT_1_TUPLE_H
#include <string>
#include <vector>
#include "Header.h"
using namespace std;


class Tuple {
private:
    vector<string> values;

public:
    bool operator< (const Tuple& other) const {
        return this->values < other.values;
    }

    vector<string> getValues();
    void setValues(vector<string> values);
    void addValue(string value);
    string getValue(int index);
    void toString(Header header);
};


#endif //PROJECT_1_TUPLE_H
