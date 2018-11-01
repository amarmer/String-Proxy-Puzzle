template <typename T> 
constexpr auto StringProxy()
{
  constexpr auto const& pf = __PRETTY_FUNCTION__;
  constexpr auto prefix = sizeof("constexpr auto StringProxy() [with T =");
  constexpr auto size = sizeof(pf) - (prefix + 2);

  struct SP
  {
      char str[size];
      constexpr bool operator==(char const* cp)
      {
          for (unsigned i=0; i!=size && (str[i]==*cp || !*cp); ++i, ++cp)
              if (!*cp) return false;
          return !*cp;
      }
  };

  SP ret{};
  for (unsigned i = 0; i != size; ++i)
      ret.str[i] = pf[prefix+i];
  return ret;
}

static_assert(StringProxy<struct StringProxy>() == "StringProxy", "");

int main() { return 0; }
