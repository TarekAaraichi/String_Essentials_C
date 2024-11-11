// Function that swaps the values of two variables
void swapInts(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

#include <stdlib.h>
#include <stdio.h>

/* Function that prints all values in an array

Parameters: 
    - const int *array: pointer to the array to print
    - int size: number of elements in the array
*/
void printIntArray(const int *array, int size) {
    for (int i = 0; i < size; i++) {    // Loop through each element in the array
        printf("%d ", array[i]);        // Print the current element followed by a space
    }
    printf("\n");                       // New line after the last element
}

/* Function that prints the sum of all values in an array

Parameters:
    - int *array: pointer to the array containing the numbers
    - int size: number of elements in the array
*/
void printSumOfIntArray(int *array, int size) {
    int sum = 0;                   // Variable to hold the sum
    for (int i = 0; i < size; i++) {
        sum += array[i];           // Add each element to the sum
    }
    printf("The sum of the numbers: %d\n", sum); // Print the sum
}

#include <string.h>

/* Function that checks if all characters in the string are the same

Parameters:
    - str: The input string
    Returns 1 if all characters are the same, otherwise 0
*/
int allCharsAreSame(char *str) {
    int length = strlen(str);  // Get the length of the string

    // If the string is empty or has only one character, return Yes
    if (length <= 1) {
        return 1;  // All characters (or none) are the same
    }

    // Loop through the string and compare each character to the first one
    for (int i = 1; i < length; i++) {
        if (str[i] != str[0]) {  // If any character is not the same as the first
            return 0;  // No, not all characters are the same
        }
    }

    return 1;  // Yes, all characters are the same
}

// Function that finds the most frequent character and its frequency in an input string

#define MAX_CHAR 255  // Number of possible characters (ASCII)

void findMostFrequentChar(char *str) {
    int freq[MAX_CHAR] = {0};  // Array to hold frequencies for all characters

    // Go through each character in the string and count the frequency
    for (int i = 0; str[i] != '\0'; i++) {
        freq[(unsigned char)str[i]]++;  // Increase frequency for the current character
    }

    // Find the most frequent character and its frequency
    int maxFreq = 0;
    char mostFrequentChar = '\0';
    for (int i = 0; i < MAX_CHAR; i++) {
        // Skip spaces (ASCII 32)
        if (i == ' ') {
            continue;
        }
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            mostFrequentChar = (char)i;  // Find the character with the highest frequency
        }
    }

    // If there is a character that occurs, print it
    if (maxFreq > 0) {
        printf("The most frequent character is '%c' which appears %d times.\n", mostFrequentChar, maxFreq);
    } else {
        printf("No characters found in the string.\n");
    }
}

#include <ctype.h> // To use isalpha() to check for letters

// Function that removes all non-letter characters from a string
int RemoveNotLetters(char *szOrig, char *szNew) {
    int j = 0;  // Index for the new string
    
    // Go through each character in the original string
    for (int i = 0; szOrig[i] != '\0'; i++) {
        // If the character is a letter, add it to the new string
        if (isalpha(szOrig[i])) {
            szNew[j++] = szOrig[i];  // Copy the letter and increase the index
        }
    }
    
    // Add a null-terminator to mark the end of the string
    szNew[j] = '\0';
    
    return 0;  // Return value can be useful for error handling
}
