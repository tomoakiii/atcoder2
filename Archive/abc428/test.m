function test
pt = fullfile(cd, "build", "testcase", "d");
for n = 1 : 10000
    T= 1;
    fname = sprintf("test-%.3d.in", n);
    fpw = fopen(fullfile(pt, fname), "w+");
    fprintf(fpw, "%d\n", T);
    for tt = 1 : T
        rand1 = rand(1);
        rand1 = floor(rand1 * 2e8);
        rand2 = rand(1);
        rand2 = floor(rand2 * 5e9);
        fprintf(fpw, "%d %d\n", rand1, rand2);
    end
    fclose all;
    run;
end
