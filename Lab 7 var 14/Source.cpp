#include <iostream>
#include <queue>
#include <stack>
#include <time.h>

using namespace std;

void easy()
{
    /*Создать очередь. Если кол-во элементов очереди >= N(> 0), то выводим в консоль N первых элементов
    очереди. В противном выводим в консоль всю очередь.*/
    //создаем очередь;
    queue <int> Numbers;
    int N, size, *P1, *P2;

    do {
        cout << "Введите число N для его сравнения с кол-вом элементов очереди: ";
        cin >> N;
        cout << endl;
    } while (N <= 0);

    do {
        cout << "Введите кол-во элементов очереди: ";
        cin >> size;
        cout << endl;
    } while (size <= 0);

    cout << "Элементы всей очереди: ";
    //выводим ее элементы, а также первый и последний; 
    for (int i = 0; i < size; i++)
    {
        Numbers.push(rand() % 10);
        cout << Numbers.back() << " ";
    }

    P1 = &Numbers.front();
    P2 = &Numbers.back();

    cout << endl << "Первый элемент очереди: " << *P1 << ", последний элемент: " << *P2 << endl;
    //если кол-во элементов очереди больше чем N - выводим на экран N элементов очереди;
    if (size >= N)
    {
        cout << endl << "Кол-во элементов очереди больше либо равно числу N - выводим первые N элементов очереди: ";
        for (int i = 0; i < N; i++)
        {
            cout << Numbers.front() << " ";
            Numbers.pop();
        }

        cout << endl << endl;
    }
    else
    {
        //в противном выводим всю очередь;
        cout << endl << "Кол-во элементов очереди меньше чем число N - выводим все элементы очереди: ";
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
    //Заполнить стек строковыми значениями. Удалить элемент стека. Посчитать кол-во односимвольных строк стека;
    stack <string> Words;

    Words.push("abc");
    Words.push("de");
    Words.push("f");
    Words.push("g");
    Words.push("hi");
    Words.push("gk");

    string arr[6];
    int count = 0;
    //выводим элементы стека;
    cout << "Элементы стека: ";
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
    //удаляем первый элемент и выводим стек еще раз;
    cout << endl;
    Words.pop();

    cout << "Стек после удаления элемента: ";
    for (int i = 0; i < 5; i++)
    {
        cout << Words.top() << " ";
        if (Words.top().length() == 1)
            count++;
        Words.pop(); 
    }

    cout << endl << "Кол-во односимвольных строк: " << count << endl << endl;
}

void hard()
{
    /*Реализовать очередь, используя два стека. Перекинуть элементы из первого стека в очередь. Если второй стек не пуст - 
    перекидываем из второго стека элементы в очередь. В противном перекидываем элементы из первого стека во второй.*/
    stack <int> Stack1;
    stack <int> Stack2;
    queue <int> Queue;
    int size = 5, k, count = 0;
    //добавляем элементы в первыйй стек и перекидываем из него элементы в очередь;
    cout << "Очередь после перемещения в нее элементов из 1-ого стека: ";
    for (int i = 0; i < 5; i++)
    {
        Stack1.push(rand() % 5);
        cout << Stack1.top() << " ";
        Queue.push(Stack1.top());
    }
    cout << endl << "Первый стек заполнен" << endl;

    do {
        cout << endl << "Хотите заполнить второй стек элементами? 1 - Да, 2 - Нет - 2: ";
        cin >> k;
        if (k == 1 || k == 2)
        {
            count++;
        }
    } while (count == 0);

    if (k == 2)
    {
        cout << endl << "Вы решили не заполнять второй стек" << endl;
    }
    else
    {
        cout << endl << "Второй стек заполнен" << endl;
        for (int i = 0; i < 5; i++)
        {
            Stack2.push(rand() % 5);
        }
    }
    //если второй стек заполнен - перекидываем из него элементы в очередь;
    if (!Stack2.empty())
    {
        cout << "Так как второй стек не пуст - перемещаем из него элементы в очередь. Очередь после изменений: ";
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
    //в противном перекидываем элементы из первого стека во второй;
    else
    {
        cout << "Второй стек пуст - перемещаем в него элементы из первого стека: ";
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
        cout << "Введите номер задания(easy - 1, medium - 2, hard - 3): ";

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

        cout << "Продолжить ввод? Да - 1, Нет - 2: ";

        cin >> b;

        cout << endl;

        if (b == 1)
        {
            count++;
            main();
        }

        if (b == 2)
        {
            cout << "Вы решили не продолжать";
            count++;
            break;
        }

    } while (count == 0);
}