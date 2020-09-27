/* 
 * A minimal, single-header C89 testing framework in under a Kibibyte.
 * Sean Tyler Berryhill
 */

#ifndef _KIBITEST_H
#define _KIBITEST_H

#include <stdio.h>
#include <stdlib.h>

int _kibi_currentTestHasFailures; /* Do not modify externally */

#define Kibi_Test(function) ({\
  _kibi_currentTestHasFailures = 0;\
  printf("%s:\n", #function);\
  function();\
  if (_kibi_currentTestHasFailures) {\
    printf("...FAILED.\n\n");\
    exit(EXIT_FAILURE);\
  } else {\
    printf("... PASSED.\n\n");\
  }\
})

#define Kibi_AssertTrue(condition) ({\
  if (!(condition)) {\
    _kibi_currentTestHasFailures = 1;\
    printf("\tError @ %s:%d\texpected true but was false\n", __FILE__, __LINE__);\
  }\
})

#define Kibi_AssertFalse(condition) ({\
  if (condition) {\
    _kibi_currentTestHasFailures = 1;\
    printf("\tError @ %s:%d\texpected false but was true\n", __FILE__, __LINE__);\
  }\
})

#endif