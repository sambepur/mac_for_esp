#include "include/frame.h"


void mapper_init(mapper* mpp) {
    mpp->size = SIZE_WITH_NESESSARY_FIELDS_ONLY;
    mpp->map = NESESSARY_MAP_FIELD;
    TOTAL_ADDRESSES_SIZE(mpp);
    CHECK_REST(mpp);
    mpp->size += strlen(mpp->frame.data);
    mpp->payload_size = strlen(mpp->frame.data);
}

void* to_raw_80211_buffer(mapper* mpp) {
    u_int8_t* buff = (u_int8_t*) malloc(mpp->size);
    u_int8_t offset = 0;
    if (mpp->map & FC_PRESENT) {
        BIN_WORD_INTO_ARRAY(mpp->frame.frame_control, buff, offset);
        offset++;
    }
    if (mpp->map & DI_PRESENT) {
        BIN_WORD_INTO_ARRAY(mpp->frame.frame_id_or_duration, buff, offset);
        offset++;
    }
    if (mpp->map & AD1_PRESENT) {
        cut(mpp->frame.addr_1, buff, offset, 6);
        offset += 5;
    }
    if (mpp->map & AD2_PRESENT) {
        cut(mpp->frame.addr_2, buff, offset, 6);
        offset+=5;
    }
    if (mpp->map & AD3_PRESENT) {
        cut(mpp->frame.addr_3, buff, offset, 6);
        offset+=5;
    }
    if (mpp->map & SC_PRESENT) {
        BIN_WORD_INTO_ARRAY(mpp->frame.seq_control, buff, offset);
        offset++;
    }
    if (mpp->map & AD4_PRESENT) {
        cut(mpp->frame.addr_4, buff, offset, 6);
        offset+=5;
    }
    if (mpp->map & QOS_PRESENT) {
        BIN_WORD_INTO_ARRAY(mpp->frame.qos_control, buff, offset);
        offset++;
    }
    if (mpp->map & HT_PRESENT) {
        buff[offset] = BIN_WORD_LOW_BITS(mpp->frame.ht_control);
        buff[offset+1] = BIN_WORD_HIGH_BITS(mpp->frame.ht_control);
        buff[offset+2] = THIRD_OCTET(mpp->frame.ht_control);
        offset+=2;
    }
    if (mpp->map & DAT_PRESENT) {
        cut(mpp->frame.data, buff, offset, mpp->payload_size);
        offset += mpp->payload_size;
    }
    if (mpp->map & FCS_PRESENT) {
        buff[offset] = BIN_WORD_LOW_BITS(mpp->frame.frame_check_seq);
        buff[offset+1] = BIN_WORD_HIGH_BITS(mpp->frame.frame_check_seq);
        buff[offset+2] = THIRD_OCTET(mpp->frame.frame_check_seq);
        offset+=2;
    }
    return buff;
}