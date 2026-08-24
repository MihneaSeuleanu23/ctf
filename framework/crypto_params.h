#ifndef CRYPTO_PARAMS_H
#define CRYPTO_PARAMS_H

#include <stdint.h>
#include <stddef.h>

/*
 * Generic parameter structure for all algorithms.
 *
 * Algorithms interpret only the fields they need.
 *
 * Examples:
 *
 * SHA-256:
 *   in1      = message
 *   in1_len  = message length
 *   out      = digest (32 bytes)
 *   out_len  = 32
 *
 * HMAC-SHA256:
 *   in1      = key
 *   in1_len  = key length
 *   in2      = message
 *   in2_len  = message length
 *   out      = digest (32 bytes)
 *
 * HKDF-SHA256:
 *   in1      = IKM
 *   in2      = salt
 *   in3      = info
 *   out      = OKM
 *
 * AES-GCM:
 *   in1      = key
 *   in2      = IV
 *   in3      = AAD
 *   out      = ciphertext (or plaintext)
 *
 * ECC algorithms use dedicated ECC parameter structs
 * (not included here to keep the core clean).
 */

typedef struct {

    const uint8_t *in1;
    size_t         in1_len;

    const uint8_t *in2;
    size_t         in2_len;

    const uint8_t *in3;
    size_t         in3_len;

    uint8_t       *out;
    size_t         out_len;

} crypto_params_t;

#endif
