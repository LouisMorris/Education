#include "header.hpp"

int checkAccount();

BANK atm[2];

int main() {
    while(1)
    {
        int id_idx = checkAccount();
        if(id_idx==!-1)
        {
            while(1) 
            {
                int num=0;
                std::cout << "0.EXIT 1. DEPOSIT 2.NEW 3.WITHDRAW 4.REMITTANCE" << std::endl;
                std::cin>>num;
                if (num == 0) break;
                else if (num == 1) atm[id_idx].depositFunc();
                else if (num == 2) atm[id_idx].accountFunc();
                else if (num == 3) atm[id_idx].withdrawFunc();
                else if (num == 4)
                {
                    remittance(id_idx);             
                }
            }
        }
        std::cout<<"아이디또는 비밀번호가 잘못되었습니다. 다시 입력해주십시오."<<std::endl;
    }
    return 0;
}

int checkAccount() {
    std::string name, password;
    std::cout << "Input the account name" << std::endl;
    std::cin >> name;
    std::cout << "Input the account password" << std::endl;
    std::cin >> password;
    for (int i = 0; i < 2; i++)
    {
        if (atm[i].getName() == name)
        {
            if (atm[i].getPassword() == password) 
            {
                return i;
            }
        }
    }
    return -1;
}

void remittance(int n)
{
    std::string name;
    std::cout<<"상대의 아이디를 입력하시오.";
    std::cin>>name;

    int num = atm[n].remittanceFunc(n);

    for(int i=0;i<2;i++)
    {
        if(atm[i].getName()==name)
        {
            if(num==0)
            {
                return;
            }
            atm[i].setMoney(atm[i].getmoney()-num);
            std::cout<<"송금이 완료되었습니다."<<std::endl;
            std::cout<<"현제 잔액 "<<atm[n].getmoney() << "원입니다. " <<std::endl<<"송금 금액 "<<num<<"원 입니다."<<std::endl;
        }
 
    }
}
/*
int main() 

{
    while(1)

    {
        //int num=0;
        std::cout << "0.EXIT 1. DEPOSIT 2.NEW 3.WITHDRAW 4.REMITTANCE" << std::endl;    //옵션
        std::cin>>num;
        if(num==0)  //종료
        {
            break; 
        }
        else if(num==1)   //예금
        {
            deposit();   
        }
        else if(num==2)  //계좌 건설
        {
            accountFunc();
        }
        else if (num==3)   //출금
        {
            withdraw();
        }
        else if(num==4)  //송금
        {
            Remittance();
        }
    }
    return 0;
}


void deposit()     
{
    std::cout<<"다시 옵션으로 돌아가고 싶다면 0을 입력하시오"<<std::endl;
    std::cout<<"아이디를 입력하시오: ";
    std::cin >>name>>std::endl;
    if(ID(name))
    {
        return;
    }
    if (account==0)  
    {
        std::cout << "No Account" << std::endl;
        return;
    }
    else if (account==1)
    {
        Passward();
        if(account==1)
        {
            std::cout << "How much : ";
            //std::cout<<"예급할 금액을 입력하시오. ";
            std::cin>>money[0][0];
            if(money[0][0]==0)   //나가기
            {
                return;
            }
            accountmoney[turn]=money[0][0]+accountmoney[turn]; 
            std::cout << "Deposit complete" << std::endl;
            std::cout << "Current : " << accountmoney[turn] << "WON" << std::endl;
            return;
            //std::cout<<"예금이 완료되었습니다."<<std::endl;
            //std::cout<<"현재 잔액"<<accountmoney<<" 원 입니다."<<std::endl;
        }
        
    }
    std::cout<<"비밀번호가 틀렸습니다. 다시입력해 주십시오"<<std::endl;
    account=0;
    return;
}

void accountFunc()   //계좌 건설
{
    std::cout<<"다시 옵션으로 돌아가고 싶다면 0을 입력하시오"<<std::endl;
    std::cout<<"아이디를 입력하시오: ";
    std::cin >>name>>std::endl;
    // duplication check.
    if(ID(name))
    {
        return;
    }
    if(0==ID(name))
    {
        std::cout<<"이미 있는 아이디 입니다."<<std::endl;
        return;
    }

    passward();
    if (account==1)   //계좌 유무 확인
    {
        std::cout << "There has been an passward already" << std::endl;
        //std::cout<<"이미 있는 비밀번호입니다."<<std::endl;
    }
    else if (account==0)
    {
        std::cout<<"비밀번호를 입력하시오: "
        std::cin >>passward>>std::endl;
     
        Impormate[sizeof(Impormate)][0]=name;
        Impormate[sizeof(Impormate)][1]=passward;
        std::cout<< "Made a new account" << std::endl;
        //std::cout<<"계좌가 개설되었습니다."<<std::endl;
    }
    return;
}
 
void withdraw()  //출금
{
    std::cout<<"다시 옵션으로 돌아가고 싶다면 0을 입력하시오"<<std::endl;
    std::cout<<"아이디를 입력하시오: ";
    std::cin >>name>>std::endl;
    if(ID(name))
    {
        return;
    }
    if(account==0)
    {
        std::cout<<"입력하신 아이디는 없는 아이디 입니다. 다시 입력해 주십시오"<<std::endl;
        return;
    }        
    else if(account==1)
    {
        Passward();
        if(account=1)
        {
            std::cout << "How much : ";
            //std::cout<<"출금할 액수를 입력하시오. ";
            std::cin>>money[0][0];
            if(money[0][0]==0)
            {
                return;
            }
            else if (money[0][0]>accountmoney[turn])  //입력한 금액이 통장 잔액보다 높을 경우 다시 옵션선택으로 이동
            {
                std::cout << "Not enought money" << std::endl;
                //std::cout<<"입력하신 금액"<<accountmoney<<"원 보다 "<<money-accountmoney<<"원 만큼 더 많이 입력하셨습니다."<<std::endl<<"다시 입력해 주십시오."<<std::endl;
                return;
            }
            accountmoney[turn]=accountmoney[turn]-money[0][0];
            std::cout << "Withdraw complete" << std::endl;
            std::cout << "Current : " << accountmoney[turn] << "WON" << std::endl;
            //std::cout<<money<<"가 성공적으로 출금 되었습니다."<<std::endl<<"현제 통장 잔액은 "<<accountmoney<<"입니다."<<std::endl;
        }
    }
}
 
int ID(std::string n)   //이이디 비교
{
    turn=0;
    // return option.
    if(n=="0")
    {
        return 1;
    }
    for(int i=0;i<100;i++)
    {
        if(n==Impormate[i][0])
        {
            account=1;
            turn=i;
            return 0;
        }
    }
    return 2;
}
 
void Passward()  //비밀번호 비교
{
    std::cout << "비밀번호를 입력하시오: ";
    std::cin >>passward>>std::endl;
    account=0;
    if(passward==Impormate[turn][1])
    {
        account=1;
    }
}
 
void Remittance()
{
    std::cout<<"다시 옵션으로 돌아가고 싶다면 0을 입력하시오"<<std::endl;
    std::cout<<"먼저 상대의 아이디를 입력하시오: ";
    std::cin >>name>>std::endl;
    if(ID(name))
    {
        return;
    }
    if(ID(name)==1)
    {
        money[0][0]=accountmoney[turn];
        money[0][1]=turn;
        std::cout<<"송할 상대의 아이디를 입력하시오. "<<std::endl;
        std::cin >>nae>>std::endl;
        if(ID(name)
        {
           return;
        }
        if(ID(name)==1)
        {
            money[1][1]=turn;
            std::cout<<"송금할 금액을 입력하시오";
            std::cin>>money[1][0]>>std::endl;
            if(accountmoney[money[0][0]]<money[1][0])
            {
                std::cout<<"송금할 금액이 가지고 계신 금액보다 많습니다."<<std::endl;
                return;
 
            }
            accountmoney[money[0][1]]=accountmoney[money[0][1]]-money[0][0];
            accountmoney[money[1][1]]=accountmoney[money[1][1]]+money[1][0];
            std::cout<<"송금 되었습니다."<<std::endl;
            std::cout<<"현제"<<accountmoney[money[0][1]]<<"원 남았습니다."<<std::endl;
        }
    }
}

*/




