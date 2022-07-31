class StudentAccounts
{
private:
    vector<Account> stdAcc;

public:
    void addAccount();
    void getAccounts();
    bool login(string user, string pass);
    void addFirstAccount()
    {
        Account acc("Student", "ather", "12345678901", "student", "student");
        acc.setID(stdAcc.size() + 1);
        stdAcc.push_back(acc);
    }
    int getUserID(string user, string pass);
    string getName(int id);
};

void StudentAccounts::addAccount()
{

    string tmp;
    string fullName;
    string fatherName;
    string CNIC;
    string username;
    string password;

    cin.clear();
    cin.ignore();
    cout << endl;
    cin.clear();
    cin.ignore();
    cout << "Eneter Full Name >> ";
    getline(cin, tmp);
    stringstream(tmp) >> fullName;

    cout << "Eneter Father Name >> ";
    getline(cin, tmp);
    stringstream(tmp) >> fatherName;

    cout << "Eneter CNIC >> ";
    getline(cin, tmp);
    stringstream(tmp) >> CNIC;

    cout << "Eneter User Name >> ";
    getline(cin, tmp);
    stringstream(tmp) >> username;

    cout << "Eneter Password >> ";
    getline(cin, tmp);
    stringstream(tmp) >> password;

    Account account(fullName, fatherName, CNIC, username, password);
    account.setID(stdAcc.size() + 1);

    stdAcc.push_back(account);
}

void StudentAccounts::getAccounts()
{
    for (auto it = stdAcc.begin(); it != stdAcc.end(); it++)
    {
        it->showUser();
    }
}

bool StudentAccounts::login(string user, string pass)
{
    for (auto it = stdAcc.begin(); it != stdAcc.end(); it++)
    {
        bool check = it->login(user, pass);
        if (check)
        {
            return true;
        }
    }
    return false;
}

int StudentAccounts::getUserID(string user, string pass)
{
    for (auto it = stdAcc.begin(); it != stdAcc.end(); it++)
    {
        bool check = it->login(user, pass);
        if (check)
        {
            return it->getID();
        }
    }
    return 0;
}

string StudentAccounts::getName(int id){
    for(auto it = stdAcc.begin(); it != stdAcc.end(); it++){
        if(it->getID() == id){
            return it->getName();
        }
    }
    return "NULL";
}