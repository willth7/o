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
	
	if ((bin[*bn + 1] & 224) != 224 && (bin[*bn + 1] & 248) == 0 && !(((bin[*bn] >> 6) & 3) + ((bin[*bn] << 2) & 28))) {
		printf("mov ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u ", (bin[*bn] >> 3) & 7);
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 224) != 224 && (bin[*bn + 1] & 248) == 0) {
		printf("lsl ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u, ", (bin[*bn] >> 3) & 7);
		printf("%hhu ", ((bin[*bn] >> 6) & 3) + ((bin[*bn] << 2) & 28));
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 224) != 224 && (bin[*bn + 1] & 248) == 8) {
		printf("lsr ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u, ", (bin[*bn] >> 3) & 7);
		printf("%hhu ", ((bin[*bn] >> 6) & 3) + ((bin[*bn] << 2) & 28));
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 224) != 224 && (bin[*bn + 1] & 248) == 16) {
		printf("asr ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u, ", (bin[*bn] >> 3) & 7);
		printf("%hhu ", ((bin[*bn] >> 6) & 3) + ((bin[*bn] << 2) & 28));
		*bn += 2;
	}
	else if ((bin[*bn + 1] & 224) != 224 && (bin[*bn + 1] & 254) == 24) {
		printf("add ");
		printf("r%u, ", bin[*bn] & 7);
		printf("r%u, ", (bin[*bn] >> 3) & 7);
		printf("r%u ", ((bin[*bn] >> 6) & 3) + ((bin[*bn] << 2) & 4));
		*bn += 2;
	}
	else {
		printf("~byte %hhu", bin[*bn]);
		*bn += 2;
	}
}
