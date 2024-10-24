dir_path=`cd $(dirname ${0}) && pwd`
dir_path=$dir_path\/\*
echo "$dir_path"
dirs=`find $dir_path -maxdepth 0 -type d`

for dir in $dirs; do
    echo "$dir"
    if [ "$dir" = ".git" ]; then
        echo success
    else
        find $dir -type f -regextype posix-extended ! -regex '^.+\.[^/]*$' -exec rm -f {} \;
    fi
done
