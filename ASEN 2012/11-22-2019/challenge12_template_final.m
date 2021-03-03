%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% CODE CHALLENGE 12 - Gaussian Elimination
% 
% This challenge is an exercise in applying Gaussian Elimination in order
% to solve a system of equations. The system of equations you are looking
% to solve is as follows:
%        7x + 3y - 17z = 13
%       -4x + 2z = -2
%        4x + 3y - 9z = -5
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
% Please name according to: 
%
% SECTION 1!!! Name your file as:
%   Challenge12_S1_{group number}.m
%
% SECTION 2!!! Name your file as:
%   Challenge12_S2_{group number}.m
%
%
% STUDENT TEAMMATES
% 1. Henry Meyerson
% 2. Andrew Haskett
% 3. Parker Randolph
% 4. Mohammed Alnasser
%
% CHALLENGE AUTHOR
% Hugo Stetz
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clear; close all; clc;

%% Organizing Known Values
coeffs1 = [7 3 -17]; % Coefficients of equation 1 in x y z order
coeffs2 = [-4 0 2]; % Coefficients of equation 2 in x y z order
coeffs3 = [4 3 -9]; % Coefficients of equation 3 in x y z order

answers = [13; -2; -5]; % Answers to the three equations

AMat = [coeffs1;coeffs2;coeffs3]; % Creating an A-matrix using the given coefficients
[m,n] = size(AMat); % m for the number of rows in your A-matrix, n for the number of columns

aa = AMat;
bb = answers;

%% Using the Recursive Method to reduce the A-matrix
r=1;
for k = 2:m % Total number of iterations that must be taken
    for i = r+1:m % Marker for rows
        for j = r:n % Marker for columns
            scale_factor = AMat(i,r)/AMat(r,r);
            aa(i,j) = AMat(i,j)-AMat(r,j)*scale_factor; % Define the new values of the A matrix
        end
        bb(i) = answers(i) - answers(r)*scale_factor; % Define the new values of the b matrix
    end
    AMat = aa; % Set the new reference a matrix
    answers = bb; % Set the new reference b matrix
    r = r+1; % Increase the step number
end  

%% Next, using Backwards Substitution
...
    
z = AMat(3,3)/answers(3); % Solving for z
y = (answers(2)-z*(AMat(2,3)))/AMat(2,2); % Back-substituting z to solve for y
x = (answers(1)-z*(AMat(1,3))-y*(AMat(1,2)))/AMat(1,1); % Back-substituting z and y to solve for x



% Outputting answers
fprintf('The calculated values for our variables are:\n')
fprintf('    x = %.4f\n',x)
fprintf('    y = %.4f\n',y)
fprintf('    z = %.4f\n\n',z)


%% BONUS:
%    Solve the system using matrix methods, with the "\" operator and the
%    "inv()" operator. Compare the time it takes for these two methods with
%    the time that Gaussian elimination took.

a = [coeffs1;coeffs2;coeffs3];
b = [13; -2; -5];

% Using \ operator
tic
answersBackslash = b\a;
timeBackslash = toc;

% Using matrix inverse
tic
answersInverse = inv(a)*b;
timeInverse = toc;