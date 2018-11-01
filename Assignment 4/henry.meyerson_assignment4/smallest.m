%Henry Meyerson
%CSCI 1320 - 235
%109190761
%Assignment 4 - Smallest
%10/05/2018

function s = smallest(v)
%Locate Zeros
z = find(v==0);
%Pre-Allocate space
b = zeros(1,length(z));
%Iterate through the different zero valuess
for i = 1:length(z)
    if z(i)== 1
        %if zero comes first
        b(i) = [];
    else
        %All other times
        b(i) = v(z(i)-1);
    end
end
%Return
s = min(b);
end