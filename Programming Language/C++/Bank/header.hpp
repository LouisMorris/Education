#pragma once
#include <iostream>
#include <string>
#include <vector>
/*

int ID(std::string);         //?��?��?�� 중복?��?��

void Passward();   //비�??번호 중복?��?��

void Remittance();  //?���?

*/
int login();
int checkAccount(std::string name, std::string password);
void remittance(int n);

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
    void addmoney(int n)
    {
        money=money+n;
    }
    int remittanceFunc()
    {
        int remittance;
        std::cout<<"?��금할 금액?�� ?��?��?��?��?��.";
        std::cin>>remittance;
        if(remittance>money)
        {
            return 0;
        }
        money=money-remittance;
        return remittance;
    }

    void newAccount() {
        std::cout << "New ID : ";
        std::cin >> name;
        std::cout << "New PWD : ";
        std::cin >> passward;

        std::cout << "//////////////////////////////" << std::endl;
        std::cout << "// ID : " << name << std::endl;
        std::cout << "// PWD : " << passward << std::endl;
        std::cout << "//////////////////////////////" << std::endl;
    }   
    
    std::string getName() { return name; }
    std::string getPassword() { return passward; }
    int getmoney() { return money; }
    void setMoney(int n) {
        money = n;
    }

    void setClientIndex(int i) {
        client_idx = i;
    }

    int getClinetIndex() {
        return 0; 
    }

private:
    std::string name;
    std::string passward;
    int money;
    int client_idx;
};