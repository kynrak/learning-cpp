#include "item.h"
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

// following the interface defined in the .h file

// constructor of the todo list, setting to nullptr intializes an empty list
ToDoList::ToDoList() : head(nullptr), currentId(1) { loadFromFile(); }

// destructer of the todo list, removes the entire thing
ToDoList::~ToDoList() {
  saveToFile();
  // this deletes each item at a time through a while loop
  while (head) {
    ToDoItem *temp = head;
    head = head->next;
    delete temp;
  }
}

// define the functions to be used

/*
 * addItem adds an item to the linked list
 *
 * @param title Title of the todo list to be saved
 * @param id Optional id parameter to set the id of the item if exists
 * @return void
 */
void ToDoList::addItem(const std::string &title, int id) {
  // create the new item pointer based on the new id and the title
  // if id param exists, use it, otherwise iterate current id
  // problem now is that it currentId is always 1, why ?
  int newId;
  if (id != 0) {
    newId = id;
  } else {
    newId = currentId++;
  }
  ToDoItem *newItem = new ToDoItem{newId, title, nullptr};

  if (!head) {
    // if its the first item in the list, set the first item in the list to the
    // new item
    head = newItem;
  } else {
    // if it is not the first item in the list, traverse to the last item
    // and set the last item next pointer to the new item
    ToDoItem *temp = head;
    while (temp->next) {
      temp = temp->next;
    }

    temp->next = newItem;
  }
}

/*
 * deleteItem deletes an item in the linked list based on their id
 *
 * @param The id of the target item to be deleted
 * @return void
 */
void ToDoList::deleteItem(int id) {
  // if the list is empty
  if (!head) {
    std::cout << "The list is empty, there is nothing to delete" << "\n";
    return;
  }

  // if the item to be delted is the first item
  if (head->id == id) {
    ToDoItem *temp = head;
    head = head->next;
    delete temp;
    return;
  }

  // traverse the linked list and find the id
  ToDoItem *current = head;
  while (current->next && current->next->id != id) {
    current = current->next;
  }

  // if the item is found, delete it
  if (current->next) {
    ToDoItem *temp = current->next;
    current->next = current->next->next;
    delete temp;
  }
}

/*
 * displayItems shows all the current item in the list
 */
void ToDoList::displayItems() const {
  if (!head) {
    std::cout << "The list is empty" << "\n";
    return;
  }

  ToDoItem *temp = head;
  while (temp) {
    std::cout << temp->id << ": " << temp->title << "\n";
    temp = temp->next;
  }
}

/*
 * saveToFile ensures persistent storage is being used e.g. a text file in this
 * case
 */
void ToDoList::saveToFile() {
  std::ofstream file("list.txt");
  if (!file) {
    std::cerr
        << "Error opening file for writing. File may not have been created \n";
    return;
  }

  ToDoItem *temp = head;
  while (temp) {
    file << temp->id << "," << temp->title << "\n";
    temp = temp->next;
  }

  file.close();
}

/*
 * loadFromFile grabs all the text from the list file and keep it in memory
 */
void ToDoList::loadFromFile() {
  std::ifstream file("list.txt");
  if (!file) {
    std::cerr << "Error opening file for reading \n";
    return;
  }

  std::string line;
  while (std::getline(file, line)) {
    std::istringstream iss(line);
    int id;
    std::string title;

    if (std::getline(iss, line, ',')) {
      id = std::stoi(line);     // Read the ID
      std::getline(iss, title); // Read the title

      if (id >= currentId) {
        currentId = id + 1;
      }
      // Create a new item and add it to the list using the existing addItem
      // function
      ToDoItem *newItem = new ToDoItem{id, title, nullptr};
      addItem(title, id);
    }
  }

  file.close();
}
