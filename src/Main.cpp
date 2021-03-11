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
// --------------------Memory Leak---------------------------------------------
// Add this block to the top of your Driver
#define _CRTDBG_MAP_ALLOC
#include <cstdlib>  // Detects leaks for dynamic memory
#include <stdlib.h>   // For memory leaks using standard CRT malloc
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif
//------------------------End Memory Leak block--------------------------------

//#include "BranchOperations.h"
#include <iostream>
#include <vector>
using namespace std;

//Testing
#include "UserManager.h"
#include "Coin.h"
#include "SportsCard.h"
#include "ComicBook.h"

int main() {
   //-------------------------Memory Leak Code---------------------------------
// Memory leak check, forces a memory leak report
   _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
   _CrtMemState s1;  // Creates a memory state for taking snapshot.
   //_CrtSetBreakAlloc(18); // Sets breakpoint to memory allocation number "18"
                            // Change "18" to match your case
   //--------------------------End Memory Leak code----------------------------
   {


      //-------------------------Test UserManager ----------------------------
      UserManager userInventory;
      userInventory.displayAll();  // test empty list


      Hashable* ptrCoin = new Coin(1913, "Liberty Nickel", 70);
      Hashable* ptrSports = new SportsCard(1952, "Mickey Mantle", "Topps", "Very Good");
      Hashable* ptrComic = new ComicBook(2010, "X-Men", "Marvel", "Excellent");

      Hashable* ptrCoin3 = ptrCoin->clone();
      Hashable* ptrSports1 = ptrSports->clone();
      Hashable* ptrComic1 = ptrComic->clone();

      Hashable* ptrSports2 = ptrSports->clone();
      Hashable* ptrSports3 = ptrSports->clone();

      ifstream inFile("hw4customers.txt");
      if (!inFile) {
         cerr << "File could not be opened." << endl;
         return 1;
      }
      userInventory.loadCustomers(inFile);
      userInventory.displayAll();


      cout << "\nAdd Coin and Sports Card \n";
      userInventory.addTransaction(5, "Buy", ptrCoin);  // should output error
      userInventory.addTransaction(1, "Buy", ptrSports);
      userInventory.displayCustomer(999);
      userInventory.displayCustomer(1);


      userInventory.addTransaction(1, "Sell", ptrComic);
      userInventory.addTransaction(1, "Sell", ptrCoin3);
      userInventory.addTransaction(1, "Buy", ptrSports1);
      userInventory.addTransaction(456,"Sell", ptrComic1);
      userInventory.addTransaction(456,"Sell", ptrSports2);
      userInventory.addTransaction(1,"Sell", ptrSports3);
      
      userInventory.displayCustomer(1);
      userInventory.displayCustomer(456);
      userInventory.displayCustomer(999);

      cout << "\nDisplay All Transaction:\n";
      userInventory.displayAll();
      //----------------------------------------------------------------------



   }
   //-------------------------Memory Leak Code---------------------------------
   _CrtMemCheckpoint(&s1); // Takes snapshot of memory state
   _CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG | _CRTDBG_MODE_WNDW);
   _CrtDumpMemoryLeaks();
   _CrtMemDumpStatistics(&s1); // prints outs memory allocation summary

   //--------------------------End Memory Leak code----------------------------

}

//int main() {
   //BranchOperations branchEverett;

   //ifstream inventory("Inventory.txt");
   //if (!inventory) {
   //   cerr << "File could not be opened." << endl;
   //   return 1;
   //}
   //ifstream customers("customers.txt");
   //if (!customers) {
   //   cerr << "File could not be opened." << endl;
   //   return 1;
   //}
   //ifstream transactions("transactions.txt");
   //if (!transactions) {
   //   cerr << "File could not be opened." << endl;
   //   return 1;
   //}

   //// Load files to branch operations.
   //branchEverett.loadCustomers(customers);
   //branchEverett.loadInventory(inventory);
   //branchEverett.loadTransactions(transactions);
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

//-----------------Test ComicBook Class--------------------------------------
//ComicBook cust; // test default constructor
//cout << "Default constructor: " << cust.toString() << "\n";
//
//ComicBook cust1(1938, "SuperMan", "DC Comics", "Excellent");
//cout << "Convenience constructor 'DC Comics, SuperMan, 1938, Excellent' : "
//<< cust1.toString() << "\n";
//
//// Test setters
//cust.setYear(1950);
//cout << "Year 1950: " << cust.toString() << "\n";
//
//
//// Test getters
//cout << "Getters: Year(1938): " << cust1.getYear() << "\n";
//
//// Test getHascode
//cout << "Hashcode: " << cust1.getHashCode() << "\n";
//
//// Test relational operators
//cout << "\n-------------------Relational Operators-------------\n";
//ComicBook cust2(1913, "Chapulin", "A Huevo", "Muy Bueno");
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
//ComicBook* custptr = cust1.create();
//cout << "Should be empty object: " << custptr->toString() << "\n";
//cout << cust1.toString() << "\n";
//
//ComicBook* custptr2 = cust1.clone();
//cout << "Should be : " << cust1.toString() << " = " << custptr2->toString() << "\n";
//
//// Test as a Hashable
//cout << "\n---------------Test as a Hashable pointer---------------------" << "\n";
//Hashable* hashPtr = new ComicBook(350, "Incas", "Nike", "Hella Mint");
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

//-----------------Test CreateSportsCard Class--------------------------------------
//CreateComicBook cust; // test default constructor
//string s("2010, Excellent, X-Men, Marvel");
//ComicBook* card = cust.create(s); // create sports card
//cout << "Input: 2010, Excellent, X-Men, Marvel : "
//<< card->toString() << "\n";
//
//// Erroneous input
//string s1("2010, Excellent, Marvel");
//ComicBook* card1 = cust.create(s1); // create sports card
//cout << "Input: 2010, Excellent,  , Marvel : "
//<< card1->toString() << "\n";
//
//delete card;
//delete card1;

//------------------------------------------------------------------------------

//-----------------Test CreateCoin Class--------------------------------------
//CreateCoin cust; // test default constructor
//string s("1913, 70, Liberty Nickel");
//Coin* card = cust.create(s); // create sports card
//cout << "Input: 1913, 70, Liberty Nickel : "
//<< card->toString() << "\n";
//
//// Erroneous input
//string s1("2001, 600, ");
//Coin* card1 = cust.create(s1); // create sports card
//cout << "Input: 2001, 600,  : "
//<< card1->toString() << "\n";
//
//delete card;
//delete card1;

//------------------------------------------------------------------------------

//-----------------Test CreateCustomer Class--------------------------------------
//CreateCustomer cust; // test default constructor
//string s("191, Young Jeezy");
//Customer* card = cust.create(s); // create sports card
//cout << "Input: 191, Young Jeezy : "
//<< card->toString() << "\n";
//
//// Erroneous input
//string s1("2001, la di la");
//Customer* card1 = cust.create(s1); // create sports card
//cout << "Input: 2001, la di la : "
//<< card1->toString() << "\n";
//
//delete card;
//delete card1;
//------------------------------------------------------------------------------

//-------------------------TEST FactoryHashable-----------------------------
//   // Create factory
//FactoryHashable factory;
//
//// --------------CreateCustomer-----------------------
//cout << "Create Customer\n";
//string s("191, Young Jeezy");
//Hashable* card = factory.createIt('A', s); // create customer
//cout << "Input: 191, Young Jeezy : "
//<< card->toString() << "\n";
//
//// Erroneous input
//string s1("2001, la di la");
//Hashable* card1 = factory.createIt('A', s1); // create customer
//cout << "Input: 2001, la di la : "
//<< card1->toString() << "\n";
//
//delete card;
//delete card1;
//// ----------------------------------------------------
//
//// --------------CreateComicBook-----------------------
//cout << "\nCreate ComicBook\n";
//string s2("1938, Mint, Superman, DC ");
//card = factory.createIt('C', s2); // create comicbook
//cout << "Input: 1938, Mint, Superman, DC  : "
//<< card->toString() << "\n";
//
//// Erroneous input
//string s3("1938, Mint, Superman");
//card1 = factory.createIt('C', s3); // create comicbook
//cout << "Input: 1938, Mint, Superman : "
//<< card1->toString() << "\n";
//
//delete card;
//delete card1;
//
////----Create SportsCard
//cout << "\nCreate SportsCard\n";
//string s4("1989, Near Mint, Ken Griffey Jr., Upper Deck");
//card = factory.createIt('S', s4); // create sports card
//cout << "Input: 2010, Excellent, X-Men, Marvel : "
//<< card->toString() << "\n";
//
//// Erroneous input
//string s5("1952, Very Good, Mickey Mantle,");
//card1 = factory.createIt('S', s5); // create sports card
//cout << "Input: 2010, Excellent,  , Marvel : "
//<< card1->toString() << "\n";
//
//delete card;
//delete card1;
//
////-----------------Create Coin-----------------
//cout << "\nCreate Coin\n";
//string s6("1913, 70, Liberty Nickel");
//card = factory.createIt('M', s6); // create Coin
//cout << "Input: 1913, 70, Liberty Nickel : "
//<< card->toString() << "\n";
//
//// Erroneous input
//string s7("2001, 600, ");
//card1 = factory.createIt('M', s7); // create Coin
//cout << "Input: 2001, 600,  : "
//<< card1->toString() << "\n";
//
//delete card;
//delete card1;
//------------------------------------------------------------------------------

//-------------------------Test Search Tree----------------------------
//SearchTree tree;
//cout << "Empty tree : " << tree << "\n";
//Coin* coin1 = new Coin(1913, "Lincoln Cent", 65); // create coin
//Coin* coin2 = new Coin(1913, "Liberty Nickel", 70);
//Coin* coin3 = new Coin(2000, "Gabriel Quarter", 100); // create coin
//Coin* coin4 = new Coin(1950, "Clara Nickel", 70);
//Coin* coin5 = new Coin(2006, "Mommy cent", 99); // create coin
//Coin* coin6 = new Coin(2019, "Nestor Dime", 5);
//
//tree.insert(coin1);
//cout << "1913 Lincoln Cent 65 : " << tree << "\n";
//tree.insert(coin2);  tree.insert(coin3); tree.insert(coin4);
//tree.insert(coin5); tree.insert(coin6);
//cout << " 6 coins: \n" << tree << "\n";
//
//Coin* coin7 = new Coin(2006, "Mommy cent", 60); // create coin
//Coin* coin8 = new Coin(2019, "Nestor Dime", 80);
//tree.insert(coin7);    tree.insert(coin8);
//cout << " 8 coins: \n" << tree << "\n";
//
//cout << "Increment count of existing Coins\n";
//Coin* temp = coin1->clone();
//tree.insert(temp, 50);
//temp = coin2->clone();
//tree.insert(temp);
//cout << " 8 coins: \n" << tree << "\n";
//
//cout << "Decrement count of existing Coins\n";
//temp = coin4->clone();
//tree.decreaseCount(temp);
//temp = coin1->clone();
//tree.decreaseCount(temp);
//cout << " 8 coins: \n" << tree << "\n";
//
//cout << "Decrement count of existing Coins. Clara Nickel should not be < 0\n";
//temp = coin4->clone();
//tree.decreaseCount(temp);
//temp = coin1->clone();
//tree.decreaseCount(temp);
//cout << " 8 coins: \n" << tree << "\n";
//----------------------------------------------------------------------

//-------------------------Test InventoryMgr ----------------------------
//InventoryMgr inventory;
//inventory.displayAll();
//
//Hashable* ptrCoinT = new Coin(1913, "Liberty Nickel", 70);
//Hashable* ptrCoinT1 = ptrCoinT->clone();
//cout << "Try buying and selling from empty inventory : \n";
//inventory.buyItem('M', ptrCoinT);
//inventory.sellItem('M', ptrCoinT1);
//cout << "End of buying and selling from empty inventory : \n";
//
//ifstream inFile("hw4inventory.txt");
//if (!inFile) {
//   cerr << "File could not be opened." << endl;
//   return 1;
//}
//inventory.loadInventory(inFile);
//inventory.displayAll();
//
//cout << "\nTest buying an item \n";
//
//Hashable* ptrCoin = new Coin(1913, "Liberty Nickel", 70);
//Hashable* ptrSports = new SportsCard(1952, "Mickey Mantle", "Topps", "Very Good");
//Hashable* ptrComic = new ComicBook(2010, "X-Men", "Marvel", "Excellent");
//Hashable* ptrCoin2 = ptrCoin->create(); // empty coin
//
//Hashable* ptrCoin3 = ptrCoin->clone();
//Hashable* ptrSports1 = ptrSports->clone();
//Hashable* ptrComic1 = ptrComic->clone();
//
//Hashable* ptrSports2 = ptrSports->clone();
//Hashable* ptrSports3 = ptrSports->clone();
//
//cout << "\nBuy with empty coin object:\n";
//inventory.buyItem('M', ptrCoin2);
//inventory.displayAll();
//
//cout << "\nComic : " << ptrComic->toString() << "\n";
//cout << "\nCoin : " << ptrCoin->toString() << "\n";
//cout << "\Sports Card : " << ptrSports->toString() << "\n";
//cout << "\nBuy a coin, sports card and comic book\n";
//inventory.buyItem('M', ptrCoin);
//inventory.buyItem('C', ptrComic);
//inventory.buyItem('S', ptrSports);
//inventory.displayAll();
//
//cout << "\nSell a coin, sports card and comic book\n";
//inventory.sellItem('M', ptrCoin3);
//inventory.sellItem('C', ptrComic1);
//inventory.sellItem('S', ptrSports1);
//inventory.displayAll();
//
//cout << "\nSell a sports card, should be quantity 0 after sell.\n";
//inventory.sellItem('S', ptrSports2);
//inventory.displayAll();
//cout << "\nSell a sports card, should not drop below 0 after sell.\n";
//inventory.sellItem('S', ptrSports3);
//inventory.displayAll();

//----------------------------------------------------------------------

//-------------------------Test TransactionList ----------------------------
//TransactionList transaction;
//transaction.print();  // test empty list
//cout << "Empty List = 0 : " << transaction.getCurrentSize();
//cout << "\nTest if empty = 1 (true) : " << transaction.isEmpty();
//
//Hashable* ptrCoin = new Coin(1913, "Liberty Nickel", 70);
//Hashable* ptrSports = new SportsCard(1952, "Mickey Mantle", "Topps", "Very Good");
//Hashable* ptrComic = new ComicBook(2010, "X-Men", "Marvel", "Excellent");
//Hashable* ptrCoin2 = ptrCoin->create(); // empty coin
//
//Hashable* ptrCoin3 = ptrCoin->clone();
//Hashable* ptrSports1 = ptrSports->clone();
//Hashable* ptrComic1 = ptrComic->clone();
//
//Hashable* ptrSports2 = ptrSports->clone();
//Hashable* ptrSports3 = ptrSports->clone();
//
//cout << "\nAdd Coin and Sports Card \n";
//transaction.add("Buy", ptrCoin);
//transaction.add("Buy", ptrSports);
//transaction.print();
//cout << "list size = 2 : " << transaction.getCurrentSize() << "\n";
//cout << "\nTest isEmpty() should return false (0) : "
//<< transaction.isEmpty() << "\n";
//
//transaction.add("Sell", ptrComic);
//transaction.add("Buy", ptrCoin2);
//transaction.add("Sell", ptrCoin3);
//transaction.add("Buy", ptrSports1);
//transaction.add("Sell", ptrComic1);
//transaction.add("Sell", ptrSports2);
//transaction.add("Sell", ptrSports3);
//transaction.print();
//----------------------------------------------------------------------

//-------------------------Test UserManager ----------------------------
//UserManager userInventory;
//userInventory.displayAll();  // test empty list
//
//
//Hashable* ptrCoin = new Coin(1913, "Liberty Nickel", 70);
//Hashable* ptrSports = new SportsCard(1952, "Mickey Mantle", "Topps", "Very Good");
//Hashable* ptrComic = new ComicBook(2010, "X-Men", "Marvel", "Excellent");
//
//Hashable* ptrCoin3 = ptrCoin->clone();
//Hashable* ptrSports1 = ptrSports->clone();
//Hashable* ptrComic1 = ptrComic->clone();
//
//Hashable* ptrSports2 = ptrSports->clone();
//Hashable* ptrSports3 = ptrSports->clone();
//
//ifstream inFile("hw4customers.txt");
//if (!inFile) {
//   cerr << "File could not be opened." << endl;
//   return 1;
//}
//userInventory.loadCustomers(inFile);
//userInventory.displayAll();
//
//
//cout << "\nAdd Coin and Sports Card \n";
//userInventory.addTransaction(5, "Buy", ptrCoin);  // should output error
//userInventory.addTransaction(1, "Buy", ptrSports);
//userInventory.displayCustomer(999);
//userInventory.displayCustomer(1);
//
//
//userInventory.addTransaction(1, "Sell", ptrComic);
//userInventory.addTransaction(1, "Sell", ptrCoin3);
//userInventory.addTransaction(1, "Buy", ptrSports1);
//userInventory.addTransaction(456, "Sell", ptrComic1);
//userInventory.addTransaction(456, "Sell", ptrSports2);
//userInventory.addTransaction(1, "Sell", ptrSports3);
//
//userInventory.displayCustomer(1);
//userInventory.displayCustomer(456);
//userInventory.displayCustomer(999);
//
//cout << "\nDisplay All Transaction:\n";
//userInventory.displayAll();
//----------------------------------------------------------------------