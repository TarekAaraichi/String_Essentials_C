#include <stdio.h>
#include <string.h>
#include "input_utils.h"
#include "utility_functions.h"

/*
 Uses "strchr" to find the first occurrence of a letter in a given text string. 
 It implements the "GetInput" function, which prompts the user for input, 
 and make sure it works correctly for text and letterInput.
*/

void findFirst() {
    char text[100];
    char letterInput[2];

    // Get input for the text and letter
    getInput("\nPlease, enter a text: ", text, sizeof(text));
    getInput("Please, enter a letter: ", letterInput, sizeof(letterInput));

    char letter = letterInput[0];  // Get the first character of letterInput

    // Find the first occurrence of the letter in the text 
    char *find = strchr(text, letter); // starts counting from 0

    if (find == NULL) {
        printf("\nThere is no '%c' in the text you entered\n", letter);
    } else {
        printf("\nThe first position I found '%c' is at position %ld\n", letter, find - text + 1);
    }
}

/*
Counts for all occurrences of a specific letter in a string and list each position where it occurs.
Upgrades the "findFirst" funtction by looping through the entire string, 
counting occurrences and recording their positions.
*/

#include <ctype.h>

void findAllOccurrences() {
    char text[100];
    char letterInput[2];

    // Get input for the text and letter
    getInput("\nEnter a text: ", text, sizeof(text));
    getInput("Enter a letter: ", letterInput, sizeof(letterInput));

    char letter = letterInput[0];  // Get the first character of letterInput
    int count = 0;  // Initialize occurrence count

    printf("\nSearching for occurrences of '%c' in the text...\n", letter);

    // Loop through each character in the text

    for (int i = 0; text[i] != '\0'; i++) {
        // Check if the current character matches the letter, ignoring case
        if (tolower(text[i]) == tolower(letter)) {
            count++;
            printf("Occurrence %d found at position %d\n", count, i+1);
        }
    }

    // Summary message
    if (count == 0) {
        printf("There is no '%c' in the text you entered.\n", letter);
    } else {
        printf("\nThe letter '%c' appeared %d times in the text.\n", letter, count);
    }
}

/*
Replaces a specified character in the string with another character (both provided by the user), 
A loop to perform the replacement and then count the occurrences of the newly replaced character.
*/

void replaceCharacter() {
    char text[100];
    char charToReplace[2];
    char replacementChar[2];

    // Get input for the text
    getInput("\nEnter a text: ", text, sizeof(text));

    // Get input for the character to replace
    getInput("Enter the character to replace:", charToReplace, sizeof(charToReplace));
    
    // Get input for the replacement character
    getInput("Enter the replacement character:", replacementChar, sizeof(replacementChar));

    char toReplace = charToReplace[0];      // Character to be replaced
    char replaceWith = replacementChar[0];  // Character to replace with
    int count = 0;                          // Counter for occurrences of the new character

    // Replace occurrences of toReplace with replaceWith
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == toReplace) {
            text[i] = replaceWith; // Replace the character
        }
    }

    // Count occurrences of the new character
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == replaceWith) {
            count++; // Increment count for each occurrence
        }
    }

    // Display the modified text and the count of occurrences
    printf("\nModified text: %s\n", text);
    printf("The character '%c' appears %d times in the modified text.\n", replaceWith, count);
}

/*
Validation: Prompt the user to enter an email adress.
*/

int isValidEmail(const char *email) {
    char *atSign = strchr(email, '@'); // Find the '@' character
    if (atSign == NULL) {
        return 0; // No '@' character found
    }

    char *dot = strchr(atSign, '.'); // Find the last '.' after '@'
    if (dot == NULL || dot - atSign <= 1) {
        return 0; // No '.' after '@' or '.' is too close to '@'
    }

    // Check if there are 2 or 3 characters after the last '.'
    int charsAfterDot = strlen(dot + 1);
    if (charsAfterDot < 2 || charsAfterDot > 3) {
        return 0; // Invalid number of characters after '.'
    }

    return 1; // The email format is valid
}

void promptForValidEmail() {
    char email[100];
    int valid = 0;

    while (!valid) {
        //getEmailInput(email, sizeof(email)); // Prompt user for email
        getInput("\nPlease, enter your email address: ", email, sizeof(email));
        if (isValidEmail(email)) {
            printf("The email address is valid! :)\n");
            valid = 1; // Exit loop if email is valid
        } else {
            printf("Invalid email address. Please try again!\n");
        }
    }
}

/*
Function to prompt for a sentence, count the words, and display the result
*/

#include <ctype.h>

void countWordsInSentence() {
    char sentence[200];

    printf("Please, enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);
    removeNewline(sentence, sizeof(sentence));

    int wordCount = 0;
    int inWord = 0; // Tracks if we are inside a word

    for (int i = 0; sentence[i] != '\0'; i++) {
        if (!isspace(sentence[i])) {
            if (!inWord) {
                wordCount++; // Start of a new word
                inWord = 1;
            }
        } else {
            inWord = 0; // End of a word
        }
    }

    printf("The sentence contains %d word(s).\n", wordCount);
}

/*
Let the user input a word or a sentence then check if the word is a palindrome, 
meaning it reads the same forwards and backwards. 
Examples of palindromes: "anna" or "otto". 
Notify the user whether it is a palindrome or not.
NOTE: Spaces should be removed! Uppercase and lowercase letters are considered the same.
*/

void checkPalindrome() {
    char input[100];
    char processed[100];

    printf("Enter a word or a sentence: ");
    fgets(input, sizeof(input), stdin);
    removeNewline(input, sizeof(input));

    // Remove spaces and convert to lowercase
    int j = 0; // Index for processed array
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isspace(input[i])) { // Skip spaces
            processed[j++] = tolower(input[i]); // Convert to lowercase and add to processed
        }
    }
    processed[j] = '\0'; // Null-terminate the processed string

    // Check if it's a palindrome
    int len = strlen(processed);
    int isPalindrome = 1; // Assume it's a palindrome unless proven otherwise
    for (int i = 0; i < len / 2; i++) {
        if (processed[i] != processed[len - i - 1]) {
            isPalindrome = 0; // Not a palindrome
            break;
        }
    }

    // Output the result
    if (isPalindrome) {
        printf("\"%s\" is a palindrome.\n", input);
    } else {
        printf("\"%s\" is not a palindrome.\n", input);
    }
}

/* Which character is the most common
    - input a string
    - Example: Hello, what’s your name?
    - The most common character is 'C', which appears 3 times

    Tip – create int array[255] – i.e., one element per possible character??
*/

int findMostFrequentCharacter() {
    char str[1000];  // Array to store the string (max 999 characters)

    // Read a string from the user
    printf("\nEnter a string: ");
    fgets(str, sizeof(str), stdin);  // Read the entire line, including spaces

    // Remove newline character (\n) if it exists at the end of the string
    str[strcspn(str, "\n")] = 0;

    // Call the function to find the most common character
    findMostFrequentChar(str);

    return 0;
}

/* Extract a part of a string
    - input a string
    - Example: Hello, how are you?
    - Input a START position
    - Input an END position

    Print the part of the string between the two positions

    Input> Hello there
    Start> 3
    End> 7
    Between position 3 and 7 in the string, it reads:
    'llo t'
*/

int extractSubstring() {
    char str[1000];  // Array to store the string
    int start, end;  // Variables for start and end positions

    // Read the string
    printf("\nEnter a string: ");
    fgets(str, sizeof(str), stdin);  // Read the entire line, including spaces

    // Remove newline character (\n) if it exists at the end of the string
    str[strcspn(str, "\n")] = 0;

    // Read start and end positions
    printf("\nEnter a START position: ");
    scanf("%d", &start);
    
    printf("Enter an END position: ");
    scanf("%d", &end);

    // Check that the start position is less than the end position and they are within string bounds
    if (start >= 0 && end < strlen(str) && start <= end) {
        // Print the part of the string between start and end
        printf("\nBetween position %d and %d in the string, it reads:\n'%.*s'\n", start, end, end - start + 1, &str[start]); // Counting from 0
        printf("\nBetween position %d and %d in the string, it reads:\n'%.*s'\n", start, end, end - start + 1, &str[start - 1]); // Counting from 1
    } else {
        // If start or end position is outside valid limits
        printf("\nInvalid positions. Make sure start is less than or equal to end and they are within the string's length.\n");
    }

    return 0;
}

/* Swap the case of all characters
    - input a string
    - Example: Hello, How are you?

    Print the string with reversed casing

    Input> Hello, How are you?
    Output> hELLO, hOW ARE YOU?
*/

#include <ctype.h>  // To use toupper() and tolower() functions

int toggleCase() {
    char str[1000];  // Array to store the string

    // Read the string
    printf("\nEnter a string: ");
    fgets(str, sizeof(str), stdin);  // Read the entire line, including spaces

    // Remove newline character (\n) if it exists at the end of the string
    str[strcspn(str, "\n")] = 0;

    // Loop through the string and print each character with reversed casing
    printf("String with reversed casing: ");
    for (int i = 0; str[i] != '\0'; i++) {
        // If the character is lowercase, make it uppercase
        if (islower(str[i])) {
            putchar(toupper(str[i]));
        }
        // If the character is uppercase, make it lowercase
        else if (isupper(str[i])) {
            putchar(tolower(str[i]));
        }
        // If the character is not a letter (e.g., space), print it directly
        else {
            putchar(str[i]);
        }
    }
    printf("\n");

    return 0;
}

/* Remove all non-letter characters
    - input a string
    - call a function that removes all non-letter characters
    int RemoveNotLetters(char *szOrig, char *szNew)
    - print the new string

    Input> Hello123”Bob”
    Output> HelloBob
*/

int removeNonLetters() {
    char szOrig[1000];  // Array to store the original string
    char szNew[1000];   // Array to store the cleaned string

    // Read the string
    printf("\nEnter a string: ");
    fgets(szOrig, sizeof(szOrig), stdin);  // Read the entire line, including spaces

    // Remove newline character (\n) if it exists at the end of the string
    szOrig[strcspn(szOrig, "\n")] = 0;

    // Call the function to remove non-letters
    RemoveNotLetters(szOrig, szNew);

    // Print the new string
    printf("String without non-letter characters: %s\n", szNew);

    return 0;
}


/*
Generates a random number between 1 and 6. 
Then, ask the user if they want to continue (Yes, No).
*/

#include <stdlib.h> // for rand and srand
#include <time.h>

// Function to generate a random number between min and max
int generateRandomNumber(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void playRandomNumberGame() {
    char input[4];
    int min, max;

    // Seed random number generator once
    srand(time(NULL));

    // Get valid min and max values from user
    printf("\nChoose the minimum number for the random generation: ");
    min = getValidNumberInput(0);

    printf("Choose the maximum number for the random generation: ");
    max = getValidNumberInput(min);

    // Generate random number and display
    int randomNumber = generateRandomNumber(min, max);
    printf("\nGenerated random number: %d\n", randomNumber);

    // Clear buffer after number generation
    while (getchar() != '\n'); 

    do {
        printf("\nDo you want to continue? (Yes/No): ");
        fgets(input, sizeof(input), stdin);
        removeNewline(input, sizeof(input));

        // Convert input to lowercase for case-insensitive comparison
        toLowerCase(input);

        // Check for valid responses
        if (strcmp(input, "no") == 0) {
            printf("\nThank you for playing - Goodbye! :)\n");
            return; // End the game
        } else if (strcmp(input, "yes") == 0) {
            // Ask for min and max again
            printf("\nChoose the minimum number for the random generation: ");
            min = getValidNumberInput(0);

            printf("Choose the maximum number for the random generation: ");
            max = getValidNumberInput(min);

            // Generate and display a new random number
            randomNumber = generateRandomNumber(min, max);
            printf("\nGenerated random number: %d\n", randomNumber);
            // Clear buffer after number generation
            while (getchar() != '\n'); 

        } else {
            printf("Invalid response! Please answer with 'Yes' or 'No'.\n");
        }
    } while (1);
}


// Main function
int main() {
    // Call and implement each function as required:

    // Random generator game
    printf("\n\t* Random generator game:\n");
    playRandomNumberGame(); // Call the random number game function

    // Finding first occurrence of a letter in the text
    printf("\n\t* Finding the first occurrence of a letter in the text:\n");
    findFirst(); // Call the function to find the first occurrence of a letter

    // Find all occurrences of a letter in the text
    printf("\n\t* Finding all occurrences of a letter in the text:\n");
    findAllOccurrences(); // Call the function to find all occurrences

    // Replace a character in the text
    printf("\n\t* Replacing a character in the text:\n");
    replaceCharacter(); // Call the function to replace a character

    // Validate email address
    printf("\n\t* Email validation:\n");
    promptForValidEmail(); // Call the function to prompt and validate an email address

    // Count words in a sentence
    printf("\n\t* Counting words in a sentence:\n");
    countWordsInSentence(); // Call the function to count words in a sentence

    // Check if a word or sentence is a palindrome
    printf("\n\t* Checking for a palindrome:\n");
    checkPalindrome(); // Call the function to check for palindrome

    // Find the most frequent character
    printf("\n\t* Finding the most frequent character:\n");
    findMostFrequentCharacter(); // Call the function to find the most frequent character

    // Extract a substring based on position
    printf("\n\t* Extracting a substring:\n");
    extractSubstring(); // Call the function to extract a substring

    // Toggle case of each character
    printf("\n\t* Toggling case for each character:\n");
    toggleCase(); // Call the function to toggle case

    // Remove non-letter characters from the text
    printf("\n\t* Removing non-letter characters:\n");
    removeNonLetters(); // Call the function to remove non-letter characters

    return 0;
}
