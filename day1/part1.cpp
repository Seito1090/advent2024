#include <bits/stdc++.h> 
using namespace std;

int main(){
    int sizeTot, totDist = 0;
    cin>>sizeTot;
    cin.ignore();
    int* valuesA = new int[sizeTot];
    int* valuesB = new int[sizeTot];
    for (int a = 0; a < sizeTot; a++){
        cin>>valuesA[a]>>valuesB[a];
    }
    sort(valuesA, valuesA+sizeTot);
    sort(valuesB, valuesB+sizeTot);
    for (int b = 0; b < sizeTot; b++){
        totDist += abs(valuesA[b] - valuesB[b]);
    }
    delete[] valuesA;
    delete[] valuesB;
    cout<<totDist<<endl;
    return 0;
}