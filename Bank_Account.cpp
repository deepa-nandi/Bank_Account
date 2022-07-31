#include<iostream.h>
#include<string.h>
#include<conio.h>
#include<process.h>
#include<stdio.h>
#include<math.h>

class account
{
    char cname[30];
    char account_type[30];
    int account_no;
    public:
    double balance;
    void getdata()
    {
        cout<<"Enter customer name: ";
        gets(cname);
        cout<<"Enter account type: ";
        gets(account_type);
        cout<<"Enter account number: ";
        cin>>account_no;
        balance=0;
    }
    void display()
    {
        cout<<"The customer name is: ";
        puts(cname);
        cout<<"The account type is: ";
        puts(account_type);
        cout<<"The account number is: ";
        cin>>account_no;
    }
    void deposit()
    {
        double amount;
        cout<<"Enter the amount you want to deposit: ";
        cin>>amount;
        balance=balance+amount;
        cout<<"The balance is: "<<balance;
    }
};
class savings_account:public account
{
    double interest;
    public:
    int compound_interest()
    {
        double time1, rate;
        cout<<"Enter the time: ";
        cin>>time1;
        cout<<"Enter the rate: ";
        cin>>rate;
        interest = balance*pow(1+rate/100.0,time1)-balance;
        cout<<"the interest is: "<<interest;
        return interest;
    }
    void update_balance()
    {
        balance=balance+compound_interest();
        cout<<"The total balance is: "<<balance;
    }
    void withdraw_balance()
    {
        double withdraw;
        cout<<"Enter the amount you want to withdraw: ";
        cin>>withdraw;
        if(balance>=withdraw)
        {
            balance=balance-withdraw;
            cout<<"The balance is: "<<balance;
        }
        else
        {
            cout<<"Not sufficient balance.";
        }
    }
};
class current_account:public account
{
    int penalty;
    public:
    int min_bal()
    {
        int f=1;
        if(balance<=5000)
        {
            cout<<"Enter penalty: ";
            cin>>penalty;
            balance=balance-penalty;
            cout<<"The balance is: "<<balance;
            f=0;
        }
        else
        {
            cout<<"No penalty imposed.";
        }
        return f;
    }
    void withdrawal()
    {
        int w,k;
        cout<<"Enter the amount you want to withdraw: ";
        cin>>w;
        k=min_bal();
        if(k==1)
        {
            if(balance>=w)
            {
                balance=balance-w;
                cout<<"The balance is: "<<balance;
            }
            else
            {
                cout<<"Withdrawal is not possible.";
            }
        }
    }
};

void main()
{
    int choice;
    clrscr();
    current_account c1;
    savings_account s1;
    do
    {
        cout<<"1. Savings Account";
        cout<<"2. Current Account";
        cout<<"3. Exit";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice)
        {
            case 1: s1.getdata();
            s1.display();
            s1.deposit();
            s1.display();
            s1.update_balance();
            s1.display();
            s1.withdraw_balance();
            s1.display();
            break;
            case 2: c1.getdata();
            c1.display();
            c1.deposit();
            c1.display();
            c1.withdrawal();
            c1.display();
            break;
            case 3: exit(0);
            break;
            default: cout<<"Wrong choice.";
        }
    }while(choice!=3);
    getch();
}