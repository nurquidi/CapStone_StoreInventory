/*
 * @file Hashable.h
 * Interface class. All derived classes will need to implement the pure 
 * virtual method.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * Hashable Interface Class:
 * Super class for all the users and items for the store.
*/

#pragma once
#include <string>

using namespace std;

class Hashable
{
public:
   //------------------------------Destructor----------------------------------
   /* Virtual destructor.
   * @pre     None.
   * @post    Releases any dynamic memory used.
   */
   virtual ~Hashable() = 0 {};

   //------------------------------getHashCode---------------------------------
   /* Hash code generator
   * @pre     None.
   * @post    Returns the hash code for the Hashable object.
   */
   virtual int getHashCode() const = 0;

   //------------------------------toString---------------------------------
   /* Converts data items to a string.
   * @pre     None.
   * @post    Returns a string with the data item contents.
   */
   virtual string toString() const = 0;

   //------------------------------create--------------------------------------
   /* Creates a new object.
   * @pre     None.
   * @post    Returns a pointer to the new object.
   */
   virtual Hashable* create() const = 0;

   //------------------------------clone---------------------------------------
   /* Creates a clone of this object.
   * @pre     None.
   * @post    Returns a pointer to the cloned object.
   */
   virtual Hashable* clone() = 0;

   /**---------------------------operator<-------------------------------------
    * Compares two objects.
    * @pre     A Hashable object to compare to.
    * @post    Returns true if lhs < rhs, false other wise. 
    * @param   const Hashable& rhs
   */
   virtual bool operator<(const Hashable& rhs) const = 0;

   /**---------------------------operator==------------------------------------
    * Compares two objects.
    * @pre     A hashable object to compare to.
    * @post    Returns true if lhs == rhs, false other wise.
    * @param   const Hashable& rhs
   */
   virtual bool operator==(const Hashable& rhs) const = 0;
};
