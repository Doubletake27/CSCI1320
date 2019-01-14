%Henry Meyerson
%CSCI 1320 - 235
%109190761

%Display Function

function [] = displayTime(h,m,s,f,t)
    %Print Out New Time
    if f == 12
        fprintf('Time in 24 format is: %d:%d:%d\n',h,m,s)
    elseif f==24
        fprintf('Time in 12 format is: %d:%d:%d %s \n',h,m,s,t)
    end
end