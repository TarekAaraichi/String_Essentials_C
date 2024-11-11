// input_utils.c
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "input_utils.h"

/**
 * @brief Converts a string to lowercase for easier case-insensitive comparison.
 *
 * This function iterates over each character of the input string and converts 
 * it to lowercase using the `tolower` function from the C standard library.
 * 
 * @param str A pointer to the string to be converted to lowercase.
 */
void toLowerCase(char *str) {
    if (str == NULL) return;  // Return if the string is null
    
    for (int i = 0; str[i]; i++) {
        str[i] = (char) tolower((unsigned char) str[i]);  // Convert to lowercase
    }
}

/**
 * @brief Removes the newline character from the end of the string and clears
 *        any leftover input from the buffer if necessary.
 *
 * If the input contains a newline character, it's replaced with the null 
 * terminator. If the input exceeds the buffer size, the remaining characters 
 * in the input buffer are discarded.
 * 
 * @param input A pointer to the string from which the newline will be removed.
 * @param size The size of the input buffer to ensure no overflow occurs.
 */
void removeNewline(char *input, size_t size) {
    size_t len = strlen(input);

    // Remove newline character if present
    if (len > 0 && input[len - 1] == '\n') {
        input[len - 1] = '\0';  // Replace newline with null terminator
    } else {
        // If the input was too long and no newline, clear the input buffer
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);  // Discard the remaining input
    }
}

/**
 * @brief Prompts the user for a number and validates that it is greater than a specified minimum value.
 *
 * This function ensures that the entered number is valid (i.e., an integer greater than the provided minimum).
 * If the input is invalid, it will keep asking the user for a correct input.
 * 
 * @param min The minimum acceptable value for the number entered.
 * 
 * @return A valid integer greater than the specified minimum.
 */
int getValidNumberInput(int min) {
    int number;
    while (1) {
        if (scanf("%d", &number) == 1 && number > min) {
            return number;  // Valid input
        }
        
        // Clear the input buffer if invalid input is encountered
        while (getchar() != '\n');  
        printf("Invalid input! Please enter a valid integer greater than %d: ", min);
    }
}

/**
 * @brief Prompts the user for input, reads the input string, and removes any trailing newline.
 *
 * This function displays a prompt message, reads the user's input into the provided string, 
 * and ensures that any trailing newline character is removed. The input is read with a buffer 
 * size limit to prevent overflow.
 * 
 * @param prompt A constant string to display as the prompt to the user.
 * @param input A pointer to the string where the user's input will be stored.
 * @param size The maximum number of characters to read (including the null terminator).
 */
void getInput(const char *prompt, char *input, size_t size) {
    printf("%s ", prompt);  // Display the prompt to the user
    fgets(input, size, stdin);  // Read input from stdin with a buffer size limit

    // Remove any trailing newline character
    removeNewline(input, size);
}

/**
 * @brief Capitalizes the first letter of each word in the input string.
 *
 * This function capitalizes the first alphabetic character of each word and converts 
 * the rest of the characters to lowercase. Words are determined by spaces or other 
 * delimiters. Non-alphabetic characters are unaffected.
 * 
 * @param input A pointer to the string to be formatted.
 */
void capitalizeWords(char *input) {
    int isNewWord = 1;  // Flag to indicate the start of a new word

    // Iterate over each character in the string
    for (int i = 0; input[i] != '\0'; i++) {
        if (isspace((unsigned char) input[i])) {
            isNewWord = 1;  // Start of a new word after a space
        } else if (isNewWord) {
            input[i] = (char) toupper((unsigned char) input[i]);  // Capitalize the first letter
            isNewWord = 0;  // Inside a word now
        } else {
            input[i] = (char) tolower((unsigned char) input[i]);  // Convert subsequent letters to lowercase
        }
    }
}
