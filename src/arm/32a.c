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

int8_t* arm_32a_c4(uint8_t c) {
	if (c == 14) {
		return "\0";
	}
	else if (c == 0) {
		return "eq";
	}
	else if (c == 1) {
		return "ne";
	}
	else if (c == 2) {
		return "cs";
	}
	else if (c == 3) {
		return "lo";
	}
	else if (c == 4) {
		return "mi";
	}
	else if (c == 5) {
		return "pl";
	}
	else if (c == 6) {
		return "vs";
	}
	else if (c == 7) {
		return "vc";
	}
	else if (c == 8) {
		return "hi";
	}
	else if (c == 9) {
		return "ls";
	}
	else if (c == 10) {
		return "ge";
	}
	else if (c == 11) {
		return "lt";
	}
	else if (c == 12) {
		return "gt";
	}
	else if (c == 13) {
		return "le";
	}
}

int8_t* arm_32a_sh(uint8_t sh) {
	if (sh == 0) {
		return "lsl";
	}
	else if (sh == 1) {
		return "lsr";
	}
	else if (sh == 2) {
		return "asr";
	}
	else if (sh == 3) {
		return "ror";
	}
}

void arm_32a_dec(uint8_t* bin, uint64_t* bn, uint64_t* addr) {
	printf("%04lx %04lx    ", (*bn >> 16) & 65535, (*bn) & 65535); //address
	printf("%02x %02x %02x %02x    ", bin[*bn + 3], bin[*bn + 2], bin[*bn + 1], bin[*bn]); //machine code
	
	if ((bin[*bn + 3] & 13) == 0 && (bin[*bn + 2] & 224) == 0) {
		if (bin[*bn + 2] & 16) {
			printf("ands%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		else {
			printf("and%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn + 2] & 15);
		
		if (bin[*bn + 3] & 2) {
			printf("%u ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, ", arm_32a_sh((bin[*bn] >> 5) & 3));
			printf("r%u, ", bin[*bn + 1] & 15);
		}
		else if (((bin[*bn] >> 5) & 3) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, %hhu ", arm_32a_sh((bin[*bn] >> 5) & 3), (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else {
			printf("r%u ", bin[*bn] & 15);
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 0 && (bin[*bn + 2] & 224) == 32) {
		if (bin[*bn + 2] & 16) {
			printf("eors%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		else {
			printf("eor%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn + 2] & 15);
		
		if (bin[*bn + 3] & 2) {
			printf("%u ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, ", arm_32a_sh((bin[*bn] >> 5) & 3));
			printf("r%u, ", bin[*bn + 1] & 15);
		}
		else if (((bin[*bn] >> 5) & 3) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, %hhu ", arm_32a_sh((bin[*bn] >> 5) & 3), (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else {
			printf("r%u ", bin[*bn] & 15);
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 0 && (bin[*bn + 2] & 224) == 64) {
		if (bin[*bn + 2] & 16) {
			printf("subs%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		else {
			printf("sub%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn + 2] & 15);
		
		if (bin[*bn + 3] & 2) {
			printf("%u ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, ", arm_32a_sh((bin[*bn] >> 5) & 3));
			printf("r%u, ", bin[*bn + 1] & 15);
		}
		else if (((bin[*bn] >> 5) & 3) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, %hhu ", arm_32a_sh((bin[*bn] >> 5) & 3), (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else {
			printf("r%u ", bin[*bn] & 15);
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 0 && (bin[*bn + 2] & 224) == 96) {
		if (bin[*bn + 2] & 16) {
			printf("rsbs%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		else {
			printf("rsb%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn + 2] & 15);
		
		if (bin[*bn + 3] & 2) {
			printf("%u ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, ", arm_32a_sh((bin[*bn] >> 5) & 3));
			printf("r%u, ", bin[*bn + 1] & 15);
		}
		else if (((bin[*bn] >> 5) & 3) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, %hhu ", arm_32a_sh((bin[*bn] >> 5) & 3), (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else {
			printf("r%u ", bin[*bn] & 15);
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 0 && (bin[*bn + 2] & 224) == 128) {
		if (bin[*bn + 2] & 16) {
			printf("adds%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		else {
			printf("add%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn + 2] & 15);
		
		if (bin[*bn + 3] & 2) {
			printf("%u ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, ", arm_32a_sh((bin[*bn] >> 5) & 3));
			printf("r%u, ", bin[*bn + 1] & 15);
		}
		else if (((bin[*bn] >> 5) & 3) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, %hhu ", arm_32a_sh((bin[*bn] >> 5) & 3), (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else {
			printf("r%u ", bin[*bn] & 15);
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 0 && (bin[*bn + 2] & 224) == 160) {
		if (bin[*bn + 2] & 16) {
			printf("adcs%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		else {
			printf("adc%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn + 2] & 15);
		
		if (bin[*bn + 3] & 2) {
			printf("%u ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, ", arm_32a_sh((bin[*bn] >> 5) & 3));
			printf("r%u, ", bin[*bn + 1] & 15);
		}
		else if (((bin[*bn] >> 5) & 3) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, %hhu ", arm_32a_sh((bin[*bn] >> 5) & 3), (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else {
			printf("r%u ", bin[*bn] & 15);
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 0 && (bin[*bn + 2] & 224) == 192) {
		if (bin[*bn + 2] & 16) {
			printf("sbcs%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		else {
			printf("sbc%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn + 2] & 15);
		
		if (bin[*bn + 3] & 2) {
			printf("%u ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, ", arm_32a_sh((bin[*bn] >> 5) & 3));
			printf("r%u, ", bin[*bn + 1] & 15);
		}
		else if (((bin[*bn] >> 5) & 3) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, %hhu ", arm_32a_sh((bin[*bn] >> 5) & 3), (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else {
			printf("r%u ", bin[*bn] & 15);
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 0 && (bin[*bn + 2] & 224) == 224) {
		if (bin[*bn + 2] & 16) {
			printf("rscs%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		else {
			printf("rsc%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn + 2] & 15);
		
		if (bin[*bn + 3] & 2) {
			printf("%u ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, ", arm_32a_sh((bin[*bn] >> 5) & 3));
			printf("r%u, ", bin[*bn + 1] & 15);
		}
		else if (((bin[*bn] >> 5) & 3) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, %hhu ", arm_32a_sh((bin[*bn] >> 5) & 3), (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else {
			printf("r%u ", bin[*bn] & 15);
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 1 && (bin[*bn + 2] & 240) == 16) {
		printf("tst%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 2] & 15);
		
		if (bin[*bn + 3] & 2) {
			printf("%u ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, ", arm_32a_sh((bin[*bn] >> 5) & 3));
			printf("r%u, ", bin[*bn + 1] & 15);
		}
		else if (((bin[*bn] >> 5) & 3) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, %hhu ", arm_32a_sh((bin[*bn] >> 5) & 3), (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else {
			printf("r%u ", bin[*bn] & 15);
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 1 && (bin[*bn + 2] & 240) == 48) {
		printf("teq%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 2] & 15);
		
		if (bin[*bn + 3] & 2) {
			printf("%u ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, ", arm_32a_sh((bin[*bn] >> 5) & 3));
			printf("r%u, ", bin[*bn + 1] & 15);
		}
		else if (((bin[*bn] >> 5) & 3) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, %hhu ", arm_32a_sh((bin[*bn] >> 5) & 3), (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else {
			printf("r%u ", bin[*bn] & 15);
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 1 && (bin[*bn + 2] & 240) == 80) {
		printf("cmp%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 2] & 15);
		
		if (bin[*bn + 3] & 2) {
			printf("%u ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, ", arm_32a_sh((bin[*bn] >> 5) & 3));
			printf("r%u, ", bin[*bn + 1] & 15);
		}
		else if (((bin[*bn] >> 5) & 3) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, %hhu ", arm_32a_sh((bin[*bn] >> 5) & 3), (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else {
			printf("r%u ", bin[*bn] & 15);
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 1 && (bin[*bn + 2] & 240) == 112) {
		printf("cmn%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 2] & 15);
		
		if (bin[*bn + 3] & 2) {
			printf("%u ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, ", arm_32a_sh((bin[*bn] >> 5) & 3));
			printf("r%u, ", bin[*bn + 1] & 15);
		}
		else if (((bin[*bn] >> 5) & 3) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, %hhu ", arm_32a_sh((bin[*bn] >> 5) & 3), (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else {
			printf("r%u ", bin[*bn] & 15);
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 1 && (bin[*bn + 2] & 224) == 128) {
		if (bin[*bn + 2] & 16) {
			printf("orrs%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		else {
			printf("orr%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn + 2] & 15);
		
		if (bin[*bn + 3] & 2) {
			printf("%u ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, ", arm_32a_sh((bin[*bn] >> 5) & 3));
			printf("r%u, ", bin[*bn + 1] & 15);
		}
		else if (((bin[*bn] >> 5) & 3) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, %hhu ", arm_32a_sh((bin[*bn] >> 5) & 3), (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else {
			printf("r%u ", bin[*bn] & 15);
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 1 && (bin[*bn + 2] & 224) == 160 && (bin[*bn] & 96) == 0 && !((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
		if (bin[*bn + 2] & 16) {
			printf("movs%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		else {
			printf("mov%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		printf("r%u, ", bin[*bn + 1] >> 4);
		
		if (bin[*bn + 3] & 2) {
			printf("%u ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else {
			printf("r%u ", bin[*bn] & 15);
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 1 && (bin[*bn + 2] & 224) == 160 && (bin[*bn] & 96) == 0) {
		if (bin[*bn + 2] & 16) {
			printf("lsls%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		else {
			printf("lsl%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn] & 15);
		
		if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn + 1] & 15);
		}
		else {
			printf("%hhu ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 1 && (bin[*bn + 2] & 224) == 160 && (bin[*bn] & 96) == 32) {
		if (bin[*bn + 2] & 16) {
			printf("lsrs%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		else {
			printf("lsr%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn] & 15);
		
		if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn + 1] & 15);
		}
		else {
			printf("%hhu ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 1 && (bin[*bn + 2] & 224) == 160 && (bin[*bn] & 96) == 64) {
		if (bin[*bn + 2] & 16) {
			printf("asrs%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		else {
			printf("asr%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn] & 15);
		
		if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn + 1] & 15);
		}
		else {
			printf("%hhu ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 1 && (bin[*bn + 2] & 224) == 160 && (bin[*bn] & 96) == 96) {
		if (bin[*bn + 2] & 16) {
			printf("rors%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		else {
			printf("ror%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn] & 15);
		
		if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn + 1] & 15);
		}
		else {
			printf("%hhu ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 1 && (bin[*bn + 2] & 224) == 192) {
		if (bin[*bn + 2] & 16) {
			printf("bics%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		else {
			printf("bic%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn + 2] & 15);
		
		if (bin[*bn + 3] & 2) {
			printf("%u ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, ", arm_32a_sh((bin[*bn] >> 5) & 3));
			printf("r%u, ", bin[*bn + 1] & 15);
		}
		else if (((bin[*bn] >> 5) & 3) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, %hhu ", arm_32a_sh((bin[*bn] >> 5) & 3), (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else {
			printf("r%u ", bin[*bn] & 15);
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 1 && (bin[*bn + 2] & 224) == 224) {
		if (bin[*bn + 2] & 16) {
			printf("mvns%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		else {
			printf("mvn%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		}
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn + 2] & 15);
		
		if (bin[*bn + 3] & 2) {
			printf("%u ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, ", arm_32a_sh((bin[*bn] >> 5) & 3));
			printf("r%u, ", bin[*bn + 1] & 15);
		}
		else if (((bin[*bn] >> 5) & 3) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, %hhu ", arm_32a_sh((bin[*bn] >> 5) & 3), (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else {
			printf("r%u ", bin[*bn] & 15);
		}
		
		*bn += 4;
	}
	else {
		printf("~byt4 %u", bin[*bn]);
		*bn += 4;
	}
}
