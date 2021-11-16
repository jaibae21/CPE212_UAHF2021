// ****************************************
// Program Title: Project 5
// Project File: bstree.cpp
// Name: Jaiden Gann
// Course Section: CPE-212-01
// Due Date: 11/13/2021
// Program description: The .cpp file that 
// defines the basic functions from the
// bstree.h file
// ****************************************

#include <iostream>
#include <new>
#include "bstree.h"


template <typename SomeType>
void BSTree<SomeType>::Delete(BSTreeNode<SomeType>*& treePtr, SomeType& item)
{
	
	if (treePtr == NULL)
	{
		throw NotFoundBSTree();
	}
	else if (item < treePtr->data)
	{
		Delete(treePtr->leftPtr, item);
	}
	else if (item > treePtr->data)
	{
		Delete(treePtr->rightPtr, item);
	}
	else
	{
		item = treePtr->data;
		DeleteNode(treePtr);
	}
}
template <typename SomeType>
void BSTree<SomeType>::DeleteNode(BSTreeNode<SomeType>*& treePtr)
{
	SomeType tmp;
	if (treePtr->rightPtr == NULL && treePtr->leftPtr == NULL)
	{
		delete treePtr;
		treePtr = NULL;
	}
	else if (treePtr->leftPtr == NULL)
	{
		BSTreeNode<SomeType>* tmp = treePtr;	//tmp pointer to treePtr
		treePtr = treePtr->rightPtr;	//change what treePtr points to
		delete tmp;	//delete tmp which was the original treePtr
	}
	else if (treePtr->rightPtr == NULL)
	{
		BSTreeNode<SomeType>* tmp = treePtr;
		treePtr = treePtr->leftPtr;
		delete tmp;
	}
	else // two children
	{
		
		tmp = GetPredecessor(treePtr->leftPtr);
		treePtr->data = tmp;
		Delete(treePtr->leftPtr, tmp);	//delete duplicate just made
	}
}
template <typename SomeType>
void BSTree<SomeType>::Insert(BSTreeNode<SomeType>*& ptr, SomeType item)
{
	if (ptr == NULL)
	{
		ptr = new BSTreeNode<SomeType>;
		ptr->rightPtr = NULL;
		ptr->leftPtr = NULL;
		ptr->data = item;

	}
	else if (item < ptr->data)
	{
		Insert(ptr->leftPtr, item);
	}
	else if (item > ptr->data)
	{
		Insert(ptr->rightPtr, item);
	}
	else
	{
		throw FoundInBSTree();
	}
}
template <typename SomeType>
void BSTree<SomeType>::Destroy(BSTreeNode<SomeType>*& ptr)
{
	if (ptr->rightPtr == NULL && ptr->leftPtr == NULL)
	{
		DeleteNode(ptr);
	}
	else if (ptr->rightPtr == NULL)
	{
		Destroy(ptr->leftPtr);
		DeleteNode(ptr);
	}
	else if (ptr->leftPtr == NULL)
	{
		Destroy(ptr->rightPtr);
		DeleteNode(ptr);
	}
	else
	{
		Destroy(ptr->rightPtr);
		Destroy(ptr->leftPtr);
		DeleteNode(ptr);
	}
}
template <typename SomeType>
void BSTree<SomeType>::CopyTree(BSTreeNode<SomeType>*& copy, const BSTreeNode<SomeType>* originalTree)
{
	if (originalTree == NULL)
	{
		copy = NULL;
	}
	else
	{
		copy = new BSTreeNode<SomeType>;
		copy->data = originalTree->data;
		copy->leftPtr = originalTree->leftPtr;
		copy->rightPtr = originalTree->rightPtr;

		CopyTree(copy->leftPtr, originalTree->leftPtr);
		CopyTree(copy->rightPtr, originalTree->rightPtr);
	}
}
template <typename SomeType>
SomeType BSTree<SomeType>::GetPredecessor(BSTreeNode<SomeType>* treePtr) const
{
	BSTreeNode<SomeType>* tmp = treePtr;
	while (tmp->rightPtr != NULL)
	{
		tmp = tmp->rightPtr;
	}

	return tmp->data;
}
template <typename SomeType>
int BSTree<SomeType>::CountNodes(BSTreeNode<SomeType>* treePtr) const
{
	if (treePtr->rightPtr == NULL && treePtr->leftPtr == NULL)
	{
		return 1;
	}
	else if (treePtr->leftPtr == NULL)
	{
		return 1 + CountNodes(treePtr->rightPtr);
	}
	else if (treePtr->rightPtr == NULL)
	{
		return 1 + CountNodes(treePtr->leftPtr);
	}
	else
	{
		return 1 + CountNodes(treePtr->rightPtr) + CountNodes(treePtr->leftPtr);
	}
}

template <typename SomeType>
int BSTree<SomeType>::LevelCount(BSTreeNode<SomeType>* treePtr) const
{
	if (treePtr->rightPtr == NULL && treePtr->leftPtr == NULL)
	{
		return 1;
	}
	else if (treePtr->rightPtr == NULL)
	{
		return 1 + LevelCount(treePtr->leftPtr);
	}
	else if (treePtr->leftPtr == NULL)
	{
		return 1 + LevelCount(treePtr->rightPtr);
	}
	else
	{
		return 1 + max(LevelCount(treePtr->leftPtr), LevelCount(treePtr->rightPtr));
	}
}

template <typename SomeType>
int BSTree<SomeType>::FindLevel(BSTreeNode<SomeType>* treePtr, SomeType item) const
{
	if (treePtr == NULL)
	{
		throw NotFoundBSTree();
	}
	else if (treePtr->data == item)
	{
		return 0;
	}
	else if (treePtr->data < item)
	{
		return 1 + FindLevel(treePtr->rightPtr, item);
	}
	else
	{
		return 1 + FindLevel(treePtr->leftPtr, item);
	}
}


//Public Functions//
template <typename SomeType> 
BSTree<SomeType>::BSTree()
{
	this->rootPtr = NULL;
}

template <typename SomeType>
BSTree<SomeType>::BSTree(const BSTree<SomeType>& someTree)
{
	CopyTree(this->rootPtr, someTree.rootPtr);
}

template <typename SomeType>
void BSTree<SomeType>::operator=(const BSTree<SomeType>& originalTree)
{
	CopyTree(this->rootPtr, originalTree.rootPtr);
}

template <typename SomeType>
BSTree<SomeType>::~BSTree()
{
	if (!this->IsEmpty())
	{
		Destroy(this->rootPtr);
	}
}

template <typename SomeType>
void BSTree<SomeType>::InsertItem(SomeType item)
{
	if (this->IsFull())
	{
		throw FoundInBSTree();
	}

	Insert(this->rootPtr, item);
}

template <typename SomeType>
SomeType BSTree<SomeType>::DeleteItem(SomeType item)
{
	if (this->IsEmpty())
	{
		throw EmptyBSTree();
	}

	SomeType itemCopy = item;

	Delete(this->rootPtr, item);

	return itemCopy;
}

template <typename SomeType>
void BSTree<SomeType>::MakeEmpty()
{
	if (!this->IsEmpty())
	{
		Destroy(this->rootPtr);
	}
}

template <typename SomeType>
int BSTree<SomeType>::Size() const
{
	if (this->rootPtr == NULL)
	{
		return 0;
	}
	else
	{
		return CountNodes(this->rootPtr);
	}
}

template <typename SomeType>
bool BSTree<SomeType>::IsFull() const
{
	return false;
}

template <typename SomeType>
bool BSTree<SomeType>::IsEmpty() const
{
	return rootPtr == NULL;
}

template <typename SomeType>
SomeType BSTree<SomeType>::Min() const
{
	if (this->IsEmpty())
	{
		throw EmptyBSTree();
	}

	BSTreeNode<SomeType> *tmp = this->rootPtr;

	while (tmp->leftPtr != NULL)
	{
		tmp = tmp->leftPtr;
		return tmp->data;
	}
}

template <typename SomeType>
SomeType BSTree<SomeType>::Max() const
{
	if (this->IsEmpty())
	{
		throw EmptyBSTree();
	}

	BSTreeNode<SomeType>* tmp = this->rootPtr;

	while (tmp->rightPtr != NULL)
	{
		tmp = tmp->rightPtr;
		return tmp->data;
	}
}

template <typename SomeType>
int BSTree<SomeType>::TotalLevels() const
{
	if (this->IsEmpty())
	{
		throw EmptyBSTree();
	}

	return LevelCount(this->rootPtr);
}

template <typename SomeType>
int BSTree<SomeType>::Level(SomeType item) const
{
	if (this->IsEmpty())
	{
		throw EmptyBSTree();
	}

	return FindLevel(this->rootPtr, item);
}

