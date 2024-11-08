// checks if this interface is defined, if not it will proceed to
// define it
#ifndef ITEM_H
#define ITEM_H

#include <string>

struct ToDoItem {
  int id;
  std::string title;
  ToDoItem *next;
};

class ToDoList {
private:
  ToDoItem *head;
  int currentId;
  void saveToFile();
  void loadFromFile();

public:
  ToDoList();
  ~ToDoList();
  void addItem(const std::string &title);
  void deleteItem(int id);
  void displayItems() const;
};

#endif // ensure that the conditional statement has an end
