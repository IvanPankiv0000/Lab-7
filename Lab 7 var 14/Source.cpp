#include <iostream>
#include <queue>
#include <stack>
#include <time.h>

using namespace std;

void easy()
{
    /*������� �������. ���� ���-�� ��������� ������� >= N(> 0), �� ������� � ������� N ������ ���������
    �������. � ��������� ������� � ������� ��� �������.*/
    //������� �������;
    queue <int> Numbers;
    int N, size, *P1, *P2;

    do {
        cout << "������� ����� N ��� ��� ��������� � ���-��� ��������� �������: ";
        cin >> N;
        cout << endl;
    } while (N <= 0);

    do {
        cout << "������� ���-�� ��������� �������: ";
        cin >> size;
        cout << endl;
    } while (size <= 0);

    cout << "�������� ���� �������: ";
    //������� �� ��������, � ����� ������ � ���������; 
    for (int i = 0; i < size; i++)
    {
        Numbers.push(rand() % 10);
        cout << Numbers.back() << " ";
    }

    P1 = &Numbers.front();
    P2 = &Numbers.back();

    cout << endl << "������ ������� �������: " << *P1 << ", ��������� �������: " << *P2 << endl;
    //���� ���-�� ��������� ������� ������ ��� N - ������� �� ����� N ��������� �������;
    if (size >= N)
    {
        cout << endl << "���-�� ��������� ������� ������ ���� ����� ����� N - ������� ������ N ��������� �������: ";
        for (int i = 0; i < N; i++)
        {
            cout << Numbers.front() << " ";
            Numbers.pop();
        }

        cout << endl << endl;
    }
    else
    {
        //� ��������� ������� ��� �������;
        cout << endl << "���-�� ��������� ������� ������ ��� ����� N - ������� ��� �������� �������: ";
        for (int i = 0; i < size; i++)
        {
            cout << Numbers.front() << " ";
            Numbers.pop();
        }

        cout << endl << endl;
    }
}

void medium()
{
    //��������� ���� ���������� ����������. ������� ������� �����. ��������� ���-�� �������������� ����� �����;
    stack <string> Words;

    Words.push("abc");
    Words.push("de");
    Words.push("f");
    Words.push("g");
    Words.push("hi");
    Words.push("gk");

    string arr[6];
    int count = 0;
    //������� �������� �����;
    cout << "�������� �����: ";
    for (int i = 0; i < 6; i++)
    {
        cout << Words.top() << " ";
        arr[i] = Words.top();
        Words.pop();
    }

    for (int i = 0; i < 6; i++)
    {
        Words.push(arr[i]);
    }
    //������� ������ ������� � ������� ���� ��� ���;
    cout << endl;
    Words.pop();

    cout << "���� ����� �������� ��������: ";
    for (int i = 0; i < 5; i++)
    {
        cout << Words.top() << " ";
        if (Words.top().length() == 1)
            count++;
        Words.pop(); 
    }

    cout << endl << "���-�� �������������� �����: " << count << endl << endl;
}

void hard()
{
    /*����������� �������, ��������� ��� �����. ���������� �������� �� ������� ����� � �������. ���� ������ ���� �� ���� - 
    ������������ �� ������� ����� �������� � �������. � ��������� ������������ �������� �� ������� ����� �� ������.*/
    stack <int> Stack1;
    stack <int> Stack2;
    queue <int> Queue;
    int size = 5, k, count = 0;
    //��������� �������� � ������� ���� � ������������ �� ���� �������� � �������;
    cout << "������� ����� ����������� � ��� ��������� �� 1-��� �����: ";
    for (int i = 0; i < 5; i++)
    {
        Stack1.push(rand() % 5);
        cout << Stack1.top() << " ";
        Queue.push(Stack1.top());
    }
    cout << endl << "������ ���� ��������" << endl;

    do {
        cout << endl << "������ ��������� ������ ���� ����������? 1 - ��, 2 - ��� - 2: ";
        cin >> k;
        if (k == 1 || k == 2)
        {
            count++;
        }
    } while (count == 0);

    if (k == 2)
    {
        cout << endl << "�� ������ �� ��������� ������ ����" << endl;
    }
    else
    {
        cout << endl << "������ ���� ��������" << endl;
        for (int i = 0; i < 5; i++)
        {
            Stack2.push(rand() % 5);
        }
    }
    //���� ������ ���� �������� - ������������ �� ���� �������� � �������;
    if (!Stack2.empty())
    {
        cout << "��� ��� ������ ���� �� ���� - ���������� �� ���� �������� � �������. ������� ����� ���������: ";
        do
        {
            Queue.push(Stack2.top());
            Stack2.pop();
        } while (!Stack2.empty());

        do
        {
            cout << Queue.front() << " ";
            Queue.pop();
        } while (!Queue.empty());

        cout << endl << endl;
    }
    //� ��������� ������������ �������� �� ������� ����� �� ������;
    else
    {
        cout << "������ ���� ���� - ���������� � ���� �������� �� ������� �����: ";
        do
        {
            Stack2.push(Stack1.top());
            Stack1.pop();
            cout << Stack2.top() << " ";
        } while (!Stack1.empty());

        cout << endl << endl;
    }
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "RU");

    int a;
    int count = 0;

    do
    {
        cout << "������� ����� �������(easy - 1, medium - 2, hard - 3): ";

        cin >> a;

        cout << endl;

        if (a == 1)
        {
            easy();
            count++;
        }

        if (a == 2)
        {
            medium();
            count++;
        }

        if (a == 3)
        {
            hard();
            count++;
        }

    } while (count == 0);

    int b;

    do
    {
        count = 0;

        cout << "���������� ����? �� - 1, ��� - 2: ";

        cin >> b;

        cout << endl;

        if (b == 1)
        {
            count++;
            main();
        }

        if (b == 2)
        {
            cout << "�� ������ �� ����������";
            count++;
            break;
        }

    } while (count == 0);
}