/*
 * @file SearchTree.cpp
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
 * -- Overloaded operator >> prints out the frequency table. This table includes
 *    the Hashable object and its count. Output is in sorted order.
 *    Example:
 *       a 5
 *       b 6
 *
 * Error Handling:
 * -- Failure of memory allocation for new node is handled via a cerr statement.
*/


#include "SearchTree.h"


/**----------------------------- << ----------------------------------------
 * Overloads the output stream operator to output the SearchTree objects.
 * @pre     SearchTree object to output.
 * @post    Outputs the frequency table in ascending order.  Uses an inorder
 *          traversal of the SearchTree
 * @param   ostream& outStream
 * @param   SearchTree& treeObj
 * @return  outStream
*/
ostream& operator<<(ostream& outStream, const SearchTree& treeObj)
{
   return treeObj.inOrder(outStream, treeObj.root);
}

/**-----------------------------inOrder----------------------------------------
 * Recursive helper method for the overloaded operator <<, this is an
 * in order traversal of the BST.
 * @pre     Pointer to root of tree.
 * @post    Outputs the frequency table in ascending order.  Uses an inorder
 *          traversal of the SearchTree.
 * @param   ostream& outStream
 * @param   DataNode* subTreePtr
 * @return ostream&
*/
ostream& SearchTree::inOrder(ostream& outStream,
   const SearchTree::DataNode* const subTreePtr) const
{
   // Use in-order traversal to print out in ascending order.
   // base case: subTreePtr == nullptr
   if (subTreePtr != nullptr) { // If tree not empty.
      inOrder(outStream, subTreePtr->left); // go down the left of the tree
      outStream << subTreePtr->hashObjPtr->toString() << ": Quantity = " 
                << subTreePtr->count << "\n";
      inOrder(outStream, subTreePtr->right); // go down the right of the tree
   }
   return outStream;
}


/**-----------------------------Copy Constructor-------------------------------
 * Copy constructor.
 * @pre     None
 * @post    Creates an identical copy of the passed object.
 * @param   SearchTree object
*/
SearchTree::SearchTree(const SearchTree& obj)
{
   // Use recursive helper method to make exact copy of tree.
   root = makeCopy(obj.root);
}

/**-----------------------------makeCopy---------------------------------------
 * Recursive helper method for copy constructor.
 * @pre     Root pointer to SearchTree object to copy.
 * @post    Creates an identical copy of the passed object.
 * @param   Hashable* subTreePtr
 * @return  DataNode*
 * @throw   Memory allocation failure for new DataNode or Hashable.
*/
SearchTree::DataNode* SearchTree::makeCopy(
   const SearchTree::DataNode* const subTreePtr) const
{
   // Use pre-order method to copy each DataNode as soon as it is reached.

   // Base case: subTreePtr = nullptr
   if (subTreePtr == nullptr) {
      return nullptr;
   }
   else { // Keep traversing tree using pre-order
      // Clone the hashable object
      Hashable* compTemp = subTreePtr->hashObjPtr->clone();

      DataNode* newPtr = new DataNode(compTemp); // copy node
      newPtr->count = subTreePtr->count; // copy count;

      newPtr->left = makeCopy(subTreePtr->left);   // go down the left tree
      newPtr->right = makeCopy(subTreePtr->right); // go down the right tree
      return newPtr;

   }
}

/**-----------------------------Destructor----------------------------------
 * Destructor.  Uses post-order traversal of the tree, this deletes all
 * the children first before the root.
 * @pre     None
 * @post    Deallocates the memory assigned to each node in the tree
*/
SearchTree::~SearchTree()
{
   destroyTree(root); // deallocates memory
}

/**-----------------------------destroyTree------------------------------------
 * Recursive helper method.  Uses post-order traversal of the tree, this
 * deletes all the children first before the root.
 * @pre     Pointer to root of tree.
 * @post    Deallocates the memory assigned to each node in the tree.
 * @param   DataNode* subTreePtr
*/
void SearchTree::destroyTree(SearchTree::DataNode* subTreePtr)
{
   // Base case is root = nullptr
   if (subTreePtr != nullptr) { // if tree not empty.

      destroyTree(subTreePtr->left); // go down the left tree
      destroyTree(subTreePtr->right); // go down the right tree

      //Delete data and release memory.
      subTreePtr = removeNode(subTreePtr);
   }
}

/**-----------------------------removeNode------------------------------------
 * Private remove node method.
 * @pre     A valid poiner to a DataNode, cannot be a nullptr.
 * @post    Deallocates the memory assigned to the Datanode and Hashable.
 *          Sets left and right children to nullptr. This can cause a memory
 *          leak if not handled correctly for non-leaf node.
 * @param   DataNode* removePtr.
 * @return  Nullptr.
*/
SearchTree::DataNode* SearchTree::removeNode(SearchTree::DataNode* removePtr)
{
   //Delete data and release memory.
   delete removePtr->hashObjPtr; // Deallocates Hashable object memory.
   removePtr->hashObjPtr = nullptr;
   removePtr->right = nullptr;
   removePtr->left = nullptr;
   delete removePtr;
   removePtr = nullptr;
   return removePtr;
}

/**---------------------------    =    ----------------------------------------
* Assignment operator.
* @pre     A SearchTree object to copy.
* @post    *this (left hand side) is assigned same values as right hand side
* @param   SearchTree& object
* @return  *this
*/
SearchTree& SearchTree::operator=(const SearchTree& rightHandSide)
{
   // Check if the two objects are the same objects.
   if (this == &rightHandSide) {
      // this = memory address
      return *this; // return the object
   }
   else {
      // Clear (deallocate memory) of the left hand side tree.
      makeEmpty();
      root = nullptr;

      // Use the makeCopy recursive helper method to create an identical
      // copy of the right hand side object.
      root = makeCopy(rightHandSide.root);
   }
   return *this;
}

/**--------------------------makeEmpty-----------------------------------------
 * Clears tree.
 * @pre    None
 * @post   All nodes are deallocated and tree is reset to empty. Does not
 *         destroy the SearchTree, Hashables may still be inserted.
 */
void SearchTree::makeEmpty()
{
   destroyTree(root); // Deletes all nodes and deallocates memory.
   root = nullptr;
}


/**---------------------------    ==    ---------------------------------------
* Equality operator.
* @pre     A lhs and rhs SearchTree objects to compare.
* @post    Two trees are equal only if they have the same data, the same
*          structure, and the same number of occurrences for each Hashable
* @param   SearchTree& object
* @return  Returns true if both objects are equal, false otherwise
*/
bool SearchTree::operator==(const SearchTree& rightHandSide) const
{
   // Check if both are the same object
   if (this == &rightHandSide) return true;

   // Use recursive helper method to check if equal
   return isEqual(root, rightHandSide.root);
}

/**---------------------------isEqual------------------------------------------
* Recursive helper method. Check for equality.
* @pre     Pointers to lhs and rhs objects.
* @post    Two trees are equal only if they have the same data, the same
*          structure, and the same number of occurrences for each Hashable
* @param   DataNode* lhs
* @param   DataNode* rhs
* @return  Returns true if both objects are equal, false otherwise
*/
bool SearchTree::isEqual(const SearchTree::DataNode* const lhs,
   const SearchTree::DataNode* const rhs) const
{
   // Use a pre-order traversal to check each node
   // Base case: lhs = nullptr or rhs = nullptr
   if (lhs == nullptr && rhs == nullptr) {
      return true; // Empty trees or have reached the end of a branch
   }
   else if ((lhs == nullptr && rhs != nullptr) ||
      (lhs != nullptr && rhs == nullptr)) {
      // One tree branch has ended and the other did not
      return false;
   }
   else if ((*(lhs->hashObjPtr) == *(rhs->hashObjPtr)) &&
      (lhs->count == rhs->count)) {
      // Keep traversing and checking for equality
      return isEqual(lhs->left, rhs->left) && isEqual(lhs->right, rhs->right);
   }
   else {
      return false;
   }
}

/**---------------------------    !=    ---------------------------------------
* Equality operator.
* @pre     A lhs and rhs SearchTree objects to compare.
* @post    Returns false if both objects are equal, true otherwise
* @param   SearchTree& object
* @return  Returns false if both objects are equal, true otherwise
*/
bool SearchTree::operator!=(const SearchTree& rightHandSide) const
{
   // Use the already defined equality operator ==
   return !(*this == rightHandSide);
}

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
bool SearchTree::insert(Hashable* item)
{
   // Use a boolean flag to signal if insertion is true or false
   bool success = false;

   // Use recursive helper method for inserting the Hashable.
   root = insertRecursive(root, item, success);

   return success;
}

/**--------------------------- insertRecursive------------------------------
 * Inserts the given Hashable to the tree.
 * @pre     Pointer to root and a pointer to Hashable to insert.
 * @post    Inserts a Hashable into the SearchTree and sets
 *          counter to 1, or increments the count if it is already in
 *          in the tree.
 *          Memory management: The passed object is destroyed if it already
 *                             exists in the list and is set to nullptr.
 * @param   DataNode* subTreePtr
 * @param   Hashable* item
 * @param   bool& success
 * @throw   Memorey allocation failure for new node.
 * @return  True if Hashable was inserted, false if only count was
 *          increased.
*/
SearchTree::DataNode* SearchTree::insertRecursive(
   SearchTree::DataNode* subTreePtr, Hashable* item, bool& success)
{
   // Base case: subTreePtr ==  nullptr
   if (subTreePtr == nullptr) {
      // Reached last node, add Hashable here.
      // New node initialized with item and counter = 1, left = nullptr and
      // right = nullptr. */
      DataNode* newNode = new (std::nothrow) DataNode(item);
      // std::nothrow returns nullptr if memory allocation failed.
      if (newNode == nullptr) {
         cerr << "New tree node memory allocation failed.";
      }
      success = true; // new item is added to the tree
      return newNode;
   }
   else if (*item == *subTreePtr->hashObjPtr) {
      subTreePtr->count++; // Hashable is in tree already, increase count by 1
      success = false; // No new item added
      delete item; // release memory
      item = nullptr;
      return subTreePtr;
   }
   else if (*item < *subTreePtr->hashObjPtr) {
      // Go down the left tree.
      subTreePtr->left = insertRecursive(subTreePtr->left, item, success);
   }
   else {
      // Go down the right tree
      subTreePtr->right = insertRecursive(subTreePtr->right, item, success);
   }
   return subTreePtr;
}

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
bool SearchTree::insert(Hashable* item, const int count) {
   // Use a boolean flag to signal if insertion is true or false
   bool success = false;

   // Use recursive helper method for inserting the Hashable.
   root = insertRecursive(root, item, count, success);

   return success;
}

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
SearchTree::DataNode* SearchTree::insertRecursive(
                              SearchTree::DataNode* subTreePtr, Hashable* item,
                              const int num ,bool& success)
{
   // Base case: subTreePtr ==  nullptr
   if (subTreePtr == nullptr) {
      // Reached last node, add Hashable here.
      // New node initialized with item and counter = num, left = nullptr and
      // right = nullptr. */
      DataNode* newNode = new (std::nothrow) DataNode(item, num);
      // std::nothrow returns nullptr if memory allocation failed.
      if (newNode == nullptr) {
         cerr << "New tree node memory allocation failed.";
      }
      success = true; // new item is added to the tree
      return newNode;
   }
   else if (*item == *subTreePtr->hashObjPtr) {
      subTreePtr->count = num; // Hashable is in tree already, override count
      success = false; // No new item added
      delete item; // release memory
      item = nullptr;
      return subTreePtr;
   }
   else if (*item < *subTreePtr->hashObjPtr) {
      // Go down the left tree.
      subTreePtr->left = insertRecursive(subTreePtr->left, item, num, success);
   }
   else {
      // Go down the right tree
      subTreePtr->right = insertRecursive(subTreePtr->right, item, num, success);
   }
   return subTreePtr;
}
/**--------------------------remove--------------------------------------------
 * Removes one occurrence of Hashable from the SearchTree.
 * @pre     Hashable object to remove from the tree.
 * @post    Removes one occurrence of a Hashable from the tree.
 *          If it is the last occurrence, removes the node.
 * @param   Hashable& item
 * @return  False if the Hashable is not found, true otherwise.
*/
bool SearchTree::remove(const Hashable& item)
{
   // Use a boolean flag to signal if insertion is true or false
   bool success = false;
   root = removeHelper(root, item, success);
   return success;
}

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
SearchTree::DataNode* SearchTree::removeHelper(SearchTree::DataNode* subTreePtr,
   const Hashable& item, bool& success)
{
   // Base case: nullptr
   if (subTreePtr == nullptr) {
      success = false; // item not found
      return subTreePtr; // returns the nullptr
   }
   else if (*subTreePtr->hashObjPtr == item) {
      // Item found, need to remove it.
      success = true;  // set removal to true

      // CASE 1:---------------------------------------------------------------
      // Only lower the count of Hashable.
      if (subTreePtr->count > 1) {
         // Reduce count only, do not remove the node
         subTreePtr->count--;
         return subTreePtr;
      }

      // CASE 2:---------------------------------------------------------------
      // DataNode is a leaf, remove and return nullptr.
      if (subTreePtr->right == nullptr && subTreePtr->left == nullptr) {
         return removeNode(subTreePtr); // Deallocates memory & returns nullptr
      }

      // CASE 3:---------------------------------------------------------------
      // No right child, replace with left child
      if (subTreePtr->right == nullptr) {
         DataNode* tempReturn = subTreePtr->left; // store left child pointer

         // Deallocate data
         subTreePtr = removeNode(subTreePtr);  // returns nullptr.
         subTreePtr = tempReturn; // relink tree
         return subTreePtr;
      }

      // CASE 4:---------------------------------------------------------------
      // No left child, replace with right child
      if (subTreePtr->left == nullptr) {
         DataNode* tempReturn = subTreePtr->right; // store right child pointer

         // Deallocate data
         subTreePtr = removeNode(subTreePtr);  // returns nullptr.
         subTreePtr = tempReturn;
         return subTreePtr;
      }

      // CASE 5:---------------------------------------------------------------
      // DataNode has two children, replace with in-order successor

      // Get pointer to minimum value from right tree (in-order successor)
      DataNode* minPtr = getMin(subTreePtr->right);

      // Swap data from minPtr with subTreePtr (current node), then
      // remove minPtr.
      *subTreePtr->hashObjPtr = *minPtr->hashObjPtr;
      subTreePtr->count = minPtr->count;
      *minPtr->hashObjPtr = item;
      minPtr->count = 1;

      // Now we can remove minPtr, which is easier to remove vs subTreePtr.
      // Two possibilities for minPtr, it either is a leaf or it has a
      // right child.
      // Continue searching the tree for "item" which is now contained in 
      // minPtr.
      success = false; // since the node has not been removed yet.
      subTreePtr->right = removeHelper(subTreePtr->right, item, success);

   }
   else if (item < *subTreePtr->hashObjPtr) {
      // keep searching, go down the left tree
      subTreePtr->left = removeHelper(subTreePtr->left, item, success);
   }
   else {
      // go down the right
      subTreePtr->right = removeHelper(subTreePtr->right, item, success);
   }
   return subTreePtr;
}

/**--------------------------getMin-----------------------------------------
 * Returns the minimum value of the subtree (i.e. next in-order value).
 * @pre    Pointer to sub-tree root.
 * @post   Returns the most left value of the sub-tree (minimum value)
 * @return Pointer to minimum value. This DataNode is either a leaf or
 *         only has right child.
 */
SearchTree::DataNode* SearchTree::getMin(SearchTree::DataNode* const subTreePtr)
{
   // Check if emptry tree
   if (subTreePtr == nullptr) {
      return subTreePtr;
   }

   // If no left child then return this node
   if (subTreePtr->left == nullptr) {
      return subTreePtr;
   }
   else {
      // go down next left node.
      return getMin(subTreePtr->left);
   }
}

/**--------------------------decreaseCount---------------------------------
* Decrease the count of the object by 1.
* @pre     Item must already be in the SearchTree.
* @post    Decreases quantity of item by 1. Quantity will not be < 0.
*          Memory management: The passed object is destroyed and set to
*                             nullptr.
* @param   const Hashable* ptr
*/
bool SearchTree::decreaseCount(Hashable* item) {
   // Get pointer to object in the search tree
   DataNode* temp = getPointer(root, *item);
   if (temp != nullptr) {
      // Count cannot drop below 0
      if (temp->count > 0) {
         temp->count--;
         delete item; // release memory
         item = nullptr;
         return true;
      }
   }
   delete item; // release memory
   item = nullptr;
   return false;
}

/**-------------------------getPointer----------------------------------------
 * Private helper method that returns pointer to DataNode that contains the
 * Hashable object that it is searched for.
 * @pre    Pointer to root and Hashable to search for.
 * @post   Returns pointer to DataNode that contains the Hashable.
 * @param  DataNode subTreePtr
 * @param  Hashable& item
 * @return If found returns pointer to DataNode, returns nullptr otherwise.
*/
SearchTree::DataNode* SearchTree::getPointer(
   SearchTree::DataNode* const subTreePtr, const Hashable& item)
{
   if (subTreePtr == nullptr) { // base case
      return subTreePtr; // reached last node and value is not found.
   }
   else if (item == *subTreePtr->hashObjPtr) {
      return subTreePtr; // value was found.
   }
   else if (item < *subTreePtr->hashObjPtr) {
      // If less than then go down the left tree
      return getPointer(subTreePtr->left, item);
   }
   else {
      // Greater than go down the right tree
      return getPointer(subTreePtr->right, item);
   }
}

/**--------------------------increaseCount---------------------------------
* Increase the count of the object by 1.
* @pre     Item must already be in the SearchTree.
* @post    Increases quantity by 1.
*          Memory management: The passed object is destroyed and set to
*                             nullptr.
* @param   const Hashable* ptr
*/
bool SearchTree::increaseCount(Hashable* item) {
   // Get pointer to object in the search tree
   DataNode* temp = getPointer(root, *item);
   if (temp != nullptr) {
      temp->count++;
      delete item; // release memory
      item = nullptr;
      return true;
   }
   delete item; // release memory
   item = nullptr;
   return false;
}

/**-------------------------numHashables-------------------------------------
 * Returns the number of Hashables in the tree. Uses pre-order traversal.
 * @pre     None
 * @post    Returns the number of unique Hashables contained in the tree.
 * @return  Integer total of number of unique Hashables in the tree.
*/
int SearchTree::numHashables() const
{
   /** Use recursive helper method.*/
   return numHashablesRecursive(root);
}

/**-------------------------numHashablesRecursive----------------------------
 * Returns the number of Hashables in the tree. Uses pre-order traversal.
 * @pre     Pointer to root or sub-tree root.
 * @post    Returns the number of unique Hashables contained in the tree.
 *          If subtree root pointer is provided it only returns the number
 *          of Hashables in the subtree.
 * @param   DataNode* subTreePtr
 * @return  Integer total of number of unique Hashables in the tree.
*/
int SearchTree::numHashablesRecursive(
   const SearchTree::DataNode* const subTreePtr) const
{
   // Pre-order traversal.
   if (subTreePtr == nullptr) { // base case.
      return 0; // empty
   }
   else {
      // The "1" represents visiting the root first, then left and right
      // which is the same order as pre-order traversal.
      return 1 + numHashablesRecursive(subTreePtr->left) +
         numHashablesRecursive(subTreePtr->right);
   }
}
