#include <bits/stdc++.h> 
using namespace std;

int main(){
    int sizeTot, similarity = 0;
    cin>>sizeTot;
    cin.ignore();
    unordered_map<int,int> occA;
    unordered_map<int,int> occB;
    for (int a = 0; a < sizeTot; a++){
        int nbA,nbB;
        cin>>nbA>>nbB;
        occA[nbA]++;
        occB[nbB]++;
    }
    for (const auto& [key, value] : occA) {
        similarity += (value*occB[key])*key;
    }
    cout<<similarity<<endl;
    return 0;
}