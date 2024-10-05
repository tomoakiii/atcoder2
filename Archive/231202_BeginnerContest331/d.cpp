#include <bits/stdc++.h>
using namespace std;



int main(){
    int N, Q;
    cin >> N >> Q;
    string s;
    vector<vector<long long>> accum = vector<vector<long long>>(N+1, vector<long long>(N+1));
    long long tmp = 0;
    for (int i = 1; i <= N ; i++){
        cin >> s;
        tmp = 0;
        for (int k = 1; k <= N; k++){
            if (s[k-1] == 'B'){
                tmp++;
            }
            accum[i][k] = accum[i-1][k] + tmp;
        }
    }
    auto ccnt = [&accum](int a, int b, int c, int d){
        return accum[c+1][d+1] - accum[c+1][b] - accum[a][d+1] + accum[a][b];
    };

    vector<long long> ans(Q, 0);
    for (auto &a : ans){
        long long A, B, C, D;
        cin >> A >> B >> C >> D;
        long long vframe, hframe;
        long long mA=A%N, mB=B%N, mC=C%N, mD=D%N;
        vframe = max((long long)0, (C/N) - (A/N));
        hframe = max((long long)0, (D/N) - (B/N));
        if ((vframe>0)&&(hframe>0)){
            a += ccnt(mA, mB, N-1, N-1); //left up
            a += ccnt(0, 0, mC, mD); // right down
            a += ccnt(0, mB, mC, N-1); // left down
            a += ccnt(mA, 0, N-1, mD); // right up
            a += (vframe-1) * ccnt(0, mB, N-1, N-1); // left edge
            a += (vframe-1) * ccnt(0, 0, N-1, mD); // right edge
            a += (hframe-1) * ccnt(mA, 0, N-1, N-1); // upper edge
            a += (hframe-1) * ccnt(0, 0, mC, N-1); // lower edge
            a += ((vframe-1)*(hframe-1)) * accum[N][N];
        } else if ((vframe==0)&&(hframe>0)){
            a += ccnt(mA, mB, mC, N-1); //left up
            a += ccnt(mA, 0, mC, mD); // right up
            a += (hframe-1) * ccnt(mA, 0, mC, N-1); // upper edge
        } else if ((vframe>0)&&(hframe==0)){
            a += ccnt(mA, mB, N-1, mD); //left up
            a += ccnt(0, mB, mC, mD); // left down
            a += (vframe-1) * ccnt(0, mB, N-1, mD); // left edge
        } else {
            a += ccnt(mA, mB, mC, mD); //only one
        }

    }
    for (auto a : ans){
        cout << a << endl;
    }

    cout << endl;
    return 0;
}
