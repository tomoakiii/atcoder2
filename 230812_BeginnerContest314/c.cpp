#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main(){
    map<int, vector<int>> mp;
    int N;
    cin >> N;
    vector<int> man(N); 
    for (int i=0; i<N; i++){
        int c;
        cin >> c;
        man[i] = c;
        for (int j=0; j<c; j++){
            int v;
            cin >> v;
            mp[v].push_back(i);
        }
    }

    int x;
    cin >> x;
    int mn = 1000;
    for (auto s: mp[x]){
        mn = min(mn, man[s]);
    }
    if (mn == 1000){
        cout << 0 << endl;
        return 0;
    }
    vector<int> ans;
    for (auto s: mp[x]){
        if (man[s] == mn) {
            ans.push_back(s);
        }
    };
    cout << ans.size() << endl;
    for (auto a: ans) cout << (a+1) << " ";


    return 0;
}

