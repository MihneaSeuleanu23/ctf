#include "../framework/crypto_provider.h"
#include "../framework/crypto_params.h"
#include "../framework/crypto_algorithm_ids.h"

/*
 * Generic SHA-256 algorithm wrapper.
 * This does NOT implement SHA-256.
 * It simply calls the provider's implementation.
 */

int crypto_sha256(const crypto_provider_t *provider,
                  const uint8_t *msg,
                  size_t msg_len,
                  uint8_t *digest32)
{
    if (!provider)
        return -1;

    if (!(provider->caps & (1u << CRYPTO_ALG_SHA2)))
        return -1;

    crypto_params_t params = {
        .in1     = msg,
        .in1_len = msg_len,
        .out     = digest32,
        .out_len = 32
    };

    return provider->funcs[CRYPTO_ALG_SHA2](&params);
}
