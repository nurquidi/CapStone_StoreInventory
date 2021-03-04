/*
 * @file Customer.h
 * Simple customer class.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * Customer Class:
 * Simple customer class that stores a userID and userName. This class
 * is derived from User.h.
 * - Customer ID has must be 0 <= customer ID <= 999
 * 
 * The only difference in this class is that it has a customer ID and customer
 * name, which is similar to the user ID and user name from the base class.
 * 
 * The only methods required to be overriden are the create, clone, setID
 * operator< and operator>.
*/
#pragma once
#include "User.h"
#include <string>
#include <iostream>

using namespace std;

class Customer : public User
{
private:
   // Uses the data members of User base class.
public:
   //-------------------------Default Constructor------------------------------
   /* Default constructor.
   * @pre     None.
   * @post    Initializes userID to 0 and userName to empty string.
   * @param   int ID
   */
   Customer() {}; // Nothing to do.

   //------------------------------Constructor---------------------------------
   /* Convenience constructor.
   * @pre     Customer ID must be 0 <= customer ID <= 999
   * @post    Initializes the object with the given ID.
   * @param   const int ID
   * @param   const string name
   */
   Customer(const int ID, const string name);

   //------------------------------Destructor----------------------------------
   /* Virtual destructor.
   * @pre     None.
   * @post    Releases any dynamic memory used.
   */
   ~Customer() {}; // no dynamic memory to use

   //------------------------------create--------------------------------------
   /* Creates a new object.
   * @pre     None.
   * @post    Returns a pointer to the new object.
   */
   Customer* create() const;

   //------------------------------clone---------------------------------------
   /* Creates a clone of this object.
   * @pre     None.
   * @post    Returns a pointer to the cloned object.
   */
   Customer* clone();

   //------------------------------setID---------------------------------
   /* Sets the Customer ID.
   * @pre     Customer ID must be 0 <= customer ID <= 999
   * @post    Sets the Customer ID.
   */
   void setID(const int ID);

   /**---------------------------operator<-------------------------------------
    * Compares two objects.
    * @pre     A Customer object to compare to.
    * @post    Returns true if lhs < rhs, false other wise. Use the std::string
    *          operator< to compare names.
    * @param   const Hashable& rhs
   */
   bool operator<(const Hashable& rhs) const;

   /**---------------------------operator==------------------------------------
    * Compares two objects.
    * @pre     A Customer object to compare to.
    * @post    Returns true if lhs == rhs, false other wise. Use the
    *          std::string operator== to compare names.
    * @param   const Hashable& rhs
   */
   bool operator==(const Hashable& rhs) const;
};
