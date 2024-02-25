int main() {
    using namespace std;
    unsigned N, M;
    cin >> N >> M;
    // 電車の情報を保持する構造体
    struct train {
        unsigned from, to;
        unsigned long first_train;
        unsigned long interval;
        unsigned long count;
        unsigned long distance;
        // time_limit までに駅 to へ到着するような列車の出発時刻のうち最小のものを求める
        // 存在しなければ nullopt を返す
        optional<unsigned long> get_last_train(unsigned long time_limit) const {
            if (time_limit < first_train + distance)
                return nullopt;
            return first_train + min(count - 1, (time_limit - first_train - distance) / interval) * interval;
        }
    };
    vector<vector<train>> train_info(N);
    for (const auto _ : views::iota(0U, M)) {
        unsigned long l, d, k, c;
        unsigned A, B;
        cin >> l >> d >> k >> c >> A >> B;
        train_info[--B].push_back({--A, --B, l, d, k, c});
    }
    priority_queue<pair<unsigned long, unsigned>> pq;
    vector<unsigned long> ans(N);
    // 駅 N に十分遅い時間にいるところから探索を始める
    pq.emplace(ans.back() = numeric_limits<unsigned long>::max(), N - 1);
    while (!empty(pq)) {
        // まだ探索していない駅のうちもっとも遅くまでいられる駅を探索する
        const auto[time_limit, now]{pq.top()};
        pq.pop();
        if (ans[now] > time_limit)continue;
        // 駅 now に向かう電車情報に対して
        for (const auto &e : train_info[now]) {
            const auto next{e.from};
            const auto next_time{e.get_last_train(time_limit)};
            // 駅 next の最終時刻 ≥ 駅 now の最終時刻に間に合う電車の発射時刻
            if (next_time && ans[next] < *next_time) // 更新できるなら
                pq.emplace(ans[next] = *next_time, next); // 優先度つきキューに入れる
        }
    }
    for (const auto d : ans | views::take(N - 1))
        if (d)
            cout << d << endl;
        else
            cout << "Unreachable" << endl;
    return 0;
}