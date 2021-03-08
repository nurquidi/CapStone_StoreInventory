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

#include "CreateComicBook.h"

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
ComicBook* CreateComicBook::create(string objData) const {

   stringstream s(objData); // create a string stream for parsing input.
   string temp; // used when parsing through the data
   int year;
   string grade;
   string title;
   string publisher;

   getline(s, temp, ','); // get year
   year = stoi(temp);
   s.get(); // throw away space
   getline(s, grade, ','); // get grade
   s.get(); // throw away space
   getline(s, title, ','); // get title
   s.get(); // throw away space
   getline(s, publisher); // get publisher

   return new ComicBook(year, title, publisher, grade);
}