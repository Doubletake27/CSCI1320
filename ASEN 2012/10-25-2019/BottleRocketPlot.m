close all
clear 
clc

%Load Results
load result.mat
s = result(1); 
% t
% ma
% Va
% mr
% x
% y
% z
% vx
% vy
% vz
% rangeft
% angle
l = length(s.t);

% Plot position
figure
plot3(s.x,s.y,s.z)
title('Rocket Position')
xlabel('X-Position (feet)')
ylabel('Y-Position (feet)')
zlabel('Height (feet)')
grid on
hold on

labels = {'Launch','Apogee','Landing'};
x = [s.x(1) s.x(s.z==max(s.z)) s.x(end)];
y = [s.y(1) s.y(s.z==max(s.z)) s.y(end)];
z = [s.z(1) max(s.z) s.z(end)];
plot3(x,y,z,'co')
text(x,y,z,labels,'VerticalAlignment','bottom','HorizontalAlignment','center')


% Direction Arrow
% pt = 50;
% quiver3(s.x(pt), s.y(pt), s.z(pt), s.x(pt+1), s.y(pt+1), s.z(pt+1))
