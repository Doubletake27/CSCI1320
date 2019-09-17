%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% CODE CHALLENGE 1 - File Reading and Data Manipulation
%
% The purpose of this program is to read in and manipulate data from a
% file.
%
% To complete the challenge, execute the following steps:
% 1) Load data from given file and print column headers to the command line
% 2) Extract data columns to meaningfully named variables
% 3) Calculate mean and standard deviation of atmospheric pressure and
%    temperature
% 4) Calculate mean and standard deviation of atmospheric air density
% 5) Calculate airspeed vector
% 6) Scatterplot airspeed vs ELD Probe Y axis position
% 
% If you have more time, attempt the following extension:
% E1) Calculate the average airspeed at each of the 11 y-positions
%     of the ELD Probe
%
% NOTE: DO NOT change any variable names already present in the code.
% 
% Upload your team's script to Canvas to complete the challenge.
%
% STUDENT TEAMMATES
% 1) Henry Meyerson
% 2) Gio Borrani
% 3) Alex Gonzalez
% 4) 
%
% CHALLENGE AUTHOR
% Joshua Kirby
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


% Housekeeping
clear all   % Clear all variables in workspace
close all   % Close all open figure windows
clc         % Clear the command window

% 1) Load data from given file and print column headers to the command line
%    (Hint: Look up xlsread and the different ways to use it, MATLAB 
%           recommends readmatrix so that may be another option)
%    (MATLAB Hint: run "doc xlsread" from command line)
%    (NOTE: There are many other functions related to loading different
%    kinds of data, which will be important for your labs next week!)

[NUM,TXT,RAW] = xlsread('datafile.csv');

% 2) Extract data columns to meaningfully named variables
% P_atm = raw(
% etc for all columns...

% 3) Calculate mean and standard deviation of atmospheric pressure and
% temperature (Hint: look up mean and std options or logical indexing)
% P_atm_bar = 
% P_atm_std = 
% 
% T_atm_bar = 
% T_atm_std = 

% 4) Calculate mean and standard deviation of atmospheric air density using
% ideal gas law:
%           P = rho*R*T, R = 286.9 J/(kg*K)
%    Hint: You can perform element-wise division using the ./ operator
R = 286.9; % J/(kg*K)
% rho_atm_bar = 
% rho_atm_std = 

% 5) Calculate airspeed vector via Pitot-static equation:
%                   2*(P_t - P_s)
%           V^2 = ------------------
%                        rho
%    Note that (P_t - P_s) is the Airspeed Differential Pressure
% V = 

% 6) Scatterplot airspeed vs ELD Probe Y axis position, excluding points
% where y > 100 mm (Hint: look up logical indexing).  Plot points as x's.
%
% The following figure call sets the lower left corner of the figure window
% to be 25% of the way up and over from the lower left corner of your
% screen and sets its size such that it takes up 50% of your screen
% horizontally and vertically.
figure('units','normalized','position',[0.25,0.25,0.5,0.5])


% E1) Calculate the average airspeed at each of the 11 y-positions
% of the ELD Probe.
% On the scatterplot from Part 5, plot the average points as dots.
ypos = 0:1:10;                  % 11 y positions of the ELD probe





