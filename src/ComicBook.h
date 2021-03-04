/*
 * @file SportsCard.h
 * This represents a collectible sports card for the store.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * SportsCard Class:
 * This sports card class is derived from the Collectible class. It stores the player,
 * year, manufacturer and grade for each collectible sports card the store sells.
*/

#pragma once
#include "Collectible.h"
#include <string>

using namespace std;

class ComicBook : public Collectible
{
private:
   // year, uses the private data member in Collectible.
   string title; // stores the title of the comic book.
   string publisher; // stores the publisher.
   string grade;   // grade rating of comic book.

public:

   //------------------------Default Constructor-------------------------------
   /* Default constructor.
   * @pre     None
   * @post    Initializes the object with year = 0 and empty strings.
   */
   ComicBook() : title(), publisher(), grade() {};

   //------------------------------Constructor---------------------------------
   /* Convenience constructor.
   * @pre     None.
   * @post    Initializes the object with the given paramaters.
   * @param   const int yearC
   * @param   const string titleC
   * @param   const string publisherC
   * @param   const string gradeC
   */
   ComicBook(const int yearC, const string titleC,
             const string publisherC, const string gradeC);
      // year is set using setter from Collectible class

   //------------------------------Destructor----------------------------------
   /* Virtual destructor.
   * @pre     None.
   * @post    Releases any dynamic memory used.
   */
   ~ComicBook() {};

   //------------------------------getHashCode---------------------------------
   /* Hash code generator
   * @pre     None.
   * @post    Returns the hash code for the object.
   */
   int getHashCode() const;
      // This hash code is not critical, set equal to average of all 4 data 
      // members.
      // Conver each string to an int = int(str[0]) + int(str[lenght/2])*7 + 
      //             int(str[lenght-1])*7*7
      // hash code = (year + title + publisher + grade) / 4

   //------------------------------toString------------------------------------
   /* Creates a string for output.
   * @pre     None.
   * @post    Returns a string with the following order: publisher title
   *          year grade, all separated by a single space.
   */
   string toString() const;

   //------------------------------create--------------------------------------
   /* Creates a new object.
   * @pre     None.
   * @post    Returns a pointer to the new empty object.
   */
   ComicBook* create() const;

   //------------------------------clone---------------------------------------
   /* Creates a clone of this object.
   * @pre     None.
   * @post    Returns the cloned object.
   */
   ComicBook* clone();

   //------------------------------getYear-------------------------------------
   /* Returns the year.
   * @pre     None.
   * @post    Returns the year it was made.
   */
   int getYear() const;
      // Use the Collectible getYear method

   //------------------------------setYear-------------------------------------
   /* Sets the year.
   * @pre     None.
   * @post    Sets the year.
   * @param   const int year
   */
   void setYear(const int year);
      // Use the Collectible setYear method

   /**---------------------------operator<-------------------------------------
    * Compares two ComicBook objects.
    * @pre     A ComicBook object to compare to.
    * @post    Returns true if lhs < rhs, false other wise. Sorting order is
    *          player, year, manufacturer and grade.
    * @param   const Hashable& rhs
   */
   bool operator<(const Hashable& rhs) const;
      // Use dynamic casting to cast down to ComicBook, check for nullptr.
      // Use the sorting order of publisher, title, year and grade.

   /**---------------------------operator==------------------------------------
    * Compares two ComicBook objects.
    * @pre     A ComicBook object to compare to.
    * @post    Returns true if lhs == rhs, false other wise. Player, year,
    *          manufacturer and grade all must be equal.
    * @param   const Hashable& rhs
   */
   bool operator==(const Hashable& rhs) const;
      // Use dynamic casting to cast down to ComicBook, check for nullptr.
};