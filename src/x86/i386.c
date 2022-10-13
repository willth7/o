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
		return "bx, si";
	}
	else if (a == 1) {
		return "bx, di";
	}
	else if (a == 2) {
		return "bp, si";
	}
	else if (a == 3) {
		return "bp, di";
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

uint8_t i386_dec_8r(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7);
		uint8_t mrs = ((bin[*bn] >> 3) & 7);
		
		if (mod == 0) {
			if (mrd == 5) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn];
				*bn += 4;
				printf("    %s (%u), %s ", mn, d, i386_r8(mrs));
			}
		}
		else if (mod == 3) {
			*bn += 1;
			printf("    %s %s, %s ", mn, i386_r8(mrd), i386_r8(mrs));
		}
		return 0;
	}
	if (bin[*bn] == op + 2) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7);
		uint8_t mrs = ((bin[*bn] >> 3) & 7);
		
		if (mod == 0) {
			if (mrd == 5) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn];
				*bn += 4;
				printf("    %s %s, (%u) ", mn, i386_r8(mrs), d);
			}
		}
		else if (mod == 3) {
			*bn += 1;
			printf("    %s %s, %s ", mn, i386_r8(mrs), i386_r8(mrd));
		}
		return 0;
	}
	else if (bin[*bn] == op + 4) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn += 1;
		printf("    %s al, %u ", mn, k);
		return 0;
	}
	return 1;
}

uint8_t i386_dec_16r(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo) {
	if (bin[*bn] == op + 1 && lgo) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7);
		uint8_t mrs = ((bin[*bn] >> 3) & 7);
		
		if (mod == 0 && lga) {
			*bn += 1;
			printf("    %s (%s), %s ", mn, i386_a16(mrd), i386_r16(mrs));
		}
		else if (mod == 0) {
			if (mrd == 5) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn];
				*bn += 4;
				printf("    %s (%u), %s ", mn, d, i386_r16(mrs));
			}
		}
		else if (mod == 1 && lga) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			printf("    %s (%s, %u), %s ", mn, i386_a16(mrd), d, i386_r16(mrs));
		}
		else if (mod == 2 && lga) {
			*bn += 1;
			printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn];
			*bn += 4;
			printf("    %s (%s, %u), %s ", mn, i386_a16(mrd), d, i386_r16(mrs));
		}
		else if (mod == 3) {
			*bn += 1;
			printf("    %s %s, %s ", mn, i386_r16(mrd), i386_r16(mrs));
		}
		return 0;
	}
	if (bin[*bn] == op + 3 && lgo) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7);
		uint8_t mrs = ((bin[*bn] >> 3) & 7);
		
		if (mod == 0 && lga) {
			*bn += 1;
			printf("    %s %s, (%s) ", mn, i386_r16(mrs), i386_a16(mrd));
		}
		else if (mod == 0) {
			if (mrd == 5) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn];
				*bn += 4;
				printf("    %s %s, (%u) ", mn, i386_r16(mrs), d);
			}
		}
		else if (mod == 1 && lga) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			printf("    %s %s, (%s, %u) ", mn, i386_r16(mrs), i386_a16(mrd), d);
		}
		else if (mod == 2 && lga) {
			*bn += 1;
			printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn];
			*bn += 4;
			printf("    %s %s, (%s, %u) ", mn, i386_r16(mrs), i386_a16(mrd), d);
		}
		else if (mod == 3) {
			*bn += 1;
			printf("    %s %s, %s ", mn, i386_r16(mrs), i386_r16(mrd));
		}
		return 0;
	}
	else if (bin[*bn] == op + 5 && lgo) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
		uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
		*bn += 2;
		printf("    %s ax, %u ", mn, k);
		return 0;
	}
	return 1;
}

uint8_t i386_dec_32r(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo) {
	if (bin[*bn] == op + 1) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7);
		uint8_t mrs = ((bin[*bn] >> 3) & 7);
		
		if (mod == 0) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i =  ((bin[*bn] >> 3) & 7);
				if (i == 4 && (b & 7) == 5) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("    %s (%u), %s ", mn, d, i386_r32(mrs));
				}
				else if (i == 4) {
					*bn += 1;
					printf("    %s (%s), %s ", mn, i386_r32(b), i386_r32(mrs));
				}
				else {
					*bn += 1;
					printf("    %s (%s, %s), %s ", mn, i386_r32(b), i386_r32(i), i386_r32(mrs));
				}
			}
			else if ((mrd & 7) == 5) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("    %s (eip, %u), %s ", mn, d, i386_r32(mrs));
			}
			else {
				*bn += 1;
				printf("    %s (%s), %s ", mn, i386_r32(mrd), i386_r32(mrs));
			}
		}
		else if (mod == 1) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i =  ((bin[*bn] >> 3) & 7);
				if (i == 4) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					printf("    %s (%s, %u), %s ", mn, i386_r32(b), d, i386_r32(mrs));
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					printf("    %s (%s, %s, %u), %s ", mn, i386_r32(b), i386_r32(i), d, i386_r32(mrs));
				}
			}
			else {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				printf("    %s (%s, %u), %s ", mn, i386_r32(mrd), d, i386_r32(mrs));
			}
		}
		else if (mod == 2) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i =  ((bin[*bn] >> 3) & 7);
				if (i == 4) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("    %s (%s, %u), %s ", mn, i386_r32(b), d, i386_r32(mrs));
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("    %s (%s, %s, %u), %s ", mn, i386_r32(b), i386_r32(i), d, i386_r32(mrs));
				}
			}
			else {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("    %s (%s, %u), %s ", mn, i386_r32(mrd), d, i386_r32(mrs));
			}
		}
		else if (mod == 3) {
			*bn += 1;
			printf("    %s %s, %s ", mn, i386_r32(mrd), i386_r32(mrs));
		}
		return 0;
	}
	else if (bin[*bn] == op + 3) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7);
		uint8_t mrs = ((bin[*bn] >> 3) & 7);
		
		if (mod == 0) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i =  ((bin[*bn] >> 3) & 7);
				if (i == 4 && (b & 7) == 5) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("    %s %s, (%u) ", mn, i386_r32(mrs), d);
				}
				else if (i == 4) {
					*bn += 1;
					printf("    %s %s, (%s) ", mn, i386_r32(mrs), i386_r32(b));
				}
				else {
					*bn += 1;
					printf("    %s %s, (%s, %s) ", mn, i386_r32(mrs), i386_r32(b), i386_r32(i));
				}
			}
			else if ((mrd & 7) == 5) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("    %s %s, (eip, %u) ", mn, i386_r32(mrs), d);
			}
			else {
				*bn += 1;
				printf("    %s %s, (%s) ", mn, i386_r32(mrs), i386_r32(mrd));
			}
		}
		else if (mod == 1) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i =  ((bin[*bn] >> 3) & 7);
				if (i == 4) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					printf("    %s %s, (%s, %u) ", mn, i386_r32(mrs), i386_r32(b), d);
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					printf("    %s %s, (%s, %s, %u) ", mn, i386_r32(mrs), i386_r32(b), i386_r32(i), d);
				}
			}
			else {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				printf("    %s %s, (%s, %u) ", mn, i386_r32(mrs), i386_r32(mrd), d);
			}
		}
		else if (mod == 2) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i =  ((bin[*bn] >> 3) & 7);
				if (i == 4) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("    %s %s, (%s, %u) ", mn, i386_r32(mrs), i386_r32(b), d);
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("    %s %s, (%s, %s, %u) ", mn, i386_r32(mrs), i386_r32(b), i386_r32(i), d);
				}
			}
			else {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("    %s %s, (%s, %u) ", mn, i386_r32(mrs), i386_r32(mrd), d);
			}
		}
		else if (mod == 3) {
			*bn += 1;
			printf("    %s %s, %s ", mn, i386_r32(mrs), i386_r32(mrd));
		}
		return 0;
	}
	else if (bin[*bn] == op + 5) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x %02x %02x %02x", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
		uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
		*bn += 4;
		printf("    %s eax, %u ", mn, k);
		return 0;
	}
	return 1;
}

void i386_dec(uint8_t* bin, uint64_t* bn, uint64_t* addr) {
	uint8_t lga = 0;
	uint8_t lgo = 0;
	
	if (bin[*bn] == 103) { //leg addr
		printf("67 ");
		lga = 1;
		*bn += 1;
	}
	
	if (bin[*bn] == 102) { //leg op
		printf("66 ");
		lgo = 1;
		*bn += 1;
	}
	
	uint8_t eo = 1;
	
	if (eo) {
		eo = i386_dec_8r(bin, bn, addr, 0, "add", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_16r(bin, bn, addr, 0, "add", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_32r(bin, bn, addr, 0, "add", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_8r(bin, bn, addr, 8, "or", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_16r(bin, bn, addr, 8, "or", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_32r(bin, bn, addr, 8, "or", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_8r(bin, bn, addr, 16, "adc", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_16r(bin, bn, addr, 16, "adc", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_32r(bin, bn, addr, 16, "adc", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_8r(bin, bn, addr, 024, "sbb", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_16r(bin, bn, addr, 24, "sbb", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_32r(bin, bn, addr, 24, "sbb", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_8r(bin, bn, addr, 32, "and", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_16r(bin, bn, addr, 32, "and", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_32r(bin, bn, addr, 32, "and", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_8r(bin, bn, addr, 40, "sub", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_16r(bin, bn, addr, 40, "sub", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_32r(bin, bn, addr, 40, "sub", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_8r(bin, bn, addr, 48, "xor", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_16r(bin, bn, addr, 48, "xor", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_32r(bin, bn, addr, 48, "xor", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_8r(bin, bn, addr, 56, "cmp", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_16r(bin, bn, addr, 56, "cmp", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_32r(bin, bn, addr, 56, "cmp", lga, lgo);
	}
	if (eo) {
		*bn += 1000;
	}
}
