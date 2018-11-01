function y = transposemat(x);
%transposemat(x) returns the transpose of matrix x
r1 = [x(1,1);x(1,2);x(1,3)];
r2 = [x(2,1);x(2,2);x(3,3)];
r3 = [x(3,1);x(3,2);x(3,3)];
y = [r1,r2,r3];
end
%{
Henry Meyerson
109190761
CSCI 1320-100 (-112)
Assignment 3
%}