%Inverse Freshman Fourier transforms (invfrft) specifically tailored for freshman
%students for a better visualization and understanding of frequency
%analysis.
%Disclaimer: The transform is applicable to real signals only.
%
%Author: Momin Uppal, Department of Electrical Engineering, LUMS
%        October 5, 2020
%Usage: [x, t] = invfrft(X, f, fs)
%X : Complex vector representing the amplitude/phase of Fourier decomposition.
%f : Frequency vector corresponding to the Fourier decomposition
%where X(k) is a complex number, with |X(k)| and angle(X(k)) representing the
%amplitude and phase, respectively, of a sinusoid of frequency f(k) that makes up the desired time domain signal x(n).
%If N = length(x), f is a linearly spaced frequency vector of length ceil((N+1)/2) with each sample spaced fs/N Hz apart.
%x:  The desired time-domain signal corresponding to the Fourier
%coefficients
%t: The corresponding time vector for x, spaced linearly at 1/fs seconds 


function [x, t] = invfrfft(X, f, fs)
X(1) = X(1)*2;
if f(end) == fs/2   %--- the original time-domain sequence was of even length
    X(end) = X(end) * 2;
    if (size(X,1) == 1)
        Xc = [X flip(conj(X(2:end-1)))];
    else
        Xc = [X; flip(conj(X(2:end-1)))];
    end;
else
   if (size(X,1) == 1)
       Xc = [X flip(conj(X(2:end)))];
   else
       Xc = [X; flip(conj(X(2:end)))]; 
   end
end

x = ifft(Xc);
N = length(x);
x = x * N/2;
x = real(x);
t = (0:N-1)/fs;