%Henry Meyerson
%CSCI 1320 - 235
%109190761
%Lab 4 - Rep Vec
%10/5/2018

function r = repvec(vec,x)
%Memory Pre-Allocation
v = zeros(1,length(vec)*x);
%Iterator
for i = 1:length(vec)
    v(x*(i-1)+1:i*x) = vec(i);
end
r = v;
end