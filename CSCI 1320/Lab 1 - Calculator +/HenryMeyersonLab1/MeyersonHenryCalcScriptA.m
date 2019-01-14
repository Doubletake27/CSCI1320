%Author: Henry Meyerson
%Date: Sept 10, 2018

clear %clear the workspace
clc %clear the command window
close all% close all windows (graphs)

%INPUTS
% Input A 
varA = input('Enter First Number: ');
% Input B
varB = input('Enter Second Number: ');

%OUTPUTS
%Addition
addition = varA + varB;
fprintf('%.1f + %.1f = %.1f \n',varA,varB, addition);

%Subtraction
subtraction = varA - varB;
fprintf('%.1f - %.1f = %.1f \n',varA,varB, subtraction);

%Multiplication
multiplication = varA * varB;
fprintf('%.1f * %.1f = %.1f \n',varA,varB, multiplication);

%Division
division = varA / varB;
fprintf('%.1f / %.1f = %.1f \n',varA,varB, division);

%Power
power = varA ^ varB;
fprintf('%.1f ^ %.1f = %.1f \n',varA,varB, power);

