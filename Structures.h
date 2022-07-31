struct Date
{
    int day, month, year;
};

struct BookIssueDetails
{
    int id;
    int userID;
    int bookID;
    bool type;
    bool status;
};

struct LoginDetails{
    string user, pass;
};

struct IssueBookByLib{
    int uid, bid;
    bool type;
};