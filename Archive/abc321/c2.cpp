#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
int main(){
    int K;
    cin >> K;
    vector dp(10, vector<vector<ll>>(10, vector<ll>{}));
    int cnt = 0;    
    
    set<ll> st;
    for(int p = 0; p < 10; p++){
        dp[0][p].push_back(p);
        st.insert(p);
    }
    
    ll last = 1;
    for(int k = 1; k < 10; k++){
        last *= 10;
        for(int p = 0; p < 10; p++){ 
            for (int q = 0; q < p ; q++){
                for (auto v: dp[k-1][q]){
                    ll t = last * p + v;
                    dp[k][p].push_back(t);
                    st.insert(t);
                }                
            }
        }
    }

    auto it = st.begin();
    while(K--) it++;
    cout << *it << endl;
    return 0;
}