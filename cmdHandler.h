#ifndef CMDHANDLER_H_INCLUDED
#define CMDHANDLER_H_INCLUDED

/*Commands for each function*/
#define STRREV 0
#define STRCPY 1
#define STRNCPY 2
#define STRCAT 3
#define STRCHR 4
#define STRSTR 5
#define STRTOK 6
#define STRUPR 7
#define STRLWR 8
#define STRCMP 9
#define STRNCMP 10
#define COUNTSTRINGCHAR 11
#define STRLEN 12


#define STRING_LENGTH 20005

int scanCommand();
int scanNumber();

void scanString(char *str);
void scan2Strings(char *first, char *second);
int scan2String1Number(char *first, char *second);

void printString(char *str);
void printNumber(int number);

void commandInterpreter();

#endif // CMDHANDLER_H_INCLUDED
