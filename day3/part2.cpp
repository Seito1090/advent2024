#include <bits/stdc++.h>
using namespace std;

int main(){
    string line;
    smatch match;
    int sum = 0;
    regex str_expr(R"(mul\((\d{1,3}),(\d{1,3})\)|do\(\)|don't\(\))");
    bool jump = false;
    // Loop over all matches
    while (getline(cin,line)){
        // Move to the next match
        regex_iterator<string::iterator> rit(line.begin(), line.end(), str_expr);
        regex_iterator<string::iterator> rend;

        while (rit != rend) {
            string match_str = rit->str();
            if (match_str == "do()"){
                jump = false;
            } else if (match_str == "don't()"){
                jump = true;
            } else if (!jump){
                sum += stoi(rit->str(1)) * stoi(rit->str(2));
            }
            ++rit;  
        }
    }
    cout<<sum<<endl;
    return 0;
}

