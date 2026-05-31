export PATH="/home/tetitubuta/.local/bin:$PATH"
#!/bin/bash
#!/bin/bash

# 1. まず引数を受け取る（例: ~/atcoder2/Archive/abc112/a.cpp）
relative_file=$1
# 2. そのファイルがあるディレクトリの絶対パスを取得
# 一旦そのディレクトリに移動して pwd を取ることで、"~" も正しく展開されます
dir_full_path=$(cd "$(dirname "$relative_file")" && pwd)

# 3. ディレクトリの末尾（abc112）を抽出
contest_name=$(basename "$dir_full_path")

# 4. ファイル名から問題ID（a）を抽出
problem_id=$(basename "$relative_file" .cpp)


relative_path=$(dirname "$relative_file")
#contest_name=${relative_path//\//}
#problem_id=$(basename "$relative_file" .cpp)
url=https://atcoder.jp/contests/${contest_name}/tasks/${contest_name}_${problem_id}

download_dir=${relative_path}/build/testcase/${problem_id}
echo $download_dir
mkdir -p "$download_dir"

if [[ ! -e ${download_dir}/sample-1.in ]]; then
    if ! oj dl -d "$download_dir" "$url"; then
        oj login https://atcoder.jp/ || exit 1
        oj dl -d "$download_dir" "$url" || exit 2
    fi
    clear
fi

oj t -e 1e-6 -c "${relative_path}/build/${problem_id}" -d "${relative_path}/build/testcase/${problem_id}" -j 4