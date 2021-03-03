%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% CODE CHALLENGE 9 - Guided Template Script
%
% The purpose of this challenge is to predict whether or not the Boulder
% Reservior will have to close due to a major leak.
%
% To complete the challenge, execute the following steps:
% 1) Set an initial condition velocity
% 2) Set values for constants
% 3) Propagate freefall w/ drag for 20 seconds
% 4) Plot the velocity vs. time
% 5) Calculate the change kinetic energy vs. time
% 6) Plot the change in kinetic energy vs. time
%
% NOTE: DO NOT change any variable names already present in the code.
% 
% Upload your team's script to Canvas to complete the challenge.
% 
% SECTION 1!!! Name your file as:
% Challenge9_S1_{group number}.m
% SECTION 2!!! Name your file as:
% Challenge9_S2_{group number}.m
% 
% STUDENT NAMES:
% 1) Henry Meyerson
% 2) Gio Borrani
% 3) Julia Sheeran
% 4) Carlin Hornbostel
% 
% CHALLENGE AUTHOR:
% Connie Childs
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Housekeeping
clear variables; close all; clc;

%% Set up
m = 0.3; % mass of object [kg]
g = 9.8066; % acceleration of gravity [m/s^2]
rho = 1.225; % air density [kg/m^3]
Cd = 1.2; % coefficient of drag
A = 0.0046; % object's cross-sectional area [m^2]
v0 = 0; % [m/s]

t_lim = [0 20]; % time bounds [s]
IC = v0; % initial condition

%% Propagate with ode45

[t,v] = ode45(@(t,v) dvdt(m,g,rho,Cd,A,v), t_lim, IC);

%% Plot Velocity vs. Time
figure(1);
subplot(121);
plot(t,v); % plot starting point

%% Calculate Kinetic Energy 
% KE = 1/2 mv^2
E = 0.5 * m * v.^2; % [J]

%% Plot Kinetic Energy vs. Time
subplot(122);
plot(t,E); % plot starting point

%% Acceleration = dv/dt
% dv/dt = g - D/m
function dv = dvdt(m,g,rho,Cd,A,v)
    acc = g - 0.5*rho*(v^2)*Cd*A*sign(v)/m;
    dv = acc; 
end 
