#include "auto.h"

#include "gtest/gtest.h"
#include <iostream>

using namespace std;

namespace {

	////////////////////////////////////////////////////////////////////////////
	// 
	// Tests add for int
	//
	// expect success
	// 
	////////////////////////////////////////////////////////////////////////////
	//
	// 
	TEST(tc_add, integer) {
		int                  left       = 1;
		int                  right      = 2;
		int                  expect     = left + right;
		int                  result     = 0;
		
		result        = add(left, right);
		cout << "left  : " << left   << endl;
		cout << "right : " << right  << endl;
		cout << "result: " << result << endl;

		EXPECT_EQ(expect, result);
	}

	////////////////////////////////////////////////////////////////////////////
	// 
	// Tests add for double
	//
	// expect success
	// 
	////////////////////////////////////////////////////////////////////////////
	//
	// 
	TEST(tc_add, double) {
		double                  left       = 1.1;
		double                  right      = 2.2;
		double                  expect     = left + right;
		double                  result     = 0;

		result        = add(left, right);

		cout << "left  : " << left   << endl;
		cout << "right : " << right  << endl;
		cout << "result: " << result << endl;

		EXPECT_DOUBLE_EQ(expect, result);
	}

}  // namespace
