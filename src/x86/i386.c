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

int8_t* i386_r8(uint8_t r) {
	if (r == 0) {
		return "al";
	}
	else if (r == 1) {
		return "cl";
	}
	else if (r == 2) {
		return "dl";
	}
	else if (r == 3) {
		return "bl";
	}
	else if (r == 4) {
		return "ah";
	}
	else if (r == 5) {
		return "ch";
	}
	else if (r == 6) {
		return "dh";
	}
	else if (r == 7) {
		return "bh";
	}	
}

int8_t* i386_r16(uint8_t r) {
	if (r == 0) {
		return "ax";
	}
	else if (r == 1) {
		return "cx";
	}
	else if (r == 2) {
		return "dx";
	}
	else if (r == 3) {
		return "bx";
	}
	else if (r == 4) {
		return "sp";
	}
	else if (r == 5) {
		return "bp";
	}
	else if (r == 6) {
		return "si";
	}
	else if (r == 7) {
		return "di";
	}
}

int8_t* i386_r32(uint8_t r) {
	if (r == 0) {
		return "eax";
	}
	else if (r == 1) {
		return "ecx";
	}
	else if (r == 2) {
		return "edx";
	}
	else if (r == 3) {
		return "ebx";
	}
	else if (r == 4) {
		return "esp";
	}
	else if (r == 5) {
		return "ebp";
	}
	else if (r == 6) {
		return "esi";
	}
	else if (r == 7) {
		return "edi";
	}
}

int8_t* i386_a16(uint8_t a) {
	if (a == 0) {
		return "bx, (si)";
	}
	else if (a == 1) {
		return "bx, (di)";
	}
	else if (a == 2) {
		return "bp, (si)";
	}
	else if (a == 3) {
		return "bp, (di)";
	}
	else if (a == 4) {
		return "si";
	}
	else if (a == 5) {
		return "di";
	}
	else if (a == 6) {
		return "bp";
	}
	else if (a == 7) {
		return "bx";
	}
}

uint8_t i386_s8(uint8_t k) {
	if (k == 0) {
		return 1;
	}
	else if (k == 1) {
		return 2;
	}
	else if (k == 2) {
		return 4;
	}
	else if (k == 3) {
		return 8;
	}
}

uint8_t i386_dec_reg(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7);
		uint8_t mrs = ((bin[*bn] >> 3) & 7);
		
		if (mod == 0 && lga) {
			*bn += 1;
			printf("                              %s (%s), %s ", mn, i386_a16(mrd), i386_r8(mrs));
		}
		else if (mod == 1 && lga) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			printf("                           %s (%s, %u), %s ", mn, i386_a16(mrd), d, i386_r8(mrs));
		}
		else if (mod == 2 && lga) {
			*bn += 1;
			printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			printf("                        %s (%s, %u), %s ", mn, i386_a16(mrd), d, i386_r8(mrs));
		}
		else if (mod == 0) {
			if (mrd == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4 && (b & 7) == 5) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("               %s (%u), %s ", mn, d, i386_r8(mrs));
				}
				else if (i == 4) {
					*bn += 1;
					printf("                           %s (%s), %s ", mn, i386_r32(b), i386_r8(mrs));
				}
				else if (s) {
					*bn += 1;
					printf("                           %s (%s, (%s, %u)), %s ", mn, i386_r32(b), i386_r32(i), i386_s8(s), i386_r8(mrs));
				}
				else {
					*bn += 1;
					printf("                           %s (%s, (%s)), %s ", mn, i386_r32(b), i386_r32(i), i386_r8(mrs));
				}
			}
			else {
				*bn += 1;
				printf("                              %s (%s), %s ", mn, i386_r32(mrd), i386_r8(mrs));
			}
		}
		else if (mod == 3) {
			*bn += 1;
			printf("                           %s %s, %s ", mn, i386_r8(mrd), i386_r8(mrs));
		}
		return 0;
	}
}

void i386_dec(uint8_t* bin, uint64_t* bn, uint64_t* addr) {
	uint8_t lga = 0;
	uint8_t lgo = 0;
	
	if (bin[*bn] == 102) { //leg addr
		printf("66 ");
		lgo = 1;
		*bn += 1;
	}
	else {
		printf("   ");
	}
	
	if (bin[*bn] == 103) { //leg op
		printf("67 ");
		lga = 1;
		*bn += 1;
	}
	else {
		printf("   ");
	}
	
	uint8_t eo = 1;
	
	if (eo) {
		eo = i386_dec_reg(bin, bn, addr, 0, "add", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_reg(bin, bn, addr, 8, "or", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_reg(bin, bn, addr, 16, "adc", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_reg(bin, bn, addr, 24, "sbb", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_reg(bin, bn, addr, 32, "and", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_reg(bin, bn, addr, 40, "sub", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_reg(bin, bn, addr, 48, "xor", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_reg(bin, bn, addr, 56, "cmp", lga, lgo);
	}
	if (eo) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
	}
}
