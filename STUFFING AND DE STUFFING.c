#include <stdio.h>
#include <string.h>
#define FLAG_SEQUENCE "01111110"
#define MAX_SIZE 30 // Maximum size for bit sequence

void bitStuffing(int N, int arr[]) {
    int stuffed[MAX_SIZE * 2]; // Twice the size to accommodate possible stuffing
    int j = 0; // Index for stuffed array

    // Copy the flag sequence to the output
    for (int i = 0; i < strlen(FLAG_SEQUENCE); i++)
        stuffed[j++] = FLAG_SEQUENCE[i] - '0';

    int count = 0; // Count consecutive 1s
    for (int i = 0; i < N; i++) {
        if (arr[i] == 1) {
            stuffed[j++] = arr[i];
            count++;
        } else {
            count = 0;
            stuffed[j++] = arr[i];
        }
        if (count == 5) { // Stuff 0 after 5 consecutive 1s
            stuffed[j++] = 0;
            count = 0; // Reset count
        }
    }

    // Copy the flag sequence to the end of the output
    for (int i = 0; i < strlen(FLAG_SEQUENCE); i++)
        stuffed[j++] = FLAG_SEQUENCE[i] - '0';

    // Print the stuffed sequence
    for (int i = 0; i < j; i++)
        printf("%d", stuffed[i]);
}

void bitDestuffing(int N, int arr[]) {
    int destuffed[MAX_SIZE]; // Initialize array for destuffed sequence
    int j = 0; // Index for destuffed array

    // Skip the flag sequence at the beginning
    int i = strlen(FLAG_SEQUENCE);
    while (i < N - strlen(FLAG_SEQUENCE)) {
        if (arr[i] == 0 || arr[i + 1] == 1 || arr[i + 2] == 1 || arr[i + 3] == 1 || arr[i + 4] == 1 || arr[i + 5] == 1 || arr[i + 6] == 0) {
            destuffed[j++] = arr[i];
            i++;
        } else {
            // Skip stuffed 0
            i += 7;
        }
    }

    // Print the destuffed sequence
    for (int k = 0; k < j; k++)
        printf("%d", destuffed[k]);
}

int main() {
    int choice;
    printf("Enter 1 for bit stuffing or 2 for bit destuffing: ");
    scanf("%d", &choice);

    int N;
    int arr[MAX_SIZE];

    switch (choice) {
        case 1:
            printf("Enter the number of bits: ");
            scanf("%d", &N);
            printf("Enter the bit sequence: ");
            for (int i = 0; i < N; i++)
                scanf("%d", &arr[i]);
            bitStuffing(N, arr);
            break;

        case 2:
            printf("Enter the number of bits: ");
            scanf("%d", &N);
            printf("Enter the bit sequence: ");
            for (int i = 0; i < N; i++)
                scanf("%d", &arr[i]);
            bitDestuffing(N, arr);
            break;

        default:
            printf("Invalid choice!\n");
            break;
    }

    return 0;
}
