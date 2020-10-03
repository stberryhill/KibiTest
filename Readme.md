# KibiTest 
*A minimal, single-header C89 testing framework in under a Kibibyte.*

![logo](https://github.com/stberryhill/KibiTest/blob/master/Media/Kibi_Logo.png)

* There are three main functions: **Kibi_Test**, **Kibi_AssertTrue**, and **Kibi_AssertFalse**. Optionally specify setup/teardown functions to be called before and after each test with **Kibi_ForEach**.
* Pass the desired test function into Kibi_Test to run it (must have no parameters).
* Simply include the header file - no linking necessary.

## Example
### Usage
![gif-showing-example-code](https://github.com/stberryhill/KibiTest/blob/master/Media/Example_Source.gif)
### Output
![gif-showing-example-output](https://github.com/stberryhill/KibiTest/blob/master/Media/Example_Execution.gif)
