#include <bits/stdc++.h>
using namespace std;
int H, W;
typedef long long ll;

int main(){
    cin >> H >> W;
    vector A(H, vector<long>(W));
    vector B(H, vector<long>(W));
    map<ll, int> sA;
    int r = 0;
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            cin >> A[i][j];
            if (sA.find(A[i][j]) == sA.end()){
                sA[[i][j]] = r++;
            }
            A[i][j] = sA[A[i][j]];
        }
    }
    for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
            cin >> B[i][j];
            if (sA.find(B[i][j]) == sA.end()){
                cout << -1 << endl;
                return 0;
            }
            B[i][j] = sA[B[i][j]];
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