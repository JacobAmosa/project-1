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

Relation::Relation() {};

void Relation::addTuple(Tuple tuple) {
    tupleSet.insert(tuple);
}

Relation Relation::select1(int index, string value) {
    Relation relation(this->relationName, this->header);
    for(Tuple t: tupleSet){
        if (t.getValues().at(index) == value) {
            relation.addTuple(t);
        }
    }
    return relation;
}

Relation Relation::select2(int index1, int index2) {
    Relation relation(this->relationName, this->header);
    for(Tuple t: tupleSet){
        if (t.getValues().at(index1) == t.getValues().at(index2)) {
            relation.addTuple(t);
        }
    }
    return relation;
}

Relation Relation::project(vector<int> columns) {
    Relation relation(this->relationName, this->header);
    vector<string> newColumns;
    Tuple newTuple;
    for(Tuple t: tupleSet){
        for (unsigned int j = 0; j < columns.size(); ++j){
            newColumns.push_back(t.getValues().at(columns[j]));
        }
        newTuple.setValues(newColumns);
        relation.addTuple(newTuple);
        newColumns.clear();
    }
    return relation;
}

void Relation::rename(vector<string> newHeader) {
    //Relation relation(this->relationName, this->header);
    Header myHeader(newHeader);
    header = myHeader;
    //return relation;
}

void Relation::clearRelation() {
    Header blankHeader;
    relationName = "";
    tupleSet.clear();
    header = blankHeader;
}

set<Tuple> Relation::getTupleSet() {
    return tupleSet;
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