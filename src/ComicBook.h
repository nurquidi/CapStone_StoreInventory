/*
 * @file ComicBook.h
 * This represents a collectible comic book for the store.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * ComicBook Class:
 * This ComicBook class is derived from the Collectible class. It stores the 
 * publisher, title, year and grade of the comic books the store sells.
*/

#pragma once
#include "Collectible.h"
#include <string>
#include <iostream>

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

   //------------------------------toString------------------------------------
   /* Creates a string for output.
   * @pre     None.
   * @post    Returns a string with the following order: publisher title
   *          year grade, all separated by a single space and comma.
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

   /**---------------------------operator<-------------------------------------
    * Compares two ComicBook objects.
    * @pre     A ComicBook object to compare to.
    * @post    Returns true if lhs < rhs, false other wise. Sorting order is
    *          player, year, manufacturer and grade.
    * @param   const Hashable& rhs
   */
   bool operator<(const Hashable& rhs) const;

   /**---------------------------operator==------------------------------------
    * Compares two ComicBook objects.
    * @pre     A ComicBook object to compare to.
    * @post    Returns true if lhs == rhs, false other wise. Player, year,
    *          manufacturer and grade all must be equal.
    * @param   const Hashable& rhs
   */
   bool operator==(const Hashable& rhs) const;
};