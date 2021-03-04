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
   *          for initiazling the object.
   *          Note, dynamic memory ownership is passed to the calling function.
   */
   ComicBook* create(string objData) const;
   /*
   * Can convert string to a streamstring and parse through it.
   * while ( stream objData is not empty) {
   *    Parse through and create the data types needed.
   *    int year, string grade, string title, string publisher
   * }
   *
   * Use the convenience constructor of the ComicBook class to create a
   * new object with the data.
   */
};
