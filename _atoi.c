#include "shell.h"

/**
 * Determine if the shell is running in interactive mode.
 * @param info: Pointer to a structure containing shell information.
 * @return 1 if interactive mode, 0 otherwise.
 */
int checkInteractiveMode(info_t *info) {
    return (isatty(STDIN_FILENO) && info->readfd <= 2);
}

/**
 * Check if a character is a delimiter.
 * @param c: The character to check.
 * @param delim: The delimiter characters.
 * @return 1 if true, 0 if false.
 */
int isDelimiterChar(char c, const char *delim) {
    while (*delim) {
        if (*delim == c) {
            return 1;
        }
        delim++;
    }
    return 0;
}

/**
 * Check if a character is an alphabetic character.
 * @param c: The character to check.
 * @return 1 if it's an alphabetic character, 0 otherwise.
 */
int isAlphabeticChar(int c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * Convert a string to an integer.
 * @param s: The string to be converted.
 * @return 0 if no numbers found, or the converted number.
 */
int stringToInteger(const char *s) {
    int i = 0, sign = 1, flag = 0, output = 0;

    while (s[i]) {
        if (s[i] == '-') {
            sign = -1;
        } else if (s[i] >= '0' && s[i] <= '9') {
            flag = 1;
            output = output * 10 + (s[i] - '0');
        } else if (flag == 1) {
            break;
        }
        i++;
    }

    return sign * output;
}
