/*
 * @file User.h
 * Generic user class.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * User Class:
 * Base class for all the users in the system, contains a userID and userName.
 * All methods are virtual so that derived classes can use polymorphism and 
 * override them.
*/

#pragma once
#include "Hashable.h"
#include <string>
#include <iostream>

using namespace std;

class User : public Hashable
{
private:
   int userID; // stores user identifier
   string userName; // stores user name

public:
   //-------------------------Default Constructor------------------------------
   /* Default constructor.
   * @pre     None.
   * @post    Initializes userID to 0 and userName to empty string.
   * @param   int ID
   */
   User() : userID(0), userName() {};

   //------------------------------Constructor---------------------------------
   /* Convenience constructor.
   * @pre     None.
   * @post    Initializes the object with the given ID and name.
   * @param   int ID
   */
   User(const int ID, const string name) : userID(ID), userName(name) {};

   //------------------------------Destructor----------------------------------
   /* Virtual destructor.
   * @pre     None.
   * @post    Releases any dynamic memory used.
   */
   virtual ~User() {}; // No dynamic memory in this class.

   //------------------------------getHashCode---------------------------------
   /* Hash code generator
   * @pre     None.
   * @post    Returns the hash code for the User object.
   */
   virtual int getHashCode() const;

   //------------------------------toString------------------------------------
   /* Creates a string for output.
   * @pre     None.
   * @post    Returns a string with the data item contents. userID is first
   *          followed by a space then userName.
   */
   virtual string toString() const;

   //------------------------------create--------------------------------------
   /* Creates a new object.
   * @pre     None.
   * @post    Returns a pointer to the new object.
   */
   virtual User* create() const;

   //------------------------------clone---------------------------------------
   /* Creates a clone of this object.
   * @pre     None.
   * @post    Returns the cloned object.
   */
   virtual User* clone();

   //------------------------------getID---------------------------------------
   /* Returns the user ID.
   * @pre     None.
   * @post    Returns the user ID.
   */
   virtual int getID() const;

   //------------------------------setID---------------------------------------
   /* Sets the user ID.
   * @pre     None.
   * @post    Sets the user ID.
   * @param   const int ID
   */
   virtual void setID(const int ID);


   //------------------------------getUserName---------------------------------
   /* Returns the user name.
   * @pre     None.
   * @post    Returns the user name as a string.
   */
   virtual string getUserName() const;

   //------------------------------setUserName---------------------------------
   /* Sets the user ID.
   * @pre     None.
   * @post    Sets the user ID.
   * @param   const string name
   */
   virtual void setUserName(const string name);

   /**---------------------------operator<-------------------------------------
    * Compares two objects.
    * @pre     A User object to compare to.
    * @post    Returns true if lhs < rhs, false other wise. Use the std::string
    *          operator< to compare names.
    * @param   const Hashable& rhs
   */
   virtual bool operator<(const Hashable& rhs) const;
      // Use dynamic casting to cast down to User, check for nullptr.

   /**---------------------------operator==------------------------------------
    * Compares two objects.
    * @pre     A User object to compare to.
    * @post    Returns true if lhs == rhs, false other wise. Use the 
    *          std::string operator== to compare names. 
    * @param   const Hashable& rhs
   */
   virtual bool operator==(const Hashable& rhs) const;
      // Use dynamic casting to cast down to User, check for nullptr.
};
