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



deque<pair<char, int>> encode_str(string str) {
    deque<pair<char, int>> ret;
    int n = (int)str.size();
    for (int l = 0; l < n;) {
        int r = l + 1;
        for (; r < n && str[l] == str[r]; r++) {};
        ret.push_back({str[l], r - l});
        l = r;
    }
    return ret;
}


string decode_str(const deque<pair<char, int>>& code) {
    string ret;
    for (auto p : code) {
        for (int i = 0; i < p.second; i++) {
            ret.push_back(p.first);
        }
    }
    return ret;
}


/* encode: ランレングス圧縮を行う*/
template <class Type> class encode{
    private:
    deque<pair<Type, int>> ret;

    public:
     encode(vector<Type> str) {
        int n = (int)str.size();
        for (int l = 0; l < n;) {
            int r = l + 1;
            for (; r < n && str[l] == str[r]; r++) {};
            ret.push_back({str[l], r - l});
            l = r;
        }
    }

    deque<pair<Type, int>> get(){
        return ret;
    }

    // vectorで返すとき
    vector<pair<Type, int>> get_vector(){
        vector<pair<Type, int>> retv(ret.size());
        rep(i,ret.size()) retv[i]=ret[i];
        return retv;
    };
};

/* decode: ランレングス圧縮の復元を行う*/
template <class Type> class decode{
    private:
    deque<Type> ret;

    public:
     decode(const deque<pair<Type, int>>& code) {
        for (auto p : code) {
            for (int i = 0; i < p.second; i++) {
                ret.push_back(p.first);
            }
        }
    }

    deque<Type> get(){
        return ret;
    };
};
