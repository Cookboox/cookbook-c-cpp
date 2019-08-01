#pragma once
#include <vector>
#include "Account.h"
#include "SavingAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"


void display_all(std::vector<Account> &vec_acc);
void deposit_to_all(std::vector<Account> &vec_acc, double const& amount);
void withdraw_from_all(std::vector<Account> &vec_acc, double const& amount);

//SavingAccounts
void display_all(std::vector<SavingAccount> &vec_sacc);
void deposit_to_all(std::vector<SavingAccount> &vec_sacc, double const& amount);
void withdraw_from_all(std::vector<SavingAccount> &vec_sacc, double const& amount);

//CheckingAccounts
void display_all(std::vector<CheckingAccount>& vec_cacc);
void deposit_to_all(std::vector<CheckingAccount>& vec_cacc, double const& amount);
void withdraw_from_all(std::vector<CheckingAccount>& vec_cacc, double const& amount);

////TrustAccounts
void display_all(std::vector<TrustAccount>& v);
void deposit_to_all(std::vector<TrustAccount>& vec_tacc, double const& amount);
void withdraw_from_all(std::vector<TrustAccount>& vec_tacc, double const& amount);