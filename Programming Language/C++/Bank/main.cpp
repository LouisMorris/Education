#include "header.hpp"

std::vector<BANK> client;

int main(int argc, char** argv) {
    while(1)
    {
        int id_idx;
        int choice_medu;
        std::cout << "//////////////////////////////" << std::endl;
        std::cout << "// 0.EXIT  1.SIGNIN 2. SIGNUP" << std::endl;
        std::cout << "//////////////////////////////" << std::endl;
        std::cin >> choice_medu;
        if (choice_medu == 0) break;
        else if (choice_medu == 2) {
            BANK tmp;
            tmp.newAccount();
            client.push_back(tmp);
        }
        else if (choice_medu == 1) {
            login();
            while(1) 
            {
                int num=0;
                std::cout << "0.EXIT 1. DEPOSIT 2.NEW 3.WITHDRAW 4.REMITTANCE" << std::endl;
                std::cin>>num;
                if (num == 0) break;
                else if (num == 1) client[id_idx].depositFunc();
                else if (num == 2) client[id_idx].accountFunc();
                else if (num == 3) client[id_idx].withdrawFunc();
                else if (num == 4)
                {
                    remittance(id_idx);             
                }
            }
        }
    }
    return 0;
}

void login() {
    // client 사이즈가 0인지 확인.
    if (client.size() == 0) {
        std::cout << "This bank has no any client." << std::endl;
        return;
    }

    std::string name, password;
    std::cout << "Input the account name" << std::endl;
    std::cin >> name;
    std::cout << "Input the account password" << std::endl;
    std::cin >> password;

    int check = checkAccount(name, password);
    if (check == 1) {
        std::cout << "Hello, Mr/Ms " << std::endl;
    }
    else if (check== -1) {
        std::cout<<"Wrong ID and PWD. Try again"<<std::endl;
    }
}

int checkAccount(std::string name, std::string password) {
    for (int i = 0; i < client.size(); i++) {
        if (client[i].getName() == name) {
            if (client[i].getPassword() == password) {
                client[i].setClientIndex(i);
            }
        }
    }

    
    return -1;
}

void remittance(int n)
{
    std::string name;
    std::cout<<"To who.";
    std::cin>>name;

    int num = client[n].remittanceFunc(n);

    for(int i=0;i<2;i++)
    {
        if(client[i].getName()==name)
        {
            if(num==0)
            {
                return;
            }
            client[i].setMoney(client[i].getmoney()-num);
            std::cout<<"Complete remittance."<<std::endl;
            std::cout<<"Current "<<client[n].getmoney() << "WON. " <<std::endl<<"remittance "<<num<<"WON."<<std::endl;
        }
 
    }
}




