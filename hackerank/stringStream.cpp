#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
	
    
    stringstream ss(str);
    vector<int> r;
    char ch;
    int tmp;
    while(ss >> tmp){
        r.push_back(tmp);
        ss >> ch;
    }
    return r;
}

int main() {
    string str;
    cin >> str;
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }
    
    return 0;
}
