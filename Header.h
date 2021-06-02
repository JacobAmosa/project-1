#ifndef PROJECT_1_HEADER_H
#define PROJECT_1_HEADER_H
#include <string>
#include <vector>
using namespace std;

class Header {
private:
    vector<string> attributes;

public:
    Header(vector<string> parameters);
    Header();   //2 constructors to be able to set a header in the relation constructor.
    vector<string> getAttributes();
    void setAttributes(vector<string> attributes);

};


#endif //PROJECT_1_HEADER_H
