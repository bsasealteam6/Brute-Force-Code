// Brute Force Code.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "string.h"

#include "words.h"


#define LETTERS_IN_THE_ALPHABET 26

char letters[] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };
char dec_message[50];
char * dec;
char * word1 = {
	"yokmgeosd"
};
char * word2 = {
	"bocrpegmngjr"
};
char * word3 = {
	"xyykprixnigf"
};
char * word_list[3] = {
	word1,
	word2,
	word3
};

int get_letter_index(char letter, char * alphabet) {
	for (int n = 0; n < LETTERS_IN_THE_ALPHABET; n++) {
		if (letter == alphabet[n]) {
			return n;
		}
	}
	return 0;
}

char * decrypt(char * alphabet, int word_num) {
	for (int n = 0; n < strlen(word_list[word_num]); n++) {
		dec_message[n] = letters[get_letter_index(word_list[word_num][n], alphabet)];
	}
	return dec_message;
}

bool is_word(char * word) {
	bool IsWord = false;

	for (int n = 0; n < number_of_words; n++) {
		IsWord = true;
		if (strlen(dictionary[n]) == strlen(word)) {

			for (int let = 0; let < strlen(dictionary[n]); let++) {

				if (word[let] == dictionary[n][let]) {

				}
				else
				{
					IsWord = false;
					break;
				}
			}
		}
		else {
			IsWord = false;
		}
		if (IsWord) {
			
			break;
		}
	}
	return IsWord;
}
bool check(char * decrypted) {
	bool word = is_word(decrypted);
	return word;
}
int main()
{
	char alphabet[LETTERS_IN_THE_ALPHABET];
	int i, j, k, l, m;
	printf("Mixed Alphabet Keyword Decrypter - v0.1 - 10jun16\n");
	printf("dictionary contains %d words\n", number_of_words);

	for (i = 0; i < number_of_words; i++)
	{
		printf("%6d:  ", i);
		for (j = 0; j < strlen(dictionary[i]); j++) {
			printf("%c ", dictionary[i][j]);
		}
		printf("\n");
	} //for (i = 0; i < number_of_words; i++);

	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nAnswers:\n");

	for (int word_number = 0; word_number < 3; word_number++) {
		
		printf("	Word %d:  \n",word_number);
		printf("		Encrypted word: ");
		for (int m = 0; m < strlen(word_list[word_number]); m++) {
			printf("%c ", word_list[word_number][m]);
		}
		printf("\n");
		for (i = 0; i < number_of_words; i++) {
			//
			// initialize the mixed alphabet to ? to help with debugging
			//
			for (l = 0; l < LETTERS_IN_THE_ALPHABET; l++)
			{
				alphabet[l] = '?';
			} //for (l = 0; l < LETTERS_IN_THE_ALPHABET; l++)
			  //
			  // initialize the index that is used to step thru the mixed alphabet
			  //
			l = 0;

			//
			// Process the first/next word in the dictionary one letter at a time
			//
			for (j = 0; j < strlen(dictionary[i]); j++)
			{
				//
				//Determine if this letter is a duplicate of any previous letter in this word
				//
				for (k = 0; k < j; k++)
				{
					if (dictionary[i][k] == dictionary[i][j])
					{
						break;
					}//if (dictionary[i][k] = dictionary[i][j])
				}//for (k = 0; k < j; k++) 

				 // check if this letter is unique in the word and store it into the mixed alphabet if it is
				 //
				if (k == j) {
					alphabet[l] = dictionary[i][j];
					l++;
				}//if (k==j)

			}//for (j = 0; j < strlen(dictionary[j]); j++)

			 //
			 //fill in the rest of the mixed alphabet
			 //

			for (j = 0; j < strlen(letters); j++)
			{
				//
				//Determine if this letter is a duplicate of any previous letter in this word
				//
				bool different = true;
				for (k = 0; k < l; k++)
				{
					if (alphabet[k] == letters[j])
					{
						different = false;
						break;
					}//if (dictionary[i][k] = dictionary[i][j])
				}//for (k = 0; k < j; k++) 

				 // check if this letter is unique in the word and store it into the mixed alphabet if it is
				 //
				if (different) {
					alphabet[l] = letters[j];
					l++;
				}//if (k==j)

			}

			char * dec = decrypt(alphabet, word_number);

			if (check(dec)) {
				printf("		Decrypted word: ");
				for (int m = 0; m < strlen(dec); m++) {
					printf("%c ", dec[m]);
				}
				printf("\n		Keyword: ");
				for (int m = 0; m < strlen(dictionary[i]); m++) {
					printf("%c ", dictionary[i][m]);
				}
				printf("\n\n");
				break;

			}



		}




	}
	return 0;
}

