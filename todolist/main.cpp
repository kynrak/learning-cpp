#include "item.h"
#include <string>
int main(int argc, char *argv[]) {
  ToDoList todoList;

  if (argc == 1) {
    todoList.displayItems();
  } else if (argc >= 2) {
    std::string flag = argv[1];
    if (flag == "-a" && argc >= 3) {
      std::string title = argv[2];
      todoList.addItem(title);
    } else if (flag == "-d" && argc >= 3) {
      int id = std::stoi(argv[2]);
      todoList.deleteItem(id);
    }
  }

  return 0;
}
