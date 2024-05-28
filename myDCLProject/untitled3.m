% Load your noisy audio signal (replace 'XN' with your actual signal)
% Replace 'sample_audio.wav' with the actual filename
filename = 'sample_audio.wav';
[y, Fs] = audioread(filename);

sound(y, Fs);

% Denoise the signal down to level 4 using wdenoise with default settings
xd = wdenoise(XN, 4);

% Plot the original and denoised signals
figure;
subplot(211)
plot(X);
title('Original Signal');
subplot(212)
plot(xd);
title('Denoised Signal');
