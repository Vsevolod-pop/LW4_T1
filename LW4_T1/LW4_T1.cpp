#include <iostream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    string stroka;
    int sum = 0;
    char flag = '+';
    int f = 1;
    cout << "Введите строку:  ";
    getline(cin, stroka);
    while (f == 1)
    {
        f = 0;
        if (stroka.length() % 2 == 0)
        {
            f = 1;
            cout << "Вы ввели строку неверно, введите ее корректно по типу <цифра> +- <цифра> и тд. -  ";
            getline(cin, stroka);
            continue;
        }
        for (int i = 0; i < stroka.length(); i++)
        {
            if (i == 0 and isdigit(stroka[i]))
            {
                sum = stroka[i]-48;
                continue;
            }
            if (i%2 != 0)
            {
                if (stroka[i] == '-')
                {
                    flag = '-';
                    continue;
                }
                else if (stroka[i] == '+')
                {
                    flag = '+';
                    continue;
                }
                else
                {
                    f = 1;
                    cout << "В ввели строку неверно, введите ее корректно по типу <цифра> +- <цифра> и тд. -  ";
                    getline(cin, stroka);
                    break;
                }
            }
            if (i % 2 == 0 and isdigit(stroka[i]) and flag == '-')
            {
                sum -= stroka[i]-48;
            }
            else if (i % 2 == 0 and isdigit(stroka[i]) and flag == '+')
            {
                sum += stroka[i]-48;
            }
            else
            {
                f = 1;
                cout << "ВS ввели строку неверно, введите ее корректно по типу <цифра> +- <цифра> и тд. -  ";
                getline(cin, stroka);
                break;
            }
        }
        if (f == 0)
        {
            break;
        }
    }
    cout << "Исходная строка: " << stroka << endl << "Полученная сумма: " << sum << endl;
}


