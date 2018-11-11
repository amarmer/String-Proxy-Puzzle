
template <typename T>
constexpr auto StringProxy()
{
  struct Aux
  {
    constexpr bool operator == (const char* s)
    {
      auto compare = [&s](auto compare, auto* pArr)
      {
        if constexpr (1 == sizeof(*pArr))
          return !*s;
        else
          return (*s++ == sizeof(*pArr)/sizeof(void*)) ? compare(compare, (decltype(**pArr + 0))nullptr) : false;
      };
            
      return compare(compare, (T)nullptr);
    }
  };
    
  return Aux();
}

static_assert(StringProxy<char* (*(*(*(*(*(*(*(*(*(*(*)['S'])['t'])['r'])['i'])['n'])['g'])['P'])['r'])['o'])['x'])['y']>() 
              == "StringProxy");
static_assert(StringProxy<char*>() == "");

int main() { return 0; }
