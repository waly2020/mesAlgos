#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#define CODE_LENGTH 4
#define MAX_ATTEMPTS 10
void generateSecretCode(char *secretCode);
void getUserGuess(char *userGuess);
void evaluateGuess(const char *secretCode, const char *userGuess, int *wellPlaced, int *misplaced);
int isValidGuess(const char *guess);
void printResult(int wellPlaced, int misplaced);
void printInvalidInput();

int main(int argc, char *argv[]) {
    char secretCode[CODE_LENGTH + 1];
    char userGuess[CODE_LENGTH + 1];
    int wellPlaced, misplaced;
    int attempts = MAX_ATTEMPTS;

    // Check if custom code is provided
    if (argc > 1 && strcmp(argv[1], "-c") == 0 && argc >= 3 && strlen(argv[2]) == CODE_LENGTH) {
        strncpy(secretCode, argv[2], CODE_LENGTH);
        secretCode[CODE_LENGTH] = '\0';
    } else {
        // Generate random secret code
        generateSecretCode(secretCode);
    }

    // Check if custom number of attempts is provided
    if (argc > 1 && strcmp(argv[1], "-t") == 0 && argc >= 3) {
        attempts = atoi(argv[2]);
        if (attempts <= 0) {
            attempts = MAX_ATTEMPTS;
        }
    }

    printf("Will you find the secret code?\nPlease enter a valid guess\n");

    // Game loop
    for (int i = 0; i < attempts; i++) {
        printf("---\nRound %d\n>", i);

        // Get user's guess
        getUserGuess(userGuess);

        // Evaluate the guess
        evaluateGuess(secretCode, userGuess, &wellPlaced, &misplaced);

        // Check if the user found the secret code
        if (wellPlaced == CODE_LENGTH) {
            printf("Congratz! You did it!\n");
            return 0;
        }

        // Print the result
        printResult(wellPlaced, misplaced);
    }

    printf("---\nYou failed to find the secret code! The code was %s\n", secretCode);

    return 0;
}

void generateSecretCode(char *secretCode) {
    char pieces[] = "012345678";
    int numPieces = strlen(pieces);

    srand(time(NULL));

    for (int i = 0; i < CODE_LENGTH; i++) {
        int index = rand() % numPieces;
        secretCode[i] = pieces[index];
    }

    secretCode[CODE_LENGTH] = '\0';
}

void getUserGuess(char *userGuess) {
    char input[CODE_LENGTH + 2];  // +2 to account for newline and null character
    ssize_t bytesRead = read(STDIN_FILENO, input, CODE_LENGTH + 1);
    if (bytesRead > 0) {
        input[bytesRead] = '\0';

        // Remove newline character
        if (input[bytesRead - 1] == '\n') {
            input[bytesRead - 1] = '\0';
        }

        strncpy(userGuess, input, CODE_LENGTH);
        userGuess[CODE_LENGTH] = '\0';
    } else {
        // Handle read error or end of file
        exit(1);
    }
}

void evaluateGuess(const char *secretCode, const char *userGuess, int *wellPlaced, int *misplaced) {
    *wellPlaced = 0;
    *misplaced = 0;

    // Create temporary arrays for marking visited pieces
    char tempSecretCode[CODE_LENGTH + 1];
    char tempUserGuess[CODE_LENGTH + 1];
    strncpy(tempSecretCode, secretCode, CODE_LENGTH);
    strncpy(tempUserGuess, userGuess, CODE_LENGTH);
    tempSecretCode[CODE_LENGTH] = '\0';
    tempUserGuess[CODE_LENGTH] = '\0';

    // Count well-placed pieces
    for (int i = 0; i < CODE_LENGTH; i++) {
        if (tempUserGuess[i] == tempSecretCode[i]) {
            (*wellPlaced)++;
            tempSecretCode[i] = '*';  // Mark the piece as visited in secret code
            tempUserGuess[i] = '*';   // Mark the piece as visited in user guess
        }
    }

    // Count misplaced pieces
    for (int i = 0; i < CODE_LENGTH; i++) {
        if (tempUserGuess[i] != '*') {
            for (int j = 0; j < CODE_LENGTH; j++) {
                if (tempUserGuess[i] == tempSecretCode[j]) {
                    (*misplaced)++;
                    tempSecretCode[j] = '*';  // Mark the piece as visited in secret code
                    break;
                }
            }
        }
    }
}

int isValidGuess(const char *guess) {
    if (strlen(guess) != CODE_LENGTH) {
        return 0;
    }

    for (int i = 0; i < CODE_LENGTH; i++) {
        if (guess[i] < '0' || guess[i] > '8') {
            return 0;
        }
    }

    return 1;
}

void printResult(int wellPlaced, int misplaced) {
    printf("Well placed pieces: %d\nMisplaced pieces: %d\n", wellPlaced, misplaced);
}

void printInvalidInput() {
    printf("Wrong input!\n");
}