class FacultyAccounts{
 private:
        vector<Account> facultyAccount;
    public:
        void addAccount();
        void getAccounts();
        bool login(string user, string pass);
        void addFirstAccount(){
            Account acc("Teacher", "Teacher", "12345678901", "teacher", "teach123");
            acc.setID(facultyAccount.size() + 1);
            facultyAccount.push_back(acc);
        }
        int getUserID(string user, string pass);
        string getName(int id);
};

void FacultyAccounts::addAccount(){

    string tmp;
    string fullName;
    string fatherName;
    string CNIC;
    string username;
    string password;

    cin.clear();
    cin.ignore();
	cout<<endl;
    cin.clear();
    cin.ignore();
	cout<<"Eneter Full Name >> ";
	getline(cin, tmp);
	stringstream(tmp) >> fullName;

    cout<<"Eneter Father Name >> ";
	getline(cin, tmp);
	stringstream(tmp) >> fatherName;

    cout<<"Eneter CNIC >> ";
	getline(cin, tmp);
	stringstream(tmp) >> CNIC;

    cout<<"Eneter User Name >> ";
	getline(cin, tmp);
	stringstream(tmp) >> username;

    cout<<"Eneter Password >> ";
	getline(cin, tmp);
	stringstream(tmp) >> password;

    Account account(fullName, fatherName, CNIC, username, password);
    account.setID(facultyAccount.size()+1);

    facultyAccount.push_back(account);
}

void FacultyAccounts::getAccounts(){
    for(auto it = facultyAccount.begin(); it != facultyAccount.end(); it++){
        it->showUser();
    }
}

bool FacultyAccounts::login(string user, string pass){
    for(auto it = facultyAccount.begin(); it != facultyAccount.end(); it++){
        bool check = it->login(user, pass);
        if(check){
            return true;
        }
    }
    return false;
}

int FacultyAccounts::getUserID(string user, string pass)
{
    for (auto it = facultyAccount.begin(); it != facultyAccount.end(); it++)
    {
        bool check = it->login(user, pass);
        if (check)
        {
            return it->getID();
        }
    }
    return 0;
}

string FacultyAccounts::getName(int id){
    for(auto it = facultyAccount.begin(); it != facultyAccount.end(); it++){
        if(it->getID() == id){
            return it->getName();
        }
    }
    return "NULL";
}