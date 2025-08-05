#ifndef BINARY_H
#define BINARY_H

#define BIN_WORD_LOW_BITS(num) num & 0xFF
#define BIN_WORD_HIGH_BITS(num) (num & 0xFF00) >> 8
#define THIRD_OCTET(num) (num & 0xFF0000) >> 16
#define FORTH_OCTET(num) (num & 0xFF000000) >> 24

#define BIN_WORD_INTO_ARRAY(word, buff, ind) \
    buff[ind] = BIN_WORD_HIGH_BITS(word); \
    buff[ind+1] = BIN_WORD_LOW_BITS(word); \

#define BIN_DWORD_INTO_ARRAY(dword, buff, ind) \
    buff[ind] = FORTH_OCTET(dword); \
    buff[ind+1] = THIRD_OCTET(dword); \
    buff[ind+2] = BIN_WORD_HIGH_BITS(dword); \
    buff[ind+3] = BIN_WORD_LOW_BITS(dword); \

#endif