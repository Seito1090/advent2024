#include <bits/stdc++.h>
using namespace std;

int main(){
    string line;
    smatch match;
    int sum = 0;
    regex str_expr(R"(mul\((\d{1,3}),(\d{1,3})\))");

    // Loop over all matches
    while (getline(cin,line)){
        regex_iterator<string::iterator> rit(line.begin(), line.end(), str_expr);
        regex_iterator<string::iterator> rend;
        while (rit != rend) {
            sum += stoi(rit->str(1)) * stoi(rit->str(2));
            // Move to the next match
            ++rit;
        }
    }
    cout<<sum<<endl;
    return 0;
}
