/*
 * @file CreateComicBook.h
 * Command class for creating a ComicBook object.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * CreateComicBook Class:
 * Takes a string that contains the combined data fields for the object.
 * Initializes the object and returns a pointer to it.
*/

#pragma once
#include "CreateObject.h"
#include "ComicBook.h"
#include <string>
#include <sstream>

using namespace std;

class CreateComicBook : public CreateObject
{
public:
   //------------------------------Destructor----------------------------------
   /* Virtual destructor.
   * @pre     None.
   * @post    No dynamic data is owned in this class.
   */
   ~CreateComicBook() {};

   //------------------------------create--------------------------------------
   /* Creates a ComicBook object.
   * @pre     String must be in the correct format.
   *          Format: Year(int), grade(string), title(string), and 
   *                  publisher(string)
   *                 - No leading spaces in the string
   *                 - A single comma followed by a space in between
                       data strings.
   *          Example string: "2010, Excellent, X-Men, Marvel"
   * @post    The string is processed and separated into the appropriate types
   *          for initiazling the object. if string is the wrong format an
   *          empty object is returned.
   *          Note, dynamic memory ownership is passed to the calling function.
   */
   ComicBook* create(string objData) const;
};
