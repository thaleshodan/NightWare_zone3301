#include <openssl/aes.h>
#include <openssl/err.h>
#include <fstream>
#include <iostream>
#include <filesystem 
#include <string>
#include <vector>

// Function to handle errors
void handleErrors(void) {
    ERR_print_errors_fp(stderr);
    abort();
}

// Function to encrypt a file
int encrypt(const std::string& input_file, const std::string& output_file, unsigned char* key, unsigned char* iv) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int ciphertext_len;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new()))
        handleErrors();

    // Initialize the encryption operation
    if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    // Open the input file
    std::ifstream input(input_file, std::ios::binary);
    if (!input) {
        std::cerr << "Error opening input file" << std::endl;
        return 1;
    }

    // Open the output file
    std::ofstream output(output_file, std::ios::binary);
    if (!output) {
        std::cerr << "Error opening output file" << std::endl;
        return 1;
    }

    // Encrypt the file
    unsigned char buffer[1024];
    int bytes_read;
    while ((bytes_read = input.read(buffer, 1024).gcount()) > 0) {
        if (1 != EVP_EncryptUpdate(ctx, buffer, &len, buffer, bytes_read))
            handleErrors();
        output.write((char*)buffer, len);
    }

    // Finalize the encryption operation
    if (1 != EVP_EncryptFinal_ex(ctx, buffer, &len))
        handleErrors();
    output.write((char*)buffer, len);

    // Close the files
    input.close();
    output.close();

    return 0;
}

// Function to decrypt a file
int decrypt(const std::string& input_file, const std::string& output_file, unsigned char* key, unsigned char* iv) {
    EVP_CIPHER_CTX *ctx;
    int len;
    int plaintext_len;

    // Create and initialize the context
    if (!(ctx = EVP_CIPHER_CTX_new()))
        handleErrors();

    // Initialize the decryption operation
    if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        handleErrors();

    // Open the input file
    std::ifstream input(input_file, std::ios::binary);
    if (!input) {
        std::cerr << "Error opening input file" << std::endl;
        return 1;
    }

    // Open the output file
    std::ofstream output(output_file, std::ios::binary);
    if (!output) {
        std::cerr << "Error opening output file" << std::endl;
        return 1;
    }

    // Decrypt the file
    unsigned char buffer[1024];
    int bytes_read;
    while ((bytes_read = input.read(buffer, 1024).gcount()) > 0) {
        if (1 != EVP_DecryptUpdate(ctx, buffer, &len, buffer, bytes_read))
            handleErrors();
        output.write((char*)buffer, len);
    }

    // Finalize the decryption operation
    if (1 != EVP_DecryptFinal_ex(ctx, buffer, &len))
        handleErrors();
    output.write((char*)buffer, len);

    // Close the files
    input.close();
    output.close();

    return 0;
}

int main() {
    // Set the encryption and decryption keys
    unsigned char key[] = { 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
                            0x38, 0x39, 0x30, 0x31, 0x32, 0x33, 0x34, 0x35,
                            0x36, 0x37, 0x38, 0x39, 0x30, 0x31, 0x32, 0x33,
                            0x34, 0x35, 0x36, 0x37, 0x38, 0x39, 0x30, 0x31 };
    unsigned char iv[] = { 0x30, 0x31, 0x32, 0x33, 0x34, 0x35, 0x36, 0x37,
                            0x38, 0x39, 0x30, 0