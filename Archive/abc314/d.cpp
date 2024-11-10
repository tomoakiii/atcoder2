#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    int last = -1;
    struct txc{
        int t;
        int x;
        char c;
    };
    vector<txc> t(q);
    
    for (int i=0; i<q; i++){
        cin >> t[i].t >> t[i].x >> t[i].c;
        t[i].x--;
        if (t[i].t > 1) {
            last = i;
        }
    }

    if (last >= 0){
        for (int i=0; i<last; i++){
            if (t[i].t == 1) s[t[i].x] = t[i].c;
        }
        if (t[last].t == 2) {
            for (int i=0; i<n; i++){
                if (s[i] >= 'A' && s[i] <= 'Z') s[i] = s[i] - 'A' + 'a';
            }
        } else {
            for (int i=0; i<n; i++){
                if (s[i] >= 'a' && s[i] <= 'z') s[i] = s[i] - 'a' + 'A';    
            }        
        }
    }

    for (int i=last+1; i<q; i++){
        s[t[i].x] = t[i].c;
    }
    cout << s << endl;
    return 0;
}

