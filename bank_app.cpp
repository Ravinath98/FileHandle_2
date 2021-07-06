#include <iostream>
#include <fstream> //library for crreate,reads and writes to files
#include <iomanip> //to get the precision
#include <cmath>   //for mathematical functions (abs)
#include <stdio.h>
#include <string>
#include <sstream>
#include <cstdio>
using namespace std;

struct node   //structure node...
{
	int accountNo;
	int checkingValue;
	int dateT;
	long double updatedBalance;
	long double updateBankBalance;

	struct node* next;
	struct node* prev;
};

class LinkedList    //linked list class..
{
private:
	node* start;   //starting node..
	
public:

	void insertEnd(int x, int y);   //start node at the begining
	int search(int f);	//search a given value in the list
	void searchbAndChange(long double o, int v);
	void listValue();
	void insertEndUpdated(long double n1, int m1);
	void insertEndb(long double p, int q);
	long double searchBalance(int w);
	void searchAndChange(long double a1, int b1);

};

void LinkedList::listValue()  //set start and end pointers to NULL
{
	start = NULL;  //Begining list is empty..
	
}
void LinkedList::insertEnd(int x, int y)  //insert a node at the end..
{
	node* newNode; //define a new node...
	node* temp;
	newNode = new node; //allocate memory...
	newNode->accountNo = x;
	newNode->checkingValue = y;
	temp = start;
	if (start == NULL)
	{
		start = newNode;
		newNode->prev = NULL;
		newNode->next = NULL;
		return;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
		newNode->next = NULL;
		return;
	}

}
void LinkedList::insertEndUpdated(long double n1, int m1)  //insert a node at the end..
{
	node* newNode; //define a new node...
	node* temp;
	newNode = new node; //allocate memory...
	newNode->updatedBalance = n1;
	newNode->accountNo = m1;
	
	temp = start;
	if (start == NULL)
	{
		start = newNode;
		newNode->prev = NULL;
		newNode->next = NULL;
		return;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
		newNode->next = NULL;
		return;
	}


}
void LinkedList::insertEndb(long double p, int q)  //insert a node at the end..
{
	node* newNode; //define a new node...
	node* temp;
	newNode = new node; //allocate memory...
	newNode->accountNo = q;
	newNode->updateBankBalance = p;
	temp = start;
	if (start == NULL)
	{
		start = newNode;
		newNode->prev = NULL;
		newNode->next = NULL;
		return;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newNode;
		newNode->prev = temp;
		newNode->next = NULL;
		return;
	}


}

int LinkedList::search(int f) 
{
	node* temp;
	temp = start;
	while (temp != NULL)
	{
		if (temp->accountNo == f)
		{

			return temp->checkingValue;  //if found....
		}
		temp = temp->next;
	}

	return -1; //if not found....

}

void LinkedList::searchbAndChange(long double o, int v) //search an existing element...
{
	node* temp;
	temp = start;
	while (temp != NULL)
	{
		if (temp->accountNo == v)
		{

			temp->updateBankBalance;  //if found....
		}
		temp = temp->next;
	}

	return; //if not found....


}
long double LinkedList::searchBalance(int w) //search an existing element...
{
	node* temp;
	temp = start;
	while (temp != NULL)
	{
		if (temp->accountNo == w)
		{

			return temp->updatedBalance;  //if found....
		}
		temp = temp->next;
	}

	return -1; //if not found....


}
void LinkedList::searchAndChange(long double a1, int b1) //search an existing element...
{
	node* temp;
	temp = start;
	while (temp != NULL)
	{
		if (temp->accountNo == b1)
		{

			temp->updatedBalance = a1;  //if found....
		}
		temp = temp->next;
	}

	return; //if not found....

}
using namespace std;

int main()
{
	///delete text files if available in the folder
	char fileNam1[] = "account_1.txt";
	remove(fileNam1);
	char fileNam2[] = "account_2.txt";
	remove(fileNam2);
	char fileNam3[] = "account_3.txt";
	remove(fileNam3);
	char fileNam4[] = "account_4.txt";
	remove(fileNam4);
	char fileNam5[] = "account_5.txt";
	remove(fileNam5);
	char fileNam6[] = "account_6.txt";
	remove(fileNam6);
	char fileNam7[] = "account_7.txt";
	remove(fileNam7);
	char fileNam8[] = "account_8.txt";
	remove(fileNam8);
	char fileNam9[] = "account_9.txt";
	remove(fileNam9);
	char fileNam10[] = "account_10.txt";
	remove(fileNam10);
	long double currentBalances[11];
	long double lastBank;
	LinkedList accDetailsList, list2, list3;
	accDetailsList.listValue();
	list2.listValue();
	list3.listValue();
	ifstream balance;  //read the text file(variable)
	ifstream transaction;
	ofstream account_bank("account-bank.txt");  //for the bank accounts...

	balance.open("balance.txt");    //open the first text file
	if (!balance)    //if file cannot open....
	{
		cout << "Unable to open the text file!!!!" << endl;
		return 0;
	}

	transaction.open("transaction.txt");
	if (!transaction)    //if file cannot open....
	{
		cout << "Unable to open the text file!!!!" << endl;
		return 0;
	}

	string accDetailLine;
	int check = 0;  //checking variable for bank....
	balance >> accDetailLine;
	long double updatedBalBAcc;

	while (balance.good())
	{
		int size = accDetailLine.length();
		//check the correctness of accounts details..
		int commas = 0;
		for (int i = 0; i < size; i++)
		{
			if (accDetailLine[i] == ',')
			{
				commas = commas + 1;
			}
		}
		if (commas == 2)
		{
			int tempory1, tempory;
			long double balanceb;
			long double bankbalrest;
			//below here
			if (check == 0) //check for bank account(This is for the bank account)
			{

				int k1 = 0;

				string dateb;
				while (accDetailLine[k1] != ',')
				{
					dateb += accDetailLine[k1];
					k1 = k1 + 1;

				}
				int date1 = stoi(dateb);
				account_bank << to_string(date1); //text file
				account_bank << ',';   //text file
				account_bank << '0';  //text file
				account_bank << ',';   //text file

				k1 = k1 + 1;

				string accno_b;
				while (accDetailLine[k1] != ',')
				{
					accno_b += accDetailLine[k1];
					k1 = k1 + 1;

				}
				k1 = k1 + 1;
				tempory = stoi(accno_b);
				accDetailsList.insertEnd(tempory, check);
				string amount;  //store opening balance(I got maximum digit size as 20)

				while (accDetailLine[k1] != '.')  //to get the integer part
				{
					amount += accDetailLine[k1];
					k1 = k1 + 1;


				}
     			int temp1 = stof(amount);
				cout << fixed;
				cout << setprecision(2);
				long double floating = 0.01 * ((accDetailLine[k1 + 1] - '0') * 10 + (accDetailLine[k1 + 2] - '0'));  //get the decimal part
				balanceb = temp1 + floating;  //get the entire balance value...
				bankbalrest = balanceb;
				list3.insertEndb(balanceb, tempory);

				list2.insertEndUpdated(balanceb, tempory); ////////////////////////////////

				ostringstream oss; //convert to string(that balance value)
				oss << fixed;   //to string
				oss << setprecision(2);  //set precision
				oss << balanceb;

				account_bank << oss.str();   //text file(store as a string)	
				account_bank << ",";   //text file
				account_bank << oss.str();   //updated balance...
				account_bank << endl;
				

			}
			else  //if not the bank account(for user accounts)....
			{

				ofstream account;  //write..
				account.open("account-" + to_string(check) + ".txt", ios::app);  //open text files for user accounts....


				int k2 = 0;
				string dateb;
				while (accDetailLine[k2] != ',')
				{
					dateb += accDetailLine[k2];
					k2 = k2 + 1;
				}

				int date1 = stoi(dateb); //dateeeeeeeeeeeeeeeeeeee
				account << to_string(date1); //text file
				account << ',';   //text file
				account << '0';  //text file
				account << ',';   //text file

				k2 = k2 + 1;

				string accno_u;
				while (accDetailLine[k2] != ',')
				{
					accno_u += accDetailLine[k2];
					k2 = k2 + 1;

				}
				k2 = k2 + 1;

				tempory1 = stoi(accno_u);  /////////////////account nooooo
				accDetailsList.insertEnd(tempory1, check);
				string amount;  //store opening balance(I got maximum digit size as 20)
				while (accDetailLine[k2] != '.')  //to get the integer part
				{
					amount += accDetailLine[k2];
					k2 = k2 + 1;
				}
				int temp1 = stof(amount);
				cout << fixed;
				cout << setprecision(2);
				long double floating = 0.01 * ((accDetailLine[k2 + 1] - '0') * 10 + (accDetailLine[k2 + 2] - '0'));  //get the decimal part
				long double balanceu = temp1 + floating;  //get the entire balance value...

				long double interest = balanceu * 0.0002;
				cout << fixed;
				cout << setprecision(2);
				long double total = interest + balanceu;
				cout << fixed;
				cout << setprecision(2);

				updatedBalBAcc = list2.searchBalance(111111) - interest;
				list2.searchAndChange(updatedBalBAcc, 111111);
				
				list2.insertEndUpdated(total, tempory1);

				list2.insertEndUpdated(updatedBalBAcc, 111111); ///////////////////////////////bank..........
				ostringstream pre; //convert to string(that balance value)
				pre << fixed;   //to string
				pre << setprecision(2);  //set precision
				pre << balanceu;

				account << pre.str();   //text file(store as a string)	
				account << ",";   //text file
				account << pre.str();   //text file
				//
				if (balanceu > 0)
				{
					account << endl;
					account << to_string(date1); //text file
					account << ',';   //text file
					account << '3';  //text file
					account << ',';   //text file
					ostringstream pre3, pre4;
					pre3 << fixed;
					pre3 << setprecision(2);
					pre3 << interest;
					account << pre3.str();
					account << ",";
					pre4 << fixed;
					pre4 << setprecision(2);
					pre4 << total;
					account << pre4.str();

					//bank..
					ofstream linkBank;  //update the opening  balance with interests....
					linkBank.open("account-bank.txt", std::ios_base::app);
					linkBank << endl;
					linkBank << to_string(date1); //text file
					linkBank << ',';   //text file
					linkBank << '3';  //text file
					linkBank << ',';   //text file
					ostringstream pre5, pre6;
					pre5 << fixed;
					pre5 << setprecision(2);
					pre5 << interest;
					linkBank << pre5.str();
					linkBank << ",";
					pre6 << fixed;
					pre6 << setprecision(2);
					pre6 << updatedBalBAcc;
					linkBank << pre6.str();


				}

			}
			check = check + 1;
			balance >> accDetailLine;
		}
		else
		{
			cout << "Wrong Bank details!!" << endl;
			balance >> accDetailLine;
		}
	}
	cout << endl << endl;
	string transactionLine;
	transaction >> transactionLine;
	long double balan;
	while (transaction.good())
	{

		ofstream updateText;
		ofstream bankText;
		int sizeT = transactionLine.length();
		string dateTra; //date of the transaction
		int i = 0;
		while (transactionLine[i] != ',')
		{
			dateTra += transactionLine[i];
			i = i + 1;
		}
		int datex = stoi(dateTra);
		i = i + 1;
		string accno;  //account no of the transaction
		while (transactionLine[i] != ',')
		{
			accno += transactionLine[i];
			i = i + 1;
		}
		int acc = stoi(accno); //transaction account no.//////////////////////
		i = i + 1;
		int ttype = transactionLine[i] - '0';  //transaction type..

		string amountT;
		i = i + 2;
		while (i < sizeT)
		{
			amountT += transactionLine[i];
			i = i + 1;
		}

		int amou = stoi(amountT);  //transaction amount..

		long double updatedBalanceUAcc;  //updated bank account balance
		if (ttype == 1)
		{
			updatedBalanceUAcc = list2.searchBalance(acc) + amou;
			list2.searchAndChange(updatedBalanceUAcc, acc);
		}
		else if (ttype == 2)
		{
			updatedBalanceUAcc = list2.searchBalance(acc) - amou;
			list2.searchAndChange(updatedBalanceUAcc, acc);
		}
		else
		{
			cout << "Wrong Details in transaction !!!!" << endl;
		}

		ostringstream pre2;
		pre2 << fixed;
		pre2 << setprecision(2);
		pre2 << updatedBalanceUAcc;

		updateText.open("account-" + to_string(accDetailsList.search(acc)) + ".txt", std::ios_base::app);///////

		if (accDetailsList.search(acc) != -1)
		{

			updateText << endl;
			updateText << dateTra << "," << to_string(ttype) << "," << amountT << "," << pre2.str();
			
			transaction >> transactionLine;
		}
		else
		{
			cout << "Wrong Bank Details!!!!!!!!!!!!!!!!!!" << endl;
			transaction >> transactionLine;
		}
	}

	ofstream bn;  //write..
	bn.open("account-bank.txt", ios::app);  //open text files for user accounts....
	bn << endl;
	
	int j = 1;
	for (j = 1; j < 11; j++)
	{
	ifstream uac;
	
	uac.open("account-" + to_string(j) + ".txt");
	
	if (!uac)
	{
		cout << "Unable to open!!!" << endl;
		return 0;
	}
	long double temp[100];
	string lineAc;
	uac >> lineAc;
	int li = 0;   //line of the account text...........
	int ksize = lineAc.length();
	int updatingDate = 20190101;
	long double lastBalance;
	ofstream acco;
	int mydt1;
	int mytp;
	while (uac.good())
	{
		ofstream acco;
		acco.open("account_" + to_string(j) + ".txt", ios::app);
		int c = 0;
		string dt;
		while (lineAc[c] != ',')
		{
			dt += lineAc[c];
			c = c + 1;
		}
		c = c + 1;
		int dt1 = stoi(dt);  //date
		mydt1 = dt1;
		int tp = lineAc[c] - '0';  //type
		mytp = tp;
		c = c + 2;
		string tamount;  //t amount...
		while (lineAc[c] != ',')
		{
			tamount += lineAc[c];
			c = c + 1;
		}
		int ta = stoi(tamount);

		c = c + 1;

		string bala;  //store opening balance(I got maximum digit size as 20)

		while (lineAc[c] != '.')  //to get the integer part
		{
			bala += lineAc[c];
			c = c + 1;
		}


		int temp4 = stof(bala);
		cout << fixed;
		cout << setprecision(2);
		long double floating = 0.01 * ((lineAc[c + 1] - '0') * 10 + (lineAc[c + 2] - '0'));  //get the decimal part
	     balan = temp4 + floating;  //get the entire balance value...////////////////////////////////////////////llllllllllllllllllllllllllllll
					
		temp[li] = balan;  //tepory store the final balance...
	
		///////////////////////////////////////////////////////////
		if (li > 1)
		{

			if (updatingDate < dt1) //if date changing...........
			{
				int dateDifferent = dt1 - updatingDate; //dates differents.....
				if (dateDifferent == 1)
				{
					if (temp[li-1] < 1000)
					{
						long double updatedBalance1 = temp[li-1] - 10;
						long double updatedBankBalance1 = updatedBalBAcc + 10;
						ostringstream u1, u2;
						u1 << fixed;
						u1 << setprecision(2);
						u1 << updatedBalance1;
						u2 << fixed;
						u2 << setprecision(2);
						u2 << updatedBankBalance1;

						acco << to_string(updatingDate) << "," << to_string(4) << "," << to_string(10) << "," << u1.str() << endl;  //user account update 
						bn << to_string(updatingDate) << "," << to_string(4) << "," << to_string(10) << "," << u2.str() << endl;   //bank account update..

						if (updatedBalance1 < 0)
						{
							///////////////////////
							long double updatedBalance2 = updatedBalance1 - 50;
							long double updatedBankBalance2 = updatedBankBalance1 + 50;
							ostringstream u3, u4;
							u3 << fixed;
							u3 << setprecision(2);
							u3 << updatedBalance2;
							u4 << fixed;
							u4 << setprecision(2);
							u4 << updatedBankBalance2;

							acco << to_string(updatingDate) << "," << to_string(4) << "," << to_string(50) << "," << u3.str() << endl;  //user account update 
							bn << to_string(updatingDate) << "," << to_string(4) << "," << to_string(50) << "," << u4.str() << endl;   //bank account update..
							/////////////////////

						}
						else if (updatedBalance1 > 0)  //interest..........
						{
							///////////////////////
							long double updatedBalance3 = updatedBalance1 + updatedBalance1 * 0.0002;
							long double updatedBankBalance3 = updatedBankBalance1 - (updatedBalance1 * 0.0002);
							ostringstream u5, u6, u7;
							u5 << fixed;
							u5 << setprecision(2);
							u5 << updatedBalance3;
							u6 << fixed;
							u6 << setprecision(2);
							u6 << updatedBankBalance3;
							u7 << fixed;
							u7 << setprecision(2);
							u7 << updatedBalance1 * 0.0002;

							acco << to_string(dt1) << "," << to_string(3) << "," << u7.str() << "," << u5.str() << endl;  //user account update 
							bn << to_string(dt1) << "," << to_string(3) << "," << u7.str() << "," << u6.str() << endl;   //bank account update..
							////////////////////
						}

					}
					else  // if greater than 1000 the interest......
					{
						long double updatedBalancee = temp[li-1] + temp[li-1] * 0.0002;
						long double updatedBankBalancee = updatedBalBAcc - (updatedBalBAcc * 0.0002);
						ostringstream n5, n6, n7;
						n5 << fixed;
						n5 << setprecision(2);
						n5 << updatedBalancee;
						n6 << fixed;
						n6 << setprecision(2);
						n6 << updatedBankBalancee;
						n7 << fixed;
						n7 << setprecision(2);
						n7 << updatedBalBAcc * 0.0002;

						acco << to_string(dt1) << "," << to_string(3) << "," << n7.str() << "," << n5.str() << endl;  //user account update 
						bn << to_string(dt1) << "," << to_string(3) << "," << n7.str() << "," << n6.str() << endl;   //bank account update..
					}


					updatingDate = dt1;
				}
				else  //if date different greater than 1.........
				{
					//////////////////////////////////////
					// int common = temp[li - 1];
					long double updatedBalan;
					long double updatedBankBalan;
					long double updatedBalanc;
					long double updatedBankBalanc;
					long double updatedBalance0;
					long double updatedBankBalance0;
					int mycheck = 0;
					if (temp[li-1] < 1000)
					{
						updatedBalanc = temp[li-1] - 10;
						updatedBankBalanc = updatedBalBAcc + 10;
						ostringstream u1, u2;
						u1 << fixed;
						u1 << setprecision(2);
						u1 << updatedBalanc;
						u2 << fixed;
						u2 << setprecision(2);
						u2 << updatedBankBalanc;
						mycheck = 1;
						acco << to_string(updatingDate) << "," << to_string(4) << "," << to_string(10) << "," << u1.str() << endl;  //user account update 
						bn << to_string(updatingDate) << "," << to_string(4) << "," << to_string(10) << "," << u2.str() << endl;   //bank account update..

						if (updatedBalanc < 0)
						{
							///////////////////////
							updatedBalan = updatedBalanc - 50;
							updatedBankBalan = updatedBankBalanc + 50;
							ostringstream u3, u4;
							u3 << fixed;
							u3 << setprecision(2);
							u3 << updatedBalan;
							u4 << fixed;
							u4 << setprecision(2);
							u4 << updatedBankBalan;

							acco << to_string(updatingDate) << "," << to_string(4) << "," << to_string(50) << "," << u3.str() << endl;  //user account update 
							bn << to_string(updatingDate) << "," << to_string(4) << "," << to_string(50) << "," << u4.str() << endl;   //bank account update..
							/////////////////////

						}


					}
					////////////////////////////////////
					for (int s = updatingDate + 1; s < dt1; s++)
					{
						if (temp[li-1] > 1000)
						{
							long double updatedBalance5 = temp[li-1] + temp[li-1] * 0.0002;
							long double updatedBankBalance5 = updatedBalBAcc - (temp[li-1] * 0.0002);
							ostringstream u8, u9, u10;
							u8 << fixed;
							u8 << setprecision(2);
							u8 << updatedBalance5;
							u9 << fixed;
							u9 << setprecision(2);
							u9 << updatedBankBalance5;
							u10 << fixed;
							u10 << setprecision(2);
							u10 << updatedBalance5 * 0.0002;

							acco << to_string(s) << "," << to_string(3) << "," << u10.str() << "," << u8.str() << endl;  //user account update 
							bn << to_string(s) << "," << to_string(3) << "," << u10.str() << "," << u9.str() << endl;   //bank account update..





						}
						if (mycheck==1)
						{
							//////////
							mycheck = 2;
							 updatedBalance0 = updatedBalanc + updatedBalanc * 0.0002;
						     updatedBankBalance0 = updatedBalBAcc - (updatedBalanc * 0.0002);
							ostringstream k8, k9, k10;
							k8 << fixed;
							k8 << setprecision(2);
							k8 << updatedBalance0;
							k9 << fixed;
							k9 << setprecision(2);
							k9 << updatedBankBalance0;
							k10 << fixed;
							k10 << setprecision(2);
							k10 << updatedBalance0 * 0.0002;

							acco << to_string(s) << "," << to_string(3) << "," << k10.str() << "," << k8.str() << endl;  //user account update 
							bn << to_string(s) << "," << to_string(3) << "," << k10.str() << "," << k9.str() << endl;   //bank account update..



							///
						}
						if (mycheck==2)
						{
							//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
							long double updatedBalance9 = updatedBalance0 - 10;
							long double updatedBankBalance9 = updatedBankBalance0 + 10;
							ostringstream m1, m2;
							m1 << fixed;
							m1 << setprecision(2);
							m1 << updatedBalance9;
							m2 << fixed;
							m2 << setprecision(2);
							m2 << updatedBankBalance9;

							acco << to_string(s) << "," << to_string(4) << "," << to_string(10) << "," << m1.str() << endl;  //user account update 
							bn << to_string(s) << "," << to_string(4) << "," << to_string(10) << "," << m2.str() << endl;   //bank account update..

							if (updatedBalance9 < 0)
							{
								///////////////////////
								long double updatedBalance10 = updatedBalance9 - 50;
								long double updatedBankBalance10 = updatedBankBalance9 + 50;
								ostringstream m3, m4;
								m3 << fixed;
								m3 << setprecision(2);
								m3 << updatedBalance10;
								m4 << fixed;
								m4 << setprecision(2);
								m4 << updatedBankBalance10;

								acco << to_string(s) << "," << to_string(4) << "," << to_string(50) << "," << m3.str() << endl;  //user account update 
								bn << to_string(s) << "," << to_string(4) << "," << to_string(50) << "," << m4.str() << endl;   //bank account update..
								/////////////////////

							}
							//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
						}


					}
					updatingDate = dt1;


				}


			}
		}

		ostringstream k6;
		k6 << fixed;
		k6 << setprecision(2);
		k6 << balan;
		acco << to_string(dt1) << "," << to_string(tp) << "," << to_string(ta) << "," << k6.str()<<endl;
		uac >> lineAc;
		li = li + 1;

	}
	acco.open("account_" + to_string(j) + ".txt", ios::app);
	long double lastInterest = balan + balan * 0.0002;
    lastBank=updatedBalBAcc- balan * 0.0002;
	 
	
	currentBalances[j-1] = lastInterest;



	ostringstream la,lai,lab;
	la << fixed;
	la << setprecision(2);
	la << lastInterest;
	lai << fixed;
	lai << setprecision(2);
	lai << balan * 0.0002;
	lab << fixed;
	lab << setprecision(2);
	lab << lastBank;
	

	acco << to_string(20190112) << "," << to_string(3) << "," << lai.str() << "," << la.str(); //12 th day interest......
	bn<< to_string(20190112) << "," << to_string(3) << "," << lai.str() << "," << lab.str()<<endl; //12 th day interest......


	}
	currentBalances[10] = lastBank;
	
	cout << "For view current(12th) Account 1 Balance : Press 1" << endl;
	cout << "For view current(12th) Account 2 Balance : Press 2" << endl;
	cout << "For view current(12th) Account 3 Balance : Press 3" << endl;
	cout << "For view current(12th) Account 4 Balance : Press 4" << endl;
	cout << "For view current(12th) Account 5 Balance : Press 5" << endl;
	cout << "For view current(12th) Account 6 Balance : Press 6" << endl;
	cout << "For view current(12th) Account 7 Balance : Press 7" << endl;
	cout << "For view current(12th) Account 8 Balance : Press 8" << endl;
	cout << "For view current(12th) Account 9 Balance : Press 9" << endl;
	cout << "For view current(12th) Account 10 Balance : Press 10" << endl;
	cout<<"For view current(12th) Bank vault Balance : Press 11"<<endl;
	cout << endl << "Please Enter the option: " << endl;
	int choice;
	cin >> choice;
	if (choice == 1)
	{
		cout << "Current Balance : " << fixed << setprecision(2) << currentBalances[0];
	}
	else if (choice == 2)
	{
		cout << "Current Balance : " << fixed << setprecision(2) << currentBalances[1];
	}
	else if (choice == 3)
	{
		cout << "Current Balance : " << fixed << setprecision(2) << currentBalances[2];
	}
	else if (choice == 4)
	{
		cout << "Current Balance : " << fixed << setprecision(2) << currentBalances[3];
	}
	else if (choice == 5)
	{
		cout << "Current Balance : " << fixed << setprecision(2) << currentBalances[4];
	}
	else if (choice == 6)
	{
		cout << "Current Balance : " << fixed << setprecision(2) << currentBalances[5];
	}
	else if (choice == 7)
	{
		cout << "Current Balance : " << fixed << setprecision(2) << currentBalances[6];
	}
	else if (choice == 8)
	{
		cout << "Current Balance : " << fixed << setprecision(2) << currentBalances[7];
	}
	else if (choice == 9)
	{
		cout << "Current Balance : " << fixed << setprecision(2) << currentBalances[8];
	}
	else if (choice == 10)
	{
		cout << "Current Balance : " << fixed << setprecision(2) << currentBalances[9];
	}
	else if (choice == 11)
	{
		cout << "Current Balance : " << fixed << setprecision(2) << currentBalances[10];
	}
	else
	{
		cout << "wrong input!!!" << endl;
	}
	//removing my temorary created text files...........

	char fileName1[] = "account-1.txt";
	remove(fileName1);
	char fileName2[] = "account-2.txt";
	remove(fileName2);
	char fileName3[] = "account-3.txt";
	remove(fileName3);
	char fileName4[] = "account-4.txt";
	remove(fileName4);
	char fileName5[] = "account-5.txt";
	remove(fileName5);
	char fileName6[] = "account-6.txt";
	remove(fileName6);
	char fileName7[] = "account-7.txt";
	remove(fileName7);
	char fileName8[] = "account-8.txt";
	remove(fileName8);
	char fileName9[] = "account-9.txt";
	remove(fileName9);
	char fileName10[] = "account-10.txt";
	remove(fileName10);
	return 0;
}