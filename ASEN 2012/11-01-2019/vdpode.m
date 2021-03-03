function [dydt] = vdpode(t, yi, mu)
    % The purpose of this function is to integrate a 2nd over function to
    % solve a van der Pol oscilator
    
    % Se the current states
    y = yi(1); % Position
    y_dot = yi(2); % Velocity 
    
    %Equations to integrate
    dydt(1) = y_dot; % Velocity (dr/dt)
    dydt(2) = -y+mu*(1-y^2)*y_dot;  % Acceleration (dv/dt)
    
    % Put it into a column vector (transpose)
    dydt = dydt'; 
end 
