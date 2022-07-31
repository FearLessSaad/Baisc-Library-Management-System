#include "Core.h"

int StudentPortal(Core &core);
int FacultyPortal(Core &core);
int LaibrarianPortal(Core &core);

int userID;

int main(){

	Core core;

	int choice = -1;
	string tmp;

	while( choice != 0 ){
		cin.clear();

		core.p.printLine();
		core.p.showStartUpOptions();
		getline(cin, tmp);
		stringstream(tmp) >> choice;
		LoginDetails lgdt;

		switch(choice){
			case 1:
				lgdt = core.p.getLoginDetails();
				if(core.stdAcc.login(lgdt.user, lgdt.pass)){
					userID = core.stdAcc.getUserID(lgdt.user, lgdt.pass);
					choice = StudentPortal(core);
				}else{
					core.p.LoginError();
				}
				break;
			case 2:
				lgdt = core.p.getLoginDetails();
				if(core.facAcc.login(lgdt.user, lgdt.pass)){
					userID = core.facAcc.getUserID(lgdt.user, lgdt.pass);
					choice = FacultyPortal(core);
				}else{
					core.p.LoginError();
				}
				break;
			case 3:
				lgdt = core.p.getLoginDetails();
				if(core.laibAcc.login(lgdt.user, lgdt.pass)){
					userID = core.laibAcc.getUserID(lgdt.user, lgdt.pass);
					choice = LaibrarianPortal(core);
				}else{
					core.p.LoginError();
				}
				break;
			case 0:
				break;
			case 99:
				break;
			default:
				choice = -1;
				core.p.incorrectOption();
				break;
		}
	}

	return 0;
}

int StudentPortal(Core &core){
	int choice = -1;
	string tmp;
	int bid;
	
	while( choice != 99 ){
		core.p.showStudentPortalOptions();
		getline(cin, tmp);
		stringstream(tmp) >> choice;

		switch (choice)
		{
		case 1:
			core.p.bookDetailsHeader();
			core.books.getBooks();
			core.p.printLine();
			break;
		case 2:
			tmp = core.p.getSearchBookInput(); 
			core.p.bookDetailsHeader();
			core.books.search(tmp);
			core.p.printLine();
			break;
		case 3:
			bid = core.p.getBookIDInput();
			core.issuebook.issudeBook(userID, bid, core.books, false);
			break;
		case 99:
			break;
		default:
			core.p.incorrectOption();
			break;
		}
	}
	return 99;
}

int FacultyPortal(Core &core){
	int choice = -1;
	string tmp;
	int bid;
	
	while( choice != 99 ){
		core.p.showStudentPortalOptions();
		getline(cin, tmp);
		stringstream(tmp) >> choice;

		switch (choice)
		{
		case 1:
			core.p.bookDetailsHeader();
			core.books.getBooks();
			core.p.printLine();
			break;
		case 2:
			tmp = core.p.getSearchBookInput(); 
			core.p.bookDetailsHeader();
			core.books.search(tmp);
			core.p.printLine();
			break;
		case 3:
			bid = core.p.getBookIDInput();
			core.issuebook.issudeBook(userID, bid, core.books, true);
			break;
		case 99:
			break;
		default:
			core.p.incorrectOption();
			break;
		}
	}
	return 99;
}

int LaibrarianPortal(Core &core){
	int choice = -1;
	string tmp;
	int bid;
	int id;
	IssueBookByLib ibl;
	
	while( choice != 99 ){
		cin.clear();
		core.p.showLibPortalOptions();
		cin>>choice;

		switch (choice)
		{
		case 1:
			core.p.bookDetailsHeader();
			core.books.getBooks();
			core.p.printLine();
			break;
		case 2:
			tmp = core.p.getSearchBookInput(); 
			core.p.bookDetailsHeader();
			core.books.search(tmp);
			core.p.printLine();
			break;
		case 3:
			ibl = core.p.issueBookByLib();
			core.issuebook.issudeBook(ibl.uid, ibl.bid, core.books, ibl.type);
			break;
		case 4:
			id = core.p.showReturnBook();
			core.issuebook.returnBook(id, core.books);
			break;
		case 5:
			core.books.addBook();
			break;
		case 6:
			core.p.issuedBooksHistoryHeader();
			core.issuebook.issuedBooksHistoryStudent(core.books, core.stdAcc);
			core.p.printLine();
			break;
		case 7:
			core.p.issuedBooksHistoryHeader();
			core.issuebook.issuedBooksHistoryFaculty(core.books, core.facAcc);
			core.p.printLine();
			break;
		case 8:
			core.p.issuedBooksHistoryHeader();
			core.issuebook.returnedBooksHistoryStudent(core.books, core.stdAcc);
			core.p.printLine();
			break;
		case 9:
			core.p.issuedBooksHistoryHeader();
			core.issuebook.returnedBooksHistoryFaculty(core.books, core.facAcc);
			core.p.printLine();
			break;
		case 10:
			core.p.printLine();
			core.stdAcc.addAccount();
			core.p.printLine();
			break;
		case 11:
			core.p.printLine();
			core.facAcc.addAccount();
			core.p.printLine();
			break;
		case 12:
			core.p.printLine();
			core.laibAcc.addAccount();
			core.p.printLine();
			break;
		case 99:
			break;
		default:
			core.p.incorrectOption();
			break;
		}
	}
	return 99;
}