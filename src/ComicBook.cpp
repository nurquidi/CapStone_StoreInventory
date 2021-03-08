/*
 * @file ComicBook.cpp
 * This represents a collectible comic book for the store.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * ComicBook Class:
 * This ComicBook class is derived from the Collectible class. It stores the
 * publisher, title, year and grade of the comic books the store sells.
 */

#include "ComicBook.h"

 //------------------------------Constructor---------------------------------
 /* Convenience constructor.
 * @pre     None.
 * @post    Initializes the object with the given paramaters.
 * @param   const int yearC
 * @param   const string titleC
 * @param   const string publisherC
 * @param   const string gradeC
 */
ComicBook::ComicBook(const int yearC, const string titleC,
   const string publisherC, const string gradeC) {
   if (yearC < 0 || yearC > 9999) {
      cerr << "Coin year " << yearC << " could be incorrect.\n";
   }
   setYear(yearC);
   title = titleC;
   publisher = publisherC;
   grade = gradeC;
}

//------------------------------getHashCode---------------------------------
/* Hash code generator
* @pre     None.
* @post    Returns the hash code for the object.
*/
int ComicBook::getHashCode() const {
   // This hash code is not critical, set equal to average of all 4 data 
   // members.
   // Conver each string to an int = int(str[0]) + int(str[lenght/2])*7 + 
   //             int(str[lenght-1])*7*7
   // hash code = (year + title + publisher + grade) / 4
   
   // return 0 if empty
   if (title.empty() || publisher.empty() || grade.empty()) return 0;

   int hashTitle = int(title[0]) + int(title[title.length() / 2]) * 7 +
                   int(title[title.length() - 1]) * 7 * 7;
   int hashPub = int(publisher[0]) + 
                 int(publisher[publisher.length() / 2]) * 7 +
                 int(publisher[publisher.length() - 1]) * 7 * 7;
   int hashGrade = int(grade[0]) + int(grade[grade.length() / 2]) * 7 +
      int(grade[grade.length() - 1]) * 7 * 7;
   return ((getYear() + hashTitle + hashPub + hashGrade) / 4);
}

//------------------------------toString------------------------------------
/* Creates a string for output.
* @pre     None.
* @post    Returns a string with the following order: publisher title
*          year grade, all separated by a single space and comma.
*/
string ComicBook::toString() const {
   return publisher + ", " + title + ", " + to_string(getYear()) + ", "
          + grade;
}

//------------------------------create--------------------------------------
/* Creates a new object.
* @pre     None.
* @post    Returns a pointer to the new empty object.
*/
ComicBook* ComicBook::create() const {
   return new ComicBook;
}

//------------------------------clone---------------------------------------
/* Creates a clone of this object.
* @pre     None.
* @post    Returns the cloned object.
*/
ComicBook* ComicBook::clone() {
   return new ComicBook(getYear(), title, publisher, grade);
}

/**---------------------------operator<-------------------------------------
 * Compares two ComicBook objects.
 * @pre     A ComicBook object to compare to.
 * @post    Returns true if lhs < rhs, false other wise. Sorting order is
 *          player, year, manufacturer and grade.
 * @param   const Hashable& rhs
*/
bool ComicBook::operator<(const Hashable& rhs) const {
   // check if same object
   if (this == &rhs) {
      return false;
   }

   // Use dynamic casting to cast down to ComicBook, check for nullptr.
   const ComicBook* item = dynamic_cast<const ComicBook*>(&rhs);
   if (item == nullptr) {
      cerr << "Right hand side object is not a ComicBook object" << endl;
      return false;
   }
   else {
      // Use the sorting order of publisher, title, year and grade.
      if (publisher != item->publisher) {
         return publisher < item->publisher;
      }
      else if (title != item->title) {
         return title < item->title;
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
 * Compares two ComicBook objects.
 * @pre     A ComicBook object to compare to.
 * @post    Returns true if lhs == rhs, false other wise. Player, year,
 *          manufacturer and grade all must be equal.
 * @param   const Hashable& rhs
*/
bool ComicBook::operator==(const Hashable& rhs) const {
   // check if same object
   if (this == &rhs) {
      return true;
   }

   // Use dynamic casting to cast down to ComicBook, check for nullptr.
   const ComicBook* item = dynamic_cast<const ComicBook*>(&rhs);
   if (item == nullptr) {
      cerr << "Right hand side object is not a ComicBook object" << endl;
      return false;
   }
   else {
      // Use the sorting order of publisher, title, year and grade.
      return (publisher == item->publisher) && (title == item->title) &&
         (getYear() == item->getYear()) && (grade == item->grade);
   }
}
