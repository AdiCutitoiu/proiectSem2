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
/*Creates the pattern of a string
  The pattern will be used only by the myStrstr() function
  As a result, the user of the library
  will not have access to this function*/
int *pattern(char *str){
    /*Length of the string*/
    int n = myStrlen(str);

    /*Allocate memory for the pattern vector*/
    int *p = malloc(n * sizeof(int));

    p[0] = 0;

    int index = 1, currentLen = 0;

    /*Iterate from 1 to n-1*/
    while(index < n){

        /*If characters match*/
        if(str[currentLen] == str[index]){
            /*Set the length of the current prefix suffix*/
            currentLen++;
            p[index] = currentLen;
            index++;
        }

        else{
            /*Try to find a suffix of the current prefix with
              a smaller length*/
            if(currentLen != 0){
                currentLen = p[currentLen - 1];
            }
            /*All the suffixes of the current prefix were tried
              and no match found*/
            else{
                p[index] = 0;
                index++;
            }
        }
    }
    /*Return the pattern vector*/
    return p;
}

char *myStrstr(char * first, char *second){

    /*Compute the lengths of the strings*/
    int lengthF = myStrlen(first);
    int lengthS = myStrlen(second);

    /*Compute the pattern vector for the second string*/
    int *p = pattern(second);

    /*f_index is an iterator for the first string
      s_index is an iterator for the second string*/
    int f_index = 0, s_index = 0;

    /*Iterate the first string*/
    while(f_index < lengthF){

        /*If the current characters match,
          advance to the next characters*/
        if(second[s_index] == first[f_index])
        {
            f_index++;
            s_index++;
        }

        /*A match of the string was found*/
        if(s_index == lengthS){
            free(p);    /*Free the memory used for the pattern vector*/

            /*Return a pointer to the match*/
            return first + f_index - s_index;
        }
        /*If characters do not match anymore*/
        else if(f_index < lengthF && second[s_index] != first[f_index]){

            /*If we may still have a pattern*/
            if(s_index)
                /*Try a shorter prefix suffix*/
                s_index = p[s_index - 1];
            else
                /*Go to the next character in the first string*/
                f_index++;
        }
    }

    /*Deallocate the memory for the pattern vector*/
    free(p);

    /*No pattern found means returning NULL*/
    return NULL;

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
          to be the beginning of the string*/
        next = str;

        /*Skip the charactern in the beginning of the string
          which are delimiters*/
        while(next < endStr && myStrchr(delimiters, *next))
            next++;

        /*If the end of the string was reached return NULL*/
        if(next == endStr)
            return NULL;

        current = next;
    }
    else{
        /*Return the NULL pointer if the string cannot be split anymore*/
        if(current == endStr){
            return NULL;
        }

        /*Get the next part of the string*/
        current++;

        /*Save the pointer to it to next*/
        next = current;
    }

    /*While the end of the string hasn't been reached and a delimiter
      hasn't been found keep iterating*/
    while(*current){

        /*If the current substring is valid (starts with a non-delimiter, ends
          right before a delimiter)
          Stop iterating*/
        if(!myStrchr(delimiters, *next) && myStrchr(delimiters, *current))
            break;

        /*If next points to a delimiter,
          skip to the following character*/
        if(myStrchr(delimiters, *next)){
            next = current;
        }
        current++;
    }

    /*Make the character at the current position a string terminator*/
    *current = '\0';

    /*Return the pointer to the next part of the string*/
    /*CORNER CASE: current reached the end of the string, but
      the character to which next is pointing is a delimiter
      CORNER CASE: next reaches the string terminator*/
    return myStrchr(delimiters, *next) || *next == '\0'? NULL : next;
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
