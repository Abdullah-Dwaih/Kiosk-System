#pragma once
#include <iostream>
#include <queue>
#include "clsDate.h"
#include <string>
#include <stack>
using namespace std;



class clsQueueLine
{

private :

	string _Prefix = "";
	int _AverageServTime = 0, _TotalTickets = 0;


	class clsTicket
	{

	private:

		int _Number = 0, _WaitingClients = 0, _AverageServTime = 0, _ExpectedSerTime = 0;
		string _TicketIssueTime, _Prefix;


	public:

		clsTicket(int Number, int AverageServTime, int WaitingClients, string Prefix)
		{
			_Number = Number;
			_Prefix = Prefix;
			_WaitingClients = WaitingClients;
			_AverageServTime = AverageServTime;
			_TicketIssueTime = clsDate::GetSystemDateTimeString();
		}

		string Prefix()
		{
			return _Prefix;
		}

		int Number()
		{
			return _Number;
		}

		string FullNumber()

		{
			return _Prefix + to_string(_Number);
		}

		string TicketTime()
		{
			return _TicketIssueTime;
		}

		short WaitingClients()
		{
			return _WaitingClients;
		}

		int ExpectedServingTime()
		{
			return _AverageServTime * _WaitingClients;
		}

		void Print()
		{
			cout << "\n\t\t\t  _______________________\n";
			cout << "\n\t\t\t\t    " << FullNumber();
			cout << "\n\n\t\t\t    " << _TicketIssueTime;
			cout << "\n\t\t\t    Wating Clients = " << _WaitingClients;
			cout << "\n\t\t\t      Serve Time In";
			cout << "\n\t\t\t       " << ExpectedServingTime() << " Minutes.";
			cout << "\n\t\t\t  _______________________\n";


		}

	};


public:



	queue <clsTicket> QueueLine;


	clsQueueLine(string Prefix, int TimeToServ)
	{
		_Prefix = Prefix;
		_AverageServTime = TimeToServ;
		_TotalTickets = 0;
	}

	void IssueTicket()
	{
		_TotalTickets++;

		clsTicket Ticket(_TotalTickets, _AverageServTime, WaitingClients(), _Prefix);

		QueueLine.push(Ticket);
	}

	int WaitingClients()
	{
		return QueueLine.size();

	}

	string WhoIsNext()

	{
		if (QueueLine.empty())
			return "\nNo Client To Serv\n";
		else
			return QueueLine.front().FullNumber();

	}

	bool ServingNextClient()
	{
		if (QueueLine.empty())
			return false;


		QueueLine.pop();
		return true;
		
	}

	int ServedClients()
	{
		return _TotalTickets - WaitingClients();
	}


	void PrintInfo()
	{
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t\tQueue Info";
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t    Prefix   = " << _Prefix;
		cout << "\n\t\t\t    Total Tickets   = " << _TotalTickets;
		cout << "\n\t\t\t    Served Clients  = " << ServedClients();
		cout << "\n\t\t\t    Wating Clients  = " << WaitingClients(); ;
		cout << "\n\t\t\t _________________________\n";
		cout << "\n";

	}



	void PrintTicketsLineRTL()
	{

		if (QueueLine.empty())
			cout << "\n\t\tTickets: No Tickets.";
		else
			cout << "\n\t\tTickets: ";

		//we copy the queue in order not to lose the original
		queue <clsTicket> TempQueueLine = QueueLine;


		while (!TempQueueLine.empty())
		{
			clsTicket Ticket = TempQueueLine.front();

			cout << " " << Ticket.FullNumber() << " <-- ";

			TempQueueLine.pop();
		}

		cout << "\n";

	}

	void PrintTicketsLineLTR()
	{
		if (QueueLine.empty())
			cout << "\n\t\tTickets: No Tickets.";
		else
			cout << "\n\t\tTickets: ";

		//we copy the queue in order not to lose the original
		queue <clsTicket> TempQueueLine = QueueLine;
		stack <clsTicket> TempStackLine;

		while (!TempQueueLine.empty())
		{
			TempStackLine.push(TempQueueLine.front());
			TempQueueLine.pop();
		}

		while (!TempStackLine.empty())
		{
			clsTicket Ticket = TempStackLine.top();

			cout << " " << Ticket.FullNumber() << " --> ";

			TempStackLine.pop();
		}
		cout << "\n";
	}


	void PrintAllTickets()
	{

		cout << "\n\n\t\t\t       ---Tickets---";

		if (QueueLine.empty())
			cout << "\n\n\t\t\t     ---No Tickets---\n";

		//we copy the queue in order not to lose the original
		queue <clsTicket> TempQueueLine = QueueLine;


		while (!TempQueueLine.empty())
		{
			TempQueueLine.front().Print();
			TempQueueLine.pop();
		}

	}
};

