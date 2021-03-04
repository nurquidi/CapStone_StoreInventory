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

class SportsCard : public Collectible
{
private:
   // year, uses the private data member in Collectible.
   string player; // stores the players name.
   string manufacturer; // stores the manufacturer of the card.
   string grade;   // grade rating of card.

public:

   //------------------------Default Constructor-------------------------------
   /* Default constructor.
   * @pre     None
   * @post    Initializes the object with year = 0 and empty strings.
   */
   SportsCard() : player(), manufacturer(), grade() {};

   //------------------------------Constructor---------------------------------
   /* Convenience constructor.
   * @pre     None.
   * @post    Initializes the object with the given parameters.
   * @param   const int yearSC
   * @param   const string playerSC
   * @param   const string manufacturerSC
   * @param   const string gradeSC
   */
   SportsCard(const int yearSC, const string playerSC, 
              const string manufacturerSC, const string gradeSC);
      // year is set using setter from Collectible class

   //------------------------------Destructor----------------------------------
   /* Virtual destructor.
   * @pre     None.
   * @post    Releases any dynamic memory used.
   */
   ~SportsCard() {};

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
      // hash code = (year + player + manufacturer + grade) / 4

   //------------------------------toString------------------------------------
   /* Creates a string for output.
   * @pre     None.
   * @post    Returns a string with the following order: player year 
   *          manufacturer grade, all separated by a single space.
   */
   string toString() const;

   //------------------------------create--------------------------------------
   /* Creates a new object.
   * @pre     None.
   * @post    Returns a pointer to the new empty object.
   */
   SportsCard* create() const;

   //------------------------------clone---------------------------------------
   /* Creates a clone of this object.
   * @pre     None.
   * @post    Returns the cloned object.
   */
   SportsCard* clone();

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
    * Compares two Collectible objects.
    * @pre     A SportsCard object to compare to.
    * @post    Returns true if lhs < rhs, false other wise. Sorting order is
    *          player, year, manufacturer and grade.
    * @param   const Hashable& rhs
   */
   bool operator<(const Hashable& rhs) const;
      // Use dynamic casting to cast down to SportsCard, check for nullptr.
      // Use the sorting order of player, year, manufacturer and grade.

   /**---------------------------operator==------------------------------------
    * Compares two Collectible objects.
    * @pre     A SportsCard object to compare to.
    * @post    Returns true if lhs == rhs, false other wise. Player, year,
    *          manufacturer and grade all must be equal.
    * @param   const Hashable& rhs
   */
   bool operator==(const Hashable& rhs) const;
      // Use dynamic casting to cast down to SportsCard, check for nullptr.
};