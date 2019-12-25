#include <type_traits>
#include <utility>

template <typename T> 
constexpr auto StringProxy()
{
  struct SP
  {
      char str[std::rank_v<T>];
      constexpr bool operator==(char const* cp)
      {
          for (unsigned i=0; i!=std::rank_v<T> && (str[i]==*cp || !*cp); ++i, ++cp)
              if (!*cp) return false;
          return !*cp;
      }
  };
  return []<std::size_t... i>(std::index_sequence<i...>){
    return SP{char(std::extent_v<T,i>)...};
  }(std::make_index_sequence<std::rank_v<T>>{});
}

static_assert(StringProxy<char['S']['t']['r']['i']['n']['g']>() == "String", "");
                                                           
int main() { return 0; }
