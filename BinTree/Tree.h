//
// Created by charari on 9/18/21.
//

#ifndef DATA_STRUCTURE_TREE_H
#define DATA_STRUCTURE_TREE_H

#include "Common.h"

typedef struct Node
{
    DataType data;
    struct Node* lchild;
    struct Node* rchild;
}Node, *Tree;

// 二叉树构建
// 根据带有ENDFLAG的前序序列建立二叉树
void BinTreeInit(Tree* root, const DataType* arr, int* subs, int n);
void BinTreeInit_Iter(Tree* root, const DataType* arr, int n);
// 根据前序和中序序列建立二叉树(树中没有重复元素)
void BinTreeInit_VLR_LVR(Tree* root, const DataType* VLR, const DataType* LVR, int n);
void BinTreeInit_VLR_LVR_Iter(Tree* root, const DataType* VLR, const DataType* LVR, int n);
// 根据后序和中序序列建立二叉树(树中没有重复元素)
void BinTreeInit_LVR_LRV(Tree* root, const DataType* LVR, const DataType* LRV, int n);
void BinTreeInit_LVR_LRV_Iter(Tree* root, const DataType* LVR, const DataType* LRV, int n);
// 前序遍历二叉树(递归、非递归、Morris)
void preOrder(Tree root);
void preOrder_Iter(Tree root);
void preOrder_Morris(Tree root);
// 中序遍历二叉树(递归、非递归、Morris)
void inOrder(Tree root);
void inOrder_Iter(Tree root);
void inOrder_Morris(Tree root);
// 后序遍历二叉树(递归、非递归、Morris)
void postOrder(Tree root);
void postOrder_Iter(Tree root);
void postOrder_Morris(Tree root);
// 层序遍历二叉树
void levelOrder(Tree root);
// 二叉树节点个数
int BinTreeSize(Tree root);
int BinTreeSize_Iter(Tree root);
// 二叉树叶子节点个数
int BinTreeLeafSize(Tree root);
int BinTreeLeafSize_Iter(Tree root);
// 二叉树第k层结点个数
int BinTreeLevelKSize(Tree root, int k);
int BinTreeLevelKSize_Iter(Tree root, int k);
// 查找值为x的结点
Node* BinTreeFind(Tree root, DataType v);
Node* BinTreeFind_Iter(Tree root, DataType v);
// 销毁二叉树
void BinTreeDestroy(Tree* root);
void BinTreeDestroy_Iter(Tree* root);

#endif //DATA_STRUCTURE_TREE_H
