/*
 * @file Customer.cpp
 * Simple customer class.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * Customer Class:
 * Simple customer class that stores a userID and userName. This class
 * is derived from User.h.
 *
 * The only difference in this class is that it has a customer ID and customer
 * name, which is similar to the user ID and user name from the base class.
 *
 * The only methods required to be overriden are the operator< and operator>.
*/

#include "Customer.h"

//------------------------------Constructor---------------------------------
/* Convenience constructor.
* @pre     Customer ID must be 0 <= customer ID <= 999
* @post    Initializes the object with the given ID.
* @param   const int ID
* @param   const string n
*/
Customer::Customer(const int ID, const string name) {
   // Use the setters to enter this data.
   if (ID >= 0 && ID <= 999) {
      setID(ID);
      setUserName(name);
   }
   else {
      cerr << "Customer ID is out of bounds." << endl;
   }
}

//------------------------------create--------------------------------------
/* Creates a new object.
* @pre     None.
* @post    Returns a pointer to the new object.
*/
Customer* Customer::create() const {
   return new Customer; // return new object.
}

//------------------------------clone---------------------------------------
/* Creates a clone of this object.
* @pre     None.
* @post    Returns a pointer to the cloned object.
*/
Customer* Customer::clone() {
   return new Customer(getID(), getUserName());
}

//------------------------------setID---------------------------------
/* Sets the Customer ID.
* @pre     Customer ID must be 0 <= customer ID <= 999
* @post    Sets the Customer ID.
*/
void Customer::setID(const int ID) {
   if (ID >= 0 && ID <= 999) {
      User::setID(ID);
   }
   else {
      cerr << "Customer ID is out of bounds." << endl;
   }
}

/**---------------------------operator<-------------------------------------
 * Compares two objects.
 * @pre     A Customer object to compare to.
 * @post    Returns true if lhs < rhs, false other wise. Use the std::string
 *          operator< to compare names.
 * @param   const Hashable& rhs
*/
bool Customer::operator<(const Hashable& rhs) const {
   // check if same object
   if (this == &rhs) {
      return false;
   }
   
   // Use dynamic casting to cast down to User, check for nullptr.
   const Customer* custmr = dynamic_cast<const Customer*>(&rhs);
   if (custmr == nullptr) {
      cerr << "Right hand side object is not a Customer object" << endl;
      return false;
   }
   else {
      return this->getUserName() < custmr->getUserName();
   }
}
// Use dynamic casting to cast down to Customer, check for nullptr.

/**---------------------------operator==------------------------------------
 * Compares two objects.
 * @pre     A Customer object to compare to.
 * @post    Returns true if lhs == rhs, false other wise. Use the
 *          std::string operator== to compare names.
 * @param   const Hashable& rhs
*/
bool Customer::operator==(const Hashable& rhs) const {
   // check if same object
   if (this == &rhs) {
      return true;
   }
   
   // Use dynamic casting to cast down to User, check for nullptr.
   const Customer* custmr = dynamic_cast<const Customer*>(&rhs);
   if (custmr == nullptr) {
      cerr << "Right hand side object is not a Customer object" << endl;
      return false;
   }
   else {
      return this->getUserName() == custmr->getUserName();
   }
}
