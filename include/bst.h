//
//  bst.h
//  bst
//
//  Created by Justin Hsieh on 2/12/17.
//  Copyright (c) 2017 Justin Hsieh. All rights reserved.
//

#ifndef __bst__bst__
#define __bst__bst__

#define DEBUG

#include <cstdlib>
#include <vector>
#include <cassert>

using namespace std;

enum BST_PRINT_TYPE {PRE, IN, POST};

class bst {
    
public:
    // Default
    bst(): head(NULL), max_val(0), min_val(0) {}
    
    // Copy Constructor
    bst(bst const &_bst);
    
    // Destructor
    ~bst();
    
    // INFO
    bool empty();
    int max();
    int min();
    void print(BST_PRINT_TYPE);
    bool search(int key);
    
	// EDITING
    void add(int key, int value);
    bool remove(int key);


	#ifdef DEBUG
	vector<int> checker;
	void create_checker();
	#endif

  
private:
    struct Node {
		Node(int _key, int _value): 
		key(_key), value(_value), right(NULL), left(NULL) {}
       
		~Node() {}
 
		int key;
        int value;
        Node* right;
        Node* left;
    };    


    Node* head;
	int max_val;
	int min_val;
	bool search_helper(Node* node, int key);
	void add_helper(Node* node, int key, int value);
	void create_checker_helper(Node* node);
	bool remove_helper(Node** node, int key, Node* prev);
	void destruct(Node** node);
	void copy_helper(Node* node, Node** copy);


	void preorder(Node* node);
	void postorder(Node* node);
	void inorder(Node* node);
};

#endif /* defined(__bst__bst__) */
