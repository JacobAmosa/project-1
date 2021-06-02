#ifndef PROJECT_1_RELATION_H
#define PROJECT_1_RELATION_H
#include "Header.h"
#include "Tuple.h"
#include <vector>
#include <set>
#include <string>
using namespace std;

//Keeps track of the tuples coming from the facts.
//NO DUPLICATES (use sets).
//Retrieves vector of strings from tuple and header classes.
//

class Relation {
private:
    string relationName;
    Header header;
    set<Tuple> tupleSet;
public:
    Relation(string name, Header newHeader);
    void addTuple(Tuple tuple);
    void toString();
    //ADD 4 SPECIAL FUNCTIONS SELECT*2, PROJECT, RENAME*****
};


#endif //PROJECT_1_RELATION_H
