//   Copyright 2025 Will Thomas
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

//   sub umbra alarum suarum

#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int8_t* arm_32m_c4(uint8_t c) {
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

int8_t* arm_32m_m4(uint8_t c, uint8_t m) {
	if (m == 8) {
		return "\0";
	}
	else if (m == ((c << 3) & 8) + 4) {
		return "t";
	}
	else if (m == ((~c << 3) & 8) + 4) {
		return "e";
	}
	else if (m == ((c << 3) & 8) + ((c << 2) & 4) + 2) {
		return "tt";
	}
	else if (m == ((~c << 3) & 8) + ((c << 2) & 4) + 2) {
		return "et";
	}
	else if (m == ((c << 3) & 8) + ((~c << 2) & 4) + 2) {
		return "te";
	}
	else if (m == ((~c << 3) & 8) + ((~c << 2) & 4) + 2) {
		return "ee";
	}
	else if (m == ((c << 3) & 8) + ((c << 2) & 4) + ((c << 1) & 2) + 1) {
		return "ttt";
	}
	else if (m == ((~c << 3) & 8) + ((c << 2) & 4) + ((c << 1) & 2) + 1) {
		return "ett";
	}
	else if (m == ((c << 3) & 8) + ((~c << 2) & 4) + ((c << 1) & 2) + 1) {
		return "tet";
	}
	else if (m == ((~c << 3) & 8) + ((~c << 2) & 4) + ((c << 1) & 2) + 1) {
		return "eet";
	}
	else if (m == ((c << 3) & 8) + ((c << 2) & 4) + ((~c << 1) & 2) + 1) {
		return "tte";
	}
	else if (m == ((~c << 3) & 8) + ((c << 2) & 4) + ((~c << 1) & 2) + 1) {
		return "ete";
	}
	else if (m == ((c << 3) & 8) + ((~c << 2) & 4) + ((~c << 1) & 2) + 1) {
		return "tee";
	}
	else if (m == ((~c << 3) & 8) + ((~c << 2) & 4) + ((~c << 1) & 2) + 1) {
		return "eee";
	}
}

int8_t* arm_32m_sh(uint8_t sh) {
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

void arm_32m_dec(uint8_t* bin, uint64_t* bn, uint64_t* addr) {
	printf("%04lx %04lx    ", (*bn >> 16) & 65535, (*bn) & 65535); //address
	printf("%02x %02x    ", bin[*bn + 1], bin[*bn]); //machine code
	
	if ((bin[*bn + 1] & 248) == 0 && !(((bin[*bn] >> 6) & 3) + ((bin[*bn] << 2) & 28))) {
		printf("mov ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u ", (bin[*bn] >> 3) & 7);
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 248) == 0) {
		printf("lsl ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u, ", (bin[*bn] >> 3) & 7);
		printf("%u ", ((bin[*bn] >> 6) & 3) + ((bin[*bn + 1] << 2) & 28));
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 248) == 8) {
		printf("lsr ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u, ", (bin[*bn] >> 3) & 7);
		printf("%u ", ((bin[*bn] >> 6) & 3) + ((bin[*bn + 1] << 2) & 28));
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 248) == 16) {
		printf("asr ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u, ", (bin[*bn] >> 3) & 7);
		printf("%u ", ((bin[*bn] >> 6) & 3) + ((bin[*bn + 1] << 2) & 28));
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 254) == 24) {
		printf("add ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u, ", (bin[*bn] >> 3) & 7);
		printf("r%u ", ((bin[*bn] >> 6) & 3) + ((bin[*bn + 1] << 2) & 4));
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 254) == 26) {
		printf("sub ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u, ", (bin[*bn] >> 3) & 7);
		printf("r%u ", ((bin[*bn] >> 6) & 3) + ((bin[*bn + 1] << 2) & 4));
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 254) == 28) {
		printf("add ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u, ", (bin[*bn] >> 3) & 7);
		printf("%u ", ((bin[*bn] >> 6) & 3) + ((bin[*bn + 1] << 2) & 4));
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 254) == 30) {
		printf("sub ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u, ", (bin[*bn] >> 3) & 7);
		printf("%u ", ((bin[*bn] >> 6) & 3) + ((bin[*bn + 1] << 2) & 4));
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 248) == 32) {
		printf("mov ");
		printf("r%u, ", bin[*bn + 1] & 7);
		printf("%u ", bin[*bn]);
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 248) == 40) {
		printf("cmp ");
		printf("r%u, ", bin[*bn + 1] & 7);
		printf("%u ", bin[*bn]);
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 248) == 48) {
		printf("add ");
		printf("r%u, ", bin[*bn + 1] & 7);
		printf("%u ", bin[*bn]);
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 248) == 56) {
		printf("sub ");
		printf("r%u, ", bin[*bn + 1] & 7);
		printf("%u ", bin[*bn]);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 64 && (bin[*bn] & 192) == 0) {
		printf("and ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u ", (bin[*bn] >> 3) & 7);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 64 && (bin[*bn] & 192) == 64) {
		printf("eor ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u ", (bin[*bn] >> 3) & 7);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 64 && (bin[*bn] & 192) == 128) {
		printf("lsl ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u ", (bin[*bn] >> 3) & 7);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 64 && (bin[*bn] & 192) == 192) {
		printf("lsr ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u ", (bin[*bn] >> 3) & 7);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 65 && (bin[*bn] & 192) == 0) {
		printf("asr ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u ", (bin[*bn] >> 3) & 7);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 65 && (bin[*bn] & 192) == 64) {
		printf("adc ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u ", (bin[*bn] >> 3) & 7);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 65 && (bin[*bn] & 192) == 128) {
		printf("sbc ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u ", (bin[*bn] >> 3) & 7);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 65 && (bin[*bn] & 192) == 192) {
		printf("ror ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u ", (bin[*bn] >> 3) & 7);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 66 && (bin[*bn] & 192) == 0) {
		printf("tst ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u ", (bin[*bn] >> 3) & 7);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 66 && (bin[*bn] & 192) == 64) {
		printf("rsb ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u ", (bin[*bn] >> 3) & 7);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 66 && (bin[*bn] & 192) == 128) {
		printf("cmp ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u ", (bin[*bn] >> 3) & 7);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 66 && (bin[*bn] & 192) == 192) {
		printf("cmn ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u ", (bin[*bn] >> 3) & 7);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 67 && (bin[*bn] & 192) == 0) {
		printf("orr ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u ", (bin[*bn] >> 3) & 7);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 67 && (bin[*bn] & 192) == 64) {
		printf("mul ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u ", (bin[*bn] >> 3) & 7);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 67 && (bin[*bn] & 192) == 128) {
		printf("bic ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u ", (bin[*bn] >> 3) & 7);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 67 && (bin[*bn] & 192) == 192) {
		printf("mvn ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u ", (bin[*bn] >> 3) & 7);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 68) {
		printf("add ");
		printf("r%u, ", (bin[*bn] & 7) + ((bin[*bn] >> 4) & 8));
		printf("r%u ", (bin[*bn] >> 3) & 15);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 69) {
		printf("cmp ");
		printf("r%u, ", (bin[*bn] & 7) + ((bin[*bn] >> 4) & 8));
		printf("r%u ", (bin[*bn] >> 3) & 15);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 70) {
		printf("mov ");
		printf("r%u, ", (bin[*bn] & 7) + ((bin[*bn] >> 4) & 8));
		printf("r%u ", (bin[*bn] >> 3) & 15);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 71 && (bin[*bn] & 128) == 0) {
		printf("bx ");
		printf("r%u ", (bin[*bn] >> 3) & 15);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 71 && (bin[*bn] & 128) == 128) {
		printf("blx ");
		printf("r%u ", (bin[*bn] >> 3) & 15);
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 248) == 72) {
		printf("ldr ");
		printf("r%u, ", bin[*bn + 1] & 7);
		printf("pc, %u ", bin[*bn]);
		*bn += 2;
		*addr = (bin[*bn] * 4) + *bn + 2;
	}
	else if ((bin[*bn + 1] & 254) == 80) {
		printf("str ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u, ", (bin[*bn] >> 3) & 7);
		printf("r%u ", ((bin[*bn] >> 6) & 3) + ((bin[*bn + 1] << 2) & 4));
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 254) == 82) {
		printf("strh ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u, ", (bin[*bn] >> 3) & 7);
		printf("r%u ", ((bin[*bn] >> 6) & 3) + ((bin[*bn + 1] << 2) & 4));
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 254) == 84) {
		printf("strb ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u, ", (bin[*bn] >> 3) & 7);
		printf("r%u ", ((bin[*bn] >> 6) & 3) + ((bin[*bn + 1] << 2) & 4));
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 254) == 86) {
		printf("ldrsb ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u, ", (bin[*bn] >> 3) & 7);
		printf("r%u ", ((bin[*bn] >> 6) & 3) + ((bin[*bn + 1] << 2) & 4));
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 254) == 88) {
		printf("ldr ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u, ", (bin[*bn] >> 3) & 7);
		printf("r%u ", ((bin[*bn] >> 6) & 3) + ((bin[*bn + 1] << 2) & 4));
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 254) == 90) {
		printf("ldrh ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u, ", (bin[*bn] >> 3) & 7);
		printf("r%u ", ((bin[*bn] >> 6) & 3) + ((bin[*bn + 1] << 2) & 4));
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 254) == 92) {
		printf("ldrb ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u, ", (bin[*bn] >> 3) & 7);
		printf("r%u ", ((bin[*bn] >> 6) & 3) + ((bin[*bn + 1] << 2) & 4));
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 254) == 94) {
		printf("ldrsh ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u, ", (bin[*bn] >> 3) & 7);
		printf("r%u ", ((bin[*bn] >> 6) & 3) + ((bin[*bn + 1] << 2) & 4));
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 248) == 96) {
		printf("str ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u, ", (bin[*bn] >> 3) & 7);
		printf("%u ", ((bin[*bn] >> 6) & 3) + ((bin[*bn + 1] << 2) & 28));
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 248) == 104) {
		printf("ldr ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u, ", (bin[*bn] >> 3) & 7);
		printf("%u ", ((bin[*bn] >> 6) & 3) + ((bin[*bn + 1] << 2) & 28));
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 248) == 112) {
		printf("strb ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u, ", (bin[*bn] >> 3) & 7);
		printf("%u ", ((bin[*bn] >> 6) & 3) + ((bin[*bn + 1] << 2) & 28));
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 248) == 120) {
		printf("ldrb ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u, ", (bin[*bn] >> 3) & 7);
		printf("%u ", ((bin[*bn] >> 6) & 3) + ((bin[*bn + 1] << 2) & 28));
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 248) == 128) {
		printf("strh ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u, ", (bin[*bn] >> 3) & 7);
		printf("%u ", ((bin[*bn] >> 6) & 3) + ((bin[*bn + 1] << 2) & 28));
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 248) == 136) {
		printf("ldrh ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u, ", (bin[*bn] >> 3) & 7);
		printf("%u ", ((bin[*bn] >> 6) & 3) + ((bin[*bn + 1] << 2) & 28));
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 248) == 144) {
		printf("str ");
		printf("r%u, ", bin[*bn + 1] & 7);
		printf("sp, %u ", bin[*bn]);
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 248) == 152) {
		printf("ldr ");
		printf("r%u, ", bin[*bn + 1] & 7);
		printf("sp, %u ", bin[*bn]);
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 248) == 160) {
		printf("adr ");
		printf("r%u, ", bin[*bn + 1] & 7);
		printf("pc, %u ", bin[*bn]);
		*bn += 2;
		*addr = (bin[*bn] * 4) + *bn + 2;
	}
	else if ((bin[*bn + 1] & 248) == 168) {
		printf("add ");
		printf("r%u, ", bin[*bn + 1] & 7);
		printf("sp, %u ", bin[*bn]);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 176 && (bin[*bn] & 128) == 0) {
		printf("add ");
		printf("sp, sp, %u ", bin[*bn]);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 176 && (bin[*bn] & 128) == 128) {
		printf("sub ");
		printf("sp, sp, %u ", bin[*bn]);
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 253) == 177) {
		printf("cbz ");
		printf("r%u, ", bin[*bn] & 7);
		printf("%u, ", ((bin[*bn] >> 3) & 31) + ((bin[*bn + 1] << 4) & 32));
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 253) == 185) {
		printf("cbnz ");
		printf("r%u, ", bin[*bn] & 7);
		printf("%u, ", ((bin[*bn] >> 3) & 31) + ((bin[*bn + 1] << 4) & 32));
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 254) == 180) {
		printf("push ");
		uint8_t a = 0;
		for (uint8_t b = 0; b < 9; b++) {
			if (b < 8) {
				if (bin[*bn] & (1 << b)) {
					if (a) {
						printf(", ");
					}
					printf("r%u", b);
					a = 1;
				}
			}
			else {
				if (bin[*bn + 1] & 1) {
					if (a) {
						printf(", ");
					}
					printf("lr");
					a = 1;
				}
			}
		}
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 254) == 188) {
		printf("pop ");
		uint8_t a = 0;
		for (uint8_t b = 0; b < 9; b++) {
			if (b < 8) {
				if (bin[*bn] & (1 << b)) {
					if (a) {
						printf(", ");
					}
					printf("r%u", b);
					a = 1;
				}
			}
			else {
				if (bin[*bn + 1] & 1) {
					if (a) {
						printf(", ");
					}
					printf("pc");
					a = 1;
				}
			}
		}
		*bn += 2;
	}
	else if (bin[*bn + 1] == 190) {
		printf("bkpt ");
		printf("%u ", bin[*bn]);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 191 && bin[*bn] == 0) {
		printf("nop ");
		*bn += 2;
	}
	else if (bin[*bn + 1] == 191 && bin[*bn] == 16) {
		printf("yield ");
		*bn += 2;
	}
	else if (bin[*bn + 1] == 191 && bin[*bn] == 32) {
		printf("wfe ");
		*bn += 2;
	}
	else if (bin[*bn + 1] == 191 && bin[*bn] == 48) {
		printf("wfi ");
		*bn += 2;
	}
	else if (bin[*bn + 1] == 191 && bin[*bn] == 64) {
		printf("sev ");
		*bn += 2;
	}
	else if (bin[*bn + 1] == 191) {
		printf("it");
		printf("%s", arm_32m_m4(bin[*bn] >> 4, bin[*bn] & 15));
		printf("%s ", arm_32m_c4(bin[*bn] >> 4));
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 248) == 192) {
		printf("stmia ");
		printf("r%u", bin[*bn + 1] & 7);
		for (uint8_t b = 0; b < 8; b++) {
			if (bin[*bn] & (1 << b)) {
				printf(", r%u", b);
			}
		}
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 248) == 200) {
		printf("ldmia ");
		printf("r%u", bin[*bn + 1] & 7);
		for (uint8_t b = 0; b < 8; b++) {
			if (bin[*bn] & (1 << b)) {
				printf(", r%u", b);
			}
		}
		*bn += 2;
	}
	else if (bin[*bn + 1] == 222) {
		printf("udf ");
		printf("%u ", bin[*bn]);
		*bn += 2;
		*addr = (bin[*bn] * 2) + *bn + 4;
	}
	else if (bin[*bn + 1] == 223) {
		printf("svc ");
		printf("%u ", bin[*bn]);
		*bn += 2;
		*addr = (bin[*bn] * 2) + *bn + 4;
	}
	else if ((bin[*bn + 1] & 248) == 224) {
		printf("b ");
		printf("%u ", bin[*bn] + ((bin[*bn + 1] & 7) << 8));
		*bn += 2;
		*addr = ((bin[*bn] + ((bin[*bn + 1] & 7) << 8)) * 2) + *bn + 4;
	}
	else if ((bin[*bn + 1] & 240) == 208) {
		printf("b");
		printf("%s ", arm_32m_c4(bin[*bn + 1] & 15));
		printf("%u ", bin[*bn]);
		*bn += 2;
		*addr = (bin[*bn] * 2) + *bn + 4;
	}
	else if (bin[*bn + 1] == 232 && (bin[*bn] & 240) == 128) { //32
		printf("stmia ");
		printf("r%u", bin[*bn] & 15);
		for (uint8_t b = 0; b < 16; b++) {
			if (b < 8) {
				if (bin[*bn + 2] & (1 << b)) {
					printf(", r%u", b);
				}
			}
			else {
				if (bin[*bn + 3] & (1 << (b - 8))) {
					printf(", r%u", b);
				}
			}
		}
		*bn += 4;
	}
	else if (bin[*bn + 1] == 232 && (bin[*bn] & 240) == 160) {
		printf("stmiaw ");
		printf("r%u", bin[*bn] & 15);
		for (uint8_t b = 0; b < 16; b++) {
			if (b < 8) {
				if (bin[*bn + 2] & (1 << b)) {
					printf(", r%u", b);
				}
			}
			else {
				if (bin[*bn + 3] & (1 << (b - 8))) {
					printf(", r%u", b);
				}
			}
		}
		*bn += 4;
	}
	else if (bin[*bn + 1] == 232 && bin[*bn] == 189) {
		printf("pop ");
		uint8_t a = 0;
		for (uint8_t b = 0; b < 16; b++) {
			if (b < 8) {
				if (bin[*bn + 2] & (1 << b)) {
					if (a) {
						printf(", ");
					}
					printf("r%u", b);
					a = 1;
				}
			}
			else {
				if (bin[*bn + 3] & (1 << (b - 8))) {
					if (a) {
						printf(", ");
					}
					printf("r%u", b);
					a = 1;
				}
			}
		}
		*bn += 4;
	}
	else if (bin[*bn + 1] == 232 && (bin[*bn] & 240) == 144) {
		printf("ldmia ");
		printf("r%u", bin[*bn] & 15);
		for (uint8_t b = 0; b < 16; b++) {
			if (b < 8) {
				if (bin[*bn + 2] & (1 << b)) {
					printf(", r%u", b);
				}
			}
			else {
				if (bin[*bn + 3] & (1 << (b - 8))) {
					printf(", r%u", b);
				}
			}
		}
		*bn += 4;
	}
	else if (bin[*bn + 1] == 232 && (bin[*bn] & 240) == 176) {
		printf("ldmiaw ");
		printf("r%u", bin[*bn] & 15);
		for (uint8_t b = 0; b < 16; b++) {
			if (b < 8) {
				if (bin[*bn + 2] & (1 << b)) {
					printf(", r%u", b);
				}
			}
			else {
				if (bin[*bn + 3] & (1 << (b - 8))) {
					printf(", r%u", b);
				}
			}
		}
		*bn += 4;
	}
	else if (bin[*bn + 1] == 233 && bin[*bn] == 45) {
		printf("push ");
		uint8_t a = 0;
		for (uint8_t b = 0; b < 16; b++) {
			if (b < 8) {
				if (bin[*bn + 2] & (1 << b)) {
					if (a) {
						printf(", ");
					}
					printf("r%u", b);
					a = 1;
				}
			}
			else {
				if (bin[*bn + 3] & (1 << (b - 8))) {
					if (a) {
						printf(", ");
					}
					printf("r%u", b);
					a = 1;
				}
			}
		}
		*bn += 4;
	}
	else if (bin[*bn + 1] == 233 && (bin[*bn] & 240) == 0) {
		printf("stmdb ");
		printf("r%u", bin[*bn] & 15);
		for (uint8_t b = 0; b < 16; b++) {
			if (b < 8) {
				if (bin[*bn + 2] & (1 << b)) {
					printf(", r%u", b);
				}
			}
			else {
				if (bin[*bn + 3] & (1 << (b - 8))) {
					printf(", r%u", b);
				}
			}
		}
		*bn += 4;
	}
	else if (bin[*bn + 1] == 233 && (bin[*bn] & 240) == 32) {
		printf("stmdbw ");
		printf("r%u", bin[*bn] & 15);
		for (uint8_t b = 0; b < 16; b++) {
			if (b < 8) {
				if (bin[*bn + 2] & (1 << b)) {
					printf(", r%u", b);
				}
			}
			else {
				if (bin[*bn + 3] & (1 << (b - 8))) {
					printf(", r%u", b);
				}
			}
		}
		*bn += 4;
	}
	else if (bin[*bn + 1] == 233 && (bin[*bn] & 240) == 16) {
		printf("ldmdb ");
		printf("r%u", bin[*bn] & 15);
		for (uint8_t b = 0; b < 16; b++) {
			if (b < 8) {
				if (bin[*bn + 2] & (1 << b)) {
					printf(", r%u", b);
				}
			}
			else {
				if (bin[*bn + 3] & (1 << (b - 8))) {
					printf(", r%u", b);
				}
			}
		}
		*bn += 4;
	}
	else if (bin[*bn + 1] == 233 && (bin[*bn] & 240) == 48) {
		printf("ldmdbw ");
		printf("r%u", bin[*bn] & 15);
		for (uint8_t b = 0; b < 16; b++) {
			if (b < 8) {
				if (bin[*bn + 2] & (1 << b)) {
					printf(", r%u", b);
				}
			}
			else {
				if (bin[*bn + 3] & (1 << (b - 8))) {
					printf(", r%u", b);
				}
			}
		}
		*bn += 4;
	}
	else if (bin[*bn + 1] == 232 && (bin[*bn] & 240) == 64) {
		printf("strex ");
		printf("r%u, ", bin[*bn + 3] & 15);
		printf("r%u, ", (bin[*bn + 3] >> 4) & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("%u, ", bin[*bn + 2]);
		*bn += 4;
	}
	else if (bin[*bn + 1] == 232 && (bin[*bn] & 240) == 80) {
		printf("ldrex ");
		printf("r%u, ", (bin[*bn + 3] >> 4) & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("%u, ", bin[*bn + 2]);
		*bn += 4;
	}
	else {
		printf("~byt2 %u", bin[*bn]);
		*bn += 2;
	}
}
