/*
 * @file CreateSportsCard.h
 * Command class for creating a Coin object.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * CreateCoin Class:
 * Takes a string that contains the combined data fields for the object.
 * Initializes the object and returns a pointer to it.
*/

#pragma once
#include "CreateObject.h"
#include "Coin.h"
#include <string>
#include <sstream>

using namespace std;

class CreateCoin : public CreateObject
{
public:
   //------------------------------Destructor----------------------------------
   /* Virtual destructor.
   * @pre     None.
   * @post    No dynamic data is owned in this class.
   */
   ~CreateCoin() {};

   //------------------------------create--------------------------------------
   /* Creates a Coin object.
   * @pre     String must be in the correct format.
   *          Format: Year(int), grade(int), type(string)
   *                 - No leading spaces in the string
   *                 - A single comma followed by a space in between
                       data strings.
   *          Example string: "2001, 65, Lincoln Cent"
   * @post    The string is processed and separated into the appropriate types
   *          for initiazling the object.
   *          Note, dynamic memory ownership is passed to the calling function.
   */
   Coin* create(string objData) const;
};