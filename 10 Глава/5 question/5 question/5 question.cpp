#include <iostream>
#include <string>
#include <vector>

template <typename CheckIdT, typename BalanceT>
struct ClientInfo {
    std::string m_client_name;
    CheckIdT m_check_id;
    BalanceT m_balance;
};

template <typename CheckIdT, typename BalanceT> class Check {
private:
    std::string m_client_name;
    CheckIdT m_check_id;
    BalanceT m_balance;
public:
    Check(std::string client_name, CheckIdT check_id);
    void Add(BalanceT balance);
    bool Get(BalanceT balance);
    ClientInfo<CheckIdT, BalanceT> GetInfo();
};

template <typename CheckIdT, typename BalanceT>
Check<CheckIdT, BalanceT>::Check(std::string client_name, CheckIdT check_id) {
    m_client_name = client_name;
    m_check_id = check_id;
    m_balance = 0;
}

template <typename CheckIdT, typename BalanceT>
void Check<CheckIdT, BalanceT>::Add(BalanceT balance) {
    m_balance += balance;
}

template <typename CheckIdT, typename BalanceT>
bool Check<CheckIdT, BalanceT>::Get(BalanceT balance) {
    if (m_balance < balance) return false;
    else {
        m_balance -= balance;
        return true;
    }
}

template <typename CheckIdT, typename BalanceT>
ClientInfo<CheckIdT, BalanceT> Check<CheckIdT, BalanceT>::GetInfo() {
    ClientInfo<CheckIdT, BalanceT> info = {m_client_name, m_check_id, m_balance};
    return info;
}

int main()
{
    Check<long long int, long long int> first("Golovko Yaroslav", 1);
    ClientInfo<long long int, long long int> info;
    first.Add(1000);
    first.Add(12345);
    info = first.GetInfo();
    std::cout << info.m_client_name << std::endl;
    std::cout << info.m_check_id << std::endl;
    std::cout << info.m_balance << std::endl;
    first.Get(10000);
    info = first.GetInfo();
    std::cout << info.m_client_name << std::endl;
    std::cout << info.m_check_id << std::endl;
    std::cout << info.m_balance << std::endl;
    first.Get(10000);
    info = first.GetInfo();
    std::cout << info.m_client_name << std::endl;
    std::cout << info.m_check_id << std::endl;
    std::cout << info.m_balance << std::endl;
}