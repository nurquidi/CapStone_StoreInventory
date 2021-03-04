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

   //------------------------------toString------------------------------------
   /* Creates a string for output.
   * @pre     None.
   * @post    Returns a string with the following order: player year 
   *          manufacturer grade, all separated by a single space and comma.
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

   /**---------------------------operator<-------------------------------------
    * Compares two Collectible objects.
    * @pre     A SportsCard object to compare to.
    * @post    Returns true if lhs < rhs, false other wise. Sorting order is
    *          player, year, manufacturer and grade.
    * @param   const Hashable& rhs
   */
   bool operator<(const Hashable& rhs) const;

   /**---------------------------operator==------------------------------------
    * Compares two Collectible objects.
    * @pre     A SportsCard object to compare to.
    * @post    Returns true if lhs == rhs, false other wise. Player, year,
    *          manufacturer and grade all must be equal.
    * @param   const Hashable& rhs
   */
   bool operator==(const Hashable& rhs) const;
};