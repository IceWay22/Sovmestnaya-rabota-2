# Sovmestnaya-rabota-2
// Казино.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"

#include <iostream>

#include <string> 

#include <cstdlib> 

#include <ctime>

using namespace std;

void rules();

int main()
{
	setlocale(LC_ALL, "RUS");
	
    int balance; // Баланс игрока
    
    int bettingAmount; //Количество ставок
    
    int guess; //Угадал или неугадал
    
    int dice; // Загадывается рандомное число
    
    char choice; // Выбор
    
    srand(time(0)); // Рандомный генератор
    
    cout << "\n\t\t========Добро пожаловать в казино=======\n\n";
    
    cout << "\n\nВыберите начальный баланс : $";
    
    cin >> balance; //Ваш баланс
    
    do
    
    {
        system("cls");// Отчистка экрана
	
        rules(); //Правила
	
        cout << "\n\nВаш текущий баланс $ " << balance << "\n";
	
// Указать размер ставки

        do
        {
	
            cout << "Теперь укажите ставку : $";
	    
            cin >> bettingAmount; //Ставка
	    
            if(bettingAmount > balance)// Сравнение ставки с балансом
	    
                cout << "Баланс ставок не может быть больше текущего баланса!\n"
		
                       <<"\nПовторно введите баланс\n ";
		       
        }while(bettingAmount > balance);// Сумма ставки больше баланса
	
// Получаем выбранный игроком номер
	
        do
	
        {
	
            cout << "Угадайте любой номер ставки между 1 & 10 :";
	
            cin >> guess;// Угадывание числа
	
            if(guess <= 0 || guess > 10) // Угадывания числа 
	
                cout << "\nНомер должен быть между 1 и 10\n"
	
                    <<"Повторно введите число:\n ";
	
        }while(guess <= 0 || guess > 10);//если игрок угадал число то
	
        dice = rand()%10 + 1;//баланс увеличиваеться
	
        if(dice == guess)
        {
            cout << "\n\nВы очень удачливый! Вы выйграли:" << bettingAmount * 10;
            balance = balance + bettingAmount * 10; //Баланс увеличиваеться 
        }
        else
        {
            cout << "Эх, вы не угадали, в следующий раз обязательно повезёт $ "<< bettingAmount <<"\n";
            balance = balance - bettingAmount;//Баланс уменьшаеться
        }
        cout << "\nВыйгрышный номер был : " << dice <<"\n";
        cout << "\nТеперь ваш баланс $ " << balance << "\n";
        if(balance == 0) // если баланс заканчиваеться
        {
			cout << "У вас закончились деньги ;)";
            break;
        }
        cout << "\n\n-->Понравилось ли вам наше казино?";
        cin >> choice;
    }while(choice =='Da'|| choice=='da');
    cout << "\n\n\n";
    cout << "\n\nСпасибо за отзыв, приходите ещё. Ваш баланс $ " << balance << "\n\n";
	system("pause");
    return 0;
}

void rules()//Правила игры в казино

{

    system("cls");// Отчистка экрана
    cout << "\t\t======Правила казино======\n";
    cout << "\t1. Выбранное число должно быть от  1 до 10\n";
    cout << "\t2. Победитель получит сумму в 10 раз больше ставки\n";
    cout << "\t3. Неправильная ставка, и вы теряете сумму, которую поставили\n\n";
}
