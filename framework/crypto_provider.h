#ifndef CRYPTO_PROVIDER_H
#define CRYPTO_PROVIDER_H

#include <stdint.h>
#include "crypto_algorithm_ids.h"
#include "crypto_params.h"

/*
 * Provider function type.
 * Every algorithm implementation matches this signature.
 *
 * Providers interpret crypto_params_t according to the algorithm ID.
 */
typedef int (*crypto_func_t)(const crypto_params_t *params);

/*
 * Provider structure.
 *
 * funcs[] is indexed by crypto_algorithm_id_t.
 * caps is a bitmask of supported algorithms.
 *
 * Adding a new algorithm:
 *   1. Add enum value in crypto_algorithm_ids.h
 *   2. Provider sets funcs[id] = implementation
 *   3. Provider sets caps |= (1u << id)
 *
 * No struct changes required.
 */

typedef struct {
    crypto_func_t funcs[64];   /* supports up to 64 algorithms */
    uint64_t      caps;        /* bitmask of supported algorithms */
} crypto_provider_t;

#endif
