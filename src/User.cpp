/*
 * @file User.cpp
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

#include "User.h"

//------------------------------getHashCode---------------------------------
/* Hash code generator
* @pre     None.
* @post    Returns the hash code for the User object.
*/
int User::getHashCode() const
{
   //Hash code is equal to the 3 digit userID.
   return userID;
}

//------------------------------toString------------------------------------
/* Creates a string for output.
* @pre     None.
* @post    Returns a string with the data item contents. userID is first
*          followed by a space then userName.
*/
string User::toString() const {
   string temp;
   temp = to_string(userID) + " " + userName;
   return temp;
}

//------------------------------create--------------------------------------
/* Creates a new object.
* @pre     None.
* @post    Returns a pointer to the new object.
*/
User* User::create() const {
   return new User; // returns empty object.
}

//------------------------------clone---------------------------------------
/* Creates a clone of this object.
* @pre     None.
* @post    Returns the cloned object.
*/
 User* User::clone() {
    return new User(userID, userName); // returns a clone
}

//------------------------------getID---------------------------------------
/* Returns the user ID.
* @pre     None.
* @post    Returns the user ID.
*/
 int User::getID() const {
    return userID;
}

//------------------------------setID---------------------------------------
/* Sets the user ID.
* @pre     None.
* @post    Sets the user ID.
* @param   const int ID
*/
 void User::setID(const int ID) {
    userID = ID;
}


//------------------------------getUserName---------------------------------
/* Returns the user name.
* @pre     None.
* @post    Returns the user name as a string.
*/
 string User::getUserName() const {
    return userName;
}

//------------------------------setUserName---------------------------------
/* Sets the user ID.
* @pre     None.
* @post    Sets the user ID.
* @param   const string name
*/
 void User::setUserName(const string name) {
    userName = name;
}

/**---------------------------operator<-------------------------------------
 * Compares two objects.
 * @pre     A User object to compare to.
 * @post    Returns true if lhs < rhs, false other wise. Use the std::string
 *          operator< to compare names.
 * @param   const Hashable& rhs
*/
 bool User::operator<(const Hashable& rhs) const {
    // check if same object
    if (this == &rhs) {
       return false;
    }

    // Use dynamic casting to cast down to User, check for nullptr.
    const User* usr = dynamic_cast<const User*>(&rhs);
    if (usr == nullptr) {
       cerr << "Right hand side object is not a User object" << endl;
       return false;
    }
    else {
       return this->userName < usr->userName;
    }
}


/**---------------------------operator==------------------------------------
 * Compares two objects.
 * @pre     A User object to compare to.
 * @post    Returns true if lhs == rhs, false other wise. Use the
 *          std::string operator== to compare names.
 * @param   const Hashable& rhs
*/
 bool User::operator==(const Hashable& rhs) const {
    // check if same object
    if (this == &rhs) {
       return true;
    }

    // Use dynamic casting to cast down to User, check for nullptr.
    const User* usr = dynamic_cast<const User*>(&rhs);
    if (usr == nullptr) {
       cerr << "Right hand side object is not a User object" << endl;
       return false;
    }
    else {
       return this->userName == usr->userName;
    }
}