class Account{
    private:
        int id;
        string fullName;
        string fatherName;
        string CNIC;
        string username;
        string password;
    public:
        Account(string fn, string fan, string cnic, string usr, string pass){
            this->fullName = fn;
            this->fatherName = fan;
            this->CNIC = cnic;
            this->username = usr;
            this->password = pass;
        }

        void setID(int i){
            this->id = i;
        }

        int getID(){
            return id;
        }

        string getName(){
            return this->fullName;
        }

        bool login(string user, string pass){
            if(this->username == user && this->password == pass){
                return true;
            }
            return false;
        }

        void showUser(){
            cout<<endl<<id<<endl;
            cout<<endl<<fullName<<endl;
            cout<<endl<<fatherName<<endl;
        }
};