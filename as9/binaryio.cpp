//  Inventory Program
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
using namespace std;

// Constant for array sizes
const int DESC_SIZE = 31;
const int DATE_SIZE = 11;

// Declaration of Inventory structure
struct Inventory
{
   char desc[DESC_SIZE];  // Description
   int qty;               // Quantity
   double wholeSale;      // Wholesale cost
   double retail;         // Retail price
   char date[DATE_SIZE];  // Date added to inventory
};

// Function prototypes
void clear(fstream &);
void addRecord(fstream &);
void viewRecord(fstream &);
void changeRecord(fstream &);
void searchbyname(fstream &);
void display(fstream &);
void report(fstream &);
void add_from_text(fstream &, fstream &);

int main()
{
   // File stream object
   fstream inventoryFile;
   fstream textFile;

   // User's menu choice
   int choice;

   clear(inventoryFile);

   // Display the menu and process the
   // user's request.
   do
   {
      // Display the menu.
      cout << "\n1. Add a new record\n";
      cout << "2. View an existing record\n";
      cout << "3. Change an existing record\n";
      cout << "4. Search the file by item name\n";
      cout << "5. Display records\n";
      cout << "6. Report\n";
      cout << "7. Add from text file\n";
      cout << "8. Exit\n\n";

      // Get the user's menu selection.
      cout << "Enter your choice (1-7): ";
      cin >> choice;

      // Validate the menu selection.
      while (choice < 1 || choice > 8)
      {
         cout << "ERROR. Enter 1, 2, 3, 4, 5, 6, 7 or 8: ";
         cin >> choice;
      }

      // Process the selection.
      switch (choice)
      {
         // Choice 1 is to add a record.
         case 1:
            addRecord(inventoryFile);
            break;

         // Choice 2 is to view a record.
         case 2:
            viewRecord(inventoryFile);
            break;

         // Choice 3 is to change a record.
         case 3:
            changeRecord(inventoryFile);
            break;
         case 4:
            searchbyname(inventoryFile);
            break;
         case 5:
             display(inventoryFile);
             break;
         case 6:
         	report(inventoryFile);
         	break;
         case 7:
         	add_from_text(textFile, inventoryFile);
     }

   } while (choice != 8);

   return 0;
}

//************************************************
// Function addRecord                            *
// This function gets the data for a record      *
// and writes it to the file.                    *
//************************************************

void addRecord(fstream &invFile)
{
   // An inventory structure to hold an
   // inventory record.
   Inventory record;

   // Open the file.
   invFile.open("invtry.dat", ios::out | ios::app | ios::binary);


   // If an error happened, exit.
   if (invFile.fail() )
   {
      cout << "Error opening binary file.\n";
      exit(EXIT_FAILURE);
   }
   cin.get();
   cout << "\nEnter the following inventory data:\n";

   // Get the description.
   cout << "Description: ";
   cin.getline(record.desc, 31);

   // Get the quantity.
   cout << "Quantity: ";
   cin >> record.qty;
   while (record.qty < 0)
   {
      cout << "Enter a positive value, please: ";
      cin >> record.qty;
   }

   // Get the wholesale cost.
   cout << "Wholesale cost: ";
   cin >> record.wholeSale;
   while (record.wholeSale < 0)
   {
      cout << "Enter a positive value, please: ";
      cin >> record.wholeSale;
   }

   // Get the retail price.
   cout << "Retail price: ";
   cin >> record.retail;
   while (record.retail < 0)
   {
      cout << "Enter a positive value, please: ";
      cin >> record.retail;
   }

   // Get the date added to inventory.
   cout << "Date added to inventory: ";
   cin >> record.date;

   // Write the record.
   invFile.write(reinterpret_cast<char*>(&record), sizeof(record));

   // Make sure we didn't have an error writing.
   if (invFile.fail())
      cout << "Error writing record to file.\n";
   else
      cout << "record written to file.\n\n";

   // Close the file.
   invFile.close();
}

//************************************************
// Function viewRecord                           *
// This function reads a specified record from   *
// the file and displays it on the screen.       *
//************************************************

void viewRecord(fstream &invFile)
{
   Inventory record;

   // Record number
   long recNum;

   // Open the file.
   invFile.open("invtry.dat", ios::in | ios::binary);

   // If we encountered an error, exit.
   if (invFile.fail())
   {
      cout << "Error opening file.\n";
      exit(EXIT_FAILURE);
   }

   // Get the record number from the user.
   cout << "\nEnter the record number of the item: ";
   cin >> recNum;

   // Seek to the record.
   invFile.seekg(recNum * sizeof(record), ios::beg);
   if (invFile.fail())
   {
         cout << "\nError locating record.\n";
      invFile.close();
      return;
   }

   // Read the record.
   invFile.read(reinterpret_cast<char*>(&record), sizeof(record));
   invFile.close();

   // Display the record.
   cout << "Description: ";
   cout << record.desc << endl;
   cout << "Quantity: ";
   cout << record.qty << endl;
   cout << "Wholesale cost: ";
   cout << record.wholeSale << endl;
   cout << "Retail price: ";
   cout << record.retail << endl;
   cout << "Date added to the file: ";
   cout << record.date << endl << endl;
   cout << "Press any key to continue...\n ";
   cin.get();
}

//************************************************
// Function changeRecord                         *
// This function reads a specified record from   *
// the file and allows the user to change it.    *
//************************************************

void changeRecord(fstream &invFile)
{
   Inventory record;

   // Record number.
   long recNum;

   // Open the file.
   invFile.open("invtry.dat", ios::in | ios::out | ios::binary);

   // If we encountered an error, exit.
   if (invFile.fail())
   {
       cout << "Error opening file.\n";
       exit(EXIT_FAILURE);
   }

   // Get the record number from the user.
   cout << "Enter the record number of the item: ";
   cin >> recNum;

   // Seek to the record.
   invFile.seekg(recNum * sizeof(record), ios::beg);
   if (invFile.fail())
   {
       cout << "Error locating record.\n";
       invFile.close();
       return;
   }

   // Read the record.
   invFile.read(reinterpret_cast<char*>(&record), sizeof(record));

   // Display the record.
   cout << "Current record contents:\n";
   cout << "Description: ";
   cout << record.desc << endl;
   cout << "Quantity: ";
   cout << record.qty << endl;
   cout << "Wholesale cost: ";
   cout << record.wholeSale << endl;
   cout << "Retail price: ";
   cout << record.retail << endl << endl;
   cout << "Date added to the file: ";
   cout << record.date;
   // Get new data.
   cout << "\n\nEnter the new data:\n";
   cin.get();
   cout << "Description: ";
   cin.getline(record.desc, 31);
   cout << "Quantity: ";
   cin >> record.qty;
   cout << "Wholesale cost: ";
   cin >> record.wholeSale;
   cout << "Retail price: ";
   cin >> record.retail;
   cout << "Date added to inventory: ";
   cin >> record.date;

   // Seek to the record position again.
   invFile.seekp(recNum * sizeof(record), ios::beg);

   // Write the record with the new data.
   invFile.write(reinterpret_cast<char*>(&record), sizeof(record));

   // Close the file.
   invFile.close();

   cout << "Press any key to continue... ";
   cin.get();
}
void searchbyname(fstream & invFile)
{
    long recNum =0;
    bool found = false;
    Inventory record;
    char toFind[30];

    cin.get();
    cout << " Enter part or entire name of an item ";

    cin.getline(toFind,30);

    invFile.open("invtry.dat", ios::in | ios::binary);

   // If we encountered an error, exit.
   if (invFile.fail())
   {
       cout << "Error opening file.\n";
       exit(EXIT_FAILURE);
   }
    //cin.ignore();
    invFile.read(reinterpret_cast<char*>(&record), sizeof(record));
    while (!invFile.eof())
    {
        if(strncmp(toFind, record.desc, strlen(toFind))== 0)
        {
            found = true;
            cout << record.desc << endl;
            break;
        }
        recNum++;
        invFile.read(reinterpret_cast<char*>(&record), sizeof(record));
    }
    invFile.clear();
    if(found == false)
    {
        cout << "Record not found\n";
    }
    else
    {
     cout << "\n\nRecord found   \n\n";
     invFile.seekg(recNum * sizeof(record), ios::beg);
     invFile.read(reinterpret_cast<char*>(&record), sizeof(record));
     // Display the record.
       cout << "Description: ";
       cout << record.desc << endl;
       cout << "Quantity: ";
       cout << record.qty << endl;
       cout << "Wholesale cost: ";
       cout << record.wholeSale << endl;
       cout << "Retail price: ";
       cout << record.retail << endl;
       cout << "Date added to the file: ";
       cout << record.date << endl << endl;

    }
cout << "Press any key to continue...\n ";
       cin.get();
    invFile.close();
}

void display(fstream &invFile)
{
	Inventory record;

	invFile.open("invtry.dat", ios::in | ios::binary);

   // If we encountered an error, exit.
   if (invFile.fail())
   {
       cout << "Error opening file.\n";
       exit(EXIT_FAILURE);
   }
    //cin.ignore();
    invFile.read(reinterpret_cast<char*>(&record), sizeof(record));
    while (!invFile.eof())
    {
       cout << "\nDescription: ";
       cout << record.desc << endl;
       cout << "Quantity: ";
       cout << record.qty << endl;
       cout << "Wholesale cost: ";
       cout << record.wholeSale << endl;
       cout << "Retail price: ";
       cout << record.retail << endl;
       cout << "Date added to the file: ";
       cout << record.date << endl << endl;//testing

       invFile.read(reinterpret_cast<char*>(&record), sizeof(record));

    }
	cout << "Press any key to continue...\n ";
    cin.get();

       invFile.close();
}

void report(fstream &invFile)
{
	Inventory record;
	double total_qty = 0, total_wholesale = 0, total_retail = 0;

	invFile.open("invtry.dat", ios::in | ios::binary);

   // If we encountered an error, exit.
   if (invFile.fail())
   {
       cout << "Error opening file.\n";
       exit(EXIT_FAILURE);
   }

   invFile.read(reinterpret_cast<char*>(&record), sizeof(record));

   while(!invFile.eof()) {
   	total_qty += record.qty;
   	total_wholesale += record.wholeSale;
   	total_retail += record.retail;

   	invFile.read(reinterpret_cast<char*>(&record), sizeof(record));
   }
   invFile.close();

   cout << "\n\nInventory summary\n\n";
   cout << "Total quantity\t\t" << total_qty << endl;
   cout << "Total retail\t\t" << total_retail << endl;
   cout << "Total wholesale\t\t" << total_wholesale << endl;

   cout << "Press any key to continue...\n ";
   cin.get();
}

void clear(fstream &invFile)
{
	invFile.open("invtry.dat", ios::trunc | ios::binary);
	invFile.close();
}


void add_from_text(fstream &textFile, fstream &invFile)
{
	Inventory record;

	textFile.open("stuff.txt", ios::in);
        invFile.open("invtry.dat", ios::out | ios::binary);

	if(textFile.fail()) {
		cout << "Error reading infile" << endl;
		exit(1);
	}
        if(invFile.fail()) {
                cout << "Error reading inventory file" << endl;
		exit(2);
	}

	textFile >> record.desc >> record.qty >> record.wholeSale >> record.retail >> record.date;
        invFile.write(reinterpret_cast<char*>(&record), sizeof(record));

	while(!textFile.eof())
	{
		textFile >> record.desc >> record.qty >> record.wholeSale >> record.retail >> record.date;
        	invFile.write(reinterpret_cast<char*>(&record), sizeof(record));
	}

	textFile.close();
	invFile.close();
}
