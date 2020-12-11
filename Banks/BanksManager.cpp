#include "BanksManager.h"

void BankManager::CreateNewBank(float percentDebit, float percentDeposit, float percentCredit, int depositTerm, float creditLimit, float doubtfullLimit) {

	Bank newBank(std::to_string(banks.size()), percentDebit, percentDeposit, percentCredit, depositTerm, creditLimit, doubtfullLimit);
	std::vector<Client> newClients;
	banks.push_back(std::make_pair(newBank, newClients));

}

void BankManager::CreateAccountForClient(Client client, std::string bankID, std::string account_type, float summ) {

	for (int i = 0; i < banks.size(); ++i) {
		if (banks[i].first.GetID() == bankID) {
			banks[i].first.CreateAccountForClient(client, account_type, summ);
		}
	}
}

void BankManager::CreateDebitAccount(Client client, std::string bankID, float summ) {

	for (int i = 0; i < banks.size(); ++i) {
		if (banks[i].first.GetID() == bankID) {
			banks[i].first.CreateDebitAccount(client, summ);
		}
	}
}

void BankManager::CreateDepositAccount(Client client, std::string bankID, float summ) {

	for (int i = 0; i < banks.size(); ++i) {
		if (banks[i].first.GetID() == bankID) {
			banks[i].first.CreateDepositAccount(client, summ);
		}
	}

}

void BankManager::CreateCreditAccount(Client client, std::string bankID, float summ) {
	
	for (int i = 0; i < banks.size(); ++i) {
		if (banks[i].first.GetID() == bankID) {
			banks[i].first.CreateCreditAccount(client, summ);
		}
	}

}

void BankManager::ShowAll() {
	for (int i = 0; i < banks.size(); ++i) {
		std::cout << " \n\n\nBANK" << banks[i].first.GetID() << "\n";
		banks[i].first.ShowAll();
	}
}

void BankManager::Refill(std::string id, float summ) {

	for (int i = 0; i < banks.size(); ++i) {
		if (banks[i].first.GetID() == id) {
			banks[i].first.Refill(id, summ);
		}
	}
}

void BankManager::CashWithdrawal(std::string id, float summ) {

	for (auto it = banks.begin(); it != banks.end(); it++) {
		Bank bank = (*it).first;
		if (bank.GetID() == id) {
			bank.CashWithdrawal(id, summ);
		}
	}

}

void BankManager::TransferMoney(std::string idRecipient, std::string idSender, float summ) {
	std::string recipientBankID = idRecipient.substr(0, 1);
	std::string senderBankID = idSender.substr(0, 1);

	for (int i = 0; i < banks.size(); ++i) {
		if (banks[i].first.GetID() == senderBankID) {
			banks[i].first.CashWithdrawal(idSender, summ);
			banks[i].first.LastTransfer(idSender, idRecipient, summ);
		}
		if (banks[i].first.GetID() == recipientBankID) {
			banks[i].first.Refill(idRecipient, summ);
			banks[i].first.LastTransfer(idSender, idRecipient, summ);
		}
	}
}

float BankManager::GetBalance(std::string id) {
	std::string ID = id.substr(0, 3);
	for (int i = 0; i < banks.size(); ++i) {
		if (banks[i].first.GetID() == ID) {
			return banks[i].first.GetBalance(id);
		}
	}
}

void BankManager::RewindTime(std::string id, int days) {
	std::string ID = id.substr(0, 1);
	for (int i = 0; i < banks.size(); ++i) {
		if (banks[i].first.GetID() == ID) {
			std::cout << "After " << banks[i].first.RewindTime(id, days).first << " days the deposit will be " << banks[i].first.RewindTime(id, days).second << "\n";
		}
	}
}

void BankManager::CancellTransaction(std::string type, std::string id, std::string id2, float summ) {
	std::string bankID = id.substr(0, 1);
	for (int i = 0; i < banks.size(); ++i) {
		if (banks[i].first.GetID() == bankID) {
			if (type == "transfer")
				banks[i].first.CancelTransaction("refill", id, id2, summ);
			else {
				banks[i].first.CancelTransaction(type, id, id2, summ);
			}
		}
	}
	if (id2 != "") {
		std::string bankID = id2.substr(0, 1);
		for (int i = 0; i < banks.size(); ++i) {
			if (banks[i].first.GetID() == bankID) {
				if (type == "transfer")
					banks[i].first.CancelTransaction("drawal", id2, id, summ);
				else {
					banks[i].first.CancelTransaction(type, id, id2, summ);
				}
			}
		}
	}
}