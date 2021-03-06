/*
 * @file FactoryHashable.cpp
 * Factory method for creating Hashable objects.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * Factory Class:
 * Clash with a hastable that creates objects on demand.
*/
#include "FactoryHashable.h"

//------------------------------hash----------------------------------------
/* Takes a char and returns the index number for the createOjb array.
* @pre     Only capital chars and must be A, C, M or S
* @post    Converts the char into a hash number (index of array).
*          Returns -1 if wrong input provided, this can lead to segmentation
*          fault error if not handled correctly.
*/
int FactoryHashable::hash(const char ch) const
{
   // create a hash function that will result in A = 0, C = 1, M = 2, S = 3
   // This is a very simple example of a hash function, so use switch
   // statements to return the correct code.

   if (ch == 'A') return 0;
   if (ch == 'C') return 1;
   if (ch == 'M') return 2;
   if (ch == 'S') return 3;

   // Output error message and return -1
   cerr << "Wrong input data provided for method hash(char).\n";
   return -1;
}

//------------------------------Constructor---------------------------------
/* Default constructor.
* @pre     None.
* @post    Initializes the createObj array with Collectible and Customer
*          objects.
* @param   const int ID
* @param   const string n
*/
FactoryHashable::FactoryHashable() {
   // Initialize createObj array.
   createObj[0] = new CreateCustomer;
   createObj[1] = new CreateComicBook;
   createObj[2] = new CreateCoin;
   createObj[3] = new CreateSportsCard;
}

//------------------------------Destructor----------------------------------
/* Destructor.
* @pre     None.
* @post    Deletes dynamic memory
*/
FactoryHashable::~FactoryHashable() {
   // cycle through createObj array and delete objects
   for (int i = 0; i < ARRAYSIZE; i++) {
      delete createObj[i];
   }
}

//------------------------------createIt------------------------------------
/* Creates the requested object.
* @pre     Valid char code for the hashtable. Only capital chars and
*          must be A, C, M or S.
*          string data must be the correct format for the object type.
*          Format:
*                 - No leading spaces in the string
*                 - A single comma followed by a space in between
*                 data strings.
*          Coin:  Year(int), grade(int), type(string)
*                 Example string: "2001, 65, Lincoln Cent"
*          SportsCard: Year(int), grade(string), player(string), and
*                 manufacturer(strint)
*                 Example string: "1989, Near Mint, Ken Griffey Jr.,
*                                  Upper Deck"
*          ComicBook: Year(int), grade(string), title(string), and
*                 publisher(string)
*                 Example string: "2010, Excellent, X-Men, Marvel"
*          Customer: customerID(int), name(string).
*                 Example string: "999, Pele"
* @post    Returns pointer to new Hashabe object that was created.
*          Returns nullptr if obj not created.
*/
Hashable* FactoryHashable::createIt(char ch, const string data) {
   // Use the hash code to identify correct location createObj array.
   // For example, for a customer: return createObj[0]->create(data);
   int index = hash(ch);
   if (index == -1) return nullptr; // wrong char code provided

   return createObj[index]->create(data);
}