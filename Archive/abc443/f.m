function f
pt = fullfile(cd, "build", "testcase", "f");
for n = 1 : 100      
    fn = sprintf('sample-%.4d.in', n);
    fpi = fopen(fullfile(pt, fn), 'w+');
    fprintf(fpi, "%d\n", n);
    fn = sprintf('sample-%.4d.out', n);
    fpo = fopen(fullfile(pt, fn), 'w+');    
    flg = true;
    flg_m = false;
    for nx = 1 : n
        x = n * nx;
        lastp = 10;
        flg = true;
        while (x > 0)
            p = rem(x,10);            
            x = floor(x / 10);
            if p <= lastp
                lastp = p;
            else
                flg = false;
                break;
            end
        end
        if flg
            flg_m = true;
            fprintf(fpo, "%d\n", n*nx);
            break
        end        
    end
    if ~flg_m
        fprintf(fpo, "-1\n");
    end
    fclose all;
end