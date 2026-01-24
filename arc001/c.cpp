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

    auto fill = [&](int i, int j)->bool{
        rep(y,8) {
            if(C[y][j] == 'Q' && y==i) return false;
            if(C[y][j] == '.') C[y][j] = 'x';
        }
        rep(x,8) {
            if(C[i][x] == 'Q' && x==j) return false;
            if(C[i][x] == '.') C[i][x] = 'x';
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
        }
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
        }
        return true;
    };

    rep(i,8)rep(j,8) {
        if(C[i][j]!='Q') continue;
        fill(i,j);
    }

    rep(i,8) {
        rep(j,8) {
            cout<<C[i][j];
        }
        cout<<endl;
    }

    auto func = [&](auto func, int i, int j, int rem)->void{
        if(j == 8) return;
        if(rem == 2) {
            cerr << "2" << endl;

        }
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
            func(func, ni, nj, rem);
        }
        C[i][j] = 'Q';
        if(fill(i,j)) func(func, ni, nj, rem-1);
        C[i][j] = '.';
    };
    func(func, 0,0,5);
    cout << "No answer" << endl;
    return 0;
}