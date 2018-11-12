### String Proxy Puzzle

C-style string cannot be used as a template parameter (X<"abc">() won't compile).
</br>It is possible for any C-style string to use it's proxy as a template parameter and reconstruct the compile-time string from it.
Program below demonstrates it. Code can be modified only in the places where `PUZZLE` is.

```C++
// No headers

template <typename T> 
constexpr auto StringProxy()
{
  PUZZLE 
}

static_assert(StringProxy<PUZZLE>() == "StringProxy");
                                                           
int main() { return 0; }
```

#### There are 2 solutions (compile on Clang and GCC C++17): [solution](https://github.com/amarmer/String-Proxy-Puzzle/blob/master/Solution.cpp) and [solution](https://github.com/amarmer/String-Proxy-Puzzle/blob/888f16926c583115bee57dc2f874c4e825214ea2/recursive_function_array_extents.cpp).
