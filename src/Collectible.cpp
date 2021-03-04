/*
 * @file Collectible.cpp
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

#include "Collectible.h"

//------------------------------getHashCode---------------------------------
   /* Hash code generator
   * @pre     None.
   * @post    Returns the hash code for the Collectible object.
   */
int Collectible::getHashCode() const {
   // This hash code is not critical, set it equal to the year.
   return yearMade;
}

//------------------------------toString------------------------------------
/* Creates a string for output.
* @pre     None.
* @post    Returns a string with the year.
*/
string Collectible::toString() const {
   return to_string(yearMade);
}

//------------------------------create--------------------------------------
/* Creates a new object.
* @pre     None.
* @post    Returns a pointer to the new empty object.
*/
Collectible* Collectible::create() const {
   return new Collectible;
}

//------------------------------clone---------------------------------------
/* Creates a clone of this object.
* @pre     None.
* @post    Returns the cloned object.
*/
Collectible* Collectible::clone() {
   return new Collectible(yearMade);
}

//------------------------------getYear-------------------------------------
/* Returns the year.
* @pre     None.
* @post    Returns the year it was made.
*/
int Collectible::getYear() const {
   return yearMade;
}

//------------------------------setYear-------------------------------------
/* Sets the year.
* @pre     None.
* @post    Sets the year.
* @param   const int year
*/
void Collectible::setYear(const int year) {
   yearMade = year;
}

/**---------------------------operator<-------------------------------------
 * Compares two Collectible objects.
 * @pre     A collectible object to compare to.
 * @post    Returns true if lhs < rhs, false other wise. Uses the
 *          int::operator< for comparison of the year.
 * @param   const Hashable& rhs
*/
bool Collectible::operator<(const Hashable& rhs) const {
   // check if same object
   if (this == &rhs) {
      return false;
   }

   // Use dynamic casting to cast down to User, check for nullptr.
   const Collectible* item = dynamic_cast<const Collectible*>(&rhs);
   if (item == nullptr) {
      cerr << "Right hand side object is not a Collectible object" << endl;
      return false;
   }
   else {
      return yearMade < item->yearMade;
   }
}

/**---------------------------operator==------------------------------------
 * Compares two Collectible objects.
 * @pre     A collectible object to compare to.
 * @post    Returns true if lhs == rhs, false other wise. Uses the
 *          int::operator== for comparison of the string item.
 * @param   const Collectible& rhs
*/
bool Collectible::operator==(const Hashable& rhs) const {
   // check if same object
   if (this == &rhs) {
      return false;
   }

   // Use dynamic casting to cast down to User, check for nullptr.
   const Collectible* item = dynamic_cast<const Collectible*>(&rhs);
   if (item == nullptr) {
      cerr << "Right hand side object is not a Collectible object" << endl;
      return false;
   }
   else {
      return yearMade == item->yearMade;
   }
}