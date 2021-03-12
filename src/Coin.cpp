/*
 * @file Coin.cpp
 * This represents a collectible coin for the store.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * Coin Class:
 * This coin class is derived from the Collectible class. It stores the type,
 * year and grade for each collectible coin the store sells.
*/

#include "Coin.h"

//------------------------------Constructor---------------------------------
/* Convenience constructor.
* @pre     None.
* @post    Initializes the object with the given type and grade.
* @param   const int yearC
* @param   const string typeC
* @param   const int gradeC
*/
Coin::Coin(const int yearC, const string typeC, const int gradeC) {
   if (yearC < 0 || yearC > 9999) {
      cerr << "\nCoin year " << yearC << " could be incorrect.\n";
   }
   if (gradeC < 0 || gradeC > 100) {
      cerr << "\nCoin grade " << gradeC << " could be incorrect.\n";
   }
   setYear(yearC); // year is stored in base class
   type = typeC;
   grade = gradeC;
}

//------------------------------getHashCode---------------------------------
/* Hash code generator
* @pre     None.
* @post    Returns the hash code for the Coin object.
*/
int Coin::getHashCode() const {
   // This hash code is not critical, set equal to the first, middle, and 
   // last characters of the type string and multiply by the prime number 7.
   // hash(str) = int(str[0]) + int(str[lenght/2])*7 + 
   //             int(str[lenght-1])*7*7
   if (type.empty()) return 0; // return 0 for empty string
   int hashC = int(type[0]) + int(type[type.length()/2]) * 7 + 
               int(type[type.length()-1]) * 7 * 7;
   return hashC;
}

//------------------------------toString------------------------------------
/* Creates a string for output.
* @pre     None.
* @post    Returns a string with the follwoing order: type year grade.
*          All separated by a single space.
*/
string Coin::toString() const {
   return type + ", " + to_string(getYear()) + ", " + to_string(grade);
}

//------------------------------create--------------------------------------
/* Creates a new object.
* @pre     None.
* @post    Returns a pointer to the new empty object.
*/
Coin* Coin::create() const {
   return new Coin;
}

//------------------------------clone---------------------------------------
/* Creates a clone of this object.
* @pre     None.
* @post    Returns the cloned object.
*/
Coin* Coin::clone() {
   return new Coin(getYear(), type, grade);
}

/**---------------------------operator<-------------------------------------
 * Compares two Collectible objects.
 * @pre     A Coin object to compare to.
 * @post    Returns true if lhs < rhs, false other wise. Sorting order is
 *          type, then year, then grade.
 * @param   const Hashable& rhs
*/
bool Coin::operator<(const Hashable& rhs) const {
   // check if same object
   if (this == &rhs) {
      return false;
   }

   // Use dynamic casting to cast down to Coin, check for nullptr.
   const Coin* item = dynamic_cast<const Coin*>(&rhs);
   if (item == nullptr) {
      cerr << "\nRight hand side object is not a Coin object\n" << endl;
      return false;
   }
   else {
      // Method should sort first by type, year and then grade.
      if (type != item->type) {
         return type < item->type;
      }
      else if (getYear() != item->getYear()) {
         return getYear() < item->getYear();
      }
      else {
         return grade < item->grade;
      }
   }
}

/**---------------------------operator==------------------------------------
 * Compares two Collectible objects.
 * @pre     A Coin object to compare to.
 * @post    Returns true if lhs == rhs, false other wise. Type, year and
 *          grade must be equal to be true.
 * @param   const Hashable& rhs
*/
bool Coin::operator==(const Hashable& rhs) const {
   // check if same object
   if (this == &rhs) {
      return true;
   }

   // Use dynamic casting to cast down to Coin, check for nullptr.
   const Coin* item = dynamic_cast<const Coin*>(&rhs);
   if (item == nullptr) {
      cerr << "\nRight hand side object is not a Coin object\n" << endl;
      return false;
   }
   else {
      // Method should sort first by type, year and then grade.
      return (type == item->type) && (getYear() == item->getYear()) &&
             (grade == item->grade);
   }
}