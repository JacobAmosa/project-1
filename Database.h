#ifndef PROJECT_1_DATABASE_H
#define PROJECT_1_DATABASE_H
#include <map>
#include <string>
#include "Relation.h"
using namespace std;

class Database {
private:
    map<string, Relation> database;

public:
    Relation& findDatabase(string table);
    map<string, Relation> getDatabase();
    void setDatabase(string tableName, Relation relation);
};


#endif //PROJECT_1_DATABASE_H
