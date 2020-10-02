# KibiTest
*A minimal, single-header C89 testing framework in under a Kibibyte.*

* There are three main functions: **Kibi_Test**, **Kibi_AssertTrue**, and **Kibi_AssertFalse**. You can optionally specify setup/teardown functions to be called before and after each test with **Kibi_ForEach**.
* Simply pass the desired test function into Kibi_Test (it must have no parameters).
* Just include the header file and you're good to go, no linking necessary.

## Example
### Usage
![gif-showing-example-code](https://github.com/stberryhill/KibiTest/blob/master/GIFs/Example_Source.gif)
### Output
![gif-showing-example-output](https://github.com/stberryhill/KibiTest/blob/master/GIFs/Example_Execution.gif)
