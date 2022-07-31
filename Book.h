class Book
{
private:
	int id;
	string title;
	int pages;
	string auther;
	string publisher;
	int price;

public:
	Book(string t, int p, string a, string pp, int pri)
	{
		this->title = t;
		this->auther = a;
		this->pages = p;
		this->publisher = pp;
		this->price = pri;
	}

	void setID(int i)
	{
		this->id = i;
	}

	int getID()
	{
		return this->id;
	}

	string getTitle()
	{
		return this->title;
	}

	int getPages(){
		return this->pages;
	}

	int getPrice() {
		return this->price;
	}

	void getDetails()
	{
		cout << setw(5) << left << this->id;
		cout << setw(25) << left << this->title;
		cout << setw(10) << left << this->pages;
		cout << setw(15) << left << this->auther;
		cout << setw(35) << left << this->publisher;
		cout << setw(10) << left << this->price<<endl;
		
	}

	void updateBook()
	{
		string tmp;

		cin.clear();
		cout << endl;
		cout << endl
			 << "[+] Update Book Details." << endl;
		cout << "Eneter Book Title >> ";
		getline(cin, tmp);
		stringstream(tmp) >> this->title;

		cout << "Enter Number Of Pages >> ";
		getline(cin, tmp);
		stringstream(tmp) >> this->pages;

		cout << "Enter Auther Name >> ";
		getline(cin, tmp);
		stringstream(tmp) >> this->auther;

		cout << "Enter Publisher Name >> ";
		getline(cin, tmp);
		stringstream(tmp) >> this->publisher;

		cout << "Enter Book Price >> ";
		getline(cin, tmp);
		stringstream(tmp) >> this->price;

		cout << "[^_^] Book Has Been Updated Successfully." << endl;
	}
};
