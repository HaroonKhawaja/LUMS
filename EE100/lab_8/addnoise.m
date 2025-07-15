function noisy_signal = addnoise(clean_signal, snr)
% NOISY_SPEECH = ADDNOISE(CLEAN_SPEECH, SNR)
%
%   ADDNOISE is used to add white gaussian noise to clean_signal so that 
%   it's signal-to-noise ratio is equal to SNR [dB].


if size(clean_signal,1) ~= length(clean_signal)
    clean_signal = clean_signal';
end

n = length(clean_signal) ;

% generate zero-mean unity-variance white gaussian noise
x = randn(n,1) ;

% ensure the mean is zero
av = sum(x)/n ;
x = x - av ;

% ensure the standard deviation is unity
var = sum(x.^2)/n ;
sd = sqrt(var) ;
x = x/sd ;

% determine the power of the clean signal
var = sum(clean_signal.^2)/n ;

% determine the noise power required to attain desired snr
ratio = 10^(snr/10) ;
sd = sqrt(var/ratio) ;

% add noise to speech
noisy_signal = clean_signal + (sd*x) ;

end