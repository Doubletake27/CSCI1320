%{
Henry Meyerson
109190761
CSCI 1320-100 (-112)
Assignment 3 - Task 4
Easter Sunday Calculator
%} 

% Set Year
y = input('Please enter the year: ');

% Math
% Step 2
a = mod(y,19);
% Step 3
b = fix(y/100);
c = mod(y,100);
% Step 4
d = fix(b/4);
e = mod(b,4);
% Step 5
g = fix((8 * b + 13)/25);
% Step 6
h = mod(19 * a + b - d - g + 15, 30);
% Step 7
j = fix(c/4);
k = mod(c,4);
% Step 8
m = fix((a+11*h)/319);
% Step 9
r = mod((2 * e + 2 * j - k - h + m + 32),7);
% Step 10
n = fix((h - m + r + 90)/25);
% Step 11
p = mod((h - m + r + n + 19),32);

% Print Out
fprintf('In %d, Easter Sunday fell on %d/%d.\n',y,n,p)


