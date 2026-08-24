#ifndef CRYPTO_ALGORITHM_IDS_H
#define CRYPTO_ALGORITHM_IDS_H

/*
 * Global list of supported algorithms.
 * Extend freely without modifying any provider structs.
 */

typedef enum
{
    CRYPTO_ALG_NONE = 0,

    /* Hashes */
    CRYPTO_ALG_SHA2 = 1,
    CRYPTO_ALG_SHA3 = 2

    // ... to be added

} crypto_algorithms_id_t;

#endif // CRYPTO_ALGORITHMS_IDS_H