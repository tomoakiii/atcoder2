#include <atcoder/all>
#include <bits/stdc++.h>
using namespace std;
using namespace atcoder;
#define rep(i,n) for (ll i = 0; i < (n); ++i)
template<typename T> inline bool chmax(T &a, T b) { return ((a < b) ? (a = b, true) : (false)); }
template<typename T> inline bool chmin(T &a, T b) { return ((a > b) ? (a = b, true) : (false)); }

typedef long long ll;
const ll INF = 0x0F0F0F0F0F0F0F0F;
const int INFi = 0x0F0F0F0F;

int main(){
    vector C(8,vector<char>(8));
    rep(i,8)rep(j,8) cin>>C[i][j];

    auto fill = [&](int i, int j, vector<vector<char>> &C)->bool{
        rep(x,8) {
            if(x == j) continue;
            if(C[i][x] == 'Q')  return false;
            if(C[i][x] == '.')  C[i][x] = 'x';
        }
        int ct = 0;
        for(int y=i+1; y<8; y++) {
            ct++;
            int x = j+ct;
            if(x<8) {
                if(C[y][x]=='Q') return false;
                if(C[y][x]=='.') C[y][x]='x';
            }
            x = j-ct;
            if(x>=0) {
                if(C[y][x]=='Q') return false;
                if(C[y][x]=='.') C[y][x]='x';
            }
            x = j;
            if(C[y][x]=='Q') return false;
            if(C[y][x]=='.') C[y][x]='x';
        }
        ct = 0;
        for(int y=i-1; y>=0; y--) {
            ct++;
            int x = j+ct;
            if(x<8) {
                if(C[y][x]=='Q') return false;
                if(C[y][x]=='.') C[y][x]='x';
            }
            x = j-ct;
            if(x>=0) {
                if(C[y][x]=='Q') return false;
                if(C[y][x]=='.') C[y][x]='x';
            }
            x = j;
            if(C[y][x]=='Q') return false;
            if(C[y][x]=='.') C[y][x]='x';
        }
        return true;
    };


    auto debug = [&]()->void{
        cerr<<endl;
        rep(i,8) {
            rep(j,8) {
                cerr<<C[i][j];
            }
            cerr<<endl;
        }
        cerr<<endl;
    };

    rep(i,8)rep(j,8) {
        if(C[i][j]!='Q') continue;
        if(!fill(i,j,C)) {
            cout << "No Answer" << endl;
            return 0;
        }
    }
    debug();
    auto func = [&fill](auto func, int i, int j, int rem, vector<vector<char>> C)->void{
        if(j == 8) return;
        if(rem == 0) {
            rep(i,8) {
                rep(j,8) {
                    if(C[i][j]=='Q') cout<<'Q';
                    else cout<<'.';
                }
                cout<<endl;
            }
            exit(0);
        }
        int ni=i+1, nj=j;
        if(ni==8) {
            ni=0; nj++;
        }
        if(C[i][j] != '.') {
            func(func, ni, nj, rem, C);
            return;
        }
        auto C2 = C;
        C2[i][j] = 'Q';
        if(fill(i,j,C2)) {
            func(func, ni, nj, rem-1, C2);
        }
        func(func, ni, nj, rem, C);
    };
    func(func, 0,0,5,C);
    cout << "No Answer" << endl;
    return 0;
}