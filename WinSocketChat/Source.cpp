#include <iostream>
#include "Socket.h"

using namespace std;

int main()
{
	int sum = 0, n, col=0;
	int nChoice;
	int port = 24242; //выбираем порт
	string ipAddress = "127.0.0.1"; //Адрес сервера
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
		//Запускаем сервер
		server.StartHosting(port);
		while (true)
		{
			//Получаем данные от клиента
			//и сохраняем в переменной receiveMessage
			server.ReceiveData(receiveMessage, MAXSTRLEN);
			
			//Отправляем данные клиенту
			server.SendDataMessage();
			cout << "1.Телефон = 7800" << endl;
			cout << "2.Ноутбук = 26000" << endl;
			cout << "3.Планшет = 9000" << endl;
			//Если есть сообщение "end", завершаем работу
			if (strcmp(receiveMessage, "end") == 0 ||
				strcmp(sendMessage, "end") == 0)
				break;
		}
	}
	else if (nChoice == 2)
	{
		cout << "Enter an IP address: " << endl;
		//Запрашиваем IP сервера
		
		ClientSocket client;
		//подключаемся к серверу
		client.ConnectToServer(ipAddress.c_str(), port);
		while (true)
		{
			//отправляем сообщение
			client.SendDataMessage();
			cout << "\tWaiting" << endl;
			//получаем ответ
			client.ReceiveData(receiveMessage, MAXSTRLEN);
			cout << "Введите номер продукции:" << endl;
			cin >> n;
			cout << "Введите количество:" << endl;
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
			cout << "Итого:" << sum;
			if (strcmp(receiveMessage, "end") == 0 ||
				strcmp(sendMessage, "end") == 0)
				break;
		}
		//Закрываем соединение
		client.CloseConnection();
	}
	else if (nChoice == 3)
		return 0;
}