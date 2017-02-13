//
//  bst.cpp
//  bst
//
//  Created by Justin Hsieh on 2/12/17.
//  Copyright (c) 2017 Justin Hsieh. All rights reserved.
//

#include "../include/bst.h"
#include <iostream>
using namespace std;

// Copy Constructor
bst::bst(bst const &_bst) {
    if(_bst.head==NULL)
		return;

	copy_helper(_bst.head, &head);
   	min_val = _bst.min_val; 
    max_val = _bst.max_val; 
}

// Destructor
bst::~bst() {
	if(!this->empty())
		destruct(&head); 
}

////////////////////////////////////////////////
//					PRIVATE					  //
////////////////////////////////////////////////
void bst::copy_helper(Node* node, Node** copy) {
	Node* t = new Node(node->key, node->value);
	*copy = t;
	
	if(node->left!=NULL)
		copy_helper(node->left, &(*copy)->left);
	if(node->right!=NULL)
		copy_helper(node->right, &(*copy)->right);

}

void bst::destruct(Node** node) {
	if((*node)->left!=NULL)
		destruct(&(*node)->left);
	if((*node)->right!=NULL)
		destruct(&(*node)->right);

	if((*node)->left==NULL && (*node)->right==NULL) {
		delete *node; *node = 0;
	}
}

// recursive until key equals, then remove and fix
bool bst::remove_helper(Node** node, int key, Node* prev) {
	if(*node == NULL)
		return false;

	if((*node)->key > key)
		return remove_helper(&(*node)->left, key, *node); 
	else if((*node)->key < key)
		return remove_helper(&(*node)->right, key, *node);
	else {		
		if((*node)->right!=NULL) {
			prev->right = (*node)->right;			
		}
		else if((*node)->left!=NULL) {
			prev->left = (*node)->left;
		}

		delete *node; *node = 0;

		return true;
	}
}


// recursively search until key equals
bool bst::search_helper(Node* node, int key) {
	if(node == NULL)
		return false;

	if(node->key > key)
		return search_helper(node->left, key); 
	else if(node->key < key)
		return search_helper(node->right, key);
	else
		return true;
}

// recursivley traverse until correct position, then add Node
void bst::add_helper(Node* node, int key, int value) {
	if(node->key > key)
		if(node->left!=NULL)
			add_helper(node->left, key, value);
		else {
			Node* t = new Node(key, value);
			node->left = t;
		}
	else {
		if(node->right!=NULL) 
			add_helper(node->right, key, value);
		else {
			Node* t = new Node(key, value);
			node->right = t;
		}
	}
}

#ifdef DEBUG
// add keys inorder to vector to be checked
void bst::create_checker_helper(Node* node) {
	if(node==NULL)
		return;
	create_checker_helper(node->left);
	checker.push_back(node->key);
	create_checker_helper(node->right);
}
#endif

// preorder print out
void bst::preorder(Node* node) {
	if(node==NULL)
		return;
	cout << node->key << ", ";
	preorder(node->left);
	preorder(node->right);
}

// inorder print out
void bst::inorder(Node* node) {
	if(node==NULL)
		return;
	inorder(node->left);
	cout << node->key << ", ";
	checker.push_back(node->key);
	inorder(node->right);
}

// postorder print out
void bst::postorder(Node* node) {
	if(node==NULL)
		return;
	postorder(node->left);
	postorder(node->right);
	cout << node->key << ", ";
}

////////////////////////////////////////////////					
//					PUBLIC					  //
////////////////////////////////////////////////

// DEBUG
#ifdef DEBUG
void bst::create_checker() {
	create_checker_helper(head);	
}	
#endif


// INFO
bool bst::empty() {
    if(head==NULL)
		return true;
	else
		return false;
}

// return 0 is empty
int bst::max() {
	return max_val;
}

// return 0 is empty
int bst::min() {
    return min_val;
}
void bst::print(BST_PRINT_TYPE type) {
	switch(type) {
		case PRE:
			cout << "PREORDER: ";
			preorder(head);
			break;
		case IN:
			cout << "INORDER: ";
			inorder(head);
			break;
		case POST:
			cout << "POSTORDER: ";
			postorder(head);
			break;
		default:
			inorder(head);
			break;
	}
	cout << endl;
}
bool bst::search(int key) {
    return search_helper(head, key);
}

// EDITING

// create and add node to bst
// key cannot be 0, means empty
void bst::add(int key, int value) {

	assert(key != 0);
	
	if(head == NULL) {
		Node* t = new Node(key, value);
		head = t;
	}
	else { 
		add_helper(head, key, value);
	}


	if(head->left==NULL && head->right==NULL) {
		min_val = max_val = key;
	}
	else {	
		min_val = std::min(min_val, key);
		max_val = std::max(max_val, key);
	}
}

// remove and fix tree
bool bst::remove(int key) {
	if(!bst::search(key))
		return false;
	else {
 		return remove_helper(&head, key, NULL);
	}

}


