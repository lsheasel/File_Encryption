#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 4096

// Funktion zur automatischen Entfernung von Anführungszeichen
void remove_quotes(char *str) {
    size_t len = strlen(str);
    if (len > 1 && str[0] == '"' && str[len - 1] == '"') {
        memmove(str, str + 1, len - 2);
        str[len - 2] = '\0';
    }
}

// XOR Verschlüsselung / Entschlüsselung
void xor_encrypt_decrypt(const char *input_filename, const char *output_filename, const char *key) {
    FILE *input = fopen(input_filename, "rb");
    FILE *output = fopen(output_filename, "wb");

    if (!input || !output) {
        perror("Error opening file");
        exit(1);
    }

    size_t key_len = strlen(key);
    unsigned char buffer[BUFFER_SIZE];
    size_t bytesRead;
    size_t i;

    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, input)) > 0) {
        for (i = 0; i < bytesRead; i++) {
            buffer[i] ^= key[i % key_len];  // XOR Verschlüsselung
        }
        fwrite(buffer, 1, bytesRead, output);
    }

    fclose(input);
    fclose(output);
}

int main() {
    char input_filepath[512];
    char output_filepath[512];
    char key[256];
    int choice;

    printf("File Encryption Program\n");
    printf("1) Encrypt a file\n");
    printf("2) Decrypt a file\n");
    printf("Choose an option (1 or 2): ");
    scanf("%d", &choice);
    getchar();  // Enter abfangen

    if (choice != 1 && choice != 2) {
        printf("Invalid input!\n");
        return 1;
    }

    printf("Enter the full file path: ");
    fgets(input_filepath, sizeof(input_filepath), stdin);
    input_filepath[strcspn(input_filepath, "\n")] = 0;  // Entfernt das "\n"

    remove_quotes(input_filepath);  // Entfernt automatisch Anführungszeichen

    printf("Enter your password/key: ");
    fgets(key, sizeof(key), stdin);
    key[strcspn(key, "\n")] = 0;  // Entfernt das "\n"

    // Ausgabe-Dateipfad generieren
    snprintf(output_filepath, sizeof(output_filepath), "%s.%s", input_filepath, choice == 1 ? "enc" : "dec");

    xor_encrypt_decrypt(input_filepath, output_filepath, key);

    printf("File successfully processed: %s -> %s\n", input_filepath, output_filepath);
    return 0;
}
