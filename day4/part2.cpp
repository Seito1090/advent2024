#include <bits/stdc++.h>
using namespace std;

vector<string> read_input(){
    string line;
    vector<string> input;
    while (getline(cin,line)){
        input.push_back(line);
    }
    return input;
}

int check_X(vector<string>* ptr_input){
    int count = 0;
    int y = (*ptr_input).size();
    int x = (*ptr_input).at(0).size();
    for (int row = 1; row < y - 1; row++){
        for (int col = 1; col < x -1; col++){
            if ((*ptr_input).at(row).at(col)=='A'){
                if (((((*ptr_input).at(row+1).at(col+1)=='M'&&(*ptr_input).at(row-1).at(col-1)=='S')) ||
                 ((*ptr_input).at(row+1).at(col+1)=='S'&&(*ptr_input).at(row-1).at(col-1)=='M')) &&
                 ((((*ptr_input).at(row+1).at(col-1)=='M'&&(*ptr_input).at(row-1).at(col+1)=='S')) ||
                 ((*ptr_input).at(row+1).at(col-1)=='S'&&(*ptr_input).at(row-1).at(col+1)=='M'))){
                    count++;
                 }
            }
        }
    }
    return count;
}

int main(){
    vector<string> input = read_input();
    vector<string>* ptr_input = &input;
    cout<<check_X(ptr_input)<<endl;
    return 0;
}
