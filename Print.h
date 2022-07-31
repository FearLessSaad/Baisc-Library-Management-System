class Print
{
private:
    int lineLength = 100;
    char lineChar = '=';
    string tmp;

public:
    void printLine()
    {
        for (int i = 0; i < lineLength; i++)
        {
            cout << lineChar;
        }
        cout << endl;
    }

    void showStartUpOptions()
    {
        printLine();
        cout << "[*] Please Select User Type For Login." << endl;
        cout << "[1] Student." << endl;
        cout << "[2] Faculty." << endl;
        cout << "[3] Laibrarian." << endl;
        cout << "[0] Exit." << endl;
        cout << "[Select] >> ";
    }

    LoginDetails getLoginDetails()
    {
        LoginDetails d;
        printLine();
        cout << "Enetr Username >> ";
        getline(cin, tmp);
        stringstream(tmp) >> d.user;
        cout << "Enetr Password >> ";
        getline(cin, tmp);
        stringstream(tmp) >> d.pass;
        return d;
    }

    void LoginError()
    {
        printLine();
        cout << "[!] Incorrect Username OR Password" << endl;
        printLine();
    }

    void incorrectOption()
    {
        printLine();
        cout << "[!] Incorrect Option Sleceted." << endl;
        printLine();
    }

    void showStudentPortalOptions()
    {
        printLine();
        cout << "[*] Please Select Option." << endl;
        cout << "[1] Show Books." << endl;
        cout << "[2] Search Book." << endl;
        cout << "[3] Issue Book." << endl;
        cout << "[99] Logout." << endl;
        cout << "[Select] >> ";
    }

    void bookDetailsHeader()
    {
        cout << endl;
        printLine();
        cout << setw(5) << left << "#";
        cout << setw(25) << left << "Title";
        cout << setw(10) << left << "Pages";
        cout << setw(15) << left << "Auther";
        cout << setw(35) << left << "Publisher";
        cout << setw(10) << left << "Price" << endl;
        printLine();
    }
    string getSearchBookInput(){
        cin.clear();
        cout<<endl<<"[^_*] Enter Book Name >> ";
        getline(cin, tmp);
        return tmp;
    }

    int getBookIDInput(){
        cin.clear();
        int id;
        cout<<endl<<"[^_*] Enter Book ID >> ";
        getline(cin, tmp);
        stringstream(tmp) >> id;
        return id;
    }

    void showLibPortalOptions()
    {
        printLine();
        cout << "[*] Please Select Option." << endl;
        cout << "[1] Show Books." << endl;
        cout << "[2] Search Book." << endl;
        cout << "[3] Issue Book." << endl;
        cout << "[4] Return Book." << endl;
        cout << "[5] Add Book." << endl;
        cout << "[6] Student Issued Books History." << endl;
        cout << "[7] Faculty Issued Books History." << endl;
        cout << "[8] Student Returned Books History." << endl;
        cout << "[9] Faculty Returned Books History." << endl;
        cout << "[10] Add Student Account." << endl;
        cout << "[11] Add Faculty Account." << endl;
        cout << "[11] Add Librarian Account." << endl;
        cout << "[99] Logout." << endl;
        cout << "[Select] >> ";
    }

    IssueBookByLib issueBookByLib(){
        cin.clear();
        IssueBookByLib ibl;
        int c;
        bool t;
        cout<<endl<<"[+] Enter User Type.";
        cout<<endl<<"[1] Faculty.";
        cout<<endl<<"[2] Student.";
        cout<<endl<<"[^_*] Select >> ";
        getline(cin, tmp);
        stringstream(tmp) >> c;
        cout<<endl<<"[^_*] Enter Book ID >> ";
        getline(cin, tmp);
        stringstream(tmp) >> ibl.bid;
        cout<<endl<<"[^_*] Enter User ID >> ";
        getline(cin, tmp);
        stringstream(tmp) >> ibl.uid;
        if(c == 1){
            t = true;
        }else if(c ==2){
            t = false;
        }
        ibl.type = t;
        return ibl;
    }

    int showReturnBook(){
        cin.clear();
        int id;
        cin.clear();
        cin.ignore();
        cout<<endl<<"[^_*] Enter Issue ID >> ";
        getline(cin, tmp);
        stringstream(tmp) >> id;
        return id;
    }

    void issuedBooksHistoryHeader(){
        cout << endl;
        printLine();
        cout << setw(5) << left << "#";
        cout << setw(25) << left << "Title";
        cout << setw(10) << left << "Pages";
        cout << setw(25) << left << "Issued To";
        cout << setw(25) << left << "Status";
        cout << setw(10) << left << "Price"<<endl;
        printLine();
    }

};