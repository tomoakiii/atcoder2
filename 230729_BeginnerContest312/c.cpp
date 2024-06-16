#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;
int main(){
    int N, M;
    cin >> N >> M;
    vector<ll> A(N), B(M);
    for (int i=0; i<N; i++) cin >> A[i];
    for (int i=0; i<M; i++) cin >> B[i];
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    A.push_back(INF);
    B.push_back(INF);
    int s=0, b=M;
    int cs=-1, cb=-1;
    ll x = min(A[0], B[0]);
    while (true){
        while(A[cs+1] <= x){
            cs++;
            s++;
        }
        while(B[cb+1] < x){
            cb++;
            b--;
        }
        if (s >= b){
            cout << x << endl;
            return 0;
        }

        if (A[cs+1] <= B[cb+1]) {
            x = A[cs+1];
        } else {
            x = B[cb+1]+1;
        }
    }
    return 0;
}

