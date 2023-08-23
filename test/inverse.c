#include <stdio.h>
#include <stdlib.h> // Ajout de l'en-tête pour inclure malloc
#include <string.h>

char* reverseString(const char* str) {
    int length = strlen(str);
    char* reversed = (char*)malloc((length + 1) * sizeof(char)); // Allouer de la mémoire pour la chaîne inversée
    int i;

    // Inverser la chaîne
    for (i = 0; i < length; i++) {
        reversed[i] = str[length - i - 1];
    }

    reversed[length] = '\0'; // Terminer la chaîne inversée avec un caractère nul

    return reversed;
}

int main() {
    const char* original = "Hello wally :(";
    char* reversed = reverseString(original);

    printf("Chaîne originale : %s\n", original);
    printf("Chaîne inversée : %s\n", reversed);

    free(reversed); // Libérer la mémoire allouée pour la chaîne inversée

    return 0;
}
