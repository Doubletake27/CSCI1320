%Henry Meyerson
%Lab 5 - Sound Effects and Analysis Tool
%Psuedocode and Skeleton Code

%Starting the Loop
m = 1;

%Select File
file = uigetfile('*.wav');

%Parse File 
%Create Audio Vector & Pull Sampling Frequency 
[soundVec,Fs] = audioread(file);

%While Loop    
while m ~= 0
    %Cleaning
    clc
    close all
    
    %GUI
    m = menu('Sound Edit Options','Echo','Compress','fftBar','Select File','Play File');
    
    switch m
        case 0
            %Exit
        case 1
            %soundEcho
            fprintf('--- Echo %s ---\n',file);
            delay = input('Echo Delay: ');
            echoGain = input('Echo Gain: '); %Consider validating for 0=<EchoGain=<1
            soundVecEcho = soundEcho(soundVec,Fs,delay,echoGain);
            
        case 2
            %Compress
            fprintf('--- Compress %s ---\n',file);
            compRatio = input('Compression Ratio: ');
            compSoundVec = compress(soundVec,Fs,compRatio);

        case 3
            %fftBar
            fprintf('--- FFT %s ---\n',file);
            fftBar(soundVec,Fs);
        
        case 4
            %Select File
            file = uigetfile('*.wav');

            %Parse File 
            %Create Audio Vector & Pull Sampling Frequency 
            [soundVec,Fs] = audioread(file);
        
            fprintf('--- %s Selected ---\n',file);
        case 5
            %Play File
            sound(soundVec,Fs);
            
            fprintf('--- Playing %s ---\n',file);
            %Prevents the program from continuing while the echo plays
            pause(length(echoVec)/Fs);
    end
end

