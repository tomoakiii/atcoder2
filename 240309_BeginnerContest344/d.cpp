#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 0x0F0F0F0F;

int main () {
    string T;
    cin >> T;
    int N;
    cin >> N;
    int a;
    string s;
    vector<map<string, int>> mp(N+1);
    string st = "";
    for (char c: T) {
        st = st + c;
        mp[N][st] = INF;
    }
    while (N--) {
        mp[N] = mp[N+1];
        cin >> a;
        while (a--){
            cin >> s;
            if (mp[N+1].find(s) != mp[N+1].end()) mp[N][s] = 1;
            for (auto it = mp[N+1].begin(); it != mp[N+1].end(); it++){ 
                string st = it->first + s;
                if (mp[N+1].find(st) == mp[N+1].end()) continue;
                mp[N][st] = min(mp[N][st], it->second + 1); 
            }
        }
    }
    if (mp[0][T] < INF) cout << mp[0][T] << endl;
    else cout << -1 << endl;
    return 0;
}

