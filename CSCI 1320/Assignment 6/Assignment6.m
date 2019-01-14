%Henry Meyerson
%Assignment 6
clear all
clc

%PART 1 - READ and CLEAN
%Import Excel File
[~, ~, raw] = xlsread('Section9_data.xlsx');
%Answer Key
key = raw(2,7:23);
%Student IDs
ids = raw(3:end,2); %Consider switching end for 103
%Essay Scores
es = raw(3:end,5);
%Student Answers
resp = raw(3:end,7:23);
%Save data
save('grading.mat','key','ids','es','resp')

clear all
clc

%PART 2 - LOAD AND CALCULATE
%Load in variables
load grading.mat
%Calculate Grade
for i = 1:100
    multScore = 0;
    for j = 1:length(key)
        if resp{i,j} == key{j}
            multScore = multScore+1;
        end
    end
    multScore = multScore/length(key);
    %disp(multScore)
    essayScore = es{i}/15;
    %disp(essayScore)
    totalScore = (.4*essayScore + .6*multScore)*100;
    
    %Translate to Letter Grade
    if totalScore >= 93
        letter = 'A';
    elseif totalScore >= 90
        letter = 'A-';
    elseif totalScore >= 87
        letter = 'B+';
    elseif totalScore >= 83
        letter = 'B';
    elseif totalScore >= 80
        letter = 'B-';
    elseif totalScore >= 77
        letter = 'C+';
    elseif totalScore >= 73
        letter = 'C';
    elseif totalScore >= 70
        letter = 'C-';
    elseif totalScore >= 67
        letter = 'D+';
    elseif totalScore >= 63
        letter = 'D';
    elseif totalScore >= 60
        letter = 'D-';
    else
        letter ='F';
    end
     
    %disp(totalScore)
    fprintf('Student %s recieved a %s \n',ids{i},letter)
end
