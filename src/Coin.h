/*
 * @file Coin.h
 * This represents a collectible coin for the store.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * Coin Class:
 * This coin class is derived from the Collectible class. It stores the type,
 * year and grade for each collectible coin the store sells.
*/

#pragma once
#include "Collectible.h"
#include <string>

using namespace std;

class Coin : public Collectible
{
private:
   // year, uses the private data member in Collectible.
   string type; // stores the type of coin.
   int grade;   // grade rating of coin.

public:

   //------------------------Default Constructor-------------------------------
   /* Default constructor.
   * @pre     None
   * @post    Initializes the object with type (empty string) and grade = 0.
   */
   Coin() : type(), grade(0) {};

   //------------------------------Constructor---------------------------------
   /* Convenience constructor.
   * @pre     None.
   * @post    Initializes the object with the given type and grade.
   * @param   const int yearC
   * @param   const string typeC
   * @param   const int gradeC
   */
   Coin(const int yearC, const string typeC, const int gradeC);
        // year is set using setter from Collectible class

   //------------------------------Destructor----------------------------------
   /* Virtual destructor.
   * @pre     None.
   * @post    Releases any dynamic memory used.
   */
   ~Coin() {};

   //------------------------------getHashCode---------------------------------
   /* Hash code generator
   * @pre     None.
   * @post    Returns the hash code for the Coin object.
   */
   int getHashCode() const;
      // This hash code is not critical, set equal to the first, middle, and 
      // last characters of the type string and multiply by the prime number 7.
      // hash(str) = int(str[0]) + int(str[lenght/2])*7 + 
      //             int(str[lenght-1])*7*7

   //------------------------------toString------------------------------------
   /* Creates a string for output.
   * @pre     None.
   * @post    Returns a string with the follwoing order: type year grade.
   *          All separated by a single space.
   */
   string toString() const;

   //------------------------------create--------------------------------------
   /* Creates a new object.
   * @pre     None.
   * @post    Returns a pointer to the new empty object.
   */
   Coin* create() const;

   //------------------------------clone---------------------------------------
   /* Creates a clone of this object.
   * @pre     None.
   * @post    Returns the cloned object.
   */
   Coin* clone();

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
    * @pre     A Coin object to compare to.
    * @post    Returns true if lhs < rhs, false other wise. Sorting order is 
    *          type, then year, then grade.
    * @param   const Hashable& rhs
   */
   bool operator<(const Hashable& rhs) const;
      // Use dynamic casting to cast down to Coin, check for nullptr.
      // Method should sort first by type, year and then grade.

   /**---------------------------operator==------------------------------------
    * Compares two Collectible objects.
    * @pre     A Coin object to compare to.
    * @post    Returns true if lhs == rhs, false other wise. Type, year and 
    *          grade must be equal to be true.
    * @param   const Hashable& rhs
   */
   bool operator==(const Hashable& rhs) const;
      // Use dynamic casting to cast down to Coin, check for nullptr.
};