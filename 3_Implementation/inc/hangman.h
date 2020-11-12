#ifndef HANGMAN_H_INCLUDED
#define HANGMAN_H_INCLUDED
#include<stdio.h>    /*Header file declaration*/

#include<string.h>   /*<string.h> for strcmp();,strlen(); functions use*/

#include<stdlib.h>
/**
*  shows hangman after every incorrect guess
* @param[in] choice
* @return different stages of hangman after every incorrect guess
*/


int MarkBody(int choicezero);
int Markzero(int choiceone);
int Markone(int choicetwo);
int Marktwo(int choicethree);
int Markthree(int choicefour);
int Markfour(int choicefive);

#endif // HANGMAN_H_INCLUDED
