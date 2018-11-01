%Henry Meyerson
%Compress Function

function compVec = compress(soundVec,Fs,compRatio)
    %Rounds Fs to a whole number for the parser to understand
    Fs = round(Fs/compRatio);
    
    %Removes all but every compRatio+1 multiple index from soundVec and
    %write to Comp vec
    compVec = soundVec(1:compRatio:length(soundVec));
    
    %Plays The vector
    sound(compVec,Fs);

    %Prevents the program from continuing while the program plays
    pause(length(compVec)/Fs);
end