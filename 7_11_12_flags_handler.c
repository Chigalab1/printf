#include "main.h"

/**
* flags_handler - a function to calculate active flag
* @format: a pointer to a constant character string passed to function
* @i: pointer to an integer passed as a parameter to function
*
* Return: the flags
*/
int flags_handler(const char *format, int *i) {
    int j; /* to iterate through the bitmask */
    int current_i; /* keep track of current position in the format string passed*/
    int flags = 0; /* the possible flag characters for the _printf() function. */
    const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\'', '\0'}; /* the corresponding flag bitmasks for the flags listed above. */
    const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, F_APOSTROPHE, 0};
    for (current_i = *i + 1; format[current_i] != '\0'; current_i++) {
        for (j = 0; FLAGS_CH[j] != '\0'; j++) {
            if (format[current_i] == FLAGS_CH[j]) {
                /* If a flag character is found, set the corresponding flag bitmask. */
                flags = flags | FLAGS_ARR[j];
                break;
            }
        }
        if (FLAGS_CH[j] == '\0') {
            /* If an invalid flag character is found, return an error code. */
            return (-1);
        }
    }
    *i = current_i - 1;
    return (flags);
}
