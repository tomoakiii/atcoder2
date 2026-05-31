function run
pt = fullfile(cd, "build", "testcase", "d");
d = dir(fullfile(pt, "*.in"));
for n = 1 : length(d)
    if d(n).isdir
        continue;
    end
    [~, fn, ~] = fileparts(d(n).name);
    fn2 = [fn, '.out'];
    fpw = fopen(fullfile(pt, fn2), "w+");
    call = append('./d2.out < ', fullfile(pt, d(n).name), ' > ', fullfile(pt, fn2));
    [~, cmdout] = system(call);
    fclose all;
end
