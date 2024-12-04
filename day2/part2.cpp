#include <bits/stdc++.h>
using namespace std;

vector<char> copy_string(string line){
    vector<char> cp_line(line.begin(), line.end());
    cp_line.push_back('\0');
    return cp_line;
}

void remove_idx(vector<int>* vec, int idx){
    vec->erase(vec->begin() + idx);
}

vector<int> get_values(string line, string delimiter){
    string cp_line = string(copy_string(line).data());
    vector<int> values;
    int pos = 0;
    while ((pos = cp_line.find(" ")) != string::npos){
        int number = stoi(cp_line.substr(0, pos));
        cp_line.erase(0, pos+ delimiter.size());
        values.push_back(number);
    }
    values.push_back(stoi(cp_line));
    return values;
}

int check_vector(vector<int> vec){
    bool increasing = vec.at(1) - vec.at(0) > 0;
    int diff;
    for (int a = 0; a < vec.size() - 1; a++){
        diff = vec.at(a+1) - vec.at(a);
        if ((increasing && diff < 0) || (!increasing && diff > 0)){
            return 0;
        }
        if (!increasing) diff = abs(diff);
        if (diff > 3 || diff < 1) return 0;
    }
    return 1;
}

int check(string line){
    vector<int> values = get_values(line, " ");
    //Init check (if it is a normal good case)
    if (check_vector(values) == 0){
        //it's not good :(
        for (int a = 0; a < values.size(); a ++){
            vector<int> tmp = get_values(line, " ");
            vector<int>* ptr_tmp = &tmp;
            remove_idx(ptr_tmp,a);
            if (check_vector(tmp) == 1) return 1;
        }
        return 0;
    } else {
        return 1;
    }
}

//BUG, not removing the first ever item on the line ex 12 10 11 13 15 18 20
int main(){
    int in_len = 0, nbr_safe = 0, ad;
    string line;
    cin >> in_len;
    cin.ignore();
    for (int a = 0; a < in_len; a++){
        getline(cin, line);
        nbr_safe += check(line);
    }
    cout << nbr_safe <<endl;
    return 0;
}
