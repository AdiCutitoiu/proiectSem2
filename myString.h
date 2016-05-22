#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED
#include <stdio.h>
#include <stdbool.h>

/*Gets a line of stdin. The line length must be
  less than the alocated memory for the string*/
char* myGetline(char *str);

/*Reverses a given string*/
void myStrrev(char *str);

/*Copies the string "source" to string "destination"*/
void myStrcpy(char *destination, char* source);

/*Copies "nrCharacters" from string "source" to string
  "destination"*/
void myStrncpy(char *destination, char *source, int nrCharacters);

/*Concatenates the second string at the end of the first string*/
void myStrcat(char *first, char *second);

/*Searches for the character "characterToFind" in string "str"
  Returns a pointer to the first position in the string where the
  character occurs
  Returns NULL if the character was not found*/
char* myStrchr(char *str, char characterToFind);

//MYSTRSTR

/*Returns the length of the string*/
int myStrlen(char *str);

/*Splits the given string according to the delimiting characters
  For the first time, the function is called with a pointer to a string and
  a list of delimiters
  For each other time, the function is called with the NULL pointer and a list
  of delimiters.

  Each time the function is called, it returns a pointer to a string
  between two occurrences of a delimiter(exception making the first call, in which
  the string is between the beginning of the original string and the first occurrence
  of a delimiter.

  If pointers to all the parts of the split string have been already returned, the
  returned pointer is NULL*/
char* myStrtok(char *str, char *delimiters);

/*Checks if the given character is a letter of the
  English alphabet*/
bool myIsalpha(char character);

/*Checks if the given character is a digit*/
bool myIsnum(char character);

/*Checks if the given character is a letter of the
  English alphabet or a digit*/
bool myIsalnum(char character);

/*Returns the uppercase of a given lowercase character
  If the given character is not lowercase, it will be returned
  without changes*/
char myToupper(char character);

/*Returns the lowercase of a given uppercase character
  If the given character is not uppercase, it will be returned
  without changes*/
char myTolower(char character);

/*Transforms all the lowercase characters in the given string to
  uppercase characters*/
void myStrupr(char *str);

/*Transforms all the uppercase characters in the given string to
  lowercase characters*/
void myStrlwr(char *str);

/*Compares two strings lexicographically
  Returns:  <0 if first <  second
             0 if first == second
            >0 if first >  second*/
int myStrcmp(char *first, char *second );

/*Compares the first "nrCharacters" of two
  strings lexicographically
  Returns:  <0 if first <  second
             0 if first == second
            >0 if first >  second*/
int myStrncmp(char *first, char *second, int nrCharacters);

/*Counts the number of occurences of a given character in
  a string*/
int myCountStringChar(char* str, char character);

/*inttostr*/
/*strtoint*/

/*floattostr*/
/*strtofloat*/

/*doubletostr*/
/*strtodouble*/


#endif // MYSTRING_H_INCLUDED
