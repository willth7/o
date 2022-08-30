//   Copyright 2022 Will Thomas
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0;
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.

//   gloria in excelsis deo

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void avr_dec(uint8_t* bin, uint64_t* bn, uint64_t* addr) {
	printf("%02x %02x    ", bin[*bn + 1], bin[*bn]);
	
	if (bin[*bn + 1] == 0 && bin[*bn] == 0) {
		printf("nop ");
		
		*bn += 2;
	}
	else if (bin[*bn + 1] == 1) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) * 2;
		uint8_t rs = ((bin[*bn]) & 15) * 2;
		
		printf("movw ");
		printf("r%u, ", rd);
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if (bin[*bn + 1] == 2) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) * 2;
		uint8_t rs = ((bin[*bn]) & 15) * 2;
		
		printf("muls ");
		printf("r%u, ", rd);
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if (bin[*bn + 1] == 3 && (bin[*bn] & 136) == 0) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) * 2;
		uint8_t rs = ((bin[*bn]) & 15) * 2;
		
		printf("mulsu ");
		printf("r%u, ", rd);
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if (bin[*bn + 1] == 3 && (bin[*bn] & 136) == 8) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) * 2;
		uint8_t rs = ((bin[*bn]) & 15) * 2;
		
		printf("fmul ");
		printf("r%u, ", rd);
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if (bin[*bn + 1] == 3 && (bin[*bn] & 136) == 128) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) * 2;
		uint8_t rs = ((bin[*bn]) & 15) * 2;
		
		printf("fmuls ");
		printf("r%u, ", rd);
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if (bin[*bn + 1] == 3 && (bin[*bn] & 136) == 136) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) * 2;
		uint8_t rs = ((bin[*bn]) & 15) * 2;
		
		printf("fmulsu ");
		printf("r%u, ", rd);
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 252) == 4) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		uint8_t rs = ((bin[*bn]) & 15) + ((bin[*bn + 1] << 3) & 16);
		
		printf("cp ");
		printf("r%u, ", rd);
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 252) == 20) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		uint8_t rs = ((bin[*bn]) & 15) + ((bin[*bn + 1] << 3) & 16);
		
		printf("cpc ");
		printf("r%u, ", rd);
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 252) == 8) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		uint8_t rs = ((bin[*bn]) & 15) + ((bin[*bn + 1] << 3) & 16);
		
		printf("sub ");
		printf("r%u, ", rd);
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 252) == 24) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		uint8_t rs = ((bin[*bn]) & 15) + ((bin[*bn + 1] << 3) & 16);
		
		printf("sbc ");
		printf("r%u, ", rd);
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 252) == 12) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		uint8_t rs = ((bin[*bn]) & 15) + ((bin[*bn + 1] << 3) & 16);
		
		if (rd != rs) {
			printf("add ");
			printf("r%u, ", rd);
			printf("r%u ", rs);
		}
		else {
			printf("lsl ");
			printf("r%u ", rd);
		}
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 252) == 28) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		uint8_t rs = ((bin[*bn]) & 15) + ((bin[*bn + 1] << 3) & 16);
		
		if (rd != rs) {
			printf("adc ");
			printf("r%u, ", rd);
			printf("r%u ", rs);
		}
		else {
			printf("rol ");
			printf("r%u ", rd);
		}
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 252) == 16) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		uint8_t rs = ((bin[*bn]) & 15) + ((bin[*bn + 1] << 3) & 16);
		
		printf("cpse ");
		printf("r%u, ", rd);
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 252) == 32) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		uint8_t rs = ((bin[*bn]) & 15) + ((bin[*bn + 1] << 3) & 16);
		
		printf("and ");
		printf("r%u, ", rd);
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 252) == 36) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		uint8_t rs = ((bin[*bn]) & 15) + ((bin[*bn + 1] << 3) & 16);
		
		printf("eor ");
		printf("r%u, ", rd);
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 252) == 40) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		uint8_t rs = ((bin[*bn]) & 15) + ((bin[*bn + 1] << 3) & 16);
		
		printf("or ");
		printf("r%u, ", rd);
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 252) == 44) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		uint8_t rs = ((bin[*bn]) & 15) + ((bin[*bn + 1] << 3) & 16);
		
		printf("mov ");
		printf("r%u, ", rd);
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else {
		printf("~byt2 %hu", ((bin[*bn + 1] << 8) + bin[*bn]));
		*bn += 2;
	}
}
