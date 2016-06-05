#ifndef MYSTRING_H_INCLUDED
#define MYSTRING_H_INCLUDED
#include <stdio.h>
#include <stdbool.h>

/**
 *@brief Gets a line from stdin.

  The line length must be less than the alocated memory for the string

  @param str The string where the line will be put
 */
char* myGetline(char *str);

/**
 *@brief Reverses a given string

  @param str The string to be reversed
 */
void myStrrev(char *str);

/**
 *@brief Copies a string to another

  @param destination Becomes the copy of the string from source
  @param source The string to be copied
 */
void myStrcpy(char *destination, char* source);

/**
  *@brief Copies a number of characters from a string to another string

   @param nrCharacters Represents the number of characters to be copied
   @param destination The location where the characters will be copied
   @param source The string to be copied
  */
void myStrncpy(char *destination, char *source, int nrCharacters);

/**
 *@brief Concatenates a string to the end of another

  @param first The result of the concatenation
  @param second The string to be concatenated
 */
void myStrcat(char *first, char *second);

/**
 *@brief Searches for a character in string

  @param str The string in which the search is made
  @param characterToFind The searched character

  @return A pointer to the first position in the string where the
          character occurs
  @return NULL if the character was not found*/
char* myStrchr(char *str, char characterToFind);

/**
 *@brief Searches a string for the occurences of another string

  @param first The string in which the search will be made
  @param second The searched string

  @return A pointer to the first occurence of second
  @return NULL if the second string does not occur
 */
char* myStrstr(char *first, char *second);

/**
  *@brief Computes the length of a string

   @param str The string whose length will be computed
   @return The length of the string*/
int myStrlen(char *str);

/**
  @brief Splits the given string according to the delimiting characters

  For the first time, the function is called with a pointer to a string and
  a list of delimiters
  For each other time, the function is called with the NULL pointer and the same list
  of delimiters.

  @param str The string which will be split
  @param delimiters The list of delimiters

  @return A pointer to a string between two occurrences of a delimiter
  @return NULL if the string can be split no more
  */
char* myStrtok(char *str, char *delimiters);

/**
 *@brief Transformes an English alphabet character to its uppercase version

  @param character The character which will be transformed

  @return The uppercase version of the character
  @return The same character if the character was not alphabetical or
          already uppercase
 */
char myToupper(char character);

/**
 *@brief Transformes an English alphabet character to its lowercase version

  @param character The character which will be transformed

  @return The lowercase version of the character
  @return The same character if the character was not alphabetical or
          already lowercase
 */
char myTolower(char character);

/**
 *@brief Transforms all the lowercase characters in the given string to
         uppercase characters

  @param str The transformed string
 */
void myStrupr(char *str);

/**
 *@brief Transforms all the uppercase characters in the given string to
         lowercase characters

  @param str The transformed string
 */
void myStrlwr(char *str);

/**
  *@brief Compares two strings lexicographically

   @param first String to be compared
   @param second String to be compared


   @return  A number:
   @return  <0 if first <  second
   @return   0 if first == second
   @return  >0 if first >  second
  */
int myStrcmp(char *first, char *second );

/**
  *@brief Compares a given number of characters of two string

   @param first String to be compared
   @param second String to be compared
   @param nrCharacters Number of characters to be compared

   @return  A number:
   \return  <0 if first <  second
   @return   0 if first == second
   @return  >0 if first >  second
  */
int myStrncmp(char *first, char *second, int nrCharacters);

/**
 *@brief Counts the number of occurences of a given character in
         a string

  @param str The string in which the counting will be made
  @param character The character which occurences will be counted

  @return Number of occurences
 */
int myCountStringChar(char* str, char character);

#endif // MYSTRING_H_INCLUDED
