function garbage_clear
dname = cdhome;
garbage_clear_fnc(dname);


function garbage_clear_fnc(dname)
d = dir(dname);
for n=1:length(d)
    if(d(n).name(1) == '.')
        continue;
    end
    fpath = fullfile(dname, d(n).name);
    if(isfolder(fpath)) 
        garbage_clear_fnc(fpath);
    else
       [p, f, e] = fileparts(fpath);
       if(isempty(e))
           delete(fpath);
       end
    end
end