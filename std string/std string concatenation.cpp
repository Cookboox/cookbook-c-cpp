#include<iostream>
#include<string>



int main()
{
    std::string ct_s1 = "CREATE TABLE IF NOT EXISTS ";
    std::string ct_s2 = "intraday ";
    std::string ct_s3 = "(symbol varchar(100), qty int, entry_datetime datetime, exit_datetime datetime, entry_price float, profit_loss float, cummulative_pl float)";
    ct_s1 += ct_s2 += ct_s3;
    const char * query_create_table = ct_s1.c_str();
    
    std::cout << "1: " << ct_s1 << "\n";
    std::cout << "2: " << query_create_table << "\n";






    
    return 0;
}
