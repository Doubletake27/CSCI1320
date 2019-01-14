function p = throwBall_func(v, a, M)
h = 1.5; %Starting height of 1.5 meters 
g = 9.8; %Gravity Defines at 9.8 m/s/s
t = linspace(0,M,10000);
y = h + (v * sin(a * pi/180) * t) - (0.5 * g * t.^2);
p = ~isempty(find(y<0));
end
%{
Henry Meyerson
109190761
CSCI 1320-100 (-112)
Assignment 3
%}