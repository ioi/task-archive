# Notice

Each task has an attachment package that is available both in CMS and on your desktop.

* The attachment package contains sample graders, sample implementations, example test cases, and compile scripts.
* You have to submit exactly one file, and you may make up to 50 submissions.
* Your submissions must not read from the standard input, print to the standard output or interact with any other file.
However, they may output to the standard error stream.
* The name of the file that you should submit is given in the task statement header.
It should implement the procedures described in the task statement using the signatures provided in the sample implementations.
* You are free to implement other procedures.
* When testing your programs with the sample grader,
your input should match the format and constraints from the task statement, otherwise, unspecified behaviors may occur.

## Conventions

The task statements specify signatures using generic type names  `bool`, `int`, `int64`, and `int[]` (array).

In each of the supported programming languages, the graders use appropriate data types or implementations, as listed below:

Language | `bool` | `int` | `int64` |  `int[]` | length of array `a`
--- | --- | --- | --- | ---
C++ | `bool` | `int` | `long long` | `std::vector<int>` | `a.size()`
Pascal | `boolean` | `longint` |  `int64` |  `array of longint` | `Length(a)`
Java | `boolean` | `int` | `long` |  `int[]` | `a.length`

## Limits

Task | Time limit | Memory limit
--- | --- | ---
prize | 1 sec | 1024 MB
simurgh | 3 sec | 1024 MB
books | 2 sec | 1024 MB

<div style="margin-top:-1em"></div>