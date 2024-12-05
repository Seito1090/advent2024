#include <bits/stdc++.h>
using namespace std;

void get_input(vector<string>* ptr_in){
    string line;
    while (getline(cin, line)){
        (* ptr_in).push_back(line);
    }
}

void get_cols(vector<string>* ptr_in, vector<string>* ptr_cols ){
    int nbr_cols = (int) (*ptr_in).at(0).size();
    for (int a = 0; a < nbr_cols; a++){
        string col = "";
        for (string line : (*ptr_in)){
            col+=line.at(a);
        }
        (*ptr_cols).push_back(col);
    }
}

void get_diags(vector<string>* ptr_in, vector<string>* ptr_diag, size_t* nbr_diags){
    for (int a = 0; a < (*ptr_in).size(); a++){
        for (int b = 0; b < (*ptr_in).at(0).size(); b++){
            (*ptr_diag).at(a+b) += (*ptr_in).at(a).at(b);
            (*ptr_diag).at(((*nbr_diags) / 2 + ((*ptr_in).at(0).size() - b) + a ) - 1) += (*ptr_in).at(a).at(b);
        }
    }
}

void fuse(vector<string>*ptr_input,vector<string>* ptr_cols,vector<string>* ptr_diags){
    for (string ln : (*ptr_cols)){
        (*ptr_input).push_back(ln);
    }
    for (string ln : (*ptr_diags)){
        (*ptr_input).push_back(ln);
    }
}

int get_occ(vector<string>* ptr_input){
    //what we looking for
    int occ = 0;
    regex str_expr(R"(XMAS|SAMX)");
    for (const string& line : *ptr_input) {
        auto search_start = line.begin();
        smatch match;

        while (regex_search(search_start, line.end(), match, str_expr)) {
            occ++; // Count the match
            search_start = match[0].first + 1; // Shift one character forward for overlap
        }
    }
    return occ;
}

int main(){
    /*Get the basic input (in this case rows), 
    this serves as a way to store the input as well as copy it as needed
    and covers 2 of the 8 directions of search for regex
    */
    int occ = 0;
    vector<string> input, columns;
    vector<string>* ptr_input = &input;
    vector<string>* ptr_cols = &columns;
    get_input(ptr_input); 
    size_t nbr_diags = ((*ptr_input).size() + (*ptr_input).at(0).size() - 1) * 2;
    size_t* ptr_nbr_diags = &nbr_diags;
    vector<string> diagonals(nbr_diags, "");
    vector<string>* ptr_diags = &diagonals;
    get_cols(ptr_input, ptr_cols); get_diags(ptr_input, ptr_diags, ptr_nbr_diags); fuse(ptr_input, ptr_cols, ptr_diags); 
    occ = get_occ(ptr_input);
    cout<<occ<<endl;
    return 0;
}