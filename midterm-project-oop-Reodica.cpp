#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype>
#include <limits>
using namespace std;

class Empty { // Empty class for menus
public:
    virtual void displayMenu() = 0;
};

class EmptySecond {
public:
    virtual void displaySecond() const = 0;
    virtual ~EmptySecond() = default;
};



//=======================================================================================//
class Item { // Data setup for items (Representations)
public:
    string id;
    string name;
    double price;
    int qty;
    int category;

    Item(const string& id, const string& name, double price, int qty, int category)
        : id(id), name(name), price(price), qty(qty), category(category) {} // Constructor
};

class Inventory : public EmptySecond { // Inventory
private:
    vector<Item> items;
    
    void swapper(Item& a, Item& b){		//For sorting
		Item decoy = a;
		a = b;
		b = decoy;	
	}
	void printSwapped(const vector<Item>& items) const{	//To print vector data
		cout << "ID" << setw(20) << "Name" << setw(20) << "Quantity" << setw(20) << "Price" << endl;
		for(size_t i = 0 ; i < items.size(); ++i){
			cout << items[i].id << setw(20) << items[i].name << setw(20) << items[i].qty << setw(20) << items[i].price << endl;
		}
	}
public:
    void addItem(const Item& item) { // Adding//creating items to list
        items.emplace_back(item); // Adds items to the bottom of the list of data
    }

    void displaySecond() const override {	//Displaying items
        cout << "ID" << setw(20) << "Name" << setw(20) << "Quantity" << setw(20) << "Price" << setw(20) << "Category" << endl;
        for (const auto& item : items) {
            cout << item.id << setw(20) << item.name << setw(20) << item.qty << setw(20) << item.price << setw(20);
            switch (item.category){
					case 1:{
						cout << "Clothing";
						break;
					}
					case 2:{
						cout << "Electronics";
						break;
					}
					case 3:{
						cout << "Entertainment";
						break;
					}
					default:{
						cout << "No category";
						break;
					}
				}
				cout << endl;
        }
        cout << endl;
        system("pause");
        system("cls");
    }
    
    bool verifyItemid(const string& id){		//For verifying duplicates in adding items
		for(size_t i = 0 ; i < items.size(); i++){
			if (items[i].id == id){
				cout << "This ID has a duplicate\n";
				system("pause");
				system("cls");
			return true;
			}
			
		}
		return false;
	}
    
    bool deleteItem(const string& id) {			//For the delete Item class
    	for (size_t i = 0; i < items.size(); ++i) {
        	if (items[i].id == id) {
            	//Process after finding
				cout << "Item " << items[i].name << " deleted successfully!\n"; //Confirmation that the ID was found and deleted
				items.erase(items.begin() + i); // Remove the item - also pin pointing where its target data is
			
        		return true; // Item found and removed
            }
        }
        return false; // Item not found
    }
    
    bool editItem(const string& id){			//Editing items
    	for (size_t i = 0 ; i < items.size(); ++i){
    		if(items[i].id == id){
    			//Process after finding
    			int choose;		//Temporary data for item to edit
				cout << "Edit [1 - Quantity][2 - Price] for " << items[i].name << ":\n";
    			cin >> choose;
    			
    			if(choose == 1){
    				int change_qty;		//New data to insert into qty
    				bool tempqty = true;
    			while(tempqty){
						cout << "Enter mew quantity for " << items[i].name << ": ";
						cin >> change_qty;
    				if(change_qty <= 0){
    					cout << "Quantity cannot be or go under zero, please delete the item instead when sold out\n";
    					system("pause");
               			system("cls");
               			cin.clear();
               			cin.ignore(100000, '\n');
					}
					else if(change_qty > 0){
						cout << "Quantity of Item " << items[i].name << " from " << items[i].qty << " to " << change_qty << endl;
						items[i].qty = change_qty;
						system("pause");
						system("cls");
						return true;		//Process complete
					}
					else{
						cout << "Invalid input\n";
						system("pause");
               			system("cls");
               			cin.clear();
               			cin.ignore(100000, '\n');
					}
				}
					
				return true; // Item found and edited
				}
				
				else if(choose == 2){
					float change_price; 	//New data to insert to price
					bool tempprice = true;
					while (tempprice){
					cout << "Enter new price for " << items[i].name << ": ";
					cin >> change_price;
					
					if(change_price <= 0){
    					cout << "Price cannot be or go under zero\n";
    					system("pause");
               			system("cls");
               			cin.clear();
               			cin.ignore(100000, '\n');
					}
					
					else if(change_price > 0){
						cout << "Price of item " << items[i].name << " from " << items[i].price << " to " << change_price << endl;
						items[i].price = change_price;
						system("pause");
						system("cls");
						return true;		//Process complete
					}
					else{
						cout << "Invalid input\n";
						system("pause");
               			system("cls");
               			cin.clear();
               			cin.ignore(100000, '\n');
					}
					}
					
					
				return true; // Item found and edited
				}
					
				else{
					cout << "Invalid input\n";
					cin.clear();
                	cin.ignore(1000, '\n');
					system("pause");
					system("cls");
					
				}
			}
		}
	return false;	//Item not found
	}

	bool searchItem(const string& id){		//For searching items
		for(size_t i = 0 ; i < items.size(); i++){
			if (items[i].id == id){
				
				cout << "-_-_-_-_-_-_[Item ID found!]-_-_-_-_-_-_\n";
				cout << "ID" << setw(20) << "Name" << setw(20) << "Quantity" << setw(20) << "Price" << setw(20) << "Category" << endl;
				cout << items[i].id << setw(20) << items[i].name << setw(20) << items[i].qty << setw(20) << items[i].price << setw(20);
				switch (items[i].category){
					case 1:{
						cout << "Clothing";
						break;
					}
					case 2:{
						cout << "Electronics";
						break;
					}
					case 3:{
						cout << "Entertainment";
						break;
					}
					default:{
						cout << "No category";
						break;
					}
				}
				cout << endl;
				system("pause");
				system("cls");
			return true;
			}
			
		}
		return false;
	}
	
	
	bool displayCategory(const int& category){		//By Category
	bool checker = false;
		cout << "-_-_-_-_-_-_[Displaying]-_-_-_-_-_-_\n";
			cout << "ID" << setw(20) << "Name" << setw(20) << "Quantity" << setw(20) << "Price" << setw(20) << "Category" << endl;
		if(category > 3 || category < 0){
			cin.clear();
			cin.ignore(1000, '\n');
			return false;
			}
		
		for(size_t i = 0 ; i < items.size(); ++i){
			if (items[i].category == category){
				checker = true;		//Confirmed that an item exists in the category
				cout << items[i].id << setw(20) << items[i].name << setw(20) << items[i].qty << setw(20) << items[i].price << setw(20);
				switch (items[i].category){
					case 1:{
						cout << "Clothing";
						break;
					}
					case 2:{
						cout << "Electronics";
						break;
					}
					case 3:{
						cout << "Entertainment";
						break;
					}
					default:{
						cout << "No category";
						break;
					}
				}
			cout << endl;
			}
			
		}
		if (!checker){
			cout << "No items in this category\n";
		}
		
		return checker;	
	}
	
	void lowStock(){			//Low Stock
			cout << "ID" << setw(20) << "Name" << setw(20) << "Quantity" << setw(20) << "Price" << setw(20) << "Category" << endl;
		for(size_t i = 0 ; i < items.size(); ++i){
			if(items[i].qty <= 5){
				cout << items[i].id << setw(20) << items[i].name << setw(20) << items[i].qty << setw(20) << items[i].price << setw(20);
				switch (items[i].category){
					case 1:{
						cout << "Clothing";
						break;
					}
					case 2:{
						cout << "Electronics";
						break;
					}
					case 3:{
						cout << "Entertainment";
						break;
					}
					default:{
						cout << "No category";
						break;
					}
				}cout << endl;
			}
		}
		
	}
	
	void sortItemtype(int choice, int choice2){
		size_t n = items.size();
		if(choice == 1 && choice2 == 1){	//By quantity // Ascending
			for(size_t i = 0 ; i < n - 1; ++i){
				bool confirm_s = false;
				
				for(size_t j = 0 ; j < n - i - 1; ++j){
					if(items[j].qty > items[j + 1].qty){		//Changeable
						swapper(items[j], items[j + 1]);
						confirm_s = true;
					}
				}
				if (!confirm_s){
					break;
				}
			}
		}
		else if(choice == 2 && choice2 == 1){	//By price // Ascending
			for(size_t i = 0 ; i < n - 1; ++i){
				bool confirm_s = false;
				
				for(size_t j = 0 ; j < n - i - 1; ++j){
					if(items[j].price > items[j + 1].price){		//Changeable
						swapper(items[j], items[j + 1]);
						confirm_s = true;
					}
				}
				if (!confirm_s){
					break;
				}
			}
		}
		else if(choice == 1 && choice2 == 2){	//By quantity // Descending
			for(size_t i = 0 ; i < n - 1; ++i){
				bool confirm_s = false;
				
				for(size_t j = 0 ; j < n - i - 1; ++j){
					if(items[j].qty < items[j + 1].qty){		//Changeable
						swapper(items[j], items[j + 1]);
						confirm_s = true;
					}
				}
				if (!confirm_s){
					break;
				}
			}
		}
		else if(choice == 2 && choice2 == 2){	//By price // Descending
			for(size_t i = 0 ; i < n - 1; ++i){
				bool confirm_s = false;
				
				for(size_t j = 0 ; j < n - i - 1; ++j){
					if(items[j].price < items[j + 1].price){		//Changeable
						swapper(items[j], items[j + 1]);
						confirm_s = true;
					}
				}
				if (!confirm_s){
					break;
				}
			}
		}
		//============================//
	
		//==============[Print]==============//
		printSwapped(items);
	}

};
//=====================[Empty to all functions that require altering data]=================//
class EmptyThird {
	public:
	virtual void displayThird(Inventory& i1) = 0;
	virtual ~EmptyThird() = default;
};
//========================================================================//


class AddItem : public EmptyThird {							//Add Item - option number 1					<=========================marked]
private:
	void doubleUpper(string& str) {
   	 		for (char& ch : str) {
        		ch = toupper(ch); 				// Convert each letter to uppercase
    		}
		}
		bool twoLetters(const string& str) {		//For ID size (Must be only 2 letters)
    		return str.length() == 2;
		}
public:
    void displayThird(Inventory& i1) override {
        string new_id;
        string new_name;
        double new_price;
        int new_qty;
        int new_category;
		string new_category_sub;
		
        bool newItemTemp = true;
        while (newItemTemp) {
            cout << "What category does the item fall under?(Enter the word)\n";
            cout << "[Clothing]\n[Electronics]\n[Entertainment]\n";
            cout << "User input: ";
            cin >> new_category_sub;
			doubleUpper(new_category_sub);							//Quick note: Categorized by option chosen for easy sorting later
            
            if (new_category_sub == "CLOTHING") {			//Clothing items
                new_category = 1;
            bool val = true;
            while(val){
				cout << "Enter item ID: ";
                cin >> new_id;								//ID
                
                if(twoLetters(new_id)){
                	doubleUpper(new_id);
                	if(i1.verifyItemid(new_id)){			//Verify duplicates
						val = true;
					}
                	
                	else {
						val = false;
					}
				}
				else{
					cout << "Invalid input, IDs can only have 2 letters or numbers\n";
					cin.clear();
                	cin.ignore(1000, '\n');
					system("pause");
					system("cls");
				}
			}
                cout << "Enter item name: ";
                cin.ignore();
                getline(cin, new_name);
				
				bool val2 = true;
				while(val2){	
                	cout << "Enter item price: ";
               		cin >> new_price;						//Price
               		
               		if (cin.fail()){
               			cout << "Please enter a number for this section\n";
               			system("pause");
               			system("cls");
               			cin.clear();
               			cin.ignore(100000, '\n');
					}
					
					else if (new_price <= 0){
						cout << "Item price cannot be or go lower than 0\n";
               			cin.clear();
               			cin.ignore(100000, '\n');
					}
					
					else{
						val2 = false;
					}
				}

                bool val3 = true;
				while(val3){	
                	cout << "Enter item quantity: ";
               		cin >> new_qty;						//Quantity
               		
               		if (cin.fail()){
               			cout << "Please enter a number for this section\n";
               			system("pause");
               			system("cls");
               			cin.clear();
               			cin.ignore(100000, '\n');
					}
					
					else if (new_qty <= 0){
						cout << "Item quantity be or go lower than 0\n";
               			cin.clear();
               			cin.ignore(100000, '\n');
					}
					
					else{
						val3 = false;
					}
				}

                // Add the item to the inventory
                i1.addItem(Item(new_id, new_name, new_price, new_qty, new_category));
                cout << "New clothing item added successfully!\n";
                system("pause");
                system("cls");
                
                newItemTemp = false;
            } 
			else if (new_category_sub == "ELECTRONICS") {			//Electronic items
                new_category = 2;
            bool val = true;
            while(val){
				cout << "Enter item ID: ";
                cin >> new_id;								//ID
                
                if(twoLetters(new_id)){
                	doubleUpper(new_id);
                	if(i1.verifyItemid(new_id)){
						val = true;
					}
                	
                	else {
						val = false;
					}
				}
				else{
					cout << "Invalid input, IDs can only have 2 letters or numbers\n";
					cin.clear();
                	cin.ignore(1000, '\n');
					system("pause");
					system("cls");
				}
			}
                cout << "Enter item name: ";
                cin.ignore();
                getline(cin, new_name);
				
				bool val2 = true;
				while(val2){	
                	cout << "Enter item price: ";
               		cin >> new_price;						//Price
               		
               		if (cin.fail()){
               			cout << "Please enter a number for this section\n";
               			system("pause");
               			system("cls");
               			cin.clear();
               			cin.ignore(100000, '\n');
					}
					else if (new_price <= 0){
					cout << "Item price cannot be or go lower than 0\n";
               		cin.clear();
              			cin.ignore(100000, '\n');
					}
					
					else{
						val2 = false;
					}
				}

                bool val3 = true;
				while(val3){	
                	cout << "Enter item quantity: ";
               		cin >> new_qty;						//Quantity
               		
               		if (cin.fail()){
               			cout << "Please enter a number for this section\n";
               			system("pause");
               			system("cls");
               			cin.clear();
               			cin.ignore(100000, '\n');
					}
					else if (new_qty <= 0){
						cout << "Item quantity be or go lower than 0\n";
               			cin.clear();
               			cin.ignore(100000, '\n');
					}
					
					else{
						val3 = false;
					}
				}

                // Add the item to the inventory
                i1.addItem(Item(new_id, new_name, new_price, new_qty, new_category));
                cout << "New Electronic item added successfully!\n";
                system("pause");
                system("cls");
                
                newItemTemp = false;
            } 
			else if (new_category_sub == "ENTERTAINMENT") {			//Entertainment items
                new_category = 3;
            bool val = true;
            while(val){
				cout << "Enter item ID: ";
                cin >> new_id;								//ID
                
                if(twoLetters(new_id)){
                	doubleUpper(new_id);
                	if(i1.verifyItemid(new_id)){
						val = true;
					}
                	
                	else {
						val = false;
					}
				}
				else{
					cout << "Invalid input, IDs can only have 2 letters or numbers\n";
					cin.clear();
                	cin.ignore(1000, '\n');
					system("pause");
					system("cls");
				}
			}
                cout << "Enter item name: ";
                cin.ignore();
                getline(cin, new_name);
				
				bool val2 = true;
				while(val2){	
                	cout << "Enter item price: ";
               		cin >> new_price;						//Price
               		
               		if (cin.fail()){
               			cout << "Please enter a number for this section\n";
               			system("pause");
               			system("cls");
               			cin.clear();
               			cin.ignore(100000, '\n');
					}
					else if (new_price <= 0){
					cout << "Item price cannot be or go lower than 0\n";
               		cin.clear();
              			cin.ignore(100000, '\n');
					}
					
					else{
						val2 = false;
					}
				}

                bool val3 = true;
				while(val3){	
                	cout << "Enter item quantity: ";
               		cin >> new_qty;						//Quantity
               		
               		if (cin.fail()){
               			cout << "Please enter a number for this section\n";
               			system("pause");
               			system("cls");
               			cin.clear();
               			cin.ignore(100000, '\n');
					}
					else if (new_qty <= 0){
						cout << "Item quantity be or go lower than 0\n";
               			cin.clear();
               			cin.ignore(100000, '\n');
					}
					
					else{
						val3 = false;
					}
				}

                // Add the item to the inventory
                i1.addItem(Item(new_id, new_name, new_price, new_qty, new_category));
                cout << "New entertainment item added successfully!\n";
                system("pause");
                system("cls");
                
                newItemTemp = false;
            } 
			
			
			else {
                cout << "Category " << new_category_sub << " does not exist\n";
                cin.clear();
                cin.ignore(1000, '\n');
                system("pause");
                system("cls");
            }
        }
    }
};


class EditItem : public EmptyThird{				//Edit item - Option number 2
	private:
		string key_id;
		void doubleUpper(string& str) {
   	 		for (char& ch : str) {
        		ch = toupper(ch); 				// Convert each letter to uppercase
    		}
		}
		
	public:
		void displayThird(Inventory& i1) override{ //The key to find an ID
			cout << "Input the ID of the item to edit: ";
			cin >> key_id;
				doubleUpper(key_id);
			
			if (i1.editItem(key_id)){
			}
			else{
				cout << "Item not found\n";
				cin.clear();
                cin.ignore(1000, '\n');
				system("pause");
				system("cls");
			}
		}
};


class DeleteItem : public EmptyThird{			//Delete ITem - Option number 3
	private:
		string key_id;
		void doubleUpper(string& str) {
   	 		for (char& ch : str) {
        		ch = toupper(ch); 				// Convert each letter to uppercase
    		}
		}
		int i;
	public:
    	void displayThird(Inventory& i1) override{
    		cout << "Enter ID of item to delete: ";
			cin >> key_id;
			doubleUpper(key_id);
			
        if (i1.deleteItem(key_id)) {//	This is meant to delete when the ID is found // will be a reoccuring theme for the whole program
        } 
		else {
        	cout << "Item with ID " << key_id << " not found.\n";
        	cin.clear();
            cin.ignore(1000, '\n');
        }
        system("pause");
        system("cls");
    }
};

class SearchItem : public EmptyThird{		//Search item - Option number 6
	private:
		string key_id;
		void doubleUpper(string& str) {
   	 		for (char& ch : str) {
        		ch = toupper(ch); 				// Convert each letter to uppercase
    		}
		}
	public:
		void displayThird(Inventory& i1) override{
			cout << "Enter ID of item to search: ";
			cin >> key_id;
			doubleUpper(key_id);
			
			if(i1.searchItem(key_id)){
				
			}
			else{
				cout << "Item not found\n";
				system("pause");
				system("cls");
				cin.clear();
                cin.ignore(1000, '\n');
			}
		}
};

class DisplayCategory : public EmptyThird{		//Display by category - Option number 4
	private:
		int c_key;
	public:
		void displayThird(Inventory& i1) override {
			cout << "-_-_-_-_-_-_[Input category - Enter the number]_-_-_-_-_-_-\n";
			cout << "[1 - Clothes]\n[2 - Electronic]\n[3 - Entertainment]\n";
			cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
			cin >> c_key;
			
			if(i1.displayCategory(c_key)){
				cout << endl;
				system("pause");
				system("cls");
			}
			else if(c_key != 1 or c_key != 2 or c_key != 3){
				cout << "Category not found\n";
				system("pause");
				system("cls");
				cin.clear();
                cin.ignore(1000, '\n');
			}
			
		}
};

class LowStock : public EmptyThird{		//Display low stock items - Option number 8
	private:
		
	public: 
		void displayThird(Inventory& i1) override{
			cout << "-_-_-_-_-_-_[Low stock items]_-_-_-_-_-_-\n";
			i1.lowStock();
			cout << endl;
			system("pause");
			system("cls");
		}
};

class SortItems : public EmptyThird{			//Sort Items - Option number 7
	private: 
		int choice;
		int choice2;
	public:
		void displayThird(Inventory& i1) override{
			bool temp_sort = true;
			bool temp_sort2 = true;
			
			while(temp_sort){
				cout << "-_-_-_-_-_-_[Sorting items - Enter the number]_-_-_-_-_-_-_-\n";
				cout << "Sort by [1 - Quantity][2 - price]\n";
				cout << "User input: ";
				cin >> choice;
				
				if(choice == 1 || choice == 2){
					temp_sort = false;
					system("pause");
					system("cls");
				}
				
				else{
					cout << "Invalid input\n";
					system("pause");
					system("cls");
					cin.clear();
        	        cin.ignore(1000, '\n');
				}
			}
			while (temp_sort2){
				cout << "-_-_-_-_-_-_[Sorting items]_-_-_-_-_-_-_-\n";
				cout << "Sort in [1 - Ascending][2 - Descending]\n";
				cout << "User input: ";
				cin >> choice2;
				
				if (choice2 == 1 || choice2 == 2){
					i1.sortItemtype(choice, choice2);
					temp_sort2 = false;
					cin.clear();
        	        cin.ignore(1000, '\n');
				}
				else{
					cout << "Invalid input\n";
					system("pause");
					system("cls");
					cin.clear();
        	        cin.ignore(1000, '\n');
				}
			}
		cout << endl << endl;
		system ("pause");
		system ("cls");	
		}
		
};

//=======================================================================================//
class MainMenu : public Empty { // Displays
public:
    void displayMenu() override {
        cout << "_-_-_-_-_-[Inventory Management]-_-_-_-_-_\n";
        cout << "[1] - Add Item\n[2] - Update Item\n[3] - Remove Item\n[4] - Display items by category\n[5] - Display all items\n[6] - Search item\n[7] - Sort items\n[8] - Display Low stock items\n[9] - Exit\n";
        cout << "-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-_-\n";
    }
};
//=======================================================================================//

int main() {
    // Calls
    Inventory i1;
    MainMenu m1;
    AddItem a1;
    EditItem e1;
    DeleteItem d1;
    SearchItem s1;
    DisplayCategory dc;
    LowStock l1;
    SortItems sor1;

    // Main inventory // Format = ID, name, price, quantity, category(Numeral)
    i1.addItem(Item("AA", "Jacket", 500.00, 10, 1));
    i1.addItem(Item("AB", "Desktop", 4000, 5, 2));
    i1.addItem(Item("AC", "Zelda", 200, 3, 3));
    i1.addItem(Item("AD", "Shirt", 400, 2, 1));
    i1.addItem(Item("AE", "Controller", 250.50, 20, 2));

    // Other variables
    int action;
    string valid;

    // Main Process
    bool temp = true;
    while (temp) {
        m1.displayMenu();
        cin >> action;
        valid = action;
        
        char extra;											//Extra character
		if (cin.get(extra) && extra != '\n') {				//For validating if theres a second input
                cout << "Invalid input. Please enter a single number\n";
                system("pause");
				system("cls");
				cin.clear();
                cin.ignore(1000, '\n');
            } 
		else{
        switch (action) {		//Add item		[done]		[Validated]
            case 1: {
                a1.displayThird(i1);
                break;
            }
            case 2: {			//Edit item 	[done]		[Validated]
            	e1.displayThird(i1);
                break;
            }
            case 3: {			//Remove item	[done]		[Validated]
                d1.displayThird(i1);
                break;
            }
            case 4: {			//Display by category 	[done]		[Validated]
                dc.displayThird(i1);
                break;
            }
            case 5: { // Display all items [no arrangement]	[done]		[Validated]
                i1.displaySecond();
                break;
            }
            case 6: {		//Search item		[done]		[Validated]
                s1.displayThird(i1);
                break;
            }
            case 7: {		//Sort items		[done]		[Validated]
                sor1.displayThird(i1);
                break;
            }
            case 8: {		//Display low stock items		[done]		[Validated]
                l1.displayThird(i1);
                break;
            }
            case 9: { // Close program			[done]
                temp = false;
                break;
            }
            default: {
                cout << "Invalid input\n";
                cin.clear();
                cin.ignore(1000, '\n');
                system("pause");
                system("cls");
                break;
            }
        }
		}
    }
    return 0;
}