#include "KibiTest.h"

void fiveTimesSevenIsThirtyFive() {
  const int FIVE_TIMES_SEVEN = 5 * 7;
  Kibi_AssertTrue(FIVE_TIMES_SEVEN == 35);
}

void threeIsLessThanTwo() {
  const int X = 3;
  Kibi_AssertTrue(X < 2);
}

void onePlusOneIsNotFour() {
  Kibi_AssertFalse(1 + 1 == 4);
}

int main() {
  Kibi_Test(fiveTimesSevenIsThirtyFive);
  Kibi_Test(threeIsLessThanTwo);
  Kibi_Test(onePlusOneIsNotFour);

  return 0;
}