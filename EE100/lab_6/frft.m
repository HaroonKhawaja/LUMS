%Freshman Fourier transforms (frft) specifically tailored for freshman
%students for a better visualization and understanding of frequency
%analysis.
%Disclaimer: The transform is applicable to real signals only.
%
%Author: Momin Uppal, Department of Electrical Engineering, LUMS
%        October 5, 2020
%Usage: [X, f] = frft(x, fs)
%x:  The input time-domain signal
%fs: The sampling frequency correspondign to the time-domain signal
%X : Complex vector representing the amplitude/phase of Fourier decomposition.
%f : Frequency vector corresponding to the Fourier decomposition
%X(k): Is a complex number, with |X(k)| and angle(X(k)) representing the
%amplitude and phase, respectively, of a sinusoid of frequency f(k) that makes up the signal x(n).
%If N = length(x), f is a linearly spaced frequency vector of length ceil((N+1)/2) with each sample spaced fs/N Hz apart.

function [X, f] = frft(x, fs);
N = length(x);
X = 2*fft(x)/N;
fk = (0:N-1)/N * fs;
Ntruncated = ceil((N+1)/2);
X = X(1:Ntruncated);
X(1) = X(1)/2;
if (mod(N,2)==0)
    X(end) = X(end)/2;
end
f = fk(1:Ntruncated);

