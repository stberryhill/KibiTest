# KibiTest
> A minimal, single-header C89 testing framework in under a Kibibyte.


KibiTest is designed to be the bare essentials - a no-fuss testing solution that's self-explanatory. It was conceived as both a fun exercise in minimalism and as the testing solution for my upcoming terminal-manipulation library.

* [Summary](#summary)
* [Examples](#examples)
	* [Simple Example](#simple-example)
	* [Complete Example](#complete-example)
* [Automated Workflow](#automated-workflow)

## Summary

* There are three main functions: **Kibi_Test**, **Kibi_AssertTrue**, and **Kibi_AssertFalse**. Optionally specify setup/teardown functions to be called before and after each test with **Kibi_ForEach**.
* Pass the desired test function into **Kibi_Test** to run it (must have no parameters).
* Simply include the header file - no linking necessary. If a test fails, the process exits with a non-0 return code.
  

## Examples

<a name="simple-example"></a>
### Simple Example

Here is an example that covers the most common 3 functions one will need to use.

 #### Source

```c
#include "KibiTest.h"
#include <stdbool.h>

bool correctPrefixIsKibi(int numBytes) {
  bool isKibi = numBytes == 1024 ? true : false;
}

bool correctPrefixIsKilo(int numBytes) {
  bool isKibi = numBytes == 1000 ? true : false;
}

void KibiMeans1024() {
  const int numBytes = 1024;
  Kibi_AssertTrue(correctPrefixIsKibi(numBytes));
  Kibi_AssertFalse(correctPrefixIsKilo(numBytes));
}

void KiloMeans1000() {
  const int numBytes = 1000;
  Kibi_AssertTrue(correctPrefixIsKilo(numBytes));
  Kibi_AssertFalse(correctPrefixIsKibi(numBytes));
}

int main() {

  Kibi_Test(KibiMeans1024);
  Kibi_Test(KiloMeans1000);

  return 0;
}
```



#### Output

```sh
$ gcc -std=c89 SimpleTest.c -o SimpleTest
$ ./SimpleTest
KibiMeans1024:
... PASSED.

KiloMeans1000:
... PASSED.

$ 
```


<a name="complete-example"></a>
### Complete Example

This example includes usage of **Kibi_ForEach**, the fourth and final function in KibiTest. This is useful if you need to create a blank slate before each test and then clean it up after, for example.

 #### Source

```c
#include "KibiTest.h"
#include <string.h>

struct Foo {
  int a;
  char string[256];
};

struct Foo *foo;

void before() {
  foo = malloc(sizeof *foo);
  foo->a = 0;
  strcpy(foo->string, "Hello, World");
}

void after() {
  free(foo);
}

void fooIsCreatedCorrectly() {
  Kibi_AssertTrue(foo != NULL);
  Kibi_AssertTrue(foo-> a == 0);
  Kibi_AssertTrue(strcmp(foo->string, "Hello, World") == 0);
}

int main() {
  Kibi_ForEach(before, after); /* Completely optional  */

  Kibi_Test(fooIsCreatedCorrectly);

  return 0;
}
```




#### Output

```sh
$ gcc -std=c89 CompleteTest.c -o CompleteTest
$ ./CompleteTest
fooIsCreatedCorrectly:
... PASSED.

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
