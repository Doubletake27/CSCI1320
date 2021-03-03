%Runge Kutta Integration
clc
clear 
%dy/dx = g(x,y) = x^2 y 
%K1 = g(x,y);  slope of the start of the time point
%K2 = g(x + .5 delta x, y + .5 k1 delta x)
%K3 = g(x + .5 delta x, y + .5 k2 delta x)
%K4 = g(x + delta x, y + k3 delta x)

%Y(i+1) = Yi + delta x / 6 * (k1 + 2k2 + 2k3 + k4)


% Initial Conditions
x = 0;
y = 1;
dx = 0.1; % Delta x
fprintf('   X0: %.2f Y0: %d\n',x,y)


% Loop Begin
n =3;

for i = 1:n
    fprintf('--------------------\n')

    k1 = gxy(x,y);
    k2 = gxy(x + 0.5*dx,y + 0.5*k1*dx);
    k3 = gxy(x + 0.5*dx,y + 0.5*k2*dx);
    k4 = gxy(x + dx,y + k3*dx);

    y = y + (dx/6) * (k1 + 2*k2 + 2*k3 + k4); %y(i+1) 
    
    x = x+dx;
    fprintf('K1: %.8f K2: %.8f\n',k1,k2)
    fprintf('K3: %.8f K4: %.8f\n',k3,k4)
    fprintf('   X%.0f: %.2f Y%.0f: %.8f\n',i,x,i,y)
    
end

% ---- G(x,y) ----
function g = gxy(x,y)
    g = double(x^2) * double(y);
end
