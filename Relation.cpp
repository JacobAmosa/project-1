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

Relation Relation::join(Relation myRelation) {
        Relation newRelation(this->relationName, combineHeaders(this->header, myRelation.header));
        for(Tuple tuple1: this->tupleSet){
            for (Tuple tuple2: myRelation.tupleSet){
                if (isJoinable(matchingColumns, tuple1, tuple2)){
                    newRelation.addTuple(combineTuples(tuple1, tuple2));
                }
            }
        }
        matchingColumns.clear();
        uniqueColumns.clear();
        return newRelation;
}

bool Relation::isJoinable(vector<pair<int, int>> matchingColumns, Tuple tuple1, Tuple tuple2) {
    for(pair<int, int> match : matchingColumns){
        if (tuple1.getValues()[match.first] != tuple2.getValues()[match.second]){
            return false;
        }
    }
    return true;
}

Tuple Relation::combineTuples(Tuple tuple1, Tuple tuple2) {
    for (unsigned int i = 0; i < uniqueColumns.size(); i++){
        tuple1.addValue(tuple2.getValue(uniqueColumns[i]));
    }
    return tuple1;
}

Header Relation::combineHeaders(Header header1, Header header2) {
    Header newHeader(header1.getAttributes());
    vector<string> headerVector = header1.getAttributes();
    bool exists = false;
    for (unsigned int i = 0; i < header2.getAttributes().size(); i++){
        exists = false;
        for (unsigned int j = 0; j < header1.getAttributes().size(); j++){
            if (header2.getAttributes()[i] == header1.getAttributes()[j]){
                exists = true;
                matchingColumns.push_back(pair<int, int>(j, i));
            }
        }
        if (!exists){
            uniqueColumns.push_back(i);
            headerVector.push_back(header2.getAttributes()[i]);
            newHeader.setAttributes(headerVector);
        }
    }
    return newHeader;
}

void Relation::unite(Relation inputRelation){
    for(Tuple tuple : inputRelation.getTupleSet()){
        if (tupleSet.insert(tuple).second){
            cout << " ";
            tuple.toString(header);
            cout << endl;
        }
    }
}

void Relation::toString() {
    int counter = 0;
    for(Tuple t: tupleSet){
        for (unsigned int i = 0; i < t.getValues().size(); ++i){
            if (t.getValues().size() > i + 1){
                cout << header.getAttributes()[i] << "=" << t.getValues()[i] << ",";
                counter++;
            }
            else {
                cout << header.getAttributes()[i] << "=" << t.getValues()[i];
                counter++;
            }
        }
        if (counter != 0){
            cout << endl;
        }
    }
}

Header Relation::getHeader() {
    return header;
}
