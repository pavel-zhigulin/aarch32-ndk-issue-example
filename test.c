
#include <arm_neon.h>
#include <arm_acle.h>
#include <stdint.h>
#include <stddef.h>

static inline void
prepareInterleavedKeys(
     uint8_t* roundKeys
) {
     enum {
          roundKeySize = 16
     };
     uint8_t* output = roundKeys;
     uint8x16x4_t  keys_0_3;
     uint8x16x4_t  keys_4_7;
     uint8x16x3_t  keys_8_10;
     uint8x16x4_t  buff;

     keys_0_3  = vld1q_u8_x4(roundKeys);
     keys_4_7  = vld1q_u8_x4(roundKeys + roundKeySize * 4);
     keys_8_10 = vld1q_u8_x3(roundKeys + roundKeySize * 8);

     for(size_t i = 0; i < 4u; ++i) {
          buff.val[0] = keys_0_3.val[i];
          buff.val[1] = keys_0_3.val[i];
          buff.val[2] = keys_0_3.val[i];
          buff.val[3] = keys_0_3.val[i];

          vst1q_u8_x4(output, buff);
          output += roundKeySize * 4;
     }

     for(size_t i = 0; i < 4u; ++i) {
          buff.val[0] = keys_4_7.val[i];
          buff.val[1] = keys_4_7.val[i];
          buff.val[2] = keys_4_7.val[i];
          buff.val[3] = keys_4_7.val[i];

          vst1q_u8_x4(output, buff);
          output += roundKeySize * 4;
     }

     for(size_t i = 0; i < 3u; ++i) {
          buff.val[0] = keys_8_10.val[i];
          buff.val[1] = keys_8_10.val[i];
          buff.val[2] = keys_8_10.val[i];
          buff.val[3] = keys_8_10.val[i];

          vst1q_u8_x4(output, buff);
          output += roundKeySize * 4;
     }
}

int main(void) {
     uint8_t keys[704] = {0};
     prepareInterleavedKeys(keys);
}