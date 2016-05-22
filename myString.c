#include "myString.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char* myGetline(char *str) {

	if (str == NULL || feof(stdin))
		return NULL;

	char c;
	int charactersRead = 0;

	while ( (scanf("%c", &c) != EOF) && (c != '\n') )
		str[charactersRead++] = c;

	str[charactersRead] = '\0';

    return str;
}

void myStrrev(char *str){

    char *strEnd = str + myStrlen(str) - 1;
    char auxCharacter;


    while(str < strEnd){

        auxCharacter = *str;
        *str = *strEnd;
        *strEnd = auxCharacter;

        str++;
        strEnd--;
    }

}

void myStrcpy(char *destination, char *from){

    while( ( *destination++ = *from++ ) );
}

void myStrncpy(char *destination, char *source, int nrCharacters){

    if(nrCharacters <= 0)
        return;

    while(nrCharacters-- && ( *destination++ = *source++ ) );
}

void myStrcat(char *first, char *second){

    while(*first){
        first ++;
    }

    myStrcpy(first, second);
}

char* myStrchr(char *str, char characterToFind){

    while((*str != characterToFind) && *str){
        str++;
    }

    return ( *str != '\0' ) ? str : NULL;
}

int myStrlen(char *str){

    char *lastPosition;
    lastPosition = str;

    while(*lastPosition){
        lastPosition++;
    }

    return lastPosition - str;
}

char* myStrtok(char *str, char *delimiters){
    static char *current, *next, *endStr;

    /*Check if this is the first call for a string*/
    if(str != NULL){
        /*If so, compute the pointer to the position of
          the '\0' character (string terminator) -> endPosition*/
        endStr = str + myStrlen(str);

        /*Set the next pointer to be returned and the
          current position to be the beginning of the string*/
        next = current = str;
    }
    else{
        /*Return the NULL pointer if the string cannot be split anymore*/
        if(current == endStr){
            return NULL;
        }

        /*Get the next part of the string*/
        current++;
        /*Save it to next*/
        next = current;
    }

    /*While the end of the string hasn't been reached and a delimiter
      hasn't been found keep iterating*/
    while(*current && !myStrchr(delimiters, *current) )
        current++;

    /*Make the character at the current position a string terminator*/
    *current = '\0';

    /*Return the pointer to the next part of the string*/
    return next;
}

bool myIsalpha(char character){

    return  (character >= 'A' && character <= 'Z') ||
            (character >= 'a' && character <= 'z');
}

bool myIsnum(char character){

    return character >= '0' && character <= '9';
}

bool myIsalnum(char character){

    return myIsalpha(character) || myIsnum(character);
}

char myToupper(char character){

    return (character >= 'a' && character <= 'z') ? (character-32) : (character);
}

char myTolower(char character){

    return (character >= 'A' && character <= 'Z') ? (character+32) : (character);
}

void myStrupr(char *str){

    int stringSize = myStrlen(str);

    for(int index = 0; index < stringSize; index++){
        str[index] = myToupper( str[index] );
    }
}

void myStrlwr(char *str){

    int stringSize = myStrlen(str);

    for(int index = 0; index < stringSize; index++){
        str[index] = myTolower( str[index] );
    }
}

int myStrcmp(char *first, char* second){

    while( (*first == *second) && *first && *second){
        first++;
        second++;
    }

    return *first - *second;
}

int myStrncmp(char *first, char *second, int nrCharacters){

    if(nrCharacters <= 0)
        return 0;

    while( (*first == *second) && *first && *second && --nrCharacters){
        first++;
        second++;
    }

    return *first - *second;
}

int myCountStringChar(char *str, char character){

    int found = 0;

    while(*str){
        if(*str == character){
            found++;
        }
        str++;
    }

    return found;
}
