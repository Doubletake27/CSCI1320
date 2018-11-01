%Henry Meyerson
%CSCI 1320 - 235
%109190761
%Assignment 4 - Noisify
%10/05/2018

%Noisify
%Clean Up
clear all
close all
clc

%Constants
x = 1:20;
y = x.^.5;

%SQRT X
plot(x,y,'b')
hold on

%NOisE
n = (rand(1,20)-0.5)/10;
y2 = y + n;
plot(x,y2,'r.')

%Labels
xlabel('x')
ylabel('y')
title('x vs y and x vs y + noise')
legend('y original','y + noise')
