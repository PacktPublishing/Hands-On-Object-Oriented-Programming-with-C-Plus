#include <iostream> 
#include <vector> 
#include <string> 
#include <numeric> 
#include <iterator> 
#include <functional> 
  
template<typename T, typename Derived> 
class FilteredContainerBase 
{ 
public: 
     std::string toString() const 
     { 
         return std::accumulate(std::next(m_vec.begin()), m_vec.end(), std::to_string(m_vec.front()), 
                 [](const std::string& acc, int val) 
                 { return acc + ", " + std::to_string(val); }) + '\n'; 
     } 
     
public: 
     FilteredContainerBase(const std::vector<T>& vec) 
     { 
         for(T val : vec) 
         { 
             if(static_cast<Derived*>(this)->isIncluded(val)) 
                 m_vec.push_back(val); 
         } 
     }; 
     
private: 
     std::vector<T> m_vec; 
}; 
  
class EvenIntContainer: public FilteredContainerBase<int, EvenIntContainer> 
{ 
private: 
     using my_base = FilteredContainerBase<int, EvenIntContainer>; 
     friend my_base; 
     static bool isIncluded(int val) { return (val % 2) == 0; } 
public: 
     using my_base::FilteredContainerBase; 
}; 
  
class OddIntContainer: public FilteredContainerBase<int, OddIntContainer> 
{ 
private: 
     using my_base = FilteredContainerBase<int, OddIntContainer>; 
     friend my_base; 
     static bool isIncluded(int val) { return (val % 2) != 0; } 
public: 
     using my_base::FilteredContainerBase; 
}; 
  
template<typename... Args> 
void display(Args... args) 
{ 
     (std::cout << ... << args.toString()); 
} 
  
int main() 
{ 
     std::vector<int> numbers(10); 
     std::iota(numbers.begin(), numbers.end(), 1); 
     
     EvenIntContainer even{numbers}; 
     OddIntContainer odd{numbers}; 
     
     display(odd, even); 
} 