#include <bits/stdc++.h>

using namespace std;

int main(){
    string s, t;
    cin >> s >> t;
    int sl, tl;
    sl = abs(s[0] - s[1]);
    tl = abs(t[0] - t[1]);

    if (sl==3) sl=2;
    if (tl==3) tl=2;
    if (sl==4) sl=1;
    if (tl==4) tl=1;

    cout << ((sl==tl) ? "Yes" : "No") << endl;
    return 0;
}