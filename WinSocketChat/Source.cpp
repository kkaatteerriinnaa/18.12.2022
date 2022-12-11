#include <iostream>
#include "Socket.h"

using namespace std;

int main()
{
	int sum = 0, n, col=0;
	int nChoice;
	int port = 24242; //�������� ����
	string ipAddress = "127.0.0.1"; //����� �������
	char receiveMessage[MAXSTRLEN];
	char sendMessage[MAXSTRLEN];
	cout << "1) Start server" << endl;
	cout << "2) Connect to server" << endl;
	cout << "3) Exit" << endl;
	cin >> nChoice;
	if (nChoice == 1)
	{
		ServerSocket server;
		cout << "Starting server..." << endl;
		//��������� ������
		server.StartHosting(port);
		while (true)
		{
			//�������� ������ �� �������
			//� ��������� � ���������� receiveMessage
			server.ReceiveData(receiveMessage, MAXSTRLEN);
			
			//���������� ������ �������
			server.SendDataMessage();
			cout << "1.������� = 7800" << endl;
			cout << "2.������� = 26000" << endl;
			cout << "3.������� = 9000" << endl;
			//���� ���� ��������� "end", ��������� ������
			if (strcmp(receiveMessage, "end") == 0 ||
				strcmp(sendMessage, "end") == 0)
				break;
		}
	}
	else if (nChoice == 2)
	{
		cout << "Enter an IP address: " << endl;
		//����������� IP �������
		
		ClientSocket client;
		//������������ � �������
		client.ConnectToServer(ipAddress.c_str(), port);
		while (true)
		{
			//���������� ���������
			client.SendDataMessage();
			cout << "\tWaiting" << endl;
			//�������� �����
			client.ReceiveData(receiveMessage, MAXSTRLEN);
			cout << "������� ����� ���������:" << endl;
			cin >> n;
			cout << "������� ����������:" << endl;
			if (n == 1)
			{
				sum = 7800 * col;
			}
			if (n == 2)
			{
				sum = 26000 * col;
			}
			if (n == 3)
			{
				sum = 9000 * col;
			}
			cout << "�����:" << sum;
			if (strcmp(receiveMessage, "end") == 0 ||
				strcmp(sendMessage, "end") == 0)
				break;
		}
		//��������� ����������
		client.CloseConnection();
	}
	else if (nChoice == 3)
		return 0;
}