#pragma once
#include "List.cpp"

template<class Type>
class Interface
{
	Type obj;                     //Шаблонная переменная
public:
	Interface();                  //Конструктор без параметров
	Interface(const Type& obj);   //Конструктор копирования
	void mainMenu()								//Главное меню
	{
		char decision;
		int trigger;          //Номер данных
		string fileName;      //Имя файла
		Interface <Diesel> designDiesel;
		Interface <Electro> designElectro;
		Interface <carryWeight> designWeight;
		Interface <carryWood> designWood;
		Interface <exhTrain> designExh;
		Interface <SpeedTrain> designSpeed;


		while (true)
		{
			cout << "С какими данными вы хотите работать?" << endl;
			cout << "1| Обычные поезда" << endl;
			cout << "2| Международные и особые поезда" << endl;
			cout << "3| Промышленные поезда" << endl;
			cout << "4| Выход" << endl;

			cout << "Ваше решение: ";
			cin >> decision;
			switch (decision)
			{
			case '1':
				system("cls");
				cout << "Выберите подкатегорию данных" << endl;
				cout << "1| Дизельные поезда" << endl;
				cout << "2| Электрички" << endl;
				cout << "3| Назад" << endl;

				cout << "Ваше решение: ";
				cin >> decision;
				switch (decision)
				{
				case '1':
					fileName = "Diesel.txt";
					trigger = 1;
					designDiesel.orderMenu(trigger, fileName);      //Вызов меню 
					break;
				case '2':
					fileName = "Electro.txt";
					trigger = 2;
					designElectro.orderMenu(trigger, fileName);      //Вызов меню 
					break;
				case '3':
					system("cls");
					break;
				default:
					system("cls");
					cout << "[ОШИБКА] Такой подкатегории не существует" << endl;
					break;
				}
				break;
			case '2':
				system("cls");
				cout << "Выберите подкатегорию данных" << endl;
				cout << "1| Поезда-выставки" << endl;
				cout << "2| Скоростные поезда" << endl;
				cout << "3| Назад" << endl;
				cout << "Ваше решение: ";
				cin >> decision;
				switch (decision)
				{
				case '1':
					fileName = "exhTrain.txt";
					trigger = 3;
					designExh.orderMenu(trigger, fileName);      //Вызов меню 
					break;
				case '2':
					fileName = "SpeedTrain.txt";
					trigger = 4;
					designSpeed.orderMenu(trigger, fileName);      //Вызов меню
					break;
				case '3':
					system("cls");
					break;
				default:
					system("cls");
					cout << "[ОШИБКА] Такой подкатегории не существует" << endl;
					break;
				}
				break;
			case '3':
				system("cls");
				cout << "Выберите подкатегорию данных" << endl;
				cout << "1| Грузовые поезда" << endl;
				cout << "2| Сверхдлинные поезда" << endl;
				cout << "3| Назад" << endl;
				cout << "Ваше решение: ";
				cin >> decision;
				switch (decision)
				{
				case '1':
					fileName = "carryWeight.txt";
					trigger = 5;
					designWeight.orderMenu(trigger, fileName);  //Вызов меню
					break;
				case '2':
					trigger = 6;
					fileName = "carryWood.txt";
					designWood.orderMenu(trigger, fileName);//Вызов меню 	    
					break;
				case '3': 
					system("cls");
					break;
				default:
					system("cls");
					cout << "[ОШИБКА] Такой подкатегории не существует" << endl;
					break;
				}
				break;
			case '4':
				exit(0);
				break;
			default:
				system("cls");
				cout << "[ОШИБКА] Такой категории не существует" << endl;
				break;
			}
		}
	}	
	void orderMenu(int trigger, string fileName)	//Меню для работы с данными
	{
		List<Type> list;				//Объявление списка
		list.readFile(fileName);        //Считывание данных с файла
		Type value;
		char decision;
		int index;
		bool flag = true;
		while (flag)
		{
			cout << "Действия с данными" << endl;
			cout << "1| Добавить элементы" << endl;
			cout << "2| Удалить элементы" << endl;
			cout << "3| Поиск элемента" << endl;
			cout << "4| Просмотреть список" << endl;
			cout << "5| Редактирование списка" << endl;
			cout << "6| Сортировка списка" << endl;
			cout << "7| Сохранить прогресс" << endl;
			cout << "8| Выход" << endl;
			cout << "Ваше решение: ";
			cin >> decision;
			switch (decision)
			{
			case '1':
				system("cls");
				cout << "Выберите действие" << endl;
				cout << "1| Добавить в начало списка" << endl;
				cout << "2| Добавить в конец списка" << endl;
				cout << "Ваше решение: ";
				cin >> decision;
				switch (decision)
				{
				case '1':
					system("cls");
					value.setData();
					list.push(value);
					cout << "[ЛОГ] Успешное выполнение действия" << endl;
					break;
				case '2':
					system("cls");
					value.setData();
					list.pushBack(value);
					cout << "[ЛОГ] Успешное выполнение действия" << endl;
					break;
				default:
					cout << "[ОШИБКА] Такой подкатегории не существует" << endl;
					break;
				}
				break;
			case '2':
				system("cls");
				cout << "Выберите действие" << endl;
				cout << "1| Удалить с начала списка" << endl;
				cout << "2| Удалить с конца списка" << endl;
				cout << "3| Удалить заданный элемент списка" << endl;
				cout << "Ваше решение: ";
				cin >> decision;
				if (list.getCount() == 0)
				{
					system("cls");
					cout << "[ОШИБКА] Список пуст" << endl;
				}
				else {
					switch (decision)
					{
					case '1':
						list.dellOne();
						system("cls");
						cout << "[ЛОГ] Успешное выполнение действия" << endl;
						break;
					case '2':
						list.dellOneBack();
						system("cls");
						cout << "[ЛОГ] Успешное выполнение действия" << endl;
						break;
					case '3':
						system("cls");
						value.showHeader();
						list.show();
						cout << "Введите номер элемента: ";
						cin >> index;
						list.dellPoint(list[index]);				//Удаление определенного элемента
						system("cls");
						cout << "[ЛОГ] Успешное выполнение действия" << endl;
						break;
					default:
						system("cls");
						cout << "[ОШИБКА] Такой подкатегории не существует" << endl;
						break;
					}
				}
				break;
			case '3':
				system("cls");
				if (list.getCount() == 0)
				{
					system("cls");
					cout << "[ОШИБКА] Список пуст" << endl;
				}
				else {
					cout << "Введите ключи для поиска" << endl;
					value.setOptional();
					system("cls");
					list.search(value);
				}
				break;
			case '4':
				system("cls");
				cout << "Выберите действие" << endl;
				cout << "1| Просмотреть с начала" << endl;
				cout << "2| Просмотреть с конца" << endl;
				cout << "Ваше решение: " << endl;
				cin >> decision;
				if (list.getCount() == 0)
				{
					system("cls");
					cout << "[ОШИБКА] Список пуст" << endl;
				}
				else {
					switch (decision)
					{
					case '1':
						system("cls");
						value.showHeader();
						list.show();
						cout << "[ЛОГ] Успешное выполнение действия" << endl;
						break;
					case '2':
						system("cls");
						value.showHeader();
						list.showBack();
						cout << "[ЛОГ] Успешное выполнение действия" << endl;
						break;
					default:
						system("cls");
						cout << "[ОШИБКА] Такой подкатегории не существует" << endl;
						break;
					}
				}
				break;
			case '5':
				if (list.getCount() == 0)
				{
					system("cls");
					cout << "[ОШИБКА] Список пуст" << endl;
				}
				else {
					system("cls");
					value.showHeader();
					list.show();
					cout << "Введите номер элемента для редактирования: ";
					cin >> index;
					cout << "Выберите поле для редактирования" << endl;
					list[index]->obj.editData();
					cout << "[ЛОГ] Успешное выполнение действия" << endl;
				} break;
			case '6':
				if (list.getCount() == 0)
				{
					system("cls");
					cout << "[ОШИБКА] Список пуст" << endl;
				}
				else {
					cout << "Выберите способ сортировки" << endl;
					cout << "1| По убыванию" << endl;
					cout << "2| По возрастанию" << endl;
					cout << "Ваше решение: ";
					cin >> decision;
					switch (decision)
					{
					case '1':
						system("cls");
						cout << "Выберите поле для сортировки" << endl;
						value.showLabel();
						cout << "Ваше решение: " << endl;
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
							cout << "[ОШИБКА] Такой подкатегории не существует" << endl;
							break;
						}
						system("cls");
						cout << "[ЛОГ] Успешное выполнение действия" << endl;
						break;
					case '2':
						system("cls");
						cout << "Выберите поле для сортировки" << endl;
						value.showLabel();
						cout << "Ваше решение: " << endl;
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
								cout << "[ОШИБКА] Такой подкатегории не существует" << endl;
								break;
							}
							system("cls");
							cout << "[ЛОГ] Успешное выполнение действия" << endl;
							break;
						default:
							system("cls");
							cout << "[ОШИБКА] Такой подкатегории не существует" << endl;
						}
					}
					break;
			case '7':
				system("cls");
				cout << "Вы точно желаете сохранить прогресс?" << endl;
				cout << "1| Да" << endl;
				cout << "2| Нет" << endl;
				cout << "Ваше решение: ";
				cin >> decision;
				switch (decision)
				{
				case '1':
					list.writeFile(fileName);
					cout << "[ЛОГ] Успешное сохранение" << endl;
					break;
				case '2':
					break;
				default:
					system("cls");
					cout << "[ОШИБКА] Такой категории не существует" << endl;
					break;
				}
				break;
			case '8': { system("cls");
				flag = false; }break;
			default:
				system("cls");
				cout << "[ОШИБКА] Такой категории не существует" << endl;
				break;
				}
			}
		}
	}
	~Interface();                 //Деструктор
};