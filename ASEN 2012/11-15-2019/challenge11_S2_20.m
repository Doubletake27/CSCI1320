%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% CODE CHALLENGE 11 - Zero Finding with MATLAB
% 
% This challenge is an exercise in finding the zeros of functions in
% MATLAB. There are several functions you can use to do this - use the
% `help` function to learn more. You will find the zeros of the van der
% Waals equation of a gas state for CO2. 
%
% Please name according to: 
%
% SECTION 1!!! Name your file as:
% Challenge11_S1_{group number}.m
% SECTION 2!!! Name your file as:
% Challenge11_S2_{group number}.m
%
% STUDENT TEAMMATES
% 1. Henry Meyerson
% 2. Tanisha Anand
% 3. Fernando Chavez Arroyo
% 4. Parker Randolph
%
% CHALLENGE AUTHOR
% Riley Reid
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

clear; close all; clc;

% Given:
% The equation and constants for CO2. a and b are specific to CO2.
a = 3.59; % atm*L^2/mol^2
b = 0.0427; % l/mol
R = 0.082; % L*atm/K*mol
P = 10; % atm
T = 300; % K

% The anonymous function
vdw = @(V) (P-(a./(V.^2))).*(V-b)-R*T; 
% The derivative of the anonymous function with respect to V (only use for 
% Newton's method)
vdw_dot = @(V) (a*(V-2*b))./(V.^3) + P;

% 1. Create a volume vector linearly spaced between -1 and 3 
% with atleast 300 values 
v = -1:.01:3;

% 2. Plot the van der Waals function vs. volume. Change the scale of the
% plot to get a better look around the roots.
figure
plot(v,vdw(v))
ylim([-50,50])

% 3. From looking at the plot, how many roots are there, and what are they
% approximately? 

% There are 3 Roots

% 4. Use Newton's method to find the roots and then display them (simplest 
% approach may be a separate while loop for each root, but if you'd like to 
% implement a different approach, you may do so). Also, find time to compute 

% set the tolerance
tol = .001;
t1_newton = tic;   % find time using tic
r1 = 2.5;            % guess for the largest root

% implement while loop here
do = true;
while do
    ri = r1;
    r1 = ri - vdw(r1)/vdw_dot(r1);
    do = (vdw(r1)-vdw(ri)) >= tol;
end

r2 = -0.25;            % guess for the smallest root
do = true;
while do
    ri = r2;
    r2 = ri - vdw(r2)/vdw_dot(r2);
    do = (vdw(r2)-vdw(ri)) >= tol;
end

r3 = 0.01;            % guess for the smallest root
do = true;
while do
    ri = r3;
    r3 = ri - vdw(r3)/vdw_dot(r3);
    do = (vdw(r3)-vdw(ri)) >= tol;
    disp(2)
end

% repeat for the other roots

t2_newton = toc(t1_newton);    % after finding all roots, find time elapsed using toc

% display the roots
newtonv_roots = [r1,r2,r3];

% 5. Find and display the roots of the polynomial using the `roots` function.
% also find the time to compute
t1_roots = tic;
C =[10, -25.027,-3.59,0.153293];
v_roots = roots(C);
t2_roots = toc(t1_roots);

% 6. Find and display the roots of the polynomial using the `fzero` function.
% also find the time to compute
tic;
v_fzero1 = fzero(vdw,2.5);
v_fzero2 = fzero(vdw,-0.25);
v_fzero3 = fzero(vdw,.01);
t2_fzero = toc;

% 7. Find and display the roots of the polynomial using the `fsolve` function.
% also find the time to compute
t1_fsolve = tic;
v_fsolve = fsolve(vdw,[-0.25 0.01 2.5]);
t2_fsolve = toc(t1_fsolve);

% 8. Plot the roots that you calculated on the plot created in 2. Just
% choose one set of the roots (4, 5, 6, or 7)
hold on
plot(v_fsolve,vdw(v_fsolve),'ro')

% 9. On a new figure, plot the time elapsed for each method implemented as a 
% bar chart - which method is fastest? 
figure
x = categorical({'Newton','Roots','fzero','fsolve'});
x=reordercats(x,{'Newton','Roots','fzero','fsolve'});
y = [t2_newton,t2_roots,t2_fzero,t2_fsolve];
bar(x,y)

% set(gca,'xtick',1:4,'xticklabel',['Newton';'Roots';'fzero';'fsolve'])
title('Computation time by function')
ylabel('Computationl time (s)')











