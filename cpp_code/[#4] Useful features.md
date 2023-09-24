# More features in C++

## 
##### Let's start with C language

- Call by value vs. Call by reference
  
> void swap(int x, int y){ \
    int temp = x; \
    x = y; \
    y = temp; \
}

- This function will not swap the values of the variables! It's because the variables x and y are local to the 'swap' function.
- To deal with this problem we learned the concept "call by reference".
  
> void swap(int* x, int* y){ \
    int temp = *x; \
    *x = *y; \
    *y = temp; \
}

##
###
##### However, with C++ it is not necessary to declare and assign pointers for call-by-reference!!!

> void swap(int &x,int &y){ \
    int temp = x; \
    x = y; \
    y = temp; \
}

- The only difference is '&' in front of the parameter names in the header.
- - No dereferencing!(*x)
- - When calling the function the parameters are: the original variables(x not &x)
- That is '&' means "call-by-reference".
- - Zero additional variable
- Advantage : If a parameter needs to be a reference, we only need to change the function itself and not the places it is called
- - Sounds like 'class' in Python...

### const References

- Comparing call-by-value and call-by-reference, we observe that the latter is dangerous but memory efficient. 
- const Reference is a mixed concept of the two -> If you want only to read the value but efficiently, then use const Reference !

### One step further...
##### We want to implement swap function not only for integers but also doubles and charcters...
##### C-style implementation is:

> void swap_int(int &x, int &y){ \
    int temp = x; \
    x = y; \
    y = temp; \
} \
void swap_double(double &x, double &y){ \
    double temp = x; \
    x = y; \
    y = temp; \
} \
void swap_char(char &x, char &y){ \
    char temp = x; \
    x = y; \
    y = temp; \
}

- Three different swaps with three different names
  
### Function Overloading
##### With C++ we don't neet to remember all the names!

> void swap(int &x, int &y){ \
    int temp = x; \
    x = y; \
    y = temp; \
} \
void swap(double &x, double &y){ \
    double temp = x; \
    x = y; \
    y = temp; \
}\
void swap(char &x, char &y){ \
    char temp = x; \
    x = y; \
    y = temp; \
}

- Three different swaps with a single name
  
##### However, there are still three different versions of swap.
### Function Templates

> template \<class T> \
void mySwap(T &x,T &y){ \
    T temp = x; \
    x = y; \
    y = temp; \
} \
int main(void){ \
    int intA = 10, intB = 20; \
    double doubleA = 10.15, doubleB = 20.25; \
    char charA = 'a', charB = 'b'; \
    using namespace std; \
    cout <<" A: " << intA << "\t B: " << intB << endl; \
    mySwap\<int>(intA,intB); \
    cout <<" A: " << intA << "\t B: " << intB << endl; \
    ... \
}

- For instantiating we specify the type in \<...>
  
#### Automatinc typ deduction

- Calling operation became a bit more complex. So, C++ also provides "automatic type deduction".
  
#### Non-type template arguments

>template\<class T, int N> \
T fixed_multiply(T val){ \
    return val*N; \
}

- A non-type template argument provided within a template argument list is an expression whose value can be determined at complie time
- One application is to use it for the size of data(ex. Array size)-> reduce overhead for the dynamic allocation(?)