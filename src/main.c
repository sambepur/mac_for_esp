#include "include/main.h"

int main() {
    mapper mpp;
    unsigned char payload[2] = {0xA, 0xB};
    IEEE_80211_frame frame = {
        .frame_control = FC_VER | FC_TYPE_DATA | FC_SUBTYPE_DATA | FC_TO_DS,
        .frame_id_or_duration = EMPTY,
        .addr_1 = BROADCAST_MAC,
        .addr_2 = BROADCAST_MAC,
        .addr_3 = BROADCAST_MAC,
        .seq_control = EMPTY,
        .addr_4 = BROADCAST_MAC,
        .qos_control = EMPTY,
        .ht_control = EMPTY,
        .data = (void*) payload,
        .frame_check_seq = EMPTY
    };
    mpp.frame = frame;
    mapper_init(&mpp);
    printf("size: %lu\n", mpp.size);
}