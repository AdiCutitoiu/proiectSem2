#include "cmdHandler.h"
#include "myString.h"

/**@file main.c
  *@brief String library.

    Created by Adrian-Nicolae Cutitoiu.
  */

int scanNumber(){
    int number;
    char c;

    scanf("%d", &number);

    scanf("%c", &c);

    return number;
}

int scanCommand(){
    return scanNumber();
}

char scanCharacter(){
    char c, x;

    scanf("%c", &c);

    scanf("%c", &x);

    return c;
}

void scanString(char *str){
    myGetline(str);
}
void scan2Strings(char *first, char *second){
    myGetline(first);
    myGetline(second);
}

int scan2Strings1Number(char *first, char *second){
    scan2Strings(first, second);
    return scanNumber();
}

void printString(char *str){
    printf("%s\n",str);
}

void printNumber(int number){
    printf("%d\n", number);
}

void commandInterpreter(){
    int current_command;

    char *p;

    int number;

    int character;

    char first[STRING_LENGTH], second[STRING_LENGTH];

    while(!feof(stdin)){
        current_command = scanCommand();

        switch(current_command){

            case STRREV:
                scanString(first);
                myStrrev(first);
                printString(first);
                break;

            case STRCPY:
                scan2Strings(first, second);
                myStrcpy(first, second);
                printString(first);
                break;

            case STRNCPY:
                number = scan2Strings1Number(first, second);
                myStrncpy(first, second, number);
                printString(first);
                break;

            case STRCAT:
                scan2Strings(first, second);
                myStrcat(first, second);
                printString(first);
                break;

            case STRCHR:
                scanString(first);
                character = scanCharacter();
                printString(myStrchr(first, character));
                break;

            case STRSTR:
                scan2Strings(first, second);
                printString(myStrstr(first, second));
                break;

            case STRTOK:
                scan2Strings(first, second);
                p = myStrtok(first, second);
                while(p){
                    printString(p);
                    p = myStrtok(NULL, second);
                }
                break;

            case STRUPR:
                scanString(first);
                myStrupr(first);
                printString(first);
                break;

            case STRLWR:
                scanString(first);
                myStrlwr(first);
                printString(first);
                break;
            case STRCMP:
                scan2Strings(first, second);
                printNumber( myStrcmp(first, second) );
                break;

            case STRNCMP:
                number = scan2Strings1Number(first, second);
                printNumber( myStrncmp(first, second, number) );
                break;
            case COUNTSTRINGCHAR:
                scanString(first);
                character = scanCharacter();
                printNumber( myCountStringChar(first, character) );
                break;
            case STRLEN:
                scanString(first);
                printNumber(myStrlen(first));
        }
    }
}
