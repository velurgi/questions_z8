//8 вопросов
#include <iostream>
#include <fstream>
#include <string>
#include <bitset>
#include <limits.h>


using std::cout;
using std::endl;
using std::cin;

int result = 0b00000000;
int dataCheck(int a) { // Проверка на бинарность ответа
    setlocale(LC_ALL, "ru");
    while (cin.fail() || a < 1 || a > 2) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка, вы должны выбрать 1 или 2" << endl;
        cin >> a;
    }
    return a;
}

int dataCheck2(int a) { // Проверка на норм ответ
    setlocale(LC_ALL, "ru");
    while (cin.fail() || a < 1 || a > 8) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка, вы должны выбрать от 1 до 8" << endl;
        cin >> a;
    }
    return a;
}


char resultF(int a) {
    if (a == 1) {
        result = result | 1;
        result = result << 1;
        /*cout << "Результат: " << result << endl;*/
    }
    if (a == 2) {
        result = result << 1;
        /*cout << "Результат: " << result << endl;*/
    }
    if (a == 3) {
        result = result >> 1;
        cout << "Финальный результат: " << result << endl;
        unsigned char z = result;

        return z;
    }
    return 0;
}

int main()
{
    int result = 0b00000000;
    int answer = 0;
    int answerCounter = 0;
    setlocale(LC_ALL, "ru");
    bool fileExistance = true;
    cout << "Здравстуйте! Желаете пройти тест, или ознакомиться с результатом?." << endl;
    cout << "1. Пройти тест. \t 2. Узнать результат." << endl;
    cin >> answer;
    answer = dataCheck(answer);
    if (answer == 2) {

        std::string line;
        std::ifstream in;
        in.open("result");

        if (in.is_open()) { // проверка на существование файла
            getline(in, line);
            cout << line;
            unsigned int result = line[0];
            cout << "Ваши ответы: " << result << endl;


            for (int i = 1; i < 9; i++) {
                int j = i - 0;
                cout << i << ". ";
                if (result / 2 == 0) {
                    cout << "Нет \t";
                    result = result / 2;
                }
                else {
                    cout << "Да \t";
                    result = result / 2;
                }

            }
            cout << endl << endl;
            cout << "Желаете их изменить?" << endl;
            cout << "1. Да \t 2. Нет" << endl;
            cin >> answer;
            answer = dataCheck(answer);
            if (answer == 1) {
                cout << "Введите номер вопроса, ответ на который, желаете изменить: " << endl;
                int answer2;
                cin >> answer2;
                answer2 = dataCheck2(answer2);
                switch (answer2)
                {
                case 1:
                    cout << "Вопрос 1. В любой многоугольник можно вписать окружность?" << endl;
                    cout << "1. Да \t 2. Нет" << endl;
                    cin >> answer;
                    answer = dataCheck(answer);
                    resultF(answer);
                    break;
                case 2:
                    cout << "Вопрос 2. Треугольник называется правильным, если все его стороны и углы равны?" << endl;
                    cout << "1. Да \t 2. Нет" << endl;
                    cin >> answer;
                    answer = dataCheck(answer);
                    resultF(answer);
                    break;
                case 3:
                    cout << "Вопрос 3. Любой четырехугольник с равными сторонами является правильным?" << endl;
                    cout << "1. Да \t 2. Нет" << endl;
                    cin >> answer;
                    answer = dataCheck(answer);
                    resultF(answer);
                    break;
                case 4:
                    cout << "Вопрос 4. В правильном треугольнике каждый угол равен 60 градусов?" << endl;
                    cout << "1. Да \t 2. Нет" << endl;
                    cin >> answer;
                    answer = dataCheck(answer);
                    resultF(answer);
                    break;
                case 5:
                    cout << "Вопрос 5. Периметр квадрата, вписанного в окружность радиуса 2, равен 8?" << endl;
                    cout << "1. Да \t 2. Нет" << endl;
                    cin >> answer;
                    answer = dataCheck(answer);
                    resultF(answer);
                    break;
                case 6:
                    cout << "Вопрос 6. Ромб –правильный четырехугольник?" << endl;
                    cout << "1. Да \t 2. Нет" << endl;
                    cin >> answer;
                    answer = dataCheck(answer);
                    resultF(answer);
                    break;
                case 7:
                    cout << "Вопрос 7. Любой прямоугольник можно вписать в окружность?" << endl;
                    cout << "1. Да \t 2. Нет" << endl;
                    cin >> answer;
                    answer = dataCheck(answer);
                    resultF(answer);
                    break;
                case 8:
                    cout << "Вопрос 8. Около любого правильного многоугольника можно описать окружность и притом только одну?" << endl;
                    cout << "1. Да \t 2. Нет" << endl;
                    cin >> answer;
                    answer = dataCheck(answer);
                    resultF(answer);
                    break;
                }
                // ДОБАВИТЬ СЮДА СОХРАНЕНИЕ ИЗМЕНЕННЫХ ВОПРОСОВ И ВОЗМОЖНО ЗАЦИКЛИТЬ С ВОПРОСОМ, ВСЁ ЛИ ЧТО ОНИ ХОТЕЛИ ПОМЕНЯТЬ
            }

        }
        else { //если файла нет, СДЕЛАТЬ ЧТОБЫ ДАЛЬШЕ НЕ ШЛО
            cout << "Ошибки, файл не найден." << endl;
            bool fileExistance = false;
            system("pause");
        }

    }
    if (fileExistance == true) {

        cout << "Вопрос 1. В любой многоугольник можно вписать окружность?" << endl;
        cout << "1. Да \t 2. Нет" << endl;
        cin >> answer;
        answer = dataCheck(answer);
        resultF(answer);

        cout << "Вопрос 2. Треугольник называется правильным, если все его стороны и углы равны?" << endl;
        cout << "1. Да \t 2. Нет" << endl;
        cin >> answer;
        answer = dataCheck(answer);
        resultF(answer);

        cout << "Вопрос 3. Любой четырехугольник с равными сторонами является правильным?" << endl;
        cout << "1. Да \t 2. Нет" << endl;
        cin >> answer;
        answer = dataCheck(answer);
        resultF(answer);

        cout << "Вопрос 4. В правильном треугольнике каждый угол равен 60 градусов?" << endl;
        cout << "1. Да \t 2. Нет" << endl;
        cin >> answer;
        answer = dataCheck(answer);
        resultF(answer);

        cout << "Вопрос 5. Периметр квадрата, вписанного в окружность радиуса 2, равен 8?" << endl;
        cout << "1. Да \t 2. Нет" << endl;
        cin >> answer;
        answer = dataCheck(answer);
        resultF(answer);

        cout << "Вопрос 6. Ромб –правильный четырехугольник?" << endl;
        cout << "1. Да \t 2. Нет" << endl;
        cin >> answer;
        answer = dataCheck(answer);
        resultF(answer);

        cout << "Вопрос 7. Любой прямоугольник можно вписать в окружность?" << endl;
        cout << "1. Да \t 2. Нет" << endl;
        cin >> answer;
        answer = dataCheck(answer);
        resultF(answer);

        cout << "Вопрос 8. Около любого правильного многоугольника можно описать окружность и притом только одну?" << endl;
        cout << "1. Да \t 2. Нет" << endl;
        cin >> answer;
        answer = dataCheck(answer);
        resultF(answer);
    }

    std::ofstream out;
    out.open("result");
    out << resultF(3) << endl;
    out.close();
}


