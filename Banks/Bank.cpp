#include "Bank.h"


Bank::Bank(std::string bank_id, float percentDebit, float percentDeposit, float percentCredit, int depositTerm, float creditLimit, float doubtfullLimit) {

	this->bank_id = bank_id;

	accountsAmounts.push_back(std::make_pair("debit", 0));

	accountsAmounts.push_back(std::make_pair("deposit", 0));

	accountsAmounts.push_back(std::make_pair("credit", 0));

	accountsTerms.push_back(std::make_pair("debit", percentDebit));

	accountsTerms.push_back(std::make_pair("deposit", percentDeposit));

	accountsTerms.push_back(std::make_pair("credit", percentCredit));

	this->depositTerm = depositTerm;

	this->creditLimit = creditLimit;

	this->doubtfulLimit = doubtfullLimit;

}

void Bank::ShowAll() {

	for (int i = 0; i < accounts.size(); ++i) {
		std::cout << "\nNAME: " << accounts[i].first.GetName();
		std::cout << "\nSURNAME: " << accounts[i].first.GetSurname();
		std::cout << "\nAccounts:\n";
		std::cout << "\nID" << "           " << "BALANCE\n";
		for (int j = 0; j < accounts[i].second.size(); ++j) {
			std::cout << accounts[i].second[j]->GetID() << "           " << accounts[i].second[j]->GetBalance() << "\n";
		}
	}
}

std::string Bank::GetID() {

	return this->bank_id;

}

float Bank::GetBalance(std::string id) {

	for (int i = 0; i < accounts.size(); i++) {
		for (int j = 0; j < accounts[i].second.size(); j++) {
			if (accounts[i].second[j]->GetID() == id)
				return accounts[i].second[j]->GetBalance();
		}
	}
}

void Bank::CreateAccountForClient(Client client, std::string account_type, float summ) {

	int buf = -1;
	for (int i = 0; i < accounts.size(); i++) {
		Client curClient = accounts[i].first;
		if (curClient.GetName() == client.GetName() && curClient.GetSurname() == client.GetSurname() && curClient.GetAddress() == client.GetAddress() && curClient.GetPassport() == client.GetPassport()) {
			buf = i;
			break;
		}
	}
	if (buf != -1)
		throw ExistenceError();


	if (account_type == "debit") {
		std::vector <Account*> curAccounts;
		curAccounts.push_back(new DebitAccount(GenerateAccountID(account_type), summ, this->accountsTerms[0].second));
		accounts.push_back(std::make_pair(client, curAccounts));
	}
	else if (account_type == "deposit") {
		std::vector <Account*> curAccounts;
		curAccounts.push_back(new Deposit(GenerateAccountID(account_type), summ, this->accountsTerms[0].second, this->depositTerm));
		accounts.push_back(std::make_pair(client, curAccounts));
	}
	else if (account_type == "credit") {
		std::vector <Account*> curAccounts;
		curAccounts.push_back(new CreditAccount(GenerateAccountID(account_type), summ, this->creditLimit, this->accountsTerms[0].second));
		this->accounts.push_back(std::make_pair(client, curAccounts));
	}
}

std::string Bank::GenerateAccountID(std::string account_type) {

	int amount = 0;
	for (int i = 0; i < accountsAmounts.size(); ++i) {
		if (account_type == accountsAmounts[i].first) {
			amount = accountsAmounts[i].second;
			accountsAmounts[i].second++;
			break;
		}

	}
	std::string id = "";

	assert(account_type == "debit" || account_type == "deposit" || account_type == "credit");

	if (account_type == "debit")
		id = bank_id + std::to_string(000) + std::to_string(amount);
	else if (account_type == "deposit")
		id = bank_id + std::to_string(001) + std::to_string(amount);
	else if (account_type == "credit")
		id = bank_id + std::to_string(002) + std::to_string(amount);

	return id;
}

void Bank::CreateDebitAccount(Client client, float summ) {

	int buf = -1;
	for (int i = 0; i < accounts.size(); i++) {
		Client curClient = accounts[i].first;
		if (curClient.GetName() == client.GetName() && curClient.GetSurname() == client.GetSurname() && curClient.GetAddress() == client.GetAddress() && curClient.GetPassport() == client.GetPassport()) {
			buf = i;
			break;
		}
	}

	if (buf != -1) {

		float percent = this->accountsTerms[0].second;
		accounts[buf].second.push_back(new DebitAccount(GenerateAccountID("debit"), summ, percent));

	}
	else {
		std::vector<Account*> buff;
		float percent = this->accountsTerms[0].second;
		buff.push_back(new DebitAccount(GenerateAccountID("debit"), summ, percent));
		accounts.push_back(std::make_pair(client, buff));

	}

}

void Bank::CreateDepositAccount(Client client, float summ) {

	int buf = -1;
	for (int i = 0; i < accounts.size(); i++) {
		Client curClient = accounts[i].first;
		if (curClient.GetName() == client.GetName() && curClient.GetSurname() == client.GetSurname() && curClient.GetAddress() == client.GetAddress() && curClient.GetPassport() == client.GetPassport()) {
			buf = i;
			break;
		}
	}

	if (buf != -1) {
		float percent = this->accountsTerms[1].second;
		int term = this->depositTerm;
		accounts[buf].second.push_back(new Deposit(GenerateAccountID("deposit"), summ, percent, term));

	}
	else {
		std::vector<Account*> buff;
		float percent = this->accountsTerms[1].second;
		int term = this->depositTerm;
		buff.push_back(new Deposit(GenerateAccountID("deposit"), summ, percent, term));
		accounts.push_back(std::make_pair(client, buff));

	}

}

void Bank::CreateCreditAccount(Client client, float summ) {

	int buf = -1;
	for (int i = 0; i < accounts.size(); i++) {
		Client curClient = accounts[i].first;
		if (curClient.GetName() == client.GetName() && curClient.GetSurname() == client.GetSurname() && curClient.GetAddress() == client.GetAddress() && curClient.GetPassport() == client.GetPassport()) {
			buf = i;
			break;
		}
	}
	if (buf != -1) {
		float limit = this->creditLimit;
		float commission = this->accountsTerms[2].second;
		accounts[buf].second.push_back(new CreditAccount(GenerateAccountID("credit"), summ, limit, commission));

	}
	else {
		std::vector<Account*> buff;
		float limit = this->creditLimit;
		float commission = this->accountsTerms[2].second;
		buff.push_back(new CreditAccount(GenerateAccountID("credit"), summ, limit, commission));
		accounts.push_back(std::make_pair(client, buff));

	}

}

bool Bank::CheckExistence(std::string id) {

	for (int j = 0; j < accounts.size(); ++j) {
		for (int i = 0; i < accounts[j].second.size(); ++i) {
			if (accounts[j].second[i]->GetID() == id)
				return true;
		}
	}
	return false;

}

void Bank::CashWithdrawal(std::string idSender, float summ) {

	int flag = 0;
	if (!CheckExistence(idSender))
		throw ExistenceError();

	if (CheckThePerson(idSender) && summ > this->doubtfulLimit) {
		std::cout << "This client cannot transfer the full amount of money, since the bank considers his profile to be dubious."
			<< "He can only transfer" << doubtfulLimit << " rubles.\n";
		summ = doubtfulLimit;
	}
	else if (CheckThePerson(idSender)) {
		std::cout << "The account holder is considered questionable. Add address information and passport details.\n";
	}

	for (int j = 0; j < accounts.size(); ++j) {
		for (int i = 0; i < accounts[j].second.size(); i++) {
			if (accounts[j].second[i]->GetID() == idSender) {
				accounts[j].second[i]->CashWithDrawal(summ);
				flag++;
			}

		}
	}

	if (flag != 1)
		throw ExcessError();

}

bool Bank::CheckThePerson(std::string id) {

	for (int j = 0; j < accounts.size(); ++j) {
		for (int i = 0; i < accounts[j].second.size(); i++) {
			if (accounts[j].second[i]->GetID() == id) {
				if (accounts[j].first.GetAddress() != "" && accounts[j].first.GetPassport() != "") {
					return 0; //все ок
				}
			}
		}
	}
	return 1;
}

void Bank::Refill(std::string id, float summ) {

	for (int j = 0; j < accounts.size(); ++j) {
		for (int i = 0; i < accounts[j].second.size(); i++) {

			if (accounts[j].second[i]->GetID() == id) {
				accounts[j].second[i]->Refill(summ);
			}
		}
	}
}

void Bank::LastTransfer(std::string idSender, std::string idRecipient, float summ) {

	for (int j = 0; j < accounts.size(); ++j) {
		for (int i = 0; i < accounts[j].second.size(); i++) {
			if (accounts[j].second[i]->GetID() == idSender) {
				accounts[j].second[i]->Transfer("drawal", idRecipient, summ);
			}
			if (accounts[j].second[i]->GetID() == idRecipient) {
				accounts[j].second[i]->Transfer("refill", idSender, summ);
			}
		}
	}
}

std::pair<int, float> Bank::RewindTime(std::string id, int days) {

	for (int j = 0; j < accounts.size(); ++j) {
		for (int i = 0; i < accounts[j].second.size(); i++) {
			if (accounts[j].second[i]->GetID() == id) {
				return accounts[j].second[i]->RewindTime(days);
			}
		}
	}
}

void Bank::CancelTransaction(std::string type, std::string id, std::string id2, float summ) { //транзакция id->id2

	for (int i = 0; i < accounts.size(); ++i) {
		for (int j = 0; j < accounts[i].second.size(); ++j) {
			if (accounts[i].second[j]->GetID() == id) {
				accounts[i].second[j]->CanselTransaction(type, id2, summ);
			}
		}
	}
}