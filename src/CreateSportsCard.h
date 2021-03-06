/*
 * @file CreateSportsCard.h
 * Command class for creating a SportsCard object.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * CreateSportsCard Class:
 * Takes a string that contains the combined data fields for the object.
 * Initializes the object and returns a pointer to it.
*/

#pragma once
#include "CreateObject.h"
#include "SportsCard.h"
#include <string>
#include <sstream>

using namespace std;

class CreateSportsCard : public CreateObject
{
public:
   //------------------------------Destructor----------------------------------
   /* Virtual destructor.
   * @pre     None.
   * @post    No dynamic data is owned in this class.
   */
   ~CreateSportsCard() {};

   //------------------------------create--------------------------------------
   /* Creates a SportsCard object.
   * @pre     String must be in the correct format.
   *          Format: Year(int), grade(string), player(string), and
   *                  manufacturer(strint)
   *                 - No leading spaces in the string
   *                 - A single comma followed by a space in between
                       data strings.
   *          Example string: "1989, Near Mint, Ken Griffey Jr., Upper Deck"
   * @post    The string is processed and separated into the appropriate types
   *          for initiazling the object. if string is the wrong format an
   *          empty object is returned.
   *          Note, dynamic memory ownership is passed to the calling function.
   */
   SportsCard* create(string objData) const;
};
