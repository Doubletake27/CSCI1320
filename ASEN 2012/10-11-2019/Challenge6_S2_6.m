%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% CODE CHALLENGE 6 - Template Script
%
% The purpose of this challenge is to predict whether or not the Boulder
% Reservior will have to close due to a major leak.
%
% To complete the challenge, execute the following steps:
% Part 1:
% 1) Read in the data file
% 2) Set values to any constants
% 3) Perform a trapazoid integration on the data w/r.t. x
% 4) Perform a simpson's 1/3 integration on the data w/r.t. x
% 5) Display which volume measurement is more accurate and why
%
% Part 2:
% 1) Define which ?t will be used in the Euler integration
% 2) Set values to any constants and initial conditions
% 3) Propagate h with t using Euler integration
% 4) Repeat steps 1-4 with different ?t values
% 5) Display which ?t gives a more accurate result and why.
% 
%
% NOTE: DO NOT change any variable names already present in the code.
% 
% Upload your team's script to Canvas to complete the challenge.
% 
% SECTION 1!!! Name your file as:
% Challenge1_S1_{group number}.m
% SECTION 2!!! Name your file as:
% Challenge1_S2_{group number}.m
% 
% STUDENT NAMES:
% 1) Henry Meyerson
% 2) Mitchell Phelps
% 3) Walter Sabin
% 4) Evan Meany
% 
% CHALLENGE AUTHOR:
% Connie Childs
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Housekeeping
% don't "clear variables", it makes things easier to grade
close all;   % Close all open figure windows
clc;         % Clear the command window


%% Part 1

[NUM,~,~] = xlsread('depth_data.csv');

%% Set up
data = NUM; % read in .csv
x = NUM(:,1); % [ft]
d = NUM(:,2); % [ft]
L = 4836; % length of reservior [ft]

%% Trapazoid - Calculate Volume
A_trap = 0; %Its A_Trap 
for i = 1:(length(d)-1)
    step = (x(i+1)-x(i));
    A_trap = A_trap + step*(d(i+1)+d(i)/2); 
end
Vol_trap = L * A_trap; % [ft^3]

%% Simpson 1/3 - Calculate Volume
A_simp = 0;%
for i = 1:(length(d)-2)
    step = (x(i+2)-x(i))/6;
    A_simp = A_simp + step * (d(i) + 4* d(i+1) + d(i+2));
end
V_simp = L*A_simp; % [ft^3]


%% Part 2

%% Set up
del_t = 4; % various delta t values to test [days]

figure(1) % create figure

h0 = 20; % initial depth
alpha = 1.5*(10^6); % relating volume out per day to depth [ft^2/day]
dV_in = 2*(10^7); % volume in rate per day
t = 0:del_t:(100*del_t); % allocate time vector [days]
h = zeros(1,length(t)); % allocate depth vector [ft]
h(1)= h0; % set initial value in h vector

for i = 1:(length(t)-1) % Euler method
    dV_out = alpha * h(i);
    dVdt = dV_in - dV_out;
    [V, dVdh] = get_Volume(h(i),L);
    dhdt = dVdt / dVdh; % get dh/dt at this depth
    h(i+1) = h(i) + del_t*dhdt; %compute next depth value
end

fprintf('Stabilizes around %0.2f ft\n',h(end))
% plot results
plot(t,h,'-')
% labels for plot
title('Resivour Heigth vs. Time')
xlabel('Time Elapsed (days)')
ylabel('Resivour Height (ft)')



