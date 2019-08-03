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
     auto test = [](const auto& vals) 
     { 
        SmartArray smart_vals{vals}; 
        std::cout << smart_vals.toString() << std::endl; 
     }; 

     auto test_multiple = [&test](const auto&... vals) 
     { 
         (test(vals), ...);
     }; 

     int numbers[] = {2, 0, 1, 9};  
     char letters[] = {'h', 'e', 'l', 'l', 'o'};  
     std::string strings[] = {"hello", "world", "!"};  

     test_multiple(numbers, letters, strings); 

     return 0;  
} 