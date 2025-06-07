#include <stdio.h>
#include <string.h>
#include <oqs/kem.h>

int main() {
    // Initialize the Kyber-512 KEM
    OQS_KEM *kem = OQS_KEM_new(OQS_KEM_alg_kyber_512);
    if (kem == NULL) {
        fprintf(stderr, "Failed to initialize Kyber-512 KEM\n");
        return 1;
    }

    // Allocate memory for keys and shared secrets
    uint8_t *public_key = malloc(kem->length_public_key);
    uint8_t *secret_key = malloc(kem->length_secret_key);
    uint8_t *ciphertext = malloc(kem->length_ciphertext);
    uint8_t *shared_secret_enc = malloc(kem->length_shared_secret);
    uint8_t *shared_secret_dec = malloc(kem->length_shared_secret);

    if (!public_key || !secret_key || !ciphertext || !shared_secret_enc || !shared_secret_dec) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // Generate key pair
    if (OQS_KEM_keypair(kem, public_key, secret_key) != OQS_SUCCESS) {
        fprintf(stderr, "Key pair generation failed\n");
        return 1;
    }

    // Encapsulate
    if (OQS_KEM_encaps(kem, ciphertext, shared_secret_enc, public_key) != OQS_SUCCESS) {
        fprintf(stderr, "Encapsulation failed\n");
        return 1;
    }

    // Decapsulate
    if (OQS_KEM_decaps(kem, shared_secret_dec, ciphertext, secret_key) != OQS_SUCCESS) {
        fprintf(stderr, "Decapsulation failed\n");
        return 1;
    }

    // Check that both shared secrets match
    if (memcmp(shared_secret_enc, shared_secret_dec, kem->length_shared_secret) != 0) {
        fprintf(stderr, "Shared secrets do not match\n");
        return 1;
    }

    printf("ML-KEM Kyber-512 test passed\n");

    OQS_MEM_insecure_free(public_key);
    OQS_MEM_insecure_free(secret_key);
    OQS_MEM_insecure_free(ciphertext);
    OQS_MEM_insecure_free(shared_secret_enc);
    OQS_MEM_insecure_free(shared_secret_dec);
    OQS_KEM_free(kem);
    return 0;
}
