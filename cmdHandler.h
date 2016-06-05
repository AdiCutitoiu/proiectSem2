#ifndef CMDHANDLER_H_INCLUDED
#define CMDHANDLER_H_INCLUDED

/**
 *Command for myStrrev function call
 */
#define STRREV 0

/**
 *Command for myStrcpy function call
 */
#define STRCPY 1

/**
 *Command for myStrncpy function call
 */
#define STRNCPY 2

/**
 *Command for myStrcat function call
 */
#define STRCAT 3

/**
 *Command for myStrchr function call
 */
#define STRCHR 4

/**
 *Command for myStrstr function call
 */
#define STRSTR 5

/**
 *Command for myStrtok function call
 */
#define STRTOK 6

/**
 *Command for myStrupr function call
 */
#define STRUPR 7

/**
 *Command for myStrlwr function call
 */
#define STRLWR 8

/**
 *Command for myStrcmp function call
 */
#define STRCMP 9

/**
 *Command for myStrncmp function call
 */
#define STRNCMP 10

/**
 *Command for myCountStingChar function call
 */
#define COUNTSTRINGCHAR 11

/**
 *Command for myStrlen function call
 */
#define STRLEN 12

/**
 *Maximum string length
 */
#define STRING_LENGTH 20005

/**
 * @brief Scans a number from stdin

   @return Scanned number
 */
int scanNumber();

/**
 * @brief Scans a command from stdin

   The command is a number

   @return Scanned command
 */
int scanCommand();

/**
 * @brief Scans a string from stdin

   @param str The string to be scanned
 */
void scanString(char *str);

/**
 * @brief Scans two strings from stdin

   @param first String to be scanned
   @param second String to be scanned
 */
void scan2Strings(char *first, char *second);

/**
 * @brief Scans two strings and one number from stdin

   The scanning order is : string, string, number

   @param first String to be scanned
   @param second String to be scanned

   @return returns the scanned number
 */
int scan2Strings1Number(char *first, char *second);

/**
 * @brief Prints a string

   @param str The string to be printed
 */
void printString(char *str);

/**
 * @brief Prints a number

   @param number The number to be printed
 */
void printNumber(int number);

/**
 * @brief Reads, interprets commands, makes calls to myLibrary functions

   The interpretted commands are defined at the beginning of the header file
 */
void commandInterpreter();

#endif // CMDHANDLER_H_INCLUDED
