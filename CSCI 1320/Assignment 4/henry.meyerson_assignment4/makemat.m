%Henry Meyerson
%CSCI 1320 - 235
%109190761
%Assignment 4 - MakeMat
%10/05/2018

function m = makemat(x,y)
%Set Size
a = size(x);
b = size(y);

%Check Matrix
if ~(a(1) == 1 || a(2) == 1)
    error('Please input a VECTOR')
end
if ~(b(1) == 1 || b(2) == 1)
    error('Please input a VECTOR')
end

%Transpose
if(a(1)~=1)
    x = x';
    a = size(a);
end
if(b(1)~=1)
    y = y';
    b = size(b);
end

%Match Lengths
if a(2) > b(2)
    %Make y Longer
    z = a(2)-b(2);
    z = zeros(1,z)
    y = [y,z];
elseif b(2) > a(2)
    %Make x Longer
    z = b(2)-a(2);
    z = zeros(1,z)
    x = [x,z];
end

%RETURN
m = [x',y'];

end