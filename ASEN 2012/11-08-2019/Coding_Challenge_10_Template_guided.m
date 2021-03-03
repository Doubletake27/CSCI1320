%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% CODE CHALLENGE 10 - Guided Template Script
%
% The purpose of this challenge is to propagate an orbit in a two body
% system for one period, and to plot it's specific energy over time.
%
% To complete the challenge, execute the following steps:
% 1) Set an initial condition vector
% 2) Propagate for exactly period of the orbit
% 3) Calculate the specific energy of the s/c vs. time
% 4) Plot the trajectory, include points for where the trajectory starts,
% ends, and the where the Earth is.
% 5) Plot the change in specific energy vs. time
%
% NOTE: DO NOT change any variable names already present in the code.
% 
% Upload your team's script to Canvas to complete the challenge.
% 
% SECTION 1!!! Name your file as:
% Challenge10_S1_{group number}.m
% SECTION 2!!! Name your file as:
% Challenge10_S2_{group number}.m
% 
% STUDENT NAMES:
% 1) 
% 2) 
% 3) 
% 4) 
% 
% CHALLENGE AUTHOR:
% Connie Childs
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% Housekeeping
clear variables; close all; clc;


%% Set up
mu = 6.6743e-20 * 5.972e24; % GM of Earth [km^3/s^2]
r = [0, 10000, 1000]'; % initial r vetor [km]
v = [0, 7.5574, 0]'; % initial v vetor [km/s]
a = -mu*(norm(v)^2-2*(mu)/norm(r))^(-1); % calculating a [km]
T = 2*pi*sqrt(a^3 / mu); % calculating T [s]
IC = [r;v]; % initial condition vector 
t = [0 T]; % time domain [s]

%% Propagate w/ ode45

[t1,c1] = ode45(@(t,C) vrODE(t,C,mu),t,IC);
r1 = c1(:,1:3);
v1 = c1(:,4:6);

%% Calculate specific energy
E = zeros(1,length(r1));
for i = 1:length(r1)
   E(i) = norm(v1(i,:))^2 - 2*mu/norm(r1(i,:));
end
energy = E;

%% Plotting
figure(1)
plot3(r(1),r(2),r(3),'.r'); % plot starting point
hold on; grid minor;
% plot3(); % plot earth
xlabel('x-position'); 
ylabel('y-position');
zlabel('z-position');
title('trajectory');
plot3(r1(:,1),r1(:,2),r1(:,3)); % plot trajectory
plot3(r1(end,1),r1(end,2),r1(end,3),'.r'); % plot ending point

figure(2)
plot(t1,E); %plot specific energy vs. time
grid minor;
xlabel('Time (seconds)');
ylabel('Specific Energy (J/kg)');
title('specific energy');

%% Function
function [ddt] = vrODE(t,C,mu)
    % Initial Conditions
    r = C(1:3);
    v = C(4:6);
    
    % Equations to integrate
    ddt(1:3,1)= v; % dr/dt
    ddt(4:6,1)=(-mu/norm(r)^3)*r;% dv/dt
end

