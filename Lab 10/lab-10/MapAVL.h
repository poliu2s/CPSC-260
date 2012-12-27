// file: MapAVL.h
// Header file for the template version of MapAVL class
//  that uses a AVL binary search tree.


/*--------------------------------------------------------------------------*/
/*                                                                          */
/*  This class implements a map using AVL trees                             */
/*                                                                          */
/*- Modification History ---------------------------------------------------*/
/*  When:       Who:                    Comments:                           */
/*                                                                          */
/*  18-Mar-92   Christopher G. Healey   Initial implementation              */
/*  07-Jan-93   Christopher G. Healey   Converted to work as a dictionary   */
/*  04-Jul-93   Christopher G. Healey   Converted to C++                    */
/*  28-Jul-98   Felix Chang             Change the interface to             */
/*                                        follow the other Map template     */
/*                                        class examples.                   */
/*  20-Jun-01   Paul Carter             Changed so that this class is       */
/*                                      derived from MapAbstract base class */
/*--------------------------------------------------------------------------*/


#ifndef MAPAVL_H
#define MAPAVL_H

#include "MapAbstract.h"
#include "Pair.h"


enum MapAVL_balance      // Three possible balance types for an AVL node
{
   LH,              // Left subtree 1 higher than right
   RH,              // Right subtree 1 higher than left
   EQ               // Both subtrees same height
};

template <class Key, class Value>
struct MapAVLNode
{
   MapAVL_balance factor;   // balance factor.  LH, RH, or EQ.
   Key key;
   Value value;
   MapAVLNode* left;
   MapAVLNode* right;
};


template <class Key, class Value>
class MapAVL : public MapAbstract< Key, Value >

   // The MapAVL class defines a mapping of 'keys' to 'values'.
   // It has both default and copy constructor.

   // Requirement:
   // - "Key" for this container must have
   //      default constructor
   //      copy constructor
   //      assignment operator
   //      == operator
   //      < operator
   // - "Value" for this container must have
   //      default constructor
   //      copy constructor
   //      assignment operator
{
  public:

    MapAVL( );
    // Default constructor
    // POST: An empty MapAVL is created

    MapAVL( const MapAVL& originalMapAVL );
    // Copy constructor
    // POST: A new MapAVL is created containing the same elements as originalMapAVL

    ~MapAVL();
    // Destructor
    // POST: The MapAVL object is destroyed

    MapAVL& operator=( const MapAVL& someMapAVL );
    // Member operator function
    // POST:  The contents of 'otherMapAVL' are copied into the current MapAVL

    bool empty( const Key& key ) const;
    // Pre: key has been initialized
    // Post: if the key is not in the map true is returned; otherwise
    // false is returned

    void erase( const Key& key );
    // Pre: key has been initialized
    // Post: if key is in the map it has been removed; otherwise
    // map is not changed

    Value& operator[] ( const Key& key );
    // Pre: key has been initialized
    // Post: if key is in the map, reference to value corresponding to key 
    //       has been returned; otherwise key has been added to map with 
    //       corresponding default value
    // Exception: if not enough memory to add key, map_full has been thrown

    const Value& operator[] ( const Key& key ) const;
    // Pre: key is in the map
    // Post: const reference to value corresponding to key has been returned
    // Exception: if the key is not in the map, not_valid_key has been thrown

    void dump(Pair<Key,Value>* array) const;
    // Pre: array is an array of pairs of Key and Value
    //      array must be at least size() elements long
    // Post: key and value pairs have been written into the array

  private:

    MapAVLNode<Key,Value>*  root;   // Points to the top-most node

    int dumpHelper( MapAVLNode<Key,Value>* ptr, Pair<Key,Value>* array ) const;
    // Helper function that stores the keys and values of a particular SUBTREE
    //   into a user supplied array.
    // PRE:  array is an array of at least size() elements long.
    //
    // POST: All <key,value> pairs in the subtree is written into the array.
    //       The number of pairs written is returned as the function return value.

    void copy( const MapAVL& someMapAVL );
    // Helper function used by MapAVL( const MapAVL& someMapAVL )
    // and operator=( const MapAVL& someMapAVL )
    // POST: The contents of 'someMapAVL' are copied into the current MapAVL

    void copySubTree( MapAVLNode<Key,Value>& root, const MapAVLNode<Key,Value>& otherRoot );
    // Private helper function that copies all values from 'otherRoot' into this root,
    //   including all children nodes.
    // POST:  All childr nodes are copied from 'otherRoot' into 'root'.

    void eraseTree( MapAVLNode<Key,Value>* ptr );
    // Private helper function that deletes a node and all children.
    // POST:  If the pointer is NULL, then nothing happens.
    //        otherwise, the node and all children are deleted.

    Value& add( const Key& key );
    // Private helper function that adds a key to a tree.
    // PRE:   key has been initialized
    // POST:  If key is not already in the tree, then it is added.
    //        otherwise map is not changed.
    // Exception: if not enough memory to add key, map_full exception is thrown


    MapAVLNode<Key,Value>* addNode   ( MapAVLNode<Key,Value>* tree, const Key& key, bool& taller  );
    // Private helper function that adds a key to a subtree.
    // PRE:   key has been initialized 
    // POST:  If key is not already in the tree, then it is added (and the new root returned)
    //        otherwise map is not changed
    //        Also, taller will be set according to whether the tree has grown taller or not.

    MapAVLNode<Key,Value>* eraseNode ( MapAVLNode<Key,Value>* tree, const Key& key, bool& shorter );
    // Private helper function that erases a key from a subtree.
    // PRE:   key has been initialized
    // POST:  If key is already in the tree, then it is deleted (and the new root returned)
    //        otherwise map is not changed
    //        Also, shorter will be set according to whether the tree has become shorter or not.

    MapAVLNode<Key,Value>* leftBalance  ( MapAVLNode<Key,Value>* node );
    // Private helper function that performs with a LL or a LR rotation on a node.

    MapAVLNode<Key,Value>* rightBalance ( MapAVLNode<Key,Value>* node );
    // Private helper function that performs with a RL or a RR rotation on a node.

    MapAVLNode<Key,Value>* LL_rotate ( MapAVLNode<Key,Value>* node );
    // Private helper function that performs with a LL rotation on a node.

    MapAVLNode<Key,Value>* LR_rotate ( MapAVLNode<Key,Value>* node );
    // Private helper function that performs with a LR rotation on a node.

    MapAVLNode<Key,Value>* RL_rotate ( MapAVLNode<Key,Value>* node );
    // Private helper function that performs with a RL rotation on a node.

    MapAVLNode<Key,Value>* RR_rotate ( MapAVLNode<Key,Value>* node );
    // Private helper function that performs with a RR rotation on a node.
};

#include "MapAVL.template"

#endif
