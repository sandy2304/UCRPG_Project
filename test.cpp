#include "gtest/gtest.h"

#include <iostream>

TEST(testForTest, test){
	int num = 1;
	EXPECT_EQ(num, 1);	
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
