#include <iostream>
#include <string>
#include <fstream>

using std::string;
using std::cout;
using std::cin;
using std::ifstream;

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

int indent(std::istream &f) {
    string res = "";
    string temp = "";
    int block_num = 0;
    while (getline(f, temp)) {
        countChar(temp, '{');
    }
    return 0;
}

int main() {
    ifstream f("bad-code.cpp");
    unindent(f);
    //indent(f);
    return 0;
}