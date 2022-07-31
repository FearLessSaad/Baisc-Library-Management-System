class Books{
	private:
		vector<Book> books;
	public:
		void addBook();
		void getBooks();
		string getTitle(int id);
		void updateBook(int id);
		void search(string title);
		bool verifyID(int id);
		int getPages(int id);
		int getPrice(int id);
		void addFirstBook(string title, int pages, string auther, string publisher,	int price){
			Book book(title, pages, auther, publisher, price);
			book.setID(books.size()+1);
			books.push_back(book);
		}
};

void Books::addBook(){

	string tmp;
	string title;
	int pages;
	string auther;
	string publisher;
	int price;

	cin.clear();
	cout<<endl;

	cout<<"Eneter Book Title >> ";
	getline(cin, tmp);
	stringstream(tmp) >> title;

	cout<<"Enter Number Of Pages >> ";
	getline(cin, tmp);
	stringstream(tmp) >> pages;

	cout<<"Enter Auther Name >> ";
	getline(cin, tmp);
	stringstream(tmp) >> auther;

	cout<<"Enter Publisher Name >> ";
	getline(cin, tmp);
	stringstream(tmp) >> publisher;

	cout<<"Enter Book Price >> ";
	getline(cin, tmp);
	stringstream(tmp) >> price;

	Book book(title, pages, auther, publisher, price);
	book.setID(books.size()+1);
	books.push_back(book);
}

void Books::getBooks(){
	for(auto it = books.begin(); it != books.end(); it++){
		it->getDetails();
	}
}

string Books::getTitle(int id){
	for(auto it = books.begin(); it != books.end(); it++){
		if(it->getID() == id){
			return it->getTitle();
		}
	}
	return "NULL";
}

int Books::getPages(int id){
	for(auto it = books.begin(); it != books.end(); it++){
		if(it->getID() == id){
			return it->getPages();
		}
	}
	return 0;
}

int Books::getPrice(int id){
	for(auto it = books.begin(); it != books.end(); it++){
		if(it->getID() == id){
			return it->getPrice();
		}
	}
	return 0;
}

void Books::updateBook(int id){
	for(auto it = books.begin(); it != books.end(); it++){
		if(it->getID() == id){
			it->updateBook();
		}
	}
}

void Books::search(string title){
	for(auto it = books.begin(); it != books.end(); it++){
		if(it->getTitle() == title){
			it->getDetails();
		}
	}
}

bool Books::verifyID(int id){
	for(auto it = books.begin(); it != books.end(); it++){
		if(it->getID() == id){
			return true;
		}
	}
	return false;
}