#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;

int main(){
    ll H, W, N;
    cin >> H >> W >> N;
    string T;
    cin >> T;
    char G[1001][1001];
    string s;
    for(int y=0; y<H; y++){
        cin >> s;
        for(int x=0; x<W; x++){
            G[y][x] = (s[x] == '.');
        }
    }
    int x=500, y=500, minx=1001, miny=1001, maxx = 0, maxy = 0;
    vector<pair<int, int>> xy;
    xy.push_back(make_pair(y,x));
    for (int i=0; i<N; i++){
        switch(T[i]){
            case 'L':
                x-=1;
                break;
            case 'R':
                x+=1;
                break;
            case 'U':
                y-=1;
                break;
            case 'D':
                y+=1;
                break;
        }
        xy.push_back(make_pair(y,x));
        minx = min(x, minx);
        miny = min(y, miny);
        maxx = max(x, minx);
        maxy = max(y, miny);
    }
    for(auto p=xy.begin(); p!=xy.end(); p++) {
        p->first -= miny;
        p->second -= minx;
    }
    ll cnt = 0;
    for (int ys=1; ys<=H-(maxy-miny); ys++)
    for (int xs=1; xs<=W-(maxx-minx); xs++){
        bool flg=true;
        for(auto p=xy.begin(); p!=xy.end(); p++) {
            if (!G[p->first+ys][p->second+xs]){
                flg=false;
                break;
            }
        }
        if (flg) cnt++;
    }
    cout << cnt << endl;
    return 0;
}

