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

uint8_t i386_dec_r80(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7);
		uint8_t mrs = ((bin[*bn] >> 3) & 7);
		
		if (mod == 0 && lga) {
			if (mrd == 6) {
				*bn += 1;
				printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				printf("                     %s (%u), %s", mn, d, i386_r8(mrs));
			}
			else {
				*bn += 1;
				printf("                              %s (%s), %s", mn, i386_a16(mrd), i386_r8(mrs));
			}
		}
		else if (mod == 1 && lga) {
			*bn += 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			if (d & 128) {
				d = ~d + 1;
				printf("                        %s (%s, -%u), %s", mn, i386_a16(mrd), d, i386_r8(mrs));
			}
			else {
				printf("                        %s (%s, %u), %s", mn, i386_a16(mrd), d, i386_r8(mrs));
			}
		}
		else if (mod == 2 && lga) {
			*bn += 1;
			printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			if (d & 32768) {
				d = ~d + 1;
				printf("                     %s (%s, -%u), %s", mn, i386_a16(mrd), d, i386_r8(mrs));
			}
			else {
				printf("                     %s (%s, %u), %s", mn, i386_a16(mrd), d, i386_r8(mrs));
			}
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
					printf("               %s (%u), %s", mn, d, i386_r8(mrs));
				}
				else if (i == 4) {
					*bn += 1;
					printf("                           %s (%s), %s", mn, i386_r32(b), i386_r8(mrs));
				}
				else if (s) {
					*bn += 1;
					printf("                           %s (%s, (%s, %u)), %s", mn, i386_r32(b), i386_r32(i), i386_s8(s), i386_r8(mrs));
				}
				else {
					*bn += 1;
					printf("                           %s (%s, (%s)), %s", mn, i386_r32(b), i386_r32(i), i386_r8(mrs));
				}
			}
			else if (mrd == 5) {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("               %s (%u), %s", mn, d, i386_r8(mrs));
			}
			else {
				*bn += 1;
				printf("                              %s (%s), %s", mn, i386_r32(mrd), i386_r8(mrs));
			}
		}
		else if (mod == 1) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						printf("                        %s (%s, -%u), %s", mn, i386_r32(b), d, i386_r8(mrs));
					}
					else {
						printf("                        %s (%s, %u), %s", mn, i386_r32(b), d, i386_r8(mrs));
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						printf("                        %s (%s, (%s, %u), -%u), %s", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, i386_r8(mrs));
					}
					else {
						printf("                        %s (%s, (%s, %u), %u), %s", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, i386_r8(mrs));
						}
					}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						printf("                        %s (%s, (%s), -%u), %s", mn, i386_r32(b), i386_r32(i), d, i386_r8(mrs));
					}
					else {
						printf("                        %s (%s, (%s), %u), %s", mn, i386_r32(b), i386_r32(i), d, i386_r8(mrs));
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (d & 128) {
					d = ~d + 1;
					printf("                        %s (%s, -%u), %s", mn, i386_r32(mrd), d, i386_r8(mrs));
				}
				else {
					printf("                        %s (%s, %u), %s", mn, i386_r32(mrd), d, i386_r8(mrs));
				}
			}
		}
		else if (mod == 2) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						printf("               %s (%s, -%u), %s", mn, i386_r32(b), d, i386_r8(mrs));
					}
					else {
						printf("               %s (%s, %u), %s", mn, i386_r32(b), d, i386_r8(mrs));
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						printf("               %s (%s, (%s, %u), -%u), %s", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, i386_r8(mrs));
					}
					else {
						printf("               %s (%s, (%s, %u), %u), %s", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, i386_r8(mrs));
					}
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						printf("               %s (%s, (%s), -%u), %s", mn, i386_r32(b), i386_r32(i), d, i386_r8(mrs));
					}
					else {
						printf("               %s (%s, (%s), %u), %s", mn, i386_r32(b), i386_r32(i), d, i386_r8(mrs));
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (d & 2147483648) {
					d = ~d + 1;
					printf("               %s (%s, -%u), %s", mn, i386_r32(mrd), d, i386_r8(mrs));
				}
				else {
					printf("               %s (%s, %u), %s", mn, i386_r32(mrd), d, i386_r8(mrs));
				}
			}
		}
		else if (mod == 3) {
			*bn += 1;
			printf("                              %s %s, %s", mn, i386_r8(mrd), i386_r8(mrs));
		}
		return 0;
	}
	return 1;
}

uint8_t i386_dec_rg0(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7);
		uint8_t mrs = ((bin[*bn] >> 3) & 7);
		
		if (mod == 0 && lga) {
			if (mrd == 6) {
				*bn += 1;
				printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				if (lgo) {
					printf("                     %s (%u), %s", mn, d, i386_r16(mrs));
				}
				else {
					printf("                     %s (%u), %s", mn, d, i386_r32(mrs));
				}
			}
			else {
				*bn += 1;
				if (lgo) {
					printf("                              %s (%s), %s", mn, i386_a16(mrd), i386_r16(mrs));
				}
				else {
					printf("                              %s (%s), %s", mn, i386_a16(mrd), i386_r32(mrs));
				}
			}
		}
		else if (mod == 1 && lga) {
			*bn += 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			if (d & 128) {
				d = ~d + 1;
				if (lgo) {
					printf("                        %s (%s, -%u), %s", mn, i386_a16(mrd), d, i386_r16(mrs));
				}
				else {
					printf("                        %s (%s, -%u), %s", mn, i386_a16(mrd), d, i386_r32(mrs));
				}
			}
			else {
				if (lgo) {
					printf("                        %s (%s, %u), %s", mn, i386_a16(mrd), d, i386_r16(mrs));
				}
				else {
					printf("                        %s (%s, %u), %s", mn, i386_a16(mrd), d, i386_r32(mrs));
				}
			}
		}
		else if (mod == 2 && lga) {
			*bn += 1;
			printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			if (d & 32768) {
				d = ~d + 1;
				if (lgo) {
					printf("                     %s (%s, -%u), %s", mn, i386_a16(mrd), d, i386_r16(mrs));
				}
				else {
					printf("                     %s (%s, -%u), %s", mn, i386_a16(mrd), d, i386_r32(mrs));
				}
			}
			else {
				if (lgo) {
					printf("                     %s (%s, %u), %s", mn, i386_a16(mrd), d, i386_r16(mrs));
				}
				else {
					printf("                     %s (%s, %u), %s", mn, i386_a16(mrd), d, i386_r32(mrs));
				}
			}
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
					if (lgo) {
						printf("               %s (%u), %s", mn, d, i386_r16(mrs));
					}
					else {
						printf("               %s (%u), %s", mn, d, i386_r32(mrs));
					}
				}
				else if (i == 4) {
					*bn += 1;
					if (lgo) {
						printf("                           %s (%s), %s", mn, i386_r32(b), i386_r16(mrs));
					}
					else {
						printf("                           %s (%s), %s", mn, i386_r32(b), i386_r32(mrs));
					}
				}
				else if (s) {
					*bn += 1;
					if (lgo) {
						printf("                           %s (%s, (%s, %u)), %s", mn, i386_r32(b), i386_r32(i), i386_s8(s), i386_r16(mrs));
					}
					else {
						printf("                           %s (%s, (%s, %u)), %s", mn, i386_r32(b), i386_r32(i), i386_s8(s), i386_r32(mrs));
					}
				}
				else {
					*bn += 1;
					if (lgo) {
						printf("                           %s (%s, (%s)), %s", mn, i386_r32(b), i386_r32(i), i386_r16(mrs));
					}
					else {
						printf("                           %s (%s, (%s)), %s", mn, i386_r32(b), i386_r32(i), i386_r32(mrs));
					}
				}
			}
			else if (mrd == 5) {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					printf("               %s (%u), %s", mn, d, i386_r16(mrs));
				}
				else {
					printf("               %s (%u), %s", mn, d, i386_r32(mrs));
				}
			}
			else {
				*bn += 1;
				if (lgo) {
					printf("                              %s (%s), %s", mn, i386_r32(mrd), i386_r16(mrs));
				}
				else {
					printf("                              %s (%s), %s", mn, i386_r32(mrd), i386_r32(mrs));
				}
			}
		}
		else if (mod == 1) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							printf("                        %s (%s, -%u), %s", mn, i386_r32(b), d, i386_r16(mrs));
						}
						else {
							printf("                        %s (%s, -%u), %s", mn, i386_r32(b), d, i386_r32(mrs));
						}
					}
					else {
						if (lgo) {
							printf("                        %s (%s, %u), %s", mn, i386_r32(b), d, i386_r16(mrs));
						}
						else {
							printf("                        %s (%s, %u), %s", mn, i386_r32(b), d, i386_r32(mrs));
						}
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							printf("                        %s (%s, (%s, %u), -%u), %s", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, i386_r16(mrs));
						}
						else {
							printf("                        %s (%s, (%s, %u), -%u), %s", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, i386_r32(mrs));
						}
					}
					else {
						if (lgo) {
							printf("                        %s (%s, (%s, %u), %u), %s", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, i386_r16(mrs));
						}
						else {
							printf("                        %s (%s, (%s, %u), %u), %s", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, i386_r32(mrs));
						}
					}
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							printf("                        %s (%s, (%s), -%u), %s", mn, i386_r32(b), i386_r32(i), d, i386_r16(mrs));
						}
						else {
							printf("                        %s (%s, (%s), -%u), %s", mn, i386_r32(b), i386_r32(i), d, i386_r32(mrs));
						}
					}
					else {
						if (lgo) {
							printf("                        %s (%s, (%s), %u), %s", mn, i386_r32(b), i386_r32(i), d, i386_r16(mrs));
						}
						else {
							printf("                        %s (%s, (%s), %u), %s", mn, i386_r32(b), i386_r32(i), d, i386_r32(mrs));
						}
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						printf("                        %s (%s, -%u), %s", mn, i386_r32(mrd), d, i386_r16(mrs));
					}
					else {
						printf("                        %s (%s, -%u), %s", mn, i386_r32(mrd), d, i386_r32(mrs));
					}
				}
				else {
					if (lgo) {
						printf("                        %s (%s, %u), %s", mn, i386_r32(mrd), d, i386_r16(mrs));
					}
					else {
						printf("                        %s (%s, %u), %s", mn, i386_r32(mrd), d, i386_r32(mrs));
					}
				}
			}
		}
		else if (mod == 2) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							printf("               %s (%s, -%u), %s", mn, i386_r32(b), d, i386_r16(mrs));
						}
						else {
							printf("               %s (%s, -%u), %s", mn, i386_r32(b), d, i386_r32(mrs));
						}
					}
					else {
						if (lgo) {
							printf("               %s (%s, %u), %s", mn, i386_r32(b), d, i386_r16(mrs));
						}
						else {
							printf("               %s (%s, %u), %s", mn, i386_r32(b), d, i386_r32(mrs));
						}
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							printf("               %s (%s, (%s, %u), -%u), %s", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, i386_r16(mrs));
						}
						else {
							printf("               %s (%s, (%s, %u), -%u), %s", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, i386_r32(mrs));
						}
					}
					else {
						if (lgo) {
							printf("               %s (%s, (%s, %u), %u), %s", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, i386_r16(mrs));
						}
						else {
							printf("               %s (%s, (%s, %u), %u), %s", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, i386_r32(mrs));
						}
					}
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							printf("               %s (%s, (%s), -%u), %s", mn, i386_r32(b), i386_r32(i), d, i386_r16(mrs));
						}
						else {
							printf("               %s (%s, (%s), -%u), %s", mn, i386_r32(b), i386_r32(i), d, i386_r32(mrs));
						}
					}
					else {
						if (lgo) {
							printf("               %s (%s, (%s), %u), %s", mn, i386_r32(b), i386_r32(i), d, i386_r16(mrs));
						}
						else {
							printf("               %s (%s, (%s), %u), %s", mn, i386_r32(b), i386_r32(i), d, i386_r32(mrs));
						}
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						printf("               %s (%s, -%u), %s", mn, i386_r32(mrd), d, i386_r16(mrs));
					}
					else {
						printf("               %s (%s, -%u), %s", mn, i386_r32(mrd), d, i386_r32(mrs));
					}
				}
				else {
					if (lgo) {
						printf("               %s (%s, %u), %s", mn, i386_r32(mrd), d, i386_r16(mrs));
					}
					else {
						printf("               %s (%s, %u), %s", mn, i386_r32(mrd), d, i386_r32(mrs));
					}
				}
			}
		}
		else if (mod == 3) {
			*bn += 1;
			if (lgo) {
				printf("                              %s %s, %s", mn, i386_r16(mrd), i386_r16(mrs));
			}
			else {
				printf("                              %s %s, %s", mn, i386_r32(mrd), i386_r32(mrs));
			}
		}
		return 0;
	}
	return 1;
}

uint8_t i386_dec_r81(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7);
		uint8_t mrs = ((bin[*bn] >> 3) & 7);
		
		if (mod == 0 && lga) {
			if (mrd == 6) {
				*bn += 1;
				printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				printf("                     %s %s, (%u)", mn, i386_r8(mrs), d);
			}
			else {
				*bn += 1;
				printf("                              %s %s, (%s)", mn, i386_r8(mrs), i386_a16(mrd));
			}
		}
		else if (mod == 1 && lga) {
			*bn += 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			if (d & 128) {
				d = ~d + 1;
				printf("                        %s %s, (%s, -%u)", mn, i386_r8(mrs), i386_a16(mrd), d);
			}
			else {
				printf("                        %s %s, (%s, %u)", mn, i386_r8(mrs), i386_a16(mrd), d);
			}
		}
		else if (mod == 2 && lga) {
			*bn += 1;
			printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			if (d & 32768) {
				d = ~d + 1;
				printf("                     %s %s, (%s, -%u)", mn, i386_r8(mrs), i386_a16(mrd), d);
			}
			else {
				printf("                     %s %s, (%s, %u)", mn, i386_r8(mrs), i386_a16(mrd), d);
			}
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
					printf("               %s %s, (%u)", mn, i386_r8(mrs), d);
				}
				else if (i == 4) {
					*bn += 1;
					printf("                           %s %s, (%s)", mn, i386_r8(mrs), i386_r32(b));
				}
				else if (s) {
					*bn += 1;
					printf("                           %s %s, (%s, (%s, %u))", mn, i386_r8(mrs), i386_r32(b), i386_r32(i), i386_s8(s));
				}
				else {
					*bn += 1;
					printf("                           %s %s, (%s, (%s))", mn, i386_r8(mrs), i386_r32(b), i386_r32(i));
				}
			}
			else if (mrd == 5) {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("               %s %s, (%u)", mn, i386_r8(mrs), d);
			}
			else {
				*bn += 1;
				printf("                              %s %s, (%s)", mn, i386_r8(mrs), i386_r32(mrd));
			}
		}
		else if (mod == 1) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						printf("                        %s %s, (%s, -%u)", mn, i386_r8(mrs), i386_r32(b), d);
					}
					else {
						printf("                        %s %s, (%s, %u)", mn, i386_r8(mrs), i386_r32(b), d);
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						printf("                        %s %s, (%s, (%s, %u), -%u)", mn, i386_r8(mrs), i386_r32(b), i386_r32(i), i386_s8(s), d);
					}
					else {
						printf("                        %s %s, (%s, (%s, %u), %u)", mn, i386_r8(mrs), i386_r32(b), i386_r32(i), i386_s8(s), d);
					}
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						printf("                        %s %s, (%s, (%s), -%u)", mn, i386_r8(mrs), i386_r32(b), i386_r32(i), d);
					}
					else {
						printf("                        %s %s, (%s, (%s), %u)", mn, i386_r8(mrs), i386_r32(b), i386_r32(i), d);
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (d & 128) {
					d = ~d + 1;
					printf("                        %s %s, (%s, -%u)", mn, i386_r8(mrs), i386_r32(mrd), d);
				}
				else {
					printf("                        %s %s, (%s, %u)", mn, i386_r8(mrs), i386_r32(mrd), d);
				}
			}
		}
		else if (mod == 2) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						printf("               %s %s, (%s, -%u)", mn, i386_r8(mrs), i386_r32(b), d);
					}
					else {
						printf("               %s %s, (%s, %u)", mn, i386_r8(mrs), i386_r32(b), d);
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						printf("               %s %s, (%s, (%s, %u), -%u)", mn, i386_r8(mrs), i386_r32(b), i386_r32(i), i386_s8(s), d);
					}
					else {
						printf("               %s %s, (%s, (%s, %u), %u)", mn, i386_r8(mrs), i386_r32(b), i386_r32(i), i386_s8(s), d);
					}
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						printf("               %s %s, (%s, (%s), -%u)", mn, i386_r8(mrs), i386_r32(b), i386_r32(i), d);
					}
					else {
						printf("               %s %s, (%s, (%s), %u)", mn, i386_r8(mrs), i386_r32(b), i386_r32(i), d);
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (d & 2147483648) {
					d = ~d + 1;
					printf("               %s %s, (%s, -%u)", mn, i386_r8(mrs), i386_r32(mrd), d);
				}
				else {
					printf("               %s %s, (%s, %u)", mn, i386_r8(mrs), i386_r32(mrd), d);
				}
			}
		}
		else if (mod == 3) {
			*bn += 1;
			printf("                              %s %s, %s", mn, i386_r8(mrs), i386_r8(mrs), i386_r8(mrd));
		}
		return 0;
	}
	return 1;
}

uint8_t i386_dec_rg1(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7);
		uint8_t mrs = ((bin[*bn] >> 3) & 7);
		
		if (mod == 0 && lga) {
			if (mrd == 6) {
				*bn += 1;
				printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				if (lgo) {
					printf("                     %s %s, (%u)", mn, i386_r16(mrs), d);
				}
				else {
					printf("                     %s %s, (%u)", mn, i386_r32(mrs), d);
				}
			}
			else {
				*bn += 1;
				if (lgo) {
					printf("                              %s %s, (%s)", mn, i386_r16(mrs), i386_a16(mrd));
				}
				else {
					printf("                              %s %s, (%s)", mn, i386_r32(mrs), i386_a16(mrd));
				}
			}
		}
		else if (mod == 1 && lga) {
			*bn += 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			if (d & 128) {
				d = ~d + 1;
				if (lgo) {
					printf("                        %s %s, (%s, -%u)", mn, i386_r16(mrs), i386_a16(mrd), d);
				}
				else {
					printf("                        %s %s, (%s, -%u)", mn, i386_r32(mrs), i386_a16(mrd), d);
				}
			}
			else {
				if (lgo) {
					printf("                        %s %s, (%s, %u)", mn, i386_r16(mrs), i386_a16(mrd), d);
				}
				else {
					printf("                        %s %s, (%s, %u)", mn, i386_r32(mrs), i386_a16(mrd), d);
				}
			}
		}
		else if (mod == 2 && lga) {
			*bn += 1;
			printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			if (d & 32768) {
				d = ~d + 1;
				if (lgo) {
					printf("                     %s %s, (%s, -%u)", mn, i386_r16(mrs), i386_a16(mrd), d);
				}
				else {
					printf("                     %s %s, (%s, -%u)", mn, i386_r32(mrs), i386_a16(mrd), d);
				}
			}
			else {
				if (lgo) {
					printf("                     %s %s, (%s, %u)", mn, i386_r16(mrs), i386_a16(mrd), d);
				}
				else {
					printf("                     %s %s, (%s, %u)", mn, i386_r32(mrs), i386_a16(mrd), d);
				}
			}
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
					if (lgo) {
						printf("               %s %s, (%u)", mn, i386_r16(mrs), d);
					}
					else {
						printf("               %s %s, (%u)", mn, i386_r32(mrs), d);
					}
				}
				else if (i == 4) {
					*bn += 1;
					if (lgo) {
						printf("                           %s %s, (%s)", mn, i386_r16(mrs), i386_r32(b));
					}
					else {
						printf("                           %s %s, (%s)", mn, i386_r32(mrs), i386_r32(b));
					}
				}
				else if (s) {
					*bn += 1;
					if (lgo) {
						printf("                           %s %s, (%s, (%s, %u))", mn, i386_r16(mrs), i386_r32(b), i386_r32(i), i386_s8(s));
					}
					else {
						printf("                           %s %s, (%s, (%s, %u))", mn, i386_r32(mrs), i386_r32(b), i386_r32(i), i386_s8(s));
					}
				}
				else {
					*bn += 1;
					if (lgo) {
						printf("                           %s %s, (%s, (%s))", mn, i386_r16(mrs), i386_r32(b), i386_r32(i));
					}
					else {
						printf("                           %s %s, (%s, (%s))", mn, i386_r32(mrs), i386_r32(b), i386_r32(i));
					}
				}
			}
			else if (mrd == 5) {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					printf("               %s %s, (%u)", mn, i386_r16(mrs), d);
				}
				else {
					printf("               %s %s, (%u)", mn, i386_r32(mrs), d);
				}
			}
			else {
				*bn += 1;
				if (lgo) {
					printf("                              %s %s, (%s)", mn, i386_r16(mrs), i386_r32(mrd));
				}
				else {
					printf("                              %s %s, (%s)", mn, i386_r32(mrs), i386_r32(mrd));
				}
			}
		}
		else if (mod == 1) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							printf("                        %s %s, (%s, -%u)", mn, i386_r16(mrs), i386_r32(b), d);
						}
						else {
							printf("                        %s %s, (%s, -%u)", mn, i386_r32(mrs), i386_r32(b), d);
						}
					}
					else {
						if (lgo) {
							printf("                        %s %s, (%s, %u)", mn, i386_r16(mrs), i386_r32(b), d);
						}
						else {
							printf("                        %s %s, (%s, %u)", mn, i386_r32(mrs), i386_r32(b), d);
						}
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							printf("                        %s %s, (%s, (%s, %u), -%u)", mn, i386_r16(mrs), i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
						else {
							printf("                        %s %s, (%s, (%s, %u), -%u)", mn, i386_r32(mrs), i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
					}
					else {
						if (lgo) {
							printf("                        %s %s, (%s, (%s, %u), %u)", mn, i386_r16(mrs), i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
						else {
							printf("                        %s %s, (%s, (%s, %u), %u)", mn, i386_r32(mrs), i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
					}
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							printf("                        %s %s, (%s, (%s), -%u)", mn, i386_r16(mrs), i386_r32(b), i386_r32(i), d);
						}
						else {
							printf("                        %s %s, (%s, (%s), -%u)", mn, i386_r32(mrs), i386_r32(b), i386_r32(i), d);
						}
					}
					else {
						if (lgo) {
							printf("                        %s %s, (%s, (%s), %u)", mn, i386_r16(mrs), i386_r32(b), i386_r32(i), d);
						}
						else {
							printf("                        %s %s, (%s, (%s), %u)", mn, i386_r32(mrs), i386_r32(b), i386_r32(i), d);
						}
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						printf("                        %s %s, (%s, -%u)", mn, i386_r16(mrs), i386_r32(mrd), d);
					}
					else {
						printf("                        %s %s, (%s, -%u)", mn, i386_r32(mrs), i386_r32(mrd), d);
					}
				}
				else {
					if (lgo) {
						printf("                        %s %s, (%s, %u)", mn, i386_r16(mrs), i386_r32(mrd), d);
					}
					else {
						printf("                        %s %s, (%s, %u)", mn, i386_r32(mrs), i386_r32(mrd), d);
					}
				}
			}
		}
		else if (mod == 2) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							printf("               %s %s, (%s, -%u)", mn, i386_r16(mrs), i386_r32(b), d);
						}
						else {
							printf("               %s %s, (%s, -%u)", mn, i386_r32(mrs), i386_r32(b), d);
						}
					}
					else {
						if (lgo) {
							printf("               %s %s, (%s, %u)", mn, i386_r16(mrs), i386_r32(b), d);
						}
						else {
							printf("               %s %s, (%s, %u)", mn, i386_r32(mrs), i386_r32(b), d);
						}
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							printf("               %s %s, (%s, (%s, %u), -%u)", mn, i386_r16(mrs), i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
						else {
							printf("               %s %s, (%s, (%s, %u), -%u)", mn, i386_r32(mrs), i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
					}
					else {
						if (lgo) {
							printf("               %s %s, (%s, (%s, %u), %u)", mn, i386_r16(mrs), i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
						else {
							printf("               %s %s, (%s, (%s, %u), %u)", mn, i386_r32(mrs), i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
					}
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							printf("               %s %s, (%s, (%s), -%u)", mn, i386_r16(mrs), i386_r32(b), i386_r32(i), d);
						}
						else {
							printf("               %s %s, (%s, (%s), -%u)", mn, i386_r32(mrs), i386_r32(b), i386_r32(i), d);
						}
					}
					else {
						if (lgo) {
							printf("               %s %s, (%s, (%s), %u)", mn, i386_r16(mrs), i386_r32(b), i386_r32(i), d);
						}
						else {
							printf("               %s %s, (%s, (%s), %u)", mn, i386_r32(mrs), i386_r32(b), i386_r32(i), d);
						}
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						printf("               %s %s, (%s, -%u)", mn, i386_r16(mrs), i386_r32(mrd), d);
					}
					else {
						printf("               %s %s, (%s, -%u)", mn, i386_r32(mrs), i386_r32(mrd), d);
					}
				}
				else {
					if (lgo) {
						printf("               %s %s, (%s, %u)", mn, i386_r16(mrs), i386_r32(mrd), d);
					}
					else {
						printf("               %s %s, (%s, %u)", mn, i386_r32(mrs), i386_r32(mrd), d);
					}
				}
			}
		}
		else if (mod == 3) {
			*bn += 1;
			if (lgo) {
				printf("                              %s %s, %s", mn, i386_r16(mrs), i386_r16(mrd));
			}
			else {
				printf("                              %s %s, %s", mn, i386_r32(mrs), i386_r32(mrd));
			}
		}
		return 0;
	}
	return 1;
}

uint8_t i386_dec_ral(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("                  %02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn += 1;
		printf("            %s al, %u", mn, k);
		return 0;
	}
	return 1;
}

uint8_t i386_dec_rax(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		if (lgo) {
			printf("                  %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			printf("         %s ax, %u", mn, k);
		}
		else {
			printf("                  %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			printf("   %s eax, %u", mn, k);
		}
		return 0;
	}
	return 1;
}

uint8_t i386_dec_k80(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo) {
	if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			if (mrd == 6) {
				*bn += 1;
				printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				printf("      %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				printf("            %sb (%u), %u", mn, d, k);
			}
			else {
				*bn += 1;
				printf("               %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				printf("            %sb (%s), %u", mn, i386_a16(mrd), k);
			}
		}
		else {
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
					printf("%02x ", bin[*bn]);
					uint8_t k = bin[*bn];
					*bn += 1;
					printf("            %sb (%u), %u", mn, d, k);
				}
				else if (i == 4) {
					*bn += 1;
					printf("            %02x ", bin[*bn]);
					uint8_t k = bin[*bn];
					*bn += 1;
					printf("            %sb (%s), %u", mn, i386_r32(b), k);
				}
				else if (s) {
					*bn += 1;
					printf("            %02x ", bin[*bn]);
					uint8_t k = bin[*bn];
					*bn += 1;
					printf("            %sb (%s, (%s, %u)), %u", mn, i386_r32(b), i386_r32(i), i386_s8(s), k);
				}
				else {
					*bn += 1;
					printf("            %02x ", bin[*bn]);
					uint8_t k = bin[*bn];
					*bn += 1;
					printf("            %sb (%s, (%s)), %u", mn, i386_r32(b), i386_r32(i), k);
				}
			}
			else if (mrd == 5) {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("%02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				printf("            %sb (%u), %u", mn, d, k);
			}
			else {
				*bn += 1;
				printf("               %02x ", bin[*bn], bin[*bn + 1]);
				uint8_t k = bin[*bn];
				*bn += 1;
				printf("            %sb (%s), %u", mn, i386_r32(mrd), k);
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			*bn += 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			printf("         %02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn += 1;
			if (d & 128) {
				d = ~d + 1;
				printf("            %sb (%s, -%u), %u", mn, i386_a16(mrd), d, k);
			}
			else {
				printf("            %sb (%s, %u), %u", mn, i386_a16(mrd), d, k);
			}
		}
		else {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					printf("         %02x ", bin[*bn]);
					uint8_t k = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						printf("            %sb (%s, -%u), %u", mn, i386_r32(b), d, k);
					}
					else {
						printf("            %sb (%s, %u), %u", mn, i386_r32(b), d, k);
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
					if (d & 128) {
						d = ~d + 1;
						printf("            %sb (%s, (%s, %u), -%u), %u", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, k);
					}
					else {
						printf("            %sb (%s, (%s, %u), %u), %u", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, k);
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
					if (d & 128) {
						d = ~d + 1;
						printf("            %sb (%s, (%s), -%u), %u", mn, i386_r32(b), i386_r32(i), d, k);
					}
					else {
						printf("            %sb (%s, (%s), %u), %u", mn, i386_r32(b), i386_r32(i), d, k);
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
				if (d & 128) {
					d = ~d + 1;
					printf("            %sb (%s, -%u), %u", mn, i386_r32(mrd), d, k);
				}
				else {
					printf("            %sb (%s, %u), %u", mn, i386_r32(mrd), d, k);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			*bn += 1;
			printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			printf("      %02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn += 1;
			if (d & 32768) {
				d = ~d + 1;
				printf("            %sb (%s, -%u), %u", mn, i386_a16(mrd), d, k);
			}
			else {
				printf("            %sb (%s, %u), %u", mn, i386_a16(mrd), d, k);
			}
		}
		else {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("%02x ", bin[*bn]);
					uint8_t k = bin[*bn];
					*bn += 1;
					if (d & 2147483648) {
						d = ~d + 1;
						printf("            %sb (%s, -%u), %u", mn, i386_r32(b), d, k);
					}
					else {
						printf("            %sb (%s, %u), %u", mn, i386_r32(b), d, k);
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
					if (d & 2147483648) {
						d = ~d + 1;
						printf("            %sb (%s, (%s, %u), -%u), %u", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, k);
					}
					else {
						printf("            %sb (%s, (%s, %u), %u), %u", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, k);
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
					if (d & 2147483648) {
						d = ~d + 1;
						printf("            %sb (%s, (%s), -%u), %u", mn, i386_r32(b), i386_r32(i), d, k);
					}
					else {
						printf("            %sb (%s, (%s), %u), %u", mn, i386_r32(b), i386_r32(i), d, k);
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
				if (d & 2147483648) {
					d = ~d + 1;
					printf("            %sb (%s, -%u), %u", mn, i386_r32(mrd), d, k);
				}
				else {
					printf("            %sb (%s, %u), %u", mn, i386_r32(mrd), d, k);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		*bn += 1;
		printf("               %02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn += 1;
		printf("            %sb %s, %u", mn, i386_r8(mrd), k);
		return 0;
	}
	return 1;
}

uint8_t i386_dec_imm(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo) {
	if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			if (mrd == 6) {
				*bn += 1;
				printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				if (lgo) {
					printf("      %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (%u), %u", mn, d, k);
				}
				else {
					printf("      %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (%u), %u", mn, d, k);
				}
			}
			else {
				*bn += 1;
				if (lgo) {
					printf("               %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (%s), %u", mn, i386_a16(mrd), k);
				}
				else {
					printf("               %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (%s), %u", mn, i386_a16(mrd), k);
				}
			}
		}
		else {
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
					if (lgo) {
						printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
						uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
						*bn += 2;
						printf("         %sw (%u), %u", mn, d, k);
					}
					else {
						printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
						uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
						*bn += 4;
						printf("   %sd (%u), %u", mn, d, k);
					}
				}
				else if (i == 4) {
					*bn += 1;
					if (lgo) {
						printf("            %02x %02x ", bin[*bn], bin[*bn + 1]);
						uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
						*bn += 2;
						printf("         %sw (%s), %u", mn, i386_r32(b), k);
					}
					else {
						printf("            %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
						uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
						*bn += 4;
						printf("   %sd (%s), %u", mn, i386_r32(b), k);
					}
				}
				else if (s) {
					*bn += 1;
					if (lgo) {
						printf("            %02x %02x ", bin[*bn], bin[*bn + 1]);
						uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
						*bn += 2;
						printf("         %sw (%s, (%s, %u)), %u", mn, i386_r32(b), i386_r32(i), i386_s8(s), k);
					}
					else {
						printf("            %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
						uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
						*bn += 4;
						printf("   %sd (%s, (%s, %u)), %u", mn, i386_r32(b), i386_r32(i), i386_s8(s), k);
					}
				}
				else {
					*bn += 1;
					if (lgo) {
						printf("            %02x %02x ", bin[*bn], bin[*bn + 1]);
						uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
						*bn += 2;
						printf("         %sw (%s, (%s)), %u", mn, i386_r32(b), i386_r32(i), k);
					}
					else {
						printf("            %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
						uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
						*bn += 4;
						printf("   %sd (%s, (%s)), %u", mn, i386_r32(b), i386_r32(i), k);
					}
				}
			}
			else if (mrd == 5) {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (%u), %u", mn, d, k);
				}
				else {
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (%u), %u", mn, d, k);
				}
			}
			else {
				*bn += 1;
				if (lgo) {
					printf("               %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (%s), %u", mn, i386_r32(mrd), k);
				}
				else {
					printf("               %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (%s), %u", mn, i386_r32(mrd), k);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			*bn += 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			if (d & 128) {
				d = ~d + 1;
				if (lgo) {
					printf("         %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (%s, -%u), %u", mn, i386_a16(mrd), d, k);
				}
				else {
					printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (%s, -%u), %u", mn, i386_a16(mrd), d, k);
				}
			}
			else {
				if (lgo) {
					printf("         %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (%s, %u), %u", mn, i386_a16(mrd), d, k);
				}
				else {
					printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (%s, %u), %u", mn, i386_a16(mrd), d, k);
				}
			}
		}
		else {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							printf("         %02x %02x ", bin[*bn], bin[*bn + 1]);
							uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
							*bn += 2;
							printf("         %sw (%s, -%u), %u", mn, i386_r32(b), d, k);
						}
						else {
							printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
							uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
							*bn += 4;
							printf("   %sd (%s, -%u), %u", mn, i386_r32(b), d, k);
						}
					}
					else {
						if (lgo) {
							printf("         %02x %02x ", bin[*bn], bin[*bn + 1]);
							uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
							*bn += 2;
							printf("         %sw (%s, %u), %u", mn, i386_r32(b), d, k);
						}
						else {
							printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
							uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
							*bn += 4;
							printf("   %sd (%s, %u), %u", mn, i386_r32(b), d, k);
						}
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							printf("         %02x %02x ", bin[*bn], bin[*bn + 1]);
							uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
							*bn += 2;
							printf("         %sw (%s, (%s, %u), -%u), %u", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, k);
						}
						else {
							printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
							uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
							*bn += 4;
							printf("   %sd (%s, (%s, %u), -%u), %u", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, k);
						}
					}
					else {
						if (lgo) {
							printf("         %02x %02x ", bin[*bn], bin[*bn + 1]);
							uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
							*bn += 2;
							printf("         %sw (%s, (%s, %u), %u), %u", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, k);
						}
						else {
							printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
							uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
							*bn += 4;
							printf("   %sd (%s, (%s, %u), %u), %u", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, k);
						}
					}
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							printf("         %02x %02x ", bin[*bn], bin[*bn + 1]);
							uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
							*bn += 2;
							printf("         %sw (%s, (%s), -%u), %u", mn, i386_r32(b), i386_r32(i), d, k);
						}
						else {
							printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
							uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
							*bn += 4;
							printf("   %sd (%s, (%s), -%u), %u", mn, i386_r32(b), i386_r32(i), d, k);
						}
					}
					else {
						if (lgo) {
							printf("         %02x %02x ", bin[*bn], bin[*bn + 1]);
							uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
							*bn += 2;
							printf("         %sw (%s, (%s), %u), %u", mn, i386_r32(b), i386_r32(i), d, k);
						}
						else {
							printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
							uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
							*bn += 4;
							printf("   %sd (%s, (%s), %u), %u", mn, i386_r32(b), i386_r32(i), d, k);
						}
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						printf("         %02x %02x ", bin[*bn], bin[*bn + 1]);
						uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
						*bn += 2;
						printf("         %sw (%s, -%u), %u", mn, i386_r32(mrd), d, k);
					}
					else {
						printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
						uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
						*bn += 4;
						printf("   %sd (%s, -%u), %u", mn, i386_r32(mrd), d, k);
					}
				}
				else {
					if (lgo) {
						printf("         %02x %02x ", bin[*bn], bin[*bn + 1]);
						uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
						*bn += 2;
						printf("         %sw (%s, %u), %u", mn, i386_r32(mrd), d, k);
					}
					else {
						printf("         %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
						uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
						*bn += 4;
						printf("   %sd (%s, %u), %u", mn, i386_r32(mrd), d, k);
					}
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			*bn += 1;
			printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			if (d & 32768) {
				d = ~d + 1;
				if (lgo) {
					printf("      %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (%s, -%u), %u", mn, i386_a16(mrd), d, k);
				}
				else {
					printf("      %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (%s, -%u), %u", mn, i386_a16(mrd), d, k);
				}
			}
			else {
				if (lgo) {
					printf("      %02x %02x ", bin[*bn], bin[*bn + 1]);
					uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
					*bn += 2;
					printf("         %sw (%s, %u), %u", mn, i386_a16(mrd), d, k);
				}
				else {
					printf("      %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("   %sd (%s, %u), %u", mn, i386_a16(mrd), d, k);
				}
			}
		}
		else {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
							uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
							*bn += 2;
							printf("         %sw (%s, -%u), %u", mn, i386_r32(b), d, k);
						}
						else {
							printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
							uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
							*bn += 4;
							printf("   %sd (%s, -%u), %u", mn, i386_r32(b), d, k);
						}
					}
					else {
						if (lgo) {
							printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
							uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
							*bn += 2;
							printf("         %sw (%s, %u), %u", mn, i386_r32(b), d, k);
						}
						else {
							printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
							uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
							*bn += 4;
							printf("   %sd (%s, %u), %u", mn, i386_r32(b), d, k);
						}
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
							uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
							*bn += 2;
							printf("         %sw (%s, (%s, %u), -%u), %u", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, k);
						}
						else {
							printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
							uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
							*bn += 4;
							printf("   %sd (%s, (%s, %u), -%u), %u", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, k);
						}
					}
					else {
						if (lgo) {
							printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
							uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
							*bn += 2;
							printf("         %sw (%s, (%s, %u), %u), %u", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, k);
						}
						else {
							printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
							uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
							*bn += 4;
							printf("   %sd (%s, (%s, %u), %u), %u", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, k);
						}
					}
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
							uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
							*bn += 2;
							printf("         %sw (%s, (%s), -%u), %u", mn, i386_r32(b), i386_r32(i), d, k);
						}
						else {
							printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
							uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
							*bn += 4;
							printf("   %sd (%s, (%s), -%u), %u", mn, i386_r32(b), i386_r32(i), d, k);
						}
					}
					else {
						if (lgo) {
							printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
							uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
							*bn += 2;
							printf("         %sw (%s, (%s), %u), %u", mn, i386_r32(b), i386_r32(i), d, k);
						}
						else {
							printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
							uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
							*bn += 4;
							printf("   %sd (%s, (%s), %u), %u", mn, i386_r32(b), i386_r32(i), d, k);
						}
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
						uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
						*bn += 2;
						printf("         %sw (%s, -%u), %u", mn, i386_r32(mrd), d, k);
					}
					else {
						printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
						uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
						*bn += 4;
						printf("   %sd (%s, -%u), %u", mn, i386_r32(mrd), d, k);
					}
				}
				else {
					if (lgo) {
						printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
						uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
						*bn += 2;
						printf("         %sw (%s, %u), %u", mn, i386_r32(mrd), d, k);
					}
					else {
						printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
						uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
						*bn += 4;
						printf("   %sd (%s, %u), %u", mn, i386_r32(mrd), d, k);
					}
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		*bn += 1;
		if (lgo) {
			printf("               %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			printf("         %sw %s, %u", mn, i386_r16(mrd), k);
		}
		else {
			printf("               %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			printf("   %sd %s, %u", mn, i386_r32(mrd), k);
		}
		return 0;
	}
	return 1;
}

uint8_t i386_dec_k81(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo) {
	if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			if (mrd == 6) {
				*bn += 1;
				printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				printf("      %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				if (lgo) {
					printf("            %sw (%u), %u", mn, d, k);
				}
				else {
					printf("            %sd (%u), %u", mn, d, k);
				}
			}
			else {
				*bn += 1;
				printf("               %02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				if (lgo) {
					printf("            %sw (%s), %u", mn, i386_a16(mrd), k);
				}
				else {
					printf("            %sd (%s), %u", mn, i386_a16(mrd), k);
				}
			}
		}
		else {
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
					printf("%02x ", bin[*bn]);
					uint8_t k = bin[*bn];
					*bn += 1;
					if (lgo) {
						printf("            %sw (%u), %u", mn, d, k);
					}
					else {
						printf("            %sd (%u), %u", mn, d, k);
					}
				}
				else if (i == 4) {
					*bn += 1;
					printf("            %02x ", bin[*bn]);
					uint8_t k = bin[*bn];
					*bn += 1;
					if (lgo) {
						printf("            %sw (%s), %u", mn, i386_r32(b), k);
					}
					else {
						printf("            %sd (%s), %u", mn, i386_r32(b), k);
					}
				}
				else if (s) {
					*bn += 1;
					printf("            %02x ", bin[*bn]);
					uint8_t k = bin[*bn];
					*bn += 1;
					if (lgo) {
						printf("            %sw (%s, (%s, %u)), %u", mn, i386_r32(b), i386_r32(i), i386_s8(s), k);
					}
					else {
						printf("            %sd (%s, (%s, %u)), %u", mn, i386_r32(b), i386_r32(i), i386_s8(s), k);
					}
				}
				else {
					*bn += 1;
					printf("            %02x ", bin[*bn]);
					uint8_t k = bin[*bn];
					*bn += 1;
					if (lgo) {
						printf("            %sw (%s, (%s)), %u", mn, i386_r32(b), i386_r32(i), k);
					}
					else {
						printf("            %sd (%s, (%s)), %u", mn, i386_r32(b), i386_r32(i), k);
					}
				}
			}
			else if (mrd == 5) {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("%02x ", bin[*bn]);
				uint8_t k = bin[*bn];
				*bn += 1;
				if (lgo) {
					printf("            %sw (%u), %u", mn, d, k);
				}
				else {
					printf("            %sd (%u), %u", mn, d, k);
				}
			}
			else {
				*bn += 1;
				printf("               %02x ", bin[*bn], bin[*bn + 1]);
				uint8_t k = bin[*bn];
				*bn += 1;
				if (lgo) {
					printf("            %sw (%s), %u", mn, i386_r32(mrd), k);
				}
				else {
					printf("            %sd (%s), %u", mn, i386_r32(mrd), k);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			*bn += 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			printf("         %02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn += 1;
			if (d & 128) {
				d = ~d + 1;
				if (lgo) {
					printf("            %sw (%s, -%u), %u", mn, i386_a16(mrd), d, k);
				}
				else {
					printf("            %sd (%s, -%u), %u", mn, i386_a16(mrd), d, k);
				}
			}
			else {
				if (lgo) {
					printf("            %sw (%s, %u), %u", mn, i386_a16(mrd), d, k);
				}
				else {
					printf("            %sd (%s, %u), %u", mn, i386_a16(mrd), d, k);
				}
			}
		}
		else {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					printf("         %02x ", bin[*bn]);
					uint8_t k = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							printf("            %sw (%s, -%u), %u", mn, i386_r32(b), d, k);
						}
						else {
							printf("            %sd (%s, -%u), %u", mn, i386_r32(b), d, k);
						}
					}
					else {
						if (lgo) {
							printf("            %sw (%s, %u), %u", mn, i386_r32(b), d, k);
						}
						else {
							printf("            %sd (%s, %u), %u", mn, i386_r32(b), d, k);
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
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							printf("            %sw (%s, (%s, %u), -%u), %u", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, k);
						}
						else {
							printf("            %sd (%s, (%s, %u), -%u), %u", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, k);
						}
					}
					else {
						if (lgo) {
							printf("            %sw (%s, (%s, %u), %u), %u", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, k);
						}
						else {
							printf("            %sd (%s, (%s, %u), %u), %u", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, k);
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
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							printf("            %sw (%s, (%s), -%u), %u", mn, i386_r32(b), i386_r32(i), d, k);
						}
						else {
							printf("            %sd (%s, (%s), -%u), %u", mn, i386_r32(b), i386_r32(i), d, k);
						}
					}
					else {
						if (lgo) {
							printf("            %sw (%s, (%s), %u), %u", mn, i386_r32(b), i386_r32(i), d, k);
						}
						else {
							printf("            %sd (%s, (%s), %u), %u", mn, i386_r32(b), i386_r32(i), d, k);
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
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						printf("            %sw (%s, -%u), %u", mn, i386_r32(mrd), d, k);
					}
					else {
						printf("            %sd (%s, -%u), %u", mn, i386_r32(mrd), d, k);
					}
				}
				else {
					if (lgo) {
						printf("            %sw (%s, %u), %u", mn, i386_r32(mrd), d, k);
					}
					else {
						printf("            %sd (%s, %u), %u", mn, i386_r32(mrd), d, k);
					}
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			*bn += 1;
			printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			printf("      %02x ", bin[*bn]);
			uint8_t k = bin[*bn];
			*bn += 1;
			if (d & 32768) {
				d = ~d + 1;
				if (lgo) {
					printf("            %sw (%s, -%u), %u", mn, i386_a16(mrd), d, k);
				}
				else {
					printf("            %sd (%s, -%u), %u", mn, i386_a16(mrd), d, k);
				}
			}
			else {
				if (lgo) {
					printf("            %sw (%s, %u), %u", mn, i386_a16(mrd), d, k);
				}
				else {
					printf("            %sd (%s, %u), %u", mn, i386_a16(mrd), d, k);
				}
			}
		}
		else {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					printf("%02x ", bin[*bn]);
					uint8_t k = bin[*bn];
					*bn += 1;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							printf("            %sw (%s, -%u), %u", mn, i386_r32(b), d, k);
						}
						else {
							printf("            %sd (%s, -%u), %u", mn, i386_r32(b), d, k);
						}
					}
					else {
						if (lgo) {
							printf("            %sw (%s, %u), %u", mn, i386_r32(b), d, k);
						}
						else {
							printf("            %sd (%s, %u), %u", mn, i386_r32(b), d, k);
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
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							printf("            %sw (%s, (%s, -%u), %u), %u", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, k);
						}
						else {
							printf("            %sd (%s, (%s, -%u), %u), %u", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, k);
						}
					}
					else {
						if (lgo) {
							printf("            %sw (%s, (%s, %u), %u), %u", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, k);
						}
						else {
							printf("            %sd (%s, (%s, %u), %u), %u", mn, i386_r32(b), i386_r32(i), i386_s8(s), d, k);
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
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							printf("            %sw (%s, (%s), -%u), %u", mn, i386_r32(b), i386_r32(i), d, k);
						}
						else {
							printf("            %sd (%s, (%s), -%u), %u", mn, i386_r32(b), i386_r32(i), d, k);
						}
					}
					else {
						if (lgo) {
							printf("            %sw (%s, (%s), %u), %u", mn, i386_r32(b), i386_r32(i), d, k);
						}
						else {
							printf("            %sd (%s, (%s), %u), %u", mn, i386_r32(b), i386_r32(i), d, k);
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
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						printf("            %sw (%s, -%u), %u", mn, i386_r32(mrd), d, k);
					}
					else {
						printf("            %sd (%s, -%u), %u", mn, i386_r32(mrd), d, k);
					}
				}
				else {
					if (lgo) {
						printf("            %sw (%s, %u), %u", mn, i386_r32(mrd), d, k);
					}
					else {
						printf("            %sd (%s, %u), %u", mn, i386_r32(mrd), d, k);
					}
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		*bn += 1;
		printf("               %02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn += 1;
		if (lgo) {
			printf("            %sw %s, %u", mn, i386_r16(mrd), k);
		}
		else {
			printf("            %sd %s, %u", mn, i386_r32(mrd), k);
		}
		return 0;
	}
	return 1;
}

uint8_t i386_dec_stck(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo) {
	if ((bin[*bn] & 248) == op) {
		printf("%02x ", bin[*bn]);
		uint8_t reg = (bin[*bn] & 7); 
		*bn += 1;
		
		if (lgo) {
			printf("                                 %sw %s", mn, i386_r16(reg));
		}
		else {
			printf("                                 %s %s", mn, i386_r32(reg));
		}
		return 0;
	}
	return 1;
}

uint8_t i386_dec_mvp(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo) {
	if ((bin[*bn] & 248) == op) {
		printf("%02x ", bin[*bn]);
		uint8_t reg = bin[*bn] & 7;
		*bn += 1;
		
		printf("                  %02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn += 1;
		printf("            %s %s, %u", mn, i386_r8(reg), k);
		
		return 0;
	}
	else if ((bin[*bn] & 248) == op + 8) {
		printf("%02x ", bin[*bn]);
		uint8_t reg = bin[*bn] & 7;
		*bn += 1;
		
		if (lgo) {
			printf("                  %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			printf("         %s %s, %u", mn, i386_r16(reg), k);
		}
		else {
			printf("                  %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			printf("   %s %s, %u", mn, i386_r32(reg), k);
		}
		return 0;
	}
	return 1;
}

uint8_t i386_dec_op_imm(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		
		if (lgo) {
			printf("                  %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			printf("         %sw %u", mn, k);
		}
		else {
			printf("                  %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			printf("   %s %u", mn, k);
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
			printf("            %sw %u", mn, k);
		}
		else {
			printf("            %s %u", mn, k);
		}
		return 0;
	}
	return 1;
}

uint8_t i386_dec_blnk(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo) {
	if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			if (mrd == 6) {
				*bn += 1;
				printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				if (lgo) {
					printf("                     %sw (%u)", mn, d);
				}
				else {
					printf("                     %s (%u)", mn, d);
				}
			}
			else {
				*bn += 1;
				if (lgo) {
					printf("                              %sw (%s)", mn, i386_a16(mrd));
				}
				else {
					printf("                              %s (%s)", mn, i386_a16(mrd));
				}
			}
		}
		else {
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
					if (lgo) {
						printf("               %sw (%u)", mn, d);
					}
					else {
						printf("               %s (%u)", mn, d);
					}
				}
				else if (i == 4) {
					*bn += 1;
					if (lgo) {
						printf("                           %sw (%s)", mn, i386_r32(b));
					}
					else {
						printf("                           %s (%s)", mn, i386_r32(b));
					}
				}
				else if (s) {
					*bn += 1;
					if (lgo) {
						printf("                           %sw (%s, (%s, %u))", mn, i386_r32(b), i386_r32(i), i386_s8(s));
					}
					else {
						printf("                           %s (%s, (%s, %u))", mn, i386_r32(b), i386_r32(i), i386_s8(s));
					}
				}
				else {
					*bn += 1;
					if (lgo) {
						printf("                           %sw (%s, (%s))", mn, i386_r32(b), i386_r32(i));
					}
					else {
						printf("                           %s (%s, (%s))", mn, i386_r32(b), i386_r32(i));
					}
				}
			}
			else if (mrd == 5) {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					printf("               %sw (%u)", mn, d);
				}
				else {
					printf("               %sd (%u)", mn, d);
				}
			}
			else {
				*bn += 1;
				if (lgo) {
					printf("                              %sw (%s)", mn, i386_r32(mrd));
				}
				else {
					printf("                              %s (%s)", mn, i386_r32(mrd));
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			*bn += 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			if (d & 128) {
				d = ~d + 1;
				if (lgo) {
					printf("                        %sw (%s, %u)", mn, i386_a16(mrd), d);
				}
				else {
					printf("                        %s (%s, %u)", mn, i386_a16(mrd), d);
				}
			}
			else {
				if (lgo) {
					printf("                        %sw (%s, %u)", mn, i386_a16(mrd), d);
				}
				else {
					printf("                        %s (%s, %u)", mn, i386_a16(mrd), d);
				}
			}
		}
		else {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							printf("                        %sw (%s, -%u)", mn, i386_r32(b), d);
						}
						else {
							printf("                        %s (%s, -%u)", mn, i386_r32(b), d);
						}
					}
					else {
						if (lgo) {
							printf("                        %sw (%s, %u)", mn, i386_r32(b), d);
						}
						else {
							printf("                        %s (%s, %u)", mn, i386_r32(b), d);
						}
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							printf("                        %sw (%s, (%s, %u), -%u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
						else {
							printf("                        %s (%s, (%s, %u), -%u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
					}
					else {
						if (lgo) {
							printf("                        %sw (%s, (%s, %u), %u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
						else {
							printf("                        %s (%s, (%s, %u), %u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
					}
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							printf("                        %sw (%s, (%s), -%u)", mn, i386_r32(b), i386_r32(i), d);
						}
						else {
							printf("                        %s (%s, (%s), -%u)", mn, i386_r32(b), i386_r32(i), d);
						}
					}
					else {
						if (lgo) {
							printf("                        %sw (%s, (%s), %u)", mn, i386_r32(b), i386_r32(i), d);
						}
						else {
							printf("                        %s (%s, (%s), %u)", mn, i386_r32(b), i386_r32(i), d);
						}
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						printf("                        %sw (%s, -%u)", mn, i386_r32(mrd), d);
					}
					else {
						printf("                        %s (%s, -%u)", mn, i386_r32(mrd), d);
					}
				}
				else {
					if (lgo) {
						printf("                        %sw (%s, %u)", mn, i386_r32(mrd), d);
					}
					else {
						printf("                        %s (%s, %u)", mn, i386_r32(mrd), d);
					}
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			*bn += 1;
			printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			if (d & 32768) {
				d = ~d + 1;
				if (lgo) {
					printf("                     %sw (%s, -%u)", mn, i386_a16(mrd), d);
				}
				else {
					printf("                     %s (%s, -%u)", mn, i386_a16(mrd), d);
				}
			}
			else {
				if (lgo) {
					printf("                     %sw (%s, %u)", mn, i386_a16(mrd), d);
				}
				else {
					printf("                     %s (%s, %u)", mn, i386_a16(mrd), d);
				}
			}
		}
		else {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							printf("               %sw (%s, -%u)", mn, i386_r32(b), d);
						}
						else {
							printf("               %s (%s, -%u)", mn, i386_r32(b), d);
						}
					}
					else {
						if (lgo) {
							printf("               %sw (%s, %u)", mn, i386_r32(b), d);
						}
						else {
							printf("               %s (%s, %u)", mn, i386_r32(b), d);
						}
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							printf("               %sw (%s, (%s, %u), -%u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
						else {
							printf("               %s (%s, (%s, %u), -%u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
					}
					else {
						if (lgo) {
							printf("               %sw (%s, (%s, %u), %u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
						else {
							printf("               %s (%s, (%s, %u), %u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
					}
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							printf("               %sw (%s, (%s), -%u)", mn, i386_r32(b), i386_r32(i), d);
						}
						else {
							printf("               %s (%s, (%s), -%u)", mn, i386_r32(b), i386_r32(i), d);
						}
					}
					else {
						if (lgo) {
							printf("               %sw (%s, (%s), %u)", mn, i386_r32(b), i386_r32(i), d);
						}
						else {
							printf("               %s (%s, (%s), %u)", mn, i386_r32(b), i386_r32(i), d);
						}
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						printf("               %sw (%s, -%u)", mn, i386_r32(mrd), d);
					}
					else {
						printf("               %s (%s, -%u)", mn, i386_r32(mrd), d);
					}
				}
				else {
					if (lgo) {
						printf("               %sw (%s, %u)", mn, i386_r32(mrd), d);
					}
					else {
						printf("               %s (%s, %u)", mn, i386_r32(mrd), d);
					}
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		*bn += 1;
		if (lgo) {
			printf("                           %sw %s", mn, i386_r16(mrd));
		}
		else {
			printf("                           %s %s", mn, i386_r32(mrd));
		}
		return 0;
	}
	return 1;
}

uint8_t i386_dec_alnk(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo) {
	if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			if (mrd == 6) {
				*bn += 1;
				printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				printf("                     %sb (%u)", mn, d);
			}
			else {
				*bn += 1;
				printf("                              %sb (%s)", mn, i386_a16(mrd));
			}
		}
		else {
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
					printf("               %sb (%u)", mn, d);
				}
				else if (i == 4) {
					*bn += 1;
					printf("                           %sb (%s)", mn, i386_r32(b));
				}
				else if (s) {
					*bn += 1;
					printf("                           %sb (%s, (%s, %u))", mn, i386_r32(b), i386_r32(i), i386_s8(s));
				}
				else {
					*bn += 1;
					printf("                           %sb (%s, (%s))", mn, i386_r32(b), i386_r32(i));
				}
			}
			else if (mrd == 5) {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("               %sb (%u)", mn, d);
			}
			else {
				*bn += 1;
				printf("                              %sb (%s)", mn, i386_r32(mrd));
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			*bn += 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			if (d & 128) {
				d = ~d + 1;
				printf("                        %sb (%s, -%u)", mn, i386_a16(mrd), d);
			}
			else {
				printf("                        %sb (%s, %u)", mn, i386_a16(mrd), d);
			}
		}
		else {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						printf("                        %sb (%s, -%u)", mn, i386_r32(b), d);
					}
					else {
						printf("                        %sb (%s, %u)", mn, i386_r32(b), d);
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						printf("                        %sb (%s, (%s, %u), -%u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
					}
					else {
						printf("                        %sb (%s, (%s, %u), %u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
					}
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						printf("                        %sb (%s, (%s), -%u)", mn, i386_r32(b), i386_r32(i), d);
					}
					else {
						printf("                        %sb (%s, (%s), %u)", mn, i386_r32(b), i386_r32(i), d);
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (d & 128) {
					d = ~d + 1;
					printf("                        %sb (%s, -%u)", mn, i386_r32(mrd), d);
				}
				else {
					printf("                        %sb (%s, %u)", mn, i386_r32(mrd), d);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			*bn += 1;
			printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			if (d & 32768) {
				d = ~d + 1;
				printf("                     %sb (%s, -%u)", mn, i386_a16(mrd), d);
			}
			else {
				printf("                     %sb (%s, %u)", mn, i386_a16(mrd), d);
			}
		}
		else {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						printf("               %sb (%s, -%u)", mn, i386_r32(b), d);
					}
					else {
						printf("               %sb (%s, %u)", mn, i386_r32(b), d);
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						printf("               %sb (%s, (%s, %u), -%u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
					}
					else {
						printf("               %sb (%s, (%s, %u), %u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
					}
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						printf("               %sb (%s, (%s), -%u)", mn, i386_r32(b), i386_r32(i), d);
					}
					else {
						printf("               %sb (%s, (%s), %u)", mn, i386_r32(b), i386_r32(i), d);
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (d & 2147483648) {
					d = ~d + 1;
					printf("               %sb (%s, -%u)", mn, i386_r32(mrd), d);
				}
				else {
					printf("               %sb (%s, %u)", mn, i386_r32(mrd), d);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		*bn += 1;
		printf("                           %s %s", mn, i386_r8(mrd));
		return 0;
	}
	else if (bin[*bn] == op0 + 1 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			if (mrd == 6) {
				*bn += 1;
				printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				if (lgo) {
					printf("                     %sw (%u)", mn, d);
				}
				else {
					printf("                     %sd (%u)", mn, d);
				}
			}
			else {
				*bn += 1;
				if (lgo) {
					printf("                              %sw (%s)", mn, i386_a16(mrd));
				}
				else {
					printf("                              %sd (%s)", mn, i386_a16(mrd));
				}
			}
		}
		else {
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
					if (lgo) {
						printf("               %sw (%u)", mn, d);
					}
					else {
						printf("               %sd (%u)", mn, d);
					}
				}
				else if (i == 4) {
					*bn += 1;
					if (lgo) {
						printf("                           %sw (%s)", mn, i386_r32(b));
					}
					else {
						printf("                           %sd (%s)", mn, i386_r32(b));
					}
				}
				else if (s) {
					*bn += 1;
					if (lgo) {
						printf("                           %sw (%s, (%s, %u))", mn, i386_r32(b), i386_r32(i), i386_s8(s));
					}
					else {
						printf("                           %sd (%s, (%s, %u))", mn, i386_r32(b), i386_r32(i), i386_s8(s));
					}
				}
				else {
					*bn += 1;
					if (lgo) {
						printf("                           %sw (%s, (%s))", mn, i386_r32(b), i386_r32(i));
					}
					else {
						printf("                           %sd (%s, (%s))", mn, i386_r32(b), i386_r32(i));
					}
				}
			}
			else if (mrd == 5) {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					printf("               %sw (%u)", mn, d);
				}
				else {
					printf("               %sd (%u)", mn, d);
				}
			}
			else {
				*bn += 1;
				if (lgo) {
					printf("                              %sw (%s)", mn, i386_r32(mrd));
				}
				else {
					printf("                              %sd (%s)", mn, i386_r32(mrd));
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 + 1 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			*bn += 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			if (d & 128) {
				d = ~d + 1;
				if (lgo) {
					printf("                        %sw (%s, -%u)", mn, i386_a16(mrd), d);
				}
				else {
					printf("                        %sd (%s, -%u)", mn, i386_a16(mrd), d);
				}
			}
			else {
				if (lgo) {
					printf("                        %sw (%s, %u)", mn, i386_a16(mrd), d);
				}
				else {
					printf("                        %sd (%s, %u)", mn, i386_a16(mrd), d);
				}
			}
		}
		else {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							printf("                        %sw (%s, -%u)", mn, i386_r32(b), d);
						}
						else {
							printf("                        %sd (%s, -%u)", mn, i386_r32(b), d);
						}
					}
					else {
						if (lgo) {
							printf("                        %sw (%s, %u)", mn, i386_r32(b), d);
						}
						else {
							printf("                        %sd (%s, %u)", mn, i386_r32(b), d);
						}
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							printf("                        %sw (%s, (%s, %u), -%u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
						else {
							printf("                        %sd (%s, (%s, %u), -%u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
					}
					else {
						if (lgo) {
							printf("                        %sw (%s, (%s, %u), %u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
						else {
							printf("                        %sd (%s, (%s, %u), %u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
					}
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							printf("                        %sw (%s, (%s), -%u)", mn, i386_r32(b), i386_r32(i), d);
						}
						else {
							printf("                        %sd (%s, (%s), -%u)", mn, i386_r32(b), i386_r32(i), d);
						}
					}
					else {
						if (lgo) {
							printf("                        %sw (%s, (%s), %u)", mn, i386_r32(b), i386_r32(i), d);
						}
						else {
							printf("                        %sd (%s, (%s), %u)", mn, i386_r32(b), i386_r32(i), d);
						}
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						printf("                        %sw (%s, -%u)", mn, i386_r32(mrd), d);
					}
					else {
						printf("                        %sd (%s, -%u)", mn, i386_r32(mrd), d);
					}
				}
				else {
					if (lgo) {
						printf("                        %sw (%s, %u)", mn, i386_r32(mrd), d);
					}
					else {
						printf("                        %sd (%s, %u)", mn, i386_r32(mrd), d);
					}
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 + 1 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			*bn += 1;
			printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			if (d & 32768) {
				d = ~d + 1;
				if (lgo) {
					printf("                     %sw (%s, -%u)", mn, i386_a16(mrd), d);
				}
				else {
					printf("                     %sd (%s, -%u)", mn, i386_a16(mrd), d);
				}
			}
			else {
				if (lgo) {
					printf("                     %sw (%s, %u)", mn, i386_a16(mrd), d);
				}
				else {
					printf("                     %sd (%s, %u)", mn, i386_a16(mrd), d);
				}
			}
		}
		else {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							printf("               %sw (%s, -%u)", mn, i386_r32(b), d);
						}
						else {
							printf("               %sd (%s, -%u)", mn, i386_r32(b), d);
						}
					}
					else {
						if (lgo) {
							printf("               %sw (%s, %u)", mn, i386_r32(b), d);
						}
						else {
							printf("               %sd (%s, %u)", mn, i386_r32(b), d);
						}
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							printf("               %sw (%s, (%s, %u), -%u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
						else {
							printf("               %sd (%s, (%s, %u), -%u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
					}
					else {
						if (lgo) {
							printf("               %sw (%s, (%s, %u), %u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
						else {
							printf("               %sd (%s, (%s, %u), %u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
					}
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							printf("               %sw (%s, (%s), -%u)", mn, i386_r32(b), i386_r32(i), d);
						}
						else {
							printf("               %sd (%s, (%s), -%u)", mn, i386_r32(b), i386_r32(i), d);
						}
					}
					else {
						if (lgo) {
							printf("               %sw (%s, (%s), %u)", mn, i386_r32(b), i386_r32(i), d);
						}
						else {
							printf("               %sd (%s, (%s), %u)", mn, i386_r32(b), i386_r32(i), d);
						}
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						printf("               %sw (%s, -%u)", mn, i386_r32(mrd), d);
					}
					else {
						printf("               %sd (%s, -%u)", mn, i386_r32(mrd), d);
					}
				}
				else {
					if (lgo) {
						printf("               %sw (%s, %u)", mn, i386_r32(mrd), d);
					}
					else {
						printf("               %sd (%s, %u)", mn, i386_r32(mrd), d);
					}
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 + 1 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		*bn += 1;
		if (lgo) {
			printf("                           %s %s", mn, i386_r16(mrd));
		}
		else {
			printf("                           %s %s", mn, i386_r32(mrd));
		}
		return 0;
	}
	return 1;
}

uint8_t i386_dec_mlnk(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo) {
	if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			if (mrd == 6) {
				*bn += 1;
				printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				printf("                     %sb ax, (%u)", mn, d);
			}
			else {
				*bn += 1;
				printf("                              %sb ax, (%s)", mn, i386_a16(mrd));
			}
		}
		else {
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
					printf("               %sb ax, (%u)", mn, d);
				}
				else if (i == 4) {
					*bn += 1;
					printf("                           %sb ax, (%s)", mn, i386_r32(b));
				}
				else if (s) {
					*bn += 1;
					printf("                           %sb ax, (%s, (%s, %u))", mn, i386_r32(b), i386_r32(i), i386_s8(s));
				}
				else {
					*bn += 1;
					printf("                           %sb ax, (%s, (%s))", mn, i386_r32(b), i386_r32(i));
				}
			}
			else if (mrd == 5) {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("               %sb ax, (%u)", mn, d);
			}
			else {
				*bn += 1;
				printf("                              %sb ax, (%s)", mn, i386_r32(mrd));
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			*bn += 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			if (d & 128) {
				d = ~d + 1;
				printf("                        %sb ax, (%s, -%u)", mn, i386_a16(mrd), d);
			}
			else {
				printf("                        %sb ax, (%s, %u)", mn, i386_a16(mrd), d);
			}
		}
		else {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						printf("                        %sb ax, (%s, -%u)", mn, i386_r32(b), d);
					}
					else {
						printf("                        %sb ax, (%s, %u)", mn, i386_r32(b), d);
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						printf("                        %sb ax, (%s, (%s, %u), -%u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
					}
					else {
						printf("                        %sb ax, (%s, (%s, %u), %u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
					}
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						printf("                        %sb ax, (%s, (%s), -%u)", mn, i386_r32(b), i386_r32(i), d);
					}
					else {
						printf("                        %sb ax, (%s, (%s), %u)", mn, i386_r32(b), i386_r32(i), d);
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (d & 128) {
					d = ~d + 1;
					printf("                        %sb ax, (%s, -%u)", mn, i386_r32(mrd), d);
				}
				else {
					printf("                        %sb ax, (%s, %u)", mn, i386_r32(mrd), d);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			*bn += 1;
			printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			if (d & 32768) {
				d = ~d + 1;
				printf("                     %sb ax, (%s, -%u)", mn, i386_a16(mrd), d);
			}
			else {
				printf("                     %sb ax, (%s, %u)", mn, i386_a16(mrd), d);
			}
		}
		else {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						printf("               %sb ax, (%s, -%u)", mn, i386_r32(b), d);
					}
					else {
						printf("               %sb ax, (%s, %u)", mn, i386_r32(b), d);
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						printf("               %sb ax, (%s, (%s, %u), -%u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
					}
					else {
						printf("               %sb ax, (%s, (%s, %u), %u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
					}
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						printf("               %sb ax, (%s, (%s), -%u)", mn, i386_r32(b), i386_r32(i), d);
					}
					else {
						printf("               %sb ax, (%s, (%s), %u)", mn, i386_r32(b), i386_r32(i), d);
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (d & 2147483648) {
					d = ~d + 1;
					printf("               %sb ax, (%s, -%u)", mn, i386_r32(mrd), d);
				}
				else {
					printf("               %sb ax, (%s, %u)", mn, i386_r32(mrd), d);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		*bn += 1;
		printf("                           %s ax, %s", mn, i386_r8(mrd));
		return 0;
	}
	else if (bin[*bn] == op0 + 1 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			if (mrd == 6) {
				*bn += 1;
				printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				if (lgo) {
					printf("                     %sw ax, (%u)", mn, d);
				}
				else {
					printf("                     %sd eax, (%u)", mn, d);
				}
			}
			else {
				*bn += 1;
				if (lgo) {
					printf("                              %sw ax, (%s)", mn, i386_a16(mrd));
				}
				else {
					printf("                              %sd eax, (%s)", mn, i386_a16(mrd));
				}
			}
		}
		else {
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
					if (lgo) {
						printf("               %sw ax, (%u)", mn, d);
					}
					else {
						printf("               %sd eax, (%u)", mn, d);
					}
				}
				else if (i == 4) {
					*bn += 1;
					if (lgo) {
						printf("                           %sw ax, (%s)", mn, i386_r32(b));
					}
					else {
						printf("                           %sd eax, (%s)", mn, i386_r32(b));
					}
				}
				else if (s) {
					*bn += 1;
					if (lgo) {
						printf("                           %sw ax, (%s, (%s, %u))", mn, i386_r32(b), i386_r32(i), i386_s8(s));
					}
					else {
						printf("                           %sd eax, (%s, (%s, %u))", mn, i386_r32(b), i386_r32(i), i386_s8(s));
					}
				}
				else {
					*bn += 1;
					if (lgo) {
						printf("                           %sw ax, (%s, (%s))", mn, i386_r32(b), i386_r32(i));
					}
					else {
						printf("                           %sd eax, (%s, (%s))", mn, i386_r32(b), i386_r32(i));
					}
				}
			}
			else if (mrd == 5) {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					printf("               %sw ax, (%u)", mn, d);
				}
				else {
					printf("               %sd eax (%u)", mn, d);
				}
			}
			else {
				*bn += 1;
				if (lgo) {
					printf("                              %sw ax, (%s)", mn, i386_r32(mrd));
				}
				else {
					printf("                              %sd eax, (%s)", mn, i386_r32(mrd));
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 + 1 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			*bn += 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			if (d & 128) {
				d = ~d + 1;
				if (lgo) {
					printf("                        %sw ax, (%s, -%u)", mn, i386_a16(mrd), d);
				}
				else {
					printf("                        %sd eax, (%s, -%u)", mn, i386_a16(mrd), d);
				}
			}
			else {
				if (lgo) {
					printf("                        %sw ax, (%s, %u)", mn, i386_a16(mrd), d);
				}
				else {
					printf("                        %sd eax, (%s, %u)", mn, i386_a16(mrd), d);
				}
			}
		}
		else {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							printf("                        %sw ax, (%s, -%u)", mn, i386_r32(b), d);
						}
						else {
							printf("                        %sd eax, (%s, -%u)", mn, i386_r32(b), d);
						}
					}
					else {
						if (lgo) {
							printf("                        %sw ax, (%s, %u)", mn, i386_r32(b), d);
						}
						else {
							printf("                        %sd eax, (%s, %u)", mn, i386_r32(b), d);
						}
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							printf("                        %sw ax, (%s, (%s, %u), -%u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
						else {
							printf("                        %sd eax, (%s, (%s, %u), -%u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
					}
					else {
						if (lgo) {
							printf("                        %sw ax, (%s, (%s, %u), %u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
						else {
							printf("                        %sd eax, (%s, (%s, %u), %u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
					}
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							printf("                        %sw ax, (%s, (%s), -%u)", mn, i386_r32(b), i386_r32(i), d);
						}
						else {
							printf("                        %sd eax, (%s, (%s), -%u)", mn, i386_r32(b), i386_r32(i), d);
						}
					}
					else {
						if (lgo) {
							printf("                        %sw ax, (%s, (%s), %u)", mn, i386_r32(b), i386_r32(i), d);
						}
						else {
							printf("                        %sd eax, (%s, (%s), %u)", mn, i386_r32(b), i386_r32(i), d);
						}
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						printf("                        %sw ax, (%s, -%u)", mn, i386_r32(mrd), d);
					}
					else {
						printf("                        %sd eax, (%s, -%u)", mn, i386_r32(mrd), d);
					}
				}
				else {
					if (lgo) {
						printf("                        %sw ax, (%s, %u)", mn, i386_r32(mrd), d);
					}
					else {
						printf("                        %sd eax, (%s, %u)", mn, i386_r32(mrd), d);
					}
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 + 1 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			*bn += 1;
			printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			if (d & 32768) {
				d = ~d + 1;
				if (lgo) {
					printf("                     %sw ax, (%s, -%u)", mn, i386_a16(mrd), d);
				}
				else {
					printf("                     %sd eax, (%s, -%u)", mn, i386_a16(mrd), d);
				}
			}
			else {
				if (lgo) {
					printf("                     %sw ax, (%s, %u)", mn, i386_a16(mrd), d);
				}
				else {
					printf("                     %sd eax, (%s, %u)", mn, i386_a16(mrd), d);
				}
			}
		}
		else {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							printf("               %sw ax, (%s, -%u)", mn, i386_r32(b), d);
						}
						else {
							printf("               %sd eax, (%s, -%u)", mn, i386_r32(b), d);
						}
					}
					else {
						if (lgo) {
							printf("               %sw ax, (%s, %u)", mn, i386_r32(b), d);
						}
						else {
							printf("               %sd eax, (%s, %u)", mn, i386_r32(b), d);
						}
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							printf("               %sw ax, (%s, (%s, %u), -%u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
						else {
							printf("               %sd eax, (%s, (%s, %u), -%u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
					}
					else {
						if (lgo) {
							printf("               %sw ax, (%s, (%s, %u), %u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
						else {
							printf("               %sd eax, (%s, (%s, %u), %u)", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
					}
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							printf("               %sw ax, (%s, (%s), -%u)", mn, i386_r32(b), i386_r32(i), d);
						}
						else {
							printf("               %sd eax, (%s, (%s), -%u)", mn, i386_r32(b), i386_r32(i), d);
						}
					}
					else {
						if (lgo) {
							printf("               %sw ax, (%s, (%s), %u)", mn, i386_r32(b), i386_r32(i), d);
						}
						else {
							printf("               %sd eax, (%s, (%s), %u)", mn, i386_r32(b), i386_r32(i), d);
						}
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						printf("               %sw ax, (%s, -%u)", mn, i386_r32(mrd), d);
					}
					else {
						printf("               %sd eax, (%s, -%u)", mn, i386_r32(mrd), d);
					}
				}
				else {
					if (lgo) {
						printf("               %sw ax, (%s, %u)", mn, i386_r32(mrd), d);
					}
					else {
						printf("               %sd eax, (%s, %u)", mn, i386_r32(mrd), d);
					}
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 + 1 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		*bn += 1;
		if (lgo) {
			printf("                           %s ax, %s", mn, i386_r16(mrd));
		}
		else {
			printf("                           %s eax, %s", mn, i386_r32(mrd));
		}
		return 0;
	}
	return 1;
}

uint8_t i386_dec_byt_imm(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		
		printf("                  %02x ", bin[*bn]);
		uint8_t k = bin[*bn];
		*bn += 1;
		
		if (k & 128) {
			k = ~k + 1;
			printf("            %s -%u", mn, k);
			*addr = *bn - k;
		}
		else {
			printf("            %s %u", mn, k);
			*addr = *bn + k;
		}
		return 0;
	}
	return 1;
}

uint8_t i386_dec_cond(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo) {
	if (bin[*bn] == 15 && bin[*bn + 1] == op) {
		printf("%02x %02x ", bin[*bn], bin[*bn + 1]);
		*bn += 2;
		
		printf("               %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
		uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
		*bn += 4;
		
		if (k & 2147483648) {
			k = ~k + 1;
			printf("   %s -%u", mn, k);
			*addr = *bn - k;
		}
		else {
			printf("   %s %u", mn, k);
			*addr = *bn + k;
		}
		return 0;
	}
	return 1;
}

uint8_t i386_dec_jmp(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		
		if (lgo) {
			printf("               %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t k = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			if (k & 32768) {
				k = ~k + 1;
				printf("         %sw -%u", mn, k);
				*addr = *bn - k;
			}
			else {
				printf("         %sw %u", mn, k);
				*addr = *bn + k;
			}
		}
		else {
			printf("               %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
			uint32_t k = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
			*bn += 4;
			if (k & 2147483648) {
				k = ~k + 1;
				printf("   %s -%u", mn, k);
				*addr = *bn - k;
			}
			else {
				printf("   %s %u", mn, k);
				*addr = *bn + k;
			}
		}
		return 0;
	}
	return 1;
}

uint8_t i386_dec_shft_k80(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo) {
	if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			if (mrd == 6) {
				*bn += 1;
				printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				printf("                     %sb (%u), 1", mn, d);
			}
			else {
				*bn += 1;
				printf("                              %sb (%s), 1", mn, i386_a16(mrd));
			}
		}
		else {
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
					printf("               %sb (%u), 1", mn, d);
				}
				else if (i == 4) {
					*bn += 1;
					printf("                           %sb (%s), 1", mn, i386_r32(b));
				}
				else if (s) {
					*bn += 1;
					printf("                           %sb (%s, (%s, %u)), 1", mn, i386_r32(b), i386_r32(i), i386_s8(s));
				}
				else {
					*bn += 1;
					printf("                           %sb (%s, (%s)), 1", mn, i386_r32(b), i386_r32(i));
				}
			}
			else if (mrd == 5) {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("               %sb (%u), 1", mn, d);
			}
			else {
				*bn += 1;
				printf("                              %sb (%s), 1", mn, i386_r32(mrd));
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			*bn += 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			if (d & 128) {
				d = ~d + 1;
				printf("                        %sb (%s, -%u), 1", mn, i386_a16(mrd), d);
			}
			else {
				printf("                        %sb (%s, %u), 1", mn, i386_a16(mrd), d);
			}
		}
		else {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						printf("                        %sb (%s, -%u), 1", mn, i386_r32(b), d);
					}
					else {
						printf("                        %sb (%s, %u), 1", mn, i386_r32(b), d);
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						printf("                        %sb (%s, (%s, %u), -%u), 1", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
					}
					else {
						printf("                        %sb (%s, (%s, %u), %u), 1", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
					}
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						printf("                        %sb (%s, (%s), -%u), 1", mn, i386_r32(b), i386_r32(i), d);
					}
					else {
						printf("                        %sb (%s, (%s), %u), 1", mn, i386_r32(b), i386_r32(i), d);
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (d & 128) {
					d = ~d + 1;
					printf("                        %sb (%s, -%u), 1", mn, i386_r32(mrd), d);
				}
				else {
					printf("                        %sb (%s, %u), 1", mn, i386_r32(mrd), d);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			*bn += 1;
			printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			if (d & 32768) {
				d = ~d + 1;
				printf("                     %sb (%s, -%u), 1", mn, i386_a16(mrd), d);
			}
			else {
				printf("                     %sb (%s, %u), 1", mn, i386_a16(mrd), d);
			}
		}
		else {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						printf("               %sb (%s, -%u), 1", mn, i386_r32(b), d);
					}
					else {
						printf("               %sb (%s, %u), 1", mn, i386_r32(b), d);
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						printf("               %sb (%s, (%s, %u), -%u), 1", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
					}
					else {
						printf("               %sb (%s, (%s, %u), %u), 1", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
					}
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						printf("               %sb (%s, (%s), -%u), 1", mn, i386_r32(b), i386_r32(i), d);
					}
					else {
						printf("               %sb (%s, (%s), %u), 1", mn, i386_r32(b), i386_r32(i), d);
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (d & 2147483648) {
					d = ~d + 1;
					printf("               %sb (%s, -%u), 1", mn, i386_r32(mrd), d);
				}
				else {
					printf("               %sb (%s, %u), 1", mn, i386_r32(mrd), d);
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		*bn += 1;
		printf("                              %sb %s, 1", mn, i386_r8(mrd));
		return 0;
	}
	return 1;
}

uint8_t i386_dec_shft_k81(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo) {
	if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (0 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			if (mrd == 6) {
				*bn += 1;
				printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				if (lgo) {
					printf("                     %sw (%u), 1", mn, d);
				}
				else {
					printf("                     %sd (%u), 1", mn, d);
				}
			}
			else {
				*bn += 1;
				if (lgo) {
					printf("                              %sw (%s), 1", mn, i386_a16(mrd));
				}
				else {
					printf("                              %sd (%s), 1", mn, i386_a16(mrd));
				}
			}
		}
		else {
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
					if (lgo) {
						printf("               %sw (%u), 1", mn, d);
					}
					else {
						printf("               %sd (%u), 1", mn, d);
					}
				}
				else if (i == 4) {
					*bn += 1;
					if (lgo) {
						printf("                           %sw (%s), 1", mn, i386_r32(b));
					}
					else {
						printf("                           %sd (%s), 1", mn, i386_r32(b));
					}
				}
				else if (s) {
					*bn += 1;
					if (lgo) {
						printf("                           %sw (%s, (%s, %u)), 1", mn, i386_r32(b), i386_r32(i), i386_s8(s));
					}
					else {
						printf("                           %sd (%s, (%s, %u)), 1", mn, i386_r32(b), i386_r32(i), i386_s8(s));
					}
				}
				else {
					*bn += 1;
					if (lgo) {
						printf("                           %sw (%s, (%s)), 1", mn, i386_r32(b), i386_r32(i));
					}
					else {
						printf("                           %sd (%s, (%s)), 1", mn, i386_r32(b), i386_r32(i));
					}
				}
			}
			else if (mrd == 5) {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					printf("               %sw (%u), 1", mn, d);
				}
				else {
					printf("               %sd (%u), 1", mn, d);
				}
			}
			else {
				*bn += 1;
				if (lgo) {
					printf("                              %sw (%s), 1", mn, i386_r32(mrd));
				}
				else {
					printf("                              %sd (%s), 1", mn, i386_r32(mrd));
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (8 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			*bn += 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			if (d & 128) {
				d = ~d + 1;
				if (lgo) {
					printf("                        %sw (%s, -%u), 1", mn, i386_a16(mrd), d);
				}
				else {
					printf("                        %sd (%s, -%u), 1", mn, i386_a16(mrd), d);
				}
			}
			else {
				if (lgo) {
					printf("                        %sw (%s, %u), 1", mn, i386_a16(mrd), d);
				}
				else {
					printf("                        %sd (%s, %u), 1", mn, i386_a16(mrd), d);
				}
			}
		}
		else {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							printf("                        %sw (%s, -%u), 1", mn, i386_r32(b), d);
						}
						else {
							printf("                        %sd (%s, -%u), 1", mn, i386_r32(b), d);
						}
					}
					else {
						if (lgo) {
							printf("                        %sw (%s, %u), 1", mn, i386_r32(b), d);
						}
						else {
							printf("                        %sd (%s, %u), 1", mn, i386_r32(b), d);
						}
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							printf("                        %sw (%s, (%s, %u), -%u), 1", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
						else {
							printf("                        %sd (%s, (%s, %u), -%u), 1", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
					}
					else {
						if (lgo) {
							printf("                        %sw (%s, (%s, %u), %u), 1", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
						else {
							printf("                        %sd (%s, (%s, %u), %u), 1", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
					}
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							printf("                        %sw (%s, (%s), -%u), 1", mn, i386_r32(b), i386_r32(i), d);
						}
						else {
							printf("                        %sd (%s, (%s), -%u), 1", mn, i386_r32(b), i386_r32(i), d);
						}
					}
					else {
						if (lgo) {
							printf("                        %sw (%s, (%s), %u), 1", mn, i386_r32(b), i386_r32(i), d);
						}
						else {
							printf("                        %sd (%s, (%s), %u), 1", mn, i386_r32(b), i386_r32(i), d);
						}
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						printf("                        %sw (%s, -%u), 1", mn, i386_r32(mrd), d);
					}
					else {
						printf("                        %sd (%s, -%u), 1", mn, i386_r32(mrd), d);
					}
				}
				else {
					if (lgo) {
						printf("                        %sw (%s, %u), 1", mn, i386_r32(mrd), d);
					}
					else {
						printf("                        %sd (%s, %u), 1", mn, i386_r32(mrd), d);
					}
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (16 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		if (lga) {
			*bn += 1;
			printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			if (d & 32768) {
				d = ~d + 1;
				if (lgo) {
					printf("                     %sw (%s, -%u), 1", mn, i386_a16(mrd), d);
				}
				else {
					printf("                     %sd (%s, -%u), 1", mn, i386_a16(mrd), d);
				}
			}
			else {
				if (lgo) {
					printf("                     %sw (%s, %u), 1", mn, i386_a16(mrd), d);
				}
				else {
					printf("                     %sd (%s, %u), 1", mn, i386_a16(mrd), d);
				}
			}
		}
		else {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							printf("               %sw (%s, -%u), 1", mn, i386_r32(b), d);
						}
						else {
							printf("               %sd (%s, -%u), 1", mn, i386_r32(b), d);
						}
					}
					else {
						if (lgo) {
							printf("               %sw (%s, %u), 1", mn, i386_r32(b), d);
						}
						else {
							printf("               %sd (%s, %u), 1", mn, i386_r32(b), d);
						}
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							printf("               %sw (%s, (%s, %u), -%u), 1", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
						else {
							printf("               %sd (%s, (%s, %u), -%u), 1", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
					}
					else {
						if (lgo) {
							printf("               %sw (%s, (%s, %u), %u), 1", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
						else {
							printf("               %sd (%s, (%s, %u), %u), 1", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
					}
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							printf("               %sw (%s, (%s), -%u), 1", mn, i386_r32(b), i386_r32(i), d);
						}
						else {
							printf("               %sd (%s, (%s), -%u), 1", mn, i386_r32(b), i386_r32(i), d);
						}
					}
					else {
						if (lgo) {
							printf("               %sw (%s, (%s), %u), 1", mn, i386_r32(b), i386_r32(i), d);
						}
						else {
							printf("               %sd (%s, (%s), %u), 1", mn, i386_r32(b), i386_r32(i), d);
						}
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						printf("               %sw (%s, -%u), 1", mn, i386_r32(mrd), d);
					}
					else {
						printf("               %sd (%s, -%u), 1", mn, i386_r32(mrd), d);
					}
				}
				else {
					if (lgo) {
						printf("               %sw (%s, %u), 1", mn, i386_r32(mrd), d);
					}
					else {
						printf("               %sd (%s, %u), 1", mn, i386_r32(mrd), d);
					}
				}
			}
		}
		return 0;
	}
	else if (bin[*bn] == op0 && (bin[*bn + 1] >> 3) == (24 | op1)) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mrd = (bin[*bn] & 7);
		
		*bn += 1;
		if (lgo) {
			printf("                              %sw %s, 1", mn, i386_r16(mrd));
		}
		else {
			printf("                              %sd %s, 1", mn, i386_r32(mrd));
		}
		return 0;
	}
	return 1;
}

uint8_t i386_dec_shft_r8(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo) {
	if (bin[*bn] == op0 && ((bin[*bn + 1] >> 3) & 7) == op1) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7);
		
		if (mod == 0 && lga) {
			if (mrd == 6) {
				*bn += 1;
				printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				printf("                     %sb (%u), cl", mn, d);
			}
			else {
				*bn += 1;
				printf("                              %sb (%s), cl", mn, i386_a16(mrd));
			}
		}
		else if (mod == 1 && lga) {
			*bn += 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			if (d & 128) {
				d = ~d + 1;
				printf("                        %sb (%s, -%u), cl", mn, i386_a16(mrd), d);
			}
			else {
				printf("                        %sb (%s, %u), cl", mn, i386_a16(mrd), d);
			}
		}
		else if (mod == 2 && lga) {
			*bn += 1;
			printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			if (d & 32768) {
				d = ~d + 1;
				printf("                     %sb (%s, -%u), cl", mn, i386_a16(mrd), d);
			}
			else {
				printf("                     %sb (%s, %u), cl", mn, i386_a16(mrd), d);
			}
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
					printf("               %sb (%u), cl", mn, d);
				}
				else if (i == 4) {
					*bn += 1;
					printf("                           %sb (%s), cl", mn, i386_r32(b));
				}
				else if (s) {
					*bn += 1;
					printf("                           %sb (%s, (%s, %u)), cl", mn, i386_r32(b), i386_r32(i), i386_s8(s));
				}
				else {
					*bn += 1;
					printf("                           %sb (%s, (%s)), cl", mn, i386_r32(b), i386_r32(i));
				}
			}
			else if (mrd == 5) {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				printf("               %sb (%u), cl", mn, d);
			}
			else {
				*bn += 1;
				printf("                              %sb (%s), cl", mn, i386_r32(mrd));
			}
		}
		else if (mod == 1) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						printf("                        %sb (%s, -%u), cl", mn, i386_r32(b), d);
					}
					else {
						printf("                        %sb (%s, %u), cl", mn, i386_r32(b), d);
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						printf("                        %sb (%s, (%s, %u), -%u), cl", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
					}
					else {
						printf("                        %sb (%s, (%s, %u), %u), cl", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
					}
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						printf("                        %sb (%s, (%s), -%u), cl", mn, i386_r32(b), i386_r32(i), d);
					}
					else {
						printf("                        %sb (%s, (%s), %u), cl", mn, i386_r32(b), i386_r32(i), d);
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (d & 128) {
					d = ~d + 1;
					printf("                        %sb (%s, -%u), cl", mn, i386_r32(mrd), d);
				}
				else {
					printf("                        %sb (%s, %u), cl", mn, i386_r32(mrd), d);
				}
			}
		}
		else if (mod == 2) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						printf("               %sb (%s, -%u), cl", mn, i386_r32(b), d);
					}
					else {
						printf("               %sb (%s, %u), cl", mn, i386_r32(b), d);
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						printf("               %sb (%s, (%s, %u), -%u), cl", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
					}
					else {
						printf("               %sb (%s, (%s, %u), %u), cl", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
					}
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						printf("               %sb (%s, (%s), -%u), cl", mn, i386_r32(b), i386_r32(i), d);
					}
					else {
						printf("               %sb (%s, (%s), %u), cl", mn, i386_r32(b), i386_r32(i), d);
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (d & 2147483648) {
					d = ~d + 1;
					printf("               %sb (%s, -%u), cl", mn, i386_r32(mrd), d);
				}
				else {
					printf("               %sb (%s, %u), cl", mn, i386_r32(mrd), d);
				}
			}
		}
		else if (mod == 3) {
			*bn += 1;
			printf("                              %sb %s, cl", mn, i386_r8(mrd));
		}
		return 0;
	}
	return 1;
}

uint8_t i386_dec_shft_reg(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op0, uint8_t op1, int8_t* mn, uint8_t lga, uint8_t lgo) {
	if (bin[*bn] == op0 && ((bin[*bn + 1] >> 3) & 7) == op1) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		printf("%02x ", bin[*bn]);
		uint8_t mod = bin[*bn] >> 6;
		uint8_t mrd = (bin[*bn] & 7);
		
		if (mod == 0 && lga) {
			if (mrd == 6) {
				*bn += 1;
				printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
				uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
				*bn += 2;
				if (lgo) {
					printf("                     %sw (%u), cl", mn, d);
				}
				else {
					printf("                     %sd (%u), cl", mn, d);
				}
			}
			else {
				*bn += 1;
				if (lgo) {
					printf("                              %sw (%s), cl", mn, i386_a16(mrd));
				}
				else {
					printf("                              %sd (%s), cl", mn, i386_a16(mrd));
				}
			}
		}
		else if (mod == 1 && lga) {
			*bn += 1;
			printf("   %02x ", bin[*bn]);
			uint8_t d = bin[*bn];
			*bn += 1;
			if (d & 128) {
				d = ~d + 1;
				if (lgo) {
					printf("                        %sw (%s, -%u), cl", mn, i386_a16(mrd), d);
				}
				else {
					printf("                        %sd (%s, -%u), cl", mn, i386_a16(mrd), d);
				}
			}
			else {
				if (lgo) {
					printf("                        %sw (%s, %u), cl", mn, i386_a16(mrd), d);
				}
				else {
					printf("                        %sd (%s, %u), cl", mn, i386_a16(mrd), d);
				}
			}
		}
		else if (mod == 2 && lga) {
			*bn += 1;
			printf("   %02x %02x ", bin[*bn], bin[*bn + 1]);
			uint16_t d = bin[*bn] + (bin[*bn + 1] << 8);
			*bn += 2;
			if (d & 32768) {
				d = ~d + 1;
				if (lgo) {
					printf("                     %sw (%s, -%u), cl", mn, i386_a16(mrd), d);
				}
				else {
					printf("                     %sd (%s, -%u), cl", mn, i386_a16(mrd), d);
				}
			}
			else {
				if (lgo) {
					printf("                     %sw (%s, %u), cl", mn, i386_a16(mrd), d);
				}
				else {
					printf("                     %sd (%s, %u), cl", mn, i386_a16(mrd), d);
				}
			}
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
					if (lgo) {
						printf("               %sw (%u), cl", mn, d);
					}
					else {
						printf("               %sd (%u), cl", mn, d);
					}
				}
				else if (i == 4) {
					*bn += 1;
					if (lgo) {
						printf("                           %sw (%s), cl", mn, i386_r32(b));
					}
					else {
						printf("                           %sd (%s), cl", mn, i386_r32(b));
					}
				}
				else if (s) {
					*bn += 1;
					if (lgo) {
						printf("                           %sw (%s, (%s, %u)), cl", mn, i386_r32(b), i386_r32(i), i386_s8(s));
					}
					else {
						printf("                           %sd (%s, (%s, %u)), cl", mn, i386_r32(b), i386_r32(i), i386_s8(s));
					}
				}
				else {
					*bn += 1;
					if (lgo) {
						printf("                           %sw (%s, (%s)), cl", mn, i386_r32(b), i386_r32(i));
					}
					else {
						printf("                           %sd (%s, (%s)), cl", mn, i386_r32(b), i386_r32(i));
					}
				}
			}
			else if (mrd == 5) {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (lgo) {
					printf("               %sw (%u), cl", mn, d);
				}
				else {
					printf("               %sd (%u), cl", mn, d);
				}
			}
			else {
				*bn += 1;
				if (lgo) {
					printf("                              %sw (%s), cl", mn, i386_r32(mrd));
				}
				else {
					printf("                              %sd (%s), cl", mn, i386_r32(mrd));
				}
			}
		}
		else if (mod == 1) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							printf("                        %sw (%s, -%u), cl", mn, i386_r32(b), d);
						}
						else {
							printf("                        %sd (%s, -%u), cl", mn, i386_r32(b), d);
						}
					}
					else {
						if (lgo) {
							printf("                        %sw (%s, %u), cl", mn, i386_r32(b), d);
						}
						else {
							printf("                        %sd (%s, %u), cl", mn, i386_r32(b), d);
						}
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							printf("                        %sw (%s, (%s, %u), -%u), cl", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
						else {
							printf("                        %sd (%s, (%s, %u), -%u), cl", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
					}
					else {
						if (lgo) {
							printf("                        %sw (%s, (%s, %u), %u), cl", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
						else {
							printf("                        %sd (%s, (%s, %u), %u), cl", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
					}
				}
				else {
					*bn += 1;
					printf("%02x ", bin[*bn]);
					uint8_t d = bin[*bn];
					*bn += 1;
					if (d & 128) {
						d = ~d + 1;
						if (lgo) {
							printf("                        %sw (%s, (%s), -%u), cl", mn, i386_r32(b), i386_r32(i), d);
						}
						else {
							printf("                        %sd (%s, (%s), -%u), cl", mn, i386_r32(b), i386_r32(i), d);
						}
					}
					else {
						if (lgo) {
							printf("                        %sw (%s, (%s), %u), cl", mn, i386_r32(b), i386_r32(i), d);
						}
						else {
							printf("                        %sd (%s, (%s), %u), cl", mn, i386_r32(b), i386_r32(i), d);
						}
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x ", bin[*bn]);
				uint8_t d = bin[*bn];
				*bn += 1;
				if (d & 128) {
					d = ~d + 1;
					if (lgo) {
						printf("                        %sw (%s, -%u), cl", mn, i386_r32(mrd), d);
					}
					else {
						printf("                        %sd (%s, -%u), cl", mn, i386_r32(mrd), d);
					}
				}
				else {
					if (lgo) {
						printf("                        %sw (%s, %u), cl", mn, i386_r32(mrd), d);
					}
					else {
						printf("                        %sd (%s, %u), cl", mn, i386_r32(mrd), d);
					}
				}
			}
		}
		else if (mod == 2) {
			if ((mrd & 7) == 4) {
				*bn += 1;
				printf("%02x ", bin[*bn]);
				uint8_t b = (bin[*bn] & 7);
				uint8_t i = ((bin[*bn] >> 3) & 7);
				uint8_t s = (bin[*bn] >> 6);
				if (i == 4) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							printf("               %sw (%s, -%u), cl", mn, i386_r32(b), d);
						}
						else {
							printf("               %sd (%s, -%u), cl", mn, i386_r32(b), d);
						}
					}
					else {
						if (lgo) {
							printf("               %sw (%s, %u), cl", mn, i386_r32(b), d);
						}
						else {
							printf("               %sd (%s, %u), cl", mn, i386_r32(b), d);
						}
					}
				}
				else if (s) {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							printf("               %sw (%s, (%s, %u), -%u), cl", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
						else {
							printf("               %sd (%s, (%s, %u), -%u), cl", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
					}
					else {
						if (lgo) {
							printf("               %sw (%s, (%s, %u), %u), cl", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
						else {
							printf("               %sd (%s, (%s, %u), %u), cl", mn, i386_r32(b), i386_r32(i), i386_s8(s), d);
						}
					}
				}
				else {
					*bn += 1;
					printf("%02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
					uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
					*bn += 4;
					if (d & 2147483648) {
						d = ~d + 1;
						if (lgo) {
							printf("               %sw (%s, (%s), -%u), cl", mn, i386_r32(b), i386_r32(i), d);
						}
						else {
							printf("               %sd (%s, (%s), -%u), cl", mn, i386_r32(b), i386_r32(i), d);
						}
					}
					else {
						if (lgo) {
							printf("               %sw (%s, (%s), %u), cl", mn, i386_r32(b), i386_r32(i), d);
						}
						else {
							printf("               %sd (%s, (%s), %u), cl", mn, i386_r32(b), i386_r32(i), d);
						}
					}
				}
			}
			else {
				*bn += 1;
				printf("   %02x %02x %02x %02x ", bin[*bn], bin[*bn + 1], bin[*bn + 2], bin[*bn + 3]);
				uint32_t d = bin[*bn] + (bin[*bn + 1] << 8) + (bin[*bn + 2] << 16) + (bin[*bn + 3] << 24);
				*bn += 4;
				if (d & 2147483648) {
					d = ~d + 1;
					if (lgo) {
						printf("               %sw (%s, -%u), cl", mn, i386_r32(mrd), d);
					}
					else {
						printf("               %sd (%s, -%u), cl", mn, i386_r32(mrd), d);
					}
				}
				else {
					if (lgo) {
						printf("               %sw (%s, %u), cl", mn, i386_r32(mrd), d);
					}
					else {
						printf("               %sd (%s, %u), cl", mn, i386_r32(mrd), d);
					}
				}
			}
		}
		else if (mod == 3) {
			*bn += 1;
			if (lgo) {
				printf("                              %sw %s, cl", mn, i386_r16(mrd));
			}
			else {
				printf("                              %sd %s, cl", mn, i386_r32(mrd));
			}
		}
		return 0;
	}
	return 1;
}

uint8_t i386_dec_byt(uint8_t* bin, uint64_t* bn, uint64_t* addr, uint8_t op, int8_t* mn, uint8_t lga, uint8_t lgo) {
	if (bin[*bn] == op) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
		
		printf("                                 %s", mn);
		return 0;
	}
	return 1;
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
		eo = i386_dec_r80(bin, bn, addr, 0, "add", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_rg0(bin, bn, addr, 1, "add", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_r81(bin, bn, addr, 2, "add", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_rg1(bin, bn, addr, 3, "add", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_ral(bin, bn, addr, 4, "add", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_rax(bin, bn, addr, 5, "add", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_r80(bin, bn, addr, 8, "or", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_rg0(bin, bn, addr, 9, "or", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_r81(bin, bn, addr, 10, "or", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_rg1(bin, bn, addr, 11, "or", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_ral(bin, bn, addr, 12, "or", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_rax(bin, bn, addr, 13, "or", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_r80(bin, bn, addr, 16, "adc", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_rg0(bin, bn, addr, 17, "adc", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_r81(bin, bn, addr, 18, "adc", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_rg1(bin, bn, addr, 19, "adc", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_ral(bin, bn, addr, 20, "adc", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_rax(bin, bn, addr, 21, "adc", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_r80(bin, bn, addr, 24, "sbb", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_rg0(bin, bn, addr, 25, "sbb", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_r81(bin, bn, addr, 26, "sbb", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_rg1(bin, bn, addr, 27, "sbb", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_ral(bin, bn, addr, 28, "sbb", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_rax(bin, bn, addr, 29, "sbb", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_r80(bin, bn, addr, 32, "and", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_rg0(bin, bn, addr, 33, "and", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_r81(bin, bn, addr, 34, "and", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_rg1(bin, bn, addr, 35, "and", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_ral(bin, bn, addr, 36, "and", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_rax(bin, bn, addr, 37, "and", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_r80(bin, bn, addr, 40, "sub", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_rg0(bin, bn, addr, 41, "sub", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_r81(bin, bn, addr, 42, "sub", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_rg1(bin, bn, addr, 43, "sub", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_ral(bin, bn, addr, 44, "sub", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_rax(bin, bn, addr, 45, "sub", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_r80(bin, bn, addr, 48, "xor", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_rg0(bin, bn, addr, 49, "xor", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_r81(bin, bn, addr, 50, "xor", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_rg1(bin, bn, addr, 51, "xor", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_ral(bin, bn, addr, 52, "xor", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_rax(bin, bn, addr, 53, "xor", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_r80(bin, bn, addr, 56, "cmp", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_rg0(bin, bn, addr, 57, "cmp", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_r81(bin, bn, addr, 58, "cmp", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_rg1(bin, bn, addr, 59, "cmp", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_ral(bin, bn, addr, 60, "cmp", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_rax(bin, bn, addr, 61, "cmp", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_stck(bin, bn, addr, 80, "push", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_stck(bin, bn, addr, 88, "pop", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_op_imm(bin, bn, addr, 104, "push", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt_imm(bin, bn, addr, 112, "jo", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt_imm(bin, bn, addr, 113, "jno", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt_imm(bin, bn, addr, 114, "jc", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt_imm(bin, bn, addr, 115, "jnc", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt_imm(bin, bn, addr, 116, "je", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt_imm(bin, bn, addr, 117, "jne", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt_imm(bin, bn, addr, 118, "jna", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt_imm(bin, bn, addr, 119, "ja", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt_imm(bin, bn, addr, 120, "js", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt_imm(bin, bn, addr, 121, "jns", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt_imm(bin, bn, addr, 122, "jpe", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt_imm(bin, bn, addr, 123, "jpo", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt_imm(bin, bn, addr, 124, "jl", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt_imm(bin, bn, addr, 125, "jge", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt_imm(bin, bn, addr, 126, "jle", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt_imm(bin, bn, addr, 127, "jg", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k80(bin, bn, addr, 128, 0, "add", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k80(bin, bn, addr, 128, 1, "or", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k80(bin, bn, addr, 128, 2, "adc", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k80(bin, bn, addr, 128, 3, "sbb", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k80(bin, bn, addr, 128, 4, "and", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k80(bin, bn, addr, 128, 5, "sub", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k80(bin, bn, addr, 128, 6, "xor", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k80(bin, bn, addr, 128, 7, "cmp", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_imm(bin, bn, addr, 129, 0, "add", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_imm(bin, bn, addr, 129, 1, "or", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_imm(bin, bn, addr, 129, 2, "adc", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_imm(bin, bn, addr, 129, 3, "sbb", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_imm(bin, bn, addr, 129, 4, "and", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_imm(bin, bn, addr, 129, 5, "sub", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_imm(bin, bn, addr, 129, 6, "xor", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_imm(bin, bn, addr, 129, 7, "cmp", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k81(bin, bn, addr, 131, 0, "add", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k81(bin, bn, addr, 131, 1, "or", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k81(bin, bn, addr, 131, 2, "adc", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k81(bin, bn, addr, 131, 3, "sbb", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k81(bin, bn, addr, 131, 4, "and", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k81(bin, bn, addr, 131, 5, "sub", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k81(bin, bn, addr, 131, 6, "xor", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k81(bin, bn, addr, 131, 7, "cmp", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_r81(bin, bn, addr, 134, "xchg", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_rg1(bin, bn, addr, 135, "xchg", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_r80(bin, bn, addr, 136, "mov", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_rg0(bin, bn, addr, 137, "mov", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_r81(bin, bn, addr, 138, "mov", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_rg1(bin, bn, addr, 139, "mov", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_rg1(bin, bn, addr, 141, "lea", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_blnk(bin, bn, addr, 143, 0, "pop", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_stck(bin, bn, addr, 144, "xchg", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt(bin, bn, addr, 156, "pushf", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt(bin, bn, addr, 157, "popf", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt(bin, bn, addr, 158, "sahf ah", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt(bin, bn, addr, 159, "lahf ah", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_mvp(bin, bn, addr, 176, "mov", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k80(bin, bn, addr, 192, 0, "rol", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k80(bin, bn, addr, 192, 1, "ror", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k80(bin, bn, addr, 192, 2, "rcl", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k80(bin, bn, addr, 192, 3, "rcr", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k80(bin, bn, addr, 192, 4, "shl", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k80(bin, bn, addr, 192, 5, "shr", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k80(bin, bn, addr, 192, 6, "sal", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k80(bin, bn, addr, 192, 7, "sar", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k81(bin, bn, addr, 193, 0, "rol", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k81(bin, bn, addr, 193, 1, "ror", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k81(bin, bn, addr, 193, 2, "rcl", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k81(bin, bn, addr, 193, 3, "rcr", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k81(bin, bn, addr, 193, 4, "shl", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k81(bin, bn, addr, 193, 5, "shr", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k81(bin, bn, addr, 193, 6, "sal", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_k81(bin, bn, addr, 193, 7, "sar", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt(bin, bn, addr, 195, "ret", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_imm(bin, bn, addr, 199, 0, "mov", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt(bin, bn, addr, 204, "int 3", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt_imm(bin, bn, addr, 205, "int", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_k80(bin, bn, addr, 208, 0, "rol", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_k80(bin, bn, addr, 208, 1, "ror", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_k80(bin, bn, addr, 208, 2, "rcl", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_k80(bin, bn, addr, 208, 3, "rcr", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_k80(bin, bn, addr, 208, 4, "shl", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_k80(bin, bn, addr, 208, 5, "shr", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_k80(bin, bn, addr, 208, 6, "sal", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_k80(bin, bn, addr, 208, 7, "sar", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_k81(bin, bn, addr, 209, 0, "rol", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_k81(bin, bn, addr, 209, 1, "ror", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_k81(bin, bn, addr, 209, 2, "rcl", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_k81(bin, bn, addr, 209, 3, "rcr", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_k81(bin, bn, addr, 209, 4, "shl", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_k81(bin, bn, addr, 209, 5, "shr", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_k81(bin, bn, addr, 209, 6, "sal", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_k81(bin, bn, addr, 209, 7, "sar", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_r8(bin, bn, addr, 210, 0, "rol", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_r8(bin, bn, addr, 210, 1, "ror", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_r8(bin, bn, addr, 210, 2, "rcl", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_r8(bin, bn, addr, 210, 3, "rcr", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_r8(bin, bn, addr, 210, 4, "shl", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_r8(bin, bn, addr, 210, 5, "shr", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_r8(bin, bn, addr, 210, 6, "sal", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_r8(bin, bn, addr, 210, 7, "sar", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_reg(bin, bn, addr, 211, 0, "rol", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_reg(bin, bn, addr, 211, 1, "ror", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_reg(bin, bn, addr, 211, 2, "rcl", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_reg(bin, bn, addr, 211, 3, "rcr", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_reg(bin, bn, addr, 211, 4, "shl", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_reg(bin, bn, addr, 211, 5, "shr", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_reg(bin, bn, addr, 211, 6, "sal", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_shft_reg(bin, bn, addr, 211, 7, "sar", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_jmp(bin, bn, addr, 232, "call", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_jmp(bin, bn, addr, 233, "jmp", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_cond(bin, bn, addr, 235, "jmp", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt(bin, bn, addr, 240, "lock", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt(bin, bn, addr, 241, "icebp", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt(bin, bn, addr, 242, "repne", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt(bin, bn, addr, 243, "repe", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt(bin, bn, addr, 244, "hlt", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt(bin, bn, addr, 245, "cmc", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_alnk(bin, bn, addr, 246, 2, "not", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_alnk(bin, bn, addr, 246, 3, "neg", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_mlnk(bin, bn, addr, 246, 4, "mul", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_mlnk(bin, bn, addr, 246, 5, "imul", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_mlnk(bin, bn, addr, 246, 6, "div", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_mlnk(bin, bn, addr, 246, 7, "idiv", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt(bin, bn, addr, 248, "clc", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt(bin, bn, addr, 249, "stc", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt(bin, bn, addr, 250, "cli", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt(bin, bn, addr, 251, "sti", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt(bin, bn, addr, 252, "cld", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_byt(bin, bn, addr, 253, "std", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_alnk(bin, bn, addr, 254, 0, "inc", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_alnk(bin, bn, addr, 254, 1, "dec", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_blnk(bin, bn, addr, 255, 2, "call", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_blnk(bin, bn, addr, 255, 4, "jmp", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_blnk(bin, bn, addr, 255, 6, "push", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_cond(bin, bn, addr, 128, "jo", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_cond(bin, bn, addr, 129, "jno", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_cond(bin, bn, addr, 130, "jc", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_cond(bin, bn, addr, 131, "jnc", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_cond(bin, bn, addr, 132, "je", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_cond(bin, bn, addr, 133, "jne", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_cond(bin, bn, addr, 134, "jna", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_cond(bin, bn, addr, 135, "ja", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_cond(bin, bn, addr, 136, "js", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_cond(bin, bn, addr, 137, "jns", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_cond(bin, bn, addr, 138, "jpe", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_cond(bin, bn, addr, 139, "jpo", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_cond(bin, bn, addr, 140, "jl", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_cond(bin, bn, addr, 141, "jge", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_cond(bin, bn, addr, 142, "jle", lga, lgo);
	}
	if (eo) {
		eo = i386_dec_cond(bin, bn, addr, 143, "jg", lga, lgo);
	}
	if (eo) {
		printf("%02x ", bin[*bn]);
		*bn += 1;
	}
}
