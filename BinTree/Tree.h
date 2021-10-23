#ifndef DS_TREE_H
#define DS_TREE_H

#include "Node/TNode.h"
#define tree() Tree()

typedef struct Node Node, *NodePtr;
typedef struct _TREE_ tree;
/*
 * construct func
 * usage:
 *      tree ${OBJECT_NAME} = tree()
*/
tree tree();

struct _TREE_
{
    Node* root;
    // Create BinTree by preorder sequence with ENDFLAG(a marco which indicate null pointer)
    void(*init)(NodePtr* root_ptr, const DataType* data_array_of_tree, int size_of_array);
    void(*init_iter)(NodePtr* root_ptr, const DataType* data_array_of_tree, int size_of_array);
    // Create BinTree by preorder sequence & inorder sequence(No duplicate elements in the BinTree)
    void(*init_vlr_lvr)(NodePtr* root_ptr, const DataType* preorder_sequence, const DataType* inorder_sequence, int size_of_sequence);
    void(*init_vlr_lvr_iter)(NodePtr* root_ptr, const DataType* preorder_sequence, const DataType* inorder_sequence, int size_of_sequence);
    // Create BinTree by postorder sequence & inorder sequence(No duplicate elements in the BinTree)
    void(*init_lvr_lrv)(NodePtr* root_ptr, const DataType* postorder_sequence, const DataType* inorder_sequence, int size_of_sequence);
    void(*init_lvr_lrv_iter)(NodePtr* root_ptr, const DataType* postorder_sequence, const DataType* inorder_sequence, int size_of_sequence);
    // Get preorder sequence of BinTree(recursive, iterator, Morris)
    void(*preorder)(NodePtr root_ptr);
    void(*preorder_iter)(NodePtr root_ptr);
    void(*preorder_morris)(NodePtr root_ptr);
    // Get inorder sequence of BinTree(recursive, iterator, Morris)
    void(*inorder)(NodePtr root_ptr);
    void(*inorder_iter)(NodePtr root_ptr);
    void(*inorder_morris)(NodePtr root_ptr);
    // Get postorder sequence of BinTree(recursive, iterator, Morris)
    void(*postorder)(NodePtr root_ptr);
    void(*postorder_iter)(NodePtr root_ptr);
    void(*postorder_morris)(NodePtr root_ptr);
    // Get levelorder sequence of BinTree
    void(*levelorder)(NodePtr root_ptr);
    // The number of node
    int(*size)(NodePtr root_ptr);
    int(*size_iter)(NodePtr root_ptr);
    // The number of leaf_node 
    int(*leafsize)(NodePtr root_ptr);
    int(*leafsize_iter)(NodePtr root_ptr);
    // The number of node in level K(set by variable index_of_level)
    int(*levelKSize)(NodePtr root_ptr, int index_of_level);
    int(*levelKSize_iter)(NodePtr root_ptr, int index_of_level);
    // Find the node which assigned by x(set by variable value_of_src_var)
    Node*(*find)(NodePtr root_ptr, DataType value_of_src_var);
    Node*(*find_iter)(NodePtr root_ptr, DataType value_of_src_var);
    // Destroy BinTree(ATTENTION: YOU MUST CALL THIS FUNCTION AFTER AN OBJECT FINISH ITS MISSON)
    void(*destroy)(NodePtr* root_ptr);
    void(*destroy_iter)(NodePtr* root_ptr);
};

#endif //DS_TREE_H
