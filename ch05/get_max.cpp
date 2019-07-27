#include <iostream> 
  
template<class T1, class T2> 
auto get_max(T1 l, T2 r) 
{ 
     return (l > r) ? l : r; 
} 
  
template<class T, class... Trest> 
auto get_max(T l, Trest... r) 
{ 
     return get_max(l, get_max(r...)); 
} 
  
int main() 
{ 
     int i1 = 1, i2 = 2; 
     float f1 = 3, f2 = 4; 
  
     std::cout   << get_max(f1, i2) << '\t' 
                 << get_max(i1, i2) << '\t' 
                 << get_max(i1, i2, f1) << '\t' 
                 << get_max(i1, i2, f1, f2) << '\t' 
                 << std::endl; 
     return 0; 
} 