function c
m = repmat('.', 100, 100);
fp = fopen('c.txt', 'w+');
for n = 1 : 100
    fprintf(fp, [m(n, :), '\n']);
end