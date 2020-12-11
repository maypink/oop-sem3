#pragma once
#include <vector>
#include <map>
#include "Client.h"
#include "DebitAccount.h"
#include "Deposit.h"
#include "CreditAccount.h"
#include <iostream>
#include <cassert>

class Bank {

private:

	std::string bank_id;

	std::vector <std::pair<Client, std::vector<Account*>>> accounts;

	std::vector<std::pair<std::string, int>> accountsAmounts;

	std::vector<std::pair<std::string, float>> accountsTerms;

	int depositTerm;

	float creditLimit, doubtfulLimit;

public:

	Bank(std::string bank_id, float percentDebit, float percentDeposit, float percentCredit, int depositTerm, float creditLimit, float doubtfullLimit);

	void ShowAll();

	std::string GetID();

	float GetBalance(std::string id);

	void CreateAccountForClient(Client client, std::string account_type, float summ);

	std::string GenerateAccountID(std::string account_type);

	void CreateDebitAccount(Client client, float summ);

	void CreateDepositAccount(Client client, float summ);

	void CreateCreditAccount(Client client, float summ);

	bool CheckExistence(std::string id);

	void CashWithdrawal(std::string idSender, float summ);

	bool CheckThePerson(std::string id);

	void Refill(std::string id, float summ);

	void LastTransfer(std::string idSender, std::string idRecipient, float summ);

	std::pair<int, float> RewindTime(std::string id, int days);

	void CancelTransaction(std::string type, std::string id, std::string id2, float summ);

} ;
