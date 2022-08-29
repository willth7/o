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

int8_t main(int32_t argc, int8_t** argv) {
	if (argc != 3) {
		printf("usage: o [architecture] [binary.bin or link.zn]\n");
		return -1;
	}
	
	if (!strcmp(argv[1], "avr")) {
		
	}
	else {
		printf("error: unsupported architecture\n");
	}
	
	if (!strcmp(argv[2] + strlen(argv[2]) - 4, ".bin")) {
		
	}
	else if (!strcmp(argv[2] + strlen(argv[2]) - 3, ".zn")) {
		
	}
	else {
		printf("error: invalid input format\n");
		return -1;
	}
	
	return 0;
}
