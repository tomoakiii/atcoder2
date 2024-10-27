#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (int i = 0; i < (n); ++i)

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<int> A(N);
    vector<int> B(M);
    rep(i,N) cin>>A[i];
    rep(i,M) cin>>B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    int Ain=0, Bin=0;
    int last = -1;
    bool ans = false;
    while(Ain < N || Bin < M){
        if (Ain == N) {
            Bin++;
            last = 1;
            continue;
        }
        if (Bin == M) {
            if (last == 0){
                ans = true;
                break;
            }
            Ain++;
            last = 0;
            continue;
        }


        if(A[Ain] > B[Bin]){
            last = 1;
            Bin++;
            continue;
        }

        if(A[Ain] < B[Bin]){
            if (last == 0){
                ans = true;
                break;
            }
            last = 0;
            Ain++;
        }
    }

    if (ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}