## Introduction

On my studies of data structures and algorithms, I am following the <a href="">Coding Interview University Roadmap</a>, and I have been playing around C++ at Codeforces for a while, so I figured why not implement the common data structures into a C++ library? 

#### Features
* Vectors (done)
* Linked Lists (done)
* Stack (backlog)
* Hash table (backlog)

#### Build

I am using CMake to build the library, because building manually in C++ is hell. This is the workflow:

~~~
cmake -B build
cmake --build build
./build/simple_vector_test
~~~


