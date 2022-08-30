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

void avr_dec(uint8_t* bin, uint64_t* bn, uint64_t* addr) {
	printf("%02x %02x    ", bin[*bn + 1], bin[*bn]);
	
	if (bin[*bn + 1] == 0 && bin[*bn] == 0) {
		printf("nop ");
		*bn += 2;
	}
	else if (bin[*bn + 1] == 1) {
		printf("movw ");
		printf("r%u, ", ((bin[*bn] >> 4) & 15) * 2);
		printf("r%u ", ((bin[*bn]) & 15) * 2);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 2) {
		printf("muls ");
		printf("r%u, ", ((bin[*bn] >> 4) & 15) + 16);
		printf("r%u ", ((bin[*bn]) & 15) + 16);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 3 && (bin[*bn] & 136) == 0) {
		printf("mulsu ");
		printf("r%u, ", ((bin[*bn] >> 4) & 7) + 16);
		printf("r%u ", ((bin[*bn]) & 7) + 16);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 3 && (bin[*bn] & 136) == 8) {
		printf("fmul ");
		printf("r%u, ", ((bin[*bn] >> 4) & 7) + 16);
		printf("r%u ", ((bin[*bn]) & 7) + 16);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 3 && (bin[*bn] & 136) == 128) {
		printf("fmuls ");
		printf("r%u, ", ((bin[*bn] >> 4) & 7) + 16);
		printf("r%u ", ((bin[*bn]) & 7) + 16);
		*bn += 2;
	}
	else if (bin[*bn + 1] == 3 && (bin[*bn] & 136) == 136) {
		printf("fmulsu ");
		printf("r%u, ", ((bin[*bn] >> 4) & 7) + 16);
		printf("r%u ", ((bin[*bn]) & 7) + 16);
		*bn += 2;
	}
	else {
		printf("~byt2 %hu", ((bin[*bn + 1] << 8) + bin[*bn]));
		*bn += 2;
	}
}
