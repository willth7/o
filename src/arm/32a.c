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

int8_t* arm_32a_s(uint8_t s) {
	if (s) {
		return "s";
	}
	else {
		return "\0";
	}
}

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
	else if (sh == 32) {
		return "lsr";
	}
	else if (sh == 64) {
		return "asr";
	}
	else if (sh == 96) {
		return "ror";
	}
}

void arm_32a_dec(uint8_t* bin, uint64_t* bn, uint64_t* addr) {
	printf("%04lx %04lx    ", (*bn >> 16) & 65535, (*bn) & 65535); //address
	printf("%02x %02x %02x %02x    ", bin[*bn + 3], bin[*bn + 2], bin[*bn + 1], bin[*bn]); //machine code
	
	if ((bin[*bn + 3] & 14) == 0 && (bin[*bn + 2] & 48) == 0 && (bin[*bn] & 240) == 176) {
		printf("strh%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 3] & 1) && (bin[*bn + 2] & 192) == 64) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", -1 * ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 3] & 1) && (bin[*bn + 2] & 192) == 192) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 64) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", -1 * ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 192) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 3] & 1) && (bin[*bn + 2] & 192) == 128) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("r%u) ", bin[*bn] & 15);
		}
		else if ((bin[*bn + 2] & 192) == 128) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("r%u ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 0 && (bin[*bn + 2] & 48) == 32 && (bin[*bn] & 240) == 176) {
		printf("strht%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 2] & 192) == 64) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", -1 * ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 192) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 128) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("r%u ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 48) == 32 && (bin[*bn] & 240) == 176) {
		printf("strhw%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 2] & 192) == 64) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", -1 * ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 192) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 128) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("r%u) ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 14) == 0 && (bin[*bn + 2] & 48) == 16 && (bin[*bn] & 240) == 176) {
		printf("ldrh%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 3] & 1) && (bin[*bn + 2] & 192) == 64) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", -1 * ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 3] & 1) && (bin[*bn + 2] & 192) == 192) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 64) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", -1 * ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 192) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 3] & 1) && (bin[*bn + 2] & 192) == 128) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("r%u) ", bin[*bn] & 15);
		}
		else if ((bin[*bn + 2] & 192) == 128) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("r%u ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 0 && (bin[*bn + 2] & 48) == 48 && (bin[*bn] & 240) == 176) {
		printf("ldrht%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 2] & 192) == 64) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", -1 * ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 192) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 128) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("r%u ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 48) == 48 && (bin[*bn] & 240) == 176) {
		printf("ldrhw%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 2] & 192) == 64) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", -1 * ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 192) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 128) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("r%u) ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 14) == 0 && (bin[*bn + 2] & 48) == 0 && (bin[*bn] & 240) == 208) {
		printf("ldrd%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 3] & 1) && (bin[*bn + 2] & 192) == 64) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", -1 * ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 3] & 1) && (bin[*bn + 2] & 192) == 192) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 64) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", -1 * ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 192) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 3] & 1) && (bin[*bn + 2] & 192) == 128) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("r%u) ", bin[*bn] & 15);
		}
		else if ((bin[*bn + 2] & 192) == 128) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("r%u ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 0 && (bin[*bn + 2] & 48) == 32 && (bin[*bn] & 240) == 208) {
		printf("ldrdt%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 2] & 192) == 64) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", -1 * ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 192) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 128) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("r%u ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 48) == 32 && (bin[*bn] & 240) == 208) {
		printf("ldrdw%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 2] & 192) == 64) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", -1 * ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 192) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 128) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("r%u) ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 14) == 0 && (bin[*bn + 2] & 48) == 16 && (bin[*bn] & 240) == 208) {
		printf("ldrsb%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 3] & 1) && (bin[*bn + 2] & 192) == 64) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", -1 * ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 3] & 1) && (bin[*bn + 2] & 192) == 192) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 64) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", -1 * ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 192) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 3] & 1) && (bin[*bn + 2] & 192) == 128) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("r%u) ", bin[*bn] & 15);
		}
		else if ((bin[*bn + 2] & 192) == 128) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("r%u ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 0 && (bin[*bn + 2] & 48) == 48 && (bin[*bn] & 240) == 208) {
		printf("ldrsbt%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 2] & 192) == 64) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", -1 * ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 192) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 128) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("r%u ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 48) == 48 && (bin[*bn] & 240) == 208) {
		printf("ldrsbw%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 2] & 192) == 64) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", -1 * ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 192) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 128) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("r%u) ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 14) == 0 && (bin[*bn + 2] & 48) == 0 && (bin[*bn] & 240) == 240) {
		printf("strd%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 3] & 1) && (bin[*bn + 2] & 192) == 64) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", -1 * ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 3] & 1) && (bin[*bn + 2] & 192) == 192) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 64) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", -1 * ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 192) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 3] & 1) && (bin[*bn + 2] & 192) == 128) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("r%u) ", bin[*bn] & 15);
		}
		else if ((bin[*bn + 2] & 192) == 128) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("r%u ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 0 && (bin[*bn + 2] & 48) == 32 && (bin[*bn] & 240) == 240) {
		printf("strdt%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 2] & 192) == 64) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", -1 * ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 192) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 128) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("r%u ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 48) == 32 && (bin[*bn] & 240) == 240) {
		printf("strdw%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 2] & 192) == 64) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", -1 * ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 192) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 128) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("r%u) ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 14) == 0 && (bin[*bn + 2] & 48) == 16 && (bin[*bn] & 240) == 240) {
		printf("ldrsh%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 3] & 1) && (bin[*bn + 2] & 192) == 64) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", -1 * ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 3] & 1) && (bin[*bn + 2] & 192) == 192) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 64) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", -1 * ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 192) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 3] & 1) && (bin[*bn + 2] & 192) == 128) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("r%u) ", bin[*bn] & 15);
		}
		else if ((bin[*bn + 2] & 192) == 128) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("r%u ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 0 && (bin[*bn + 2] & 48) == 48 && (bin[*bn] & 240) == 240) {
		printf("ldrsht%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 2] & 192) == 64) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", -1 * ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 192) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 128) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("r%u ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 48) == 48 && (bin[*bn] & 240) == 240) {
		printf("ldrshw%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 2] & 192) == 64) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", -1 * ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 192) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", ((bin[*bn] & 15) + ((bin[*bn + 1] & 15) << 4)));
		}
		else if ((bin[*bn + 2] & 192) == 128) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("r%u) ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 12) == 4 && (bin[*bn + 2] & 112) == 0) {
		printf("str%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 3] & 3) == 1 && (bin[*bn + 2] & 128)) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if ((bin[*bn + 3] & 3) == 1) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", -1 * (bin[*bn] + ((bin[*bn + 1] & 15) << 8)));
		}
		else if ((bin[*bn + 3] & 3) == 0 && (bin[*bn + 2] & 128)) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if ((bin[*bn + 3] & 3) == 0) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", -1 * (bin[*bn] + ((bin[*bn + 1] & 15) << 8)));
		}
		else if ((bin[*bn + 3] & 3) == 3 && (bin[*bn + 2] & 128) && ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)))) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("r%u), ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else if ((bin[*bn + 3] & 3) == 3 && (bin[*bn + 2] & 128)) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("r%u) ", bin[*bn] & 15);
		}
		else if ((bin[*bn + 3] & 3) == 2 && (bin[*bn + 2] & 128) && ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)))) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else if ((bin[*bn + 3] & 3) == 2 && (bin[*bn + 2] & 128)) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("r%u ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 4 && (bin[*bn + 2] & 112) == 32) {
		printf("strt%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 3] & 2) == 0 && (bin[*bn + 2] & 128)) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if ((bin[*bn + 3] & 2) == 0) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", -1 * (bin[*bn] + ((bin[*bn + 1] & 15) << 8)));
		}
		else if ((bin[*bn + 3] & 2) == 2 && (bin[*bn + 2] & 128) && ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)))) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else if ((bin[*bn + 3] & 2) == 2 && (bin[*bn + 2] & 128)) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("r%u ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 5 && (bin[*bn + 2] & 112) == 32) {
		printf("strw%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 3] & 2) == 0 && (bin[*bn + 2] & 128)) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if ((bin[*bn + 3] & 2) == 0) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", -1 * (bin[*bn] + ((bin[*bn + 1] & 15) << 8)));
		}
		else if ((bin[*bn + 3] & 2) == 2 && (bin[*bn + 2] & 128) && ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)))) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("r%u), ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else if ((bin[*bn + 3] & 2) == 2 && (bin[*bn + 2] & 128)) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("r%u) ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 12) == 4 && (bin[*bn + 2] & 112) == 16) {
		printf("ldr%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 3] & 3) == 1 && (bin[*bn + 2] & 128)) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if ((bin[*bn + 3] & 3) == 1) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", -1 * (bin[*bn] + ((bin[*bn + 1] & 15) << 8)));
		}
		else if ((bin[*bn + 3] & 3) == 0 && (bin[*bn + 2] & 128)) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if ((bin[*bn + 3] & 3) == 0) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", -1 * (bin[*bn] + ((bin[*bn + 1] & 15) << 8)));
		}
		else if ((bin[*bn + 3] & 3) == 3 && (bin[*bn + 2] & 128) && ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)))) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("r%u), ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else if ((bin[*bn + 3] & 3) == 3 && (bin[*bn + 2] & 128)) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("r%u) ", bin[*bn] & 15);
		}
		else if ((bin[*bn + 3] & 3) == 2 && (bin[*bn + 2] & 128) && ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)))) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else if ((bin[*bn + 3] & 3) == 2 && (bin[*bn + 2] & 128)) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("r%u ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 4 && (bin[*bn + 2] & 112) == 48) {
		printf("ldrt%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 3] & 2) == 0 && (bin[*bn + 2] & 128)) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if ((bin[*bn + 3] & 2) == 0) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", -1 * (bin[*bn] + ((bin[*bn + 1] & 15) << 8)));
		}
		else if ((bin[*bn + 3] & 2) == 2 && (bin[*bn + 2] & 128) && ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)))) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else if ((bin[*bn + 3] & 2) == 2 && (bin[*bn + 2] & 128)) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("r%u ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 5 && (bin[*bn + 2] & 112) == 48) {
		printf("ldrw%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 3] & 2) == 0 && (bin[*bn + 2] & 128)) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if ((bin[*bn + 3] & 2) == 0) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", -1 * (bin[*bn] + ((bin[*bn + 1] & 15) << 8)));
		}
		else if ((bin[*bn + 3] & 2) == 2 && (bin[*bn + 2] & 128) && ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)))) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("r%u), ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else if ((bin[*bn + 3] & 2) == 2 && (bin[*bn + 2] & 128)) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("r%u) ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 12) == 4 && (bin[*bn + 2] & 112) == 64) {
		printf("strb%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 3] & 3) == 1 && (bin[*bn + 2] & 128)) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if ((bin[*bn + 3] & 3) == 1) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", -1 * (bin[*bn] + ((bin[*bn + 1] & 15) << 8)));
		}
		else if ((bin[*bn + 3] & 3) == 0 && (bin[*bn + 2] & 128)) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if ((bin[*bn + 3] & 3) == 0) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", -1 * (bin[*bn] + ((bin[*bn + 1] & 15) << 8)));
		}
		else if ((bin[*bn + 3] & 3) == 3 && (bin[*bn + 2] & 128) && ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)))) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("r%u), ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else if ((bin[*bn + 3] & 3) == 3 && (bin[*bn + 2] & 128)) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("r%u) ", bin[*bn] & 15);
		}
		else if ((bin[*bn + 3] & 3) == 2 && (bin[*bn + 2] & 128) && ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)))) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else if ((bin[*bn + 3] & 3) == 2 && (bin[*bn + 2] & 128)) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("r%u ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 4 && (bin[*bn + 2] & 112) == 96) {
		printf("strbt%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 3] & 2) == 0 && (bin[*bn + 2] & 128)) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if ((bin[*bn + 3] & 2) == 0) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", -1 * (bin[*bn] + ((bin[*bn + 1] & 15) << 8)));
		}
		else if ((bin[*bn + 3] & 2) == 2 && (bin[*bn + 2] & 128) && ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)))) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else if ((bin[*bn + 3] & 2) == 2 && (bin[*bn + 2] & 128)) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("r%u ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 5 && (bin[*bn + 2] & 112) == 96) {
		printf("strbw%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 3] & 2) == 0 && (bin[*bn + 2] & 128)) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if ((bin[*bn + 3] & 2) == 0) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", -1 * (bin[*bn] + ((bin[*bn + 1] & 15) << 8)));
		}
		else if ((bin[*bn + 3] & 2) == 2 && (bin[*bn + 2] & 128) && ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)))) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("r%u), ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else if ((bin[*bn + 3] & 2) == 2 && (bin[*bn + 2] & 128)) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("r%u) ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 12) == 4 && (bin[*bn + 2] & 112) == 80) {
		printf("ldrb%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 3] & 3) == 1 && (bin[*bn + 2] & 128)) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if ((bin[*bn + 3] & 3) == 1) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", -1 * (bin[*bn] + ((bin[*bn + 1] & 15) << 8)));
		}
		else if ((bin[*bn + 3] & 3) == 0 && (bin[*bn + 2] & 128)) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if ((bin[*bn + 3] & 3) == 0) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", -1 * (bin[*bn] + ((bin[*bn + 1] & 15) << 8)));
		}
		else if ((bin[*bn + 3] & 3) == 3 && (bin[*bn + 2] & 128) && ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)))) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("r%u), ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else if ((bin[*bn + 3] & 3) == 3 && (bin[*bn + 2] & 128)) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("r%u) ", bin[*bn] & 15);
		}
		else if ((bin[*bn + 3] & 3) == 2 && (bin[*bn + 2] & 128) && ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)))) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else if ((bin[*bn + 3] & 3) == 2 && (bin[*bn + 2] & 128)) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("r%u ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 4 && (bin[*bn + 2] & 112) == 112) {
		printf("ldrbt%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 3] & 2) == 0 && (bin[*bn + 2] & 128)) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if ((bin[*bn + 3] & 2) == 0) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("%i ", -1 * (bin[*bn] + ((bin[*bn + 1] & 15) << 8)));
		}
		else if ((bin[*bn + 3] & 2) == 2 && (bin[*bn + 2] & 128) && ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)))) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else if ((bin[*bn + 3] & 2) == 2 && (bin[*bn + 2] & 128)) {
			printf("(r%u), ", bin[*bn + 2] & 15);
			printf("r%u ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 5 && (bin[*bn + 2] & 112) == 112) {
		printf("ldrbw%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		if ((bin[*bn + 3] & 2) == 0 && (bin[*bn + 2] & 128)) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if ((bin[*bn + 3] & 2) == 0) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("%i) ", -1 * (bin[*bn] + ((bin[*bn + 1] & 15) << 8)));
		}
		else if ((bin[*bn + 3] & 2) == 2 && (bin[*bn + 2] & 128) && ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)))) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("r%u), ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else if ((bin[*bn + 3] & 2) == 2 && (bin[*bn + 2] & 128)) {
			printf("(r%u, ", bin[*bn + 2] & 15);
			printf("r%u) ", bin[*bn] & 15);
		}
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 8 && (bin[*bn + 2] & 240) == 0) {
		printf("stmda%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("(r%u)", bin[*bn + 2] & 15);
		for (uint8_t i = 0; i < 16; i++) {
			if (i < 8) {
				if (bin[*bn] & (1 << i)) {
					printf(", r%u", i);
				}
			}
			else {
				if (bin[*bn + 1] & (1 << (i - 8))) {
					printf(", r%u", i);
				}
			}
		}
		printf(" ");
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 8 && (bin[*bn + 2] & 240) == 32) {
		printf("stmdaw%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("(r%u)", bin[*bn + 2] & 15);
		for (uint8_t i = 0; i < 16; i++) {
			if (i < 8) {
				if (bin[*bn] & (1 << i)) {
					printf(", r%u", i);
				}
			}
			else {
				if (bin[*bn + 1] & (1 << (i - 8))) {
					printf(", r%u", i);
				}
			}
		}
		printf(" ");
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 8 && (bin[*bn + 2] & 240) == 16) {
		printf("ldmda%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("(r%u)", bin[*bn + 2] & 15);
		for (uint8_t i = 0; i < 16; i++) {
			if (i < 8) {
				if (bin[*bn] & (1 << i)) {
					printf(", r%u", i);
				}
			}
			else {
				if (bin[*bn + 1] & (1 << (i - 8))) {
					printf(", r%u", i);
				}
			}
		}
		printf(" ");
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 8 && (bin[*bn + 2] & 240) == 48) {
		printf("ldmdaw%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("(r%u)", bin[*bn + 2] & 15);
		for (uint8_t i = 0; i < 16; i++) {
			if (i < 8) {
				if (bin[*bn] & (1 << i)) {
					printf(", r%u", i);
				}
			}
			else {
				if (bin[*bn + 1] & (1 << (i - 8))) {
					printf(", r%u", i);
				}
			}
		}
		printf(" ");
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 8 && (bin[*bn + 2] & 240) == 128) {
		printf("stmia%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("(r%u)", bin[*bn + 2] & 15);
		for (uint8_t i = 0; i < 16; i++) {
			if (i < 8) {
				if (bin[*bn] & (1 << i)) {
					printf(", r%u", i);
				}
			}
			else {
				if (bin[*bn + 1] & (1 << (i - 8))) {
					printf(", r%u", i);
				}
			}
		}
		printf(" ");
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 8 && (bin[*bn + 2] & 240) == 160) {
		printf("stmiaw%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("(r%u)", bin[*bn + 2] & 15);
		for (uint8_t i = 0; i < 16; i++) {
			if (i < 8) {
				if (bin[*bn] & (1 << i)) {
					printf(", r%u", i);
				}
			}
			else {
				if (bin[*bn + 1] & (1 << (i - 8))) {
					printf(", r%u", i);
				}
			}
		}
		printf(" ");
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 8 && bin[*bn + 2] == 157) {
		printf("pop%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		uint8_t a = 0;
		for (uint8_t i = 0; i < 16; i++) {
			if (i < 8) {
				if (bin[*bn] & (1 << i)) {
					if (a) {
						printf(", ");
					}
					printf("r%u", i);
					a = 1;
				}
				if (i == 7) {
					a = 0;
				}
			}
			else {
				if (bin[*bn + 1] & (1 << (i - 8))) {
					if (a) {
						printf(", ");
					}
					printf(", r%u", i);
					a = 1;
				}
			}
		}
		printf(" ");
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 8 && (bin[*bn + 2] & 240) == 144) {
		printf("ldmia%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("(r%u)", bin[*bn + 2] & 15);
		for (uint8_t i = 0; i < 16; i++) {
			if (i < 8) {
				if (bin[*bn] & (1 << i)) {
					printf(", r%u", i);
				}
			}
			else {
				if (bin[*bn + 1] & (1 << (i - 8))) {
					printf(", r%u", i);
				}
			}
		}
		printf(" ");
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 8 && (bin[*bn + 2] & 240) == 176) {
		printf("ldmiaw%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("(r%u)", bin[*bn + 2] & 15);
		for (uint8_t i = 0; i < 16; i++) {
			if (i < 8) {
				if (bin[*bn] & (1 << i)) {
					printf(", r%u", i);
				}
			}
			else {
				if (bin[*bn + 1] & (1 << (i - 8))) {
					printf(", r%u", i);
				}
			}
		}
		printf(" ");
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 9 && bin[*bn + 2] == 45) {
		printf("push%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		uint8_t a = 0;
		for (uint8_t i = 0; i < 16; i++) {
			if (i < 8) {
				if (bin[*bn] & (1 << i)) {
					if (a) {
						printf(", ");
					}
					printf("r%u", i);
					a = 1;
				}
				if (i == 7) {
					a = 0;
				}
			}
			else {
				if (bin[*bn + 1] & (1 << (i - 8))) {
					if (a) {
						printf(", ");
					}
					printf(", r%u", i);
					a = 1;
				}
			}
		}
		printf(" ");
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 9 && (bin[*bn + 2] & 240) == 0) {
		printf("stmdb%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("(r%u)", bin[*bn + 2] & 15);
		for (uint8_t i = 0; i < 16; i++) {
			if (i < 8) {
				if (bin[*bn] & (1 << i)) {
					printf(", r%u", i);
				}
			}
			else {
				if (bin[*bn + 1] & (1 << (i - 8))) {
					printf(", r%u", i);
				}
			}
		}
		printf(" ");
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 9 && (bin[*bn + 2] & 240) == 32) {
		printf("stmdbw%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("(r%u)", bin[*bn + 2] & 15);
		for (uint8_t i = 0; i < 16; i++) {
			if (i < 8) {
				if (bin[*bn] & (1 << i)) {
					printf(", r%u", i);
				}
			}
			else {
				if (bin[*bn + 1] & (1 << (i - 8))) {
					printf(", r%u", i);
				}
			}
		}
		printf(" ");
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 9 && (bin[*bn + 2] & 240) == 16) {
		printf("ldmdb%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("(r%u)", bin[*bn + 2] & 15);
		for (uint8_t i = 0; i < 16; i++) {
			if (i < 8) {
				if (bin[*bn] & (1 << i)) {
					printf(", r%u", i);
				}
			}
			else {
				if (bin[*bn + 1] & (1 << (i - 8))) {
					printf(", r%u", i);
				}
			}
		}
		printf(" ");
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 9 && (bin[*bn + 2] & 240) == 48) {
		printf("ldmdbw%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("(r%u)", bin[*bn + 2] & 15);
		for (uint8_t i = 0; i < 16; i++) {
			if (i < 8) {
				if (bin[*bn] & (1 << i)) {
					printf(", r%u", i);
				}
			}
			else {
				if (bin[*bn + 1] & (1 << (i - 8))) {
					printf(", r%u", i);
				}
			}
		}
		printf(" ");
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 9 && (bin[*bn + 2] & 240) == 128) {
		printf("stmib%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("(r%u)", bin[*bn + 2] & 15);
		for (uint8_t i = 0; i < 16; i++) {
			if (i < 8) {
				if (bin[*bn] & (1 << i)) {
					printf(", r%u", i);
				}
			}
			else {
				if (bin[*bn + 1] & (1 << (i - 8))) {
					printf(", r%u", i);
				}
			}
		}
		printf(" ");
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 9 && (bin[*bn + 2] & 240) == 160) {
		printf("stmibw%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("(r%u)", bin[*bn + 2] & 15);
		for (uint8_t i = 0; i < 16; i++) {
			if (i < 8) {
				if (bin[*bn] & (1 << i)) {
					printf(", r%u", i);
				}
			}
			else {
				if (bin[*bn + 1] & (1 << (i - 8))) {
					printf(", r%u", i);
				}
			}
		}
		printf(" ");
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 9 && (bin[*bn + 2] & 240) == 144) {
		printf("ldmib%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("(r%u)", bin[*bn + 2] & 15);
		for (uint8_t i = 0; i < 16; i++) {
			if (i < 8) {
				if (bin[*bn] & (1 << i)) {
					printf(", r%u", i);
				}
			}
			else {
				if (bin[*bn + 1] & (1 << (i - 8))) {
					printf(", r%u", i);
				}
			}
		}
		printf(" ");
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 9 && (bin[*bn + 2] & 240) == 176) {
		printf("ldmibw%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("(r%u)", bin[*bn + 2] & 15);
		for (uint8_t i = 0; i < 16; i++) {
			if (i < 8) {
				if (bin[*bn] & (1 << i)) {
					printf(", r%u", i);
				}
			}
			else {
				if (bin[*bn + 1] & (1 << (i - 8))) {
					printf(", r%u", i);
				}
			}
		}
		printf(" ");
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 10) { //todo
		printf("b%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("%u ", (uint32_t) (bin[*bn] + (bn[*bn + 1] << 8) + (bin[*bn + 2] << 16)));
		*bn += 4;
		*addr = ((bin[*bn] + (bn[*bn + 1] << 8) + (bin[*bn + 2] << 16)) * 4) + *bn + 8;
	}
	else if ((bin[*bn + 3] & 15) == 11) { //todo
		printf("bl%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("%u ", (uint32_t) (bin[*bn] + (bn[*bn + 1] << 8) + (bin[*bn + 2] << 16)));
		*bn += 4;
		*addr = ((bin[*bn] + (bn[*bn + 1] << 8) + (bin[*bn + 2] << 16)) * 4) + *bn + 8;
	}
	else if (bin[*bn + 3] == 250) { //todo
		printf("blx%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("%u ", (uint32_t) (bin[*bn] + (bn[*bn + 1] << 8) + (bin[*bn + 2] << 16)));
		*bn += 4;
		*addr = ((bin[*bn] + (bn[*bn + 1] << 8) + (bin[*bn + 2] << 16)) * 4) + *bn + 8;
	}
	else if ((bin[*bn + 3] & 13) == 0 && (bin[*bn + 2] & 224) == 0) {
		printf("and%s%s ", arm_32a_s(bin[*bn + 2] & 16), arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn + 2] & 15);
		
		if (bin[*bn + 3] & 2) {
			printf("%u ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("r%u) ", bin[*bn + 1] & 15);
		}
		else if ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)); 
		}
		else {
			printf("r%u ", bin[*bn] & 15);
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 0 && (bin[*bn + 2] & 224) == 32) {
		printf("eor%s%s ", arm_32a_s(bin[*bn + 2] & 16), arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn + 2] & 15);
		
		if (bin[*bn + 3] & 2) {
			printf("%u ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("r%u) ", bin[*bn + 1] & 15);
		}
		else if ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)); 
		}
		else {
			printf("r%u ", bin[*bn] & 15);
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 0 && (bin[*bn + 2] & 224) == 64) {
		printf("sub%s%s ", arm_32a_s(bin[*bn + 2] & 16), arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn + 2] & 15);
		
		if (bin[*bn + 3] & 2) {
			printf("%u ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("r%u) ", bin[*bn + 1] & 15);
		}
		else if ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)); 
		}
		else {
			printf("r%u ", bin[*bn] & 15);
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 0 && (bin[*bn + 2] & 224) == 96) {
		printf("rsb%s%s ", arm_32a_s(bin[*bn + 2] & 16), arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn + 2] & 15);
		
		if (bin[*bn + 3] & 2) {
			printf("%u ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("r%u) ", bin[*bn + 1] & 15);
		}
		else if ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)); 
		}
		else {
			printf("r%u ", bin[*bn] & 15);
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 0 && (bin[*bn + 2] & 224) == 128) {
		printf("add%s%s ", arm_32a_s(bin[*bn + 2] & 16), arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn + 2] & 15);
		
		if (bin[*bn + 3] & 2) {
			printf("%u ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("r%u) ", bin[*bn + 1] & 15);
		}
		else if ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)); 
		}
		else {
			printf("r%u ", bin[*bn] & 15);
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 0 && (bin[*bn + 2] & 224) == 160) {
		printf("adc%s%s ", arm_32a_s(bin[*bn + 2] & 16), arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn + 2] & 15);
		
		if (bin[*bn + 3] & 2) {
			printf("%u ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("r%u) ", bin[*bn + 1] & 15);
		}
		else if ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)); 
		}
		else {
			printf("r%u ", bin[*bn] & 15);
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 0 && (bin[*bn + 2] & 224) == 192) {
		printf("sbc%s%s ", arm_32a_s(bin[*bn + 2] & 16), arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn + 2] & 15);
		
		if (bin[*bn + 3] & 2) {
			printf("%u ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("r%u) ", bin[*bn + 1] & 15);
		}
		else if ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)); 
		}
		else {
			printf("r%u ", bin[*bn] & 15);
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 0 && (bin[*bn + 2] & 224) == 224) {
		printf("rsc%s%s ", arm_32a_s(bin[*bn + 2] & 16), arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn + 2] & 15);
		
		if (bin[*bn + 3] & 2) {
			printf("%u ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("r%u) ", bin[*bn + 1] & 15);
		}
		else if ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)); 
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
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("r%u) ", bin[*bn + 1] & 15);
		}
		else if ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)); 
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
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("r%u) ", bin[*bn + 1] & 15);
		}
		else if ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)); 
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
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("r%u) ", bin[*bn + 1] & 15);
		}
		else if ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)); 
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
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("r%u) ", bin[*bn + 1] & 15);
		}
		else if ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)); 
		}
		else {
			printf("r%u ", bin[*bn] & 15);
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 1 && (bin[*bn + 2] & 224) == 128) {
		printf("orr%s%s ", arm_32a_s(bin[*bn + 2] & 16), arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn + 2] & 15);
		
		if (bin[*bn + 3] & 2) {
			printf("%u ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("r%u) ", bin[*bn + 1] & 15);
		}
		else if ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("(%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("%u) ", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1)); 
		}
		else {
			printf("r%u ", bin[*bn] & 15);
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 1 && (bin[*bn + 2] & 224) == 160 && (bin[*bn] & 96) == 0 && !((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
		printf("mov%s%s ", arm_32a_s(bin[*bn + 2] & 16), arm_32a_c4(bin[*bn + 3] >> 4));
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
		printf("lsl%s%s ", arm_32a_s(bin[*bn + 2] & 16), arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn] & 15);
		
		if (bin[*bn] & 16) {
			printf("r%u ", bin[*bn + 1] & 15);
		}
		else {
			printf("%u", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 1 && (bin[*bn + 2] & 224) == 160 && (bin[*bn] & 96) == 32) {
		printf("lsr%s%s ", arm_32a_s(bin[*bn + 2] & 16), arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn] & 15);
		
		if (bin[*bn] & 16) {
			printf("r%u ", bin[*bn + 1] & 15);
		}
		else {
			printf("%u", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 1 && (bin[*bn + 2] & 224) == 160 && (bin[*bn] & 96) == 64) {
		printf("asr%s%s ", arm_32a_s(bin[*bn + 2] & 16), arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn] & 15);
		
		if (bin[*bn] & 16) {
			printf("r%u ", bin[*bn + 1] & 15);
		}
		else {
			printf("%u", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 1 && (bin[*bn + 2] & 224) == 160 && (bin[*bn] & 96) == 96) {
		printf("ror%s%s ", arm_32a_s(bin[*bn + 2] & 16), arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn] & 15);
		
		if (bin[*bn] & 16) {
			printf("r%u ", bin[*bn + 1] & 15);
		}
		else {
			printf("%u", (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 1 && (bin[*bn + 2] & 224) == 192) {
		printf("bic%s%s ", arm_32a_s(bin[*bn + 2] & 16), arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn + 2] & 15);
		
		if (bin[*bn + 3] & 2) {
			printf("%u ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("r%u ", bin[*bn + 1] & 15);
		}
		else if ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, %u", arm_32a_sh(bin[*bn] & 96), (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else {
			printf("r%u ", bin[*bn] & 15);
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 13) == 1 && (bin[*bn + 2] & 224) == 224) {
		printf("mvn%s%s ", arm_32a_s(bin[*bn + 2] & 16), arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 1] >> 4);
		printf("r%u, ", bin[*bn + 2] & 15);
		
		if (bin[*bn + 3] & 2) {
			printf("%u ", bin[*bn] + ((bin[*bn + 1] & 15) << 8));
		}
		else if (bin[*bn] & 16) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, ", arm_32a_sh(bin[*bn] & 96));
			printf("r%u ", bin[*bn + 1] & 15);
		}
		else if ((bin[*bn] & 96) || ((bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1))) {
			printf("r%u, ", bin[*bn] & 15);
			printf("%s, %u", arm_32a_sh(bin[*bn] & 96), (bin[*bn] >> 7) + ((bin[*bn + 1] & 15) << 1));
		}
		else {
			printf("r%u ", bin[*bn] & 15);
		}
		
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 0 && (bin[*bn + 2] & 224) == 0 && (bin[*bn] & 240) == 144) {
		printf("mul%s%s ", arm_32a_s(bin[*bn + 2] & 16), arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u ", bin[*bn + 1] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 0 && (bin[*bn + 2] & 224) == 32 && (bin[*bn] & 240) == 144) {
		printf("mla%s%s ", arm_32a_s(bin[*bn + 2] & 16), arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u ", bin[*bn + 1] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 0 && (bin[*bn + 2] & 240) == 64 && (bin[*bn] & 240) == 144) {
		printf("umaal%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u ", bin[*bn + 1] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 0 && (bin[*bn + 2] & 240) == 96 && (bin[*bn] & 240) == 144) {
		printf("mls%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u, ", bin[*bn + 1] & 15);
		printf("r%u ", (bin[*bn + 1] >> 4) & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 0 && (bin[*bn + 2] & 224) == 128 && (bin[*bn] & 240) == 144) {
		printf("umull%s%s ", arm_32a_s(bin[*bn + 2] & 16), arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u ", bin[*bn + 1] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 0 && (bin[*bn + 2] & 224) == 160 && (bin[*bn] & 240) == 144) {
		printf("umlal%s%s ", arm_32a_s(bin[*bn + 2] & 16), arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u ", bin[*bn + 1] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 0 && (bin[*bn + 2] & 224) == 192 && (bin[*bn] & 240) == 144) {
		printf("smull%s%s ", arm_32a_s(bin[*bn + 2] & 16), arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u ", bin[*bn + 1] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 0 && (bin[*bn + 2] & 224) == 224 && (bin[*bn] & 240) == 144) {
		printf("smlal%s%s ", arm_32a_s(bin[*bn + 2] & 16), arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u ", bin[*bn + 1] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 0 && (bin[*bn] & 240) == 80) {
		printf("qadd%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u ", bin[*bn] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 32 && (bin[*bn] & 240) == 80) {
		printf("qsub%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u ", bin[*bn] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 64 && (bin[*bn] & 240) == 80) {
		printf("qdadd%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u ", bin[*bn] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 96 && (bin[*bn] & 240) == 80) {
		printf("qdsub%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u ", bin[*bn] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 0 && (bin[*bn] & 240) == 128) {
		printf("smlabb%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u, ", bin[*bn + 1] & 15);
		printf("r%u ", (bin[*bn + 1] >> 4) & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 0 && (bin[*bn] & 240) == 160) {
		printf("smlatb%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u, ", bin[*bn + 1] & 15);
		printf("r%u ", (bin[*bn + 1] >> 4) & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 0 && (bin[*bn] & 240) == 192) {
		printf("smlabt%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u, ", bin[*bn + 1] & 15);
		printf("r%u ", (bin[*bn + 1] >> 4) & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 0 && (bin[*bn] & 240) == 224) {
		printf("smlatt%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u, ", bin[*bn + 1] & 15);
		printf("r%u ", (bin[*bn + 1] >> 4) & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 32 && (bin[*bn] & 240) == 128) {
		printf("smlawb%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u, ", bin[*bn + 1] & 15);
		printf("r%u ", (bin[*bn + 1] >> 4) & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 32 && (bin[*bn] & 240) == 192) {
		printf("smlawt%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u, ", bin[*bn + 1] & 15);
		printf("r%u ", (bin[*bn + 1] >> 4) & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 32 && (bin[*bn] & 240) == 160) {
		printf("smulwb%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u, ", bin[*bn + 1] & 15);
		printf("r%u ", (bin[*bn + 1] >> 4) & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 32 && (bin[*bn] & 240) == 224) {
		printf("smulwt%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u, ", bin[*bn + 1] & 15);
		printf("r%u ", (bin[*bn + 1] >> 4) & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 32 && (bin[*bn] & 240) == 128) {
		printf("smlawb%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u, ", bin[*bn + 1] & 15);
		printf("r%u ", (bin[*bn + 1] >> 4) & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 64 && (bin[*bn] & 240) == 128) {
		printf("smlalbb%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u ", bin[*bn + 1] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 64 && (bin[*bn] & 240) == 160) {
		printf("smlaltb%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u ", bin[*bn + 1] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 64 && (bin[*bn] & 240) == 192) {
		printf("smlalbt%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u ", bin[*bn + 1] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 64 && (bin[*bn] & 240) == 224) {
		printf("smlaltt%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u ", bin[*bn + 1] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 96 && (bin[*bn] & 240) == 128) {
		printf("smulbb%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u ", bin[*bn + 1] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 96 && (bin[*bn] & 240) == 160) {
		printf("smultb%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u ", bin[*bn + 1] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 96 && (bin[*bn] & 240) == 192) {
		printf("smulbt%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u ", bin[*bn + 1] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 96 && (bin[*bn] & 240) == 224) {
		printf("smultt%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", bin[*bn + 2] & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u ", bin[*bn + 1] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 0 && (bin[*bn] & 240) == 144) {
		printf("swp%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u ", bin[*bn + 2] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 64 && (bin[*bn] & 240) == 144) {
		printf("swpb%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u ", bin[*bn + 2] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 128 && (bin[*bn] & 240) == 144) {
		printf("strex%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u ", bin[*bn + 2] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 144 && (bin[*bn] & 240) == 144) {
		printf("ldrex%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		printf("r%u ", bin[*bn + 2] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 160 && (bin[*bn] & 240) == 144) {
		printf("strexd%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u ", bin[*bn + 2] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 176 && (bin[*bn] & 240) == 144) {
		printf("ldrexd%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u ", bin[*bn + 2] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 192 && (bin[*bn] & 240) == 144) {
		printf("strexb%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u ", bin[*bn + 2] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 208 && (bin[*bn] & 240) == 144) {
		printf("ldrexb%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u ", bin[*bn + 2] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 224 && (bin[*bn] & 240) == 144) {
		printf("strexh%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u ", bin[*bn + 2] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 1 && (bin[*bn + 2] & 240) == 240 && (bin[*bn] & 240) == 144) {
		printf("ldrexh%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		printf("r%u, ", bin[*bn] & 15);
		printf("r%u ", bin[*bn + 2] & 15);
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 3 && (bin[*bn + 2] & 240) == 16) {
		printf("movt%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		printf("r%u, ", (bin[*bn + 1] >> 4) & 15);
		printf("%u ", bin[*bn] + ((bin[*bn + 1] & 15) << 8) + ((bin[*bn + 2] & 15) << 12));
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 3 && (bin[*bn + 2] & 240) == 32 && bin[*bn] == 0) {
		printf("nop%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 3 && (bin[*bn + 2] & 240) == 32 && bin[*bn] == 1) {
		printf("yield%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 3 && (bin[*bn + 2] & 240) == 32 && bin[*bn] == 2) {
		printf("wfe%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 3 && (bin[*bn + 2] & 240) == 32 && bin[*bn] == 3) {
		printf("wfi%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		*bn += 4;
	}
	else if ((bin[*bn + 3] & 15) == 3 && (bin[*bn + 2] & 240) == 32 && bin[*bn] == 4) {
		printf("sev%s ", arm_32a_c4(bin[*bn + 3] >> 4));
		*bn += 4;
	}
	else {
		printf("~byt4 %u", bin[*bn]);
		*bn += 4;
	}
}
