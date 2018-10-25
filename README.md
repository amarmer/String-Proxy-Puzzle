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

static_assert(StringProxy<PUZZLE>() == "StringProxy", "");
                                                           
int main() { return 0; }
```
