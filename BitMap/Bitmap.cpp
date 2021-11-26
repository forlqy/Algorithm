#include "Bitmap.h"

bool Bitmap::test(int k) {
	return M[k >> 3] & (0x80 >> (k & 0x07));
}

void Bitmap::set(int k) {
	expand(k);
	M[k >> 3] |= (0x80 >> (k & 0x07));
}

void Bitmap::clear(int k) {
	expand(k);
	M[k >> 3] &= (0x80 >> (k & 0x07));
}