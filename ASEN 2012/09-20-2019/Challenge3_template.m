%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% CODE CHALLENGE 3 - Monte Carlo Analysis
%
% The purpose of this challenge is to perform a Monte-Carlo analysis on the
% lift generated by an aircraft.  The aircraft has the following
% characteristics:
%   Wing surface area, S = 80 m^2
%   Lift coefficient, C_L = 0.90 +- 0.03
%
% And is flying under the following conditions
%   Air density, rho = 0.653 kg/m^3
%   Airspeed, V = 100 +- 10 m/s
%
% ---------------------------------------------------------------------------------
%
% To complete the challenge, execute the following steps:
% 1) Sample S, C_L, rho, and V 10,000 times.
% 2) Calculate lift in kilonewtons for each of the 10,000 samplings/simulations.
% 3) Calculate the best estimate and error for lift and report it to the
% command window using appropriate significant figures.
% 4) Plot a histogram of L.
% E1) Calculate drag in kilonewtons for each of the 10,000
% samplings/simulations.
% E2) Make a scatterplot of Lift vs Drag.
%
% NOTE: DO NOT change any variable names already present in the code.
% 
% Upload your team's script to Canvas when complete.
% 
% NAME YOUR FILE AS Challenge3_S{section number}_{group number}.m 
%   Ex: Section 1 Group 23's file is: Challenge3_S1_23.m
%   Ex: Section 2 Group 5's file is:  Challenge3_S2_05.m
%
% STUDENT TEAMMATES
% 1) Henry Meyerson
% 2) Holland Morris
% 3) David Shaw
% 4) 
% 
% CHALLENGE AUTHOR
% Joshua Kirby
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Housekeeping (Please don't "clear all" or "clearvars", it makes grading difficult)
close all   % Close all open figure windows
clc         % Clear the command window

% 1) Sample S, C_L, rho, and V 10,000 times
% (i.e. the S variable should contain 10000 samples of the wing surface area)
N = 1e04;
S = 80;
C_L = 0.9+0.03*randn(N,1);
rho = 0.653;
V = 100+10*randn(N,1);

% 2) Calculate lift in kilonewtons for each of the 10,000 samplings/simulations.
% Given that the equation for lift is:
%       L = 0.5 * rho * V^2 * C_L * S (Newtons)
L = 0.5 * rho .* V.^2 .*C_L * S;

% 3) Calculate the best estimate and error for lift and report it to the
% command window using appropriate significant figures.
L_best = mean(L);
L_err  = std(L);

fprintf('Lift= %.2f +/- %.2f \n',L_best,L_err)

% 4) Plot a histogram (use the "histogram" command) of L with 30 bins.  Add
% annotations and labels for style points!
figure
hist(L,30);
title('Histogram')
ylabel('Number of Occurances (Out of 10,000)')
xlabel('Lift (Newtons)')

% E1) Calculate drag in kilonewtons for each of the 10,000
% samplings/simulations, given that the equation for drag is:
%       D = 0.5 * rho * V^2 * C_D * S (Newtons)
% and that C_D = 0.070 +- 0.005
C_D = 0.070+ 0.005*randn(N,1); 
D = 0.5 .* rho .* V.^2 .* C_D .* S;

% E2) Make a scatterplot of Lift vs Drag.
%
% Think about the following (no work to do):
%     - Why do you think the points are spread into an ellipse and not a
%     circle?
%     - What is the significance of the general trend/slope of the data?
%     - How could this sort of analysis be useful when dealing with more
%     complicated systems and equations?
figure
plot(L,D,'.');
title('Lift vs. Drag')
xlabel('Lift (Newtons)')
ylabel('Drag (Newtons)')



















