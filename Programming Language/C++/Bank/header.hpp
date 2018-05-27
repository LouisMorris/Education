#pragma once
#include <iostream>
#include <string>
 
/*

int ID(std::string);         //아이디 중복확인

void Passward();   //비밀번호 중복확인

void Remittance();  //송금

*/

class BANK {
public:
    BANK() { money = 0;}
    void depositFunc() {
        int deposit;
        std::cout << "How much ?" << std::endl;
        std::cin >> deposit;
        money += deposit;
        std::cout << "==================RESULT=======================" << std::endl;
        std::cout << "MONEY : " << money << std::endl;
    }
    void accountFunc()
    {
        std::cout << "Making an account is completed!" << std::endl;
        std::cout << "==================RESULT=======================" << std::endl;
        std::cout << "ID : " << name << " " << "password : " << passward << std::endl;
        return;
    }
    void withdrawFunc() {
        while (1)
        {
            int withd;
            std::cout << "How much ?" << std::endl;
            std::cin >> withd;
            if (withd > money) {
                std::cout << "Too much! Try again." << std::endl;
            } else {
                money -= withd;
                std::cout << "==================RESULT=======================" << std::endl;
                std::cout << "MONEY : " << money << std::endl;
                return;
            }
        }
    }
    void remittanceFunc(int n)
    {
        int remittance;
        std::cout<<"송금할 금액을 입력하시오."
        std::cin>>remittance>>std::endl;
        if(remittance>money)
        {
            return 0;
        }
        money=money-remittance;
        return remittance;
    }

    std::string getName() { return name; }
    std::string getPassword() { return passward; }
    int getmoney(){return money;}
private:

    std::string name;

    std::string passward;

    int money;

};