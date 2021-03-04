/*
 * @file Collectible.h
 * Generic Collectible class.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * Collectible Class:
 * Simple generic Collectible class that contains the items year. This class
 * is meant to be used as a base class for other collectible items. Since the 
 * year the collectible was made is common among all collectibles it is stored
 * here.
*/

#pragma once
#include "Item.h"
#include <string>
#include <iostream>

using namespace std;

class Collectible : public Item
{
private:
   int yearMade;      // stores the items year it was made.

public:

   //------------------------Default Constructor-------------------------------
   /* Default constructor.
   * @pre     None
   * @post    Initializes the object with year = 0.
   */
   Collectible() : yearMade(0) {};

   //------------------------------Constructor---------------------------------
   /* Convenience constructor.
   * @pre     None.
   * @post    Initializes the object with the given year.
   * @param   const int year
   */
   Collectible(const int year) : yearMade(year) {};

   //------------------------------Destructor----------------------------------
   /* Virtual destructor.
   * @pre     None.
   * @post    Releases any dynamic memory used.
   */
   virtual ~Collectible() {};

   //------------------------------getHashCode---------------------------------
   /* Hash code generator
   * @pre     None.
   * @post    Returns the hash code for the Collectible object.
   */
   virtual int getHashCode() const;
      // This hash code is not critical, set it equal to the year.

   //------------------------------toString------------------------------------
   /* Creates a string for output.
   * @pre     None.
   * @post    Returns a string with the year.
   */
   virtual string toString() const;

   //------------------------------create--------------------------------------
   /* Creates a new object.
   * @pre     None.
   * @post    Returns a pointer to the new empty object.
   */
   virtual Collectible* create() const;

   //------------------------------clone---------------------------------------
   /* Creates a clone of this object.
   * @pre     None.
   * @post    Returns the cloned object.
   */
   virtual Collectible* clone();

   //------------------------------getYear-------------------------------------
   /* Returns the year.
   * @pre     None.
   * @post    Returns the year it was made.
   */
   virtual int getYear() const;

   //------------------------------setYear-------------------------------------
   /* Sets the year.
   * @pre     None.
   * @post    Sets the year.
   * @param   const int year
   */
   virtual void setYear(const int year);

   /**---------------------------operator<-------------------------------------
    * Compares two Collectible objects.
    * @pre     A collectible object to compare to.
    * @post    Returns true if lhs < rhs, false other wise. Uses the 
    *          int::operator< for comparison of the year.
    * @param   const Hashable& rhs
   */
   virtual bool operator<(const Hashable& rhs) const;
      // Use dynamic casting to cast down to Collectible, check for nullptr.

   /**---------------------------operator==------------------------------------
    * Compares two Collectible objects.
    * @pre     A collectible object to compare to.
    * @post    Returns true if lhs == rhs, false other wise. Uses the
    *          int::operator== for comparison of the string item.
    * @param   const Collectible& rhs
   */
   virtual bool operator==(const Hashable& rhs) const;
      // Use dynamic casting to cast down to Collectible, check for nullptr.
};