#include <stddef.h>
#include <sys/types.h>
#include "frame_control.h"
#include <stdlib.h>
#include <string.h>

#ifndef FRAME_H
#define FRAME_H

#define REAL_DATA_SIZE(buff, num) \
    num -= 8; \
    num += strlen((u_int8_t*) buff->data); \

#define BROADCAST_MAC {(u_int8_t) 0xFF, (u_int8_t) 0xFF, (u_int8_t) 0xFF, (u_int8_t) 0xFF, (u_int8_t) 0xFF, (u_int8_t) 0xFF}

#define CHECK_REST(buffer, num) \
    if (buffer->seq_control == NO_DATA) \
        num -= 2; \
    if (buffer->qos_control == NO_DATA) \
        num -= 2; \
    if (buffer->ht_control == NO_DATA) \
        num -= 4; \

#define SIZE_WITH_NO_ALIGNMENT(num)\
    num -= 8;

#define TOTAL_ADDRESSES_SIZE(buffer, num) \
    if (buffer->addr_2 == NULL) \
        num -= 6; \
    if (buffer->addr_3 == NULL) \
        num -= 6; \
    if (buffer->addr_4 == NULL) \
        num -= 6; \

typedef struct
{
    u_int16_t frame_control;
    u_int16_t frame_id_or_duration;
    u_int8_t addr_1[6];
    u_int8_t addr_2[6];
    u_int8_t addr_3[6];
    u_int16_t seq_control;
    u_int8_t addr_4[6];
    u_int16_t qos_control;
    u_int32_t ht_control;
    u_int8_t* data;
    u_int32_t frame_check_seq;

} IEEE_80211_frame;

size_t sizof_IEEE_80211_frame(IEEE_80211_frame*);
void* to_raw_80211_buffer(IEEE_80211_frame*);

#endif