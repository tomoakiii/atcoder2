#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;


int main(){
    int N;
    cin >> N;
    vector<int> S(N);
    string s;
    cin >> s;
    for(int i=0; i<N; i++){
        S[i] = s[i]-'0';
    }
    sort(S.begin(), S.end());
    vector<int> S2(N);
    
    auto func = [&]() -> bool {        
        for(int i=0; i<N; i++){
            if (S[i] != S2[i]) return false;
        }
        return true;
    };
    
    ll cnt = 0;
    ll mx = 0, k = 1;
    for (int i = 0; i < N; i++){        
        mx += S[i] * k;
        k *= 10;
    }
    for (ll x = 0; x * x <= mx; x++){
        ll xx = x * x;
        for (int i=0; i<N; i++){
            S2[i] = xx%10;
            xx/=10;
        }
        sort(S2.begin(), S2.end());
        if (func()){
            cnt++;
        } 
    }  

    

    cout << cnt << endl;
    return 0;
}