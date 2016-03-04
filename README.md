# Python to C++ Code Generator 

The idea for this program was taken from the book <b>"The Pragmatic Programmer" by Andy Hunt and Dave Thomas</b>

It gives an example of the way a program might take in a high-level language (Python) and generate the corresponding low-level code (C++)

<b>Example:</b>

<b>Input:</b>
```python
print "Hello World"
```

<b>Output:</b>
```CPP
#include <cstdio>

using namespace std;

int main()
{
    std::cout << "Hellow World" << std::endl;
}
```

----

The current python commands accepted as input are:
* Print function - is parsed into cout from the std library
* Comments - used to comment lines in the input
* Variables - will take variables as input
