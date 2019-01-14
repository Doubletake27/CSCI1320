%Assignment 2 - Carnot Efficiency Calculator
%Verison: A
%Author: Henry Meyerson
%Date: Sept 14, 2018

clear %clear the workspace
clc %clear the command window
close all% close all windows (graphs)

%INPUTS
% Input TC
TC = input('TC: ');
% Input TH
TH = input('TH: ');

%Run Calc Function
n = CarnotE(TC,TH);

%Print Output
fprintf('Maximum Efficiency: %.3f\n',n)

