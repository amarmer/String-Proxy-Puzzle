template <typename T> 
constexpr auto StringProxy()
{
  struct proxy
  {
    constexpr bool operator==(char const* s)
    {
      T* scmp = []<char... c>(char const* s,
                              void(*)(char (&...a)[c]))
      {
          return ((*s++==c) && ...) && !*s;
      };
      return (*scmp)(s,0);
    }
  };
  return proxy{};
}

static_assert(
StringProxy<
  bool(
    char const *,
    void(*)(
      char (&)['S'],
      char (&)['t'],
      char (&)['r'],
      char (&)['i'],
      char (&)['n'],
      char (&)['g'],
      char (&)['P'],
      char (&)['r'],
      char (&)['o'],
      char (&)['x'],
      char (&)['y']

    )
  )
>() == "StringProxy", "");
                                                           
int main() { return 0; }
