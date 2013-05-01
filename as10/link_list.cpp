#include <iostream>

using namespace std;

struct entry {
  int number;
  entry * next;
};

entry *add_num(entry *);
entry *delete_num(entry *);
void search_num(entry *);
void display(entry *);

int main(int argc, char * argv[]) {
  entry * lst_entry = 0;
  int choice;

  while (1) {
    cout << "Enter choice:\n(1) Add a number\n(2) Delete a number\n(3) Search"
	<< " for a number\n(4) Display list\n(5) Exit\n\n$ ";
    cin >> choice;
    switch(choice){
      case 1:
        lst_entry = add_num(lst_entry); break;
      case 2:
        if (lst_entry) lst_entry = delete_num(lst_entry);
        else cout << "Invalid chocie, must add num to delete" << endl;
        break;
      case 3:
        if (lst_entry) search_num(lst_entry);
        else cout << "Invalid chocie, must add num to search" << endl;
        break;
      case 4:
        display(lst_entry);
        break;
      case 5:
        cout << "Thank you for your input" << endl;
        return 0;
      default:
        cout << "Invalid input, ending program" << endl;
        return 1;
    }
  }
}


entry *add_num(entry * list)
{
  int num;
  entry *last, *head = list, *new_num;

  cout << "Enter number to add: ";
  cin >> num;

  //fist element to add
  if (list == 0) {
    list = new entry;
    list->number = num;
    list->next = 0;
    return list;
  }

  // allocate and populate
  new_num = new entry;
  new_num->number = num;
  new_num->next = 0;
  // already smallest num set new num's next to head
  // and return address of new num
  if (list->number > num) {
    new_num->next = head;
    return new_num;
  } else {
    // iterate through until holding the last number smaller in last
    // and the next number in list (which now looks like its not the best name)
    last = list;
    while(list->next && list->number < num) {
      last = list;
      list = list->next;
    }
    // point last to new_num, and new_num to lst
    if(!list->next) { //already at end
        if(list->number < num)// last number is smaller
            list->next = new_num;
        else {//last number is bigger so put it between second to last and last
            last->next = new_num;
            new_num->next = list;
        }
    }
    else {
        new_num->next = list->next;
        list->next = new_num;
    }
  }
  // should only happen if number was not first num in sequence
  return head;
}
entry *delete_num(entry * list)
{
    entry *head = list, *last;
    int num;

    cout << "Enter number to delete: ";
    cin >> num;

    // push head one forward and free first member of list
    if(list->number == num){
        head = head->next;
        free(list);
        return head;
    }
    last = head;
    while(1) {
        if (list->number == num) {
            last->next = list->next;
            cout << "Freeing " << list->number << endl << endl;
            free(list);
            break;
        }
        if (!list->next) {
            cout << "Number not found" << endl << endl;
            break;
        }
        list = list->next;
    }
    return head;
}
void search_num(entry * list)
{
  int find;

  cout << "Enter number to find: ";
  cin >> find;

  while(list->next) {
    if (list->number == find) {
      cout << "Number found!" << endl << endl;
      return;
    }
    list = list->next;
  }
  if (list->number == find)
      cout << "Number found!" << endl << endl;
  else
      cout << "Number was not found" << endl << endl;
}
void display(entry * list)
{
  int i = 0;
  while(list->next) {
    if (i++ % 5 == 0 ) cout << endl;

    cout << list->number << ", ";
    list = list->next;
  }
  cout << list->number << endl;
}
