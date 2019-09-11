#pragma once
#include "List.cpp"

template<class Type>
class Interface
{
	Type obj;                     //��������� ����������
public:
	Interface();                  //����������� ��� ����������
	Interface(const Type& obj);   //����������� �����������
	void mainMenu()								//������� ����
	{
		char decision;
		int trigger;          //����� ������
		string fileName;      //��� �����
		Interface <Diesel> designDiesel;
		Interface <Electro> designElectro;
		Interface <carryWeight> designWeight;
		Interface <carryWood> designWood;
		Interface <exhTrain> designExh;
		Interface <SpeedTrain> designSpeed;


		while (true)
		{
			cout << "� ������ ������� �� ������ ��������?" << endl;
			cout << "1| ������� ������" << endl;
			cout << "2| ������������� � ������ ������" << endl;
			cout << "3| ������������ ������" << endl;
			cout << "4| �����" << endl;

			cout << "���� �������: ";
			cin >> decision;
			switch (decision)
			{
			case '1':
				system("cls");
				cout << "�������� ������������ ������" << endl;
				cout << "1| ��������� ������" << endl;
				cout << "2| ����������" << endl;
				cout << "3| �����" << endl;

				cout << "���� �������: ";
				cin >> decision;
				switch (decision)
				{
				case '1':
					fileName = "Diesel.txt";
					trigger = 1;
					designDiesel.orderMenu(trigger, fileName);      //����� ���� 
					break;
				case '2':
					fileName = "Electro.txt";
					trigger = 2;
					designElectro.orderMenu(trigger, fileName);      //����� ���� 
					break;
				case '3':
					system("cls");
					break;
				default:
					system("cls");
					cout << "[������] ����� ������������ �� ����������" << endl;
					break;
				}
				break;
			case '2':
				system("cls");
				cout << "�������� ������������ ������" << endl;
				cout << "1| ������-��������" << endl;
				cout << "2| ���������� ������" << endl;
				cout << "3| �����" << endl;
				cout << "���� �������: ";
				cin >> decision;
				switch (decision)
				{
				case '1':
					fileName = "exhTrain.txt";
					trigger = 3;
					designExh.orderMenu(trigger, fileName);      //����� ���� 
					break;
				case '2':
					fileName = "SpeedTrain.txt";
					trigger = 4;
					designSpeed.orderMenu(trigger, fileName);      //����� ����
					break;
				case '3':
					system("cls");
					break;
				default:
					system("cls");
					cout << "[������] ����� ������������ �� ����������" << endl;
					break;
				}
				break;
			case '3':
				system("cls");
				cout << "�������� ������������ ������" << endl;
				cout << "1| �������� ������" << endl;
				cout << "2| ������������ ������" << endl;
				cout << "3| �����" << endl;
				cout << "���� �������: ";
				cin >> decision;
				switch (decision)
				{
				case '1':
					fileName = "carryWeight.txt";
					trigger = 5;
					designWeight.orderMenu(trigger, fileName);  //����� ����
					break;
				case '2':
					trigger = 6;
					fileName = "carryWood.txt";
					designWood.orderMenu(trigger, fileName);//����� ���� 	    
					break;
				case '3': 
					system("cls");
					break;
				default:
					system("cls");
					cout << "[������] ����� ������������ �� ����������" << endl;
					break;
				}
				break;
			case '4':
				exit(0);
				break;
			default:
				system("cls");
				cout << "[������] ����� ��������� �� ����������" << endl;
				break;
			}
		}
	}	
	void orderMenu(int trigger, string fileName)	//���� ��� ������ � �������
	{
		List<Type> list;				//���������� ������
		list.readFile(fileName);        //���������� ������ � �����
		Type value;
		char decision;
		int index;
		bool flag = true;
		while (flag)
		{
			cout << "�������� � �������" << endl;
			cout << "1| �������� ��������" << endl;
			cout << "2| ������� ��������" << endl;
			cout << "3| ����� ��������" << endl;
			cout << "4| ����������� ������" << endl;
			cout << "5| �������������� ������" << endl;
			cout << "6| ���������� ������" << endl;
			cout << "7| ��������� ��������" << endl;
			cout << "8| �����" << endl;
			cout << "���� �������: ";
			cin >> decision;
			switch (decision)
			{
			case '1':
				system("cls");
				cout << "�������� ��������" << endl;
				cout << "1| �������� � ������ ������" << endl;
				cout << "2| �������� � ����� ������" << endl;
				cout << "���� �������: ";
				cin >> decision;
				switch (decision)
				{
				case '1':
					system("cls");
					value.setData();
					list.push(value);
					cout << "[���] �������� ���������� ��������" << endl;
					break;
				case '2':
					system("cls");
					value.setData();
					list.pushBack(value);
					cout << "[���] �������� ���������� ��������" << endl;
					break;
				default:
					cout << "[������] ����� ������������ �� ����������" << endl;
					break;
				}
				break;
			case '2':
				system("cls");
				cout << "�������� ��������" << endl;
				cout << "1| ������� � ������ ������" << endl;
				cout << "2| ������� � ����� ������" << endl;
				cout << "3| ������� �������� ������� ������" << endl;
				cout << "���� �������: ";
				cin >> decision;
				if (list.getCount() == 0)
				{
					system("cls");
					cout << "[������] ������ ����" << endl;
				}
				else {
					switch (decision)
					{
					case '1':
						list.dellOne();
						system("cls");
						cout << "[���] �������� ���������� ��������" << endl;
						break;
					case '2':
						list.dellOneBack();
						system("cls");
						cout << "[���] �������� ���������� ��������" << endl;
						break;
					case '3':
						system("cls");
						value.showHeader();
						list.show();
						cout << "������� ����� ��������: ";
						cin >> index;
						list.dellPoint(list[index]);				//�������� ������������� ��������
						system("cls");
						cout << "[���] �������� ���������� ��������" << endl;
						break;
					default:
						system("cls");
						cout << "[������] ����� ������������ �� ����������" << endl;
						break;
					}
				}
				break;
			case '3':
				system("cls");
				if (list.getCount() == 0)
				{
					system("cls");
					cout << "[������] ������ ����" << endl;
				}
				else {
					cout << "������� ����� ��� ������" << endl;
					value.setOptional();
					system("cls");
					list.search(value);
				}
				break;
			case '4':
				system("cls");
				cout << "�������� ��������" << endl;
				cout << "1| ����������� � ������" << endl;
				cout << "2| ����������� � �����" << endl;
				cout << "���� �������: " << endl;
				cin >> decision;
				if (list.getCount() == 0)
				{
					system("cls");
					cout << "[������] ������ ����" << endl;
				}
				else {
					switch (decision)
					{
					case '1':
						system("cls");
						value.showHeader();
						list.show();
						cout << "[���] �������� ���������� ��������" << endl;
						break;
					case '2':
						system("cls");
						value.showHeader();
						list.showBack();
						cout << "[���] �������� ���������� ��������" << endl;
						break;
					default:
						system("cls");
						cout << "[������] ����� ������������ �� ����������" << endl;
						break;
					}
				}
				break;
			case '5':
				if (list.getCount() == 0)
				{
					system("cls");
					cout << "[������] ������ ����" << endl;
				}
				else {
					system("cls");
					value.showHeader();
					list.show();
					cout << "������� ����� �������� ��� ��������������: ";
					cin >> index;
					cout << "�������� ���� ��� ��������������" << endl;
					list[index]->obj.editData();
					cout << "[���] �������� ���������� ��������" << endl;
				} break;
			case '6':
				if (list.getCount() == 0)
				{
					system("cls");
					cout << "[������] ������ ����" << endl;
				}
				else {
					cout << "�������� ������ ����������" << endl;
					cout << "1| �� ��������" << endl;
					cout << "2| �� �����������" << endl;
					cout << "���� �������: ";
					cin >> decision;
					switch (decision)
					{
					case '1':
						system("cls");
						cout << "�������� ���� ��� ����������" << endl;
						value.showLabel();
						cout << "���� �������: " << endl;
						cin >> decision;
						switch (decision)
						{
						case '1':
							list.sort(1, compareName<>); break;
						case '2':
							list.sort(1, compareType<>); break;
						case '3':
							list.sort(1, comparePrice<>); break;
						case '4':
							list.sort(1, compareDate<>); break;
						case '5':
							switch (trigger)
							{
							case 1:
							case 2:
								list.sort(1, compareTime<>); break;
							case 3:
							case 4:
								list.sort(1, comparePoint<>); break;
								/*				case 5:
												case 6:
													list.sort(1, compareStorageCondition<>);
													break;*/
							} break;
						case '6':
							switch (trigger)
							{
							case 1:
								list.sort(1, compareStops<>); break;
							case 2:
								list.sort(1, compareVipSeats<>); break;
							case 3:
								list.sort(1, compareTheme<>); break;
							case 4:
								list.sort(1, compareStorage<>); break;
							case 5:
								list.sort(1, compareLenght<>); break;
							case 6:
								list.sort(1, compareTypeSpeed<>);
								break;
							}
							break;
						default:
							system("cls");
							cout << "[������] ����� ������������ �� ����������" << endl;
							break;
						}
						system("cls");
						cout << "[���] �������� ���������� ��������" << endl;
						break;
					case '2':
						system("cls");
						cout << "�������� ���� ��� ����������" << endl;
						value.showLabel();
						cout << "���� �������: " << endl;
						cin >> decision;
						switch (decision)
						{
						case '1':
							list.sort(2, compareName<>); break;
						case '2':
							list.sort(2, compareType<>); break;
						case '3':
							list.sort(2, comparePrice<>); break;
						case '4':
							list.sort(2, compareDate<>); break;
						case '5':
							switch (trigger)
							{
							case 1:
							case 2:
								list.sort(2, compareTime<>); break;
							case 3:
							case 4:
								list.sort(2, comparePoint<>); break;
								//case 5:
								//case 6:
								//	list.sort(2, compareStorageCondition<>); break;
								//} break;
							case '6':
								switch (trigger)
								{
								case 1:
									list.sort(2, compareStops<>); break;
								case 2:
									list.sort(2, compareVipSeats<>); break;
								case 3:
									list.sort(2, compareTheme<>); break;
								case 4:
									list.sort(2, compareStorage<>); break;
								case 5:
									list.sort(2, compareLenght<>); break;
								case 6:
									list.sort(2, compareTypeSpeed<>);	break;
								}
								break;
							default:
								system("cls");
								cout << "[������] ����� ������������ �� ����������" << endl;
								break;
							}
							system("cls");
							cout << "[���] �������� ���������� ��������" << endl;
							break;
						default:
							system("cls");
							cout << "[������] ����� ������������ �� ����������" << endl;
						}
					}
					break;
			case '7':
				system("cls");
				cout << "�� ����� ������� ��������� ��������?" << endl;
				cout << "1| ��" << endl;
				cout << "2| ���" << endl;
				cout << "���� �������: ";
				cin >> decision;
				switch (decision)
				{
				case '1':
					list.writeFile(fileName);
					cout << "[���] �������� ����������" << endl;
					break;
				case '2':
					break;
				default:
					system("cls");
					cout << "[������] ����� ��������� �� ����������" << endl;
					break;
				}
				break;
			case '8': { system("cls");
				flag = false; }break;
			default:
				system("cls");
				cout << "[������] ����� ��������� �� ����������" << endl;
				break;
				}
			}
		}
	}
	~Interface();                 //����������
};