/*
 * @file CreateObject.h
 * Interface class for creating objects. All derived classes will need to 
 * implement the pure virtual method.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * CreateObject Interface Class:
 * A command interface class for creating objects.
*/
#pragma once
#include "Hashable.h"
#include <string>

using namespace std;

class CreateObject
{
public:
   //------------------------------Destructor----------------------------------
   /* Virtual destructor.
   * @pre     None.
   * @post    Releases any dynamic memory used.
   */
   virtual ~CreateObject() = 0 {};

   //------------------------------create--------------------------------------
   /* Creates an object.
   * @pre     String must be in the correct format.
   * @post    Returns the pointer of the newly created object.
   */
   virtual Hashable* create(string objData) const = 0;
};