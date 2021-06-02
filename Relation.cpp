#include "Relation.h"
#include "Header.h"
#include "Tuple.h"
#include <iostream>
#include <set>
using namespace std;

Relation::Relation(string name, Header newHeader) {
    header = newHeader;
    relationName = name;
}

void Relation::addTuple(Tuple tuple) {
    tupleSet.insert(tuple);
}

void Relation::toString() {
    for(Tuple t: tupleSet){
        for (unsigned int i = 0; i < t.getValues().size(); ++i){
            if (t.getValues().size() > i + 1){
                cout << header.getAttributes()[i] << "=" << t.getValues()[i] << ",";
            }
            else {
                cout << header.getAttributes()[i] << "=" << t.getValues()[i];
            }
        }
       cout << endl;
    }
}