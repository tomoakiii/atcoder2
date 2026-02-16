function rmd
p = fullfile(cd, "build", "testcase", "e");
for n=1:1
    fp = fopen(fullfile(p, sprintf("hand-%d.in", n)), "w+");
    fpo = fopen(fullfile(p, sprintf("hand-%d.out", n)), "w+");
    n = 30;
    r = rand(1,n);
    r = floor(r * 1000);
    fprintf(fp, "%d 100\n", n);
    fprintf(fp, "%d ", r);
    fprintf(fp, "\n");
    answ = 0;        
    for i=1:n
        for j=i:n
            m = zeros(n+1,1);
            indx = 0;
            for k = i : j
                indx = indx + 1;
                m(indx) = r(k);
            end
            m(indx + 1 : end) = [];
            m = sort(m);
            flg = true;
            for k = 1 : length(m) - 1
                if m(k+1) - m(k) < 100
                    flg = false;
                end
            end
            if flg
                answ = answ + 1;
            end
        end
    end
    fprintf(fpo, "%d\n", answ);
end