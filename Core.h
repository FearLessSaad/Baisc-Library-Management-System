#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

#include "Structures.h"
#include "Print.h"
#include "Account.h"
#include "Book.h"
#include "Books.h"
#include "StudentAccounts.h"
#include "FacultyAccounts.h"
#include "LaibrarinaAccounts.h"
#include "IssueBook.h"

class Core
{
public:
	Print p;
	Books books;
	IssueBook issuebook;
	StudentAccounts stdAcc;
	FacultyAccounts facAcc;
	LaibrarinaAccounts laibAcc;

	Core()
	{
		facAcc.addFirstAccount();
		stdAcc.addFirstAccount();
		laibAcc.addFirstAccount();
		books.addFirstBook("Software Engineering 1", 1000, "Kevin Mitnick", "The University Of Faisalabad", 10000);
		books.addFirstBook("Data Structure And Alogs", 756, "Zeshan", "The University Of Faisalabad", 1200);
		books.addFirstBook("CISSP", 2521, "Muhammad Faisal", "Alnafi", 99654);
	}
};