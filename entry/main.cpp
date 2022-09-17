#include "List.h"
#include <iostream>
#include "../tests/tests_helper.h"

int main() {
    List<int> list;

    for (int i = 1; i <= 6; i++)
        list.insertBack(i);

    list.tripleRotate();

    stringstream s;

    list.print(s);
  std::cout << s.str() << std::endl;

  return 0;
}
