#include "include/frame.h"

size_t sizof_IEEE_80211_frame(IEEE_80211_frame* frame) {
    size_t total = sizeof(*frame);
    TOTAL_ADDRESSES_SIZE(frame, total)
    CHECK_REST(frame, total)
    REAL_DATA_SIZE(frame, total);
    SIZE_WITH_NO_ALIGNMENT(total)
    return total;
}

void* to_raw_80211_buffer(IEEE_80211_frame* frame) {
     void* buff = malloc(sizof_IEEE_80211_frame(frame));
     if (buff != NULL) {
        return buff;
     }
     return NULL;
}