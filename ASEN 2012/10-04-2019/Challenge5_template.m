%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% CODE CHALLENGE 5 - Linear Least-Squares Fit
%
% The purpose of this program is to calculate the equation of the best fit
% line for a data set using linear least-squares fitting.
%
% To complete the challenge, finish the code below to:
% 1) load data from csv file
% 2) find linear best fit coefficients and associated uncertainty
% E1 plot the original data along with the best fit line 
% E2 add errorbars for fit uncertainty to this plot from the data and from
%    the linear regression parameters
%
% NOTE: DO NOT change any variable names already present in the code.
% 
% Upload your team's script to Canvas when complete.
% 
% NAME YOUR FILE AS Challenge5_S{section number}_{group number}.m 
%   Ex: Section 1 Group 23's file is: Challenge3_S1_23.m
%   Ex: Section 2 Group 5's file is:  Challenge3_S2_05.m
%
% STUDENT TEAMMATES
% 1) Henry Meyerson
% 2) Collin Rasbid
% 3) Ryan Jones
% 4) 
% 
% CHALLENGE AUTHOR
% Riley Reid
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Housekeeping (Please don't "clear all" or "clearvars", it makes grading difficult)
close all   % Close all open figure windows
clc         % Clear the command window

% Load and extract the time and velocity vectors from the data
[data,~,~] = xlsread("Challenge5_data.csv");
t = data(:,1); % [s]
v = data(:,2); % [m/s]

% Find number of data points in the vectors
N = length(t);

% Find linear best fit coefficients m and b
% Create A matrix
A = [t,ones(N,1)];

% Create d matrix
d = v;

% Create W matrix (hint: type <help diag> in command line)
W = eye(N)/(.1^2);

% Solve for Q matrix
Q = (A'*W*A)^(-1);

% Solve for t_hat matrix and extract m and b paramters
t_hat = (A'*A)^(-1) *A'*d;
m = t_hat(1);
b = t_hat(2);

% extract uncertainty in m and uncertainty in b from Q matrix
m_error = sqrt(Q(1,1));
b_error = sqrt(Q(2,2));

% display acceleration with associated uncertainty and the intial velocity
% with associated uncertainty with CORRECT SIG FIGS
fprintf("a = %0.2f +/- %0.2f m/s^2 \n",m,m_error)
fprintf("v0 = %0.1f +/- %0.1f m/s \n",b,b_error)
disp('This is likely the Moon')

% Extension
% Find predicted velocity values using your linear fit equation
v_predicted = (t*m)+b;

% On the same plot, do the following:
% 1. plot the velocity data vs time as a scatter plot 
figure
plot(t,v,'.b')
% 2. plot predicted velocity vs time as a line 
hold on
% plot(t,v_predicted,'-r') -- Moved lower for clarity
% 3. title your plot so that it indicates what celestial body this data
%    simulates
title('Velocity vs Time')
xlabel('Time(s)')
ylabel('Velocity(m/s)')
% 4. Add measured velocity error bars and predicted velocity error bars to 
%    the plot (hint - this will involve error propagation calculations
v_err = .1*ones(N,1);
errorbar(t,v,v_err,'both','.b')
viscircles([t,v],v_err,'Color','b','LineWidth',.5,'LineStyle',':')


plot(t,v_predicted,'-r')

v_predicted_error = b_error*ones(N,1);
 
legend('Velocity','Velocity Predicted','Vel Error')


