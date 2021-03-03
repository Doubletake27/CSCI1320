%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%% Guiding Code for General Implementation of Gaussian Elimination %%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Housekeeping
clear all
close all
clc

%%  Set up the matricies describing our system
a = [3 5 1;
    1 4 2;
    2 2 3]; % Left-hand sides of our equations

b = [16; 15; 15]; % Right-hand sides of our equations

[m,n] = size(a); % m is the number of rows, n is the number of columns
r = 1; % step number

% Initialize the new A matrix, called AA, and b matrix, called bb
aa = a;
bb = b;

%% Using the Recursive Method to reduce our A-matrix, starting at step 1, row 2
for k = 2:m % Total number of iterations that must be taken
    for i = r+1:m % Marker for rows
        for j = r:n % Marker for columns
            scale_factor = a(i,r)/a(r,r);
            aa(i,j) = a(i,j)-a(r,j)*scale_factor; % Define the new values of the A matrix
        end
        bb(i) = b(i) - b(r)*scale_factor; % Define the new values of the b matrix
    end
    a = aa; % Set the new reference a matrix
    b = bb; % Set the new reference b matrix
    r = r+1; % Increase the step number
end

% Output answer to check with hand calculations
aa
bb

%% Using backwards substitution to solve for our answers
x = zeros(n,1);
...