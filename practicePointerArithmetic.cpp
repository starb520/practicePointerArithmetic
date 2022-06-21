
#include <iostream>
#include <string>
#include <array>
using namespace std;

void getText(char* text);                                      // get some text from a user
void getLetter(char* letter);                                  // get a letter from a user
int getNumLetterString(const char* text, const char* letter);  // number of times a specific letter appears in some text, for loop
int getNumLetterString2(char* text, const char* letter);       // number of times specific letter appears in some text, pointer loop
 
int main()
{
   // allocate the memory for some text
   char* text = new(nothrow) char[256];

   // check if memory is available for text
   if (!text)
      cout << "No memory! This is bad\n";

   // allocate the memory for a letter
   char* letter = new(nothrow) char;

   // check if memory is available for a letter
   if (!letter)
      cout << "No memory! This is bad\n";

   // call functions to prompt user for some text and a letter
   getText(text);
   getLetter(letter);

   // display the number of times a letter  appears in some text using for loop
   int count = getNumLetterString(text, letter);
   cout << "Count using the array loop:   " << count << endl;

   // display the number of times a letter appears in some text using pointer loop
   int count2 = getNumLetterString2(text, letter);
   cout << "Count using the pointer loop: " << count2 << endl;

}



/*******************************************
* Get some text from a user.
*******************************************/
void getText(char* text)
{
   cout << "Enter text: ";
   cin.getline(text, 256);
}


/*******************************************
* Get a letter from a user.
*******************************************/
void getLetter(char* letter)
{
   cout << "Enter a letter: ";
   cin >> letter;
}


/*******************************************
* Use an array loop to find the # if times
* a letter appears in some text.
*******************************************/
int getNumLetterString(const char* text, const char* letter)
{
   // use an index loop to find the number of times a letter appears in a string
   int length = strlen(text);

   // initialize a variable to hold the number of times a letter appears in a string
   int count = 0;
   for (int i = 0; i < length; i++)
   {
      if (text[i] == *letter)
         count += 1;
   }
   return count;
}


/*******************************************
* Use pointer notation to find the # of 
* times a letter appears in some text.
*******************************************/
int getNumLetterString2(char* text, const char* letter)
{
   // initialize a variable to hold the number of times a letter appears in a string
   int count = 0;
   for (char* p = text; *p; p++)
   {
      if (*p == *letter)
         count += 1;
   }
   return count;
}
