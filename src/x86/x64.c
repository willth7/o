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

uint8_t x86_64_s8(uint8_t k) {
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

uint8_t x86_64_dec_r80(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op) {
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
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4 && (b & 7) == 5) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (rex) {
						printf("               %s (%u), %s ", mn, d, x86_64_r8x(mrs));
					}
					else {
						printf("               %s (%u), %s ", mn, d, x86_64_r8(mrs));
					}
				}
				else if (i == 4) {
					*bn += 1;
					if (rex) {
						if (lga) {
							printf("                           %s (%s), %s ", mn, x86_64_r32(b), x86_64_r8x(mrs));
						}
						else {
							printf("                           %s (%s), %s ", mn, x86_64_r64(b), x86_64_r8x(mrs));
						}
					}
					else {
						if (lga) {
							printf("                           %s (%s), %s ", mn, x86_64_r32(b), x86_64_r8(mrs));
						}
						else {
							printf("                           %s (%s), %s ", mn, x86_64_r64(b), x86_64_r8(mrs));
						}
					}
				}
				else if (s) {
					*bn += 1;
					if (rex) {
						if (lga) {
							printf("                           %s (%s, (%s, %u)), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), x86_64_r8x(mrs));
						}
						else {
							printf("                           %s (%s, (%s, %u)), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), x86_64_r8x(mrs));
						}
					}
					else {
						if (lga) {
							printf("                           %s (%s, (%s, %u)), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), x86_64_r8(mrs));
						}
						else {
							printf("                           %s (%s, (%s, %u)), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), x86_64_r8(mrs));
						}
					}
				}
				else {
					*bn += 1;
					if (rex) {
						if (lga) {
							printf("                           %s (%s, (%s)), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_r8x(mrs));
						}
						else {
							printf("                           %s (%s, (%s)), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_r8x(mrs));
						}
					}
					else {
						if (lga) {
							printf("                           %s (%s, (%s)), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_r8(mrs));
						}
						else {
							printf("                           %s (%s, (%s)), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_r8(mrs));
						}
					}
				}
			}
			else if ((mrd & 7) == 5) {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (d) {
					if (rex) {
						if (lga) {
							printf("               %s (eip, %u), %s ", mn, d, x86_64_r8x(mrs));
						}
						else {
							printf("               %s (rip, %u), %s ", mn, d, x86_64_r8x(mrs));
						}
					}
					else {
						if (lga) {
							printf("               %s (eip, %u), %s ", mn, d, x86_64_r8(mrs));
						}
						else {
							printf("               %s (rip, %u), %s ", mn, d, x86_64_r8(mrs));
						}
					}
				}
				else {
					if (rex) {
						if (lga) {
							printf("               %s (eip), %s ", mn, x86_64_r8x(mrs));
						}
						else {
							printf("               %s (rip), %s ", mn, x86_64_r8x(mrs));
						}
					}
					else {
						if (lga) {
							printf("               %s (eip), %s ", mn, x86_64_r8(mrs));
						}
						else {
							printf("               %s (rip), %s ", mn, x86_64_r8(mrs));
						}
					}
				}
			}
			else {
				*bn += 1;
				if (rex) {
					if (lga) {
						printf("                              %s (%s), %s ", mn, x86_64_r32(mrd), x86_64_r8x(mrs));
					}
					else {
						printf("                              %s (%s), %s ", mn, x86_64_r64(mrd), x86_64_r8x(mrs));
					}
				}
				else {
					if (lga) {
						printf("                              %s (%s), %s ", mn, x86_64_r32(mrd), x86_64_r8(mrs));
					}
					else {
						printf("                              %s (%s), %s ", mn, x86_64_r64(mrd), x86_64_r8(mrs));
					}
				}
			}
		}
		else if (mod == 1) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (rex) {
						if (lga) {
							printf("                        %s (%s, %u), %s ", mn, x86_64_r32(b), d, x86_64_r8x(mrs));
						}
						else {
							printf("                        %s (%s, %u), %s ", mn, x86_64_r64(b), d, x86_64_r8x(mrs));
						}
					}
					else {
						if (lga) {
							printf("                        %s (%s, %u), %s ", mn, x86_64_r32(b), d, x86_64_r8(mrs));
						}
						else {
							printf("                        %s (%s, %u), %s ", mn, x86_64_r64(b), d, x86_64_r8(mrs));
						}
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (rex) {
						if (lga) {
							printf("                        %s (%s, (%s, %u), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, x86_64_r8x(mrs));
						}
						else {
							printf("                        %s (%s, (%s, %u), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, x86_64_r8x(mrs));
						}
					}
					else {
						if (lga) {
							printf("                        %s (%s, (%s, %u), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, x86_64_r8(mrs));
						}
						else {
							printf("                        %s (%s, (%s, %u), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, x86_64_r8(mrs));
						}
					}
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (rex) {
						if (lga) {
							printf("                        %s (%s, (%s), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), d, x86_64_r8x(mrs));
						}
						else {
							printf("                        %s (%s, (%s), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), d, x86_64_r8x(mrs));
						}
					}
					else {
						if (lga) {
							printf("                        %s (%s, (%s), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), d, x86_64_r8(mrs));
						}
						else {
							printf("                        %s (%s, (%s), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), d, x86_64_r8(mrs));
						}
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (rex) {
					if (lga) {
						printf("                        %s (%s, %u), %s ", mn, x86_64_r32(mrd), d, x86_64_r8x(mrs));
					}
					else {
						printf("                        %s (%s, %u), %s ", mn, x86_64_r64(mrd), d, x86_64_r8x(mrs));
					}
				}
				else {
					if (lga) {
						printf("                        %s (%s, %u), %s ", mn, x86_64_r32(mrd), d, x86_64_r8(mrs));
					}
					else {
						printf("                        %s (%s, %u), %s ", mn, x86_64_r64(mrd), d, x86_64_r8(mrs));
					}
				}
			}
		}
		else if (mod == 2) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (rex) {
						if (lga) {
							printf("               %s (%s, %u), %s ", mn, x86_64_r32(b), d, x86_64_r8x(mrs));
						}
						else {
							printf("               %s (%s, %u), %s ", mn, x86_64_r64(b), d, x86_64_r8x(mrs));
						}
					}
					else {
						if (lga) {
							printf("               %s (%s, %u), %s ", mn, x86_64_r32(b), d, x86_64_r8(mrs));
						}
						else {
							printf("               %s (%s, %u), %s ", mn, x86_64_r64(b), d, x86_64_r8(mrs));
						}
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (rex) {
						if (lga) {
							printf("               %s (%s, (%s, %u), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, x86_64_r8x(mrs));
						}
						else {
							printf("               %s (%s, (%s, %u), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, x86_64_r8x(mrs));
						}
					}
					else {
						if (lga) {
							printf("               %s (%s, (%s, %u), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, x86_64_r8(mrs));
						}
						else {
							printf("               %s (%s, (%s, %u), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, x86_64_r8(mrs));
						}
					}
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (rex) {
						if (lga) {
							printf("               %s (%s, (%s), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), d, x86_64_r8x(mrs));
						}
						else {
							printf("               %s (%s, (%s), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), d, x86_64_r8x(mrs));
						}
					}
					else {
						if (lga) {
							printf("               %s (%s, (%s), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), d, x86_64_r8(mrs));
						}
						else {
							printf("               %s (%s, (%s), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), d, x86_64_r8(mrs));
						}
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (rex) {
					if (lga) {
						printf("               %s (%s, %u), %s ", mn, x86_64_r32(mrd), d, x86_64_r8x(mrs));
					}
					else {
						printf("               %s (%s, %u), %s ", mn, x86_64_r64(mrd), d, x86_64_r8x(mrs));
					}
				}
				else {
					if (lga) {
						printf("               %s (%s, %u), %s ", mn, x86_64_r32(mrd), d, x86_64_r8(mrs));
					}
					else {
						printf("               %s (%s, %u), %s ", mn, x86_64_r64(mrd), d, x86_64_r8(mrs));
					}
				}
			}
		}
		else if (mod == 3) {
			*bn += 1;
			if (rex) {
				printf("                              %s %s, %s ", mn, x86_64_r8x(mrd), x86_64_r8x(mrs));
			}
			else {
				printf("                              %s %s, %s ", mn, x86_64_r8(mrd), x86_64_r8(mrs));
			}
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_rg0(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op) {
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
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4 && (b & 7) == 5) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lgo) {
						printf("               %s (%u), %s ", mn, d, x86_64_r16(mrs));
					}
					else if (!rx3) {
						printf("               %s (%u), %s ", mn, d, x86_64_r32(mrs));
					}
					else {
						printf("               %s (%u), %s ", mn, d, x86_64_r64(mrs));
					}
				}
				else if (i == 4) {
					*bn += 1;
					if (lgo) {
						if (lga) {
							printf("                           %s (%s), %s ", mn, x86_64_r32(b), x86_64_r16(mrs));
						}
						else {
							printf("                           %s (%s), %s ", mn, x86_64_r64(b), x86_64_r16(mrs));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                           %s (%s), %s ", mn, x86_64_r32(b), x86_64_r32(mrs));
						}
						else {
							printf("                           %s (%s), %s ", mn, x86_64_r64(b), x86_64_r32(mrs));
						}
					}
					else {
						if (lga) {
							printf("                           %s (%s), %s ", mn, x86_64_r32(b), x86_64_r64(mrs));
						}
						else {
							printf("                           %s (%s), %s ", mn, x86_64_r64(b), x86_64_r64(mrs));
						}
					}
				}
				else if (s) {
					*bn += 1;
					if (lgo) {
						if (lga) {
							printf("                           %s (%s, (%s, %u)), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), x86_64_r16(mrs));
						}
						else {
							printf("                           %s (%s, (%s, %u)), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), x86_64_r16(mrs));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                           %s (%s, (%s, %u)), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), x86_64_r32(mrs));
						}
						else {
							printf("                           %s (%s, (%s, %u)), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), x86_64_r32(mrs));
						}
					}
					else {
						if (lga) {
							printf("                           %s (%s, (%s, %u)), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), x86_64_r64(mrs));
						}
						else {
							printf("                           %s (%s, (%s, %u)), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), x86_64_r64(mrs));
						}
					}
				}
				else {
					*bn += 1;
					if (lgo) {
						if (lga) {
							printf("                           %s (%s, (%s)), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_r16(mrs));
						}
						else {
							printf("                           %s (%s, (%s)), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_r16(mrs));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                           %s (%s, (%s)), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_r32(mrs));
						}
						else {
							printf("                           %s (%s, (%s)), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_r32(mrs));
						}
					}
					else {
						if (lga) {
							printf("                           %s (%s, (%s)), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_r64(mrs));
						}
						else {
							printf("                           %s (%s, (%s)), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_r64(mrs));
						}
					}
				}
			}
			else if ((mrd & 7) == 5) {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (d) {
					if (lgo) {
						if (lga) {
							printf("               %s (eip, %u), %s ", mn, d, x86_64_r16(mrs));
						}
						else {
							printf("               %s (rip, %u), %s ", mn, d, x86_64_r16(mrs));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %s (eip, %u), %s ", mn, d, x86_64_r32(mrs));
						}
						else {
							printf("               %s (rip, %u), %s ", mn, d, x86_64_r32(mrs));
						}
					}
					else {
						if (lga) {
							printf("               %s (eip, %u), %s ", mn, d, x86_64_r64(mrs));
						}
						else {
							printf("               %s (rip, %u), %s ", mn, d, x86_64_r64(mrs));
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("               %s (eip), %s ", mn, x86_64_r16(mrs));
						}
						else {
							printf("               %s (rip), %s ", mn, x86_64_r16(mrs));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %s (eip), %s ", mn, x86_64_r32(mrs));
						}
						else {
							printf("               %s (rip), %s ", mn, x86_64_r32(mrs));
						}
					}
					else {
						if (lga) {
							printf("               %s (eip), %s ", mn, x86_64_r64(mrs));
						}
						else {
							printf("               %s (rip), %s ", mn, x86_64_r64(mrs));
						}
					}
				}
			}
			else {
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                              %s (%s), %s ", mn, x86_64_r32(mrd), x86_64_r16(mrs));
					}
					else {
						printf("                              %s (%s), %s ", mn, x86_64_r64(mrd), x86_64_r16(mrs));
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                              %s (%s), %s ", mn, x86_64_r32(mrd), x86_64_r32(mrs));
					}
					else {
						printf("                              %s (%s), %s ", mn, x86_64_r64(mrd), x86_64_r32(mrs));
					}
				}
				else {
					if (lga) {
						printf("                              %s (%s), %s ", mn, x86_64_r32(mrd), x86_64_r64(mrs));
					}
					else {
						printf("                              %s (%s), %s ", mn, x86_64_r64(mrd), x86_64_r64(mrs));
					}
				}
			}
		}
		else if (mod == 1) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (lgo) {
						if (lga) {
							printf("                        %s (%s, %u), %s ", mn, x86_64_r32(b), d, x86_64_r16(mrs));
						}
						else {
							printf("                        %s (%s, %u), %s ", mn, x86_64_r64(b), d, x86_64_r16(mrs));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %s (%s, %u), %s ", mn, x86_64_r32(b), d, x86_64_r32(mrs));
						}
						else {
							printf("                        %s (%s, %u), %s ", mn, x86_64_r64(b), d, x86_64_r32(mrs));
						}
					}
					else {
						if (lga) {
							printf("                        %s (%s, %u), %s ", mn, x86_64_r32(b), d, x86_64_r64(mrs));
						}
						else {
							printf("                        %s (%s, %u), %s ", mn, x86_64_r64(b), d, x86_64_r64(mrs));
						}
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (lgo) {
						if (lga) {
							printf("                        %s (%s, (%s, %u), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, x86_64_r16(mrs));
						}
						else {
							printf("                        %s (%s, (%s, %u), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, x86_64_r16(mrs));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %s (%s, (%s, %u), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, x86_64_r32(mrs));
						}
						else {
							printf("                        %s (%s, (%s, %u), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, x86_64_r32(mrs));
						}
					}
					else {
						if (lga) {
							printf("                        %s (%s, (%s, %u), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, x86_64_r64(mrs));
						}
						else {
							printf("                        %s (%s, (%s, %u), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, x86_64_r64(mrs));
						}
					}
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (lgo) {
						if (lga) {
							printf("                        %s (%s, (%s), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), d, x86_64_r16(mrs));
						}
						else {
							printf("                        %s (%s, (%s), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), d, x86_64_r16(mrs));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %s (%s, (%s), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), d, x86_64_r32(mrs));
						}
						else {
							printf("                        %s (%s, (%s), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), d, x86_64_r32(mrs));
						}
					}
					else {
						if (lga) {
							printf("                        %s (%s, (%s), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), d, x86_64_r64(mrs));
						}
						else {
							printf("                        %s (%s, (%s), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), d, x86_64_r64(mrs));
						}
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                        %s (%s, %u), %s ", mn, x86_64_r32(mrd), d, x86_64_r16(mrs));
					}
					else {
						printf("                        %s (%s, %u), %s ", mn, x86_64_r64(mrd), d, x86_64_r16(mrs));
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                        %s (%s, %u), %s ", mn, x86_64_r32(mrd), d, x86_64_r32(mrs));
					}
					else {
						printf("                        %s (%s, %u), %s ", mn, x86_64_r64(mrd), d, x86_64_r32(mrs));
					}
				}
				else {
					if (lga) {
						printf("                        %s (%s, %u), %s ", mn, x86_64_r32(mrd), d, x86_64_r64(mrs));
					}
					else {
						printf("                        %s (%s, %u), %s ", mn, x86_64_r64(mrd), d, x86_64_r64(mrs));
					}
				}
			}
		}
		else if (mod == 2) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lgo) {
						if (lga) {
							printf("               %s (%s, %u), %s ", mn, x86_64_r32(b), d, x86_64_r16(mrs));
						}
						else {
							printf("               %s (%s, %u), %s ", mn, x86_64_r64(b), d, x86_64_r16(mrs));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %s (%s, %u), %s ", mn, x86_64_r32(b), d, x86_64_r32(mrs));
						}
						else {
							printf("               %s (%s, %u), %s ", mn, x86_64_r64(b), d, x86_64_r32(mrs));
						}
					}
					else {
						if (lga) {
							printf("               %s (%s, %u), %s ", mn, x86_64_r32(b), d, x86_64_r64(mrs));
						}
						else {
							printf("               %s (%s, %u), %s ", mn, x86_64_r64(b), d, x86_64_r64(mrs));
						}
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lgo) {
						if (lga) {
							printf("               %s (%s, (%s, %u), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, x86_64_r16(mrs));
						}
						else {
							printf("               %s (%s, (%s, %u), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, x86_64_r16(mrs));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %s (%s, (%s, %u), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, x86_64_r32(mrs));
						}
						else {
							printf("               %s (%s, (%s, %u), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, x86_64_r32(mrs));
						}
					}
					else {
						if (lga) {
							printf("               %s (%s, (%s, %u), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, x86_64_r64(mrs));
						}
						else {
							printf("               %s (%s, (%s, %u), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, x86_64_r64(mrs));
						}
					}
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lgo) {
						if (lga) {
							printf("               %s (%s, (%s), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), d, x86_64_r16(mrs));
						}
						else {
							printf("               %s (%s, (%s), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), d, x86_64_r16(mrs));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %s (%s, (%s), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), d, x86_64_r32(mrs));
						}
						else {
							printf("               %s (%s, (%s), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), d, x86_64_r32(mrs));
						}
					}
					else {
						if (lga) {
							printf("               %s (%s, (%s), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), d, x86_64_r64(mrs));
						}
						else {
							printf("               %s (%s, (%s), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), d, x86_64_r64(mrs));
						}
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					if (lga) {
						printf("               %s (%s, %u), %s ", mn, x86_64_r32(mrd), d, x86_64_r16(mrs));
					}
					else {
						printf("               %s (%s, %u), %s ", mn, x86_64_r64(mrd), d, x86_64_r16(mrs));
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("               %s (%s, %u), %s ", mn, x86_64_r32(mrd), d, x86_64_r32(mrs));
					}
					else {
						printf("               %s (%s, %u), %s ", mn, x86_64_r64(mrd), d, x86_64_r32(mrs));
					}
				}
				else {
					if (lga) {
						printf("               %s (%s, %u), %s ", mn, x86_64_r32(mrd), d, x86_64_r64(mrs));
					}
					else {
						printf("               %s (%s, %u), %s ", mn, x86_64_r64(mrd), d, x86_64_r64(mrs));
					}
				}
			}
		}
		else if (mod == 3) {
			*bn += 1;
			if (lgo) {
				printf("                              %s %s, %s ", mn, x86_64_r16(mrd), x86_64_r16(mrs));
			}
			else if (!rx3) {
				printf("                              %s %s, %s ", mn, x86_64_r32(mrd), x86_64_r32(mrs));
			}
			else {
				printf("                              %s %s, %s ", mn, x86_64_r64(mrd), x86_64_r64(mrs));
			}
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_r81(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op) {
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
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4 && (b & 7) == 5) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (rex) {
						printf("               %s %s, (%u) ", mn, x86_64_r8x(mrs), d);
					}
					else {
						printf("               %s %s, (%u) ", mn, x86_64_r8(mrs), d);
					}
				}
				else if (i == 4) {
					*bn += 1;
					if (rex) {
						if (lga) {
							printf("                           %s %s, (%s) ", mn, x86_64_r8x(mrs), x86_64_r32(mrs));
						}
						else {
							printf("                           %s %s, (%s) ", mn, x86_64_r8x(mrs), x86_64_r64(mrs));
						}
					}
					else {
						if (lga) {
							printf("                           %s %s, (%s) ", mn, x86_64_r8(mrs), x86_64_r32(mrs));
						}
						else {
							printf("                           %s %s, (%s) ", mn, x86_64_r8(mrs), x86_64_r64(mrs));
						}
					}
				}
				else if (s) {
					*bn += 1;
					if (rex) {
						if (lga) {
							printf("                           %s %s, (%s, (%s, %u)) ", mn, x86_64_r8x(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
						}
						else {
							printf("                           %s %s, (%s, (%s, %u)) ", mn, x86_64_r8x(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
						}
					}
					else {
						if (lga) {
							printf("                           %s %s, (%s, (%s, %u)) ", mn, x86_64_r8(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
						}
						else {
							printf("                           %s %s, (%s, (%s, %u)) ", mn, x86_64_r8(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
						}
					}
				}
				else {
					*bn += 1;
					if (rex) {
						if (lga) {
							printf("                           %s %s, (%s, (%s)) ", mn, x86_64_r8x(mrs), x86_64_r32(b), x86_64_r32(i));
						}
						else {
							printf("                           %s %s, (%s, (%s)) ", mn, x86_64_r8x(mrs), x86_64_r64(b), x86_64_r64(i));
						}
					}
					else {
						if (lga) {
							printf("                           %s %s, (%s, (%s)) ", mn, x86_64_r8(mrs), x86_64_r32(b), x86_64_r32(i));
						}
						else {
							printf("                           %s %s, (%s, (%s)) ", mn, x86_64_r8(mrs), x86_64_r64(b), x86_64_r64(i));
						}
					}
				}
			}
			else if ((mrd & 7) == 5) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (d) {
					if (rex) {
						if (lga) {
							printf("                  %s %s, (eip, %u) ", mn, x86_64_r8x(mrs), d);
						}
						else {
							printf("                  %s %s, (rip, %u) ", mn, x86_64_r8x(mrs), d);
						}
					}
					else {
						if (lga) {
							printf("                  %s %s, (eip, %u) ", mn, x86_64_r8(mrs), d);
						}
						else {
							printf("                  %s %s, (rip, %u) ", mn, x86_64_r8(mrs), d);
						}
					}
				}
				else {
					if (rex) {
						if (lga) {
							printf("                  %s %s, (eip) ", mn, x86_64_r8x(mrs));
						}
						else {
							printf("                  %s %s, (rip) ", mn, x86_64_r8x(mrs));
						}
					}
					else {
						if (lga) {
							printf("                  %s %s, (eip) ", mn, x86_64_r8(mrs));
						}
						else {
							printf("                  %s %s, (rip) ", mn, x86_64_r8(mrs));
						}
					}
				}
			}
			else {
				*bn += 1;
				if (rex) {
					if (lga) {
						printf("                              %s %s, (%s) ", mn, x86_64_r8x(mrd), x86_64_r32(mrs));
					}
					else {
						printf("                              %s %s, (%s) ", mn, x86_64_r8x(mrd), x86_64_r64(mrs));
					}
				}
				else {
					if (lga) {
						printf("                              %s %s, (%s) ", mn, x86_64_r8(mrd), x86_64_r32(mrs));
					}
					else {
						printf("                              %s %s, (%s) ", mn, x86_64_r8(mrd), x86_64_r64(mrs));
					}
				}
			}
		}
		else if (mod == 1) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (rex) {
						if (lga) {
							printf("                        %s %s, (%s, %u) ", mn, x86_64_r8x(mrs), x86_64_r32(b), d);
						}
						else {
							printf("                        %s %s, (%s, %u) ", mn, x86_64_r8x(mrs), x86_64_r64(b), d);
						}
					}
					else {
						if (lga) {
							printf("                        %s %s, (%s, %u) ", mn, x86_64_r8(mrs), x86_64_r32(b), d);
						}
						else {
							printf("                        %s %s, (%s, %u) ", mn, x86_64_r8(mrs), x86_64_r64(b), d);
						}
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (rex) {
						if (lga) {
							printf("                        %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r8x(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
						}
						else {
							printf("                        %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r8x(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
						}
					}
					else {
						if (lga) {
							printf("                        %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r8(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
						}
						else {
							printf("                        %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r8(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
						}
					}
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (rex) {
						if (lga) {
							printf("                        %s %s, (%s, (%s), %u) ", mn, x86_64_r8x(mrs), x86_64_r32(b), x86_64_r32(i), d);
						}
						else {
							printf("                        %s %s, (%s, (%s), %u) ", mn, x86_64_r8x(mrs), x86_64_r64(b), x86_64_r64(i), d);
						}
					}
					else {
						if (lga) {
							printf("                        %s %s, (%s, (%s), %u) ", mn, x86_64_r8(mrs), x86_64_r32(b), x86_64_r32(i), d);
						}
						else {
							printf("                        %s %s, (%s, (%s), %u) ", mn, x86_64_r8(mrs), x86_64_r64(b), x86_64_r64(i), d);
						}
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (rex) {
					if (lga) {
						printf("                        %s %s, (%s, %u) ", mn, x86_64_r8x(mrs), x86_64_r32(mrd), d);
					}
					else {
						printf("                        %s %s, (%s, %u) ", mn, x86_64_r8x(mrs), x86_64_r64(mrd), d);
					}
				}
				else {
					if (lga) {
						printf("                        %s %s, (%s, %u) ", mn, x86_64_r8(mrs), x86_64_r32(mrd), d);
					}
					else {
						printf("                        %s %s, (%s, %u) ", mn, x86_64_r8(mrs), x86_64_r64(mrd), d);
					}
				}
			}
		}
		else if (mod == 2) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (rex) {
						if (lga) {
							printf("               %s %s, (%s, %u) ", mn, x86_64_r8x(mrs), x86_64_r32(b), d);
						}
						else {
							printf("               %s %s, (%s, %u) ", mn, x86_64_r8x(mrs), x86_64_r64(b), d);
						}
					}
					else {
						if (lga) {
							printf("               %s %s, (%s, %u) ", mn, x86_64_r8(mrs), x86_64_r32(b), d);
						}
						else {
							printf("               %s %s, (%s, %u) ", mn, x86_64_r8(mrs), x86_64_r64(b), d);
						}
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (rex) {
						if (lga) {
							printf("               %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r8x(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
						}
						else {
							printf("               %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r8x(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
						}
					}
					else {
						if (lga) {
							printf("               %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r8(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
						}
						else {
							printf("               %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r8(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
						}
					}
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (rex) {
						if (lga) {
							printf("               %s %s, (%s, (%s), %u) ", mn, x86_64_r8x(mrs), x86_64_r32(b), x86_64_r32(i), d);
						}
						else {
							printf("               %s %s, (%s, (%s), %u) ", mn, x86_64_r8x(mrs), x86_64_r64(b), x86_64_r64(i), d);
						}
					}
					else {
						if (lga) {
							printf("               %s %s, (%s, (%s), %u) ", mn, x86_64_r8(mrs), x86_64_r32(b), x86_64_r32(i), d);
						}
						else {
							printf("               %s %s, (%s, (%s), %u) ", mn, x86_64_r8(mrs), x86_64_r64(b), x86_64_r64(i), d);
						}
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (rex) {
					if (lga) {
						printf("               %s %s, (%s, %u) ", mn, x86_64_r8x(mrs), x86_64_r32(mrd), d);
					}
					else {
						printf("               %s %s, (%s, %u) ", mn, x86_64_r8x(mrs), x86_64_r64(mrd), d);
					}
				}
				else {
					if (lga) {
						printf("               %s %s, (%s, %u) ", mn, x86_64_r8(mrs), x86_64_r32(mrd), d);
					}
					else {
						printf("               %s %s, (%s, %u) ", mn, x86_64_r8(mrs), x86_64_r64(mrd), d);
					}
				}
			}
		}
		else if (mod == 3) {
			*bn += 1;
			if (rex) {
				printf("                              %s %s, %s ", mn, x86_64_r8x(mrs), x86_64_r8x(mrd));
			}
			else {
				printf("                              %s %s, %s ", mn, x86_64_r8(mrs), x86_64_r8(mrd));
			}
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_rg1(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op) {
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
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4 && (b & 7) == 5) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lgo) {
						printf("               %s %s, (%u) ", mn, x86_64_r16(mrs), d);
					}
					else if (!rx3) {
						printf("               %s %s, (%u) ", mn, x86_64_r32(mrs), d);
					}
					else {
						printf("               %s %s, (%u) ", mn, x86_64_r64(mrs), d);
					}
				}
				else if (i == 4) {
					*bn += 1;
					if (lgo) {
						if (lga) {
							printf("                           %s %s, (%s) ", mn, x86_64_r16(mrs), x86_64_r32(b));
						}
						else {
							printf("                           %s %s, (%s) ", mn, x86_64_r16(mrs), x86_64_r64(b));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                           %s %s, (%s) ", mn, x86_64_r32(mrs), x86_64_r32(b));
						}
						else {
							printf("                           %s %s, (%s) ", mn, x86_64_r32(mrs), x86_64_r64(b));
						}
					}
					else {
						if (lga) {
							printf("                           %s %s, (%s) ", mn, x86_64_r64(mrs), x86_64_r32(b));
						}
						else {
							printf("                           %s %s, (%s) ", mn, x86_64_r64(mrs), x86_64_r64(b));
						}
					}
				}
				else if (s) {
					*bn += 1;
					if (lgo) {
						if (lga) {
							printf("                           %s %s, (%s, (%s, %u)) ", mn, x86_64_r16(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
						}
						else {
							printf("                           %s %s, (%s, (%s, %u)) ", mn, x86_64_r16(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                           %s %s, (%s, (%s, %u)) ", mn, x86_64_r32(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
						}
						else {
							printf("                           %s %s, (%s, (%s, %u)) ", mn, x86_64_r32(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
						}
					}
					else {
						if (lga) {
							printf("                           %s %s, (%s, (%s, %u)) ", mn, x86_64_r64(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
						}
						else {
							printf("                           %s %s, (%s, (%s, %u)) ", mn, x86_64_r64(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
						}
					}
				}
				else {
					*bn += 1;
					if (lgo) {
						if (lga) {
							printf("                           %s %s, (%s, (%s)) ", mn, x86_64_r16(mrs), x86_64_r32(b), x86_64_r32(i));
						}
						else {
							printf("                           %s %s, (%s, (%s)) ", mn, x86_64_r16(mrs), x86_64_r64(b), x86_64_r64(i));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                           %s %s, (%s, (%s)) ", mn, x86_64_r32(mrs), x86_64_r32(b), x86_64_r32(i));
						}
						else {
							printf("                           %s %s, (%s, (%s)) ", mn, x86_64_r32(mrs), x86_64_r64(b), x86_64_r64(i));
						}
					}
					else {
						if (lga) {
							printf("                           %s %s, (%s, (%s)) ", mn, x86_64_r64(mrs), x86_64_r32(b), x86_64_r32(i));
						}
						else {
							printf("                           %s %s, (%s, (%s)) ", mn, x86_64_r64(mrs), x86_64_r64(b), x86_64_r64(i));
						}
					}
				}
			}
			else if ((mrd & 7) == 5) {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (d) {
					if (lgo) {
						if (lga) {
							printf("               %s %s, (eip, %u) ", mn, x86_64_r16(mrs), d);
						}
						else {
							printf("               %s %s, (rip, %u) ", mn, x86_64_r16(mrs), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %s %s, (eip, %u) ", mn, x86_64_r32(mrs), d);
						}
						else {
							printf("               %s %s, (rip, %u) ", mn, x86_64_r32(mrs), d);
						}
					}
					else {
						if (lga) {
							printf("               %s %s, (eip, %u) ", mn, x86_64_r64(mrs), d);
						}
						else {
							printf("               %s %s, (rip, %u) ", mn, x86_64_r64(mrs), d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("               %s %s, (eip) ", mn, x86_64_r16(mrs));
						}
						else {
							printf("               %s %s, (rip) ", mn, x86_64_r16(mrs));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %s %s, (eip) ", mn, x86_64_r32(mrs));
						}
						else {
							printf("               %s %s, (rip) ", mn, x86_64_r32(mrs));
						}
					}
					else {
						if (lga) {
							printf("               %s %s, (eip) ", mn, x86_64_r64(mrs));
						}
						else {
							printf("               %s %s, (rip) ", mn, x86_64_r64(mrs));
						}
					}
				}
			}
			else {
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                              %s %s, (%s) ", mn, x86_64_r16(mrs), x86_64_r32(mrd));
					}
					else {
						printf("                              %s %s, (%s) ", mn, x86_64_r16(mrs), x86_64_r64(mrd));
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                              %s %s, (%s) ", mn, x86_64_r32(mrs), x86_64_r32(mrd));
					}
					else {
						printf("                              %s %s, (%s) ", mn, x86_64_r32(mrs), x86_64_r64(mrd));
					}
				}
				else {
					if (lga) {
						printf("                              %s %s, (%s) ", mn, x86_64_r32(mrs), x86_64_r32(mrd));
					}
					else {
						printf("                              %s %s, (%s) ", mn, x86_64_r64(mrs), x86_64_r64(mrd));
					}
				}
			}
		}
		else if (mod == 1) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (lgo) {
						if (lga) {
							printf("                        %s %s, (%s, %u) ", mn, x86_64_r16(mrs), x86_64_r32(b), d);
						}
						else {
							printf("                        %s %s, (%s, %u) ", mn, x86_64_r16(mrs), x86_64_r64(b), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %s %s, (%s, %u) ", mn, x86_64_r32(mrs), x86_64_r32(b), d);
						}
						else {
							printf("                        %s %s, (%s, %u) ", mn, x86_64_r32(mrs), x86_64_r64(b), d);
						}
					}
					else {
						if (lga) {
							printf("                        %s %s, (%s, %u) ", mn, x86_64_r64(mrs), x86_64_r32(b), d);
						}
						else {
							printf("                        %s %s, (%s, %u) ", mn, x86_64_r64(mrs), x86_64_r64(b), d);
						}
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (lgo) {
						if (lga) {
							printf("                        %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r16(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
						}
						else {
							printf("                        %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r16(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r32(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
						}
						else {
							printf("                        %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r32(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
						}
					}
					else {
						if (lga) {
							printf("                        %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r64(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
						}
						else {
							printf("                        %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r64(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
						}
					}
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (lgo) {
						if (lga) {
							printf("                        %s %s, (%s, (%s), %u) ", mn, x86_64_r16(mrs), x86_64_r32(b), x86_64_r32(i), d);
						}
						else {
							printf("                        %s %s, (%s, (%s), %u) ", mn, x86_64_r16(mrs), x86_64_r64(b), x86_64_r64(i), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %s %s, (%s, (%s), %u) ", mn, x86_64_r32(mrs), x86_64_r32(b), x86_64_r32(i), d);
						}
						else {
							printf("                        %s %s, (%s, (%s), %u) ", mn, x86_64_r32(mrs), x86_64_r64(b), x86_64_r64(i), d);
						}
					}
					else {
						if (lga) {
							printf("                        %s %s, (%s, (%s), %u) ", mn, x86_64_r64(mrs), x86_64_r32(b), x86_64_r32(i), d);
						}
						else {
							printf("                        %s %s, (%s, (%s), %u) ", mn, x86_64_r64(mrs), x86_64_r64(b), x86_64_r64(i), d);
						}
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                        %s %s, (%s, %u) ", mn, x86_64_r16(mrs), x86_64_r32(mrd), d);
					}
					else {
						printf("                        %s %s, (%s, %u) ", mn, x86_64_r16(mrs), x86_64_r64(mrd), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                        %s %s, (%s, %u) ", mn, x86_64_r32(mrs), x86_64_r32(mrd), d);
					}
					else {
						printf("                        %s %s, (%s, %u) ", mn, x86_64_r32(mrs), x86_64_r64(mrd), d);
					}
				}
				else {
					if (lga) {
						printf("                        %s %s, (%s, %u) ", mn, x86_64_r64(mrs), x86_64_r32(mrd), d);
					}
					else {
						printf("                        %s %s, (%s, %u) ", mn, x86_64_r64(mrs), x86_64_r64(mrd), d);
					}
				}
			}
		}
		else if (mod == 2) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lgo) {
						if (lga) {
							printf("               %s %s, (%s, %u) ", mn, x86_64_r16(mrs), x86_64_r32(b), d);
						}
						else {
							printf("               %s %s, (%s, %u) ", mn, x86_64_r16(mrs), x86_64_r64(b), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %s %s, (%s, %u) ", mn, x86_64_r32(mrs), x86_64_r32(b), d);
						}
						else {
							printf("               %s %s, (%s, %u) ", mn, x86_64_r32(mrs), x86_64_r64(b), d);
						}
					}
					else {
						if (lga) {
							printf("               %s %s, (%s, %u) ", mn, x86_64_r64(mrs), x86_64_r32(b), d);
						}
						else {
							printf("               %s %s, (%s, %u) ", mn, x86_64_r64(mrs), x86_64_r64(b), d);
						}
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lgo) {
						if (lga) {
							printf("               %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r16(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
						}
						else {
							printf("               %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r16(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r32(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
						}
						else {
							printf("               %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r32(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
						}
					}
					else {
						if (lga) {
							printf("               %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r64(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
						}
						else {
							printf("               %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r64(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
						}
					}
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lgo) {
						if (lga) {
							printf("               %s %s, (%s, (%s), %u) ", mn, x86_64_r16(mrs), x86_64_r32(b), x86_64_r32(i), d);
						}
						else {
							printf("               %s %s, (%s, (%s), %u) ", mn, x86_64_r16(mrs), x86_64_r64(b), x86_64_r64(i), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %s %s, (%s, (%s), %u) ", mn, x86_64_r32(mrs), x86_64_r32(b), x86_64_r32(i), d);
						}
						else {
							printf("               %s %s, (%s, (%s), %u) ", mn, x86_64_r32(mrs), x86_64_r64(b), x86_64_r64(i), d);
						}
					}
					else {
						if (lga) {
							printf("               %s %s, (%s, (%s), %u) ", mn, x86_64_r64(mrs), x86_64_r32(b), x86_64_r32(i), d);
						}
						else {
							printf("               %s %s, (%s, (%s), %u) ", mn, x86_64_r64(mrs), x86_64_r64(b), x86_64_r64(i), d);
						}
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					if (lga) {
						printf("               %s %s, (%s, %u) ", mn, x86_64_r16(mrs), x86_64_r32(mrd), d);
					}
					else {
						printf("               %s %s, (%s, %u) ", mn, x86_64_r16(mrs), x86_64_r64(mrd), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("               %s %s, (%s, %u) ", mn, x86_64_r32(mrs), x86_64_r32(mrd), d);
					}
					else {
						printf("               %s %s, (%s, %u) ", mn, x86_64_r32(mrs), x86_64_r64(mrd), d);
					}
				}
				else {
					if (lga) {
						printf("               %s %s, (%s, %u) ", mn, x86_64_r64(mrs), x86_64_r32(mrd), d);
					}
					else {
						printf("               %s %s, (%s, %u) ", mn, x86_64_r64(mrs), x86_64_r64(mrd), d);
					}
				}
			}
		}
		else if (mod == 3) {
			*bn += 1;
			if (lgo) {
				printf("                              %s %s, %s ", mn, x86_64_r16(mrs), x86_64_r16(mrd));
			}
			else if (!rx3) {
				printf("                              %s %s, %s ", mn, x86_64_r32(mrs), x86_64_r32(mrd));
			}
			else if (rx3) {
				printf("                              %s %s, %s ", mn, x86_64_r64(mrs), x86_64_r64(mrd));
			}
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_ral(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("                  %02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn += 1;
		printf("            %s al, %u ", mn, k);
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_rax(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		if (lgo) {
			printf("                  %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			printf("         %s ax, %u ", mn, k);
		}
		else if (!rx3) {
			printf("                  %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			printf("   %s eax, %u ", mn, k);
		}
		else {
			printf("                  %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			printf("   %s rax, %u ", mn, k);
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_k80(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4 && (b & 7) == 5) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("%02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				if (lga) {
					printf("            %sb (%u), %u ", mn, d, k);
				}
				else {
					printf("            %sb (%u), %u ", mn, d, k);
				}
			}
			else if (i == 4) {
				*bn += 1;
				printf("            %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				if (lga) {
					printf("            %sb (%s), %u ", mn, x86_64_r32(b), k);
				}
				else {
					printf("            %sb (%s), %u ", mn, x86_64_r64(b), k);
				}
			}
			else if (s) {
				*bn += 1;
				printf("            %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				if (lga) {
					printf("            %sb (%s, (%s, %u)), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), k);
				}
				else {
					printf("            %sb (%s, (%s, %u)), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), k);
				}
			}
			else {
				*bn += 1;
				printf("            %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				if (lga) {
					printf("            %sb (%s, (%s)), %u ", mn, x86_64_r32(b), x86_64_r32(i), k);
				}
				else {
					printf("            %sb (%s, (%s)), %u ", mn, x86_64_r64(b), x86_64_r64(i), k);
				}
			}
		}
		else if ((mrd & 7) == 5) {
			*bn += 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			printf("%02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn += 1;
			if (d) {
				if (lga) {
					printf("            %sb (eip, %u), %u ", mn, d, k);
				}
				else {
					printf("            %sb (rip, %u), %u ", mn, d, k);
				}
			}
			else {
				if (lga) {
					printf("            %sb (eip), %u ", mn, k);
				}
				else {
					printf("            %sb (rip), %u ", mn, k);
				}
			}
		}
		else {
			*bn += 1;
			printf("               %02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn += 1;
			if (lga) {
				printf("            %sb (%s), %u ", mn, x86_64_r32(mrd), k);
			}
			else {
				printf("            %sb (%s), %u ", mn, x86_64_r64(mrd), k);
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				printf("         %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				if (lga) {
					printf("            %sb (%s, %u), %u ", mn, x86_64_r32(b), d, k);
				}
				else {
					printf("            %sb (%s, %u), %u ", mn, x86_64_r64(b), d, k);
				}
			}
			else if (s) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				printf("         %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				if (lga) {
					printf("            %sb (%s, (%s, %u), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, k);
				}
				else {
					printf("            %sb (%s, (%s, %u), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, k);
				}
			}
			else {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				printf("         %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				if (lga) {
					printf("            %sb (%s, (%s), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), d, k);
				}
				else {
					printf("            %sb (%s, (%s), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), d, k);
				}
			}
		}
		else {
			*bn += 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			printf("         %02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn += 1;
			if (lga) {
				printf("            %sb (%s, %u), %u ", mn, x86_64_r32(mrd), d, k);
			}
			else {
				printf("            %sb (%s, %u), %u ", mn, x86_64_r64(mrd), d, k);
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("%02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				if (lga) {
					printf("            %sb (%s, %u), %u ", mn, x86_64_r32(b), d, k);
				}
				else {
					printf("            %sb (%s, %u), %u ", mn, x86_64_r64(b), d, k);
				}
			}
			else if (s) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("%02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				if (lga) {
					printf("            %sb (%s, (%s, %u), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, k);
				}
				else {
					printf("            %sb (%s, (%s, %u), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, k);
				}
			}
			else {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("%02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				if (lga) {
					printf("            %sb (%s, (%s), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), d, k);
				}
				else {
					printf("            %sb (%s, (%s), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), d, k);
				}
			}
		}
		else {
			*bn += 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			printf("%02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn += 1;
			if (lga) {
				printf("            %sb (%s, %u), %u ", mn, x86_64_r32(mrd), d, k);
			}
			else {
				printf("            %sb (%s, %u), %u ", mn, x86_64_r64(mrd), d, k);
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		*bn += 1;
		printf("               %02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn += 1;
		if (rex) {
			printf("            %sb %s, %u ", mn, x86_64_r8x(mrd + (8 * rx2)), k);
		}
		else {
			printf("            %sb %s, %u ", mn, x86_64_r8(mrd + (8 * rx2)), k);
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_imm(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4 && (b & 7) == 5) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (%u), %u ", mn, d, k);
				}
				else if (!rx3) {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (%u), %u ", mn, d, k);
				}
				else {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sq (%u), %u ", mn, d, k);
				}
			}
			else if (i == 4) {
				*bn += 1;
				if (lgo) {
					printf("            %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					if (lga) {
						printf("         %sw (%s), %u ", mn, x86_64_r32(b), k);
					}
					else {
						printf("         %sw (%s), %u ", mn, x86_64_r64(b), k);
					}
				}
				else if (!rx3) {
					printf("            %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lga) {
						printf("   %sd (%s), %u ", mn, x86_64_r32(b), k);
					}
					else {
						printf("   %sd (%s), %u ", mn, x86_64_r64(b), k);
					}
				}
				else {
					printf("            %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lga) {
						printf("   %sq (%s), %u ", mn, x86_64_r32(b), k);
					}
					else {
						printf("   %sq (%s), %u ", mn, x86_64_r64(b), k);
					}
				}
			}
			else if (s) {
				*bn += 1;
				if (lgo) {
					printf("            %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					if (lga) {
						printf("         %sw (%s, (%s, %u)), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), k);
					}
					else {
						printf("         %sw (%s, (%s, %u)), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), k);
					}
				}
				else if (!rx3) {
					printf("            %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lga) {
						printf("   %sd (%s, (%s, %u)), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), k);
					}
					else {
						printf("   %sd (%s, (%s, %u)), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), k);
					}
				}
				else {
					printf("            %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lga) {
						printf("   %sq (%s, (%s, %u)), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), k);
					}
					else {
						printf("   %sq (%s, (%s, %u)), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), k);
					}
				}
			}
			else {
				*bn += 1;
				if (lgo) {
					printf("            %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					if (lga) {
						printf("         %sw (%s, (%s)), %u ", mn, x86_64_r32(b), x86_64_r32(i), k);
					}
					else {
						printf("         %sw (%s, (%s)), %u ", mn, x86_64_r64(b), x86_64_r64(i), k);
					}
				}
				else if (!rx3) {
					printf("            %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lga) {
						printf("   %sd (%s, (%s)), %u ", mn, x86_64_r32(b), x86_64_r32(i), k);
					}
					else {
						printf("   %sd (%s, (%s)), %u ", mn, x86_64_r64(b), x86_64_r64(i), k);
					}
				}
				else {
					printf("            %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lga) {
						printf("   %sq (%s, (%s)), %u ", mn, x86_64_r32(b), x86_64_r32(i), k);
					}
					else {
						printf("   %sq (%s, (%s)), %u ", mn, x86_64_r64(b), x86_64_r64(i), k);
					}
				}
			}
		}
		else if ((mrd & 7) == 5) {
			*bn += 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			if (d) {
				if (lgo) {
					printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					if (lga) {
						printf("         %sw (eip, %u), %u ", mn, d, k);
					}
					else {
						printf("         %sw (rip, %u), %u ", mn, d, k);
					}
				}
				else if (!rx3) {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lga) {
						printf("   %sd (eip, %u), %u ", mn, d, k);
					}
					else {
						printf("   %sd (rip, %u), %u ", mn, d, k);
					}
				}
				else {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lga) {
						printf("   %sq (eip, %u), %u ", mn, d, k);
					}
					else {
						printf("   %sq (rip, %u), %u ", mn, d, k);
					}
				}
			}
			else {
				if (lgo) {
					printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					if (lga) {
						printf("         %sw (eip), %u ", mn, k);
					}
					else {
						printf("         %sw (rip), %u ", mn, k);
					}
				}
				else if (!rx3) {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lga) {
						printf("   %sd (eip), %u ", mn, k);
					}
					else {
						printf("   %sd (rip), %u ", mn, k);
					}
				}
				else {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lga) {
						printf("   %sq (eip), %u ", mn, k);
					}
					else {
						printf("   %sq (rip), %u ", mn, k);
					}
				}
			}
		}
		else {
			*bn += 1;
			if (lgo) {
				printf("               %02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				if (lga) {
					printf("         %sw (%s), %u ", mn, x86_64_r32(mrd), k);
				}
				else {
					printf("         %sw (%s), %u ", mn, x86_64_r64(mrd), k);
				}
			}
			else if (!rx3) {
				printf("               %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lga) {
					printf("   %sd (%s), %u ", mn, x86_64_r32(mrd), k);
				}
				else {
					printf("   %sd (%s), %u ", mn, x86_64_r64(mrd), k);
				}
			}
			else {
				printf("               %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lga) {
					printf("   %sq (%s), %u ", mn, x86_64_r32(mrd), k);
				}
				else {
					printf("   %sq (%s), %u ", mn, x86_64_r64(mrd), k);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			
			if (i == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lgo) {
					printf("         %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					if (lga) {
						printf("         %sw (%s, %u), %u ", mn, x86_64_r32(b), d, k);
					}
					else {
						printf("         %sw (%s, %u), %u ", mn, x86_64_r64(b), d, k);
					}
				}
				else if (!rx3) {
					printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lga) {
						printf("   %sd (%s, %u), %u ", mn, x86_64_r32(b), d, k);
					}
					else {
						printf("   %sd (%s, %u), %u ", mn, x86_64_r64(b), d, k);
					}
				}
				else {
					printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lga) {
						printf("   %sq (%s, %u), %u ", mn, x86_64_r32(b), d, k);
					}
					else {
						printf("   %sq (%s, %u), %u ", mn, x86_64_r64(b), d, k);
					}
				}
			}
			else if (s) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lgo) {
					printf("         %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					if (lga) {
						printf("         %sw (%s, (%s, %u), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, k);
					}
					else {
						printf("         %sw (%s, (%s, %u), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, k);
					}
				}
				else if (!rx3) {
					printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lga) {
						printf("   %sd (%s, (%s, %u), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, k);
					}
					else {
						printf("   %sd (%s, (%s, %u), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, k);
					}
				}
				else {
					printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lga) {
						printf("   %sq (%s, (%s, %u), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, k);
					}
					else {
						printf("   %sq (%s, (%s, %u), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, k);
					}
				}
			}
			else {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lgo) {
					printf("         %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					if (lga) {
						printf("         %sw (%s, (%s), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), d, k);
					}
					else {
						printf("         %sw (%s, (%s), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), d, k);
					}
				}
				else if (!rx3) {
					printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lga) {
						printf("   %sd (%s, (%s), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), d, k);
					}
					else {
						printf("   %sd (%s, (%s), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), d, k);
					}
				}
				else {
					printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lga) {
						printf("   %sq (%s, (%s), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), d, k);
					}
					else {
						printf("   %sq (%s, (%s), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), d, k);
					}
				}
			}
		}
		else {
			*bn += 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			if (lgo) {
				printf("         %02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				if (lga) {
					printf("         %sw (%s, %u), %u ", mn, x86_64_r32(mrd), d, k);
				}
				else {
					printf("         %sw (%s, %u), %u ", mn, x86_64_r64(mrd), d, k);
				}
			}
			else if (!rx3) {
				printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lga) {
					printf("   %sd (%s, %u), %u ", mn, x86_64_r32(mrd), d, k);
				}
				else {
					printf("   %sd (%s, %u), %u ", mn, x86_64_r64(mrd), d, k);
				}
			}
			else {
				printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lga) {
					printf("   %sq (%s, %u), %u ", mn, x86_64_r32(mrd), d, k);
				}
				else {
					printf("   %sq (%s, %u), %u ", mn, x86_64_r64(mrd), d, k);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					if (lga) {
						printf("         %sw (%s, %u), %u ", mn, x86_64_r32(b), d, k);
					}
					else {
						printf("         %sw (%s, %u), %u ", mn, x86_64_r64(b), d, k);
					}
				}
				else if (!rx3) {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lga) {
						printf("   %sd (%s, %u), %u ", mn, x86_64_r32(b), d, k);
					}
					else {
						printf("   %sd (%s, %u), %u ", mn, x86_64_r64(b), d, k);
					}
				}
				else {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lga) {
						printf("   %sq (%s, %u), %u ", mn, x86_64_r32(b), d, k);
					}
					else {
						printf("   %sq (%s, %u), %u ", mn, x86_64_r64(b), d, k);
					}
				}
			}
			else if (s) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					if (lga) {
						printf("         %sw (%s, (%s, %u), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, k);
					}
					else {
						printf("         %sw (%s, (%s, %u), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, k);
					}
				}
				else if (!rx3) {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lga) {
						printf("   %sd (%s, (%s, %u), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, k);
					}
					else {
						printf("   %sd (%s, (%s, %u), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, k);
					}
				}
				else {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lga) {
						printf("   %sq (%s, (%s, %u), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, k);
					}
					else {
						printf("   %sq (%s, (%s, %u), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, k);
					}
				}
			}
			else {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					if (lga) {
						printf("         %sw (%s, (%s), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), d, k);
					}
					else {
						printf("         %sw (%s, (%s), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), d, k);
					}
				}
				else if (!rx3) {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lga) {
						printf("   %sd (%s, (%s), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), d, k);
					}
					else {
						printf("   %sd (%s, (%s), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), d, k);
					}
				}
				else {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lga) {
						printf("   %sq (%s, (%s), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), d, k);
					}
					else {
						printf("   %sq (%s, (%s), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), d, k);
					}
				}
			}
		}
		else {
			*bn += 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			if (lgo) {
				printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				if (lga) {
					printf("         %sw (%s, %u), %u ", mn, x86_64_r32(mrd), d, k);
				}
				else {
					printf("         %sw (%s, %u), %u ", mn, x86_64_r64(mrd), d, k);
				}
			}
			else if (!rx3) {
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lga) {
					printf("   %sd (%s, %u), %u ", mn, x86_64_r32(mrd), d, k);
				}
				else {
					printf("   %sd (%s, %u), %u ", mn, x86_64_r64(mrd), d, k);
				}
			}
			else {
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lga) {
					printf("   %sq (%s, %u), %u ", mn, x86_64_r32(mrd), d, k);
				}
				else {
					printf("   %sq (%s, %u), %u ", mn, x86_64_r64(mrd), d, k);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		*bn += 1;
		if (lgo) {
			printf("               %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			printf("         %sw %s, %u ", mn, x86_64_r16(mrd + (8 * rx2)), k);
		}
		else if (!rx3) {
			printf("               %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			printf("   %sd %s, %u ", mn, x86_64_r32(mrd + (8 * rx2)), k);
		}
		else {
			printf("               %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			printf("   %sq %s, %u ", mn, x86_64_r64(mrd + (8 * rx2)), k);
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_k81(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4 && (b & 7) == 5) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("%02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				if (lgo) {
					printf("            %sw (%u), %u ", mn, d, k);
				}
				else if (!rx3) {
					printf("            %sd (%u), %u ", mn, d, k);
				}
				else {
					printf("            %sq (%u), %u ", mn, d, k);
				}
			}
			else if (i == 4) {
				*bn += 1;
				printf("            %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("            %sw (%s), %u ", mn, x86_64_r32(b), k);
					}
					else {
						printf("            %sw (%s), %u ", mn, x86_64_r64(b), k);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("            %sd (%s), %u ", mn, x86_64_r32(b), k);
					}
					else {
						printf("            %sd (%s), %u ", mn, x86_64_r64(b), k);
					}
				}
				else {
					if (lga) {
						printf("            %sq (%s), %u ", mn, x86_64_r32(b), k);
					}
					else {
						printf("            %sq (%s), %u ", mn, x86_64_r64(b), k);
					}
				}
			}
			else if (s) {
				*bn += 1;
				printf("            %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("            %sw (%s, (%s, %u)), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), k);
					}
					else {
						printf("            %sw (%s, (%s, %u)), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), k);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("            %sd (%s, (%s, %u)), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), k);
					}
					else {
						printf("            %sd (%s, (%s, %u)), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), k);
					}
				}
				else {
					if (lga) {
						printf("            %sq (%s, (%s, %u)), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), k);
					}
					else {
						printf("            %sq (%s, (%s, %u)), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), k);
					}
				}
			}
			else {
				*bn += 1;
				printf("            %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("            %sw (%s, (%s)), %u ", mn, x86_64_r32(b), x86_64_r32(i), k);
					}
					else {
						printf("            %sw (%s, (%s)), %u ", mn, x86_64_r64(b), x86_64_r64(i), k);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("            %sd (%s, (%s)), %u ", mn, x86_64_r32(b), x86_64_r32(i), k);
					}
					else {
						printf("            %sd (%s, (%s)), %u ", mn, x86_64_r64(b), x86_64_r64(i), k);
					}
				}
				else {
					if (lga) {
						printf("            %sq (%s, (%s)), %u ", mn, x86_64_r32(b), x86_64_r32(i), k);
					}
					else {
						printf("            %sq (%s, (%s)), %u ", mn, x86_64_r64(b), x86_64_r64(i), k);
					}
				}
			}
		}
		else if ((mrd & 7) == 5) {
			*bn += 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			printf("%02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn += 1;
			if (d) {
				if (lgo) {
					if (lga) {
						printf("            %sw (eip, %u), %u ", mn, d, k);
					}
					else {
						printf("            %sw (rip, %u), %u ", mn, d, k);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("            %sd (eip, %u), %u ", mn, d, k);
					}
					else {
						printf("            %sd (rip, %u), %u ", mn, d, k);
					}
				}
				else {
					if (lga) {
						printf("            %sq (eip, %u), %u ", mn, d, k);
					}
					else {
						printf("            %sq (rip, %u), %u ", mn, d, k);
					}
				}
			}
			else {
				if (lgo) {
					if (lga) {
						printf("            %sw (eip), %u ", mn, k);
					}
					else {
						printf("            %sw (rip), %u ", mn, k);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("            %sd (eip), %u ", mn, k);
					}
					else {
						printf("            %sd (rip), %u ", mn, k);
					}
				}
				else {
					if (lga) {
						printf("            %sq (eip), %u ", mn, k);
					}
					else {
						printf("            %sq (rip), %u ", mn, k);
					}
				}
			}
		}
		else {
			*bn += 1;
			printf("               %02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn += 1;
			if (lgo) {
				if (lga) {
					printf("            %sw (%s), %u ", mn, x86_64_r32(mrd), k);
				}
				else {
					printf("            %sw (%s), %u ", mn, x86_64_r64(mrd), k);
				}
			}
			else if (!rx3) {
				if (lga) {
					printf("            %sd (%s), %u ", mn, x86_64_r32(mrd), k);
				}
				else {
					printf("            %sd (%s), %u ", mn, x86_64_r64(mrd), k);
				}
			}
			else {
				if (lga) {
					printf("            %sq (%s), %u ", mn, x86_64_r32(mrd), k);
				}
				else {
					printf("            %sq (%s), %u ", mn, x86_64_r64(mrd), k);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			
			if (i == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				printf("         %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("            %sw (%s, %u), %u ", mn, x86_64_r32(b), d, k);
					}
					else {
						printf("            %sw (%s, %u), %u ", mn, x86_64_r64(b), d, k);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("            %sd (%s, %u), %u ", mn, x86_64_r32(b), d, k);
					}
					else {
						printf("            %sd (%s, %u), %u ", mn, x86_64_r64(b), d, k);
					}
				}
				else {
					if (lga) {
						printf("            %sq (%s, %u), %u ", mn, x86_64_r32(b), d, k);
					}
					else {
						printf("            %sq (%s, %u), %u ", mn, x86_64_r64(b), d, k);
					}
				}
			}
			else if (s) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				printf("         %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("            %sw (%s, (%s, %u), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, k);
					}
					else {
						printf("            %sw (%s, (%s, %u), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, k);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("            %sd (%s, (%s, %u), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, k);
					}
					else {
						printf("            %sd (%s, (%s, %u), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, k);
					}
				}
				else {
					if (lga) {
						printf("            %sq (%s, (%s, %u), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, k);
					}
					else {
						printf("            %sq (%s, (%s, %u), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, k);
					}
				}
			}
			else {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				printf("         %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("            %sw (%s, (%s), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), d, k);
					}
					else {
						printf("            %sw (%s, (%s), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), d, k);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("            %sd (%s, (%s), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), d, k);
					}
					else {
						printf("            %sd (%s, (%s), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), d, k);
					}
				}
				else {
					if (lga) {
						printf("            %sq (%s, (%s), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), d, k);
					}
					else {
						printf("            %sq (%s, (%s), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), d, k);
					}
				}
			}
		}
		else {
			*bn += 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			printf("         %02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn += 1;
			if (lgo) {
				if (lga) {
					printf("            %sw (%s, %u), %u ", mn, x86_64_r32(mrd), d, k);
				}
				else {
					printf("            %sw (%s, %u), %u ", mn, x86_64_r64(mrd), d, k);
				}
			}
			else if (!rx3) {
				if (lga) {
					printf("            %sd (%s, %u), %u ", mn, x86_64_r32(mrd), d, k);
				}
				else {
					printf("            %sd (%s, %u), %u ", mn, x86_64_r64(mrd), d, k);
				}
			}
			else {
				if (lga) {
					printf("            %sq (%s, %u), %u ", mn, x86_64_r32(mrd), d, k);
				}
				else {
					printf("            %sq (%s, %u), %u ", mn, x86_64_r64(mrd), d, k);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("%02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("            %sw (%s, %u), %u ", mn, x86_64_r32(b), d, k);
					}
					else {
						printf("            %sw (%s, %u), %u ", mn, x86_64_r64(b), d, k);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("            %sd (%s, %u), %u ", mn, x86_64_r32(b), d, k);
					}
					else {
						printf("            %sd (%s, %u), %u ", mn, x86_64_r64(b), d, k);
					}
				}
				else {
					if (lga) {
						printf("            %sq (%s, %u), %u ", mn, x86_64_r32(b), d, k);
					}
					else {
						printf("            %sq (%s, %u), %u ", mn, x86_64_r64(b), d, k);
					}
				}
			}
			else if (s) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("%02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("            %sw (%s, (%s, %u), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, k);
					}
					else {
						printf("            %sw (%s, (%s, %u), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, k);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("            %sd (%s, (%s, %u), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, k);
					}
					else {
						printf("            %sd (%s, (%s, %u), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, k);
					}
				}
				else {
					if (lga) {
						printf("            %sq (%s, (%s, %u), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, k);
					}
					else {
						printf("            %sq (%s, (%s, %u), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, k);
					}
				}
			}
			else {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("%02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("            %sw (%s, (%s), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), d, k);
					}
					else {
						printf("            %sw (%s, (%s), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), d, k);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("            %sd (%s, (%s), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), d, k);
					}
					else {
						printf("            %sd (%s, (%s), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), d, k);
					}
				}
				else {
					if (lga) {
						printf("            %sq (%s, (%s), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), d, k);
					}
					else {
						printf("            %sq (%s, (%s), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), d, k);
					}
				}
			}
		}
		else {
			*bn += 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			printf("%02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn += 1;
			if (lgo) {
				if (lga) {
					printf("            %sw (%s, %u), %u ", mn, x86_64_r32(mrd), d, k);
				}
				else {
					printf("            %sw (%s, %u), %u ", mn, x86_64_r64(mrd), d, k);
				}
			}
			else if (!rx3) {
				if (lga) {
					printf("            %sd (%s, %u), %u ", mn, x86_64_r32(mrd), d, k);
				}
				else {
					printf("            %sd (%s, %u), %u ", mn, x86_64_r64(mrd), d, k);
				}
			}
			else {
				if (lga) {
					printf("            %sq (%s, %u), %u ", mn, x86_64_r32(mrd), d, k);
				}
				else {
					printf("            %sq (%s, %u), %u ", mn, x86_64_r64(mrd), d, k);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		*bn += 1;
		printf("               %02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn += 1;
		if (lgo) {
			printf("            %sw %s, %u ", mn, x86_64_r16(mrd + (8 * rx2)), k);
		}
		else if (!rx3) {
			printf("            %sd %s, %u ", mn, x86_64_r32(mrd + (8 * rx2)), k);
		}
		else {
			printf("            %sq %s, %u ", mn, x86_64_r64(mrd + (8 * rx2)), k);
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_stck(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if ((bin[*bn] & 248) == op) {
		printf("%02x ", bin[*bn]);
		uint8_t reg = (bin[*bn] & 7) + (8 * rx0); 
		*bn += 1;
		
		if (lgo) {
			printf("                                 %sw %s ", mn, x86_64_r16(reg));
		}
		else {
			printf("                                 %s %s ", mn, x86_64_r64(reg));
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_mvp(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if ((bin[*bn] & 248) == op) {
		printf("%02x ", bin[*bn]);
		uint8_t reg = (bin[*bn] & 7) + (8 * rx0);
		*bn += 1;
		
		printf("                  %02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn += 1;
		printf("            %s %s, %u ", mn, x86_64_r8(reg), k);
		
		return 0;
	}
	else if ((bin[*bn] & 248) == op + 8) {
		printf("%02x ", bin[*bn]);
		uint8_t reg = (bin[*bn] & 7) + (8 * rx0);
		*bn += 1;
		
		if (lgo) {
			printf("                  %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			printf("         %s %s, %u ", mn, x86_64_r16(reg), k);
		}
		else if (!rx3) {
			printf("                  %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			printf("   %s %s, %u ", mn, x86_64_r32(reg), k);
		}
		else {
			printf("      %02x %02x %02x %02x %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3], bin[*bn + 4], bin[*bn + 5], bin[*bn + 6], bin[*bn + 7]);
			uint64_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24) + (bin[*bn + 4] << 32) + (bin[*bn + 5] << 40) + (bin[*bn + 6] << 48) + (bin[*bn + 7] << 56);
			*bn += 8;
			printf("   %s %s, %lu ", mn, x86_64_r64(reg), k);
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_op_imm(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		
		if (lgo) {
			printf("                  %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			printf("         %sw %u ", mn, k);
		}
		else {
			printf("                  %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			printf("   %s %u ", mn, k);
		}
		return 0;
	}
	else if (bin[*bn] == op + 2) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		
		printf("                  %02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn += 1;
		if (lgo) {
			printf("            %sw %u ", mn, k);
		}
		else {
			printf("            %s %u ", mn, k);
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_blnk(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4 && (b & 7) == 5) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					printf("               %sw (%u) ", mn, d);
				}
				else {
					printf("               %s (%u) ", mn, d);
				}
			}
			else if (i == 4) {
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                           %sw (%s) ", mn, x86_64_r32(b));
					}
					else {
						printf("                           %sw (%s) ", mn, x86_64_r64(b));
					}
				}
				else {
					if (lga) {
						printf("                           %s (%s) ", mn, x86_64_r32(b));
					}
					else {
						printf("                           %s (%s) ", mn, x86_64_r64(b));
					}
				}
			}
			else if (s) {
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                           %sw (%s, (%s, %u)) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
					}
					else {
						printf("                           %sw (%s, (%s, %u)) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
					}
				}
				else {
					if (lga) {
						printf("                           %s (%s, (%s, %u)) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
					}
					else {
						printf("                           %s (%s, (%s, %u)) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
					}
				}
			}
			else {
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                           %sw (%s, (%s)) ", mn, x86_64_r32(b), x86_64_r32(i));
					}
					else {
						printf("                           %sw (%s, (%s)) ", mn, x86_64_r64(b), x86_64_r64(i));
					}
				}
				else {
					if (lga) {
						printf("                           %s (%s, (%s)) ", mn, x86_64_r32(b), x86_64_r32(i));
					}
					else {
						printf("                           %s (%s, (%s)) ", mn, x86_64_r64(b), x86_64_r64(i));
					}
				}
			}
		}
		else {
			*bn += 1;
			if (lgo) {
				if (lga) {
					printf("                              %sw (%s) ", mn, x86_64_r32(mrd));
				}
				else {
					printf("                              %sw (%s) ", mn, x86_64_r64(mrd));
				}
			}
			else {
				if (lga) {
					printf("                              %s (%s) ", mn, x86_64_r32(mrd));
				}
				else {
					printf("                              %s (%s) ", mn, x86_64_r64(mrd));
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			
			if (i == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                        %sw (%s, %u) ", mn, x86_64_r32(b), d);
					}
					else {
						printf("                        %sw (%s, %u) ", mn, x86_64_r64(b), d);
					}
				}
				else {
					if (lga) {
						printf("                        %s (%s, %u) ", mn, x86_64_r32(b), d);
					}
					else {
						printf("                        %s (%s, %u) ", mn, x86_64_r64(b), d);
					}
				}
			}
			else if (s) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                        %sw (%s, (%s, %u), %u) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
					else {
						printf("                        %sw (%s, (%s, %u), %u) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
				}
				else {
					if (lga) {
						printf("                        %s (%s, (%s, %u), %u) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
					else {
						printf("                        %s (%s, (%s, %u), %u) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
				}
			}
			else {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                        %sw (%s, (%s), %u) ", mn, x86_64_r32(b), x86_64_r32(i), d);
					}
					else {
						printf("                        %sw (%s, (%s), %u) ", mn, x86_64_r64(b), x86_64_r64(i), d);
					}
				}
				else {
					if (lga) {
						printf("                        %s (%s, (%s), %u) ", mn, x86_64_r32(b), x86_64_r32(i), d);
					}
					else {
						printf("                        %s (%s, (%s), %u) ", mn, x86_64_r64(b), x86_64_r64(i), d);
					}
				}
			}
		}
		else {
			*bn += 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			if (lgo) {
				if (lga) {
					printf("                        %sw (%s, %u) ", mn, x86_64_r32(mrd), d);
				}
				else {
					printf("                        %sw (%s, %u) ", mn, x86_64_r64(mrd), d);
				}
			}
			else {
				if (lga) {
					printf("                        %s (%s, %u) ", mn, x86_64_r32(mrd), d);
				}
				else {
					printf("                        %s (%s, %u) ", mn, x86_64_r64(mrd), d);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					if (lga) {
						printf("               %sw (%s, %u) ", mn, x86_64_r32(b), d);
					}
					else {
						printf("               %sw (%s, %u) ", mn, x86_64_r64(b), d);
					}
				}
				else {
					if (lga) {
						printf("               %s (%s, %u) ", mn, x86_64_r32(b), d);
					}
					else {
						printf("               %s (%s, %u) ", mn, x86_64_r64(b), d);
					}
				}
			}
			else if (s) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					if (lga) {
						printf("               %sw (%s, (%s, %u), %u) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
					else {
						printf("               %sw (%s, (%s, %u), %u) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
				}
				else {
					if (lga) {
						printf("               %s (%s, (%s, %u), %u) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
					else {
						printf("               %s (%s, (%s, %u), %u) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
				}
			}
			else {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					if (lga) {
						printf("               %sw (%s, (%s), %u) ", mn, x86_64_r32(b), x86_64_r32(i), d);
					}
					else {
						printf("               %sw (%s, (%s), %u) ", mn, x86_64_r64(b), x86_64_r64(i), d);
					}
				}
				else {
					if (lga) {
						printf("               %s (%s, (%s), %u) ", mn, x86_64_r32(b), x86_64_r32(i), d);
					}
					else {
						printf("               %s (%s, (%s), %u) ", mn, x86_64_r64(b), x86_64_r64(i), d);
					}
				}
			}
		}
		else {
			*bn += 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			if (lgo) {
				if (lga) {
					printf("               %sw (%s, %u) ", mn, x86_64_r32(mrd), d);
				}
				else {
					printf("               %sw (%s, %u) ", mn, x86_64_r64(mrd), d);
				}
			}
			else {
				if (lga) {
					printf("               %s (%s, %u) ", mn, x86_64_r32(mrd), d);
				}
				else {
					printf("               %s (%s, %u) ", mn, x86_64_r64(mrd), d);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		*bn += 1;
		if (lgo) {
			printf("                              %sw %s ", mn, x86_64_r16(mrd));
		}
		else {
			printf("                              %s %s ", mn, x86_64_r64(mrd));
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_alnk(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4 && (b & 7) == 5) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("               %sb (%u) ", mn, d);
			}
			else if (i == 4) {
				*bn += 1;
				if (lga) {
					printf("                           %sb (%s) ", mn, x86_64_r32(b));
				}
				else {
					printf("                           %sb (%s) ", mn, x86_64_r64(b));
				}
			}
			else if (s) {
				*bn += 1;
				if (lga) {
					printf("                           %sb (%s, (%s, %u)) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
				}
				else {
					printf("                           %sb (%s, (%s, %u)) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
				}
			}
			else {
				*bn += 1;
				if (lga) {
					printf("                           %sb (%s, (%s)) ", mn, x86_64_r32(b), x86_64_r32(i));
				}
				else {
					printf("                           %sb (%s, (%s)) ", mn, x86_64_r64(b), x86_64_r64(i));
				}
			}
		}
		else {
			*bn += 1;
			if (lga) {
				printf("                              %sb (%s) ", mn, x86_64_r32(mrd));
			}
			else {
				printf("                              %sb (%s) ", mn, x86_64_r64(mrd));
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			
			if (i == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lga) {
					printf("                        %sb (%s, %u) ", mn, x86_64_r32(b), d);
				}
				else {
					printf("                        %sb (%s, %u) ", mn, x86_64_r64(b), d);
				}
			}
			else if (s) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lga) {
					printf("                        %sb (%s, (%s, %u), %u) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
				}
				else {
					printf("                        %sb (%s, (%s, %u), %u) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
				}
			}
			else {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lga) {
					printf("                        %sb (%s, (%s), %u) ", mn, x86_64_r32(b), x86_64_r32(i), d);
				}
				else {
					printf("                        %sb (%s, (%s), %u) ", mn, x86_64_r64(b), x86_64_r64(i), d);
				}
			}
		}
		else {
			*bn += 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			if (lga) {
				printf("                        %sb (%s, %u) ", mn, x86_64_r32(mrd), d);
			}
			else {
				printf("                        %sb (%s, %u) ", mn, x86_64_r64(mrd), d);
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lga) {
					printf("               %sb (%s, %u) ", mn, x86_64_r32(b), d);
				}
				else {
					printf("               %sb (%s, %u) ", mn, x86_64_r64(b), d);
				}
			}
			else if (s) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lga) {
					printf("               %sb (%s, (%s, %u), %u) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
				}
				else {
					printf("               %sb (%s, (%s, %u), %u) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
				}
			}
			else {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lga) {
					printf("               %sb (%s, (%s), %u) ", mn, x86_64_r32(b), x86_64_r32(i), d);
				}
				else {
					printf("               %sb (%s, (%s), %u) ", mn, x86_64_r64(b), x86_64_r64(i), d);
				}
			}
		}
		else {
			*bn += 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			if (lga) {
				printf("               %sb (%s, %u) ", mn, x86_64_r32(mrd), d);
			}
			else {
				printf("               %sb (%s, %u) ", mn, x86_64_r64(mrd), d);
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		*bn += 1;
		if (rex) {
			printf("                              %s %s ", mn, x86_64_r8x(mrd));
		}
		else {
			printf("                              %s %s ", mn, x86_64_r8(mrd));
		}
		return 0;
	}
	else if (bin[*bn] == op0 + 1 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4 && (b & 7) == 5) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					printf("               %sw (%u) ", mn, d);
				}
				else if (!rx3) {
					printf("               %sd (%u) ", mn, d);
				}
				else {
					printf("               %sq (%u) ", mn, d);
				}
			}
			else if (i == 4) {
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                           %sw (%s) ", mn, x86_64_r32(b));
					}
					else {
						printf("                           %sw (%s) ", mn, x86_64_r64(b));
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                           %sd (%s) ", mn, x86_64_r32(b));
					}
					else {
						printf("                           %sd (%s) ", mn, x86_64_r64(b));
					}
				}
				else {
					if (lga) {
						printf("                           %sq (%s) ", mn, x86_64_r32(b));
					}
					else {
						printf("                           %sq (%s) ", mn, x86_64_r64(b));
					}
				}
			}
			else if (s) {
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                           %sw (%s, (%s, %u)) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
					}
					else {
						printf("                           %sw (%s, (%s, %u)) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                           %sd (%s, (%s, %u)) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
					}
					else {
						printf("                           %sd (%s, (%s, %u)) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
					}
				}
				else {
					if (lga) {
						printf("                           %sq (%s, (%s, %u)) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
					}
					else {
						printf("                           %sq (%s, (%s, %u)) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
					}
				}
			}
			else {
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                           %sw (%s, (%s)) ", mn, x86_64_r32(b), x86_64_r32(i));
					}
					else {
						printf("                           %sw (%s, (%s)) ", mn, x86_64_r64(b), x86_64_r64(i));
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                           %sd (%s, (%s)) ", mn, x86_64_r32(b), x86_64_r32(i));
					}
					else {
						printf("                           %sd (%s, (%s)) ", mn, x86_64_r64(b), x86_64_r64(i));
					}
				}
				else {
					if (lga) {
						printf("                           %sq (%s, (%s)) ", mn, x86_64_r32(b), x86_64_r32(i));
					}
					else {
						printf("                           %sq (%s, (%s)) ", mn, x86_64_r64(b), x86_64_r64(i));
					}
				}
			}
		}
		else {
			*bn += 1;
			if (lgo) {
				if (lga) {
					printf("                              %sw (%s) ", mn, x86_64_r32(mrd));
				}
				else {
					printf("                              %sw (%s) ", mn, x86_64_r64(mrd));
				}
			}
			else if (!rx3) {
				if (lga) {
					printf("                              %sd (%s) ", mn, x86_64_r32(mrd));
				}
				else {
					printf("                              %sd (%s) ", mn, x86_64_r64(mrd));
				}
			}
			else {
				if (lga) {
					printf("                              %sq (%s) ", mn, x86_64_r32(mrd));
				}
				else {
					printf("                              %sq (%s) ", mn, x86_64_r64(mrd));
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 + 1 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			
			if (i == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                        %sw (%s, %u) ", mn, x86_64_r32(b), d);
					}
					else {
						printf("                        %sw (%s, %u) ", mn, x86_64_r64(b), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                        %sd (%s, %u) ", mn, x86_64_r32(b), d);
					}
					else {
						printf("                        %sd (%s, %u) ", mn, x86_64_r64(b), d);
					}
				}
				else {
					if (lga) {
						printf("                        %sq (%s, %u) ", mn, x86_64_r32(b), d);
					}
					else {
						printf("                        %sq (%s, %u) ", mn, x86_64_r64(b), d);
					}
				}
			}
			else if (s) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                        %sw (%s, (%s, %u), %u) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
					else {
						printf("                        %sw (%s, (%s, %u), %u) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                        %sd (%s, (%s, %u), %u) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
					else {
						printf("                        %sd (%s, (%s, %u), %u) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
				}
				else {
					if (lga) {
						printf("                        %sq (%s, (%s, %u), %u) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
					else {
						printf("                        %sq (%s, (%s, %u), %u) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
				}
			}
			else {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                        %sw (%s, (%s), %u) ", mn, x86_64_r32(b), x86_64_r32(i), d);
					}
					else {
						printf("                        %sw (%s, (%s), %u) ", mn, x86_64_r64(b), x86_64_r64(i), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                        %sd (%s, (%s), %u) ", mn, x86_64_r32(b), x86_64_r32(i), d);
					}
					else {
						printf("                        %sd (%s, (%s), %u) ", mn, x86_64_r64(b), x86_64_r64(i), d);
					}
				}
				else {
					if (lga) {
						printf("                        %sq (%s, (%s), %u) ", mn, x86_64_r32(b), x86_64_r32(i), d);
					}
					else {
						printf("                        %sq (%s, (%s), %u) ", mn, x86_64_r64(b), x86_64_r64(i), d);
					}
				}
			}
		}
		else {
			*bn += 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			if (lgo) {
				if (lga) {
					printf("                        %sw (%s, %u) ", mn, x86_64_r32(mrd), d);
				}
				else {
					printf("                        %sw (%s, %u) ", mn, x86_64_r64(mrd), d);
				}
			}
			else if (!rx3) {
				if (lga) {
					printf("                        %sd (%s, %u) ", mn, x86_64_r32(mrd), d);
				}
				else {
					printf("                        %sd (%s, %u) ", mn, x86_64_r64(mrd), d);
				}
			}
			else {
				if (lga) {
					printf("                        %sq (%s, %u) ", mn, x86_64_r32(mrd), d);
				}
				else {
					printf("                        %sq (%s, %u) ", mn, x86_64_r64(mrd), d);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 + 1 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					if (lga) {
						printf("               %sw (%s, %u) ", mn, x86_64_r32(b), d);
					}
					else {
						printf("               %sw (%s, %u) ", mn, x86_64_r64(b), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("               %sd (%s, %u) ", mn, x86_64_r32(b), d);
					}
					else {
						printf("               %sd (%s, %u) ", mn, x86_64_r64(b), d);
					}
				}
				else {
					if (lga) {
						printf("               %sq (%s, %u) ", mn, x86_64_r32(b), d);
					}
					else {
						printf("               %sq (%s, %u) ", mn, x86_64_r64(b), d);
					}
				}
			}
			else if (s) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					if (lga) {
						printf("               %sw (%s, (%s, %u), %u) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
					else {
						printf("               %sw (%s, (%s, %u), %u) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("               %sd (%s, (%s, %u), %u) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
					else {
						printf("               %sd (%s, (%s, %u), %u) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
				}
				else {
					if (lga) {
						printf("               %sq (%s, (%s, %u), %u) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
					else {
						printf("               %sq (%s, (%s, %u), %u) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
				}
			}
			else {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					if (lga) {
						printf("               %sw (%s, (%s), %u) ", mn, x86_64_r32(b), x86_64_r32(i), d);
					}
					else {
						printf("               %sw (%s, (%s), %u) ", mn, x86_64_r64(b), x86_64_r64(i), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("               %sd (%s, (%s), %u) ", mn, x86_64_r32(b), x86_64_r32(i), d);
					}
					else {
						printf("               %sd (%s, (%s), %u) ", mn, x86_64_r64(b), x86_64_r64(i), d);
					}
				}
				else {
					if (lga) {
						printf("               %sq (%s, (%s), %u) ", mn, x86_64_r32(b), x86_64_r32(i), d);
					}
					else {
						printf("               %sq (%s, (%s), %u) ", mn, x86_64_r64(b), x86_64_r64(i), d);
					}
				}
			}
		}
		else {
			*bn += 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			if (lgo) {
				if (lga) {
					printf("               %sw (%s, %u) ", mn, x86_64_r32(mrd), d);
				}
				else {
					printf("               %sw (%s, %u) ", mn, x86_64_r64(mrd), d);
				}
			}
			else if (!rx3) {
				if (lga) {
					printf("               %sd (%s, %u) ", mn, x86_64_r32(mrd), d);
				}
				else {
					printf("               %sd (%s, %u) ", mn, x86_64_r64(mrd), d);
				}
			}
			else {
				if (lga) {
					printf("               %sq (%s, %u) ", mn, x86_64_r32(mrd), d);
				}
				else {
					printf("               %sq (%s, %u) ", mn, x86_64_r64(mrd), d);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 + 1 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		*bn += 1;
		if (lgo) {
			printf("                              %s %s ", mn, x86_64_r16(mrd));
		}
		else if (!rx3) {
			printf("                              %s %s ", mn, x86_64_r32(mrd));
		}
		else {
			printf("                              %s %s ", mn, x86_64_r64(mrd));
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_mlnk(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4 && (b & 7) == 5) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("               %sb ax, (%u) ", mn, d);
			}
			else if (i == 4) {
				*bn += 1;
				if (lga) {
					printf("                           %sb ax, (%s) ", mn, x86_64_r32(b));
				}
				else {
					printf("                           %sb ax, (%s) ", mn, x86_64_r64(b));
				}
			}
			else if (s) {
				*bn += 1;
				if (lga) {
					printf("                           %sb ax, (%s, (%s, %u)) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
				}
				else {
					printf("                           %sb ax, (%s, (%s, %u)) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
				}
			}
			else {
				*bn += 1;
				if (lga) {
					printf("                           %sb ax, (%s, (%s)) ", mn, x86_64_r32(b), x86_64_r32(i));
				}
				else {
					printf("                           %sb ax, (%s, (%s)) ", mn, x86_64_r64(b), x86_64_r64(i));
				}
			}
		}
		else {
			*bn += 1;
			if (lga) {
				printf("                              %sb ax, (%s) ", mn, x86_64_r32(mrd));
			}
			else {
				printf("                              %sb ax, (%s) ", mn, x86_64_r64(mrd));
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			
			if (i == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lga) {
					printf("                        %sb ax, (%s, %u) ", mn, x86_64_r32(b), d);
				}
				else {
					printf("                        %sb ax, (%s, %u) ", mn, x86_64_r64(b), d);
				}
			}
			else if (s) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lga) {
					printf("                        %sb ax, (%s, (%s, %u), %u) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
				}
				else {
					printf("                        %sb ax, (%s, (%s, %u), %u) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
				}
			}
			else {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lga) {
					printf("                        %sb ax, (%s, (%s), %u) ", mn, x86_64_r32(b), x86_64_r32(i), d);
				}
				else {
					printf("                        %sb ax, (%s, (%s), %u) ", mn, x86_64_r64(b), x86_64_r64(i), d);
				}
			}
		}
		else {
			*bn += 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			if (lga) {
				printf("                        %sb ax, (%s, %u) ", mn, x86_64_r32(mrd), d);
			}
			else {
				printf("                        %sb ax, (%s, %u) ", mn, x86_64_r64(mrd), d);
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lga) {
					printf("               %sb ax, (%s, %u) ", mn, x86_64_r32(b), d);
				}
				else {
					printf("               %sb ax, (%s, %u) ", mn, x86_64_r64(b), d);
				}
			}
			else if (s) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lga) {
					printf("               %sb ax, (%s, (%s, %u), %u) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
				}
				else {
					printf("               %sb ax, (%s, (%s, %u), %u) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
				}
			}
			else {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lga) {
					printf("               %sb ax, (%s, (%s), %u) ", mn, x86_64_r32(b), x86_64_r32(i), d);
				}
				else {
					printf("               %sb ax, (%s, (%s), %u) ", mn, x86_64_r64(b), x86_64_r64(i), d);
				}
			}
		}
		else {
			*bn += 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			if (lga) {
				printf("               %sb ax, (%s, %u) ", mn, x86_64_r32(mrd), d);
			}
			else {
				printf("               %sb ax, (%s, %u) ", mn, x86_64_r64(mrd), d);
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		*bn += 1;
		if (rex) {
			printf("                              %s ax, %s ", mn, x86_64_r8x(mrd));
		}
		else {
			printf("                              %s ax, %s ", mn, x86_64_r8(mrd));
		}
		return 0;
	}
	else if (bin[*bn] == op0 + 1 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4 && (b & 7) == 5) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					printf("               %sw ax, (%u) ", mn, d);
				}
				else if (!rx3) {
					printf("               %sd eax, (%u) ", mn, d);
				}
				else {
					printf("               %sq rax, (%u) ", mn, d);
				}
			}
			else if (i == 4) {
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                           %sw ax, (%s) ", mn, x86_64_r32(b));
					}
					else {
						printf("                           %sw ax, (%s) ", mn, x86_64_r64(b));
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                           %sd eax, (%s) ", mn, x86_64_r32(b));
					}
					else {
						printf("                           %sd eax, (%s) ", mn, x86_64_r64(b));
					}
				}
				else {
					if (lga) {
						printf("                           %sq rax, (%s) ", mn, x86_64_r32(b));
					}
					else {
						printf("                           %sq rax, (%s) ", mn, x86_64_r64(b));
					}
				}
			}
			else if (s) {
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                           %sw ax, (%s, (%s, %u)) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
					}
					else {
						printf("                           %sw ax, (%s, (%s, %u)) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                           %sd eax, (%s, (%s, %u)) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
					}
					else {
						printf("                           %sd eax, (%s, (%s, %u)) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
					}
				}
				else {
					if (lga) {
						printf("                           %sq rax, (%s, (%s, %u)) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
					}
					else {
						printf("                           %sq rax, (%s, (%s, %u)) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
					}
				}
			}
			else {
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                           %sw ax, (%s, (%s)) ", mn, x86_64_r32(b), x86_64_r32(i));
					}
					else {
						printf("                           %sw ax, (%s, (%s)) ", mn, x86_64_r64(b), x86_64_r64(i));
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                           %sd eax, (%s, (%s)) ", mn, x86_64_r32(b), x86_64_r32(i));
					}
					else {
						printf("                           %sd eax, (%s, (%s)) ", mn, x86_64_r64(b), x86_64_r64(i));
					}
				}
				else {
					if (lga) {
						printf("                           %sq rax, (%s, (%s)) ", mn, x86_64_r32(b), x86_64_r32(i));
					}
					else {
						printf("                           %sq rax, (%s, (%s)) ", mn, x86_64_r64(b), x86_64_r64(i));
					}
				}
			}
		}
		else {
			*bn += 1;
			if (lgo) {
				if (lga) {
					printf("                              %sw ax, (%s) ", mn, x86_64_r32(mrd));
				}
				else {
					printf("                              %sw ax, (%s) ", mn, x86_64_r64(mrd));
				}
			}
			else if (!rx3) {
				if (lga) {
					printf("                              %sd eax, (%s) ", mn, x86_64_r32(mrd));
				}
				else {
					printf("                              %sd eax, (%s) ", mn, x86_64_r64(mrd));
				}
			}
			else {
				if (lga) {
					printf("                              %sq rax, (%s) ", mn, x86_64_r32(mrd));
				}
				else {
					printf("                              %sq rax, (%s) ", mn, x86_64_r64(mrd));
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 + 1 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			
			if (i == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                        %sw ax, (%s, %u) ", mn, x86_64_r32(b), d);
					}
					else {
						printf("                        %sw ax, (%s, %u) ", mn, x86_64_r64(b), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                        %sd eax, (%s, %u) ", mn, x86_64_r32(b), d);
					}
					else {
						printf("                        %sd eax, (%s, %u) ", mn, x86_64_r64(b), d);
					}
				}
				else {
					if (lga) {
						printf("                        %sq rax, (%s, %u) ", mn, x86_64_r32(b), d);
					}
					else {
						printf("                        %sq rax, (%s, %u) ", mn, x86_64_r64(b), d);
					}
				}
			}
			else if (s) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                        %sw ax, (%s, (%s, %u), %u) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
					else {
						printf("                        %sw ax, (%s, (%s, %u), %u) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                        %sd eax, (%s, (%s, %u), %u) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
					else {
						printf("                        %sd eax, (%s, (%s, %u), %u) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
				}
				else {
					if (lga) {
						printf("                        %sq rax, (%s, (%s, %u), %u) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
					else {
						printf("                        %sq rax, (%s, (%s, %u), %u) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
				}
			}
			else {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                        %sw ax, (%s, (%s), %u) ", mn, x86_64_r32(b), x86_64_r32(i), d);
					}
					else {
						printf("                        %sw ax, (%s, (%s), %u) ", mn, x86_64_r64(b), x86_64_r64(i), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                        %sd eax, (%s, (%s), %u) ", mn, x86_64_r32(b), x86_64_r32(i), d);
					}
					else {
						printf("                        %sd eax, (%s, (%s), %u) ", mn, x86_64_r64(b), x86_64_r64(i), d);
					}
				}
				else {
					if (lga) {
						printf("                        %sq rax, (%s, (%s), %u) ", mn, x86_64_r32(b), x86_64_r32(i), d);
					}
					else {
						printf("                        %sq rax, (%s, (%s), %u) ", mn, x86_64_r64(b), x86_64_r64(i), d);
					}
				}
			}
		}
		else {
			*bn += 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			if (lgo) {
				if (lga) {
					printf("                        %sw ax, (%s, %u) ", mn, x86_64_r32(mrd), d);
				}
				else {
					printf("                        %sw ax, (%s, %u) ", mn, x86_64_r64(mrd), d);
				}
			}
			else if (!rx3) {
				if (lga) {
					printf("                        %sd eax, (%s, %u) ", mn, x86_64_r32(mrd), d);
				}
				else {
					printf("                        %sd eax, (%s, %u) ", mn, x86_64_r64(mrd), d);
				}
			}
			else {
				if (lga) {
					printf("                        %sq rax, (%s, %u) ", mn, x86_64_r32(mrd), d);
				}
				else {
					printf("                        %sq rax, (%s, %u) ", mn, x86_64_r64(mrd), d);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 + 1 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					if (lga) {
						printf("               %sw ax, (%s, %u) ", mn, x86_64_r32(b), d);
					}
					else {
						printf("               %sw ax, (%s, %u) ", mn, x86_64_r64(b), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("               %sd eax, (%s, %u) ", mn, x86_64_r32(b), d);
					}
					else {
						printf("               %sd eax, (%s, %u) ", mn, x86_64_r64(b), d);
					}
				}
				else {
					if (lga) {
						printf("               %sq rax, (%s, %u) ", mn, x86_64_r32(b), d);
					}
					else {
						printf("               %sq rax, (%s, %u) ", mn, x86_64_r64(b), d);
					}
				}
			}
			else if (s) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					if (lga) {
						printf("               %sw ax, (%s, (%s, %u), %u) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
					else {
						printf("               %sw ax, (%s, (%s, %u), %u) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("               %sd eax, (%s, (%s, %u), %u) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
					else {
						printf("               %sd eax, (%s, (%s, %u), %u) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
				}
				else {
					if (lga) {
						printf("               %sq rax, (%s, (%s, %u), %u) ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
					else {
						printf("               %sq rax, (%s, (%s, %u), %u) ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
				}
			}
			else {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					if (lga) {
						printf("               %sw ax, (%s, (%s), %u) ", mn, x86_64_r32(b), x86_64_r32(i), d);
					}
					else {
						printf("               %sw ax, (%s, (%s), %u) ", mn, x86_64_r64(b), x86_64_r64(i), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("               %sd eax, (%s, (%s), %u) ", mn, x86_64_r32(b), x86_64_r32(i), d);
					}
					else {
						printf("               %sd eax, (%s, (%s), %u) ", mn, x86_64_r64(b), x86_64_r64(i), d);
					}
				}
				else {
					if (lga) {
						printf("               %sq rax, (%s, (%s), %u) ", mn, x86_64_r32(b), x86_64_r32(i), d);
					}
					else {
						printf("               %sq rax, (%s, (%s), %u) ", mn, x86_64_r64(b), x86_64_r64(i), d);
					}
				}
			}
		}
		else {
			*bn += 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			if (lgo) {
				if (lga) {
					printf("               %sw ax, (%s, %u) ", mn, x86_64_r32(mrd), d);
				}
				else {
					printf("               %sw ax, (%s, %u) ", mn, x86_64_r64(mrd), d);
				}
			}
			else if (!rx3) {
				if (lga) {
					printf("               %sd eax, (%s, %u) ", mn, x86_64_r32(mrd), d);
				}
				else {
					printf("               %sd eax, (%s, %u) ", mn, x86_64_r64(mrd), d);
				}
			}
			else {
				if (lga) {
					printf("               %sq rax, (%s, %u) ", mn, x86_64_r32(mrd), d);
				}
				else {
					printf("               %sq rax, (%s, %u) ", mn, x86_64_r64(mrd), d);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 + 1 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		*bn += 1;
		if (lgo) {
			printf("                              %s ax, %s ", mn, x86_64_r16(mrd));
		}
		else if (!rx3) {
			printf("                              %s eax, %s ", mn, x86_64_r32(mrd));
		}
		else {
			printf("                              %s rax, %s ", mn, x86_64_r64(mrd));
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_cond(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		
		printf("                  %02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn += 1;
		
		printf("            %s %u ", mn, k);
		return 0;
	}
	else if (bin[*bn] == 15 && bin[*bn + 1] == op + 16) {
		printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
		*bn += 2;
		
		printf("               %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
		uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
		*bn += 4;
		
		printf("   %s %u ", mn, k);
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_jmp(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		
		if (lgo) {
			printf("               %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			printf("         %sw %u ", mn, k);
		}
		else {
			printf("               %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			printf("   %s %u ", mn, k);
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_shft_k80(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4 && (b & 7) == 5) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lga) {
					printf("               %sb (%u), 1 ", mn, d);
				}
				else {
					printf("               %sb (%u), 1 ", mn, d);
				}
			}
			else if (i == 4) {
				*bn += 1;
				if (lga) {
					printf("                           %sb (%s), 1 ", mn, x86_64_r32(b));
				}
				else {
					printf("                           %sb (%s), 1 ", mn, x86_64_r64(b));
				}
			}
			else if (s) {
				*bn += 1;
				if (lga) {
					printf("                           %sb (%s, (%s, %u)), 1 ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
				}
				else {
					printf("                           %sb (%s, (%s, %u)), 1 ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
				}
			}
			else {
				*bn += 1;
				if (lga) {
					printf("                           %sb (%s, (%s)), 1 ", mn, x86_64_r32(b), x86_64_r32(i));
				}
				else {
					printf("                           %sb (%s, (%s)), 1 ", mn, x86_64_r64(b), x86_64_r64(i));
				}
			}
		}
		else if ((mrd & 7) == 5) {
			*bn += 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			if (d) {
				if (lga) {
					printf("               %sb (eip, %u), 1 ", mn, d);
				}
				else {
					printf("               %sb (rip, %u), 1 ", mn, d);
				}
			}
			else {
				if (lga) {
					printf("               %sb (eip), 1 ", mn);
				}
				else {
					printf("               %sb (rip), 1 ", mn);
				}
			}
		}
		else {
			*bn += 1;
			if (lga) {
				printf("                              %sb (%s), 1 ", mn, x86_64_r32(mrd));
			}
			else {
				printf("                              %sb (%s), 1 ", mn, x86_64_r64(mrd));
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lga) {
					printf("                        %sb (%s, %u), 1 ", mn, x86_64_r32(b), d);
				}
				else {
					printf("                        %sb (%s, %u), 1 ", mn, x86_64_r64(b), d);
				}
			}
			else if (s) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lga) {
					printf("                        %sb (%s, (%s, %u), %u), 1 ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
				}
				else {
					printf("                        %sb (%s, (%s, %u), %u), 1 ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
				}
			}
			else {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lga) {
					printf("                        %sb (%s, (%s), %u), 1 ", mn, x86_64_r32(b), x86_64_r32(i), d);
				}
				else {
					printf("                        %sb (%s, (%s), %u), 1 ", mn, x86_64_r64(b), x86_64_r64(i), d);
				}
			}
		}
		else {
			*bn += 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			if (lga) {
				printf("                        %sb (%s, %u), 1 ", mn, x86_64_r32(mrd), d);
			}
			else {
				printf("                        %sb (%s, %u), 1 ", mn, x86_64_r64(mrd), d);
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lga) {
					printf("               %sb (%s, %u), 1 ", mn, x86_64_r32(b), d);
				}
				else {
					printf("               %sb (%s, %u), 1 ", mn, x86_64_r64(b), d);
				}
			}
			else if (s) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lga) {
					printf("               %sb (%s, (%s, %u), %u), 1 ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
				}
				else {
					printf("               %sb (%s, (%s, %u), %u), 1 ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
				}
			}
			else {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lga) {
					printf("               %sb (%s, (%s), %u), 1 ", mn, x86_64_r32(b), x86_64_r32(i), d);
				}
				else {
					printf("               %sb (%s, (%s), %u), 1 ", mn, x86_64_r64(b), x86_64_r64(i), d);
				}
			}
		}
		else {
			*bn += 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			if (lga) {
				printf("               %sb (%s, %u), 1 ", mn, x86_64_r32(mrd), d);
			}
			else {
				printf("               %sb (%s, %u), 1 ", mn, x86_64_r64(mrd), d);
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		*bn += 1;
		if (rex) {
			printf("                              %sb %s, 1 ", mn, x86_64_r8x(mrd + (8 * rx2)));
		}
		else {
			printf("                              %sb %s, 1 ", mn, x86_64_r8(mrd + (8 * rx2)));
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_shft_k81(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4 && (b & 7) == 5) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					printf("               %sw (%u), 1 ", mn, d);
				}
				else if (!rx3) {
					printf("               %sd (%u), 1 ", mn, d);
				}
				else {
					printf("               %sq (%u), 1 ", mn, d);
				}
			}
			else if (i == 4) {
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                           %sw (%s), 1 ", mn, x86_64_r32(b));
					}
					else {
						printf("                           %sw (%s), 1 ", mn, x86_64_r64(b));
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                           %sd (%s), 1 ", mn, x86_64_r32(b));
					}
					else {
						printf("                           %sd (%s), 1 ", mn, x86_64_r64(b));
					}
				}
				else {
					if (lga) {
						printf("                           %sq (%s), 1 ", mn, x86_64_r32(b));
					}
					else {
						printf("                           %sq (%s), 1 ", mn, x86_64_r64(b));
					}
				}
			}
			else if (s) {
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                           %sw (%s, (%s, %u)), 1 ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
					}
					else {
						printf("                           %sw (%s, (%s, %u)), 1 ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                           %sd (%s, (%s, %u)), 1 ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
					}
					else {
						printf("                           %sd (%s, (%s, %u)), 1 ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
					}
				}
				else {
					if (lga) {
						printf("                           %sq (%s, (%s, %u)), 1 ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
					}
					else {
						printf("                           %sq (%s, (%s, %u)), 1 ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
					}
				}
			}
			else {
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                           %sw (%s, (%s)), 1 ", mn, x86_64_r32(b), x86_64_r32(i));
					}
					else {
						printf("                           %sw (%s, (%s)), 1 ", mn, x86_64_r64(b), x86_64_r64(i));
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                           %sd (%s, (%s)), 1 ", mn, x86_64_r32(b), x86_64_r32(i));
					}
					else {
						printf("                           %sd (%s, (%s)), 1 ", mn, x86_64_r64(b), x86_64_r64(i));
					}
				}
				else {
					if (lga) {
						printf("                           %sq (%s, (%s)), 1 ", mn, x86_64_r32(b), x86_64_r32(i));
					}
					else {
						printf("                           %sq (%s, (%s)), 1 ", mn, x86_64_r64(b), x86_64_r64(i));
					}
				}
			}
		}
		else if ((mrd & 7) == 5) {
			*bn += 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			if (d) {
				if (lgo) {
					if (lga) {
						printf("               %sw (eip, %u), 1 ", mn, d);
					}
					else {
						printf("               %sw (rip, %u), 1 ", mn, d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("               %sd (eip, %u), 1 ", mn, d);
					}
					else {
						printf("               %sd (rip, %u), 1 ", mn, d);
					}
				}
				else {
					if (lga) {
						printf("               %sq (eip, %u), 1 ", mn, d);
					}
					else {
						printf("               %sq (rip, %u), 1 ", mn, d);
					}
				}
			}
			else {
				if (lgo) {
					if (lga) {
						printf("               %sw (eip), 1 ", mn);
					}
					else {
						printf("               %sw (rip), 1 ", mn);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("               %sd (eip), 1 ", mn);
					}
					else {
						printf("               %sd (rip), 1 ", mn);
					}
				}
				else {
					if (lga) {
						printf("               %sq (eip), 1 ", mn);
					}
					else {
						printf("               %sq (rip), 1 ", mn);
					}
				}
			}
		}
		else {
			*bn += 1;
			if (lgo) {
				if (lga) {
					printf("                              %sw (%s), 1 ", mn, x86_64_r32(mrd));
				}
				else {
					printf("                              %sw (%s), 1 ", mn, x86_64_r64(mrd));
				}
			}
			else if (!rx3) {
				if (lga) {
					printf("                              %sd (%s), 1 ", mn, x86_64_r32(mrd));
				}
				else {
					printf("                              %sd (%s), 1 ", mn, x86_64_r64(mrd));
				}
			}
			else {
				if (lga) {
					printf("                              %sq (%s), 1 ", mn, x86_64_r32(mrd));
				}
				else {
					printf("                              %sq (%s), 1 ", mn, x86_64_r64(mrd));
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			
			if (i == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                        %sw (%s, %u), 1 ", mn, x86_64_r32(b), d);
					}
					else {
						printf("                        %sw (%s, %u), 1 ", mn, x86_64_r64(b), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                        %sd (%s, %u), 1 ", mn, x86_64_r32(b), d);
					}
					else {
						printf("                        %sd (%s, %u), 1 ", mn, x86_64_r64(b), d);
					}
				}
				else {
					if (lga) {
						printf("                        %sq (%s, %u), 1 ", mn, x86_64_r32(b), d);
					}
					else {
						printf("                        %sq (%s, %u), 1 ", mn, x86_64_r64(b), d);
					}
				}
			}
			else if (s) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                        %sw (%s, (%s, %u), %u), 1 ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
					else {
						printf("                        %sw (%s, (%s, %u), %u), 1 ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                        %sd (%s, (%s, %u), %u), 1 ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
					else {
						printf("                        %sd (%s, (%s, %u), %u), 1 ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
				}
				else {
					if (lga) {
						printf("                        %sq (%s, (%s, %u), %u), 1 ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
					else {
						printf("                        %sq (%s, (%s, %u), %u), 1 ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
				}
			}
			else {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                        %sw (%s, (%s), %u), 1 ", mn, x86_64_r32(b), x86_64_r32(i), d);
					}
					else {
						printf("                        %sw (%s, (%s), %u), 1 ", mn, x86_64_r64(b), x86_64_r64(i), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                        %sd (%s, (%s), %u), 1 ", mn, x86_64_r32(b), x86_64_r32(i), d);
					}
					else {
						printf("                        %sd (%s, (%s), %u), 1 ", mn, x86_64_r64(b), x86_64_r64(i), d);
					}
				}
				else {
					if (lga) {
						printf("                        %sq (%s, (%s), %u), 1 ", mn, x86_64_r32(b), x86_64_r32(i), d);
					}
					else {
						printf("                        %sq (%s, (%s), %u), 1 ", mn, x86_64_r64(b), x86_64_r64(i), d);
					}
				}
			}
		}
		else {
			*bn += 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			if (lgo) {
				if (lga) {
					printf("                         %sw (%s, %u), 1 ", mn, x86_64_r32(mrd), d);
				}
				else {
					printf("                         %sw (%s, %u), 1 ", mn, x86_64_r64(mrd), d);
				}
			}
			else if (!rx3) {
				if (lga) {
					printf("                         %sd (%s, %u), 1 ", mn, x86_64_r32(mrd), d);
				}
				else {
					printf("                         %sd (%s, %u), 1 ", mn, x86_64_r64(mrd), d);
				}
			}
			else {
				if (lga) {
					printf("                         %sq (%s, %u), 1 ", mn, x86_64_r32(mrd), d);
				}
				else {
					printf("                         %sq (%s, %u), 1 ", mn, x86_64_r64(mrd), d);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if ((mrd & 7) == 4) {
			*bn += 1;
			printf("%02x ", bin[*bn]);
			uint8_t b = (bin[*bn] & 7) + (8 * rx0);
			uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
			uint8_t s = (bin[*bn] >> 6);
			if (i == 4) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					if (lga) {
						printf("               %sw (%s, %u), 1 ", mn, x86_64_r32(b), d);
					}
					else {
						printf("               %sw (%s, %u), 1 ", mn, x86_64_r64(b), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("               %sd (%s, %u), 1 ", mn, x86_64_r32(b), d);
					}
					else {
						printf("               %sd (%s, %u), 1 ", mn, x86_64_r64(b), d);
					}
				}
				else {
					if (lga) {
						printf("               %sq (%s, %u), 1 ", mn, x86_64_r32(b), d);
					}
					else {
						printf("               %sq (%s, %u), 1 ", mn, x86_64_r64(b), d);
					}
				}
			}
			else if (s) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					if (lga) {
						printf("               %sw (%s, (%s, %u), %u), 1 ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
					else {
						printf("               %sw (%s, (%s, %u), %u), 1 ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("               %sd (%s, (%s, %u), %u), 1 ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
					else {
						printf("               %sd (%s, (%s, %u), %u), 1 ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
				}
				else {
					if (lga) {
						printf("               %sq (%s, (%s, %u), %u), 1 ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
					else {
						printf("               %sq (%s, (%s, %u), %u), 1 ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
				}
			}
			else {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					if (lga) {
						printf("               %sw (%s, (%s), %u), 1 ", mn, x86_64_r32(b), x86_64_r32(i), d);
					}
					else {
						printf("               %sw (%s, (%s), %u), 1 ", mn, x86_64_r64(b), x86_64_r64(i), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("               %sd (%s, (%s), %u), 1 ", mn, x86_64_r32(b), x86_64_r32(i), d);
					}
					else {
						printf("               %sd (%s, (%s), %u), 1 ", mn, x86_64_r64(b), x86_64_r64(i), d);
					}
				}
				else {
					if (lga) {
						printf("               %sq (%s, (%s), %u), 1 ", mn, x86_64_r32(b), x86_64_r32(i), d);
					}
					else {
						printf("               %sq (%s, (%s), %u), 1 ", mn, x86_64_r64(b), x86_64_r64(i), d);
					}
				}
			}
		}
		else {
			*bn += 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			if (lgo) {
				if (lga) {
					printf("               %sw (%s, %u), 1 ", mn, x86_64_r32(mrd), d);
				}
				else {
					printf("               %sw (%s, %u), 1 ", mn, x86_64_r64(mrd), d);
				}
			}
			else if (!rx3) {
				if (lga) {
					printf("               %sd (%s, %u), 1 ", mn, x86_64_r32(mrd), d);
				}
				else {
					printf("               %sd (%s, %u), 1 ", mn, x86_64_r64(mrd), d);
				}
			}
			else {
				if (lga) {
					printf("               %sq (%s, %u), 1 ", mn, x86_64_r32(mrd), d);
				}
				else {
					printf("               %sq (%s, %u), 1 ", mn, x86_64_r64(mrd), d);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		*bn += 1;
		if (lgo) {
			printf("                              %sw %s, 1 ", mn, x86_64_r16(mrd + (8 * rx2)));
		}
		else if (!rx3) {
			printf("                              %sd %s, 1 ", mn, x86_64_r32(mrd + (8 * rx2)));
		}
		else {
			printf("                              %sq %s, 1 ", mn, x86_64_r64(mrd + (8 * rx2)));
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_shft_r8(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op0 && ((bin[*bn + 1] >> 3) & 7) == op1) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if (mod == 0) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4 && (b & 7) == 5) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (rex) {
						printf("               %sb (%u), cl ", mn, d);
					}
					else {
						printf("               %sb (%u), cl ", mn, d);
					}
				}
				else if (i == 4) {
					*bn += 1;
					if (rex) {
						if (lga) {
							printf("                           %sb (%s), cl ", mn, x86_64_r32(b));
						}
						else {
							printf("                           %sb (%s), cl ", mn, x86_64_r64(b));
						}
					}
					else {
						if (lga) {
							printf("                           %sb (%s), cl ", mn, x86_64_r32(b));
						}
						else {
							printf("                           %sb (%s), cl ", mn, x86_64_r64(b));
						}
					}
				}
				else if (s) {
					*bn += 1;
					if (rex) {
						if (lga) {
							printf("                           %sb (%s, (%s, %u)), cl ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
						}
						else {
							printf("                           %sb (%s, (%s, %u)), cl ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
						}
					}
					else {
						if (lga) {
							printf("                           %sb (%s, (%s, %u)), cl ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
						}
						else {
							printf("                           %sb (%s, (%s, %u)), cl ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
						}
					}
				}
				else {
					*bn += 1;
					if (rex) {
						if (lga) {
							printf("                           %sb (%s, (%s)), cl ", mn, x86_64_r32(b), x86_64_r32(i));
						}
						else {
							printf("                           %sb (%s, (%s)), cl ", mn, x86_64_r64(b), x86_64_r64(i));
						}
					}
					else {
						if (lga) {
							printf("                           %sb (%s, (%s)), cl ", mn, x86_64_r32(b), x86_64_r32(i));
						}
						else {
							printf("                           %sb (%s, (%s)), cl ", mn, x86_64_r64(b), x86_64_r64(i));
						}
					}
				}
			}
			else if ((mrd & 7) == 5) {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (d) {
					if (rex) {
						if (lga) {
							printf("               %sb (eip, %u), cl ", mn, d);
						}
						else {
							printf("               %sb (rip, %u), cl ", mn, d);
						}
					}
					else {
						if (lga) {
							printf("               %sb (eip, %u), cl ", mn, d);
						}
						else {
							printf("               %sb (rip, %u), cl ", mn, d);
						}
					}
				}
				else {
					if (rex) {
						if (lga) {
							printf("               %sb (eip), cl ", mn);
						}
						else {
							printf("               %sb (rip), cl ", mn);
						}
					}
					else {
						if (lga) {
							printf("               %sb (eip), cl ", mn);
						}
						else {
							printf("               %sb (rip), cl ", mn);
						}
					}
				}
			}
			else {
				*bn += 1;
				if (rex) {
					if (lga) {
						printf("                              %sb (%s), cl ", mn, x86_64_r32(mrd));
					}
					else {
						printf("                              %sb (%s), cl ", mn, x86_64_r64(mrd));
					}
				}
				else {
					if (lga) {
						printf("                              %sb (%s), cl ", mn, x86_64_r32(mrd));
					}
					else {
						printf("                              %sb (%s), cl ", mn, x86_64_r64(mrd));
					}
				}
			}
		}
		else if (mod == 1) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (rex) {
						if (lga) {
							printf("                        %sb (%s, %u), cl ", mn, x86_64_r32(b), d);
						}
						else {
							printf("                        %sb (%s, %u), cl ", mn, x86_64_r64(b), d);
						}
					}
					else {
						if (lga) {
							printf("                        %sb (%s, %u), cl ", mn, x86_64_r32(b), d);
						}
						else {
							printf("                        %sb (%s, %u), cl ", mn, x86_64_r64(b), d);
						}
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (rex) {
						if (lga) {
							printf("                        %sb (%s, (%s, %u), %u), cl ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
						}
						else {
							printf("                        %sb (%s, (%s, %u), %u), cl ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
						}
					}
					else {
						if (lga) {
							printf("                        %sb (%s, (%s, %u), %u), cl ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
						}
						else {
							printf("                        %sb (%s, (%s, %u), %u), cl ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
						}
					}
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (rex) {
						if (lga) {
							printf("                        %sb (%s, (%s), %u), cl ", mn, x86_64_r32(b), x86_64_r32(i), d);
						}
						else {
							printf("                        %sb (%s, (%s), %u), cl ", mn, x86_64_r64(b), x86_64_r64(i), d);
						}
					}
					else {
						if (lga) {
							printf("                        %sb (%s, (%s), %u), cl ", mn, x86_64_r32(b), x86_64_r32(i), d);
						}
						else {
							printf("                        %sb (%s, (%s), %u), cl ", mn, x86_64_r64(b), x86_64_r64(i), d);
						}
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (rex) {
					if (lga) {
						printf("                        %sb (%s, %u), cl ", mn, x86_64_r32(mrd), d);
					}
					else {
						printf("                        %sb (%s, %u), cl ", mn, x86_64_r64(mrd), d);
					}
				}
				else {
					if (lga) {
						printf("                        %sb (%s, %u), cl ", mn, x86_64_r32(mrd), d);
					}
					else {
						printf("                        %sb (%s, %u), cl ", mn, x86_64_r64(mrd), d);
					}
				}
			}
		}
		else if (mod == 2) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (rex) {
						if (lga) {
							printf("               %sb (%s, %u), cl ", mn, x86_64_r32(b), d);
						}
						else {
							printf("               %sb (%s, %u), cl ", mn, x86_64_r64(b), d);
						}
					}
					else {
						if (lga) {
							printf("               %sb (%s, %u), cl ", mn, x86_64_r32(b), d);
						}
						else {
							printf("               %sb (%s, %u), cl ", mn, x86_64_r64(b), d);
						}
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (rex) {
						if (lga) {
							printf("               %sb (%s, (%s, %u), %u), cl ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
						}
						else {
							printf("               %sb (%s, (%s, %u), %u), cl ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
						}
					}
					else {
						if (lga) {
							printf("               %sb (%s, (%s, %u), %u), cl ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
						}
						else {
							printf("               %sb (%s, (%s, %u), %u), cl ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
						}
					}
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (rex) {
						if (lga) {
							printf("               %sb (%s, (%s), %u), cl ", mn, x86_64_r32(b), x86_64_r32(i), d);
						}
						else {
							printf("               %sb (%s, (%s), %u), cl ", mn, x86_64_r64(b), x86_64_r64(i), d);
						}
					}
					else {
						if (lga) {
							printf("               %sb (%s, (%s), %u), cl ", mn, x86_64_r32(b), x86_64_r32(i), d);
						}
						else {
							printf("               %sb (%s, (%s), %u), cl ", mn, x86_64_r64(b), x86_64_r64(i), d);
						}
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (rex) {
					if (lga) {
						printf("               %sb (%s, %u), cl ", mn, x86_64_r32(mrd), d);
					}
					else {
						printf("               %sb (%s, %u), cl ", mn, x86_64_r64(mrd), d);
					}
				}
				else {
					if (lga) {
						printf("               %sb (%s, %u), cl ", mn, x86_64_r32(mrd), d);
					}
					else {
						printf("               %sb (%s, %u), cl ", mn, x86_64_r64(mrd), d);
					}
				}
			}
		}
		else if (mod == 3) {
			*bn += 1;
			if (rex) {
				printf("                              %sb %s, cl ", mn, x86_64_r8x(mrd));
			}
			else {
				printf("                              %sb %s, cl ", mn, x86_64_r8(mrd));
			}
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_shft_reg(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op0 && ((bin[*bn + 1] >> 3) & 7) == op1) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		
		if (mod == 0) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4 && (b & 7) == 5) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lgo) {
						printf("               %sw (%u), cl ", mn, d);
					}
					else if (!rx3) {
						printf("               %sd (%u), cl ", mn, d);
					}
					else {
						printf("               %sq (%u), cl ", mn, d);
					}
				}
				else if (i == 4) {
					*bn += 1;
					if (lgo) {
						if (lga) {
							printf("                           %sw (%s), cl ", mn, x86_64_r32(b));
						}
						else {
							printf("                           %sw (%s), cl ", mn, x86_64_r64(b));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                           %sd (%s), cl ", mn, x86_64_r32(b));
						}
						else {
							printf("                           %sd (%s), cl ", mn, x86_64_r64(b));
						}
					}
					else {
						if (lga) {
							printf("                           %sq (%s), cl ", mn, x86_64_r32(b));
						}
						else {
							printf("                           %sq (%s), cl ", mn, x86_64_r64(b));
						}
					}
				}
				else if (s) {
					*bn += 1;
					if (lgo) {
						if (lga) {
							printf("                           %sw (%s, (%s, %u)), cl ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
						}
						else {
							printf("                           %sw (%s, (%s, %u)), cl ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                           %sd (%s, (%s, %u)), cl ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
						}
						else {
							printf("                           %sd (%s, (%s, %u)), cl ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
						}
					}
					else {
						if (lga) {
							printf("                           %sq (%s, (%s, %u)), cl ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
						}
						else {
							printf("                           %sq (%s, (%s, %u)), cl ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
						}
					}
				}
				else {
					*bn += 1;
					if (lgo) {
						if (lga) {
							printf("                           %sw (%s, (%s)), cl ", mn, x86_64_r32(b), x86_64_r32(i));
						}
						else {
							printf("                           %sw (%s, (%s)), cl ", mn, x86_64_r64(b), x86_64_r64(i));
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                           %sd (%s, (%s)), cl ", mn, x86_64_r32(b), x86_64_r32(i));
						}
						else {
							printf("                           %sd (%s, (%s)), cl ", mn, x86_64_r64(b), x86_64_r64(i));
						}
					}
					else {
						if (lga) {
							printf("                           %sq (%s, (%s)), cl ", mn, x86_64_r32(b), x86_64_r32(i));
						}
						else {
							printf("                           %sq (%s, (%s)), cl ", mn, x86_64_r64(b), x86_64_r64(i));
						}
					}
				}
			}
			else if ((mrd & 7) == 5) {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (d) {
					if (lgo) {
						if (lga) {
							printf("               %sw (eip, %u), cl ", mn, d);
						}
						else {
							printf("               %sw (rip, %u), cl ", mn, d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %sd (eip, %u), cl ", mn, d);
						}
						else {
							printf("               %sd (rip, %u), cl ", mn, d);
						}
					}
					else {
						if (lga) {
							printf("               %sq (eip, %u), cl ", mn, d);
						}
						else {
							printf("               %sq (rip, %u), cl ", mn, d);
						}
					}
				}
				else {
					if (lgo) {
						if (lga) {
							printf("               %sw (eip), cl ", mn);
						}
						else {
							printf("               %sw (rip), cl ", mn);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %sd (eip), cl ", mn);
						}
						else {
							printf("               %sd (rip), cl ", mn);
						}
					}
					else {
						if (lga) {
							printf("               %sq (eip), cl ", mn);
						}
						else {
							printf("               %sq (rip), cl ", mn);
						}
					}
				}
			}
			else {
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                              %sw (%s), cl ", mn, x86_64_r32(mrd));
					}
					else {
						printf("                              %sw (%s), cl ", mn, x86_64_r64(mrd));
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                              %sd (%s), cl ", mn, x86_64_r32(mrd));
					}
					else {
						printf("                              %sd (%s), cl ", mn, x86_64_r64(mrd));
					}
				}
				else {
					if (lga) {
						printf("                              %sq (%s), cl ", mn, x86_64_r32(mrd));
					}
					else {
						printf("                              %sq (%s), cl ", mn, x86_64_r64(mrd));
					}
				}
			}
		}
		else if (mod == 1) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (lgo) {
						if (lga) {
							printf("                        %sw (%s, %u), cl ", mn, x86_64_r32(b), d);
						}
						else {
							printf("                        %sw (%s, %u), cl ", mn, x86_64_r64(b), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %sd (%s, %u), cl ", mn, x86_64_r32(b), d);
						}
						else {
							printf("                        %sd (%s, %u), cl ", mn, x86_64_r64(b), d);
						}
					}
					else {
						if (lga) {
							printf("                        %sq (%s, %u), cl ", mn, x86_64_r32(b), d);
						}
						else {
							printf("                        %sq (%s, %u), cl ", mn, x86_64_r64(b), d);
						}
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (lgo) {
						if (lga) {
							printf("                        %sw (%s, (%s, %u), %u), cl ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
						}
						else {
							printf("                        %sw (%s, (%s, %u), %u), cl ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %sd (%s, (%s, %u), %u), cl ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
						}
						else {
							printf("                        %sd (%s, (%s, %u), %u), cl ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
						}
					}
					else {
						if (lga) {
							printf("                        %sq (%s, (%s, %u), %u), cl ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
						}
						else {
							printf("                        %sq (%s, (%s, %u), %u), cl ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
						}
					}
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (lgo) {
						if (lga) {
							printf("                        %sw (%s, (%s), %u), cl ", mn, x86_64_r32(b), x86_64_r32(i), d);
						}
						else {
							printf("                        %sw (%s, (%s), %u), cl ", mn, x86_64_r64(b), x86_64_r64(i), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("                        %sd (%s, (%s), %u), cl ", mn, x86_64_r32(b), x86_64_r32(i), d);
						}
						else {
							printf("                        %sd (%s, (%s), %u), cl ", mn, x86_64_r64(b), x86_64_r64(i), d);
						}
					}
					else {
						if (lga) {
							printf("                        %sq (%s, (%s), %u), cl ", mn, x86_64_r32(b), x86_64_r32(i), d);
						}
						else {
							printf("                        %sq (%s, (%s), %u), cl ", mn, x86_64_r64(b), x86_64_r64(i), d);
						}
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lgo) {
					if (lga) {
						printf("                        %sw (%s, %u), cl ", mn, x86_64_r32(mrd), d);
					}
					else {
						printf("                        %sw (%s, %u), cl ", mn, x86_64_r64(mrd), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("                        %sd (%s, %u), cl ", mn, x86_64_r32(mrd), d);
					}
					else {
						printf("                        %sd (%s, %u), cl ", mn, x86_64_r64(mrd), d);
					}
				}
				else {
					if (lga) {
						printf("                        %sq (%s, %u), cl ", mn, x86_64_r32(mrd), d);
					}
					else {
						printf("                        %sq (%s, %u), cl ", mn, x86_64_r64(mrd), d);
					}
				}
			}
		}
		else if (mod == 2) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7) + (8 * rx0);
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lgo) {
						if (lga) {
							printf("               %sw (%s, %u), cl ", mn, x86_64_r32(b), d);
						}
						else {
							printf("               %sw (%s, %u), cl ", mn, x86_64_r64(b), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %sd (%s, %u), cl ", mn, x86_64_r32(b), d);
						}
						else {
							printf("               %sd (%s, %u), cl ", mn, x86_64_r64(b), d);
						}
					}
					else {
						if (lga) {
							printf("               %sq (%s, %u), cl ", mn, x86_64_r32(b), d);
						}
						else {
							printf("               %sq (%s, %u), cl ", mn, x86_64_r64(b), d);
						}
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lgo) {
						if (lga) {
							printf("               %sw (%s, (%s, %u), %u), cl ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
						}
						else {
							printf("               %sw (%s, (%s, %u), %u), cl ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %sd (%s, (%s, %u), %u), cl ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
						}
						else {
							printf("               %sd (%s, (%s, %u), %u), cl ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
						}
					}
					else {
						if (lga) {
							printf("               %sq (%s, (%s, %u), %u), cl ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
						}
						else {
							printf("               %sq (%s, (%s, %u), %u), cl ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
						}
					}
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lgo) {
						if (lga) {
							printf("               %sw (%s, (%s), %u), cl ", mn, x86_64_r32(b), x86_64_r32(i), d);
						}
						else {
							printf("               %sw (%s, (%s), %u), cl ", mn, x86_64_r64(b), x86_64_r64(i), d);
						}
					}
					else if (!rx3) {
						if (lga) {
							printf("               %sd (%s, (%s), %u), cl ", mn, x86_64_r32(b), x86_64_r32(i), d);
						}
						else {
							printf("               %sd (%s, (%s), %u), cl ", mn, x86_64_r64(b), x86_64_r64(i), d);
						}
					}
					else {
						if (lga) {
							printf("               %sq (%s, (%s), %u), cl ", mn, x86_64_r32(b), x86_64_r32(i), d);
						}
						else {
							printf("               %sq (%s, (%s), %u), cl ", mn, x86_64_r64(b), x86_64_r64(i), d);
						}
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					if (lga) {
						printf("               %sw (%s, %u), cl ", mn, x86_64_r32(mrd), d);
					}
					else {
						printf("               %sw (%s, %u), cl ", mn, x86_64_r64(mrd), d);
					}
				}
				else if (!rx3) {
					if (lga) {
						printf("               %sd (%s, %u), cl ", mn, x86_64_r32(mrd), d);
					}
					else {
						printf("               %sd (%s, %u), cl ", mn, x86_64_r64(mrd), d);
					}
				}
				else {
					if (lga) {
						printf("               %sq (%s, %u), cl ", mn, x86_64_r32(mrd), d);
					}
					else {
						printf("               %sq (%s, %u), cl ", mn, x86_64_r64(mrd), d);
					}
				}
			}
		}
		else if (mod == 3) {
			*bn += 1;
			if (lgo) {
				printf("                              %sw %s, cl ", mn, x86_64_r16(mrd));
			}
			else if (!rx3) {
				printf("                              %sd %s, cl ", mn, x86_64_r32(mrd));
			}
			else {
				printf("                              %sq %s, cl ", mn, x86_64_r64(mrd));
			}
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_byt(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		
		printf("                                 %s", mn);
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_sys(uint8_t* bin, uint64_t* bn) {
	if (bin[*bn] == 15 && bin[*bn + 1] == 5) {
		printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
		*bn += 2;
		
		printf("                              syscall");
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
	else {
		printf("   ");
	}
	
	uint8_t eo = 1;
	
	if (eo) {
		eo = x86_64_dec_r80(bin, bn, addr, 0, "add", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg0(bin, bn, addr, 1, "add", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r81(bin, bn, addr, 2, "add", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg1(bin, bn, addr, 3, "add", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_ral(bin, bn, addr, 4, "add", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rax(bin, bn, addr, 5, "add", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r80(bin, bn, addr, 8, "or", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg0(bin, bn, addr, 9, "or", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r81(bin, bn, addr, 10, "or", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg1(bin, bn, addr, 11, "or", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_ral(bin, bn, addr, 12, "or", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rax(bin, bn, addr, 13, "or", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r80(bin, bn, addr, 16, "adc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg0(bin, bn, addr, 17, "adc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r81(bin, bn, addr, 18, "adc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg1(bin, bn, addr, 19, "adc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_ral(bin, bn, addr, 20, "adc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rax(bin, bn, addr, 21, "adc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r80(bin, bn, addr, 24, "sbb", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg0(bin, bn, addr, 25, "sbb", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r81(bin, bn, addr, 26, "sbb", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg1(bin, bn, addr, 27, "sbb", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_ral(bin, bn, addr, 28, "sbb", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rax(bin, bn, addr, 29, "sbb", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r80(bin, bn, addr, 32, "and", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg0(bin, bn, addr, 33, "and", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r81(bin, bn, addr, 34, "and", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg1(bin, bn, addr, 35, "and", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_ral(bin, bn, addr, 36, "and", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rax(bin, bn, addr, 37, "and", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r80(bin, bn, addr, 40, "sub", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg0(bin, bn, addr, 41, "sub", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r81(bin, bn, addr, 42, "sub", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg1(bin, bn, addr, 43, "sub", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_ral(bin, bn, addr, 44, "sub", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rax(bin, bn, addr, 45, "sub", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r80(bin, bn, addr, 48, "xor", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg0(bin, bn, addr, 49, "xor", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r81(bin, bn, addr, 50, "xor", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg1(bin, bn, addr, 51, "xor", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_ral(bin, bn, addr, 52, "xor", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rax(bin, bn, addr, 53, "xor", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r80(bin, bn, addr, 56, "cmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg0(bin, bn, addr, 57, "cmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r81(bin, bn, addr, 58, "cmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg1(bin, bn, addr, 59, "cmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_ral(bin, bn, addr, 60, "cmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rax(bin, bn, addr, 61, "cmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_stck(bin, bn, addr, 80, "push", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_stck(bin, bn, addr, 88, "pop", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_op_imm(bin, bn, addr, 104, "push", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 112, "jo", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 113, "jno", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 114, "jc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 115, "jnc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 116, "je", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 117, "jne", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 118, "jna", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 119, "ja", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 120, "js", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 121, "jns", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 122, "jpe", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 123, "jpo", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 124, "jl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 125, "jge", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 126, "jle", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 127, "jg", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 128, 0, "add", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 128, 1, "or", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 128, 2, "adc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 128, 3, "sbb", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 128, 4, "and", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 128, 5, "sub", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 128, 6, "xor", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 128, 7, "cmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_imm(bin, bn, addr, 129, 0, "add", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_imm(bin, bn, addr, 129, 1, "or", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_imm(bin, bn, addr, 129, 2, "adc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_imm(bin, bn, addr, 129, 3, "sbb", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_imm(bin, bn, addr, 129, 4, "and", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_imm(bin, bn, addr, 129, 5, "sub", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_imm(bin, bn, addr, 129, 6, "xor", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_imm(bin, bn, addr, 129, 7, "cmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 131, 0, "add", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 131, 1, "or", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 131, 2, "adc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 131, 3, "sbb", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 131, 4, "and", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 131, 5, "sub", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 131, 6, "xor", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 131, 7, "cmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r81(bin, bn, addr, 134, "xchg", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg1(bin, bn, addr, 135, "xchg", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r80(bin, bn, addr, 136, "mov", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg0(bin, bn, addr, 137, "mov", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_r81(bin, bn, addr, 138, "mov", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg1(bin, bn, addr, 139, "mov", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_rg1(bin, bn, addr, 141, "lea", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_blnk(bin, bn, addr, 143, 0, "pop", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_stck(bin, bn, addr, 144, "xchg", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 156, "pushf", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 157, "popf", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 158, "sahf ah", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 159, "lahf ah", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_mvp(bin, bn, addr, 176, "mov", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 192, 0, "rol", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 192, 1, "ror", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 192, 2, "rcl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 192, 3, "rcr", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 192, 4, "shl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 192, 5, "shr", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 192, 6, "sal", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 192, 7, "sar", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 193, 0, "rol", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 193, 1, "ror", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 193, 2, "rcl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 193, 3, "rcr", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 193, 4, "shl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 193, 5, "shr", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 193, 6, "sal", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k81(bin, bn, addr, 193, 7, "sar", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 195, "ret", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_k80(bin, bn, addr, 198, 0, "mov", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_imm(bin, bn, addr, 199, 0, "mov", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 206, "into", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 207, "iret", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k80(bin, bn, addr, 208, 0, "rol", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k80(bin, bn, addr, 208, 1, "ror", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k80(bin, bn, addr, 208, 2, "rcl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k80(bin, bn, addr, 208, 3, "rcr", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k80(bin, bn, addr, 208, 4, "shl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k80(bin, bn, addr, 208, 5, "shr", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k80(bin, bn, addr, 208, 6, "sal", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k80(bin, bn, addr, 208, 7, "sar", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k81(bin, bn, addr, 209, 0, "rol", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k81(bin, bn, addr, 209, 1, "ror", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k81(bin, bn, addr, 209, 2, "rcl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k81(bin, bn, addr, 209, 3, "rcr", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k81(bin, bn, addr, 209, 4, "shl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k81(bin, bn, addr, 209, 5, "shr", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k81(bin, bn, addr, 209, 6, "sal", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_k81(bin, bn, addr, 209, 7, "sar", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_r8(bin, bn, addr, 210, 0, "rol", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_r8(bin, bn, addr, 210, 1, "ror", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_r8(bin, bn, addr, 210, 2, "rcl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_r8(bin, bn, addr, 210, 3, "rcr", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_r8(bin, bn, addr, 210, 4, "shl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_r8(bin, bn, addr, 210, 5, "shr", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_r8(bin, bn, addr, 210, 6, "sal", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_r8(bin, bn, addr, 210, 7, "sar", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_reg(bin, bn, addr, 211, 0, "rol", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_reg(bin, bn, addr, 211, 1, "ror", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_reg(bin, bn, addr, 211, 2, "rcl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_reg(bin, bn, addr, 211, 3, "rcr", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_reg(bin, bn, addr, 211, 4, "shl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_reg(bin, bn, addr, 211, 5, "shr", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_reg(bin, bn, addr, 211, 6, "sal", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft_reg(bin, bn, addr, 211, 7, "sar", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_jmp(bin, bn, addr, 232, "call", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_jmp(bin, bn, addr, 233, "jmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_cond(bin, bn, addr, 235, "jmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 240, "lock", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 241, "icebp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 242, "repne", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 243, "repe", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 244, "hlt", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 245, "cmc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_alnk(bin, bn, addr, 246, 2, "not", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_alnk(bin, bn, addr, 246, 3, "neg", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_mlnk(bin, bn, addr, 246, 4, "mul", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_mlnk(bin, bn, addr, 246, 5, "imul", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_mlnk(bin, bn, addr, 246, 6, "div", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_mlnk(bin, bn, addr, 246, 7, "idiv", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 248, "clc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 249, "stc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 250, "cli", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 251, "sti", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 252, "cld", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 253, "std", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_alnk(bin, bn, addr, 254, 0, "inc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_alnk(bin, bn, addr, 254, 1, "dec", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_blnk(bin, bn, addr, 255, 2, "call", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_blnk(bin, bn, addr, 255, 4, "jmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_blnk(bin, bn, addr, 255, 6, "push", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_sys(bin, bn);
	}
	if (eo) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
	}
}
