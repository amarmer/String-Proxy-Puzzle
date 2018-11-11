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

        if constexpr (sizeof(R) == 1)
            return !*cp;
        else
        {
          T chr_cmp = [](auto const& a)
          {
            if (a[0] == char{sizeof(a)})
                return R{};
            else
                return R{[](auto const&) -> decltype(R{}({})){ return{}; }};
          };
          return chr_cmp({*cp})==R{} && StringProxy<R>()==cp+1;
        }
      };
      return str_cmp(s);
    }
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
    char(*)(char const&) // EOS
  >
   () == "StringProxy", "");

int main() { return 0; }
