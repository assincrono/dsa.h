## How to create a C++ library?
While implementing a Vector from scratch using C++, I thought about this, how are libraries implemented? So I decided to implement one for the data structures I'd be recreating from scratch, starting with a Vector. 

The first concept I ran into is _static_ vs _dynamic_ library. A static library is linked to the program at compile-time, whereas dynamic library is compiled at runtime. 

Then, I figured that implementing a C++ library is rather easy, all you need is to define a .h file containing the signatures of your library, so, for example, in my dsalib library, I have this class called SimpleVector, in my dsa.h I defined all of the signatures of this class:

~~~cpp
class SimpleVector {
private:
    int* arr;
    int capacity_val;
    int length;

    void resize(int new_capacity);

public:
    SimpleVector();
    ~SimpleVector();

    int size() const;
    int capacity() const;
    bool is_empty() const;

    void push(int item);
    void insert(int index, int item);
    void prepend(int item);

    int pop();
    void deleteAt(int index);
    void remove(int item);

    int at(int index) const;
    int find(int item) const;
};
~~~

Now, we just need to create a .cpp file with the implementation of this signature! Which I did into my simple_vector.cpp file. 

I tested it a little bit, and decided it would be cool to have automatic tests, so I used catch2 to test all of these methods into the simple_vector_test.cpp file. 

After this, I compiled my library using CMake, which made way easier than compiling by hand. It goes something like this:

~~~
cmake -B build
cmake --build build
./build/simple_vector_test
~~~

And there it is! A C++ library for data structures with automatic tests. Kinda cool. 
