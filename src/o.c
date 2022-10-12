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

#include "arm/32a.h"
#include "arm/32m.h"
#include "arm/64.h"
#include "x86/x86.h"
#include "x86/i386.h"
#include "x86/x64.h"

typedef struct o_sym_s {
	int64_t str;
	uint64_t addr;
	uint8_t typ;
} o_sym_t;

void (*o_read) (uint8_t*, uint64_t*, o_sym_t*, uint64_t*, int8_t*, int8_t*);

void (*o_dec) (uint8_t*, uint64_t*, uint64_t*);

void o_dasm(uint8_t* bin, uint64_t bn, o_sym_t* sym, uint64_t symn, int8_t* e) {
	uint64_t bi = 0;
	while (bi < bn) {
		for (uint64_t i = 0; i < symn; i++) {
			if (sym[i].addr == bi) {
				printf("(%s)\n", (int8_t*) &(sym[i].str));
			}
		}
		
		uint64_t addr = (uint64_t) -1;
		o_dec(bin, &bi, &addr);
		
		if (addr != (uint64_t) -1) {
			for (uint64_t i = 0; i < symn; i++) {
				if (sym[i].addr == addr) {
					printf("; *%s", (int8_t*) &(sym[i].str));
				}
			}
		}
		printf("\n");
	}
}

void o_read_bin(uint8_t* bin, uint64_t* bn, o_sym_t* sym, uint64_t* symn,int8_t* path, int8_t* e) {
	FILE* f = fopen(path, "r");
	if (!f) {
		printf("[%s] error: file doesn't exist\n", path);
		*e = -1;
		return;
	}
	fseek(f, 0, SEEK_END);
	uint64_t fn = ftell(f);
	uint8_t* fx = malloc(fn);
	fseek(f, 0, SEEK_SET);
	fread(fx, fn, 1, f);
	fclose(f);
	
	memcpy(bin, fx, fn);
	*bn = fn;
}

void o_read_zn(uint8_t* bin, uint64_t* bn, o_sym_t* sym, uint64_t* symn,int8_t* path, int8_t* e) {
	FILE* f = fopen(path, "r");
	if (!f) {
		printf("[%s] error: file doesn't exist\n", path);
		*e = -1;
		return;
	}
	fseek(f, 0, SEEK_END);
	uint64_t fn = ftell(f);
	uint8_t* fx = malloc(fn);
	fseek(f, 0, SEEK_SET);
	fread(fx, fn, 1, f);
	fclose(f);
	
	uint32_t mag = *((uint32_t*) fx);
	uint64_t binoff = *((uint64_t*) (fx + 4));
	*bn = *((uint64_t*) (fx + 12));
	uint64_t symoff = *((uint64_t*) (fx + 20));
	*symn = *((uint64_t*) (fx + 28));
	
	if (mag != 1668180346) {
		printf("[%s] error: corrupted file\n", path);
		*e = -1;
		return;
	}
	
	memcpy(bin, fx + binoff, *bn);
	
	for (uint64_t i = 0; i < *symn; i++) {
		sym[i].str = *((uint64_t*) (fx + symoff + (17 * i)));
		sym[i].addr = *((uint64_t*) (fx + symoff + (17 * i) + 8));
		sym[i].typ = *(fx + symoff + (17 * i) + 16);
	}
	
	free(fx);
}

int8_t main(int32_t argc, int8_t** argv) {
	if (argc != 3) {
		printf("usage: o [architecture] [binary.bin or link.zn]\n");
		return -1;
	}
	
	if (!strcmp(argv[1], "aarch32-a")) {
		o_dec = arm_32a_dec;
	}
	else if (!strcmp(argv[1], "aarch32-m")) {
		o_dec = arm_32m_dec;
	}
	else if (!strcmp(argv[1], "aarch64")) {
		o_dec = arm_64_dec;
	}
	else if (!strcmp(argv[1], "x86")) {
		o_dec = x86_dec;
	}
	else if (!strcmp(argv[1], "i386")) {
		o_dec = i386_dec;
	}
	else if (!strcmp(argv[1], "x86-64")) {
		o_dec = x86_64_dec;
	}
	else {
		printf("error: unsupported architecture\n");
	}
	
	if (!strcmp(argv[2] + strlen(argv[2]) - 4, ".bin")) {
		o_read = o_read_bin;
	}
	else if (!strcmp(argv[2] + strlen(argv[2]) - 3, ".zn")) {
		o_read = o_read_zn;
	}
	else {
		printf("error: invalid input format\n");
		return -1;
	}
	
	uint8_t* bin = calloc(1000, 1);
	uint64_t bn = 0;
	o_sym_t* sym = calloc(1000, 1);
	uint64_t symn = 0;
	
	int8_t e = 0;
	
	o_read(bin, &bn, sym, &symn, argv[2], &e);
	
	if (!e) {
		o_dasm(bin, bn, sym, symn, &e);
	}
	
	free(bin);
	free(sym);
	return 0;
}
