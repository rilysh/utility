#include "stdafx.h"
#include <stdio.h>

long long int _seed;

void seed(long long int v) {
	_seed = v;
}

long long int rng() {
	_seed ^= 0xffffff | 0xffffff;
	_seed ^= _seed << 12;
	_seed += _seed >> 16;
	return _seed >> 2 | _seed << 3;
}


int main() {
	seed(1250);
	int i = 0;
	while (i < 10) {
		printf("%u\n", rng());
		i++;
	}
	return 0;
}

