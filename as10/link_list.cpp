#include <iostream>

using namespace std;

struct entry {
  int number;
  entry * next;
};

entry *add_num(entry *);
void delete_num(entry *);
void search_num(entry *);
void display(entry *);

int main(int argc, char * argv[]) {
  entry * lst_entry = 0;
  int choice;

  while (1) {
    cout << "Enter choice:\n(1) Add a number\n(2) Delete a number\n(3) Search"
	<< " for a number\n(4) Display list\n\n$ ";
    cin >> choice;
    switch(choice){
      case 1:
        lst_entry = add_num(lst_entry); break;
      case 2:
        if (lst_entry) delete_num(lst_entry);
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


entry *add_num(entry * lst)
{
  int num;
  entry last, *head = lst, *new_num;

  cout << "Enter number to add: ";
  cin >> num; 

  //fist element to add
  if (lst == 0) { 
    lst = new entry;
    lst->number = num;
    lst->next = 0;
    return lst;
  } 

  // allocate and populate
  new_num = new entry;
  new_num->number = num;
  // already smallest num set new num's next to head
  // and return address of new num
  if (lst->number > num) {
    new_num->next = head;
    return new_num;
  } else { 
    // itierate through until holding the last number smaller in last
    // and the next number in lst (which now looks like its not the best name
    while(lst->next && lst->number < num) {
      last = *lst;
      lst = lst->next; 
    }
    // point last to new_num, and new_num to lst
    last.next = new_num;
    new_num->next = lst;
  }
  // should only happen if number was not first num in sequence
  return head; 
}
void delete_num(entry * lst)
{

}
void search_num(entry * lst)
{
  int find;

  cout << "Enter number to find: ";
  cin >> find;

  while(lst->next) {
    if (lst->number == find) {
      cout << "Number found!" << endl;
      return;
    }
    lst = lst->next;
  }
}
void display(entry * lst)
{
  int i = 0;
  while(lst->next) {
    if (++i % 5 == 0 ) cout << endl;

    cout << lst->number << ", ";
    lst = lst->next;
  }
  cout << endl;
}
