#ifndef ALGOS_H
#define ALGOS_H

#include <stdint.h>

int crypto_sha256(const crypto_provider_t *provider,
                  const uint8_t *msg,
                  size_t msg_len,
                  uint8_t *digest32);

#endif