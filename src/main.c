#include "include/main.h"

int main() {
    mapper mpp;
    unsigned char payload[2] = {0xD, 0xB};
    IEEE_80211_frame frame = {
        .frame_control = FC_VER | FC_TYPE_DATA | FC_SUBTYPE_DATA | FC_TO_DS,
        .frame_id_or_duration = PAYLOAD_16,
        .addr_1 = BROADCAST_MAC,
        .addr_2 = BROADCAST_MAC,
        .addr_3 = NO_ADDR_DATA,
        .seq_control = PAYLOAD_16,
        .addr_4 = BROADCAST_MAC,
        .qos_control = PAYLOAD_16,
        .ht_control = PAYLOAD_32,
        .data = (void*) payload,
        .frame_check_seq = PAYLOAD_32
    };
    mpp.frame = frame;
    mapper_init(&mpp);
    void* pckt = to_raw_80211_buffer(&mpp);
    if (pckt == NULL) {
        printf("pckt failed\n");
        return -1;
    }
    for (int i = 0; i<mpp.size; i++) {
        printf("%x ", ((u_int8_t*)pckt)[i]);
    }
    printf("\n%b\n", mpp.map);
    printf("size: %lu\n", mpp.size);
}