template <typename T> 
constexpr auto StringProxy()
{
  struct proxy
  {
    constexpr bool operator==(char const* s)
    {
      constexpr auto str_cmp = [](char const* cp) -> bool
      {
        using R = decltype(T{}({}));

        constexpr T chr_cmp = [](auto const& a)
        {
          if (a[0] == char{sizeof(a) & 0xFF})
              return R{nullptr};
          else
              return R{[](auto const&)
                       ->decltype(R{}({})){return{};}};
        };
    
        if (chr_cmp({*cp}) == R{nullptr})
            return StringProxy<R>() == cp+1;
        else
            return false;
      };
      return str_cmp(s);
    }
  };
  return proxy{};
}

// Bending the rules with a specialization to terminate recursion
template <> 
constexpr auto StringProxy<void*(*)(char const(&)[0x100])>() // EOS
{
  struct proxy
  {
    constexpr bool operator==(char const* s) { return *s=='\0'; }
  };
  return proxy{};
}

static_assert(
  StringProxy
  <
    auto(*)(char const(&)['S'])->
    auto(*)(char const(&)['t'])->
    auto(*)(char const(&)['r'])->
    auto(*)(char const(&)['i'])->
    auto(*)(char const(&)['n'])->
    auto(*)(char const(&)['g'])->
    auto(*)(char const(&)['P'])->
    auto(*)(char const(&)['r'])->
    auto(*)(char const(&)['o'])->
    auto(*)(char const(&)['x'])->
    auto(*)(char const(&)['y'])->
    void*(*)(char const(&)[0x100]) // EOS
  >
   () == "StringProxy", "");

int main() { return 0; }
