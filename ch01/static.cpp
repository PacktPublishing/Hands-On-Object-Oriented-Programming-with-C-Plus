#include <string>
#include <iostream>

class Student {
private:
 std::string firstName;
 std::string lastName;
 int grade;
public:
 static int count;
 const static int MaxGrade = 12;

 Student() {
     ++Student::count;
 }

 ~Student(){
     --Student::count;
 }

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

 static void showCount() {
     std::cout << "There are " << Student::count << " student(s) in the school\n";
 }
};

int Student::count = 0;

int main() {
 Student::showCount();
 auto student1 = Student();
 student1.setFirstName("Ada");
 student1.setLastName("Lovelace");
 student1.setGrade(12);
 Student::showCount();

 {
     auto student2 = Student();
     student2.setFirstName("Charles");
     student2.setLastName("Babbage");
     student2.setGrade(12);
     Student::showCount();
 }

 std::cout << "The student " << student1.getWholeName();
 std::cout << " is in grade " << student1.getGrade() << "."<< std::endl;
 Student::showCount();
 return 0;
}