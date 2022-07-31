class LaibrarinaAccounts{
 private:
        vector<Account> libAccount;
    public:
        void addAccount();
        void getAccounts();
        bool login(string user, string pass);
        void addFirstAccount(){
            Account acc("Admin", "Admin", "12345678901", "admin", "admin");
            acc.setID(libAccount.size() + 1);
            libAccount.push_back(acc);
        }
        int getUserID(string user, string pass);
};

void LaibrarinaAccounts::addAccount(){

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
    account.setID(libAccount.size()+1);

    libAccount.push_back(account);
}

void LaibrarinaAccounts::getAccounts(){
    for(auto it = libAccount.begin(); it != libAccount.end(); it++){
        it->showUser();
    }
}

bool LaibrarinaAccounts::login(string user, string pass){
    for(auto it = libAccount.begin(); it != libAccount.end(); it++){
        bool check = it->login(user, pass);
        if(check){
            return true;
        }
    }
    return false;
}

int LaibrarinaAccounts::getUserID(string user, string pass)
{
    for (auto it = libAccount.begin(); it != libAccount.end(); it++)
    {
        bool check = it->login(user, pass);
        if (check)
        {
            return it->getID();
        }
    }
    return 0;
}