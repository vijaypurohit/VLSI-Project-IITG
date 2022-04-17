/*
	Filename: fir.cpp
		FIR lab wirtten for WES/CSE237C class at UCSD.

	INPUT:
		x: signal (chirp)

	OUTPUT:
		y: filtered output

*/

#include "fir.h"

void fir (data_t *y,  data_t x ){
	coef_t c[N] = {53, 0, -91, 0, 313, 500, 313, 0, -91, 0,53};
	// Write your code here
	static data_t shift_reg[N];
	acc_t acc;
	int i,ans;

	acc = 0;

	Shift_Accum_Loop:

//	sol0
//	Test:
//	for(i = 0; i<10; i++){
//	ans = i*i;
//	}

	//sol1 23-45 cycles
		for (i = N - 1; i >= 0; i--) {
			if (i == 0) {
				acc += x * c[0];
				shift_reg[0] = x;
			} else {
				shift_reg[i] = shift_reg[i - 1];
				acc += shift_reg[i] * c[i];
			}
		}
	//sol1 ends

	//sol2 code hoisting - 42 cycles
//		for(i=N-1; i>0; i--){
//			shift_reg[i] = shift_reg[i-1];
//			acc += shift_reg[i]*c[i];
//		}
//
//	acc += x*c[0];
//	shift_reg[0] = x;
	//sol2 ends

	//sol3 loop fission - 66 cycles
//	TDL:
//		for(i=N-1; i>0; i--){
////			#pragma HLS resource variable=shift_reg core=RAM_1P
//			#pragma HLS pipeline
////			#pragma HLS unroll factor = 2
//			shift_reg[i] = shift_reg[i-1];
//		}
////
//		shift_reg[0] = x;
//		acc = 0;
//
//	MAC:
//		for(i=N-1; i>=0; i--){
//			#pragma HLS pipeline
////			#pragma HLS unroll
//			acc += shift_reg[i]*c[i];
//		}
	//sol3 ends


	//sol4 - 35 cycles
//	TDL:
//		for(i=N-1; i>1; i-=2){
//			shift_reg[i] = shift_reg[i-1];
//			shift_reg[i-1] = shift_reg[i-2];
//		}
//		if(i == 1)
//			shift_reg[1] = shift_reg[0];
//
//		shift_reg[0] = x;
//
//		acc = 0;
////
//	MAC:
//		for(i=N-1; i>=3; i-=4){
//			acc += shift_reg[i]*c[i] + shift_reg[i-1]*c[i-1]+shift_reg[i-2]*c[i-2]+shift_reg[i-3]*c[i-3];
//		}
//
//		for(; i>=0; i--){
//			acc += shift_reg[i]*c[i];
//		}
	//sol4 ends



	*y = acc;
}

