// Kazino.cpp: ���������� ����� ����� ��� ����������� ����������.
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
    int balance; // ������ ������
    int bettingAmount; //���������� ������
    int guess; //������ ��� ��������
    int dice; // ������������ ��������� �����
    char choice; // �����
    srand(time(0)); // ��������� ���������
    cout << "\n\t\t========����� ���������� � ������=======\n\n";
    cout << "\n\n�������� ��������� ������ : $";
    cin >> balance; //��� ������
    do
    {
        system("cls");// �������� ������
        rules(); //�������
        cout << "\n\n��� ������� ������ $ " << balance << "\n";
// ������� ������ ������
        do
        {
            cout << "������ ������� ������ : $";
            cin >> bettingAmount; //������
            if(bettingAmount > balance)// ��������� ������ � ��������
                cout << "������ ������ �� ����� ���� ������ �������� �������!\n"
                       <<"\n�������� ������� ������\n ";
        }while(bettingAmount > balance);// ����� ������ ������ �������
// �������� ��������� ������� �����
        do
        {
            cout << "�������� ����� ����� ������ ����� 1 & 10 :";
            cin >> guess;// ���������� �����
            if(guess <= 0 || guess > 10) // ���������� ����� 
                cout << "\n����� ������ ���� ����� 1 � 10\n"
                    <<"�������� ������� �����:\n ";
        }while(guess <= 0 || guess > 10);//���� ����� ������ ����� ��
        dice = rand()%10 + 1;//������ ��������������
        if(dice == guess)
        {
            cout << "\n\n�� ����� ���������! �� ��������:" << bettingAmount * 10;
            balance = balance + bettingAmount * 10; //������ �������������� 
        }
        else
        {
            cout << "��, �� �� �������, � ��������� ��� ����������� ������ $ "<< bettingAmount <<"\n";
            balance = balance - bettingAmount;//������ ������������
        }
        cout << "\n���������� ����� ��� : " << dice <<"\n";
        cout << "\n������ ��� ������ $ " << balance << "\n";
        if(balance == 0) // ���� ������ ��������������
        {
			cout << "� ��� ����������� ������ ;)";
            break;
        }
        cout << "\n\n-->����������� �� ��� ���� ������?";
        cin >> choice;
    }while(choice =='Da'|| choice=='da');
    cout << "\n\n\n";
    cout << "\n\n������� �� �����, ��������� ���. ��� ������ $ " << balance << "\n\n";
	system("pause");
    return 0;
}
void rules()//������� ���� � ������
{
    system("cls");// �������� ������
    cout << "\t\t======������� ������======\n";
    cout << "\t1. ��������� ����� ������ ���� ��  1 �� 10\n";
    cout << "\t2. ���������� ������� ����� � 10 ��� ������ ������\n";
    cout << "\t3. ������������ ������, � �� ������� �����, ������� ���������\n\n";
}
