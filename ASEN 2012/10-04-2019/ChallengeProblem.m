%10/4/2019
clc
clear 
%Challenge Problem 1
    disp("Challenge Problem 1")

    %Find Q, M, b
    A = [10,1;30,1];
    d = [5;10];
    
    t = (A'*A)^(-1) *A'*d; %[m,b]
    m=t(1);
    b =t(2);
    
    U = .5;    %Uncertainty is now +/- 0.5
    US = U^2;
    W = [1/US,0;0,1/US];
    
    Q = (A'*W*A)^(-1);
     
    em = sqrt(Q(1,1));
    eb = sqrt(Q(2,2));
    
    fprintf("m = %0.2f +/- %0.2f\n",m,em)
    fprintf("b = %0.1f +/- %0.1f\n",b,eb)
    
clear 
%Challenge Problem 2
    disp("Challenge Problem 2")

    A = [10,1;20,1;30,1];
    d = [5;10;10];
    
    t = (A'*A)^(-1) *A'*d; %[m,b]
    m=t(1);
    b =t(2);
    
    U = 1; %uncertainty +/-1
    US = U^2;
    
    W = zeros(length(A));
    for i = 1:length(A)
      W(i,i) = 1/US;  
    end
    
    Q = (A'*W*A)^(-1);

    em = sqrt(Q(1,1));
    eb = sqrt(Q(2,2));
    
    fprintf("m = %0.2f +/- %0.2f\n",m,em)
    fprintf("b = %0.1f +/- %0.1f\n",b,eb)
    
%Clicker Problem 1



