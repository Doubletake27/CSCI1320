%Assignment 2 - Calculator +
%Verison: B
%Author: Henry Meyerson
%Date: Sept 13, 2018

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
addition = addFunc(varA,varB);
fprintf('%.1f + %.1f = %.1f \n',varA,varB, addition);

%Subtraction
subtraction = subtractFunc(varA,varB);
fprintf('%.1f - %.1f = %.1f \n',varA,varB, subtraction);

%Multiplication
multiplication = multFunc(varA, varB);
fprintf('%.1f * %.1f = %.1f \n',varA,varB, multiplication);

%Division
division = divFunc(varA,varB);
fprintf('%.1f / %.1f = %.1f \n',varA,varB, division);

%Power
power = powerFunc(varA,varB);
fprintf('%.1f ^ %.1f = %.1f \n',varA,varB, power);

%Task 1
T1 = quotientInBoundsFunc(varA,varB);
fprintf('Task 1) %d \n',T1);


