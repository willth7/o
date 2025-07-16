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

int8_t* x86_r8(uint8_t r) {
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

int8_t* x86_r16(uint8_t r) {
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

int8_t* x86_a16(uint8_t a) {
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

uint8_t x86_dec_r80(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7);
		uint8_t mrs = ((bin[*bn] >> 3) & 7);
		
		if (mod == 0) {
			if (mrd == 6) {
				*bn += 1;
				printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				printf("         %s (%u), %s ", mn, d, x86_r8(mrs));
			}
			else {
				*bn += 1;
				printf("               %s (%s), %s ", mn, x86_a16(mrd), x86_r8(mrs));
			}
		}
		else if (mod == 1) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			printf("            %s (%s, %u), %s ", mn, x86_a16(mrd), d, x86_r8(mrs));
		}
		else if (mod == 2) {
			*bn += 1;
			printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			printf("         %s (%s, %u), %s ", mn, x86_a16(mrd), d, x86_r8(mrs));
		}
		else if (mod == 3) {
			*bn += 1;
			printf("               %s %s, %s ", mn, x86_r8(mrd), x86_r8(mrs));
		}
		return 0;
	}
	return 1;
}

uint8_t x86_dec_rg0(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7);
		uint8_t mrs = ((bin[*bn] >> 3) & 7);
		
		if (mod == 0) {
			if (mrd == 6) {
				*bn += 1;
				printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				printf("         %s (%u), %s ", mn, d, x86_r16(mrs));
			}
			else {
				*bn += 1;
				printf("               %s (%s), %s ", mn, x86_a16(mrd), x86_r16(mrs));
			}
		}
		else if (mod == 1) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			printf("            %s (%s, %u), %s ", mn, x86_a16(mrd), d, x86_r16(mrs));
		}
		else if (mod == 2) {
			*bn += 1;
			printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			printf("         %s (%s, %u), %s ", mn, x86_a16(mrd), d, x86_r16(mrs));
		}
		else if (mod == 3) {
			*bn += 1;
			printf("               %s %s, %s ", mn, x86_r16(mrd), x86_r16(mrs));
		}
		return 0;
	}
	return 1;
}

uint8_t x86_dec_r81(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7);
		uint8_t mrs = ((bin[*bn] >> 3) & 7);
		
		if (mod == 0) {
			if (mrd == 6) {
				*bn += 1;
				printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				printf("         %s %s, (%u) ", mn, x86_r8(mrs), d);
			}
			else {
				*bn += 1;
				printf("               %s %s, (%s) ", mn, x86_r8(mrs), x86_a16(mrd));
			}
		}
		else if (mod == 1) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			printf("            %s %s, (%s, %u) ", mn, x86_r8(mrs), x86_a16(mrd), d);
		}
		else if (mod == 2) {
			*bn += 1;
			printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			printf("         %s %s, (%s, %u) ", mn, x86_r8(mrs), x86_a16(mrd), d);
		}
		else if (mod == 3) {
			*bn += 1;
			printf("               %s %s, %s ", mn, x86_r8(mrs), x86_r8(mrd));
		}
		return 0;
	}
	return 1;
}

uint8_t x86_dec_rg1(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7);
		uint8_t mrs = ((bin[*bn] >> 3) & 7);
		
		if (mod == 0) {
			if (mrd == 6) {
				*bn += 1;
				printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				printf("         %s %s, (%u) ", mn, x86_r16(mrs), d);
			}
			else {
				*bn += 1;
				printf("               %s %s, (%s) ", mn, x86_r16(mrs), x86_a16(mrd));
			}
		}
		else if (mod == 1) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			printf("            %s %s, (%s, %u) ", mn, x86_r16(mrs), x86_a16(mrd), d);
		}
		else if (mod == 2) {
			*bn += 1;
			printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			printf("         %s %s, (%s, %u) ", mn, x86_r16(mrs), x86_a16(mrd), d);
		}
		else if (mod == 3) {
			*bn += 1;
			printf("               %s %s, %s ", mn, x86_r16(mrs), x86_r16(mrd));
		}
		return 0;
	}
	return 1;
}

uint8_t x86_dec_ral(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("         %02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn += 1;
		printf("      %s al, %u ", mn, k);
		return 0;
	}
	return 1;
}

uint8_t x86_dec_rax(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("         %02x %02x ", bin[*bn], bin[*bn + 1]);
		uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
		*bn += 2;
		printf("   %s ax, %u ", mn, k);
		return 0;
	}
	return 1;
}

uint8_t x86_dec_k80(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn) {
	if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (mrd == 6) {
			*bn += 1;
			printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			printf("%02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn += 1;
			printf("      %sb (%u), %u ", mn, d, k);
		}
		else {
			*bn += 1;
			printf("      %02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn += 1;
			printf("      %sb (%s), %u ", mn, x86_a16(mrd), k);
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t d = bin[*bn];
		*bn += 1;
		printf("   %02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn += 1;
		printf("      %sb (%s, %u), %u ", mn, x86_a16(mrd), d, k);
		
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		*bn += 1;
		printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
		uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
		*bn += 2;
		printf("%02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn += 1;
		printf("      %sb (%s, %u), %u ", mn, x86_a16(mrd), d, k);
		
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		*bn += 1;
		printf("      %02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn += 1;
		printf("      %sb %s, %u ", mn, x86_r8(mrd), k);
		
		return 0;
	}
	return 1;
}

uint8_t x86_dec_imm(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn) {
	if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (mrd == 6) {
			*bn += 1;
			printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);;
			*bn += 2;
			printf("   %sw (%u), %u ", mn, d, k);
		}
		else {
			*bn += 1;
			printf("      %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);;
			*bn += 2;
			printf("   %sw (%s), %u ", mn, x86_a16(mrd), k);
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t d = bin[*bn];
		*bn += 1;
		printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
		uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);;
		*bn += 2;
		printf("   %sw (%s, %u), %u ", mn, x86_a16(mrd), d, k);
		
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		*bn += 1;
		printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
		uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
		*bn += 2;
		printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
		uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);;
		*bn += 2;
		printf("   %sw (%s, %u), %u ", mn, x86_a16(mrd), d, k);
		
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		*bn += 1;
		printf("      %02x %02x ", bin[*bn], bin[*bn + 1]);
		uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);;
		*bn += 2;
		printf("   %sw %s, %u ", mn, x86_r8(mrd), k);
		
		return 0;
	}
	return 1;
}

uint8_t x86_dec_k81(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn) {
	if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (mrd == 6) {
			*bn += 1;
			printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			printf("%02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn += 1;
			printf("      %sw (%u), %u ", mn, d, k);
		}
		else {
			*bn += 1;
			printf("      %02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn += 1;
			printf("      %sw (%s), %u ", mn, x86_a16(mrd), k);
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t d = bin[*bn];
		*bn += 1;
		printf("   %02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn += 1;
		printf("      %sw (%s, %u), %u ", mn, x86_a16(mrd), d, k);
		
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		*bn += 1;
		printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
		uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
		*bn += 2;
		printf("%02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn += 1;
		printf("      %sw (%s, %u), %u ", mn, x86_a16(mrd), d, k);
		
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		*bn += 1;
		printf("      %02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn += 1;
		printf("      %sw %s, %u ", mn, x86_r8(mrd), k);
		
		return 0;
	}
	return 1;
}

uint8_t x86_dec_stck(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn) {
	if ((bin[*bn] & 248) == op) {
		printf("%02x ", bin[*bn]);
		uint8_t reg = (bin[*bn] & 7); 
		*bn += 1;
		
		printf("                                 %s %s ", mn, x86_r16(reg));
		return 0;
	}
	return 1;
}

uint8_t x86_dec_op_imm(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		
		printf("         %02x %02x ", bin[*bn], bin[*bn + 1]);
		uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
		*bn += 2;
		printf("%s %u ", mn, k);
		
		return 0;
	}
	else if (bin[*bn] == op + 2) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		
		printf("         %02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn += 1;
		printf("   %s %u ", mn, k);
		return 0;
	}
	return 1;
}

uint8_t x86_dec_blnk(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn) {
	if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (mrd == 6) {
			*bn += 1;
			printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			printf("      %s (%u) ", mn, d);
		}
		else {
			*bn += 1;
			printf("            %s (%s) ", mn, x86_a16(mrd));
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t d = bin[*bn];
		*bn += 1;
		printf("         %s (%s, %u) ", mn, x86_a16(mrd), d);
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		*bn += 1;
		printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
		uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);;
		*bn += 2;
		printf("      %s (%s, %u) ", mn, x86_a16(mrd), d);
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		*bn += 1;
		printf("            %s %s ", mn, x86_r16(mrd));
		return 0;
	}
	return 1;
}

uint8_t x86_dec_jmp(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		
		printf("   %02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn += 1;
		
		printf("      %s %u ", mn, k);
		return 0;
	}
	return 1;
}

uint8_t x86_dec_byt(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		
		printf("               %s", mn);
		return 0;
	}
	return 1;
}

void x86_dec(uint8_t* bin, uint64_t* bn, uint64_t* addr) {
	uint8_t eo = 1;
	if (eo) {
		eo = x86_dec_r80(bin, bn, addr, 0, "add");
	}
	if (eo) {
		eo = x86_dec_rg0(bin, bn, addr, 1, "add");
	}
	if (eo) {
		eo = x86_dec_r81(bin, bn, addr, 2, "add");
	}
	if (eo) {
		eo = x86_dec_rg1(bin, bn, addr, 3, "add");
	}
	if (eo) {
		eo = x86_dec_ral(bin, bn, addr, 4, "add");
	}
	if (eo) {
		eo = x86_dec_rax(bin, bn, addr, 5, "add");
	}
	if (eo) {
		eo = x86_dec_r80(bin, bn, addr, 8, "or");
	}
	if (eo) {
		eo = x86_dec_rg0(bin, bn, addr, 9, "or");
	}
	if (eo) {
		eo = x86_dec_r81(bin, bn, addr, 10, "or");
	}
	if (eo) {
		eo = x86_dec_rg1(bin, bn, addr, 11, "or");
	}
	if (eo) {
		eo = x86_dec_ral(bin, bn, addr, 12, "or");
	}
	if (eo) {
		eo = x86_dec_rax(bin, bn, addr, 13, "or");
	}
	if (eo) {
		eo = x86_dec_r80(bin, bn, addr, 16, "adc");
	}
	if (eo) {
		eo = x86_dec_rg0(bin, bn, addr, 17, "adc");
	}
	if (eo) {
		eo = x86_dec_r81(bin, bn, addr, 18, "adc");
	}
	if (eo) {
		eo = x86_dec_rg1(bin, bn, addr, 19, "adc");
	}
	if (eo) {
		eo = x86_dec_ral(bin, bn, addr, 20, "adc");
	}
	if (eo) {
		eo = x86_dec_rax(bin, bn, addr, 21, "adc");
	}
	if (eo) {
		eo = x86_dec_r80(bin, bn, addr, 24, "sbb");
	}
	if (eo) {
		eo = x86_dec_rg0(bin, bn, addr, 25, "sbb");
	}
	if (eo) {
		eo = x86_dec_r81(bin, bn, addr, 26, "sbb");
	}
	if (eo) {
		eo = x86_dec_rg1(bin, bn, addr, 27, "sbb");
	}
	if (eo) {
		eo = x86_dec_ral(bin, bn, addr, 28, "sbb");
	}
	if (eo) {
		eo = x86_dec_rax(bin, bn, addr, 29, "sbb");
	}
	if (eo) {
		eo = x86_dec_r80(bin, bn, addr, 32, "and");
	}
	if (eo) {
		eo = x86_dec_rg0(bin, bn, addr, 33, "and");
	}
	if (eo) {
		eo = x86_dec_r81(bin, bn, addr, 34, "and");
	}
	if (eo) {
		eo = x86_dec_rg1(bin, bn, addr, 35, "and");
	}
	if (eo) {
		eo = x86_dec_ral(bin, bn, addr, 36, "and");
	}
	if (eo) {
		eo = x86_dec_rax(bin, bn, addr, 37, "and");
	}
	if (eo) {
		eo = x86_dec_r80(bin, bn, addr, 40, "sub");
	}
	if (eo) {
		eo = x86_dec_rg0(bin, bn, addr, 41, "sub");
	}
	if (eo) {
		eo = x86_dec_r81(bin, bn, addr, 42, "sub");
	}
	if (eo) {
		eo = x86_dec_rg1(bin, bn, addr, 43, "sub");
	}
	if (eo) {
		eo = x86_dec_ral(bin, bn, addr, 44, "sub");
	}
	if (eo) {
		eo = x86_dec_rax(bin, bn, addr, 45, "sub");
	}
	if (eo) {
		eo = x86_dec_r80(bin, bn, addr, 48, "xor");
	}
	if (eo) {
		eo = x86_dec_rg0(bin, bn, addr, 49, "xor");
	}
	if (eo) {
		eo = x86_dec_r81(bin, bn, addr, 50, "xor");
	}
	if (eo) {
		eo = x86_dec_rg1(bin, bn, addr, 51, "xor");
	}
	if (eo) {
		eo = x86_dec_ral(bin, bn, addr, 52, "xor");
	}
	if (eo) {
		eo = x86_dec_rax(bin, bn, addr, 53, "xor");
	}
	if (eo) {
		eo = x86_dec_r80(bin, bn, addr, 56, "cmp");
	}
	if (eo) {
		eo = x86_dec_rg0(bin, bn, addr, 57, "cmp");
	}
	if (eo) {
		eo = x86_dec_r81(bin, bn, addr, 58, "cmp");
	}
	if (eo) {
		eo = x86_dec_rg1(bin, bn, addr, 59, "cmp");
	}
	if (eo) {
		eo = x86_dec_ral(bin, bn, addr, 60, "cmp");
	}
	if (eo) {
		eo = x86_dec_rax(bin, bn, addr, 61, "cmp");
	}
	if (eo) {
		eo = x86_dec_stck(bin, bn, addr, 80, "push");
	}
	if (eo) {
		eo = x86_dec_stck(bin, bn, addr, 88, "pop");
	}
	if (eo) {
		eo = x86_dec_op_imm(bin, bn, addr, 104, "push");
	}
	if (eo) {
		eo = x86_dec_jmp(bin, bn, addr, 112, "jo");
	}
	if (eo) {
		eo = x86_dec_jmp(bin, bn, addr, 113, "jno");
	}
	if (eo) {
		eo = x86_dec_jmp(bin, bn, addr, 114, "jc");
	}
	if (eo) {
		eo = x86_dec_jmp(bin, bn, addr, 115, "jnc");
	}
	if (eo) {
		eo = x86_dec_jmp(bin, bn, addr, 116, "je");
	}
	if (eo) {
		eo = x86_dec_jmp(bin, bn, addr, 117, "jne");
	}
	if (eo) {
		eo = x86_dec_jmp(bin, bn, addr, 118, "jna");
	}
	if (eo) {
		eo = x86_dec_jmp(bin, bn, addr, 119, "ja");
	}
	if (eo) {
		eo = x86_dec_jmp(bin, bn, addr, 120, "js");
	}
	if (eo) {
		eo = x86_dec_jmp(bin, bn, addr, 121, "jns");
	}
	if (eo) {
		eo = x86_dec_jmp(bin, bn, addr, 122, "jpe");
	}
	if (eo) {
		eo = x86_dec_jmp(bin, bn, addr, 123, "jpo");
	}
	if (eo) {
		eo = x86_dec_jmp(bin, bn, addr, 124, "jl");
	}
	if (eo) {
		eo = x86_dec_jmp(bin, bn, addr, 125, "jge");
	}
	if (eo) {
		eo = x86_dec_jmp(bin, bn, addr, 126, "jle");
	}
	if (eo) {
		eo = x86_dec_jmp(bin, bn, addr, 127, "jg");
	}
	if (eo) {
		eo = x86_dec_k80(bin, bn, addr, 128, 0, "add");
	}
	if (eo) {
		eo = x86_dec_k80(bin, bn, addr, 128, 1, "or");
	}
	if (eo) {
		eo = x86_dec_k80(bin, bn, addr, 128, 2, "adc");
	}
	if (eo) {
		eo = x86_dec_k80(bin, bn, addr, 128, 3, "sbb");
	}
	if (eo) {
		eo = x86_dec_k80(bin, bn, addr, 128, 4, "and");
	}
	if (eo) {
		eo = x86_dec_k80(bin, bn, addr, 128, 5, "sub");
	}
	if (eo) {
		eo = x86_dec_k80(bin, bn, addr, 128, 6, "xor");
	}
	if (eo) {
		eo = x86_dec_k80(bin, bn, addr, 128, 7, "cmp");
	}
	if (eo) {
		eo = x86_dec_imm(bin, bn, addr, 129, 0, "add");
	}
	if (eo) {
		eo = x86_dec_imm(bin, bn, addr, 129, 1, "or");
	}
	if (eo) {
		eo = x86_dec_imm(bin, bn, addr, 129, 2, "adc");
	}
	if (eo) {
		eo = x86_dec_imm(bin, bn, addr, 129, 3, "sbb");
	}
	if (eo) {
		eo = x86_dec_imm(bin, bn, addr, 129, 4, "and");
	}
	if (eo) {
		eo = x86_dec_imm(bin, bn, addr, 129, 5, "sub");
	}
	if (eo) {
		eo = x86_dec_imm(bin, bn, addr, 129, 6, "xor");
	}
	if (eo) {
		eo = x86_dec_imm(bin, bn, addr, 129, 7, "cmp");
	}
	if (eo) {
		eo = x86_dec_k81(bin, bn, addr, 131, 0, "add");
	}
	if (eo) {
		eo = x86_dec_k81(bin, bn, addr, 131, 1, "or");
	}
	if (eo) {
		eo = x86_dec_k81(bin, bn, addr, 131, 2, "adc");
	}
	if (eo) {
		eo = x86_dec_k81(bin, bn, addr, 131, 3, "sbb");
	}
	if (eo) {
		eo = x86_dec_k81(bin, bn, addr, 131, 4, "and");
	}
	if (eo) {
		eo = x86_dec_k81(bin, bn, addr, 131, 5, "sub");
	}
	if (eo) {
		eo = x86_dec_k81(bin, bn, addr, 131, 6, "xor");
	}
	if (eo) {
		eo = x86_dec_k81(bin, bn, addr, 131, 7, "cmp");
	}
	if (eo) {
		eo = x86_dec_r81(bin, bn, addr, 134, "xchg");
	}
	if (eo) {
		eo = x86_dec_rg1(bin, bn, addr, 135, "xchg");
	}
	if (eo) {
		eo = x86_dec_r80(bin, bn, addr, 136, "mov");
	}
	if (eo) {
		eo = x86_dec_rg0(bin, bn, addr, 137, "mov");
	}
	if (eo) {
		eo = x86_dec_r81(bin, bn, addr, 138, "mov");
	}
	if (eo) {
		eo = x86_dec_rg1(bin, bn, addr, 139, "mov");
	}
	if (eo) {
		eo = x86_dec_rg1(bin, bn, addr, 141, "lea");
	}
	if (eo) {
		eo = x86_dec_blnk(bin, bn, addr, 143, 0, "pop");
	}
	if (eo) {
		eo = x86_dec_stck(bin, bn, addr, 144, "xchg");
	}
	if (eo) {
		eo = x86_dec_byt(bin, bn, addr, 156, "pushf");
	}
	if (eo) {
		eo = x86_dec_byt(bin, bn, addr, 157, "popf");
	}
	if (eo) {
		eo = x86_dec_byt(bin, bn, addr, 158, "sahf ah");
	}
	if (eo) {
		eo = x86_dec_byt(bin, bn, addr, 159, "lahf ah");
	}
	if (eo) {
		eo = x86_dec_blnk(bin, bn, addr, 255, 6, "push");
	}
	if (eo) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
	}	
}
