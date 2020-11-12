#include"unity.h"
#include "hangman.h"

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

void test_MarkBody(void)
{
    TEST_ASSERT(1);
}
 void test_Markzero(void)
 {
     TEST_ASSERT(1);
 }
 void test_Markone(void)
 {
     TEST_ASSERT(2);
 }
 void test_Marktwo(void)
 {
    TEST_ASSERT(3);
 }
 void test_Markthree(void)
 {
     TEST_ASSERT(4);
 }
 void test_Markfour(void)
 {
     TEST_ASSERT(5);
 }
int test_main(void)
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(test_MarkBody);
  RUN_TEST(test_Markzero);
  RUN_TEST(test_Markone);
  RUN_TEST(test_Marktwo);
  RUN_TEST(test_Markthree);
  RUN_TEST(test_Markfour);
  /* Close the Unity Test Framework */
  return UNITY_END();
}
