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

int8_t* x86_64_r8(uint8_t r) {
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

int8_t* x86_64_r8x(uint8_t r) {
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
		return "spl";
	}
	else if (r == 5) {
		return "bpl";
	}
	else if (r == 6) {
		return "sil";
	}
	else if (r == 7) {
		return "dil";
	}
	else if (r == 8) {
		return "r8b";
	}
	else if (r == 9) {
		return "r9b";
	}
	else if (r == 10) {
		return "r10b";
	}
	else if (r == 11) {
		return "r11b";
	}
	else if (r == 12) {
		return "r12b";
	}
	else if (r == 13) {
		return "r13b";
	}
	else if (r == 14) {
		return "r14b";
	}
	else if (r == 15) {
		return "r15b";
	}
}

int8_t* x86_64_r16(uint8_t r) {
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
	else if (r == 8) {
		return "r8w";
	}
	else if (r == 9) {
		return "r9w";
	}
	else if (r == 10) {
		return "r10w";
	}
	else if (r == 11) {
		return "r11w";
	}
	else if (r == 12) {
		return "r12w";
	}
	else if (r == 13) {
		return "r13w";
	}
	else if (r == 14) {
		return "r14w";
	}
	else if (r == 15) {
		return "r15w";
	}
}

int8_t* x86_64_r32(uint8_t r) {
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
	else if (r == 8) {
		return "r8d";
	}
	else if (r == 9) {
		return "r9d";
	}
	else if (r == 10) {
		return "r10d";
	}
	else if (r == 11) {
		return "r11d";
	}
	else if (r == 12) {
		return "r12d";
	}
	else if (r == 13) {
		return "r13d";
	}
	else if (r == 14) {
		return "r14d";
	}
	else if (r == 15) {
		return "r15d";
	}
}

int8_t* x86_64_r64(uint8_t r) {
	if (r == 0) {
		return "rax";
	}
	else if (r == 1) {
		return "rcx";
	}
	else if (r == 2) {
		return "rdx";
	}
	else if (r == 3) {
		return "rbx";
	}
	else if (r == 4) {
		return "rsp";
	}
	else if (r == 5) {
		return "rbp";
	}
	else if (r == 6) {
		return "rsi";
	}
	else if (r == 7) {
		return "rdi";
	}
	else if (r == 8) {
		return "r8";
	}
	else if (r == 9) {
		return "r9";
	}
	else if (r == 10) {
		return "r10";
	}
	else if (r == 11) {
		return "r11";
	}
	else if (r == 12) {
		return "r12";
	}
	else if (r == 13) {
		return "r13";
	}
	else if (r == 14) {
		return "r14";
	}
	else if (r == 15) {
		return "r15";
	}
}

uint8_t x86_64_dec_8r(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		uint8_t mrs = ((bin[*bn] >> 3) & 7) + (8 * rx2);
		
		if (mod == 0 && rex) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i =  ((bin[*bn] >> 3) & 7) + (8 * rx1);
				if (i == 4 && (b & 7) == 5) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("    %s (%u), %s ", mn, d, x86_64_r8x(mrs));
				}
			}
		}
		else if (mod == 0) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i =  ((bin[*bn] >> 3) & 7) + (8 * rx1);
				if (i == 4 && (b & 7) == 5) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("    %s (%u), %s ", mn, d, x86_64_r8(mrs));
				}
			}
		}
		else if (mod == 3 && rex) {
			*bn += 1;
			printf("    %s %s, %s ", mn, x86_64_r8x(mrd), x86_64_r8x(mrs));
		}
		else if (mod == 3) {
			*bn += 1;
			printf("    %s %s, %s ", mn, x86_64_r8(mrd), x86_64_r8(mrs));
		}
		return 0;
	}
	else if (bin[*bn] == op + 2) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		uint8_t mrs = ((bin[*bn] >> 3) & 7) + (8 * rx2);
		
		if (mod == 0 && rex) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i =  ((bin[*bn] >> 3) & 7) + (8 * rx1);
				if (i == 4 && (b & 7) == 5) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("    %s %s, (%u) ", mn, x86_64_r8x(mrs), d);
				}
			}
		}
		else if (mod == 0) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i =  ((bin[*bn] >> 3) & 7) + (8 * rx1);
				if (i == 4 && (b & 7) == 5) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("    %s %s, (%u) ", mn, x86_64_r8(mrs), d);
				}
			}
		}
		else if (mod == 3 && rex) {
			*bn += 1;
			printf("    %s %s, %s ", mn, x86_64_r8x(mrs), x86_64_r8x(mrd));
		}
		else if (mod == 3) {
			*bn += 1;
			printf("    %s %s, %s ", mn, x86_64_r8(mrs), x86_64_r8(mrd));
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

uint8_t x86_64_dec_16r(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op + 1 && lgo) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		uint8_t mrs = ((bin[*bn] >> 3) & 7) + (8 * rx2);
		
		if (mod == 0) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i =  ((bin[*bn] >> 3) & 7) + (8 * rx1);
				if (i == 4 && (b & 7) == 5) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("    %s (%u), %s ", mn, d, x86_64_r16(mrs));
				}
			}
		}
		else if (mod == 3) {
			*bn += 1;
			printf("    %s %s, %s ", mn, x86_64_r16(mrd), x86_64_r16(mrs));
		}
		return 0;
	}
	if (bin[*bn] == op + 3 && lgo) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		uint8_t mrs = ((bin[*bn] >> 3) & 7) + (8 * rx2);
		
		if (mod == 0) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i =  ((bin[*bn] >> 3) & 7) + (8 * rx1);
				if (i == 4 && (b & 7) == 5) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("    %s %s, (%u) ", mn, x86_64_r16(mrs), d);
				}
			}
		}
		else if (mod == 3) {
			*bn += 1;
			printf("    %s %s, %s ", mn, x86_64_r16(mrd), x86_64_r16(mrs));
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

uint8_t x86_64_dec_32r(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op + 1 && !rx3) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		uint8_t mrs = ((bin[*bn] >> 3) & 7) + (8 * rx2);
		
		if (mod == 0 && lga) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i =  ((bin[*bn] >> 3) & 7) + (8 * rx1);
				if (i == 4) {
					*bn += 1;
					printf("    %s (%s), %s ", mn, x86_64_r32(b), x86_64_r32(mrs));
				}
				else {
					*bn += 1;
					printf("    %s (%s, %s), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_r32(mrs));
				}
			}
			else if ((mrd & 7) == 5) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("    %s (eip, %u), %s ", mn, d, x86_64_r32(mrs));
			}
			else {
				*bn += 1;
				printf("    %s (%s), %s ", mn, x86_64_r32(mrd), x86_64_r32(mrs));
			}
		}
		else if (mod == 0) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i =  ((bin[*bn] >> 3) & 7) + (8 * rx1);
				if (i == 4 && (b & 7) == 5) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("    %s (%u), %s ", mn, d, x86_64_r32(mrs));
				}
				else {
					*bn += 1;
					printf("    %s (%s, %s), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_r32(mrs));
				}
			}
		}
		else if (mod == 1 && lga) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i =  ((bin[*bn] >> 3) & 7) + (8 * rx1);
				if (i == 4) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					printf("    %s (%s, %u), %s ", mn, x86_64_r32(b), d, x86_64_r32(mrs));
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					printf("    %s (%s, %s, %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), d, x86_64_r32(mrs));
				}
			}
			else {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				printf("    %s (%s, %u), %s ", mn, x86_64_r32(mrd), d, x86_64_r32(mrs));
			}
		}
		else if (mod == 2 && lga) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i =  ((bin[*bn] >> 3) & 7) + (8 * rx1);
				if (i == 4) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("    %s (%s, %u), %s ", mn, x86_64_r32(b), d, x86_64_r32(mrs));
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("    %s (%s, %s, %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), d, x86_64_r32(mrs));
				}
			}
			else {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("    %s (%s, %u), %s ", mn, x86_64_r32(mrd), d, x86_64_r32(mrs));
			}
		}
		else if (mod == 3) {
			*bn += 1;
			printf("    %s %s, %s ", mn, x86_64_r32(mrd), x86_64_r32(mrs));
		}
		return 0;
	}
	else if (bin[*bn] == op + 3 && !rx3) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		uint8_t mrs = ((bin[*bn] >> 3) & 7) + (8 * rx2);
		
		if (mod == 0 && lga) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i =  ((bin[*bn] >> 3) & 7) + (8 * rx1);
				if (i == 4) {
					*bn += 1;
					printf("    %s %s, (%s) ", mn, x86_64_r32(mrs), x86_64_r32(b));
				}
				else {
					*bn += 1;
					printf("    %s %s, (%s, %s) ", mn, x86_64_r32(mrs), x86_64_r32(b), x86_64_r32(i));
				}
			}
			else if ((mrd & 7) == 5) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("    %s %s, (eip, %u) ", mn, x86_64_r32(mrs), d);
			}
			else {
				*bn += 1;
				printf("    %s %s, (%s) ", mn, x86_64_r32(mrs), x86_64_r32(mrd));
			}
		}
		else if (mod == 0) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i =  ((bin[*bn] >> 3) & 7) + (8 * rx1);
				if (i == 4 && (b & 7) == 5) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("    %s %s, (%u) ", mn, x86_64_r32(mrs), d);
				}
				else {
					*bn += 1;
					printf("    %s %s, (%s, %s) ", mn, x86_64_r32(mrs), x86_64_r32(b), x86_64_r32(i));
				}
			}
		}
		else if (mod == 1 && lga) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i =  ((bin[*bn] >> 3) & 7) + (8 * rx1);
				if (i == 4) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					printf("    %s %s, (%s, %u) ", mn, x86_64_r32(mrs), x86_64_r32(b), d);
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					printf("    %s %s, (%s, %s, %u) ", mn, x86_64_r32(mrs), x86_64_r32(b), x86_64_r32(i), d);
				}
			}
			else {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				printf("    %s %s, (%s, %u) ", mn, x86_64_r32(mrs), x86_64_r32(mrd), d);
			}
		}
		else if (mod == 2 && lga) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i =  ((bin[*bn] >> 3) & 7) + (8 * rx1);
				if (i == 4) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("    %s %s, (%s, %u) ", mn, x86_64_r32(mrs), x86_64_r32(b), d);
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("    %s %s, (%s, %s, %u) ", mn, x86_64_r32(mrs), x86_64_r32(b), x86_64_r32(i), d);
				}
			}
			else {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("    %s %s, (%s, %u) ", mn, x86_64_r32(mrs), x86_64_r32(mrd), d);
			}
		}
		else if (mod == 3) {
			*bn += 1;
			printf("    %s %s, %s ", mn, x86_64_r32(mrs), x86_64_r32(mrd));
		}
		return 0;
	}
	else if (bin[*bn] == op + 5 && !rx3) {
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

uint8_t x86_64_dec_64r(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op + 1) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		uint8_t mrs = ((bin[*bn] >> 3) & 7) + (8 * rx2);
		
		if (mod == 0) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i =  ((bin[*bn] >> 3) & 7) + (8 * rx1);
				if (i == 4 && (b & 7) == 5) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("    %s (%u), %s ", mn, d, x86_64_r64(mrs));
				}
				else if (i == 4) {
					*bn += 1;
					printf("    %s (%s), %s ", mn, x86_64_r64(b), x86_64_r64(mrs));
				}
				else {
					*bn += 1;
					printf("    %s (%s, %s), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_r64(mrs));
				}
			}
			else if ((mrd & 7) == 5) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("    %s (rip, %u), %s ", mn, d, x86_64_r64(mrs));
			}
			else {
				*bn += 1;
				printf("    %s (%s), %s ", mn, x86_64_r64(mrd), x86_64_r64(mrs));
			}
		}
		else if (mod == 1) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i =  ((bin[*bn] >> 3) & 7) + (8 * rx1);
				if (i == 4) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					printf("    %s (%s, %u), %s ", mn, x86_64_r64(b), d, x86_64_r64(mrs));
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					printf("    %s (%s, %s), %s ", mn, x86_64_r64(b), x86_64_r64(i), d, x86_64_r64(mrs));
				}
			}
			else {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				printf("    %s (%s, %u), %s ", mn, x86_64_r64(mrd), d, x86_64_r64(mrs));
			}
		}
		else if (mod == 2) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i =  ((bin[*bn] >> 3) & 7) + (8 * rx1);
				if (i == 4) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("    %s (%s, %u), %s ", mn, x86_64_r64(b), d, x86_64_r64(mrs));
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("    %s (%s, %s, %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), d, x86_64_r64(mrs));
				}
			}
			else {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("    %s (%s, %u), %s ", mn, x86_64_r64(mrd), d, x86_64_r64(mrs));
			}
		}
		else if (mod == 3) {
			*bn += 1;
			printf("    %s %s, %s ", mn, x86_64_r64(mrd), x86_64_r64(mrs));
		}
		return 0;
	}
	else if (bin[*bn] == op + 3) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		uint8_t mrs = ((bin[*bn] >> 3) & 7) + (8 * rx2);
		
		if (mod == 0) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i =  ((bin[*bn] >> 3) & 7) + (8 * rx1);
				if (i == 4 && (b & 7) == 5) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("    %s %s, (%u) ", mn, x86_64_r64(mrs), d);
				}
				else if (i == 4) {
					*bn += 1;
					printf("    %s %s, (%s) ", mn, x86_64_r64(mrs), x86_64_r64(b));
				}
				else {
					*bn += 1;
					printf("    %s %s, (%s, %s) ", mn, x86_64_r64(mrs), x86_64_r64(b), x86_64_r64(i));
				}
			}
			else if ((mrd & 7) == 5) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("    %s %s, (rip, %u) ", mn, x86_64_r64(mrs), d);
			}
			else {
				*bn += 1;
				printf("    %s %s, (%s) ", mn, x86_64_r64(mrs), x86_64_r64(mrd));
			}
		}
		else if (mod == 1) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i =  ((bin[*bn] >> 3) & 7) + (8 * rx1);
				if (i == 4) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					printf("    %s %s, (%s, %u) ", mn, x86_64_r64(mrs), x86_64_r64(b), d);
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					printf("    %s %s, (%s, %s, %u) ", mn, x86_64_r64(mrs), x86_64_r64(b), x86_64_r64(i), d);
				}
			}
			else {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				printf("    %s %s, (%s, %u) ", mn, x86_64_r64(mrs), x86_64_r64(mrd), d);
			}
		}
		else if (mod == 2) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i =  ((bin[*bn] >> 3) & 7) + (8 * rx1);
				if (i == 4) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("    %s %s, (%s, %u) ", mn, x86_64_r64(mrs), x86_64_r64(b), d);
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("    %s %s, (%s, %s, %u) ", mn, x86_64_r64(mrs), x86_64_r64(b), x86_64_r64(i), d);
				}
			}
			else {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("    %s %s, (%s, %u) ", mn, x86_64_r64(mrs), x86_64_r64(mrd), d);
			}
		}
		else if (mod == 3) {
			*bn += 1;
			printf("    %s %s, %s ", mn, x86_64_r64(mrs), x86_64_r64(mrd));
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

void x86_64_dec(uint8_t* bin, uint64_t* bn, uint64_t* addr) {
	uint8_t lga = 0;
	uint8_t lgo = 0;
	uint8_t rex = 0;
	uint8_t rx0 = 0;
	uint8_t rx1 = 0;
	uint8_t rx2 = 0;
	uint8_t rx3 = 0;
	
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
	
	if ((bin[*bn] & 240) == 64) { //rex
		printf("%02x ", bin[*bn]);
		rex = 1;
		if (bin[*bn] & 1) {
			rx0 = 1;
		}
		if (bin[*bn] & 2) {
			rx1 = 1;
		}
		if (bin[*bn] & 4) {
			rx2 = 1;
		}
		if (bin[*bn] & 8) {
			rx3 = 1;
		}
		*bn += 1;
	}
	
	uint8_t eo = 1;
	
	if (eo) {
		eo = x86_64_dec_8r(bin, bn, addr, 0, "add", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_16r(bin, bn, addr, 0, "add", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_32r(bin, bn, addr, 0, "add", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_64r(bin, bn, addr, 0, "add", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_8r(bin, bn, addr, 8, "or", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_16r(bin, bn, addr, 8, "or", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_32r(bin, bn, addr, 8, "or", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_64r(bin, bn, addr, 8, "or", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_8r(bin, bn, addr, 16, "adc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_16r(bin, bn, addr, 16, "adc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_32r(bin, bn, addr, 16, "adc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_64r(bin, bn, addr, 16, "adc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_8r(bin, bn, addr, 24, "sbb", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_16r(bin, bn, addr, 24, "sbb", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_32r(bin, bn, addr, 24, "sbb", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_64r(bin, bn, addr, 24, "sbb", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_8r(bin, bn, addr, 32, "and", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_16r(bin, bn, addr, 32, "and", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_32r(bin, bn, addr, 32, "and", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_64r(bin, bn, addr, 32, "and", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_8r(bin, bn, addr, 40, "sub", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_16r(bin, bn, addr, 40, "sub", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_32r(bin, bn, addr, 40, "sub", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_64r(bin, bn, addr, 40, "sub", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_8r(bin, bn, addr, 48, "xor", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_16r(bin, bn, addr, 48, "xor", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_32r(bin, bn, addr, 48, "xor", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_64r(bin, bn, addr, 48, "xor", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_8r(bin, bn, addr, 56, "cmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_16r(bin, bn, addr, 56, "cmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_32r(bin, bn, addr, 56, "cmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_64r(bin, bn, addr, 56, "cmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		*bn += 1000;
	}
}
