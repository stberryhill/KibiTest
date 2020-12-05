# KibiTest
> A minimal, single-header C89 testing framework in under a Kibibyte.


KibiTest is designed to be the bare essentials - a no-fuss testing solution that's self-explanatory. It was created as both a fun exercise in minimalism and as the testing solution for my terminal-manipulation library.

- [KibiTest](#kibitest)
  - [Summary](#summary)
  - [Complete Example](#complete-example)
      - [Source](#source)
      - [Output](#output)
  - [Automated Workflow](#automated-workflow)
    - [Make](#make)

## Summary

* There are three main functions: **Kibi_Test**, **Kibi_AssertTrue**, and **Kibi_AssertFalse**. Optionally specify setup/teardown functions to be called before and after each test with **Kibi_ForEach**.
* Pass the desired test function into **Kibi_Test** to run it (must have no parameters).
* Simply include the header file - no linking necessary. If a test fails, the process exits with a non-0 return code.
  

<a name="complete-example"></a>
## Complete Example

This example uses all four functions of KibiTest.

 #### Source

```c
#include "KibiTest.h"
#include <string.h>

struct Foo {
  int number;
  char string[256];
};

struct Foo *foo;

void before() {
  foo = malloc(sizeof *foo);
  foo->number = 0;
  strcpy(foo->string, "Hello, World");
}

void after() {
  free(foo);
}

void fooIsCreatedCorrectly() {
  Kibi_AssertFalse(foo == NULL);
  Kibi_AssertTrue(foo->number == 0);
  Kibi_AssertTrue(strcmp(foo->string, "Hello, World") == 0);
}

void fooNumberEquals5() {
  /* Fails since foo->number is 0 */
  Kibi_AssertTrue(foo->number == 5);
}

int main() {
  Kibi_ForEach(before, after);

  Kibi_Test(fooIsCreatedCorrectly);
  Kibi_Test(fooNumberEquals5);

  return 0;
}
```


#### Output

```sh
$ gcc -std=c89 test.c -o test
$ ./test
fooIsCreatedCorrectly:
... PASSED.

fooNumberEquals5:
        Error - Assert true failed @ test.c:28
...FAILED.

$
```


<a name="automated-workflow"></a>
## Automated Workflow

In general, if you're looking to use KibiTest in an automated workflow, you will use the return value of the test process. Non-0 means a test failed.

### Make

To use with make, you can declare a test target like so:

```cmake
.PHONY : test
test: all
	./$(TEST_EXECUTABLE); test $$? -eq 0
```



replacing *TEST_EXECUTABLE* with the name of your test executable. You can then run the tests with:

```shell
make test
```

Or you could make other targets depend on *test* so the build halts if any tests fail.
