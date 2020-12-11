#pragma once
#include "Bank.h"

class BankManager {

private:

	std::vector <std::pair<Bank, std::vector<Client>>> banks;

public:

	BankManager() = default;

	void CreateNewBank(float percentDebit, float percentDeposit, float percentCredit, int depositTerm, float creditLimit, float doubtfullLimit);

	void CreateAccountForClient(Client client, std::string bankID, std::string account_type, float summ);

	void CreateDebitAccount(Client client, std::string bankID, float summ);

	void CreateDepositAccount(Client client, std::string bankID, float summ);

	void CreateCreditAccount(Client client, std::string bankID, float summ);

	void ShowAll();

	void Refill(std::string id, float summ);

	void CashWithdrawal(std::string id, float summ);

	void TransferMoney(std::string idRecipient, std::string idSender, float summ);

	float GetBalance(std::string id);

	void RewindTime(std::string id, int days);

	void CancellTransaction(std::string type, std::string id, std::string id2, float summ);

};