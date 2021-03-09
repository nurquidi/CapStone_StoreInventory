/*
 * @file SearchTree.h
 * Binary Search Tree class that stores Hashable objects and int count field.
 * @author Nestor Urquidi
 * @date 01/13/2021
 * CSS 502B
 * ----------------------------------------------------------------------------
 * SearchTree class:
 * Uses linked nodes as the data structure. It stores a pointer to a Hashable
 * object and an int counter to keep track of how many times Hashable has
 * been added to the binary search tree.
 * -- Does not store duplicate values, only the count is increased.
 * -- Hashable object is sorted into the tree as it is added.
 * 
 * Input:
 * -- Hashable pointer can be passed into the tree via insert method.
 * -- Copy construct and assignment operator.
 * 
 * Output:
 * -- Overloaded operator >> prints out the frequency table. This table 
 *    includes the Hashable object and its count. Output is in sorted order.
 *    Example:
 *       a 5
 *       b 6
 * 
 * Error Handling:
 * -- Failure of memory allocation for new node is handled via a cerr 
 *    statement.
*/
#pragma once 
#include <iostream>
#include <string>
#include <iomanip>
#include "Hashable.h"

using namespace std;


class SearchTree
{
   /**----------------------------- << ----------------------------------------
    * Overloads the output stream operator to output the SearchTree objects.
    * @pre     SearchTree object to output.
    * @post    Outputs the frequency table in ascending order.  Uses an inorder
    *          traversal of the SearchTree.
    * @param   ostream& outStream
    * @param   SearchTree& treeObj
    * @return  outStream
   */
   friend ostream& operator<<(ostream& outStream, const SearchTree& treeObj);

private:
   //-----------------------------NESTED STRUCT DATANODE-----------------------
   //--------------------------------------------------------------------------
      /** Linked node structure is used for the BST.
       * Nested struct is implemented with an int that holds the count, a 
       * pointer to an object, and two pointers to the left and right children
       * of the DataNode.
      */
   struct DataNode
   {
      Hashable* hashObjPtr;   // Pointer to Hashable object.
      int count;           // Keeps track of number of times hashObjPtr 
                           // is repeated
      DataNode* left;      // Pointer to the left child.
      DataNode* right;     // Pointer to the right child.

      /**----------------------Default Constructor-----------------------------
      * Default constructor. Creates an empty DataNode structure.
      * @pre     None
      * @post    Initializes hashObjPtr = nullptr, count = 0, left = nullptr,
      *          right = nullptr.
      */
      DataNode() : hashObjPtr(nullptr), count(0), left(nullptr), 
                   right(nullptr) {};

      /**-----------------------------Constructor------------------------------
      * Constructor.
      * @pre     None
      * @post    Initializes DataNode structure with the given Hashable object
      *          pointer, sets count = 1, left = nullptr, right = nullptr.
      * @param   Hashable* item
      */
      DataNode(Hashable* const item) : hashObjPtr(item), count(1), 
                                       left(nullptr), right(nullptr) {};
      
      /**-----------------------------Constructor------------------------------
      * Constructor.
      * @pre     None
      * @post    Initializes DataNode structure with the given Hashable object
      *          pointer, sets count = num, left = nullptr, right = nullptr.
      * @param   Hashable* item
      */
      DataNode(Hashable* const item, const int num) : hashObjPtr(item),
               count(num), left(nullptr), right(nullptr) {};
   };


   //-------------------------------------FIELDS-------------------------------
   //--------------------------------------------------------------------------

   DataNode* root;       // Pointer to the root of the SearchTree.


//-----------------------PRIVATE RECURSIVE HELPER METHODS----------------------
//-----------------------------------------------------------------------------

   /**-----------------------------inOrder-------------------------------------
    * Recursive helper method for the overloaded operator <<, this is an
    * in order traversal of the BST.
    * @pre     Pointer to root of tree.
    * @post    Outputs the frequency table in ascending order.  Uses an inorder
    *          traversal of the SearchTree.
    * @param   ostream& outStream
    * @param   DataNode* subTreePtr
    * @return ostream&
   */
   ostream& inOrder(ostream& outStream, const DataNode* const subTreePtr) const;

   /**-----------------------------makeCopy---------------------------------------
    * Recursive helper method for copy constructor.
    * @pre     Root pointer to SearchTree object to copy.
    * @post    Creates an identical copy of the passed object.
    * @param   Hashable* subTreePtr
    * @return  DataNode*
    * @throw   Memory allocation failure for new DataNode or Hashable.
   */
   DataNode* makeCopy(const DataNode* const subTreePtr) const;

   /**-----------------------------destroyTree---------------------------------
    * Recursive helper method.  Uses post-order traversal of the tree, this
    * deletes all the children first before the root.
    * @pre     Pointer to root of tree.
    * @post    Deallocates the memory assigned to each node in the tree.
    * @param   DataNode* subTreePtr
   */
   void destroyTree(DataNode* subTreePtr);

   /**-----------------------------removeNode------------------------------------
    * Private remove node method.
    * @pre     A valid poiner to a DataNode, cannot be a nullptr.
    * @post    Deallocates the memory assigned to the Datanode and Hashable.
    *          Sets left and right children to nullptr. This can cause a memory
    *          leak if not handled correctly for non-leaf node.
    * @param   DataNode* removePtr.
    * @return  Nullptr.
   */
   DataNode* removeNode(DataNode* removePtr);

   /**---------------------------isEqual------------------------------------------
    * Recursive helper method. Check for equality.
    * @pre     Pointers to lhs and rhs objects.
    * @post    Two trees are equal only if they have the same data, the same
    *          structure, and the same number of occurrences for each Hashable
    * @param   DataNode* lhs
    * @param   DataNode* rhs
    * @return  Returns true if both objects are equal, false otherwise
   */
   bool isEqual(const DataNode* const lhs, const DataNode* const rhs) const;

   /**--------------------------- insertRecursive------------------------------
    * Inserts the given Hashable to the tree.
    * @pre     Pointer to root and a pointer to Hashable to insert.
    * @post    Inserts a Hashable into the SearchTree and sets
    *          counter to 1, or increments the count if it is already in
    *          in the tree. If insert returns false, memory deallocation of
    *          Hashable is the responsibility of the calling method.
    * @param   DataNode* subTreePtr
    * @param   Hashable* item
    * @param   bool& success
    * @throw   Memorey allocation failure for new node.
    * @return  True if Hashable was inserted, false if only count was
    *          increased.
   */
   DataNode* insertRecursive(DataNode* subTreePtr, Hashable* item,
      bool& success);

   /**--------------------------- insertRecursive------------------------------
    * Inserts the given Hashable to the tree.
    * @pre     Pointer to root and a pointer to Hashable to insert.
    * @post    Inserts a Hashable into the SearchTree and sets
    *          counter to count, or overrides the count if it is already in
    *          in the tree.
    *          Memory management: The passed object is destroyed if it already
    *                             exists in the list and is set to nullptr.
    * @param   DataNode* subTreePtr
    * @param   Hashable* item
    * @param   bool& success
    * @param   const int num
    * @throw   Memorey allocation failure for new node.
    * @return  True if Hashable was inserted, false if only count was
    *          increased.
   */
   DataNode* insertRecursive(DataNode* subTreePtr, Hashable* item, 
                             const int num, bool& success);

   /**--------------------------removeHelper--------------------------------------
    * Remove recursive helper.
    * @pre     Pointer to root and Hashable to remove.
    * @post    Removes one occurrence of a Hashable from the tree.
    *          If it is the last occurrence, removes the node.
    * @param   DataNode* subTreePtr
    * @param   Hashable& item
    * @param   bool& success
    * @return  False if the Hashable is not found, true otherwise.
   */
   DataNode* removeHelper(DataNode* subTreePtr, const Hashable& item,
      bool& success);

   /**--------------------------getMin-----------------------------------------
    * Returns the minimum value of the subtree (i.e. next in-order value).
    * @pre    Pointer to sub-tree root.
    * @post   Returns the most left value of the sub-tree (minimum value)
    * @return Pointer to minimum value. This DataNode is either a leaf or
    *         only has right child.
   */
   DataNode* getMin(DataNode* const subTreePtr);

   /**-------------------------getPointer----------------------------------------
    * Private helper method that returns pointer to DataNode that contains the
    * Hashable object that it is searched for.
    * @pre    Pointer to root and Hashable to search for.
    * @post   Returns pointer to DataNode that contains the Hashable.
    * @param  DataNode subTreePtr
    * @param  Hashable& item
    * @return If found returns pointer to DataNode, returns nullptr otherwise.
   */
   DataNode* getPointer(DataNode* const subTreePtr,
      const Hashable& item);

   /**--------------------------depthRecursive------------------------------------
    * Finds the depth of the node that stores the Hashable.
    * @pre     Pointer to the root of the tree
    * @post    Returns the depth of the node storing the Hashable in the Tree.
    * @param   DataNode* subTreePtr
    * @param   Hashable& item
    * @param   int depthCounter
    * @return  The root has depth 0. Return -1 if the Hashable is not found.
   */
   int depthRecursive(const DataNode* const subTreePtr,
      const Hashable& item, int depthCounter) const;


   /**-------------------------numHashablesRecursive----------------------------
    * Returns the number of Hashables in the tree. Uses pre-order traversal.
    * @pre     Pointer to root or sub-tree root.
    * @post    Returns the number of unique Hashables contained in the tree.
    *          If subtree root pointer is provided it only returns the number
    *          of Hashables in the subtree.
    * @param   DataNode* subTreePtr
    * @return  Integer total of number of unique Hashables in the tree.
   */
   int numHashablesRecursive(const DataNode* const subTreePtr) const;

   //------------------------END OF RECURSIVE HELPER METHODS----------------------

public:
   /**-----------------------------Constructor---------------------------------
    * Default constructor.
    * @pre     None
    * @post    Initializes an empty SearchTree object.  Sets root to nullptr.
   */
   SearchTree() : root(nullptr) {};

   /**-----------------------------Copy Constructor-------------------------------
    * Copy constructor.
    * @pre     None
    * @post    Creates a deep copy from the passed object.
    * @param   SearchTree object
   */
   SearchTree(const SearchTree& obj);

   /**-----------------------------Destructor----------------------------------
    * Destructor.  Uses post-order traversal of the tree, this deletes all
    * the children first before the root.
    * @pre     A non-empty SearchTree.
    * @post    Deallocates the memory assigned to each node in the tree.
   */
   ~SearchTree();

   /**---------------------------    =    -------------------------------------
   * Assignment operator.
   * @pre     A SearchTree object to copy.
   * @post    *this (left hand side) is assigned same values as right hand side
   * @param   SearchTree& object
   * @return  *this
   */
   SearchTree& operator=(const SearchTree& rightHandSide);

   /**---------------------------    ==    ------------------------------------
   * Equality operator.
   * @pre     A lhs and rhs SearchTree objects to compare.
   * @post    Two trees are equal only if they have the same data, the same
   *          structure, and the same number of occurrences for each Hashable
   * @param   SearchTree& object
   * @return  Returns true if both objects are equal, false otherwise
   */
   bool operator==(const SearchTree& rightHandSide) const;

   /**---------------------------    !=    ------------------------------------
    * Equality operator.
    * @pre     A lhs and rhs SearchTree objects to compare.
    * @post    Returns false if both objects are equal, true otherwise
    * @param   SearchTree& object
    * @return  Returns false if both objects are equal, true otherwise
   */
   bool operator!=(const SearchTree& rightHandSide) const;


   /**--------------------------- insert -----------------------------------------
    * Inserts the given Hashable to the tree.
    * @pre     Pointer to Hashable object to insert.
    * @post    Inserts a Hashable into the SearchTree and sets
    *          counter to 1, or increments the count if it is already in
    *          in the tree.
    *          Memory management: The passed object is destroyed if it already
    *                             exists in the list and is set to nullptr.
    * @param   Hashable* item
    * @throw   Memorey allocation failure for new node.
    * @return  False if Hashable is found in the tree, true otherwise.
   */
   bool insert(Hashable* item);

   /**--------------------------- insert -----------------------------------------
    * Overloaded insert method. Inserts the given Hashable to the tree.
    * @pre     Pointer to Hashable object to insert.
    * @post    Inserts a Hashable into the SearchTree and sets
    *          counter to count, or overrides the count if it is already in
    *          in the tree.
    *          Memory management: The passed object is destroyed if it already
    *                             exists in the list and is set to nullptr.
    * @param   Hashable* item
    * @param   const int count
    * @throw   Memorey allocation failure for new node.
    * @return  False if Hashable is found in the tree, true otherwise.
   */
   bool insert(Hashable* item, const int count);

   /**--------------------------remove-----------------------------------------
    * Removes one occurrence of Hashable from the SearchTree.
    * @pre     Hashable object to remove from the tree.
    * @post    Removes one occurrence of a Hashable from the tree.
    *          If it is the last occurrence, removes the node.
    * @param   Hashable& item
    * @return  False if the Hashable is not found, true otherwise.
   */
   bool remove(const Hashable& item);

   /**--------------------------decreaseCount---------------------------------
   * Decrease the count of the object by 1.
   * @pre     Item must already be in the SearchTree.
   * @post    Decreases quantity of item by 1. Quantity will not be < 0.
   *          Memory management: The passed object is destroyed and set to
   *                             nullptr.
   * @param   const Hashable* ptr
   */
   bool decreaseCount(Hashable* item);

   /**--------------------------increaseCount---------------------------------
   * Increase the count of the object by 1.
   * @pre     Item must already be in the SearchTree.
   * @post    Increases quantity by 1.
   *          Memory management: The passed object is destroyed and set to
   *                             nullptr.
   * @param   const Hashable* ptr
   */
   bool increaseCount(Hashable* item);

   /**--------------------------makeEmpty--------------------------------------
    * Clears tree.
    * @pre    None
    * @post   All nodes are deallocated and tree is reset to empty. Does not
    *         destroy the SearchTree, Hashables may still be inserted.
    */
   void makeEmpty();

   /**-------------------------numHashables----------------------------------
    * Returns the number of Hashables in the tree. Uses pre-order traversal.
    * @pre     None
    * @post    Returns the number of unique Hashables contained in the tree.
    * @return  Integer total of number of unique Hashables in the tree.
   */
   int numHashables() const;

};