#include "framework/crypto_provider.h"
#include "framework/crypto_params.h"
#include "framework/crypto_algorithm_ids.h"
#include "providers/provider.h"
#include "algorithms/algos.h"


//extern const crypto_provider_t provider_mbedtls;

int main(void)
{
    const crypto_provider_t *provider = &provider_mbedtls;

    /* Prepare test vector */
    const uint8_t msg[] = "abc";
    uint8_t digest[32];

    crypto_sha256(provider, msg, sizeof(msg) - 1, digest);

    return 0;
}
