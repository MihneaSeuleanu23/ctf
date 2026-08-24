#include "../framework/crypto_provider.h"
#include "../framework/crypto_params.h"

#include <stdio.h> // just for testing

//#include "mbedtls/sha256.h"

/*
 * mbedTLS SHA-256 implementation
 * Uses crypto_params_t:
 *   in1      = message
 *   in1_len  = message length
 *   out      = digest (32 bytes)
 *   out_len  = 32
 */

static int mbedtls_sha256_provider(const crypto_params_t *p)
{
    // if (p == NULL || p->out == NULL)
    //     return -1;

    // if (p->out_len < 32)
    //     return -1;

    // mbedtls_sha256_context ctx;
    // mbedtls_sha256_init(&ctx);

    // if (mbedtls_sha256_starts_ret(&ctx, 0) != 0) {
    //     mbedtls_sha256_free(&ctx);
    //     return -1;
    // }

    // if (p->in1 != NULL && p->in1_len > 0) {
    //     if (mbedtls_sha256_update_ret(&ctx, p->in1, p->in1_len) != 0) {
    //         mbedtls_sha256_free(&ctx);
    //         return -1;
    //     }
    // }

    // if (mbedtls_sha256_finish_ret(&ctx, p->out) != 0) {
    //     mbedtls_sha256_free(&ctx);
    //     return -1;
    // }

    // mbedtls_sha256_free(&ctx);
    printf("Hello from SHA-256 provider");
    return 0;
}

/*
 * Exported mbedTLS provider instance.
 * You typically declare this in a header:
 *   extern const crypto_provider_t provider_mbedtls_sha2;
 */

const crypto_provider_t provider_mbedtls = {
    .funcs = {
        [CRYPTO_ALG_SHA2] = mbedtls_sha256_provider,
    },
    .caps = (1u << CRYPTO_ALG_SHA2)
};
