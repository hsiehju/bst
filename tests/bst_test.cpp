#include "../include/bst.h"
#include "gtest/gtest.h"
#include <cstdlib>
#include <algorithm>


TEST (BST_COMPILATION, instantiation) {
	bst t;
}


TEST(BST_INFO, empty) {
	bst t;
	EXPECT_EQ(t.empty(), true);
}


TEST(BST_EDIT, add_head) {
	bst t;
	vector<int> checker;
	t.add(7,0);
	t.create_checker();
	
	checker.push_back(7);
	
	EXPECT_EQ(t.empty(), false);

	EXPECT_EQ(t.checker[0], checker[0]);

}


TEST(BST_EDIT, add_three_balanced) {
	bst t;
	vector<int> checker;

	t.add(7,0);
	t.add(1,0);	
	t.add(-1,0);
	t.create_checker();

	checker.push_back(-1);
	checker.push_back(1);
	checker.push_back(7);

	EXPECT_EQ(t.empty(), false);
	for(int i = 0; i < 3; i++)
		EXPECT_EQ(t.checker[i], checker[i]);
}


TEST(BST_EDIT, add_random) {
	bst t;
	vector<int> checker;

	for(int i = 0; i < 15; i++) {
		int value = rand();
		t.add(value,0);
		checker.push_back(value);
	}

	t.create_checker();
	sort(checker.begin(), checker.end());

	EXPECT_EQ(t.empty(), false);


	for(int i = 0; i < 15; i++)
		EXPECT_EQ(t.checker[i], checker[i]);
}


TEST(BST_INFO, search_for_values) {
	bst t;
	
	t.add(7,0);
	t.add(1,0);	
	t.add(-1,0);
	t.add(15,0);	
	t.add(2,0);	
	t.add(9,0);
	
	EXPECT_EQ(t.empty(), false);
	

	EXPECT_EQ(t.search(-1), true);
	EXPECT_EQ(t.search(9), true);
	EXPECT_EQ(t.search(-7), false);
	EXPECT_EQ(t.search(3), false);
}


TEST(BST_INFO, max_value) {
	bst t;
	
	t.add(7,0);
	t.add(1,0);	
	t.add(-1,0);
	t.add(15,0);	
	t.add(2,0);	
	t.add(9,0);
	
	EXPECT_EQ(t.empty(), false);
	
	EXPECT_EQ(t.max(), 15);
}



TEST(BST_INFO, min_value) {
	bst t;
	
	t.add(7,0);
	t.add(1,0);	
	t.add(-1,0);
	t.add(15,0);	
	t.add(2,0);	
	t.add(9,0);
	
	EXPECT_EQ(t.empty(), false);
	
	EXPECT_EQ(t.min(), -1);
}

TEST(BST_EDIT, remove_head) {
	bst t;
	
	t.add(7,0);
	
	EXPECT_EQ(t.empty(), false);

	EXPECT_EQ(t.remove(7), true);

	EXPECT_EQ(t.empty(), true);
	
}



TEST(BST_EDIT, remove_multiple) {
	bst t;
	vector<int> checker;
	t.add(7,0);
	t.add(1,0);	
	t.add(-1,0);
	t.add(15,0);	
	t.add(2,0);	
	t.add(9,0);
	
	EXPECT_EQ(t.empty(), false);


	EXPECT_EQ(t.remove(2), true);
	EXPECT_EQ(t.remove(9), true);
	EXPECT_EQ(t.remove(-2), false);
	EXPECT_EQ(t.remove(8), false);
	
	t.create_checker();
	checker.push_back(7);	
	checker.push_back(1);	
	checker.push_back(-1);	
	checker.push_back(15);
	sort(checker.begin(), checker.end());

	for(unsigned i = 0; i < checker.size(); i++)
		EXPECT_EQ(t.checker[i], checker[i]);
}



TEST(BST_EDIT, copy_constructor) {
	bst t;
	vector<int> checker;
	t.add(7,0);
	t.add(1,0);	
	t.add(-1,0);
	t.add(15,0);	
	t.add(2,0);	
	t.add(9,0);
	
	bst copy(t);

	EXPECT_EQ(t.empty(), false);
	EXPECT_EQ(copy.empty(), false);

	copy.create_checker();
	checker.push_back(7);	
	checker.push_back(1);	
	checker.push_back(-1);	
	checker.push_back(15);
	checker.push_back(2);
	checker.push_back(9);
	sort(checker.begin(), checker.end());

	for(unsigned i = 0; i < checker.size(); i++)
		EXPECT_EQ(copy.checker[i], checker[i]);
	
}




TEST(BST_EDIT, destructor) {
	bst* t = new bst();
	
	t->add(7,0);
	t->add(1,0);	
	t->add(-1,0);
	t->add(15,0);	
	t->add(2,0);	
	t->add(9,0);
	
	EXPECT_EQ(t->empty(), false);

	delete t;

	EXPECT_EQ(t->empty(), true);

	t = 0;
}
