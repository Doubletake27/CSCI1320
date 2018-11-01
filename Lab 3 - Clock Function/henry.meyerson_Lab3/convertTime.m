%Henry Meyerson
%CSCI 1320 - 235
%109190761

%Convert Function

function [h,m,s,f,t] = convertTime(h,m,s,f,t)
    %Convert Time Format
    switch f
        case 12
            %Convert 12 - 24
            if t == "pm"
                h = h + 12;
            end
        case 24
            %Convert 24 - 12
            if h>= 13 && h < 24
                h = h - 12; 
                t = 'PM';
            else
                t = 'AM';
                if h == 0
                  h = h + 12;
                elseif h == 24
                  h = h - 12;
                end
            end
    end
    %displayTime(h,m,s,f,t);
end