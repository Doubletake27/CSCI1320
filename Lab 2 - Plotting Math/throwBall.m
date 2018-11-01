%{
Henry Meyerson
109190761
CSCI 1320-112
Lab 2 - Plotting a Mathematical Equation
%}

clear
clear all
clc

%Constants
h = 1.5;        %meters
g = 9.8;        %meters / second
t = linspace(0,20,10000); %seconds

v = input('Initial Velocity: ');
a = input('Release Angle: ');

% Position Equations
x = v * cos(a * pi/180) * t;
y = h + (v * sin(a * pi/180) * t) - (0.5 * g * t.^2);

%When does the ball hit the ground
ground = find(y<0);
ground = ground(1);
fprintf('The ball hits the ground at a distance of %f meters. \n',x(ground))
fprintf('The ball hits the ground at a time of %f seconds. \n',t(ground))

%Base Line
xAxis = (x./x)*0;

%Plotting The Trajectory
figure();
plot(x,y,'-b',x,xAxis,'--k');
xlabel('X-Position (m)');
ylabel('Y-Position (m)');
title('Ball Trajectory');
%hold ON

print('done');
