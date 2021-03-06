#ifndef USER_H
#define USER_H

#include <QString>
#include <QDebug>

enum Sex {W,M};

class User
{
public:
    ~User();

    int uid;
    QString userName;
    QString passWord;
    QString phoneNumber;
    QString mibao;
    int power;
    Sex sex;


    User(const User&)=delete;
    User &operator=(const User&)=delete;

    static User& get_user()
    {
        static User user;

        return user;
    }
private:
    User();


};

#endif // USER_H
