#include <openssl/aes.h>
#include <openssl/rand.h>
#include <iostream>

int main() {
    // Generate a 128-bit (16-byte) AES key
    unsigned char aes_key[16];
    if (RAND_bytes(aes_key, 16) != 1) {
        std::cerr << "Error generating AES key" << std::endl;
        return 1;
    }

    // Print the generated key in hexadecimal format
    for (int i = 0; i < 16; i++) {
        printf("%02x", aes_key[i]);
    }
    std::cout << std::endl;

    // Generate a 192-bit (24-byte) AES key
    unsigned char aes_key_192[24];
    if (RAND_bytes(aes_key_192, 24) != 1) {
        std::cerr << "Error generating AES key" << std::endl;
        return 1;
    }

    // Print the generated key in hexadecimal format
    for (int i = 0; i < 24; i++) {
        printf("%02x", aes_key_192[i]);
    }
    std::cout << std::endl;

    // Generate a 256-bit (32-byte) AES key
    unsigned char aes_key_256[32];
    if (RAND_bytes(aes_key_256, 32) != 1) {
        std::cerr << "Error generating AES key" << std::endl;
        return 1;
    }

    // Print the generated key in hexadecimal format
    for (int i = 0; i < 32; i++) {
        printf("%02x", aes_key_256[i]);
    }
    std::cout << std::endl;

    return 0;
}