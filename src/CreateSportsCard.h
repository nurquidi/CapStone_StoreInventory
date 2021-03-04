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
   *          for initiazling the object.
   *          Note, dynamic memory ownership is passed to the calling function.
   */
   SportsCard* create(string objData) const;
      /* 
      * Can convert string to a streamstring and parse through it.
      * while ( stream objData is not empty) {
      *    Parse through and create the data types needed.
      *    int year, string grade, string player and string manufacturer
      * }
      * 
      * Use the convenience constructor of the SportsCard class to create a
      * new object with the data.
      */
};
