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

uint8_t x86_64_dec_reg(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
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
					if (d) {
						if (rex && lga) {
							printf("               %s (ebp, %u), %s ", mn, d, x86_64_r8x(mrs));
						}
						else if (!rex && lga) {
							printf("               %s (ebp, %u), %s ", mn, d, x86_64_r8(mrs));
						}
						else if (rex) {
							printf("               %s (rbp, %u), %s ", mn, d, x86_64_r8x(mrs));
						}
						else {
							printf("               %s (rbp, %u), %s ", mn, d, x86_64_r8(mrs));
						}
					}
					else {
						if (rex && lga) {
							printf("               %s (ebp), %s ", mn, x86_64_r8x(mrs));
						}
						else if (!rex && lga) {
							printf("               %s (ebp), %s ", mn, x86_64_r8(mrs));
						}
						else if (rex) {
							printf("               %s (rbp), %s ", mn, x86_64_r8x(mrs));
						}
						else {
							printf("               %s (rbp), %s ", mn, x86_64_r8(mrs));
						}
					}
				}
				else if (i == 4) {
					*bn += 1;
					if (!rex && !lga) {
						printf("                           %s (%s), %s ", mn, x86_64_r64(b), x86_64_r8(mrs));
					}
					else if (!rex && lga) {
						printf("                           %s (%s), %s ", mn, x86_64_r32(b), x86_64_r8(mrs));
					}
					else if (rex && !lga) {
						printf("                           %s (%s), %s ", mn, x86_64_r64(b), x86_64_r8x(mrs));
					}
					else if (rex && lga) {
						printf("                           %s (%s), %s ", mn, x86_64_r32(b), x86_64_r8x(mrs));
					}
				}
				else if (s) {
					*bn += 1;
					if (!rex && !lga) {
						printf("                           %s (%s, (%s, %u)), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), x86_64_r8(mrs));
					}
					else if (!rex && lga) {
						printf("                           %s (%s, (%s, %u)), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), x86_64_r8(mrs));
					}
					else if (rex && !lga) {
						printf("                           %s (%s, (%s, %u)), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), x86_64_r8x(mrs));
					}
					else if (rex && lga) {
						printf("                           %s (%s, (%s, %u)), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), x86_64_r8x(mrs));
					}
				}
				else {
					*bn += 1;
					if (!rex && !lga) {
						printf("                           %s (%s, (%s)), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_r8(mrs));
					}
					else if (!rex && lga) {
						printf("                           %s (%s, (%s)), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_r8(mrs));
					}
					else if (rex && !lga) {
						printf("                           %s (%s, (%s)), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_r8x(mrs));
					}
					else if (rex && lga) {
						printf("                           %s (%s, (%s)), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_r8x(mrs));
					}
				}
			}
			else if ((mrd & 7) == 5) {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (d) {
					if (!rex && !lga) {
						printf("               %s (rip, %u), %s ", mn, d, x86_64_r8(mrs));
					}
					else if (!rex && lga) {
						printf("               %s (eip, %u), %s ", mn, d, x86_64_r8(mrs));
					}
					else if (rex && !lga) {
						printf("               %s (rip, %u), %s ", mn, d, x86_64_r8x(mrs));
					}
					else if (rex && lga) {
						printf("               %s (eip, %u), %s ", mn, d, x86_64_r8x(mrs));
					}
				}
				else {
					if (!rex && !lga) {
						printf("               %s (rip), %s ", mn, x86_64_r8(mrs));
					}
					else if (!rex && lga) {
						printf("               %s (eip), %s ", mn, x86_64_r8(mrs));
					}
					else if (rex && !lga) {
						printf("               %s (rip), %s ", mn, x86_64_r8x(mrs));
					}
					else if (rex && lga) {
						printf("               %s (eip), %s ", mn, x86_64_r8x(mrs));
					}
				}
			}
			else {
				*bn += 1;
				if (!rex && !lga) {
					printf("                              %s (%s), %s ", mn, x86_64_r64(mrd), x86_64_r8(mrs));
				}
				else if (!rex && lga) {
					printf("                              %s (%s), %s ", mn, x86_64_r32(mrd), x86_64_r8(mrs));
				}
				else if (rex && !lga) {
					printf("                              %s (%s), %s ", mn, x86_64_r64(mrd), x86_64_r8x(mrs));
				}
				else if (rex && lga) {
					printf("                              %s (%s), %s ", mn, x86_64_r32(mrd), x86_64_r8x(mrs));
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
					if (!rex && !lga) {
						printf("                        %s (%s, %u), %s ", mn, x86_64_r64(b), d, x86_64_r8(mrs));
					}
					else if (!rex && lga) {
						printf("                        %s (%s, %u), %s ", mn, x86_64_r32(b), d, x86_64_r8(mrs));
					}
					else if (rex && !lga) {
						printf("                        %s (%s, %u), %s ", mn, x86_64_r64(b), d, x86_64_r8x(mrs));
					}
					else if (rex && lga) {
						printf("                        %s (%s, %u), %s ", mn, x86_64_r32(b), d, x86_64_r8x(mrs));
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (!rex && !lga) {
						printf("                        %s (%s, (%s, %u), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, x86_64_r8(mrs));
					}
					else if (!rex && lga) {
						printf("                        %s (%s, (%s, %u), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, x86_64_r8(mrs));
					}
					else if (rex && !lga) {
						printf("                        %s (%s, (%s, %u), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, x86_64_r8x(mrs));
					}
					else if (rex && lga) {
						printf("                        %s (%s, (%s, %u), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, x86_64_r8x(mrs));
					}
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (!rex && !lga) {
						printf("                        %s (%s, (%s), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), d, x86_64_r8(mrs));
					}
					else if (!rex && lga) {
						printf("                        %s (%s, (%s), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), d, x86_64_r8(mrs));
					}
					else if (rex && !lga) {
						printf("                        %s (%s, (%s), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), d, x86_64_r8x(mrs));
					}
					else if (rex && lga) {
						printf("                        %s (%s, (%s), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), d, x86_64_r8x(mrs));
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (!rex && !lga) {
					printf("                        %s (%s, %u), %s ", mn, x86_64_r64(mrd), d, x86_64_r8(mrs));
				}
				else if (!rex && lga) {
					printf("                        %s (%s, %u), %s ", mn, x86_64_r32(mrd), d, x86_64_r8(mrs));
				}
				else if (rex && !lga) {
					printf("                        %s (%s, %u), %s ", mn, x86_64_r64(mrd), d, x86_64_r8x(mrs));
				}
				else if (rex && lga) {
					printf("                        %s (%s, %u), %s ", mn, x86_64_r32(mrd), d, x86_64_r8x(mrs));
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
					if (!rex && !lga) {
						printf("               %s (%s, %u), %s ", mn, x86_64_r64(b), d, x86_64_r8(mrs));
					}
					else if (!rex && lga) {
						printf("               %s (%s, %u), %s ", mn, x86_64_r32(b), d, x86_64_r8(mrs));
					}
					else if (rex && !lga) {
						printf("               %s (%s, %u), %s ", mn, x86_64_r64(b), d, x86_64_r8x(mrs));
					}
					else if (rex && lga) {
						printf("               %s (%s, %u), %s ", mn, x86_64_r32(b), d, x86_64_r8x(mrs));
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (!rex && !lga) {
						printf("               %s (%s, (%s, %u), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, x86_64_r8(mrs));
					}
					else if (!rex && lga) {
						printf("               %s (%s, (%s, %u), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, x86_64_r8(mrs));
					}
					else if (rex && !lga) {
						printf("               %s (%s, (%s, %u), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, x86_64_r8x(mrs));
					}
					else if (rex && lga) {
						printf("               %s (%s, (%s, %u), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, x86_64_r8x(mrs));
					}
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (!rex && !lga) {
						printf("               %s (%s, (%s), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), d, x86_64_r8(mrs));
					}
					else if (!rex && lga) {
						printf("               %s (%s, (%s), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), d, x86_64_r8(mrs));
					}
					else if (rex && !lga) {
						printf("               %s (%s, (%s), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), d, x86_64_r8x(mrs));
					}
					else if (rex && lga) {
						printf("               %s (%s, (%s), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), d, x86_64_r8x(mrs));
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (!rex && !lga) {
					printf("               %s (%s, %u), %s ", mn, x86_64_r64(mrd), d, x86_64_r8(mrs));
				}
				else if (!rex && lga) {
					printf("               %s (%s, %u), %s ", mn, x86_64_r32(mrd), d, x86_64_r8(mrs));
				}
				else if (rex && !lga) {
					printf("               %s (%s, %u), %s ", mn, x86_64_r64(mrd), d, x86_64_r8x(mrs));
				}
				else if (rex && lga) {
					printf("               %s (%s, %u), %s ", mn, x86_64_r32(mrd), d, x86_64_r8x(mrs));
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
	else if (bin[*bn] == op + 1) {
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
					if (d) {
						if (lgo && lga) {
							printf("               %s (ebp, %u), %s ", mn, d, x86_64_r16(mrs));
						}
						else if (!rx3 && lga) {
							printf("               %s (ebp, %u), %s ", mn, d, x86_64_r32(mrs));
						}
						else if (rx3 && lga) {
							printf("               %s (ebp, %u), %s ", mn, d, x86_64_r64(mrs));
						}
						else if (lgo) {
							printf("               %s (rbp, %u), %s ", mn, d, x86_64_r16(mrs));
						}
						else if (!rx3) {
							printf("               %s (rbp, %u), %s ", mn, d, x86_64_r32(mrs));
						}
						else if (rx3) {
							printf("               %s (rbp, %u), %s ", mn, d, x86_64_r64(mrs));
						}
					}
					else {
						if (lgo && lga) {
							printf("               %s (ebp), %s ", mn, x86_64_r16(mrs));
						}
						else if (!rx3 && lga) {
							printf("               %s (ebp), %s ", mn, x86_64_r32(mrs));
						}
						else if (rx3 && lga) {
							printf("               %s (ebp), %s ", mn, x86_64_r64(mrs));
						}
						else if (lgo) {
							printf("               %s (rbp), %s ", mn, x86_64_r16(mrs));
						}
						else if (!rx3) {
							printf("               %s (rbp), %s ", mn, x86_64_r32(mrs));
						}
						else if (rx3) {
							printf("               %s (rbp), %s ", mn, x86_64_r64(mrs));
						}
					}
				}
				else if (i == 4) {
					*bn += 1;
					if (lgo && !lga) {
						printf("                           %s (%s), %s ", mn, x86_64_r64(b), x86_64_r16(mrs));
					}
					else if (lgo && lga) {
						printf("                           %s (%s), %s ", mn, x86_64_r32(b), x86_64_r16(mrs));
					}
					else if (!rx3 && !lga) {
						printf("                           %s (%s), %s ", mn, x86_64_r64(b), x86_64_r32(mrs));
					}
					else if (!rx3 && lga) {
						printf("                           %s (%s), %s ", mn, x86_64_r32(b), x86_64_r32(mrs));
					}
					else if (rx3 && !lga) {
						printf("                           %s (%s), %s ", mn, x86_64_r64(b), x86_64_r64(mrs));
					}
					else if (rx3 && lga) {
						printf("                           %s (%s), %s ", mn, x86_64_r32(b), x86_64_r64(mrs));
					}
				}
				else if (s) {
					*bn += 1;
					if (lgo && !lga) {
						printf("                           %s (%s, (%s, %u)), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), x86_64_r16(mrs));
					}
					else if (lgo && lga) {
						printf("                           %s (%s, (%s, %u)), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), x86_64_r16(mrs));
					}
					else if (!rx3 && !lga) {
						printf("                           %s (%s, (%s, %u)), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), x86_64_r32(mrs));
					}
					else if (!rx3 && lga) {
						printf("                           %s (%s, (%s, %u)), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), x86_64_r32(mrs));
					}
					else if (rx3 && !lga) {
						printf("                           %s (%s, (%s, %u)), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), x86_64_r64(mrs));
					}
					else if (rx3 && lga) {
						printf("                           %s (%s, (%s, %u)), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), x86_64_r64(mrs));
					}
				}
				else {
					*bn += 1;
					if (lgo && !lga) {
						printf("                           %s (%s, (%s)), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_r16(mrs));
					}
					else if (lgo && lga) {
						printf("                           %s (%s, (%s)), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_r16(mrs));
					}
					else if (!rx3 && !lga) {
						printf("                           %s (%s, (%s)), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_r32(mrs));
					}
					else if (!rx3 && lga) {
						printf("                           %s (%s, (%s)), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_r32(mrs));
					}
					else if (rx3 && !lga) {
						printf("                           %s (%s, (%s)), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_r64(mrs));
					}
					else if (rx3 && lga) {
						printf("                           %s (%s, (%s)), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_r64(mrs));
					}
				}
			}
			else if ((mrd & 7) == 5) {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (d) {
					if (lgo && !lga) {
						printf("               %s (rip, %u), %s ", mn, d, x86_64_r16(mrs));
					}
					else if (lgo && lga) {
						printf("               %s (eip, %u), %s ", mn, d, x86_64_r16(mrs));
					}
					else if (!rx3 && !lga) {
						printf("               %s (rip, %u), %s ", mn, d, x86_64_r32(mrs));
					}
					else if (!rx3 && lga) {
						printf("               %s (eip, %u), %s ", mn, d, x86_64_r32(mrs));
					}
					else if (rx3 && !lga) {
						printf("               %s (rip, %u), %s ", mn, d, x86_64_r64(mrs));
					}
					else if (rx3 && lga) {
						printf("               %s (eip, %u), %s ", mn, d, x86_64_r64(mrs));
					}
				}
				else {
					if (lgo && !lga) {
						printf("               %s (rip), %s ", mn, x86_64_r16(mrs));
					}
					else if (lgo && lga) {
						printf("               %s (eip), %s ", mn, x86_64_r16(mrs));
					}
					else if (!rx3 && !lga) {
						printf("               %s (rip), %s ", mn, x86_64_r32(mrs));
					}
					else if (!rx3 && lga) {
						printf("               %s (eip), %s ", mn, x86_64_r32(mrs));
					}
					else if (rx3 && !lga) {
						printf("               %s (rip), %s ", mn, x86_64_r64(mrs));
					}
					else if (rx3 && lga) {
						printf("               %s (eip), %s ", mn, x86_64_r64(mrs));
					}
				}
			}
			else {
				*bn += 1;
				if (lgo && !lga) {
					printf("                              %s (%s), %s ", mn, x86_64_r64(mrd), x86_64_r16(mrs));
				}
				else if (lgo && lga) {
					printf("                              %s (%s), %s ", mn, x86_64_r32(mrd), x86_64_r16(mrs));
				}
				else if (!rx3 && !lga) {
					printf("                              %s (%s), %s ", mn, x86_64_r64(mrd), x86_64_r32(mrs));
				}
				else if (!rx3 && lga) {
					printf("                              %s (%s), %s ", mn, x86_64_r32(mrd), x86_64_r32(mrs));
				}
				else if (rx3 && !lga) {
					printf("                              %s (%s), %s ", mn, x86_64_r64(mrd), x86_64_r64(mrs));
				}
				else if (rx3 && lga) {
					printf("                              %s (%s), %s ", mn, x86_64_r32(mrd), x86_64_r64(mrs));
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
					if (lgo && !lga) {
						printf("                        %s (%s, %u), %s ", mn, x86_64_r64(b), d, x86_64_r16(mrs));
					}
					else if (lgo && lga) {
						printf("                        %s (%s, %u), %s ", mn, x86_64_r32(b), d, x86_64_r16(mrs));
					}
					else if (!rx3 && !lga) {
						printf("                        %s (%s, %u), %s ", mn, x86_64_r64(b), d, x86_64_r32(mrs));
					}
					else if (!rx3 && lga) {
						printf("                        %s (%s, %u), %s ", mn, x86_64_r32(b), d, x86_64_r32(mrs));
					}
					else if (rx3 && !lga) {
						printf("                        %s (%s, %u), %s ", mn, x86_64_r64(b), d, x86_64_r64(mrs));
					}
					else if (rx3 && lga) {
						printf("                        %s (%s, %u), %s ", mn, x86_64_r32(b), d, x86_64_r64(mrs));
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (lgo && !lga) {
						printf("                        %s (%s, (%s, %u), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, x86_64_r16(mrs));
					}
					else if (lgo && lga) {
						printf("                        %s (%s, (%s, %u), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, x86_64_r16(mrs));
					}
					else if (!rx3 && !lga) {
						printf("                        %s (%s, (%s, %u), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, x86_64_r32(mrs));
					}
					else if (!rx3 && lga) {
						printf("                        %s (%s, (%s, %u), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, x86_64_r32(mrs));
					}
					else if (rx3 && !lga) {
						printf("                        %s (%s, (%s, %u), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, x86_64_r64(mrs));
					}
					else if (rx3 && lga) {
						printf("                        %s (%s, (%s, %u), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, x86_64_r64(mrs));
					}
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (lgo && !lga) {
						printf("                        %s (%s, (%s), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), d, x86_64_r16(mrs));
					}
					else if (lgo && lga) {
						printf("                        %s (%s, (%s), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), d, x86_64_r16(mrs));
					}
					else if (!rx3 && !lga) {
						printf("                        %s (%s, (%s), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), d, x86_64_r32(mrs));
					}
					else if (!rx3 && lga) {
						printf("                        %s (%s, (%s), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), d, x86_64_r32(mrs));
					}
					else if (rx3 && !lga) {
						printf("                        %s (%s, (%s), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), d, x86_64_r64(mrs));
					}
					else if (rx3 && lga) {
						printf("                        %s (%s, (%s), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), d, x86_64_r64(mrs));
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lgo && !lga) {
					printf("                        %s (%s, %u), %s ", mn, x86_64_r64(mrd), d, x86_64_r16(mrs));
				}
				else if (lgo && lga) {
					printf("                        %s (%s, %u), %s ", mn, x86_64_r32(mrd), d, x86_64_r16(mrs));
				}
				else if (!rx3 && !lga) {
					printf("                        %s (%s, %u), %s ", mn, x86_64_r64(mrd), d, x86_64_r32(mrs));
				}
				else if (!rx3 && lga) {
					printf("                        %s (%s, %u), %s ", mn, x86_64_r32(mrd), d, x86_64_r32(mrs));
				}
				else if (rx3 && !lga) {
					printf("                        %s (%s, %u), %s ", mn, x86_64_r64(mrd), d, x86_64_r64(mrs));
				}
				else if (rx3 && lga) {
					printf("                        %s (%s, %u), %s ", mn, x86_64_r32(mrd), d, x86_64_r64(mrs));
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
					if (lgo && !lga) {
						printf("               %s (%s, %u), %s ", mn, x86_64_r64(b), d, x86_64_r16(mrs));
					}
					else if (lgo && lga) {
						printf("               %s (%s, %u), %s ", mn, x86_64_r32(b), d, x86_64_r16(mrs));
					}
					else if (!rx3 && !lga) {
						printf("               %s (%s, %u), %s ", mn, x86_64_r64(b), d, x86_64_r32(mrs));
					}
					else if (!rx3 && lga) {
						printf("               %s (%s, %u), %s ", mn, x86_64_r32(b), d, x86_64_r32(mrs));
					}
					else if (rx3 && !lga) {
						printf("               %s (%s, %u), %s ", mn, x86_64_r64(b), d, x86_64_r64(mrs));
					}
					else if (rx3 && lga) {
						printf("               %s (%s, %u), %s ", mn, x86_64_r32(b), d, x86_64_r64(mrs));
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lgo && !lga) {
						printf("               %s (%s, (%s, %u), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, x86_64_r16(mrs));
					}
					else if (lgo && lga) {
						printf("               %s (%s, (%s, %u), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, x86_64_r16(mrs));
					}
					else if (!rx3 && !lga) {
						printf("               %s (%s, (%s, %u), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, x86_64_r32(mrs));
					}
					else if (!rx3 && lga) {
						printf("               %s (%s, (%s, %u), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, x86_64_r32(mrs));
					}
					else if (rx3 && !lga) {
						printf("               %s (%s, (%s, %u), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, x86_64_r64(mrs));
					}
					else if (rx3 && lga) {
						printf("               %s (%s, (%s, %u), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, x86_64_r64(mrs));
					}
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lgo && !lga) {
						printf("               %s (%s, (%s), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), d, x86_64_r16(mrs));
					}
					else if (lgo && lga) {
						printf("               %s (%s, (%s), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), d, x86_64_r16(mrs));
					}
					else if (!rx3 && !lga) {
						printf("               %s (%s, (%s), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), d, x86_64_r32(mrs));
					}
					else if (!rx3 && lga) {
						printf("               %s (%s, (%s), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), d, x86_64_r32(mrs));
					}
					else if (rx3 && !lga) {
						printf("               %s (%s, (%s), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), d, x86_64_r64(mrs));
					}
					else if (rx3 && lga) {
						printf("               %s (%s, (%s), %u), %s ", mn, x86_64_r32(b), x86_64_r32(i), d, x86_64_r64(mrs));
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo && !lga) {
					printf("               %s (%s, %u), %s ", mn, x86_64_r64(mrd), d, x86_64_r16(mrs));
				}
				else if (lgo && lga) {
					printf("               %s (%s, %u), %s ", mn, x86_64_r32(mrd), d, x86_64_r16(mrs));
				}
				else if (!rx3 && !lga) {
					printf("               %s (%s, %u), %s ", mn, x86_64_r64(mrd), d, x86_64_r32(mrs));
				}
				else if (!rx3 && lga) {
					printf("               %s (%s, %u), %s ", mn, x86_64_r32(mrd), d, x86_64_r32(mrs));
				}
				else if (rx3 && !lga) {
					printf("               %s (%s, %u), %s ", mn, x86_64_r64(mrd), d, x86_64_r64(mrs));
				}
				else if (rx3 && lga) {
					printf("               %s (%s, %u), %s ", mn, x86_64_r32(mrd), d, x86_64_r64(mrs));
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
			else if (rx3) {
				printf("                              %s %s, %s ", mn, x86_64_r64(mrd), x86_64_r64(mrs));
			}
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
					if (d) {
						if (rex && lga) {
							printf("               %s %s, (ebp, %u) ", mn, x86_64_r8x(mrs), d);
						}
						else if (!rex && lga) {
							printf("               %s %s, (ebp, %u) ", mn, x86_64_r8(mrs), d);
						}
						else if (rex) {
							printf("               %s %s, (rbp, %u) ", mn, x86_64_r8x(mrs), d);
						}
						else {
							printf("               %s %s, (rbp, %u) ", mn, x86_64_r8(mrs), d);
						}
					}
					else {
						if (rex && lga) {
							printf("               %s %s, (ebp) ", mn, x86_64_r8x(mrs));
						}
						else if (!rex && lga) {
							printf("               %s %s, (ebp) ", mn, x86_64_r8(mrs));
						}
						else if (rex) {
							printf("               %s %s, (rbp) ", mn, x86_64_r8x(mrs));
						}
						else {
							printf("               %s %s, (rbp) ", mn, x86_64_r8(mrs));
						}
					}
				}
				else if (i == 4) {
					*bn += 1;
					if (!rex && !lga) {
						printf("                           %s %s, (%s) ", mn, x86_64_r8(mrs), x86_64_r64(mrs));
					}
					else if (!rex && lga) {
						printf("                           %s %s, (%s) ", mn, x86_64_r8(mrs), x86_64_r32(mrs));
					}
					else if (rex && !lga) {
						printf("                           %s %s, (%s) ", mn, x86_64_r8x(mrs), x86_64_r64(mrs));
					}
					else if (rex && lga) {
						printf("                           %s %s, (%s) ", mn, x86_64_r8x(mrs), x86_64_r32(mrs));
					}
				}
				else if (s) {
					*bn += 1;
					if (!rex && !lga) {
						printf("                           %s %s, (%s, (%s, %u))", mn, x86_64_r8(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
					}
					else if (!rex && lga) {
						printf("                           %s %s, (%s, (%s, %u)) ", mn, x86_64_r8(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
					}
					else if (rex && !lga) {
						printf("                           %s %s, (%s, (%s, %u)) ", mn, x86_64_r8x(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
					}
					else if (rex && lga) {
						printf("                           %s %s, (%s, (%s, %u)) ", mn, x86_64_r8x(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
					}
				}
				else {
					*bn += 1;
					if (!rex && !lga) {
						printf("                           %s %s, (%s, (%s)) ", mn, x86_64_r8(mrs), x86_64_r64(b), x86_64_r64(i));
					}
					else if (!rex && lga) {
						printf("                           %s %s, (%s, (%s)) ", mn, x86_64_r8(mrs), x86_64_r32(b), x86_64_r32(i));
					}
					else if (rex && !lga) {
						printf("                           %s %s, (%s, (%s)) ", mn, x86_64_r8x(mrs), x86_64_r64(b), x86_64_r64(i));
					}
					else if (rex && lga) {
						printf("                           %s %s, (%s, (%s)) ", mn, x86_64_r8x(mrs), x86_64_r32(b), x86_64_r32(i));
					}
				}
			}
			else if ((mrd & 7) == 5) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (d) {
					if (!rex && !lga) {
						printf("                  %s %s, (rip, %u) ", mn, x86_64_r8(mrs), d);
					}
					else if (!rex && lga) {
						printf("                  %s %s, (eip, %u) ", mn, x86_64_r8(mrs), d);
					}
					else if (rex && !lga) {
						printf("                  %s %s, (rip, %u) ", mn, x86_64_r8x(mrs), d);
					}
					else if (rex && lga) {
						printf("                  %s %s, (eip, %u) ", mn, x86_64_r8x(mrs), d);
					}
				}
				else {
					if (!rex && !lga) {
						printf("                  %s %s, (rip) ", mn, x86_64_r8(mrs));
					}
					else if (!rex && lga) {
						printf("                  %s %s, (eip) ", mn, x86_64_r8(mrs));
					}
					else if (rex && !lga) {
						printf("                  %s %s, (rip) ", mn, x86_64_r8x(mrs));
					}
					else if (rex && lga) {
						printf("                  %s %s, (eip) ", mn, x86_64_r8x(mrs));
					}
				}
			}
			else {
				*bn += 1;
				if (!rex && !lga) {
					printf("                              %s %s, (%s) ", mn, x86_64_r8(mrd), x86_64_r64(mrs));
				}
				else if (!rex && lga) {
					printf("                              %s %s, (%s) ", mn, x86_64_r8(mrd), x86_64_r32(mrs));
				}
				else if (rex && !lga) {
					printf("                              %s %s, (%s) ", mn, x86_64_r8x(mrd), x86_64_r64(mrs));
				}
				else if (rex && lga) {
					printf("                              %s %s, (%s) ", mn, x86_64_r8x(mrd), x86_64_r32(mrs));
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
					if (!rex && !lga) {
						printf("                        %s %s, (%s, %u) ", mn, x86_64_r8(mrs), x86_64_r64(b), d);
					}
					else if (!rex && lga) {
						printf("                        %s %s, (%s, %u) ", mn, x86_64_r8(mrs), x86_64_r32(b), d);
					}
					else if (rex && !lga) {
						printf("                        %s %s, (%s, %u) ", mn, x86_64_r8x(mrs), x86_64_r64(b), d);
					}
					else if (rex && lga) {
						printf("                        %s %s, (%s, %u) ", mn, x86_64_r8x(mrs), x86_64_r32(b), d);
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (!rex && !lga) {
						printf("                        %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r8(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
					else if (!rex && lga) {
						printf("                        %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r8(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
					else if (rex && !lga) {
						printf("                        %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r8x(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
					else if (rex && lga) {
						printf("                        %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r8x(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (!rex && !lga) {
						printf("                        %s %s, (%s, (%s), %u) ", mn, x86_64_r8(mrs), x86_64_r64(b), x86_64_r64(i), d);
					}
					else if (!rex && lga) {
						printf("                        %s %s, (%s, (%s), %u) ", mn, x86_64_r8(mrs), x86_64_r32(b), x86_64_r32(i), d);
					}
					else if (rex && !lga) {
						printf("                        %s %s, (%s, (%s), %u) ", mn, x86_64_r8x(mrs), x86_64_r64(b), x86_64_r64(i), d);
					}
					else if (rex && lga) {
						printf("                        %s %s, (%s, (%s), %u) ", mn, x86_64_r8x(mrs), x86_64_r32(b), x86_64_r32(i), d);
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (!rex && !lga) {
					printf("                        %s %s, (%s, %u) ", mn, x86_64_r8(mrs), x86_64_r64(mrd), d);
				}
				else if (!rex && lga) {
					printf("                        %s %s, (%s, %u) ", mn, x86_64_r8(mrs), x86_64_r32(mrd), d);
				}
				else if (rex && !lga) {
					printf("                        %s %s, (%s, %u) ", mn, x86_64_r8x(mrs), x86_64_r64(mrd), d);
				}
				else if (rex && lga) {
					printf("                        %s %s, (%s, %u) ", mn, x86_64_r8x(mrs), x86_64_r32(mrd), d);
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
					if (!rex && !lga) {
						printf("               %s %s, (%s, %u) ", mn, x86_64_r8(mrs), x86_64_r64(b), d);
					}
					else if (!rex && lga) {
						printf("               %s %s, (%s, %u) ", mn, x86_64_r8(mrs), x86_64_r32(b), d);
					}
					else if (rex && !lga) {
						printf("               %s %s, (%s, %u) ", mn, x86_64_r8x(mrs), x86_64_r64(b), d);
					}
					else if (rex && lga) {
						printf("               %s %s, (%s, %u) ", mn, x86_64_r8x(mrs), x86_64_r32(b), d);
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (!rex && !lga) {
						printf("               %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r8(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
					else if (!rex && lga) {
						printf("               %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r8(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
					else if (rex && !lga) {
						printf("               %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r8x(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
					else if (rex && lga) {
						printf("               %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r8x(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (!rex && !lga) {
						printf("               %s %s, (%s, (%s), %u) ", mn, x86_64_r8(mrs), x86_64_r64(b), x86_64_r64(i), d);
					}
					else if (!rex && lga) {
						printf("               %s %s, (%s, (%s), %u) ", mn, x86_64_r8(mrs), x86_64_r32(b), x86_64_r32(i), d);
					}
					else if (rex && !lga) {
						printf("               %s %s, (%s, (%s), %u) ", mn, x86_64_r8x(mrs), x86_64_r64(b), x86_64_r64(i), d);
					}
					else if (rex && lga) {
						printf("               %s %s, (%s, (%s), %u) ", mn, x86_64_r8x(mrs), x86_64_r32(b), x86_64_r32(i), d);
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (!rex && !lga) {
					printf("               %s %s, (%s, %u) ", mn, x86_64_r8(mrs), x86_64_r64(mrd), d);
				}
				else if (!rex && lga) {
					printf("               %s %s, (%s, %u) ", mn, x86_64_r8(mrs), x86_64_r32(mrd), d);
				}
				else if (rex && !lga) {
					printf("               %s %s, (%s, %u) ", mn, x86_64_r8x(mrs), x86_64_r64(mrd), d);
				}
				else if (rex && lga) {
					printf("               %s %s, (%s, %u) ", mn, x86_64_r8x(mrs), x86_64_r32(mrd), d);
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
				uint8_t i = ((bin[*bn] >> 3) & 7) + (8 * rx1);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4 && (b & 7) == 5) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d) {
						if (lgo && lga) {
							printf("               %s %s, (ebp, %u) ", mn, x86_64_r16(mrs), d);
						}
						else if (!rx3 && lga) {
							printf("               %s %s, (ebp, %u) ", mn, x86_64_r32(mrs), d);
						}
						else if (rx3 && lga) {
							printf("               %s %s, (ebp, %u) ", mn, x86_64_r64(mrs), d);
						}
						else if (lgo) {
							printf("               %s %s, (rbp, %u) ", mn, x86_64_r16(mrs), d);
						}
						else if (!rx3) {
							printf("               %s %s, (rbp, %u) ", mn, x86_64_r32(mrs), d);
						}
						else if (rx3) {
							printf("               %s %s, (rbp, %u) ", mn, x86_64_r64(mrs), d);
						}
					}
					else {
						if (lgo && lga) {
							printf("               %s %s, (ebp) ", mn, x86_64_r16(mrs));
						}
						else if (!rx3 && lga) {
							printf("               %s %s, (ebp) ", mn, x86_64_r32(mrs));
						}
						else if (rx3 && lga) {
							printf("               %s %s, (ebp) ", mn, x86_64_r64(mrs));
						}
						else if (lgo) {
							printf("               %s %s, (rbp) ", mn, x86_64_r16(mrs));
						}
						else if (!rx3) {
							printf("               %s %s, (rbp) ", mn, x86_64_r32(mrs));
						}
						else if (rx3) {
							printf("               %s %s, (rbp) ", mn, x86_64_r64(mrs));
						}
					}
				}
				else if (i == 4) {
					*bn += 1;
					if (lgo && !lga) {
						printf("                           %s %s, (%s) ", mn, x86_64_r16(mrs), x86_64_r64(b));
					}
					else if (lgo && lga) {
						printf("                           %s %s, (%s) ", mn, x86_64_r16(mrs), x86_64_r32(b));
					}
					else if (!rx3 && !lga) {
						printf("                           %s %s, (%s) ", mn, x86_64_r32(mrs), x86_64_r64(b));
					}
					else if (!rx3 && lga) {
						printf("                           %s %s, (%s) ", mn, x86_64_r32(mrs), x86_64_r32(b));
					}
					else if (rx3 && !lga) {
						printf("                           %s %s, (%s) ", mn, x86_64_r64(mrs), x86_64_r64(b));
					}
					else if (rx3 && lga) {
						printf("                           %s %s, (%s) ", mn, x86_64_r64(mrs), x86_64_r32(b));
					}
				}
				else if (s) {
					*bn += 1;
					if (lgo && !lga) {
						printf("                           %s %s, (%s, (%s, %u)) ", mn, x86_64_r16(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
					}
					else if (lgo && lga) {
						printf("                           %s %s, (%s, (%s, %u)) ", mn, x86_64_r16(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
					}
					else if (!rx3 && !lga) {
						printf("                           %s %s, (%s, (%s, %u)) ", mn, x86_64_r32(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
					}
					else if (!rx3 && lga) {
						printf("                           %s %s, (%s, (%s, %u)) ", mn, x86_64_r32(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
					}
					else if (rx3 && !lga) {
						printf("                           %s %s, (%s, (%s, %u)) ", mn, x86_64_r64(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s));
					}
					else if (rx3 && lga) {
						printf("                           %s %s, (%s, (%s, %u)) ", mn, x86_64_r64(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s));
					}
				}
				else {
					*bn += 1;
					if (lgo && !lga) {
						printf("                           %s %s, (%s, (%s)) ", mn, x86_64_r16(mrs), x86_64_r64(b), x86_64_r64(i));
					}
					else if (lgo && lga) {
						printf("                           %s %s, (%s, (%s)) ", mn, x86_64_r16(mrs), x86_64_r32(b), x86_64_r32(i));
					}
					else if (!rx3 && !lga) {
						printf("                           %s %s, (%s, (%s)) ", mn, x86_64_r32(mrs), x86_64_r64(b), x86_64_r64(i));
					}
					else if (!rx3 && lga) {
						printf("                           %s %s, (%s, (%s)) ", mn, x86_64_r32(mrs), x86_64_r32(b), x86_64_r32(i));
					}
					else if (rx3 && !lga) {
						printf("                           %s %s, (%s, (%s)) ", mn, x86_64_r64(mrs), x86_64_r64(b), x86_64_r64(i));
					}
					else if (rx3 && lga) {
						printf("                           %s %s, (%s, (%s)) ", mn, x86_64_r64(mrs), x86_64_r32(b), x86_64_r32(i));
					}
				}
			}
			else if ((mrd & 7) == 5) {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (d) {
					if (lgo && !lga) {
						printf("               %s %s, (rip, %u) ", mn, x86_64_r16(mrs), d);
					}
					else if (lgo && lga) {
						printf("               %s %s, (eip, %u) ", mn, x86_64_r16(mrs), d);
					}
					else if (!rx3 && !lga) {
						printf("               %s %s, (rip, %u) ", mn, x86_64_r32(mrs), d);
					}
					else if (!rx3 && lga) {
						printf("               %s %s, (eip, %u) ", mn, x86_64_r32(mrs), d);
					}
					else if (rx3 && !lga) {
						printf("               %s %s, (rip, %u) ", mn, x86_64_r64(mrs), d);
					}
					else if (rx3 && lga) {
						printf("               %s %s, (eip, %u) ", mn, x86_64_r64(mrs), d);
					}
				}
				else {
					if (lgo && !lga) {
						printf("               %s %s, (rip) ", mn, x86_64_r16(mrs));
					}
					else if (lgo && lga) {
						printf("               %s %s, (eip) ", mn, x86_64_r16(mrs));
					}
					else if (!rx3 && !lga) {
						printf("               %s %s, (rip) ", mn, x86_64_r32(mrs));
					}
					else if (!rx3 && lga) {
						printf("               %s %s, (eip) ", mn, x86_64_r32(mrs));
					}
					else if (rx3 && !lga) {
						printf("               %s %s, (rip) ", mn, x86_64_r64(mrs));
					}
					else if (rx3 && lga) {
						printf("               %s %s, (eip) ", mn, x86_64_r64(mrs));
					}
				}
			}
			else {
				*bn += 1;
				if (lgo && !lga) {
					printf("                              %s %s, (%s) ", mn, x86_64_r16(mrs), x86_64_r64(mrd));
				}
				else if (lgo && lga) {
					printf("                              %s %s, (%s) ", mn, x86_64_r16(mrs), x86_64_r32(mrd));
				}
				else if (!rx3 && !lga) {
					printf("                              %s %s, (%s) ", mn, x86_64_r32(mrs), x86_64_r64(mrd));
				}
				else if (!rx3 && lga) {
					printf("                              %s %s, (%s) ", mn, x86_64_r32(mrs), x86_64_r32(mrd));
				}
				else if (rx3 && !lga) {
					printf("                              %s %s, (%s) ", mn, x86_64_r64(mrs), x86_64_r64(mrd));
				}
				else if (rx3 && lga) {
					printf("                              %s %s, (%s) ", mn, x86_64_r32(mrs), x86_64_r32(mrd));
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
					if (lgo && !lga) {
						printf("                        %s %s, (%s, %u) ", mn, x86_64_r16(mrs), x86_64_r64(b), d);
					}
					else if (lgo && lga) {
						printf("                        %s %s, (%s, %u) ", mn, x86_64_r16(mrs), x86_64_r32(b), d);
					}
					else if (!rx3 && !lga) {
						printf("                        %s %s, (%s, %u) ", mn, x86_64_r32(mrs), x86_64_r64(b), d);
					}
					else if (!rx3 && lga) {
						printf("                        %s %s, (%s, %u) ", mn, x86_64_r32(mrs), x86_64_r32(b), d);
					}
					else if (rx3 && !lga) {
						printf("                        %s %s, (%s, %u) ", mn, x86_64_r64(mrs), x86_64_r64(b), d);
					}
					else if (rx3 && lga) {
						printf("                        %s %s, (%s, %u) ", mn, x86_64_r64(mrs), x86_64_r32(b), d);
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (lgo && !lga) {
						printf("                        %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r16(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
					else if (lgo && lga) {
						printf("                        %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r16(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
					else if (!rx3 && !lga) {
						printf("                        %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r32(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
					else if (!rx3 && lga) {
						printf("                        %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r32(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
					else if (rx3 && !lga) {
						printf("                        %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r64(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
					else if (rx3 && lga) {
						printf("                        %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r64(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (lgo && !lga) {
						printf("                        %s %s, (%s, (%s), %u) ", mn, x86_64_r16(mrs), x86_64_r64(b), x86_64_r64(i), d);
					}
					else if (lgo && lga) {
						printf("                        %s %s, (%s, (%s), %u) ", mn, x86_64_r16(mrs), x86_64_r32(b), x86_64_r32(i), d);
					}
					else if (!rx3 && !lga) {
						printf("                        %s %s, (%s, (%s), %u) ", mn, x86_64_r32(mrs), x86_64_r64(b), x86_64_r64(i), d);
					}
					else if (!rx3 && lga) {
						printf("                        %s %s, (%s, (%s), %u) ", mn, x86_64_r32(mrs), x86_64_r32(b), x86_64_r32(i), d);
					}
					else if (rx3 && !lga) {
						printf("                        %s %s, (%s, (%s), %u) ", mn, x86_64_r64(mrs), x86_64_r64(b), x86_64_r64(i), d);
					}
					else if (rx3 && lga) {
						printf("                        %s %s, (%s, (%s), %u) ", mn, x86_64_r64(mrs), x86_64_r32(b), x86_64_r32(i), d);
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lgo && !lga) {
					printf("                        %s %s, (%s, %u) ", mn, x86_64_r16(mrs), x86_64_r64(mrd), d);
				}
				else if (lgo && lga) {
					printf("                        %s %s, (%s, %u) ", mn, x86_64_r16(mrs), x86_64_r32(mrd), d);
				}
				else if (!rx3 && !lga) {
					printf("                        %s %s, (%s, %u) ", mn, x86_64_r32(mrs), x86_64_r64(mrd), d);
				}
				else if (!rx3 && lga) {
					printf("                        %s %s, (%s, %u) ", mn, x86_64_r32(mrs), x86_64_r32(mrd), d);
				}
				else if (rx3 && !lga) {
					printf("                        %s %s, (%s, %u) ", mn, x86_64_r64(mrs), x86_64_r64(mrd), d);
				}
				else if (rx3 && lga) {
					printf("                        %s %s, (%s, %u) ", mn, x86_64_r64(mrs), x86_64_r32(mrd), d);
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
					if (lgo && !lga) {
						printf("               %s %s, (%s, %u) ", mn, x86_64_r16(mrs), x86_64_r64(b), d);
					}
					else if (lgo && lga) {
						printf("               %s %s, (%s, %u) ", mn, x86_64_r16(mrs), x86_64_r32(b), d);
					}
					else if (!rx3 && !lga) {
						printf("               %s %s, (%s, %u) ", mn, x86_64_r32(mrs), x86_64_r64(b), d);
					}
					else if (!rx3 && lga) {
						printf("               %s %s, (%s, %u) ", mn, x86_64_r32(mrs), x86_64_r32(b), d);
					}
					else if (rx3 && !lga) {
						printf("               %s %s, (%s, %u) ", mn, x86_64_r64(mrs), x86_64_r64(b), d);
					}
					else if (rx3 && lga) {
						printf("               %s %s, (%s, %u) ", mn, x86_64_r64(mrs), x86_64_r32(b), d);
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lgo && !lga) {
						printf("               %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r16(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
					else if (lgo && lga) {
						printf("               %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r16(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
					else if (!rx3 && !lga) {
						printf("               %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r32(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
					else if (!rx3 && lga) {
						printf("               %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r32(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
					else if (rx3 && !lga) {
						printf("               %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r64(mrs), x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d);
					}
					else if (rx3 && lga) {
						printf("               %s %s, (%s, (%s, %u), %u) ", mn, x86_64_r64(mrs), x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d);
					}
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (lgo && !lga) {
						printf("               %s %s, (%s, (%s), %u) ", mn, x86_64_r16(mrs), x86_64_r64(b), x86_64_r64(i), d);
					}
					else if (lgo && lga) {
						printf("               %s %s, (%s, (%s), %u) ", mn, x86_64_r16(mrs), x86_64_r32(b), x86_64_r32(i), d);
					}
					else if (!rx3 && !lga) {
						printf("               %s %s, (%s, (%s), %u) ", mn, x86_64_r32(mrs), x86_64_r64(b), x86_64_r64(i), d);
					}
					else if (!rx3 && lga) {
						printf("               %s %s, (%s, (%s), %u) ", mn, x86_64_r32(mrs), x86_64_r32(b), x86_64_r32(i), d);
					}
					else if (rx3 && !lga) {
						printf("               %s %s, (%s, (%s), %u) ", mn, x86_64_r64(mrs), x86_64_r64(b), x86_64_r64(i), d);
					}
					else if (rx3 && lga) {
						printf("               %s %s, (%s, (%s), %u) ", mn, x86_64_r64(mrs), x86_64_r32(b), x86_64_r32(i), d);
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo && !lga) {
					printf("               %s %s, (%s, %u) ", mn, x86_64_r16(mrs), x86_64_r64(mrd), d);
				}
				else if (lgo && lga) {
					printf("               %s %s, (%s, %u) ", mn, x86_64_r16(mrs), x86_64_r32(mrd), d);
				}
				else if (!rx3 && !lga) {
					printf("               %s %s, (%s, %u) ", mn, x86_64_r32(mrs), x86_64_r64(mrd), d);
				}
				else if (!rx3 && lga) {
					printf("               %s %s, (%s, %u) ", mn, x86_64_r32(mrs), x86_64_r32(mrd), d);
				}
				else if (rx3 && !lga) {
					printf("               %s %s, (%s, %u) ", mn, x86_64_r64(mrs), x86_64_r64(mrd), d);
				}
				else if (rx3 && lga) {
					printf("               %s %s, (%s, %u) ", mn, x86_64_r64(mrs), x86_64_r32(mrd), d);
				}
			}
		}
		else if (mod == 3) {
			*bn += 1;
			if (lgo) {
				printf("                              %s %s, %s ", mn, x86_64_r16(mrs), x86_64_r16(mrd));
			}
			else if (!rx3) {
				printf("                              %s %s, %s, ", mn, x86_64_r32(mrs), x86_64_r32(mrd));
			}
			else if (rx3) {
				printf("                              %s %s, %s, ", mn, x86_64_r64(mrs), x86_64_r64(mrd));
			}
		}
		return 0;
	}
	else if (bin[*bn] == op + 4) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("                  %02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn += 1;
		printf("            %s al, %u ", mn, k);
		return 0;
	}
	else if (bin[*bn] == op + 5) {
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
		else if (rx3) {
			printf("                  %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			printf("   %s rax, %u ", mn, k);
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_imm(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == 128 && (bin[*bn + 1] >> 3) == (0 | op)) {
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
				if (d) {
					if (lga) {
						printf("            %sb (ebp, %u), %u ", mn, d, k);
					}
					else {
						printf("            %sb (rbp, %u), %u ", mn, d, k);
					}
				}
				else {
					if (lga) {
						printf("            %sb (ebp), %u ", mn, k);
					}
					else {
						printf("            %sb (rbp), %u ", mn, k);
					}
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
	else if (bin[*bn] == 128 && (bin[*bn + 1] >> 3) == (8 | op)) {
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
	else if (bin[*bn] == 128 && (bin[*bn + 1] >> 3) == (16 | op)) {
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
	else if (bin[*bn] == 128 && (bin[*bn + 1] >> 3) == (24 | op)) {
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
	else if (bin[*bn] == 129 && (bin[*bn + 1] >> 3) == (0 | op)) {
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
				if (d) {
					if (lgo) {
						printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
						uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
						*bn += 2;
						if (lga) {
							printf("         %sw (ebp, %u), %u ", mn, d, k);
						}
						else {
							printf("         %sw (rbp, %u), %u ", mn, d, k);
						}
					}
					else {
						printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
						uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
						*bn += 4;
						if (lga) {
							printf("   %sd (ebp, %u), %u ", mn, d, k);
						}
						else {
							printf("   %sd (rbp, %u), %u ", mn, d, k);
						}
					}
				}
				else {
					if (lgo) {
						printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
						uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
						*bn += 2;
						if (lga) {
							printf("         %sw (ebp), %u ", mn, k);
						}
						else {
							printf("         %sw (rbp), %u ", mn, k);
						}
					}
					else {
						printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
						uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
						*bn += 4;
						if (lga) {
							printf("   %sd (ebp), %u ", mn, k);
						}
						else {
							printf("   %sd (rbp), %u ", mn, k);
						}
					}
				}
			}
			else if (i == 4) {
				*bn += 1;
				if (lgo && lga) {
					printf("            %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (%s), %u ", mn, x86_64_r32(b), k);
				}
				else if (lgo && !lga) {
					printf("            %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (%s), %u ", mn, x86_64_r64(b), k);
				}
				else if (!lgo && lga) {
					printf("            %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (%s), %u ", mn, x86_64_r32(b), k);
				}
				else if (!lgo && !lga) {
					printf("            %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (%s), %u ", mn, x86_64_r64(b), k);
				}
			}
			else if (s) {
				*bn += 1;
				if (lgo && lga) {
					printf("            %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (%s, (%s, %u)), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), k);
				}
				else if (lgo && !lga) {
					printf("            %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (%s, (%s, %u)), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), k);
				}
				else if (!lgo && lga) {
					printf("            %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (%s, (%s, %u)), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), k);
				}
				else if (!lgo && !lga) {
					printf("            %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (%s, (%s, %u)), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), k);
				}
			}
			else {
				*bn += 1;
				if (lgo && lga) {
					printf("            %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (%s, (%s)), %u ", mn, x86_64_r32(b), x86_64_r32(i), k);
				}
				else if (lgo && !lga) {
					printf("            %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (%s, (%s)), %u ", mn, x86_64_r64(b), x86_64_r64(i), k);
				}
				else if (!lgo && lga) {
					printf("            %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (%s, (%s)), %u ", mn, x86_64_r32(b), x86_64_r32(i), k);
				}
				else if (!lgo && !lga) {
					printf("            %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (%s, (%s)), %u ", mn, x86_64_r64(b), x86_64_r64(i), k);
				}
			}
		}
		else if ((mrd & 7) == 5) {
			*bn += 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			if (d) {
				if (lgo && lga) {
					printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (eip, %u), %u ", mn, d, k);
				}
				else if (lgo && !lga) {
					printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (rip, %u), %u ", mn, d, k);
				}
				else if (!lgo && lga) {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (eip, %u), %u ", mn, d, k);
				}
				else if (!lgo && !lga) {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (rip, %u), %u ", mn, d, k);
				}
			}
			else {
				if (lgo && lga) {
					printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (eip), %u ", mn, k);
				}
				else if (lgo && !lga) {
					printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (rip), %u ", mn, k);
				}
				else if (!lgo && lga) {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (eip), %u ", mn, k);
				}
				else if (!lgo && !lga) {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (rip), %u ", mn, k);
				}
			}
		}
		else {
			*bn += 1;
			if (lgo && lga) {
				printf("               %02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				printf("         %sw (%s), %u ", mn, x86_64_r32(mrd), k);
			}
			else if (lgo && !lga) {
				printf("               %02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				printf("         %sw (%s), %u ", mn, x86_64_r64(mrd), k);
			}
			else if (!lgo && lga) {
				printf("               %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("   %sd (%s), %u ", mn, x86_64_r32(mrd), k);
			}
			else if (!lgo && !lga) {
				printf("               %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("   %sd (%s), %u ", mn, x86_64_r64(mrd), k);
			}
		}
		return 0;
	}
	else if (bin[*bn] == 129 && (bin[*bn + 1] >> 3) == (8 | op)) {
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
				if (lgo && lga) {
					printf("         %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (%s, %u), %u ", mn, x86_64_r32(b), d, k);
				}
				else if (lgo && !lga) {
					printf("         %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (%s, %u), %u ", mn, x86_64_r64(b), d, k);
				}
				else if (!lgo && lga) {
					printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (%s, %u), %u ", mn, x86_64_r32(b), d, k);
				}
				else if (!lgo && !lga) {
					printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (%s, %u), %u ", mn, x86_64_r64(b), d, k);
				}
			}
			else if (s) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lgo && lga) {
					printf("         %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (%s, (%s, %u), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, k);
				}
				else if (lgo && !lga) {
					printf("         %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (%s, (%s, %u), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, k);
				}
				else if (!lgo && lga) {
					printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (%s, (%s, %u), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, k);
				}
				else if (!lgo && !lga) {
					printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (%s, (%s, %u), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, k);
				}
			}
			else {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (lgo && lga) {
					printf("         %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (%s, (%s), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), d, k);
				}
				else if (lgo && !lga) {
					printf("         %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (%s, (%s), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), d, k);
				}
				else if (!lgo && lga) {
					printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (%s, (%s), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), d, k);
				}
				else if (!lgo && !lga) {
					printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (%s, (%s), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), d, k);
				}
			}
		}
		else {
			*bn += 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			if (lgo && lga) {
				printf("         %02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				printf("         %sw (%s, %u), %u ", mn, x86_64_r32(mrd), d, k);
			}
			else if (lgo && !lga) {
				printf("         %02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				printf("         %sw (%s, %u), %u ", mn, x86_64_r64(mrd), d, k);
			}
			else if (!lgo && lga) {
				printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("   %sd (%s, %u), %u ", mn, x86_64_r32(mrd), d, k);
			}
			else if (!lgo && !lga) {
				printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("   %sd (%s, %u), %u ", mn, x86_64_r64(mrd), d, k);
			}
		}
		return 0;
	}
	else if (bin[*bn] == 129 && (bin[*bn + 1] >> 3) == (16 | op)) {
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
				if (lgo && lga) {
					printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (%s, %u), %u ", mn, x86_64_r32(b), d, k);
				}
				else if (lgo && !lga) {
					printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (%s, %u), %u ", mn, x86_64_r64(b), d, k);
				}
				else if (!lgo && lga) {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (%s, %u), %u ", mn, x86_64_r32(b), d, k);
				}
				else if (!lgo && !lga) {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (%s, %u), %u ", mn, x86_64_r64(b), d, k);
				}
			}
			else if (s) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo && lga) {
					printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (%s, (%s, %u), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, k);
				}
				else if (lgo && !lga) {
					printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (%s, (%s, %u), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, k);
				}
				else if (!lgo && lga) {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (%s, (%s, %u), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, k);
				}
				else if (!lgo && !lga) {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (%s, (%s, %u), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, k);
				}
			}
			else {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo && lga) {
					printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (%s, (%s), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), d, k);
				}
				else if (lgo && !lga) {
					printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (%s, (%s), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), d, k);
				}
				else if (!lgo && lga) {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (%s, (%s), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), d, k);
				}
				else if (!lgo && !lga) {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (%s, (%s), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), d, k);
				}
			}
		}
		else {
			*bn += 1;
			printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			if (lgo && lga) {
				printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				printf("         %sw (%s, %u), %u ", mn, x86_64_r32(mrd), d, k);
			}
			else if (lgo && !lga) {
				printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				printf("         %sw (%s, %u), %u ", mn, x86_64_r64(mrd), d, k);
			}
			else if (!lgo && lga) {
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("   %sd (%s, %u), %u ", mn, x86_64_r32(mrd), d, k);
			}
			else if (!lgo && !lga) {
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("   %sd (%s, %u), %u ", mn, x86_64_r64(mrd), d, k);
			}
		}
		return 0;
	}
	else if (bin[*bn] == 129 && (bin[*bn + 1] >> 3) == (24 | op)) {
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
		else if (rx3) {
			printf("               %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			printf("   %s %s, %u ", mn, x86_64_r64(mrd + (8 * rx2)), k);
		}
		return 0;
	}
	else if (bin[*bn] == 131 && (bin[*bn + 1] >> 3) == (0 | op)) {
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
				if (d) {
					if (lgo && lga) {
						printf("            %sw (ebp, %u), %u ", mn, d, k);
					}
					else if (!lgo && lga) {
						printf("            %sd (ebp, %u), %u ", mn, d, k);
					}
					else if (lgo) {
						printf("            %sw (rbp, %u), %u ", mn, d, k);
					}
					else {
						printf("            %sd (rbp, %u), %u ", mn, d, k);
					}
				}
				else {
					if (lgo && lga) {
						printf("            %sw (ebp), %u ", mn, k);
					}
					else if (!lgo && lga) {
						printf("            %sd (ebp), %u ", mn, k);
					}
					else if (lgo) {
						printf("            %sw (rbp), %u ", mn, k);
					}
					else {
						printf("            %sd (rbp), %u ", mn, k);
					}
				}
			}
			else if (i == 4) {
				*bn += 1;
				printf("            %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				if (lgo && lga) {
					printf("            %sw (%s), %u ", mn, x86_64_r32(b), k);
				}
				else if (lgo && !lga) {
					printf("            %sw (%s), %u ", mn, x86_64_r64(b), k);
				}
				else if (!lgo && lga) {
					printf("            %sd (%s), %u ", mn, x86_64_r32(b), k);
				}
				else if (!lgo && !lga) {
					printf("            %sd (%s), %u ", mn, x86_64_r64(b), k);
				}
			}
			else if (s) {
				*bn += 1;
				printf("            %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				if (lgo && lga) {
					printf("            %sw (%s, (%s, %u)), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), k);
				}
				else if (lgo && !lga) {
					printf("            %sw (%s, (%s, %u)), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), k);
				}
				else if (!lgo && lga) {
					printf("            %sd (%s, (%s, %u)), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), k);
				}
				else if (!lgo && !lga) {
					printf("            %sd (%s, (%s, %u)), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), k);
				}
			}
			else {
				*bn += 1;
				printf("            %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				if (lgo && lga) {
					printf("            %sw (%s, (%s)), %u ", mn, x86_64_r32(b), x86_64_r32(i), k);
				}
				else if (lgo && !lga) {
					printf("            %sw (%s, (%s)), %u ", mn, x86_64_r64(b), x86_64_r64(i), k);
				}
				else if (!lgo && lga) {
					printf("            %sd (%s, (%s)), %u ", mn, x86_64_r32(b), x86_64_r32(i), k);
				}
				else if (!lgo && !lga) {
					printf("            %sd (%s, (%s)), %u ", mn, x86_64_r64(b), x86_64_r64(i), k);
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
				if (lgo && lga) {
					printf("            %sw (eip, %u), %u ", mn, d, k);
				}
				else if (lgo && !lga) {
					printf("            %sw (rip, %u), %u ", mn, d, k);
				}
				else if (!lgo && lga) {
					printf("            %sd (eip, %u), %u ", mn, d, k);
				}
				else if (!lgo && !lga) {
					printf("            %sd (rip, %u), %u ", mn, d, k);
				}
			}
			else {
				if (lgo && lga) {
					printf("            %sw (eip), %u ", mn, k);
				}
				else if (lgo && !lga) {
					printf("            %sw (rip), %u ", mn, k);
				}
				else if (!lgo && lga) {
					printf("            %sd (eip), %u ", mn, k);
				}
				else if (!lgo && !lga) {
					printf("            %sd (rip), %u ", mn, k);
				}
			}
		}
		else {
			*bn += 1;
			printf("               %02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn += 1;
			if (lgo && lga) {
				printf("            %sw (%s), %u ", mn, x86_64_r32(mrd), k);
			}
			else if (lgo && !lga) {
				printf("            %sw (%s), %u ", mn, x86_64_r64(mrd), k);
			}
			else if (!lgo && lga) {
				printf("            %sd (%s), %u ", mn, x86_64_r32(mrd), k);
			}
			else if (!lgo && !lga) {
				printf("            %sd (%s), %u ", mn, x86_64_r64(mrd), k);
			}
		}
		return 0;
	}
	else if (bin[*bn] == 131 && (bin[*bn + 1] >> 3) == (8 | op)) {
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
				if (lgo && lga) {
					printf("            %sw (%s, %u), %u ", mn, x86_64_r32(b), d, k);
				}
				else if (lgo && !lga) {
					printf("            %sw (%s, %u), %u ", mn, x86_64_r64(b), d, k);
				}
				else if (!lgo && lga) {
					printf("            %sd (%s, %u), %u ", mn, x86_64_r32(b), d, k);
				}
				else if (!lgo && !lga) {
					printf("            %sd (%s, %u), %u ", mn, x86_64_r64(b), d, k);
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
				if (lgo && lga) {
					printf("            %sw (%s, (%s, %u), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, k);
				}
				else if (lgo && !lga) {
					printf("            %sw (%s, (%s, %u), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, k);
				}
				else if (!lgo && lga) {
					printf("            %sd (%s, (%s, %u), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, k);
				}
				else if (!lgo && !lga) {
					printf("            %sd (%s, (%s, %u), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, k);
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
				if (lgo && lga) {
					printf("            %sw (%s, (%s), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), d, k);
				}
				else if (lgo && !lga) {
					printf("            %sw (%s, (%s), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), d, k);
				}
				else if (!lgo && lga) {
					printf("            %sd (%s, (%s), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), d, k);
				}
				else if (!lgo && !lga) {
					printf("            %sd (%s, (%s), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), d, k);
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
			if (lgo && lga) {
				printf("            %sw (%s, %u), %u ", mn, x86_64_r32(mrd), d, k);
			}
			else if (lgo && !lga) {
				printf("            %sw (%s, %u), %u ", mn, x86_64_r64(mrd), d, k);
			}
			else if (!lgo && lga) {
				printf("            %sd (%s, %u), %u ", mn, x86_64_r32(mrd), d, k);
			}
			else if (!lgo && !lga) {
				printf("            %sd (%s, %u), %u ", mn, x86_64_r64(mrd), d, k);
			}
		}
		return 0;
	}
	else if (bin[*bn] == 131 && (bin[*bn + 1] >> 3) == (16 | op)) {
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
				if (lgo && lga) {
					printf("            %sw (%s, %u), %u ", mn, x86_64_r32(b), d, k);
				}
				else if (lgo && !lga) {
					printf("            %sw (%s, %u), %u ", mn, x86_64_r64(b), d, k);
				}
				else if (!lgo && lga) {
					printf("            %sd (%s, %u), %u ", mn, x86_64_r32(b), d, k);
				}
				else if (!lgo && !lga) {
					printf("            %sd (%s, %u), %u ", mn, x86_64_r64(b), d, k);
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
				if (lgo && lga) {
					printf("            %sw (%s, (%s, %u), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, k);
				}
				else if (lgo && !lga) {
					printf("            %sw (%s, (%s, %u), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, k);
				}
				else if (!lgo && lga) {
					printf("            %sd (%s, (%s, %u), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), x86_64_s8(s), d, k);
				}
				else if (!lgo && !lga) {
					printf("            %sd (%s, (%s, %u), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_s8(s), d, k);
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
				if (lgo && lga) {
					printf("            %sw (%s, (%s), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), d, k);
				}
				else if (lgo && !lga) {
					printf("            %sw (%s, (%s), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), d, k);
				}
				else if (!lgo && lga) {
					printf("            %sd (%s, (%s), %u), %u ", mn, x86_64_r32(b), x86_64_r32(i), d, k);
				}
				else if (!lgo && !lga) {
					printf("            %sd (%s, (%s), %u), %u ", mn, x86_64_r64(b), x86_64_r64(i), d, k);
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
			if (lgo && lga) {
				printf("            %sw (%s, %u), %u ", mn, x86_64_r32(mrd), d, k);
			}
			else if (lgo && !lga) {
				printf("            %sw (%s, %u), %u ", mn, x86_64_r64(mrd), d, k);
			}
			else if (!lgo && lga) {
				printf("            %sd (%s, %u), %u ", mn, x86_64_r32(mrd), d, k);
			}
			else if (!lgo && !lga) {
				printf("            %sd (%s, %u), %u ", mn, x86_64_r64(mrd), d, k);
			}
		}
		return 0;
	}
	else if (bin[*bn] == 131 && (bin[*bn + 1] >> 3) == (24 | op)) {
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
		else if (rx3) {
			printf("            %s %s, %u ", mn, x86_64_r64(mrd + (8 * rx2)), k);
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_mov(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if ((bin[*bn] >> 4) == 11) {
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		uint8_t r48 = (bin[*bn] & 8);
		*bn += 1;
		
		if (rex && rx3) {
			printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t kl = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t kh = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			uint64_t k = kl + (((uint64_t) kh) << 32);
			
			printf("    %s %s, %lu ", mn, x86_64_r64(mrd), k);
		}
		else if (rex && lgo) {
			printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			
			printf("                      %s %s, %u ", mn, x86_64_r16(mrd), k);
		}
		else if (rex && r48) {
			printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			
			printf("                %s %s, %u ", mn, x86_64_r32(mrd), k);
		}
		else if (rex) {
			printf("%02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn += 1;
			
			printf("                         %s %s, %u ", mn, x86_64_r8x(mrd), k);
		}
		else if (lgo) {
			printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			
			printf("                      %s %s, %u ", mn, x86_64_r16(mrd), k);
		}
		else if (r48) {
			printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			
			printf("                %s %s, %u ", mn, x86_64_r32(mrd), k);
		}
		else {
			printf("%02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn += 1;
			
			printf("                         %s %s, %u ", mn, x86_64_r8(mrd), k);
		}
		
		return 0;
	}
	else if (bin[*bn] == 199 && rx3) {
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
					printf("        %s (%u), %s ", mn, d, x86_64_r64(mrs));
				}
				else if (i == 4) {
					*bn += 1;
					printf("                      %s (%s), %s ", mn, x86_64_r64(b), x86_64_r64(mrs));
				}
				else {
					*bn += 1;
					printf("                  %s (%s, (%s)), %s ", mn, x86_64_r64(b), x86_64_r64(i), x86_64_r64(mrs));
				}
			}
			else if ((mrd & 7) == 5) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("        %s (rip, %u), %s ", mn, d, x86_64_r64(mrs));
			}
			else {
				*bn += 1;
				printf("                      %s (%s), %s ", mn, x86_64_r64(mrd), x86_64_r64(mrs));
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
					printf("                 %s (%s, %u), %s ", mn, x86_64_r64(b), d, x86_64_r64(mrs));
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					printf("                 %s (%s, (%s), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), d, x86_64_r64(mrs));
				}
			}
			else {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				printf("                   %s (%s, %u), %s ", mn, x86_64_r64(mrd), d, x86_64_r64(mrs));
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
					printf("        %s (%s, %u), %s ", mn, x86_64_r64(b), d, x86_64_r64(mrs));
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("        %s (%s, (%s), %u), %s ", mn, x86_64_r64(b), x86_64_r64(i), d, x86_64_r64(mrs));
				}
			}
			else {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("        %s (%s, %u), %s ", mn, x86_64_r64(mrd), d, x86_64_r64(mrs));
			}
		}
		else if (mod == 3) {
			*bn += 1;
			printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			printf("             %s %s, %u ", mn, x86_64_r64(mrd), k);
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_lea(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == 141) {
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
					printf("        %s %s, (%u) ", mn, x86_64_r64(mrs), d);
				}
				else if (i == 4) {
					*bn += 1;
					printf("                      %s %s, (%s) ", mn, x86_64_r64(mrs), x86_64_r64(b));
				}
				else {
					*bn += 1;
					printf("                  %s %s, (%s, (%s)) ", mn, x86_64_r64(mrs), x86_64_r64(b), x86_64_r64(i));
				}
			}
			else if ((mrd & 7) == 5) {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("             %s %s, (rip, %u) ", mn, x86_64_r64(mrs), d);
			}
			else {
				*bn += 1;
				printf("                      %s %s, (%s) ", mn, x86_64_r64(mrs), x86_64_r64(mrd));
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
					printf("                   %s %s, (%s, %u) ", mn, x86_64_r64(mrs), x86_64_r64(b), d);
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					printf("                   %s %s, (%s, (%s), %u) ", mn, x86_64_r64(mrs), x86_64_r64(b), x86_64_r64(i), d);
				}
			}
			else {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				printf("                   %s %s, (%s, %u) ", mn, x86_64_r64(mrs), x86_64_r64(mrd), d);
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
					printf("             %s %s, (%s, %u) ", mn, x86_64_r64(mrs), x86_64_r64(b), d);
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("             %s %s, (%s, (%s), %u) ", mn, x86_64_r64(mrs), x86_64_r64(b), x86_64_r64(i), d);
				}
			}
			else {
				*bn += 1;
				printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("             %s %s, (%s, %u) ", mn, x86_64_r64(mrs), x86_64_r64(mrd), d);
			}
		}
		else if (mod == 3) {
			*bn += 1;
			printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			printf("             %s %s, %u ", mn, x86_64_r64(mrd), k);
		}
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_8k(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		
		printf("%02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn += 1;
		
		printf("                         %s %u ", mn, k);
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_32k(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		
		printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
		uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
		*bn += 4;
		
		printf("                %s %u ", mn, k);
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_byt(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		
		printf("                            %s", mn);
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_8m(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if ((bin[*bn] & 248) == op) {
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		*bn += 1;
		if (lgo) {
			printf("                            %s %s ", mn, x86_64_r16(mrd + (8 * rex)));
		}
		else {
			printf("                            %s %s ", mn, x86_64_r64(mrd + (8 * rex)));
		}
		
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_jmp(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		
		printf("%02x ", bin[*bn]);
		uint8_t d = bin[*bn];
		*bn += 1;
		
		printf("                         %s %u ", mn, d);
		return 0;
	}
	else if (bin[*bn] == 15 && bin[*bn + 1] == op + 16) {
		printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
		*bn += 2;
		
		printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
		uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
		*bn += 4;
		
		printf("                %s %u ", mn, k);
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_sys(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == 15 && bin[*bn + 1] == 5) {
		printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
		*bn += 2;
		
		printf("                         syscall");
		return 0;
	}
	return 1;
}

uint8_t x86_64_dec_shft(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo, uint8_t rex, uint8_t rx0, uint8_t rx1, uint8_t rx2, uint8_t rx3) {
	if (bin[*bn] == 192 && ((bin[*bn + 1] >> 3) & 7) == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		uint8_t r48 = bin[*bn] >> 6;
		printf("%02x ", bin[*bn]);
		*bn += 1;
		
		if (rex) {
			printf("%02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn += 1;
			
			printf("                      %s %s, %u ", mn, x86_64_r8x(mrd), k);
		}
		else {
			printf("%02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn += 1;
			
			printf("                      %s %s, %u ", mn, x86_64_r8(mrd), k);
		}
		
		return 0;
	}
	else if (bin[*bn] == 193 && ((bin[*bn + 1] >> 3) & 7) == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		uint8_t mrd = (bin[*bn] & 7) + (8 * rx0);
		uint8_t r48 = bin[*bn] >> 6;
		printf("%02x ", bin[*bn]);
		*bn += 1;
		
		if (rex && rx3) {
			printf("%02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn += 1;
			
			printf("                      %s %s, %u ", mn, x86_64_r64(mrd), k);
		}
		else if (rex && lgo) {
			printf("%02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn += 1;
			
			printf("                      %s %s, %u ", mn, x86_64_r16(mrd), k);
		}
		else if (rex && r48) {
			printf("%02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn += 1;
			
			printf("                      %s %s, %u ", mn, x86_64_r32(mrd), k);
		}
		else if (lgo) {
			printf("%02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn += 1;
			
			printf("                      %s %s, %u ", mn, x86_64_r16(mrd), k);
		}
		else if (r48) {
			printf("%02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn += 1;
			
			printf("                      %s %s, %u ", mn, x86_64_r32(mrd), k);
		}
		else if (lga) {
			printf("%02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn += 1;
			
			printf("                      %s (%s), %u ", mn, x86_64_r32(mrd), k);
		}
		else {
			printf("%02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn += 1;
			
			printf("                      %s (%s), %u ", mn, x86_64_r64(mrd), k);
		}
		
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
		eo = x86_64_dec_reg(bin, bn, addr, 0, "add", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_reg(bin, bn, addr, 8, "or", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_reg(bin, bn, addr, 16, "adc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_reg(bin, bn, addr, 24, "sbb", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_reg(bin, bn, addr, 32, "and", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_reg(bin, bn, addr, 40, "sub", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_reg(bin, bn, addr, 48, "xor", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_reg(bin, bn, addr, 56, "cmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_imm(bin, bn, addr, 0, "add", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_imm(bin, bn, addr, 1, "or", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_imm(bin, bn, addr, 2, "adc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_imm(bin, bn, addr, 3, "sbb", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_imm(bin, bn, addr, 4, "and", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_imm(bin, bn, addr, 5, "sub", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_imm(bin, bn, addr, 6, "xor", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_imm(bin, bn, addr, 7, "cmp", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	
	if (eo) {
		eo = x86_64_dec_sys(bin, bn, addr, 0, 0, lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_8m(bin, bn, addr, 80, "push", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_8m(bin, bn, addr, 88, "pop", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_32k(bin, bn, addr, 104, "push", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_8k(bin, bn, addr, 106, "push", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_jmp(bin, bn, addr, 112, "jo", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_jmp(bin, bn, addr, 113, "jno", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_jmp(bin, bn, addr, 114, "jc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_jmp(bin, bn, addr, 115, "jnc", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_jmp(bin, bn, addr, 116, "je", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_jmp(bin, bn, addr, 117, "jne", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_jmp(bin, bn, addr, 118, "jna", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_jmp(bin, bn, addr, 119, "ja", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_jmp(bin, bn, addr, 120, "js", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_jmp(bin, bn, addr, 121, "jns", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_jmp(bin, bn, addr, 122, "jpe", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_jmp(bin, bn, addr, 123, "jpo", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_jmp(bin, bn, addr, 124, "jl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_jmp(bin, bn, addr, 125, "jge", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_jmp(bin, bn, addr, 126, "jle", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_jmp(bin, bn, addr, 127, "jg", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_mov(bin, bn, addr, 0, "mov", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 195, "ret", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_8k(bin, bn, addr, 205, "int", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 206, "into", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_byt(bin, bn, addr, 207, "iret", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_32k(bin, bn, addr, 232, "call", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft(bin, bn, addr, 0, "rol", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft(bin, bn, addr, 1, "ror", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft(bin, bn, addr, 2, "rcl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft(bin, bn, addr, 3, "rcr", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft(bin, bn, addr, 4, "shl", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		eo = x86_64_dec_shft(bin, bn, addr, 5, "shr", lga, lgo, rex, rx0, rx1, rx2, rx3);
	}
	if (eo) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
	}
}
