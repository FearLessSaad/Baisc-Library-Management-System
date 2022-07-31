class IssueBook
{
private:
    vector<BookIssueDetails> issuedBooksDetails;

public:
    void issudeBook(int uid, int bid, Books books, bool type)
    {
        if (books.verifyID(bid))
        {
            Print p;
            BookIssueDetails issue;
            issue.id = issuedBooksDetails.size() + 1;
            issue.userID = uid;
            issue.bookID = bid;
            issue.status = false;
            issue.type = type;
            issuedBooksDetails.push_back(issue);
            cout << endl;
            p.printLine();
            cout << "[*] Book '" << books.getTitle(bid) << "' Issued Successfully." << endl;
            cout << "[+] Book Issue ID >> " << issuedBooksDetails.size() << endl;
            p.printLine();
        }
        else
        {
            cout << endl
                 << "[!] Entered Book ID Is Not Valid." << endl;
        }
    }

    void returnBook(int id, Books books)
    {
        Print p;
        int index = -1;
        for (auto it = issuedBooksDetails.begin(); it != issuedBooksDetails.end(); it++)
        {
            if (it->id == id)
            {
                it->status = true;
                index = it->bookID;
            }
        }
        if (index != -1)
        {
            cout << endl;
            p.printLine();
            cout << "[*] Book '" << books.getTitle(index) << "' Returned Successfully." << endl;
            p.printLine();
        }
        else
        {
            cout << endl;
            p.printLine();
            cout << "[!] No Detail Found Against Entered ID." << endl;
            p.printLine();
        }
    }

    void issuedBooksHistoryStudent(Books books, StudentAccounts sda)
    {
        string status;
        for (auto it = issuedBooksDetails.begin(); it != issuedBooksDetails.end(); it++)
        {
            if (it->type == false)
            {
                cout << setw(5) << left << it->id;
                cout << setw(25) << left << books.getTitle(it->bookID);
                cout << setw(10) << left << books.getPages(it->bookID);
                cout << setw(25) << left << sda.getName(it->userID);
                (it->status) ? status = "Returned" : status = "Not Returned";
                cout << setw(25) << left << status;
                cout << setw(10) << left << books.getPrice(it->bookID) << endl;
            }
        }
    }

    void issuedBooksHistoryFaculty(Books books, FacultyAccounts fca)
    {
        string status;
        for (auto it = issuedBooksDetails.begin(); it != issuedBooksDetails.end(); it++)
        {
            if (it->type == true)
            {
                cout << setw(5) << left << it->id;
                cout << setw(25) << left << books.getTitle(it->bookID);
                cout << setw(10) << left << books.getPages(it->bookID);
                cout << setw(25) << left << fca.getName(it->userID);
                (it->status) ? status = "Returned" : status = "Not Returned";
                cout << setw(25) << left << status;
                cout << setw(10) << left << books.getPrice(it->bookID) << endl;
            }
        }
    }

    void returnedBooksHistoryFaculty(Books books, FacultyAccounts fca)
    {
        string status;
        for (auto it = issuedBooksDetails.begin(); it != issuedBooksDetails.end(); it++)
        {
            if (it->type == true && it->status == true)
            {
                cout << setw(5) << left << it->id;
                cout << setw(25) << left << books.getTitle(it->bookID);
                cout << setw(10) << left << books.getPages(it->bookID);
                cout << setw(25) << left << fca.getName(it->userID);
                (it->status) ? status = "Returned" : status = "Not Returned";
                cout << setw(25) << left << status;
                cout << setw(10) << left << books.getPrice(it->bookID) << endl;
            }
        }
    }

    void returnedBooksHistoryStudent(Books books, StudentAccounts sda)
    {
        string status;
        for (auto it = issuedBooksDetails.begin(); it != issuedBooksDetails.end(); it++)
        {
            if (it->type == false && it->status == true)
            {
                cout << setw(5) << left << it->id;
                cout << setw(25) << left << books.getTitle(it->bookID);
                cout << setw(10) << left << books.getPages(it->bookID);
                cout << setw(25) << left << sda.getName(it->userID);
                (it->status) ? status = "Returned" : status = "Not Returned";
                cout << setw(25) << left << status;
                cout << setw(10) << left << books.getPrice(it->bookID) << endl;
            }
        }
    }
};