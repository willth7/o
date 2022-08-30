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
	printf("%04lx %04lx    ", (*bn >> 16) & 65535, (*bn) & 65535); //address
	printf("%02x %02x    ", bin[*bn + 1], bin[*bn]); //machine code
	
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
		
		printf("cpc ");
		printf("r%u, ", rd);
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 252) == 20) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		uint8_t rs = ((bin[*bn]) & 15) + ((bin[*bn + 1] << 3) & 16);
		
		printf("cp ");
		printf("r%u, ", rd);
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 252) == 8) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		uint8_t rs = ((bin[*bn]) & 15) + ((bin[*bn + 1] << 3) & 16);
		
		printf("sbc ");
		printf("r%u, ", rd);
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 252) == 24) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		uint8_t rs = ((bin[*bn]) & 15) + ((bin[*bn + 1] << 3) & 16);
		
		printf("sub ");
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
	else if ((bin[*bn + 1] & 252) == 156) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		uint8_t rs = ((bin[*bn]) & 15) + ((bin[*bn + 1] << 3) & 16);
		
		printf("mul ");
		printf("r%u, ", rd);
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 240) == 48) {
		uint8_t rd = (bin[*bn] >> 4) & 15;
		uint8_t k = ((bin[*bn]) & 15) + ((bin[*bn + 1] << 4) & 240);
		
		printf("cpi ");
		printf("r%u, ", rd);
		printf("%u ", k);
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 240) == 64) {
		uint8_t rd = (bin[*bn] >> 4) & 15;
		uint8_t k = ((bin[*bn]) & 15) + ((bin[*bn + 1] << 4) & 240);
		
		printf("subi ");
		printf("r%u, ", rd);
		printf("%u ", k);
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 240) == 80) {
		uint8_t rd = (bin[*bn] >> 4) & 15;
		uint8_t k = ((bin[*bn]) & 15) + ((bin[*bn + 1] << 4) & 240);
		
		printf("sbci ");
		printf("r%u, ", rd);
		printf("%u ", k);
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 240) == 96) {
		uint8_t rd = (bin[*bn] >> 4) & 15;
		uint8_t k = ((bin[*bn]) & 15) + ((bin[*bn + 1] << 4) & 240);
		
		printf("ori ");
		printf("r%u, ", rd);
		printf("%u ", k);
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 240) == 112) {
		uint8_t rd = (bin[*bn] >> 4) & 15;
		uint8_t k = ((bin[*bn]) & 15) + ((bin[*bn + 1] << 4) & 240);
		
		printf("andi ");
		printf("r%u, ", rd);
		printf("%u ", k);
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 240) == 224) {
		uint8_t rd = (bin[*bn] >> 4) & 15;
		uint8_t k = ((bin[*bn]) & 15) + ((bin[*bn + 1] << 4) & 240);
		
		printf("ldi ");
		printf("r%u, ", rd);
		printf("%u ", k);
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 210) == 128) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		uint8_t k = ((bin[*bn]) & 7) + ((bin[*bn + 1] << 1) & 24) + ((bin[*bn + 1]) & 32);
		
		printf("ldd ");
		printf("r%u, ", rd);
		if (bin[*bn] & 8)  {
			printf("y, ");
		}
		else {
			printf("z, ");
		}
		printf("%u ", k);
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 210) == 130) {
		uint8_t rs = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		uint8_t k = ((bin[*bn]) & 7) + ((bin[*bn + 1] << 1) & 24) + ((bin[*bn + 1]) & 32);
		
		printf("std ");
		if (bin[*bn] & 8)  {
			printf("y, ");
		}
		else {
			printf("z, ");
		}
		printf("%u, ", k);
		printf("r%u ", rs);
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 144) && ((bin[*bn] & 15) == 0)) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		uint16_t k = (bin[*bn + 2]) + (bin[*bn + 3] << 8);
		
		printf("lds ");
		printf("r%u, ", rd);
		printf("%u ", k);
		*bn += 2;
		
		printf("\n%04lx %04lx    ", (*bn >> 16) & 65535, (*bn) & 65535);
		printf("%02x %02x    ", bin[*bn + 1], bin[*bn]);
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 146) && ((bin[*bn] & 15) == 0)) {
		uint8_t rs = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		uint16_t k = (bin[*bn + 2]) + (bin[*bn + 3] << 8);
		
		printf("sts ");
		printf("%u, ", k);
		printf("r%u ", rs);
		*bn += 2;
		
		printf("\n%04lx %04lx    ", (*bn >> 16) & 65535, (*bn) & 65535);
		printf("%02x %02x    ", bin[*bn + 1], bin[*bn]);
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 144) && ((bin[*bn] & 15) == 1)) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("ld ");
		printf("r%u, ", rd);
		printf("z, 1 ");
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 144) && ((bin[*bn] & 15) == 2)) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("ld ");
		printf("r%u, ", rd);
		printf("z, -1 ");
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 144) && ((bin[*bn] & 15) == 9)) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("ld ");
		printf("r%u, ", rd);
		printf("y, 1 ");
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 144) && ((bin[*bn] & 15) == 10)) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("ld ");
		printf("r%u, ", rd);
		printf("y, -1 ");
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 144) && ((bin[*bn] & 15) == 12)) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("ld ");
		printf("r%u, ", rd);
		printf("x");
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 144) && ((bin[*bn] & 15) == 13)) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("ld ");
		printf("r%u, ", rd);
		printf("x, 1 ");
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 144) && ((bin[*bn] & 15) == 14)) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("ld ");
		printf("r%u, ", rd);
		printf("x, -1 ");
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 146) && ((bin[*bn] & 15) == 1)) {
		uint8_t rs = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("st ");
		printf("z, 1, ");
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 146) && ((bin[*bn] & 15) == 2)) {
		uint8_t rs = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("st ");
		printf("z, -1, ");
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 146) && ((bin[*bn] & 15) == 9)) {
		uint8_t rs = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("st ");
		printf("y, 1, ");
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 146) && ((bin[*bn] & 15) == 10)) {
		uint8_t rs = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("st ");
		printf("y, -1 ");
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 146) && ((bin[*bn] & 15) == 12)) {
		uint8_t rs = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("st ");
		printf("x, ");
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 146) && ((bin[*bn] & 15) == 13)) {
		uint8_t rs = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("st ");
		printf("x, 1, ");
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 146) && ((bin[*bn] & 15) == 14)) {
		uint8_t rs = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("st ");
		printf("x, -1, ");
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 144) && ((bin[*bn] & 15) == 4)) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("lpm ");
		printf("r%u, ", rd);
		printf("z ");
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 144) && ((bin[*bn] & 15) == 5)) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("lpm ");
		printf("r%u, ", rd);
		printf("z, 1 ");
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 144) && ((bin[*bn] & 15) == 6)) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("elpm ");
		printf("r%u, ", rd);
		printf("z ");
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 144) && ((bin[*bn] & 15) == 7)) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("elpm ");
		printf("r%u, ", rd);
		printf("z, 1 ");
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 146) && ((bin[*bn] & 15) == 4)) {
		uint8_t rs = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("xch ");
		printf("z, ");
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 146) && ((bin[*bn] & 15) == 5)) {
		uint8_t rs = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("las ");
		printf("z, ");
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 146) && ((bin[*bn] & 15) == 6)) {
		uint8_t rs = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("lac ");
		printf("z, ");
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 146) && ((bin[*bn] & 15) == 7)) {
		uint8_t rs = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("lat ");
		printf("z, ");
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 144) && ((bin[*bn] & 15) == 15)) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("pop ");
		printf("r%u ", rd);
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 146) && ((bin[*bn] & 15) == 15)) {
		uint8_t rs = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("push ");
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 148) && ((bin[*bn] & 15) == 0)) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("com ");
		printf("r%u ", rd);
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 148) && ((bin[*bn] & 15) == 1)) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("neg ");
		printf("r%u ", rd);
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 148) && ((bin[*bn] & 15) == 2)) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("swap ");
		printf("r%u ", rd);
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 148) && ((bin[*bn] & 15) == 3)) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("inc ");
		printf("r%u ", rd);
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 148) && ((bin[*bn] & 15) == 10)) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("dec ");
		printf("r%u ", rd);
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 148) && ((bin[*bn] & 15) == 5)) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("asr ");
		printf("r%u ", rd);
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 148) && ((bin[*bn] & 15) == 6)) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("lsr ");
		printf("r%u ", rd);
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 148) && ((bin[*bn] & 15) == 7)) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		
		printf("ror ");
		printf("r%u ", rd);
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 148) && (bin[*bn] == 8)) {
		printf("sec ");
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 148) && (bin[*bn] == 24)) {
		printf("sez ");
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 148) && (bin[*bn] == 40)) {
		printf("sen ");
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 148) && (bin[*bn] == 56)) {
		printf("sev ");
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 148) && (bin[*bn] == 72)) {
		printf("ses ");
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 148) && (bin[*bn] == 88)) {
		printf("seh ");
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 148) && (bin[*bn] == 104)) {
		printf("set ");
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 148) && (bin[*bn] == 120)) {
		printf("sei ");
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 148) && (bin[*bn] == 136)) {
		printf("clc ");
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 148) && (bin[*bn] == 152)) {
		printf("clz ");
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 148) && (bin[*bn] == 168)) {
		printf("cln ");
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 148) && (bin[*bn] == 184)) {
		printf("clv ");
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 148) && (bin[*bn] == 200)) {
		printf("cls ");
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 148) && (bin[*bn] == 216)) {
		printf("clh ");
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 148) && (bin[*bn] == 232)) {
		printf("clt ");
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 148) && (bin[*bn] == 248)) {
		printf("cli ");
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 149) && (bin[*bn] == 8)) {
		printf("ret ");
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 149) && (bin[*bn] == 24)) {
		printf("reti ");
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 149) && (bin[*bn] == 136)) {
		printf("sleep ");
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 149) && (bin[*bn] == 152)) {
		printf("break ");
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 149) && (bin[*bn] == 168)) {
		printf("wdr ");
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 149) && (bin[*bn] == 200)) {
		printf("lpm ");
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 149) && (bin[*bn] == 216)) {
		printf("elpm ");
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 149) && (bin[*bn] == 232)) {
		printf("spm ");
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 149) && (bin[*bn] == 248)) {
		printf("spm ");
		printf("z, 1 ");
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 148) && (bin[*bn] == 9)) {
		printf("ijmp ");
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 148) && (bin[*bn] == 25)) {
		printf("eijmp ");
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 149) && (bin[*bn] == 9)) {
		printf("icall ");
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] == 149) && (bin[*bn] == 25)) {
		printf("eicall ");
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 255) == 148) && ((bin[*bn] & 15) == 11)) {
		uint8_t k = (bin[*bn] >> 4) & 15;
		
		printf("des ");
		printf("%u ", k);
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 148) && ((bin[*bn] & 14) == 12)) {
		uint16_t k = (bin[*bn + 2]) + (bin[*bn + 3] << 8);
		
		printf("jmp ");
		printf("%u ", k);
		*bn += 2;
		
		printf("\n%04lx %04lx    ", (*bn >> 16) & 65535, (*bn) & 65535);
		printf("%02x %02x    ", bin[*bn + 1], bin[*bn]);
		
		*addr = k * 2;
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 148) && ((bin[*bn] & 14) == 14)) {
		uint16_t k = (bin[*bn + 2]) + (bin[*bn + 3] << 8);
		
		printf("call ");
		printf("%u ", k);
		*bn += 2;
		
		printf("\n%04lx %04lx    ", (*bn >> 16) & 65535, (*bn) & 65535);
		printf("%02x %02x    ", bin[*bn + 1], bin[*bn]);
		
		*addr = k * 2;
		
		*bn += 2;
	}
	else if (bin[*bn + 1] == 150) {
		uint8_t rp = (bin[*bn] >> 4) & 3;
		rp = (rp * 2) + 24;
		uint8_t k = (bin[*bn] & 15) + ((bin[*bn] >> 2) & 80);
		
		printf("adiw ");
		printf("r%u, ", rp);
		printf("%u ", k);
		
		*bn += 2;
	}
	else if (bin[*bn + 1] == 151) {
		uint8_t rp = (bin[*bn] >> 4) & 3;
		rp = (rp * 2) + 24;
		uint8_t k = (bin[*bn] & 15) + ((bin[*bn] >> 2) & 80);
		
		printf("sbiw ");
		printf("r%u, ", rp);
		printf("%u ", k);
		
		*bn += 2;
	}
	else if (bin[*bn + 1] == 152) {
		uint8_t b = (bin[*bn]) & 3;
		uint8_t k = (bin[*bn] >> 3) & 31;
		
		printf("cbi ");
		printf("%u, ", k);
		printf("%u ", b);
		
		*bn += 2;
	}
	else if (bin[*bn + 1] == 154) {
		uint8_t b = (bin[*bn]) & 3;
		uint8_t k = (bin[*bn] >> 3) & 31;
		
		printf("sbi ");
		printf("%u, ", k);
		printf("%u ", b);
		
		*bn += 2;
	}
	else if (bin[*bn + 1] == 153) {
		uint8_t b = (bin[*bn]) & 3;
		uint8_t k = (bin[*bn] >> 3) & 31;
		
		printf("sbic ");
		printf("%u, ", k);
		printf("%u ", b);
		
		*bn += 2;
	}
	else if (bin[*bn + 1] == 155) {
		uint8_t b = (bin[*bn]) & 3;
		uint8_t k = (bin[*bn] >> 3) & 31;
		
		printf("sbis ");
		printf("%u, ", k);
		printf("%u ", b);
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 248) == 176) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		uint8_t k = ((bin[*bn]) & 15) + ((bin[*bn + 1] << 3) & 48);
		
		printf("in ");
		printf("r%u, ", rd);
		printf("%u ", k);
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 248) == 184) {
		uint8_t rs = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		uint8_t k = ((bin[*bn]) & 15) + ((bin[*bn + 1] << 3) & 48);
		
		printf("out ");
		printf("%u, ", k);
		printf("r%u ", rs);
		
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 240) == 192) {
		int16_t k = (bin[*bn]) + (bin[*bn + 1] << 12);
		k |= (k << 4) & 2048;
		
		printf("rjmp ");
		printf("%u ", k);
		
		*bn += 2;
		
		*addr = *bn + (k * 2);
	}
	else if ((bin[*bn + 1] & 240) == 208) {
		int16_t k = (bin[*bn]) + (bin[*bn + 1] << 12);
		k |= (k << 4) & 2048;
		
		printf("rcall ");
		printf("%u ", k);
		
		*bn += 2;
		
		*addr = *bn + (k * 2);
	}
	else if (((bin[*bn + 1] & 252) == 240) && ((bin[*bn] & 7) == 0)) {
		int8_t k = ((bin[*bn] >> 3) & 31) + ((bin[*bn + 1] << 5) & 96);
		k |= (k << 1) & 128;
		
		printf("brlo ");
		printf("%u ", k);
		
		*bn += 2;
		
		*addr = *bn + (k * 2);
	}
	else if (((bin[*bn + 1] & 252) == 244) && ((bin[*bn] & 7) == 0)) {
		int8_t k = ((bin[*bn] >> 3) & 31) + ((bin[*bn + 1] << 5) & 96);
		k |= (k << 1) & 128;
		
		printf("brsh ");
		printf("%u ", k);
		
		*bn += 2;
		
		*addr = *bn + (k * 2);
	}
	else if (((bin[*bn + 1] & 252) == 240) && ((bin[*bn] & 7) == 1)) {
		int8_t k = ((bin[*bn] >> 3) & 31) + ((bin[*bn + 1] << 5) & 96);
		k |= (k << 1) & 128;
		
		printf("breq ");
		printf("%u ", k);
		
		*bn += 2;
		
		*addr = *bn + (k * 2);
	}
	else if (((bin[*bn + 1] & 252) == 244) && ((bin[*bn] & 7) == 1)) {
		int8_t k = ((bin[*bn] >> 3) & 31) + ((bin[*bn + 1] << 5) & 96);
		k |= (k << 1) & 128;
		
		printf("brne ");
		printf("%u ", k);
		
		*bn += 2;
		
		*addr = *bn + (k * 2);
	}
	else if (((bin[*bn + 1] & 252) == 240) && ((bin[*bn] & 7) == 2)) {
		int8_t k = ((bin[*bn] >> 3) & 31) + ((bin[*bn + 1] << 5) & 96);
		k |= (k << 1) & 128;
		
		printf("brmi ");
		printf("%u ", k);
		
		*bn += 2;
		
		*addr = *bn + (k * 2);
	}
	else if (((bin[*bn + 1] & 252) == 244) && ((bin[*bn] & 7) == 2)) {
		int8_t k = ((bin[*bn] >> 3) & 31) + ((bin[*bn + 1] << 5) & 96);
		k |= (k << 1) & 128;
		
		printf("brpl ");
		printf("%u ", k);
		
		*bn += 2;
		
		*addr = *bn + (k * 2);
	}
	else if (((bin[*bn + 1] & 252) == 240) && ((bin[*bn] & 7) == 3)) {
		int8_t k = ((bin[*bn] >> 3) & 31) + ((bin[*bn + 1] << 5) & 96);
		k |= (k << 1) & 128;
		
		printf("brvs ");
		printf("%u ", k);
		
		*bn += 2;
		
		*addr = *bn + (k * 2);
	}
	else if (((bin[*bn + 1] & 252) == 244) && ((bin[*bn] & 7) == 3)) {
		int8_t k = ((bin[*bn] >> 3) & 31) + ((bin[*bn + 1] << 5) & 96);
		k |= (k << 1) & 128;
		
		printf("brvc ");
		printf("%u ", k);
		
		*bn += 2;
		
		*addr = *bn + (k * 2);
	}
	else if (((bin[*bn + 1] & 252) == 240) && ((bin[*bn] & 7) == 4)) {
		int8_t k = ((bin[*bn] >> 3) & 31) + ((bin[*bn + 1] << 5) & 96);
		k |= (k << 1) & 128;
		
		printf("brlt ");
		printf("%u ", k);
		
		*bn += 2;
		
		*addr = *bn + (k * 2);
	}
	else if (((bin[*bn + 1] & 252) == 244) && ((bin[*bn] & 7) == 4)) {
		int8_t k = ((bin[*bn] >> 3) & 31) + ((bin[*bn + 1] << 5) & 96);
		k |= (k << 1) & 128;
		
		printf("brge ");
		printf("%u ", k);
		
		*bn += 2;
		
		*addr = *bn + (k * 2);
	}
	else if (((bin[*bn + 1] & 252) == 240) && ((bin[*bn] & 7) == 5)) {
		int8_t k = ((bin[*bn] >> 3) & 31) + ((bin[*bn + 1] << 5) & 96);
		k |= (k << 1) & 128;
		
		printf("brhs ");
		printf("%u ", k);
		
		*bn += 2;
		
		*addr = *bn + (k * 2);
	}
	else if (((bin[*bn + 1] & 252) == 244) && ((bin[*bn] & 7) == 5)) {
		int8_t k = ((bin[*bn] >> 3) & 31) + ((bin[*bn + 1] << 5) & 96);
		k |= (k << 1) & 128;
		
		printf("brhc ");
		printf("%u ", k);
		
		*bn += 2;
		
		*addr = *bn + (k * 2);
	}
	else if (((bin[*bn + 1] & 252) == 240) && ((bin[*bn] & 7) == 6)) {
		int8_t k = ((bin[*bn] >> 3) & 31) + ((bin[*bn + 1] << 5) & 96);
		k |= (k << 1) & 128;
		
		printf("brts ");
		printf("%u ", k);
		
		*bn += 2;
		
		*addr = *bn + (k * 2);
	}
	else if (((bin[*bn + 1] & 252) == 244) && ((bin[*bn] & 7) == 6)) {
		int8_t k = ((bin[*bn] >> 3) & 31) + ((bin[*bn + 1] << 5) & 96);
		k |= (k << 1) & 128;
		
		printf("brtc ");
		printf("%u ", k);
		
		*bn += 2;
		
		*addr = *bn + (k * 2);
	}
	else if (((bin[*bn + 1] & 252) == 240) && ((bin[*bn] & 7) == 7)) {
		int8_t k = ((bin[*bn] >> 3) & 31) + ((bin[*bn + 1] << 5) & 96);
		k |= (k << 1) & 128;
		
		printf("brie ");
		printf("%u ", k);
		
		*bn += 2;
		
		*addr = *bn + (k * 2);
	}
	else if (((bin[*bn + 1] & 252) == 244) && ((bin[*bn] & 7) == 7)) {
		int8_t k = ((bin[*bn] >> 3) & 31) + ((bin[*bn + 1] << 5) & 96);
		k |= (k << 1) & 128;
		
		printf("brid ");
		printf("%u ", k);
		
		*bn += 2;
		
		*addr = *bn + (k * 2);
	}
	else if (((bin[*bn + 1] & 254) == 248) && ((bin[*bn] & 8) == 0)) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		uint8_t b = (bin[*bn]) & 3;
		
		printf("bld ");
		printf("r%u", rd);
		printf("%u ", b);
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 250) && ((bin[*bn] & 8) == 0)) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		uint8_t b = (bin[*bn]) & 3;
		
		printf("bst ");
		printf("r%u", rd);
		printf("%u ", b);
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 252) && ((bin[*bn] & 8) == 0)) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		uint8_t b = (bin[*bn]) & 3;
		
		printf("sbrc ");
		printf("r%u", rd);
		printf("%u ", b);
		
		*bn += 2;
	}
	else if (((bin[*bn + 1] & 254) == 254) && ((bin[*bn] & 8) == 0)) {
		uint8_t rd = ((bin[*bn] >> 4) & 15) + ((bin[*bn + 1] << 4) & 16);
		uint8_t b = (bin[*bn]) & 3;
		
		printf("sbrs ");
		printf("r%u", rd);
		printf("%u ", b);
		
		*bn += 2;
	}
	else {
		printf("~byt2 %hu", ((bin[*bn + 1] << 8) + bin[*bn]));
		*bn += 2;
	}
}
