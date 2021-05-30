#include "gtest/gtest.h"

#include <iostream>
#include <string>
#include "Character_Factory/Character_Factory.hpp"
#include "weapons/weapon_tests.hpp"
#include "character/character.hpp"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
