/*
 * @file Main.h
 * Client that handles inventory and customer transactions for a store.
 * @author Nestor Urquidi
 * @date 02/22/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * Main:
 * Instantiates a BranchOperations objects that handles inventory and 
 * customer transactions for a single store branch.
 * More BranchOperations objects may be instiated to represent other branches.
*/


#pragma once
//#include "BranchOperations.h"
#include <iostream>
#include <vector>
using namespace std;

//Testing
#include "ComicBook.h"

int main() {

   //-----------------Test ComicBook Class--------------------------------------
   ComicBook cust; // test default constructor
   cout << "Default constructor: " << cust.toString() << "\n";

   ComicBook cust1(1938, "SuperMan", "DC Comics", "Excellent");
   cout << "Convenience constructor 'DC Comics, SuperMan, 1938, Excellent' : " 
      << cust1.toString() << "\n";

   // Test setters
   cust.setYear(1950);
   cout << "Year 1950: " << cust.toString() << "\n";


   // Test getters
   cout << "Getters: Year(1938): " << cust1.getYear() << "\n";

   // Test getHascode
   cout << "Hashcode: " << cust1.getHashCode() << "\n";

   // Test relational operators
   cout << "\n-------------------Relational Operators-------------\n";
   ComicBook cust2(1913, "Chapulin", "A Huevo", "Muy Bueno");
   cout << cust1.toString() << " < " << cust2.toString() << " : "
      << (cust1 < cust2) << "\n";
   cout << cust1.toString() << " < " << cust1.toString() << " : "
      << (cust1 < cust1) << "\n";

   cout << cust1.toString() << " == " << cust2.toString() << " : "
      << (cust1 == cust2) << "\n";
   cout << cust1.toString() << " == " << cust1.toString() << " : "
      << (cust1 == cust1) << "\n";

   // Test create
   cout << "\n-------------------Create and Clone-------------\n";
   ComicBook* custptr = cust1.create();
   cout << "Should be empty object: " << custptr->toString() << "\n";
   cout << cust1.toString() << "\n";

   ComicBook* custptr2 = cust1.clone();
   cout << "Should be : " << cust1.toString() << " = " <<custptr2->toString() << "\n";

   // Test as a Hashable
   cout << "\n---------------Test as a Hashable pointer---------------------" << "\n";
   Hashable* hashPtr = new ComicBook(350, "Incas", "Nike", "Hella Mint");
   cout << "Setters: Year(350): " << hashPtr->toString() << "\n";
   Hashable* hashPtr2 = cust1.clone();
   cout << "Setters: " << cust1.toString() << " : " << hashPtr2->toString() << "\n";
   // Test getHascode
   cout << "Hashcode: " << cust1.getHashCode() << " = " << 
           hashPtr2->getHashCode() << "\n";

   Hashable* hashPtr3 = hashPtr->clone();
   cout << "Setters: " << hashPtr->toString() << " : " << hashPtr3->toString() << "\n";
   cout << hashPtr->toString() << " < " << hashPtr2->toString() << " : ";
   cout << (*hashPtr < *hashPtr2) << "\n";
   cout << hashPtr->toString() << " == " << hashPtr2->toString() << " : ";
   cout << (*hashPtr == *hashPtr2) << "\n";

   //------------------------------------------------------------------------------
}

//int main() {
//   BranchOperations branchEverett;
//
//   ifstream inventory("Inventory.txt");
//   if (!inventory) {
//      cerr << "File could not be opened." << endl;
//      return 1;
//   }
//   ifstream customers("customers.txt");
//   if (!customers) {
//      cerr << "File could not be opened." << endl;
//      return 1;
//   }
//   ifstream transactions("transactions.txt");
//   if (!transactions) {
//      cerr << "File could not be opened." << endl;
//      return 1;
//   }
//
//   // Load files to branch operations.
//   branchEverett.loadCustomers(customers);
//   branchEverett.loadInventory(inventory);
//   branchEverett.loadTransactions(transactions);
//
//}


//-----------------Test CUSTOMER Class--------------------------------------
//Customer cust1; // test default constructor
//cout << "Default constructor: " << cust1.toString() << "\n";
//
//// Test setters
//cust1.setID(-1); // out of bounds
//cout << "Out of bounds: " << cust1.toString() << "\n";
//cust1.setID(500);
//cust1.setUserName("Gabriel Urquidi");
//cout << "Setters: ID(500), name(Gabriel Urquidi): " << cust1.toString() << "\n";
//
//// Test getters
//cout << "Getters: ID(500), name(Gabriel Urquidi): " << cust1.getID()
//<< " " << cust1.getUserName() << "\n";
//
//// Test getHascode
//cout << "Hashcode: " << cust1.getHashCode() << "\n";
//
//// Test relational operators
//Customer cust2(200, "a");
//cout << cust1.getUserName() << " < " << cust2.getUserName() << " : "
//<< (cust1 < cust2) << "\n";
//cout << cust1.getUserName() << " < " << cust1.getUserName() << " : "
//<< (cust1 < cust1) << "\n";
//
//cout << cust1.getUserName() << " == " << cust2.getUserName() << " : "
//<< (cust1 == cust2) << "\n";
//cout << cust1.getUserName() << " == " << cust1.getUserName() << " : "
//<< (cust1 == cust1) << "\n";
//
//// Test create
//Customer* custptr = cust1.create();
//cout << "Should be empty object: " << custptr->toString() << "\n";
//cout << cust1.toString() << "\n";
//
//Customer* custptr2 = cust1.clone();
//cout << "Should be : " << cust1.toString() << " : " << custptr2->toString() << "\n";
//
//// Test as a Hashable
//cout << "\n---------------Test as a Hashable pointer---------------------" << "\n";
//Hashable* hashPtr = new Customer(350, "hashable");
//cout << "Setters: ID(350), name(hashable): " << hashPtr->toString() << "\n";
//Hashable* hashPtr2 = cust1.clone();
//cout << "Setters: ID(500), name(Gabriel Urquidi): " << hashPtr2->toString() << "\n";
//
//Hashable* hashPtr3 = hashPtr->clone();
//cout << "Setters: ID(350), name(hashable): " << hashPtr3->toString() << "\n";
//cout << hashPtr->toString() << " < " << hashPtr2->toString() << " : ";
//cout << (*hashPtr < *hashPtr2) << "\n";
//cout << hashPtr->toString() << " == " << hashPtr2->toString() << " : ";
//cout << (*hashPtr == *hashPtr2) << "\n";

//------------------------------------------------------------------------------

//-----------------Test Collectible Class--------------------------------------
//Collectible cust1; // test default constructor
//cout << "Default constructor: " << cust1.toString() << "\n";
//
//// Test setters
//cust1.setYear(1950);
//cout << "Year 1950: " << cust1.toString() << "\n";
//
//
//// Test getters
//cout << "Getters: Year(1950): " << cust1.getYear() << "\n";
//
//// Test getHascode
//cout << "Hashcode: " << cust1.getHashCode() << "\n";
//
//// Test relational operators
//cout << "\n-------------------Relational Operators-------------\n";
//Collectible cust2(2000);
//cout << cust1.getYear() << " < " << cust2.getYear() << " : "
//<< (cust1 < cust2) << "\n";
//cout << cust1.getYear() << " < " << cust1.getYear() << " : "
//<< (cust1 < cust1) << "\n";
//
//cout << cust1.getYear() << " == " << cust2.getYear() << " : "
//<< (cust1 == cust2) << "\n";
//cout << cust1.getYear() << " == " << cust1.getYear() << " : "
//<< (cust1 == cust1) << "\n";
//
//// Test create
//cout << "\n-------------------Create and Clone-------------\n";
//Collectible* custptr = cust1.create();
//cout << "Should be empty object: " << custptr->toString() << "\n";
//cout << cust1.toString() << "\n";
//
//Collectible* custptr2 = cust1.clone();
//cout << "Should be : " << cust1.toString() << " = " << custptr2->toString() << "\n";
//
//// Test as a Hashable
//cout << "\n---------------Test as a Hashable pointer---------------------" << "\n";
//Hashable* hashPtr = new Collectible(350);
//cout << "Setters: Year(350): " << hashPtr->toString() << "\n";
//Hashable* hashPtr2 = cust1.clone();
//cout << "Setters: " << cust1.toString() << " : " << hashPtr2->toString() << "\n";
//
//Hashable* hashPtr3 = hashPtr->clone();
//cout << "Setters: " << hashPtr->toString() << " : " << hashPtr3->toString() << "\n";
//cout << hashPtr->toString() << " < " << hashPtr2->toString() << " : ";
//cout << (*hashPtr < *hashPtr2) << "\n";
//cout << hashPtr->toString() << " == " << hashPtr2->toString() << " : ";
//cout << (*hashPtr == *hashPtr2) << "\n";
//
////------------------------------------------------------------------------------

//-----------------Test Coin Class--------------------------------------
//Coin cust; // test default constructor
//cout << "Default constructor: " << cust.toString() << "\n";
//
//Coin cust1(1913, "Lincoln Cent", 65);
//cout << "Convenience constructor '2001 Lincoln Cent 65' : "
//<< cust1.toString() << "\n";
//
//// Test setters
//cust.setYear(1950);
//cout << "Year 1950: " << cust.toString() << "\n";
//
//
//// Test getters
//cout << "Getters: Year(1913): " << cust1.getYear() << "\n";
//
//// Test getHascode
//cout << "Hashcode: " << cust1.getHashCode() << "\n";
//
//// Test relational operators
//cout << "\n-------------------Relational Operators-------------\n";
//Coin cust2(1913, "Lincoln Cent", 70); //Liberty Nickel
//cout << cust1.toString() << " < " << cust2.toString() << " : "
//<< (cust1 < cust2) << "\n";
//cout << cust1.toString() << " < " << cust1.toString() << " : "
//<< (cust1 < cust1) << "\n";
//
//cout << cust1.toString() << " == " << cust2.toString() << " : "
//<< (cust1 == cust2) << "\n";
//cout << cust1.toString() << " == " << cust1.toString() << " : "
//<< (cust1 == cust1) << "\n";
//
//// Test create
//cout << "\n-------------------Create and Clone-------------\n";
//Coin* custptr = cust1.create();
//cout << "Should be empty object: " << custptr->toString() << "\n";
//cout << cust1.toString() << "\n";
//
//Coin* custptr2 = cust1.clone();
//cout << "Should be : " << cust1.toString() << " = " << custptr2->toString() << "\n";
//
//// Test as a Hashable
//cout << "\n---------------Test as a Hashable pointer---------------------" << "\n";
//Hashable* hashPtr = new Coin(350, "Incas", 100);
//cout << "Setters: Year(350): " << hashPtr->toString() << "\n";
//Hashable* hashPtr2 = cust1.clone();
//cout << "Setters: " << cust1.toString() << " : " << hashPtr2->toString() << "\n";
//// Test getHascode
//cout << "Hashcode: " << cust1.getHashCode() << " = " <<
//hashPtr2->getHashCode() << "\n";
//
//Hashable* hashPtr3 = hashPtr->clone();
//cout << "Setters: " << hashPtr->toString() << " : " << hashPtr3->toString() << "\n";
//cout << hashPtr->toString() << " < " << hashPtr2->toString() << " : ";
//cout << (*hashPtr < *hashPtr2) << "\n";
//cout << hashPtr->toString() << " == " << hashPtr2->toString() << " : ";
//cout << (*hashPtr == *hashPtr2) << "\n";

//------------------------------------------------------------------------------

//-----------------Test SportsCard Class--------------------------------------
//SportsCard cust; // test default constructor
//cout << "Default constructor: " << cust.toString() << "\n";
//
//SportsCard cust1(1989, "Cen Griffey Jr.", "Upper Deck", "Near Mint");
//cout << "Convenience constructor 'Ken Griffey Jr 1989 Upper Deck Near Mint' : "
//<< cust1.toString() << "\n";
//
//// Test setters
//cust.setYear(1950);
//cout << "Year 1950: " << cust.toString() << "\n";
//
//
//// Test getters
//cout << "Getters: Year(1989): " << cust1.getYear() << "\n";
//
//// Test getHascode
//cout << "Hashcode: " << cust1.getHashCode() << "\n";
//
//// Test relational operators
//cout << "\n-------------------Relational Operators-------------\n";
//SportsCard cust2(1913, "Christian Ronaldo", "Addidas", "Mint");
//cout << cust1.toString() << " < " << cust2.toString() << " : "
//<< (cust1 < cust2) << "\n";
//cout << cust1.toString() << " < " << cust1.toString() << " : "
//<< (cust1 < cust1) << "\n";
//
//cout << cust1.toString() << " == " << cust2.toString() << " : "
//<< (cust1 == cust2) << "\n";
//cout << cust1.toString() << " == " << cust1.toString() << " : "
//<< (cust1 == cust1) << "\n";
//
//// Test create
//cout << "\n-------------------Create and Clone-------------\n";
//SportsCard* custptr = cust1.create();
//cout << "Should be empty object: " << custptr->toString() << "\n";
//cout << cust1.toString() << "\n";
//
//SportsCard* custptr2 = cust1.clone();
//cout << "Should be : " << cust1.toString() << " = " << custptr2->toString() << "\n";
//
//// Test as a Hashable
//cout << "\n---------------Test as a Hashable pointer---------------------" << "\n";
//Hashable* hashPtr = new SportsCard(350, "Incas", "Nike", "Hella Mint");
//cout << "Setters: Year(350): " << hashPtr->toString() << "\n";
//Hashable* hashPtr2 = cust1.clone();
//cout << "Setters: " << cust1.toString() << " : " << hashPtr2->toString() << "\n";
//// Test getHascode
//cout << "Hashcode: " << cust1.getHashCode() << " = " <<
//hashPtr2->getHashCode() << "\n";
//
//Hashable* hashPtr3 = hashPtr->clone();
//cout << "Setters: " << hashPtr->toString() << " : " << hashPtr3->toString() << "\n";
//cout << hashPtr->toString() << " < " << hashPtr2->toString() << " : ";
//cout << (*hashPtr < *hashPtr2) << "\n";
//cout << hashPtr->toString() << " == " << hashPtr2->toString() << " : ";
//cout << (*hashPtr == *hashPtr2) << "\n";

//------------------------------------------------------------------------------