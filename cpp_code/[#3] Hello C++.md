# Introduction
- Hello C++!
- Why C++?
- - popularity : Python >> R > C/C++
- - We want to be armed with various tools! for various situations
- Python(R)
- - Automation : easy -> dynamically typed, memory management // Inefficiency
- - Interpreted language : line by line to the computer... easy for debugging! // Slow Speed (interpretation each time...)
- - many libraries
- - Possible runtime error
- C/C++
- - Controllability : can optimize // hard, no garbage collection(?) 쓰레기 알아서 치워라
- - Compiled language : fast // less flexible -> machine specific compiling 실행 안될 수도
- Speed matters in Data Science!! And you can encounter situations where your own customized code is needed!
- You need to read C/C++ code
- Python(R) for prototyping and C/C++ for speed
- - See the python code "C++ vs Python.ipynb" for visualization

### Streams
- A stream is an entity whre a program can either inser or extract characters to/from
- - All we need to know is that:
        - Streams are a source/destination of charcters
        - These charcters are provided/accepted sequentially
- To get an entire line from cin, there exists a function, called getline, that takes the stream (cin) as the first argument, and a string variable as the second
>std::string myStr;
>getline(std::cin,myStr);
>std::cout << myStr;
- The standard header \<sstream> defines a type called stringstream that allows a string to be treated as a stream
- - Extraction/Insertion operations from/to strings in the same way as they are performed on cin and cout
- - Useful to convert strings to numerical values and vice versa
>string myStr "1204";
>int myInt;
>stringstream(myStr) >> myInt;
- - Extract the characters myStr and assign them to myInt as an integer value.

##### Now we know cin and cout. But... what we actually used are std::cin and std::cout. What is std::?
### Namespece
- Namespace :crate names and make them unique to a particular region of code
- - Global namespace is default
- - We can use names from other namespaces by using the scope operator in C++(:: )
- - - std is the namespace for C++ Standard Library
- - - std::cout is the name cout in the C++ Standard Library
>namespace myNamespace{
>   int a , b;
>}

#### Namespace - using
- The keyword using introduces a name into the current declarative region(such as a block), thus avoiding the need to qualify the name.
- The keyword using can also be used as a directive to introduce an entire namespace.
- It would be possible to first use the objects of one namespace and then those of another one by splitting the code in different blocks.
- Existing namespces can be aliased with new names, with the following syntax:
>namespace new_name = current_name;
- - See the 'using.cpp' code for details...

#### Namespace - The std namespace
- All the entities(variables, types, constants, and functions) of the standard C++ library are declared within the std namespce
- Many programmers prefer to qualify each of the elements of the standard library used in their programs

### More updates in C++
#### Default values in parameters
- Functions can also have optional parameters, for which no arguments are required in the call
- - See the 'updates.cpp' code for details...

#### Range-based for loop
- Range : A sequence of elements, including arrays, containers, and any other type supporting the functions begin and end
- The for-loop in C++ has another syntax, which is used exclusively with ranges:
>for(declaration:range) statement;
- - This kind of for loop iterates over all the elements in range, where declaration declares some variable able to take the value of an element in this range
- - Range based for loops usually also make use of type deduction for the type of the elements with auto