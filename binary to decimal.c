#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void convert_binary2decimal(char *binaryIP);
int binary2decimal(char *binary);

int main() {
    char binaryIP[33]; //  extra 1 for null terminator
    printf("Enter IPv4 32-bit binary IP: ");
    scanf("%32s", binaryIP);

    printf("Dotted Decimal IP is : ");
    convert_binary2decimal(binaryIP);

    return 0;
}

void convert_binary2decimal(char *binaryIP) {
    for (int i = 0; i < 32; i += 8) {
        int decimal = binary2decimal(binaryIP + i);
        printf("%d", decimal);
        if (i < 24) {
            printf(".");
        }
    }
    printf("\n");
}

int binary2decimal(char *binary) {
    int decimal = 0;
    for (int i = 0; i < 8; i++) {
        decimal = decimal * 2 + (binary[i] - '0');
    }
    return decimal;
}
