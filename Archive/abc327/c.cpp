#include <bits/stdc++.h>
//#include<iostream>
using namespace std;

int main(){
    int A[9][9];
    for (int i=0; i<9; i++){
        vector<bool> chk(9, false);
        for (int j=0; j < 9; j++){
            cin >> A[i][j];
            if (chk[A[i][j]-1]){
                cout << "No" << endl;
                return 0;
            }
            chk[A[i][j]-1] = true;
        }
    }
    for (int i=0; i<9; i++){
        vector<bool> chk(9, false);
        for (int j=0; j < 9; j++){
            if (chk[A[j][i]-1]){
                cout << "No" << endl;
                return 0;
            }
            chk[A[j][i]-1] = true;
        }
    }
    
    for (int i=0; i<9; i+=3){
        for (int j=0; j < 9; j+=3){
            vector<bool> chk(9, false);
            for (int x=i; x<i+3; x++){
                for (int y=i; y<i+3; y++){
                    if (chk[A[y][x]-1]){
                        cout << "No" << endl;
                        return 0;
                    }
                    chk[A[y][x]-1] = true;
                }
            }
        }
    }

    cout << "Yes" << endl;
    return 0;
    
}