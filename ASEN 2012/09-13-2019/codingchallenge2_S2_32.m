%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% CODE CHALLENGE 2 - 
%
% The purpose of this challenge is to estimate atmospheric pressure in
% Boulder CO using a pressure model and measurements, and compare the two
% through error analysis and statistics. 
%
% To complete the challenge, execute the following steps:
% 1) Load the given dataset
% 2) Extract altitude and pressure data
% 3) Determine standard deviation, variance, mean, and 
%    standard error of the mean of the pressure data
% 4) Using information given about the instrument, find uncertainty associated
%    with altitude measurements
% 5) Use the model to predict pressure measurements at each altitude in the
%    data set, along with propagated uncertainty
% 6) Compare results and discuss
% E1) Repeat for larger measurement uncertainty in altitude
%
% NOTE: DO NOT change any variable names already present in the code.
% 
% Upload your team's script to Canvas to complete the challenge.
% 
% NAME YOUR FILE AS Challenge1_S1_{group number}.m 
%  ***CHANGE TO S1 or S2 AND INCLUDE YOUR GROUP# ****
% 1) Henry Meyerson
% 2) Josie Johnson
% 3) Adam BuenCamino
% 4) Benjamin Chupik
% 
% CHALLENGE AUTHOR
% Riley Reid
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

% Housekeeping
clear all   % Clear all variables in workspace
close all   % Close all open figure windows
clc         % Clear the command window

% 1) Load data from given file and print column headers to the command line

raw = readtable('pressure_Boulder.csv');
headers = raw.Properties.VariableNames;

for i = 1:length(headers)
    fprintf("%s ",headers{i});
    %disp(headers{i});
end

disp("");
% 2) Extract just the altitude and station pressure data columns to meaningfully 
%    named variables

h = raw{:,3};
p = raw{:,2};

% 3) Determine the standard deviation, variance, mean, and 
%    standard error of the mean (sem) of the pressure data

stdev_p = std(p);
var_p = stdev_p^2;

mean_p = mean(p);

sem_p = stdev_p/sqrt(length(p));

% 4) The altitude measurements were taken using an instrument that displayed
%    altitude to the nearest tenth of a meter. What is the associated 
%    absolute uncertainty with these measurements? 

h_uncertainty =  0.05;

% 5) Using the altitude measurements and uncertainty, predict pressure with 
%    the follwing model
%    First, propagate uncertainty BY HAND before calculating uncertainty
%    for each value (is it different for each calculation?)

%                   P_est =   P_s * e^(-k*h)               
%    Assume P_s is 101.7 ± 0.4 kPa and k is 1.2*10^(-4) [1/m] 

P_s = 101.7;       % ± 0.4 kPa
k = 1.2*10^(-4);   % 1/m

P_est = P_s * exp(-k.*h);

P_sig = sqrt((exp(-k.*h)*.4).^2+(-k*P_s.*exp(-k.*h)*h_uncertainty).^2);

% 6) Display the predicted pressure from the model with it's associated uncertainty and
% the average pressure with the it's standard error of the mean from the
% data

% Discuss the accuracy of the model and whether or not you think the
% model agrees with the measurements (include some of your discussion as a
% comment - 1 or 2 lines will suffice)
dp = 2;

results  = table(round(P_est,dp),round(P_sig,dp));
P_data = [num2str(mean_p) '  ±  ' num2str(sem_p) '   kPa'];
disp(results);
disp(P_data);

%No, the model does not match the measurements because the data is
%discrepent with the model

%E1 Repeat steps 4-6, but assume the altitude measurements were taken on a
%   lower precision instrument that only displayed altitude to nearest 10
%   meters
%   How does this change the results and comparison ? 

% h_uncertainty_new =    % m

h_uncertainty =  5;

P_s = 101.7;       % ± 0.4 kPa
k = 1.2*10^(-4);   % 1/m

P_est = P_s * exp(-k.*h);

P_sig = sqrt((exp(-k.*h)*.4).^2+(-k*P_s.*exp(-k.*h)*h_uncertainty).^2);

results  = table(round(P_est,dp),round(P_sig,dp));
P_data = [num2str(mean_p) '  ±  ' num2str(sem_p) '   kPa'];
disp(results);
disp(P_data);
