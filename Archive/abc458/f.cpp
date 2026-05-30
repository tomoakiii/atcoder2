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

class AhoCorasick {
private:
    struct Node {
        // children[c]: 文字 c ('a'-'z') への遷移先ノードのインデックス。存在しない場合は 0
        std::vector<int> children;
        // fail: マッチング失敗時の遷移先ノードのインデックス
        int fail;
        // output: このノードに到達したときに検出されるキーワードのインデックスリスト
        std::vector<int> output;

        Node() : children(26, 0), fail(0) {}
    };

    std::vector<Node> nodes;
    std::vector<std::string> words; // 登録された単語の元文字列を保持

public:
    AhoCorasick() {
        // ルートノード (インデックス 0) を初期化
        nodes.emplace_back();
    }

    // 1. キーワードの挿入 (Trie木の構築)
    void insert(const std::string& word) {
        int word_id = words.size();
        words.push_back(word);

        int current = 0; // ルートから開始
        for (char ch : word) {
            int c = ch - 'a'; // 'a'を0、'z'を25とするインデックスに変換
            if (nodes[current].children[c] == 0) {
                nodes[current].children[c] = nodes.size();
                nodes.emplace_back();
            }
            current = nodes[current].children[c];
        }
        // 単語の終端ノードに単語のIDを登録
        nodes[current].output.push_back(word_id);
    }

    // 2. Failure Link と Output Link の構築 (BFS)
    void build() {
        std::queue<int> que;

        // ルート直下 (深さ1) のノードを初期化
        for (int c = 0; c < 26; ++c) {
            if (nodes[0].children[c] != 0) {
                int child = nodes[0].children[c];
                nodes[child].fail = 0; // 深さ1のfailはすべてルート(0)
                que.push(child);
            }
        }

        // BFS（幅優先探索）で深さ2以降のノードのfailを決めていく
        while (!que.empty()) {
            int current = que.front();
            que.pop();

            for (int c = 0; c < 26; ++c) {
                if (nodes[current].children[c] != 0) {
                    int child = nodes[current].children[c];

                    // 親のfail先をたどり、同じ文字 `c` の遷移先を探す
                    int fail_node = nodes[current].fail;
                    while (fail_node > 0 && nodes[fail_node].children[c] == 0) {
                        fail_node = nodes[fail_node].fail;
                    }

                    // 遷移先があればそこをセット、なければルート(0)をセット
                    if (nodes[fail_node].children[c] != 0) {
                        nodes[child].fail = nodes[fail_node].children[c];
                    } else {
                        nodes[child].fail = 0;
                    }

                    // fail先のoutputを自身のoutputにマージ (Dictionary Link)
                    int child_fail = nodes[child].fail;
                    nodes[child].output.insert(
                        nodes[child].output.end(),
                        nodes[child_fail].output.begin(),
                        nodes[child_fail].output.end()
                    );

                    que.push(child);
                }
            }
        }
    }

    // 3. テキストからキーワードを検索
    // 返り値: { (テキスト内の開始インデックス, マッチした単語), ... }
    std::vector<std::pair<int, std::string>> search(const std::string& text) {
        std::vector<std::pair<int, std::string>> results;
        int current = 0;

        for (int i = 0; i < text.length(); ++i) {
            int c = text[i] - 'a';

            // 現在の文字の遷移先がない場合、failリンクをたどる
            while (current > 0 && nodes[current].children[c] == 0) {
                current = nodes[current].fail;
            }

            // 次のノードへ遷移（遷移先がなければルートのまま）
            if (nodes[current].children[c] != 0) {
                current = nodes[current].children[c];
            } else {
                current = 0;
            }

            // マッチしたキーワードがあれば結果を格納
            for (int word_id : nodes[current].output) {
                const std::string& word = words[word_id];
                int start_idx = i - word.length() + 1;
                results.push_back({start_idx, word});
            }
        }

        return results;
    }
};


int main(){
    ll N, K;
    cin >> N >> K;
    vector<string> S(N);
    rep(i,K) cin>>S[i];
    AhoCorasick AC();
    rep(i,N) AC.insert(S[i]);
    AC.build();
    return 0;
}