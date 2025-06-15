// crypto_utils.c
// Secure IoT Framework cryptographic utilities

#include <stdio.h>
#include <string.h>
#include <openssl/sha.h>

void sha256(const char *str, unsigned char output[SHA256_DIGEST_LENGTH]) {
    SHA256_CTX ctx;
    SHA256_Init(&ctx);
    SHA256_Update(&ctx, str, strlen(str));
    SHA256_Final(output, &ctx);
}

// Example usage
int main() {
    const char *msg = "Hello, Secure IoT!";
    unsigned char hash[SHA256_DIGEST_LENGTH];
    sha256(msg, hash);

    printf("SHA-256: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++)
        printf("%02x", hash[i]);
    printf("\n");
    return 0;
}

// TODO: Implement cryptographic functions 