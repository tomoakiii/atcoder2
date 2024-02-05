#include <bits/stdc++.h>
using namespace std;
int H, W;

int rowcomp(vector<vector<long>> &a, int l){
    long rmin = 10e9;
    map<long, vector<int>> minq;
    for (int i=l; i<H; i++){
        rmin = min(rmin, a[i][l]);
        minq[a[i][l]].push_back(i);
    }
    for (auto m: minq[rmin]){
        
    }

    for (int i=l; i<H; i++){
        if (a[i][l] == rmin){
            minq = 
        }
    }


    for (int i=0; i<H; i++){
        pair<long, int> tminA = {0, 0}, tminB = {0, 0};
        for (int j=0; j<W; j++){
            if (tminA.first > A[i][j]){
                tminA = 
            }
        }
    }    
}

int main(){
    cin >> H >> W;
    vector<vector<long>> A(H, vector<long>(W));
    vector<vector<long>> B(H, vector<long>(W));
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            cin >> A[i][j];
        }    
    }
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            cin >> B[i][j];
        }    
    }

    auto Acp = A;
    auto Bcp = B;
    for (int i=0; i<H; i++){
        sort(Acp[i].begin(),Acp[i].end());
        sort(Bcp[i].begin(),Bcp[i].end());
    }

    cout << buyT << endl;
    return 0;
}