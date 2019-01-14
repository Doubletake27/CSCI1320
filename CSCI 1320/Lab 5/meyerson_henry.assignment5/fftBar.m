%Henry Meyerson
%Fast Fourier Transform Function

function [] = fftBar(soundVec,Fs)
% Only use at the first 1000 samples of the audio vector.
shortVec = soundVec(1:1000);

% Fast fourier transform
x = fft(shortVec);

% Ignore Imaginary Numbers
x = abs(x);

% Create half the origional vector
y = x(1:round(length(x)/2));

% Frequency Vector
f = Fs*(0:(length(shortVec)-1)/2)/length(shortVec);

figure;
% Plotting
bar(f,y);

%Axies
xlim([0,5000])
ylim([0,150])

%Labels
title("FFT of an Audio Signal")
xlabel("Frequency Spectrum (HZ)")
ylabel("amplitude")
end
