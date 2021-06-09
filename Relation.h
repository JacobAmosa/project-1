#ifndef PROJECT_1_RELATION_H
#define PROJECT_1_RELATION_H
#include "Header.h"
#include "Tuple.h"
#include <vector>
#include <set>
#include <string>
using namespace std;

class Relation {
private:
    string relationName = "";
    Header header;
    set<Tuple> tupleSet;
    vector<int> uniqueColumns;
    vector<pair<int, int>> matchingColumns;
public:
    Relation(string name, Header newHeader);
    Relation();
    void addTuple(Tuple tuple);
    void toString();
    void clearRelation();
    Header getHeader();
    set<Tuple> getTupleSet();
    //takes a constant and selects at a certain index.
    Relation select1(int index, string value);
    //takes two indices where the variables are the same and makes sure their values are the same.
    Relation select2(int index1, int index2);
    //only keeps certain columns of each tuple.
    Relation project(vector<int> columns);

    //renames the header of a relation.
    void rename(vector<string> newHeader);
    //join function joins two relations (LAB4)
    Relation join(Relation myRelation);
    Header combineHeaders(Header header1, Header header2);
    bool isJoinable(vector<pair<int, int>> matchingColumns, Tuple tuple1, Tuple tuple2);
    Tuple combineTuples(Tuple tuple1, Tuple tuple2);
    void unite(Relation inputRelation);
};


#endif //PROJECT_1_RELATION_H
