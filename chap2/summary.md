## Overview
creating filter which will perform DSP using Finite Impulse Response (FIR)

filters in DSP uses 2 fundamentals
- **Signal restoration**: removing noise from the signal or other distortion artifacts that may have been introduced in signal
- **Signal seperation**: Isolating different parts of the signal. ex. low pass filter removes high frequencies, band pass filter to determine presence of particular frequency.

## Background
- output signal of the impulse input signal is called impulse response
- the impulse response of an FIR filter is finite
- Convolution: Given the impulse response of an FIR filter, we can compute the output signal for any input signal.
- Above process combines impulse response (coefficients or taps) with samples of input signal and computes output signal

### convolution of N-Tap FIR filter
input signal - _x[]_

coefficients - _h[]_

![image](https://user-images.githubusercontent.com/38436564/163334484-ea3877d0-f23e-47fd-b87a-e3dd1e69b727.png)


N-tap filter requires - N multiplications and (N-1) additions

---
**Mooving average filters or box car filter**: lowpass fir filter with coefficients value being 1/N

![image](https://user-images.githubusercontent.com/38436564/163334908-cfa346bd-ca31-4d4a-8fe8-f35edff5fc65.png)

**Causal**: output function is of no future values of the input. fundamentally causality is an important property for system analysis, it is less important for a hardware implementation as a finite non-causal filter can be made causal with buffering and/or reindexing of the data.

In general, a larger value of number of taps provides more degrees of freedom when designing a filter, generally resulting in filters with better characteristics.

- larger frequency will be averaged out as we are taking average and this is kind of smoothing only.

## Base FIR Architecture
-  code is convenient for modeling a streaming architecture, since we can call it as many times as needed as more data becomes available.
-  coefficients are symmetric (mirrored around middle value) (many FIR have this symmetry) (we can take advantage for storing c[])

### code
```cpp
#define N 11
#include ”ap int.h”
typedef int coef t;
typedef int data t;
typedef int acc t;
void fir(data t ∗y, data t x) {
  coef t c[N] = {
  53, 0, −91, 0, 313, 500, 313, 0, −91, 0, 53
};
static data t shift reg[N];
acc t acc;
int i;
acc = 0;
Shift Accum Loop:
  for (i = N − 1; i >= 0; i−−) {
      if (i == 0) {
        acc += x ∗ c[0];
        shift reg[0] = x;
      } else {
        shift reg[i] = shift reg[i − 1];
        acc += shift reg[i] ∗ c[i];
      }
    }
  ∗y = acc;
  }
```
_Functionally correct, highly unoptimized code_

This function does not provide an efficient implementation of a FIR filter. It is largely sequential, and employs a significant amount of unnecessary control logic
