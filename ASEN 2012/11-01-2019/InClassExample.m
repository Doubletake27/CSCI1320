%% Lecture 11 - In class example - 11/8/2019
clear; close all; clc

%% Declare initial parameters
t_span = [0 1000]; % Seconds
yi_m1 = [5; 0]; % Y Position, Y Velocity 
mu = 1;

%% Integrate the function
[t_m1,y_m1] = ode45(@(t,y) vdpode(t, y, mu), t_span, yi_m1);

%% Set mu = 2
mu = 2;
[t_m2,y_m2] = ode45(@(t,y) vdpode(t, y, mu), t_span, yi_m1);

%% Plotting
figure
hold on
plot(y_m1(:,1),y_m1(:,2),'-k','Linewidth',4)
plot(y_m2(:,1),y_m2(:,2),'-r','Linewidth',4)


%% Test mu 1:10
figure 
hold on
xlim([-2,2])
for i = 1:20
    mu = i;
    [t_m1,y_m1] = ode45(@(t,y) vdpode(t, y, mu), t_span, yi_m1);
    plot(y_m1(:,1),y_m1(:,2),'-','Linewidth',1)
end