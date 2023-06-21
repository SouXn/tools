#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

#define MAX_INPUT_LENGTH 1000

void md5_hash(const char *input, unsigned char *output) {
    MD5_CTX md5Context;
    MD5_Init(&md5Context);
    MD5_Update(&md5Context, input, strlen(input));
    MD5_Final(output, &md5Context);
}

int main() {
    char input[MAX_INPUT_LENGTH];
    unsigned char output[MD5_DIGEST_LENGTH];

    printf("Enter the text to convert to MD5 hash: ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove trailing newline character

    md5_hash(input, output);

    printf("MD5 Hash: ");
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", output[i]);
    }
    printf("\n");

    return 0;
}