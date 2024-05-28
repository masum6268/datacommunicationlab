#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100
void bitStuff(char *input, char *output) {
    int count = 0;
    int outIndex = 0;
    strcpy(output, "01111110");
    outIndex += 8;
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '1') {
            count++;
            output[outIndex++] = '1';
        } else {
            count = 0;
            output[outIndex++] = '0';
        }

        if (count == 5) {
            output[outIndex++] = '0';
            count = 0;
        }
    }
    strcpy(output + outIndex, "01111110");
}
void bitDestuff(char *input, char *output) {
    int count = 0;
    int outIndex = 0;

    for (int i = 8; i < strlen(input) - 8; i++) {
        if (input[i] == '1') {
            count++;
            output[outIndex++] = '1';
        } else {
            count = 0;
            output[outIndex++] = '0';
        }

        if (count == 5 && input[i + 1] == '0') {
            count = 0;
            i++;
        }
    }
    output[outIndex] = '\0';
}
int main() {
    char input[MAX_SIZE];
    char stuffed[MAX_SIZE * 2];
    char destuffed[MAX_SIZE];

    printf(" Please enter the Sequence:");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = '\0';

    bitStuff(input, stuffed);
    printf("Stuffed Output: %s\n", stuffed);

    bitDestuff(stuffed, destuffed);
    printf("De-stuffed Output: %s\n", destuffed);
    return 0;
}

