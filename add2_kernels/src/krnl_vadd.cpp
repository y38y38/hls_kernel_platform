#include <stdint.h>

extern "C" {


void krnl_vadd(uint32_t* in1, uint32_t* in2, uint32_t* out, int size) {
	int i;
	for (i=0;i<size;i++) {
		out[i] = in1[i] + in2[i];
	}
}
}
