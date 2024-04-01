#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;


int main(){
    int N, Q;
    cin >> N >> Q;    
    int x;
    vector<int> stt(N, -1);
    vector<ll> acm(Q+1, 0);
    vector<ll> ans(N, 0);
    ll cacm=0, pacm=0;
    for (int i = 1; i < Q+1; i++){
        cin >> x;
        x--;
        acm[i] = pacm;
        if (stt[x] == -1){
            stt[x] = i-1;
            cacm++;
        } else {            
            ans[x] += (acm[i-1] - acm[stt[x]]);
            stt[x] = -1;
            cacm--;
        }
        acm[i] += cacm;
        pacm = acm[i];
    }
    for (int x=0; x<N; x++){
        if (stt[x] != -1){
            ans[x] += (acm[Q] - acm[stt[x]]);            
        }
    }
    for (auto a: ans) cout << a << " ";
    cout << endl;
    return 0;
}