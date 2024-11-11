// input_utils.h
#ifndef INPUT_UTILS_H
#define INPUT_UTILS_H

#include <stddef.h>  // For the size_t type used in function parameters

// Function prototypes
void removeNewline(char *input, size_t size);
void getInput(const char *prompt, char *input, size_t size);
void capitalizeWords(char *input);
int getValidNumberInput(int min);
void toLowerCase(char *str);

#endif // INPUT_UTILS_H
