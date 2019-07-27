#include <iostream> 
#include <string> 
#include <cstring> 
#include <vector> 
  
template<typename T, size_t size> 
class SmartArray 
{ 
public: 
     explicit SmartArray(const T (&arr)[size])        // size is known at compile time, referred from actual argument array 
     { 
         std::memcpy(m_arr, arr, size * sizeof(T)); 
     } 
     
     std::string toString() const 
     { 
         std::string res; 
         for(auto val: m_arr) 
             res += std::to_string(val) + "\t"; 
         return res; 
     } 
     
private: 
     T m_arr[size]; 
}; 

template<size_t size> 
class SmartArray<std::string, size> 
{ 
public: 
     explicit SmartArray(const std::string (&arr)[size]) 
     { 
         for(const auto& str: arr) 
             m_arr.push_back(str); 
     } 
     
     std::string toString() const 
     { 
         std::string res; 
         for(auto val: m_arr) 
             res += val + "\t"; 
         return res; 
     } 
     
private: 
     std::vector<std::string> m_arr; 
}; 

int main() 
{ 
     int numbers[] = {2, 0, 1, 9}; 
     SmartArray smart_numbers{numbers}; 
  
     char letters[] = {'h', 'e', 'l', 'l', 'o'}; 
     SmartArray smart_letters{letters}; 
  
     std::string strings[] = {"hello", "world", "!"}; 
     SmartArray smart_strings{strings}; 
  
     std::cout << smart_letters.toString() << std::endl << smart_numbers.toString() << std::endl << smart_strings.toString() << std::endl; 

 
     return 0; 
} 