#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void ipv4_to_binary(char *ipv4_address) {
    char *token;
    int binary[32] = {0};
    int i = 0;

    token = strtok(ipv4_address, ".");
    while (token != NULL) {
        int octet = atoi(token);
        for (int j = 7; j >= 0; j--) {
            binary[i++] = (octet >> j) & 1;
        }
        token = strtok(NULL, ".");
    }

    for (int k = 0; k < 32; k++) {
        printf("%d", binary[k]);
        if ((k + 1) % 8 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

void binary_to_ipv4(char *binary_str) {
    char ipv4_address[16] = "";
    int octet = 0;
    for (int i = 0; i < 32; i++) {
        octet = (octet << 1) | (binary_str[i] - '0');
        if ((i + 1) % 8 == 0) {
            sprintf(ipv4_address + strlen(ipv4_address), "%d", octet);
            if (i != 31) {
                strcat(ipv4_address, ".");
            }
            octet = 0;
        }
    }
    printf("IPv4 Address: %s\n", ipv4_address);
}

int main() {
    char ipv4_address[16];
    char binary_str[33];
    int option;

    printf("Enter an IPv4 address (e.g., '192.168.1.1'): ");
    fgets(ipv4_address, sizeof(ipv4_address), stdin);
    ipv4_address[strcspn(ipv4_address, "\n")] = '\0';

    printf("Choose an option:\n");
    printf("1. Convert IPv4 to Binary\n");
    printf("2. Convert Binary to IPv4\n");
    scanf("%d", &option);

    switch (option) {
        case 1:
            ipv4_to_binary(ipv4_address);
            break;
        case 2:
            printf("Enter a binary string (32 bits): ");
            scanf("%32s", binary_str);
            binary_to_ipv4(binary_str);
            break;
        default:
            printf("Invalid option\n");
            break;
    }

    return 0;
}

