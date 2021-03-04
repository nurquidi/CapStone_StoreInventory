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

#include "SportsCard.h"

//------------------------------Constructor---------------------------------
/* Convenience constructor.
* @pre     None.
* @post    Initializes the object with the given parameters.
* @param   const int yearSC
* @param   const string playerSC
* @param   const string manufacturerSC
* @param   const string gradeSC
*/
SportsCard::SportsCard(const int yearSC, const string playerSC,
   const string manufacturerSC, const string gradeSC) {
   setYear(yearSC);
   player = playerSC;
   manufacturer = manufacturerSC;
   grade = gradeSC;
}

//------------------------------getHashCode---------------------------------
/* Hash code generator
* @pre     None.
* @post    Returns the hash code for the object.
*/
int SportsCard::getHashCode() const {
   // This hash code is not critical, set equal to average of all 4 data 
   // members.
   // Conver each string to an int = int(str[0]) + int(str[lenght/2])*7 + 
   //             int(str[lenght-1])*7*7
   // hash code = (year + player + manufacturer + grade) / 4
   
   // return 0 if empty
   if (player.empty() || manufacturer.empty() || grade.empty()) return 0;

   int hashPlayer = int(player[0]) + int(player[player.length() / 2]) * 7 +
                    int(player[player.length() - 1]) * 7 * 7;
   int hashMnf = int(manufacturer[0]) + 
                 int(manufacturer[manufacturer.length() / 2]) * 7 +
                 int(manufacturer[manufacturer.length() - 1]) * 7 * 7;
   int hashGrade = int(grade[0]) + int(grade[grade.length() / 2]) * 7 +
                   int(grade[grade.length() - 1]) * 7 * 7;
   return ((getYear() + hashPlayer + hashMnf + hashGrade) / 4);
}

//------------------------------toString------------------------------------
/* Creates a string for output.
* @pre     None.
* @post    Returns a string with the following order: player year
*          manufacturer grade, all separated by a single space and comma.
*/
string SportsCard::toString() const {
   return player + ", " + to_string(getYear()) + ", " +
          manufacturer + ", " + grade;
}

//------------------------------create--------------------------------------
/* Creates a new object.
* @pre     None.
* @post    Returns a pointer to the new empty object.
*/
SportsCard* SportsCard::create() const {
   return new SportsCard;
}

//------------------------------clone---------------------------------------
/* Creates a clone of this object.
* @pre     None.
* @post    Returns the cloned object.
*/
SportsCard* SportsCard::clone() {
   return new SportsCard(getYear(), player, manufacturer, grade);
}

/**---------------------------operator<-------------------------------------
 * Compares two Collectible objects.
 * @pre     A SportsCard object to compare to.
 * @post    Returns true if lhs < rhs, false other wise. Sorting order is
 *          player, year, manufacturer and grade.
 * @param   const Hashable& rhs
*/
bool SportsCard::operator<(const Hashable& rhs) const {
   // check if same object
   if (this == &rhs) {
      return false;
   }

   // Use dynamic casting to cast down to SportsCard, check for nullptr.
   const SportsCard* item = dynamic_cast<const SportsCard*>(&rhs);
   if (item == nullptr) {
      cerr << "Right hand side object is not a SportsCard object" << endl;
      return false;
   }
   else {
      // Use the sorting order of player, year, manufacturer and grade.
      if (player != item->player) {
         return player < item->player;
      }
      else if (getYear() != item->getYear()) {
         return getYear() < item->getYear();
      }
      else if (manufacturer != item->manufacturer) {
         return manufacturer < item->manufacturer;
      }
      else {
         return grade < item->grade;
      }
   }
}

/**---------------------------operator==------------------------------------
 * Compares two Collectible objects.
 * @pre     A SportsCard object to compare to.
 * @post    Returns true if lhs == rhs, false other wise. Player, year,
 *          manufacturer and grade all must be equal.
 * @param   const Hashable& rhs
*/
bool SportsCard::operator==(const Hashable& rhs) const {
   // check if same object
   if (this == &rhs) {
      return true;
   }

   // Use dynamic casting to cast down to SportsCard, check for nullptr.
   const SportsCard* item = dynamic_cast<const SportsCard*>(&rhs);
   if (item == nullptr) {
      cerr << "Right hand side object is not a SportsCard object" << endl;
      return false;
   }
   else {
      return (player == item->player) && (getYear() == item->getYear()) &&
             (manufacturer == item->manufacturer) && (grade == item->grade);
   }
}
