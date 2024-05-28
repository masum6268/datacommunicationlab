#include <stdio.h>

void main() {
    int n;
    printf("Enter the number of data bits (<=10): ");
    scanf("%d", &n);

    if (n <= 0 || n > 10) {
        printf("Invalid input. Number of data bits should be between 1 and 10.\n");
        return;
    }

    int data[20]; // Assuming 10 data bits maximum
    int dataatrec[20]; // Assuming 10 data bits maximum
    int c, c1, c2, c3, i;

    printf("Enter %d bits of data one by one\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &data[i]);

    // Calculation of parity bits
    int numParityBits = 0;
    while ((1 << numParityBits) < n + numParityBits + 1)
        numParityBits++;

    printf("Number of parity bits needed: %d\n", numParityBits);

    // Setting up the data array to include both data and parity bits
    int totalBits = n + numParityBits;
    printf("Total bits including parity bits: %d\n", totalBits);

    // Initializing parity bits to 0
    for (i = n; i < totalBits; i++)
        data[i] = 0;

    // Calculation of parity bits
    for (i = 0; i < numParityBits; i++) {
        int parity = 0;
        for (int j = (1 << i); j < totalBits; j += (1 << (i + 1))) {
            for (int k = 0; k < (1 << i) && (j + k) < totalBits; k++) {
                parity ^= data[j + k];
            }
        }
        data[(1 << i) - 1] = parity;
    }

    printf("\nEncoded data is\n");
    for (i = 0; i < totalBits; i++)
        printf("%d", data[i]);

    printf("\n\nEnter received data bits one by one\n");
    for (i = 0; i < totalBits; i++)
        scanf("%d", &dataatrec[i]);

    // Checking for errors
    c = 0;
    for (i = 0; i < numParityBits; i++) {
        int parity = 0;
        for (int j = (1 << i); j < totalBits; j += (1 << (i + 1))) {
            for (int k = 0; k < (1 << i) && (j + k) < totalBits; k++) {
                parity ^= dataatrec[j + k];
            }
        }
        c |= (parity << i);
    }

    if (c == 0) {
        printf("\nNo error while transmission of data\n");
    } else {
        printf("\nError in position %d\n", c);

        printf("Data sent : ");
        for (i = 0; i < totalBits; i++)
            printf("%d", data[i]);

        printf("\nData received : ");
        for (i = 0; i < totalBits; i++)
            printf("%d", dataatrec[i]);

        printf("\nCorrect message is\n");

        // Flipping the erroneous bit
        if (dataatrec[c - 1] == 0)
            dataatrec[c - 1] = 1;
        else
            dataatrec[c - 1] = 0;

        for (i = 0; i < totalBits; i++) {
            printf("%d", dataatrec[i]);
        }
    }
}
