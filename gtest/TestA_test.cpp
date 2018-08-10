#include "TestA.h"
#include <gtest/gtest.h>

TEST(TestATest, testType) {
	//ASSERT_EQ(TestA::kTest, 1);
	int key = TestA::kTest;
	ASSERT_EQ(key, 1);
}


