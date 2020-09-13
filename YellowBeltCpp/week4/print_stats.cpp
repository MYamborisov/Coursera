#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

// enum class Gender {
//   FEMALE,
//   MALE
// };

// struct Person {
//   int age;  // возраст
//   Gender gender;  // пол
//   bool is_employed;  // имеет ли работу
// };

// template <typename InputIt>
// int ComputeMedianAge(InputIt range_begin, InputIt range_end) {
//   if (range_begin == range_end) {
//     return 0;
//   }
//   vector<typename InputIt::value_type> range_copy(range_begin, range_end);
//   auto middle = begin(range_copy) + range_copy.size() / 2;
//   nth_element(
//       begin(range_copy), middle, end(range_copy),
//       [](const Person& lhs, const Person& rhs) {
//         return lhs.age < rhs.age;
//       }
//   );
//   return middle->age;
// }

void PrintStats(vector<Person> persons) {
    cout << "Median age = " << ComputeMedianAge(persons.begin(), persons.end()) << endl;
    auto it1 = partition(persons.begin(), persons.end(), [](Person el){return el.gender == Gender::FEMALE;});
    cout << "Median age for females = " << ComputeMedianAge(persons.begin(), it1) << endl;
    auto it2 = partition(persons.begin(), persons.end(), [](Person el){return el.gender == Gender::MALE;});
    cout << "Median age for males = " << ComputeMedianAge(persons.begin(), it2) << endl;
    auto it3 = partition(persons.begin(), persons.end(), [](Person el){return (el.gender == Gender::FEMALE && el.is_employed);});
    cout << "Median age for employed females = " << ComputeMedianAge(persons.begin(), it3) << endl;
    auto it4 = partition(persons.begin(), persons.end(), [](Person el){return (el.gender == Gender::FEMALE && !el.is_employed);});
    cout << "Median age for unemployed females = " << ComputeMedianAge(persons.begin(), it4) << endl;
    auto it5 = partition(persons.begin(), persons.end(), [](Person el){return (el.gender == Gender::MALE && el.is_employed);});
    cout << "Median age for employed males = " << ComputeMedianAge(persons.begin(), it5) << endl;
    auto it6 = partition(persons.begin(), persons.end(), [](Person el){return (el.gender == Gender::MALE && !el.is_employed);});
    cout << "Median age for unemployed males = " << ComputeMedianAge(persons.begin(), it6) << endl;
}

// int main() {
//   vector<Person> persons = {
//       {31, Gender::MALE, false},
//       {40, Gender::FEMALE, true},
//       {24, Gender::MALE, true},
//       {20, Gender::FEMALE, true},
//       {80, Gender::FEMALE, false},
//       {78, Gender::MALE, false},
//       {10, Gender::FEMALE, false},
//       {55, Gender::MALE, true},
//   };
//   PrintStats(persons);
//   return 0;
// }
