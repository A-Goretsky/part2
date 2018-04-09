#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::cout;
using std::cin;
using std::ifstream;
using std::endl;

string removeLeadingSpaces(string line) {
    for (int i = 0; i < (int) line.size(); i++) {
        if (line[i] != ' ')
            return line.substr(i) + "\n";
    }
    return line;
}

int countChar(string line, char c) {
    int ctr = 0;
    for (int i = 0; i < (int) line.size(); i++) {
        if (line[i] == c) {
            ctr++;
        }
    }
    return ctr;
}

int unindent(std::istream &f) {
    string temp = "";
    while (getline(f, temp)) {
        cout << removeLeadingSpaces(temp);
    }
    return 0;
}

string addingLeadingSpaces(string line, int tab){
    string new_l = line;
    for (int i = tab; i > 0; --i){
        new_l = "\t" + new_l;
    }
    return new_l;
}

int indent(std::istream &f) {
    string temp = "";
    int block_num = 0; //net count of indents
    while (getline(f, temp)) {
        cout << addingLeadingSpaces(removeLeadingSpaces(temp), block_num); // add indent after dedent
        block_num += countChar(temp, '{');
        block_num -= countChar(temp, '}');
    }
    return 0;
}

int main() {
    ifstream f("bad-code.cpp");
    unindent(f);
    f.close();
    ifstream fid("bad-code.cpp");
    indent(fid);
    return 0;
}