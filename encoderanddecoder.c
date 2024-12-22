#include <stdio.h>
#include <string.h>
#include <ctype.h>

void print_ascii_art() {
    printf("\n");
    printf("  ______            _                 _   _             \n");
    printf(" |  ____|          | |               | | (_)            \n");
    printf(" | |____   _____  _| |_ ___ _ __ __ _| |_ _  ___  _ __  \n");
    printf(" |  __\\ \ / / _ \\ | __/ _ \\ '__/ _` | __| |/ _ \\ '_ \\ \n");
    printf(" | |___\\ V / (_) | | ||  __/ | | (_| | |_| | (_) | | | |\n");
    printf(" |______\\_/ \\\___/|_|\\__\\___|_|  \\\__,_|\\__|_|\\___/|_| |_|\n");
    printf("\n");
}

void caesar() {
    printf("\n===== Caesar Cipher =====\n");
    char kata[50];
    int kunci;
    printf("\tMasukan Kata : ");
    fgets(kata, 50, stdin);
    kata[strcspn(kata, "\n")] = '\0';

    printf("\tMasukan Kunci : ");
    scanf("%i", &kunci);
    getchar();

    for (int i = 0; kata[i] != '\0'; i++) {
        char k = kata[i];
        if (k >= 'a' && k <= 'z') kata[i] = (k - 'a' + kunci) % 26 + 'a';
        if (k >= 'A' && k <= 'Z') kata[i] = (k - 'A' + kunci) % 26 + 'A';
    }
    printf("\tHasil     : %s\n", kata);
}

void atbash() {
    printf("\n===== Atbash Cipher =====\n");
    char kata[50];
    printf("\tMasukan Kata : ");
    fgets(kata, 50, stdin);
    kata[strcspn(kata, "\n")] = '\0';

    for (int i = 0; kata[i] != '\0'; i++) {
        char k = kata[i];
        if (k >= 'a' && k <= 'z') kata[i] = 'z' - (k - 'a');
        if (k >= 'A' && k <= 'Z') kata[i] = 'Z' - (k - 'A');
    }
    printf("\tHasil     : %s\n", kata);
}

void text_ke_hex() {
    printf("\n===== Text to Hex =====\n");
    char kata[50];
    printf("\tMasukan Text : ");
    fgets(kata, 50, stdin);
    kata[strcspn(kata, "\n")] = '\0';

    printf("\tHasil: ");
    for (int i = 0; kata[i] != '\0'; i++) {
        printf("%02x ", kata[i]);
    }
    printf("\n");
}

void hex_ke_text() {
    printf("\n===== Hex to Text =====\n");
    char hex[50];
    printf("\tMasukan Hex : ");
    fgets(hex, sizeof(hex), stdin);
    hex[strcspn(hex, "\n")] = '\0';

    printf("\tHasil : ");
    char *token = strtok(hex, " ");
    while (token != NULL) {
        int value;
        sscanf(token, "%x", &value);
        printf("%c", (char)value);
        token = strtok(NULL, " ");
    }
    printf("\n");
}

void teks_ke_vigenere() {
    printf("\n===== Vigenere Encode =====\n");
    char kata[50], kunci[50];
    printf("\tMasukan Kata : ");
    fgets(kata, 50, stdin);
    kata[strcspn(kata, "\n")] = '\0';

    printf("\tMasukan Kunci : ");
    fgets(kunci, 50, stdin);
    kunci[strcspn(kunci, "\n")] = '\0';

    for (int i = 0; kata[i] != '\0'; i++) {
        char kc = toupper(kunci[i % strlen(kunci)]);
        char kt = toupper(kata[i]);
        kata[i] = (kt - 'A' + kc - 'A') % 26 + 'A';
    }
    printf("\tHasil     : %s\n", kata);
}

void vigenere_ke_teks() {
    printf("\n===== Vigenere Decode =====\n");
    char kata[50], kunci[50];
    printf("\tMasukan Hasil Encrypt Vigenere : ");
    fgets(kata, 50, stdin);
    kata[strcspn(kata, "\n")] = '\0';

    printf("\tMasukan Kunci : ");
    fgets(kunci, 50, stdin);
    kunci[strcspn(kunci, "\n")] = '\0';

    for (int i = 0; kata[i] != '\0'; i++) {
        char kc = toupper(kunci[i % strlen(kunci)]);
        char kt = toupper(kata[i]);
        kata[i] = (kt - 'A' - (kc - 'A') + 26) % 26 + 'A';
    }
    printf("\tText Hasil Decode : %s\n", kata);
}

int main() {
    int opsi_utama, opsi_sub;
    print_ascii_art();
    printf("Selamat Datang di Encoder & Decoder (made with <3 by baradika)\n");
    while (1) {
        printf("\nMenu Utama:\n");
        printf("1. Caesar\n2. Atbash\n3. Vigenere\n4. Hex\n5. Keluar\n");
        printf("Masukan Opsi : ");
        scanf("%i", &opsi_utama);
        getchar();

        switch (opsi_utama) {
            case 1: caesar(); break;
            case 2: atbash(); break;
            case 3:
                printf("1. Encode Vigenere\n2. Decode Vigenere\n");
                printf("Masukan Opsi: ");
                scanf("%i", &opsi_sub);
                getchar();
                if (opsi_sub == 1) teks_ke_vigenere();
                else if (opsi_sub == 2) vigenere_ke_teks();
                break;
            case 4:
                printf("1. Encode Hex\n2. Decode Hex\n");
                printf("Masukan Opsi: ");
                scanf("%i", &opsi_sub);
                getchar();
                if (opsi_sub == 1) text_ke_hex();
                else if (opsi_sub == 2) hex_ke_text();
                break;
            case 5:
                printf("Keluar dari program.\n");
                return 0;
            default:
                printf("Opsi tidak valid!\n");
        }
    }
}
