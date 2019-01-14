%Henry Meyerson
%Sound Echo Function

function echoVec = soundEcho(soundVec,Fs,delay,echoGain);
    %Converts number of seconds into a index size
    delaySamples = Fs*delay;
    
    %Formats the basic vectors to be manipulated
    soundVec = soundVec';
    delayVec = zeros(1,delaySamples);
    
    %Creates the echo
    respVec = echoGain * [delayVec,soundVec];
    soundVec = [soundVec,delayVec];
    
    %Adds the vectors
    echoVec = soundVec + respVec;
    
    %Transposes echoVec into a playable format
    echoVec = echoVec';
    
    %Plays echoVec
    sound(echoVec,Fs);
    
    %Prevents the program from continuing while the echo plays
    pause(length(echoVec)/Fs);
end