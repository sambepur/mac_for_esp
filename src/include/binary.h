#ifndef BINARY_H
#define BINARY_H

#define BIN_WORD_LOW_BITS(num) num & 0xFF
#define BIN_WORD_HIGH_BITS(num) (num & 0xFF00) >> 8
#define THIRD_OCTET(num) (num & 0xFF0000) >> 16
#endif