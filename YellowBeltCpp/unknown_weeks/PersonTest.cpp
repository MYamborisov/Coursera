#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

template <class T>
ostream& operator << (ostream& os, const vector<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class T>
ostream& operator << (ostream& os, const set<T>& s) {
  os << "{";
  bool first = true;
  for (const auto& x : s) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << x;
  }
  return os << "}";
}

template <class K, class V>
ostream& operator << (ostream& os, const map<K, V>& m) {
  os << "{";
  bool first = true;
  for (const auto& kv : m) {
    if (!first) {
      os << ", ";
    }
    first = false;
    os << kv.first << ": " << kv.second;
  }
  return os << "}";
}

template<class T, class U>
void AssertEqual(const T& t, const U& u, const string& hint = {}) {
  if (t != u) {
    ostringstream os;
    os << "Assertion failed: " << t << " != " << u;
    if (!hint.empty()) {
      os << " hint: " << hint;
    }
    throw runtime_error(os.str());
  }
}

void AssertEqual(bool b, const string& hint) {
  AssertEqual(b, true, hint);
}

class TestRunner {
public:
  template <class TestFunc>
  void RunTest(TestFunc func, const string& test_name) {
    try {
      func();
      cerr << test_name << " OK" << endl;
    } catch (exception& e) {
      ++fail_count;
      cerr << test_name << " fail: " << e.what() << endl;
    } catch (...) {
      ++fail_count;
      cerr << "Unknown exception caught" << endl;
    }
  }

  ~TestRunner() {
    if (fail_count > 0) {
      cerr << fail_count << " unit tests failed. Terminate" << endl;
      exit(1);
    }
  }

private:
  int fail_count = 0;
};

class Person {
public:
  // Р’С‹ РјРѕР¶РµС‚Рµ РІСЃС‚Р°РІР»СЏС‚СЊ СЃСЋРґР° СЂР°Р·Р»РёС‡РЅС‹Рµ СЂРµР°Р»РёР·Р°С†РёРё РєР»Р°СЃСЃР°,
  // С‡С‚РѕР±С‹ РїСЂРѕРІРµСЂРёС‚СЊ, С‡С‚Рѕ РІР°С€Рё С‚РµСЃС‚С‹ РїСЂРѕРїСѓСЃРєР°СЋС‚ РєРѕСЂСЂРµРєС‚РЅС‹Р№ РєРѕРґ
  // Рё Р»РѕРІСЏС‚ РЅРµРєРѕСЂСЂРµРєС‚РЅС‹Р№
  void ChangeFirstName(int year, const string& first_name) {
  }
  void ChangeLastName(int year, const string& last_name) {
  }
  string GetFullName(int year) {
  }
};

void AllTest1() {
    Person p;
    AssertEqual(p.GetFullName(1763), "Incognito", "hint1");
    p.ChangeFirstName(1764, "name1");
    AssertEqual(p.GetFullName(1763), "Incognito", "hint1");
    AssertEqual(p.GetFullName(1764), "name1 with unknown last name", "hint1");
    AssertEqual(p.GetFullName(1765), "name1 with unknown last name", "hint1");
    p.ChangeLastName(1800, "last1");
    AssertEqual(p.GetFullName(1763), "Incognito", "hint1");
    AssertEqual(p.GetFullName(1764), "name1 with unknown last name", "hint1");
    AssertEqual(p.GetFullName(1765), "name1 with unknown last name", "hint1");
    AssertEqual(p.GetFullName(1799), "name1 with unknown last name", "hint1");
    AssertEqual(p.GetFullName(1800), "name1 last1", "hint1");
    AssertEqual(p.GetFullName(1815), "name1 last1", "hint1");
    p.ChangeLastName(1830, "last2");
    AssertEqual(p.GetFullName(1829), "name1 last1", "hint1");
    AssertEqual(p.GetFullName(1830), "name1 last2", "hint1");
    AssertEqual(p.GetFullName(1835), "name1 last2", "hint1");
    p.ChangeFirstName(1840, "name2");
    AssertEqual(p.GetFullName(1839), "name1 last2", "hint1");
    AssertEqual(p.GetFullName(1840), "name2 last2", "hint1");
    AssertEqual(p.GetFullName(1845), "name2 last2", "hint1");
    AssertEqual(p.GetFullName(1763), "Incognito", "hint1");
}

void AllTest2() {
    Person p;
    AssertEqual(p.GetFullName(1763), "Incognito", "hint1");
    p.ChangeLastName(1764, "name1");
    AssertEqual(p.GetFullName(1763), "Incognito", "hint1");
    AssertEqual(p.GetFullName(1764), "name1 with unknown first name", "hint1");
    AssertEqual(p.GetFullName(1765), "name1 with unknown first name", "hint1");
    p.ChangeFirstName(1800, "last1");
    AssertEqual(p.GetFullName(1763), "Incognito", "hint1");
    AssertEqual(p.GetFullName(1764), "name1 with unknown first name", "hint1");
    AssertEqual(p.GetFullName(1765), "name1 with unknown first name", "hint1");
    AssertEqual(p.GetFullName(1799), "name1 with unknown first name", "hint1");
    AssertEqual(p.GetFullName(1800), "last1 name1", "hint1");
    AssertEqual(p.GetFullName(1815), "last1 name1", "hint1");
    p.ChangeLastName(1830, "last2");
    AssertEqual(p.GetFullName(1829), "last1 name1", "hint1");
    AssertEqual(p.GetFullName(1830), "last1 last2", "hint1");
    AssertEqual(p.GetFullName(1835), "last1 last2", "hint1");
    p.ChangeFirstName(1840, "name2");
    AssertEqual(p.GetFullName(1839), "last1 last2", "hint1");
    AssertEqual(p.GetFullName(1840), "name2 last2", "hint1");
    AssertEqual(p.GetFullName(1845), "name2 last2", "hint1");
    AssertEqual(p.GetFullName(1763), "Incognito", "hint1");
}

int main() {
  TestRunner runner;
  runner.RunTest(AllTest1, "AllTest1");
  runner.RunTest(AllTest2, "AllTest2");
  return 0;
}