#include <string>
#include <iostream>

class Student {
private:
  std::string firstName;
  std::string lastName;
  int grade;
public:
  std::string getFirstName(){
    return firstName;
  }

  void setFirstName(std::string name){
    firstName = name;
  }

  std::string getLastName(){
    return lastName;
  }

  void setLastName(std::string name){
    lastName = name;
  }

  int getGrade(){
    return grade;
  }

  void setGrade(int gr){
    grade = gr;
  }

  std::string getWholeName(){
    return firstName + " " + lastName;
  }

  // the set name function is overload
  void setName(std::string firstName){
    this->firstName = firstName;
  }

  void setName(std::string firstName, std::string lastName){
    this->firstName = firstName;
    this->lastName = lastName;
  }

  // Since the parameters names are not used to create the function signature, 
  // so this function is identical to the one above and we get a redefinition error 
  // void setName(std::string lastName, std::string firstName){
  // this->lastName = lastName;
  // this->firstName = firstName;
  // }

  void setNameAndGrade(std::string firstName, int grade){
    this->firstName = firstName;
    this->grade = grade;
  }

  void setNameAndGrade(int grade, std::string firstName){
    this->grade = grade;
    this->firstName = firstName;
  }
};

// a simple function to add two ints
int add(int value1, int value2){
  return value1 + value2;
}

// this function adds two doubles, so it can have the same name
double add(double value1, double value2){
  return value1 + value2;
}

int multiply(int a, int b) {
  std::cout << "multiply(int a, int b )\n";
  return a * b;
}

// int and unsigned are different types so this is legal, 
int multiply(unsigned a, unsigned b) {
  std::cout << "multiply(unsigned a, unsigned b )\n";
  return a * b;
}

double multiply(double a, double b) {
  std::cout << "multiply(double a, double b)\n";
  return a * b;
}

double multiply(int a, double b) {
  std::cout << "multiply(int a, double b)\n";
  return a * b;
}

double multiply(double a, int b) {
  std::cout << "multiply(double a, int b)\n";
  return a * b;
}

void setName(std::string firstName){
  std::cout << "My name is " << firstName << std::endl;
}

namespace School {
  void setName(std::string firstName) {
    std::cout << "School - My name is " << firstName << std::endl;
  }
}

int main() {
  std::cout << "5 + 2 = " << add(5,3) << std::endl;
  std::cout << "4.2 + 8.6 = " << add(4.2, 8.6) << std::endl;

  auto total1 = multiply(10, 5);
  auto total2 = multiply(15.2, 20.3);
  auto total3 = multiply(5, 25.42);
  auto total4 = multiply(30.51, 10);

  auto student1 = Student();
  student1.setName("Alan");
  student1.setName("Alan", "Turing");
  student1.setGrade(10);
  std::cout << "The student " << student1.getWholeName();
  std::cout << " is in grade " << student1.getGrade() << "."<< std::endl;

  setName("Charles");
  School::setName("Douglas");

  return 0;
}