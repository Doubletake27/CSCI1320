%Henry Meyerson
%CSCI 1320 - 235
%109190761
%Lab 3 - Clock Function
%9/27/2018

clear all
close all
clc

%Input Time
disp('Please input the time')
h = input('Hours: ');
m = input('Minutes: ');
s = input('Seconds: ');

%Determine Time Type
f = input('Enter Time Format(12/24): ');
if f==12
    t = input('Time in AM or PM (am/pm): ','s');
else
    t = "DNE";
end

%Check Inputs are all within correct ranges
if ~(f == 12 || f== 24)
    fprintf('%d format is invalid: Please enter time format as 12 or 24\n',f);
    error('FORMAT ERROR')
elseif h > 24
    fprintf('%d hours is an invalid input!\n',h);
elseif h > 12 && f == 12
    fprintf('%d hours is an invalid input for 12 hour time!\n',h);
elseif m > 60 || m < 0
    fprintf('%d minutes is an invalid input:\n Please enter a number between 1 and 60\n',m);
elseif s > 60 || s < 0
    fprintf('%d seconds is an invalid input:\n Please enter a number between 1 and 60\n',s)
elseif ~(t == "am" || t== "pm" || t== "DNE")
    fprintf('Please enter am or pm instead of %s\n',t)
else
    %Print Old Time
    if f == 24
        fprintf('Time in 24 format is: %d:%d:%d\n',h,m,s)
    elseif f == 12
        fprintf('Time in 12 format is: %d:%d:%d %s \n',h,m,s,t)
    end
    
    %Convert Time Format
    switch f
        case 12
            %Convert 12 - 24
            if t == "pm"
                h = h + 12;
            end
        case 24
            %Convert 24 - 12
            if h>= 13 && h < 24
                h = h - 12; 
                t = 'PM';
            else
                t = 'AM';
                if h == 0
                  h = h + 12;
                elseif h == 24
                  h = h - 12;
                end
            end
    end

    %Print Out New Time
    if f == 12
        fprintf('Time in 24 format is: %d:%d:%d\n',h,m,s)
    elseif f==24
        fprintf('Time in 12 format is: %d:%d:%d %s \n',h,m,s,t)
    end
end
    
