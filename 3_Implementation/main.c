#include<hangman.h>


int MarkBody(int choicezero);
int Markzero(int choiceone);
int Markone(int choicetwo);
int Marktwo(int choicethree);
int Markthree(int choicefour);
int Markfour(int choicefive);
int test_main();

int main(void)
{
    char Word[100], tempWord[100];       /**Word[] array for the original word and tempWord[] array to get the alphabet from user and compare it with original word**/
    char WordOutput[100];                    /**This array will show the remaining blanks and correct inputs**/
    int mistakes=6, matchFound = 0;          /**player will get 5 chance, so we use wrongTry as chance counter**/
                                                /**matchFound to search the alphabet, if the alphabet from user does not exist
                                                in the original word it will remain 0, upon finding the word, matchFound will
                                                be set as 1**/
    int count = 0 , place = 0, win, length , i;
    char Userletter;

    system("cls");                              /**for clearing the screen**/
    printf("\n\n Enter any word in lower case and hit >>ENTER<<");
    printf("\n\n\t Enter HERE ==>  ");
    scanf("%s",Word);                    /**get the string from opponent**/
    printf("\n\n Now give the COMPUTER to your friend and see if he/she can CRACK it!!!");
    printf("\n\n\tHIT >>ENTER<<");
    getchar();                                  /**hold the computer screen**/
    length = strlen(Word);               /**get the length of the word**/

    system("cls");

    printf("\n\n !!!!!!!!!!!!!!!!!!!Welcome to the HANGMAN GAME!!!!!!!!!!!!!!!!!\n\n\n");   /**Brief description of the game**/
    printf("\n\n You will get 5 chances to guess the right word");
    printf("\n\n So help the Man and get...set...GO..!!");

        printf("\n\t||===== ");                 /**show the HANGMAN**/
        printf("\n\t||    | ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");
        printf("\n\t||      ");

    printf("\n\n     The word has %d alphabets \n\n",length);  /**tell the user how many alphabets the word has**/
    for( i = 0; i < length ; i++)
    {
        WordOutput[i] = '_';
        WordOutput[length] = '\0';
    }

    for(i = 0 ; i < length ; i++)
    {
        printf(" ");
        printf("%c",WordOutput[i]);        /**Show the Word With n(length of the original word) number of underscores (_)**/

    }
    while(mistakes != 0)                        /**while loop for exiting the program when no try left**/
    {
        matchFound = 0;
        printf("\n\n   enter any alphabet from a to z and please use small case!!");
        printf("\n\n\t Enter HERE ==> ");

	    fflush(stdin);

	    scanf("%c",&Userletter);            /**get alphabet from user**/
    if(Userletter < 'a' || Userletter > 'z') /**In case player gives input other than 'a' to 'z' the console will ask again**/
    {
        printf("\n\n\t Wrong input TRY AGAIN ");
        printf("\n\n\t try lower case alphabet");
        matchFound = 2;
    }
    fflush(stdin);
    if (matchFound != 2)
    {
        for(count=0;count<length;count++)    /**for loop to check whether player input alphabet exists or not in the word**/
	    {
		    if(Userletter==Word[count])
		     {
		       matchFound = 1;
                     }//end of if()
            }//end of for()

	   if(matchFound == 0)
                            /**in case of wrong guess**/
	    {

     	      printf("\n\t :( You have %d tries left ",--mistakes);
     	      if(mistakes==5)
              Markfour(mistakes);
              if(mistakes==4)
              Markthree(mistakes);
              if(mistakes==3)
              Marktwo(mistakes);
              if(mistakes==2)
              Markone(mistakes);
              if(mistakes==1)
              Markzero(mistakes);
              if(mistakes==0)
              MarkBody(mistakes);

	    }//end of if()

	   else
	   {
	     for(count = 0; count < length; count++)
             {
     	         matchFound = 0;
                 if(Userletter == Word[count])
	          {
     		     place = count ;
     		     matchFound = 1;
	          }//end of if
    	      if(matchFound == 1)
	          {
                 for(i = 0 ; i < length ; i++)
                 {
                      if( i == place)
                  	  {
                          WordOutput[i] = Userletter; /**Put the alphabet at right position**/
                      }
                      else if( WordOutput[i] >= 'a' && WordOutput[i] <= 'z' ) /** If the position already occupied
                                                                                  by same alphabet then no need to
                                                                                  fill again EASY!! and continue */
                      {
                          continue;
                  	  }

                      else
                      {
                          WordOutput[i] = '_';            /** create blank at not guessed alphabet position **/
                      }
                }
                tempWord[place] = Userletter;      /**put the alphabet in another char array to check with the original word**/
                tempWord[length] = '\0';                    /**put the NULL character at the end of the temp string**/
                win = strcmp(tempWord,Word);      /**upon True comparison it will return 0**/

                if(win == 0)                             /**if the player guessed the whole word right then he/she is the WINNER**/
                {
                    printf("\n\n\t \t YAHOO!!!!! You are the WINNER !!!!!");
                    printf("\n\n\t The Word was %s ",Word);
                    return 0;
                }//end of inner if
	       }//end of outer if
	       test_main();
	       return 0;
	    }//end of for loop
      }//end of else
     }// end of if(matchFound != 2) condition

    printf("\n\n\t");
    for(i = 0 ; i < length ; i++)
      {
          printf(" ");
          printf("%c",WordOutput[i]);                /**Show the original Word With blanks and right Input alphabet**/
      }
    }//end of while loop

      if(mistakes <= 0)                                 /**if the player can not guess the whole word in 5 chances**/
      {
          printf("\n\n\t The Word was %s ",Word);
	      printf("\n\n\t Better luck next!!!");

      }
return 0;
}//end of main();


