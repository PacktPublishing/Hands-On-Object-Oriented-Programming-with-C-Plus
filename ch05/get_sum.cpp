#include <iostream> 
#include <algorithm> 
  
template<class Tbase = int, Tbase base = (Tbase)0> 
class get_based_sum 
{ 
public: 
     template<class ...T> 
     auto operator() (T... args) 
     { 
         return (base + ... + args); 
     } 
}; 

template<class ...T> 
auto get_sum(T... args) 
{ 
     return (... + args); 
} 

template<class Tbase = int, Tbase base = (Tbase)1> 
class get_factored_sum 
{ 
public: 
     template<class ...T> 
     auto operator() (T... args) 
     { 
         return (base * get_sum(args...)); 
     } 
}; 

int main() 
{ 
     std::cout   << get_sum(1, 2) << '\t' 
                 << get_sum(1, 2, 3) << '\t' 
                 << get_sum(1, 2, 3, 4) << '\t' 
                 << get_based_sum<char, 8>{}(1, 2, 3, 4, 5) << '\t' 
                 << get_factored_sum<short, 4>{}(1, 2, 3, 4, 5) << '\t' 
                 << std::endl; 
     return 0; 
} 