#include <bits/stdc++.h>
using namespace std;

int main(){
    string line;
    smatch match;
    getline(cin,line);
    regex str_expr(R"(mul\((\d{1,3}),(\d{1,3})\))");

    // Create a regex_iterator to loop over all matches
    regex_iterator<string::iterator> rit(line.begin(), line.end(), str_expr);
    regex_iterator<string::iterator> rend;

    // Loop over all matches
    while (rit != rend) {
        // Print the full match
        cout << "Full match: " << rit->str(0) << endl;

        // Print the start index of the match
        cout << "Start index: " << rit->position(0) << endl;

        // Print the captured groups (x and y values)
        cout << "x = " << rit->str(1) << ", y = " << rit->str(2) << endl;

        // Move to the next match
        ++rit;
    }
    cout<<"hey"<<endl;
    return 0;
}
