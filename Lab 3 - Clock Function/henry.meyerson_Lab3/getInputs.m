%Henry Meyerson
%CSCI 1320 - 235
%109190761

%Input Function

function [h,m,s,f,t] = getInputs()

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
    %convertTime(h,m,s,f,t);
    
    %Check Inputs are all within correct ranges
    if ~(f == 12 || f== 24)
        fprintf('%d format is invalid: Please enter time format as 12 or 24\n',f);
        error('FORMAT ERROR')
    elseif h > 24
        fprintf('%d hours is an invalid input!\n',h);
        error('HOURS ERROR')
    elseif h > 12 && f == 12
        fprintf('%d hours is an invalid input for 12 hour time!\n',h);
        error('HOURS ERROR')
    elseif m > 60 || m < 0
        fprintf('%d minutes is an invalid input:\n Please enter a number between 1 and 60\n',m);
        error('MINUTES ERROR')
    elseif s > 60 || s < 0
        fprintf('%d seconds is an invalid input:\n Please enter a number between 1 and 60\n',s)
        error('SECONDS ERROR')
    elseif ~(t == "am" || t== "pm" || t== "DNE")
        fprintf('Please enter am or pm instead of %s\n',t)
        error('AM/PM ERROR')
    else
        %Print Old Time
        if f == 24
            fprintf('Time in 24 format is: %d:%d:%d\n',h,m,s)
        elseif f == 12
            fprintf('Time in 12 format is: %d:%d:%d %s \n',h,m,s,t)
        end
    end
end