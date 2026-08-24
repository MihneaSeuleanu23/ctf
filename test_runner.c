#include "framework/crypto_provider.h"
#include "framework/crypto_params.h"
#include "framework/crypto_algorithm_ids.h"
#include "providers/provider.h"


//extern const crypto_provider_t provider_mbedtls;

int main(void)
{
    const crypto_provider_t *provider = &provider_mbedtls;

    /* Prepare test vector */
    const uint8_t msg[] = "abc";
    uint8_t digest[32];

    crypto_params_t params = {
        .in1     = msg,
        .in1_len = sizeof(msg) - 1,
        .out     = digest,
        .out_len = sizeof(digest)
    };

    int rc = provider->funcs[CRYPTO_ALG_SHA2](&params);

    return 0;
}
