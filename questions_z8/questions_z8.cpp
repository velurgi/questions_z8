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
int dataCheck1or2(int a) { // Проверка на бинарность ответа
    setlocale(LC_ALL, "ru");
    while (cin.fail() || a < 1 || a > 2) {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Ошибка, вы должны выбрать 1 или 2" << endl;
        cin >> a;
    }
    return a;
}

int dataCheck1or8(int a) { // Проверка на норм ответ
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

int question(int answer2) {
    switch (answer2)
    {
        int answer;
    case 1:
        cout << "Вопрос 1. В любой многоугольник можно вписать окружность?" << endl;
        cout << "1. Да \t 2. Нет" << endl;
        cin >> answer;
        answer = dataCheck1or2(answer);
        if (answer == 1)
            return 1;
        else
            return 0;
        break;
        
    case 2:
        cout << "Вопрос 2. Треугольник называется правильным, если все его стороны и углы равны?" << endl;
        cout << "1. Да \t 2. Нет" << endl;
        cin >> answer;
        answer = dataCheck1or2(answer);
        if (answer == 1)
            return 1;
        else
            return 0;
        break;
    case 3:
        cout << "Вопрос 3. Любой четырехугольник с равными сторонами является правильным?" << endl;
        cout << "1. Да \t 2. Нет" << endl;
        cin >> answer;
        answer = dataCheck1or2(answer);
        if (answer == 1)
            return 1;
        else
            return 0;
        break;
        
    case 4:
        cout << "Вопрос 4. В правильном треугольнике каждый угол равен 60 градусов?" << endl;
        cout << "1. Да \t 2. Нет" << endl;
        cin >> answer;
        answer = dataCheck1or2(answer);
        if (answer == 1)
            return 1;
        else
            return 0;
        break;
    case 5:
        cout << "Вопрос 5. Периметр квадрата, вписанного в окружность радиуса 2, равен 8?" << endl;
        cout << "1. Да \t 2. Нет" << endl;
        cin >> answer;
        answer = dataCheck1or2(answer);
        if (answer == 1)
            return 1;
        else
            return 0;
        break;
    case 6:
        cout << "Вопрос 6. Ромб –правильный четырехугольник?" << endl;
        cout << "1. Да \t 2. Нет" << endl;
        cin >> answer;
        answer = dataCheck1or2(answer);
        if (answer == 1)
            return 1;
        else
            return 0;
        break;
    case 7:
        cout << "Вопрос 7. Любой прямоугольник можно вписать в окружность?" << endl;
        cout << "1. Да \t 2. Нет" << endl;
        cin >> answer;
        answer = dataCheck1or2(answer);
         
        if (answer == 1)
            return 1;
        else
            return 0;
        break;
    case 8:
        cout << "Вопрос 8. Около любого правильного многоугольника можно описать окружность и притом только одну?" << endl;
        cout << "1. Да \t 2. Нет" << endl;
        cin >> answer;
        answer = dataCheck1or2(answer);
        if (answer == 1)
            return 1;
        else
            return 0;
        break;
    }
}

int saveFunction(int massive[8]) {
    int massive1[8];
    int z = 0;
    for (int i = 0; i < 8; i++) {
        massive1[i] = massive[7-i];
    }
    for (int i = 0; i < 8; i++) {
        if (massive1[i] == 1)
            z = z * 2 + 1;
        else
            z *= 2;
    }
    for (int i = 0; i < 8; i++) {
        cout << endl << massive[i];
    }
    char n = z;
    std::cout << endl << "z: " << z << endl << "n: " << n << endl;
    std::ofstream out;
    out.open("result");
    out << n << endl;
    out.close();
    return 0;
}

int main()
{
    bool flagChange = false;
    bool flagPass = false;
    std::ofstream out;
    int result = 0b00000000;
    int answer = 0;
    int answerCounter = 0;
    setlocale(LC_ALL, "ru");
    bool fileExistance = true;
    cout << "Здравстуйте! Желаете пройти тест, или ознакомиться с результатом?." << endl;
    cout << "1. Пройти тест. \t 2. Узнать результат." << endl;
    cin >> answer;
    answer = dataCheck1or2(answer);
    if (answer == 2) {

        std::string line;
        std::ifstream in;
        in.open("result");

        if (in.is_open()) { // проверка на существование файла

            getline(in, line);
            int result = line[0];

            if (result < 0)
                result += 256; 
            cout << "Ваши ответы: " << endl;
            int resultM[8] = { 0,0,0,0,0,0,0,0 };

            for (int i = 0; i < 8; i++) { // Разворачиваю число
                if (result % 2 == 0) {
                    resultM[i] = 0;
                    result = result / 2;
                }
                else{
                    resultM[i] = 1;
                    result = result / 2;
                }
            }
            int j = 0;

            for (int i = 7; i > -1; i--) {
                cout << ++j << ". ";
                if (resultM[i] == 0) {
                    cout << "Нет \t";
                }
                if (resultM[i] ==1) {
                    cout << "Да \t";
                }

            }
            cout << endl << endl;
            cout << "Желаете их изменить?" << endl;
            cout << "1. Да \t 2. Нет" << endl;
            cin >> answer;
            answer = dataCheck1or2(answer);
            if (answer == 1) {
                do {
                    cout << "Введите номер вопроса, ответ на который, желаете изменить (1-8): " << endl;
                    int chNum;
                    cin >> chNum;
                    chNum = dataCheck1or8(chNum);
                    resultM [7 - chNum + 1] = question(chNum);
                    saveFunction(resultM);
                    cout << "Ваш ответ сохранён. Хотите изменить другой вопрос?" << endl;
                    cout << "1. Да \t 2. Нет" << endl;
                    cin >> answer;
                    answer = dataCheck1or2(answer);
                } while (answer != 2);
            }

        }
        
        else { //если файла нет, СДЕЛАТЬ ЧТОБЫ ДАЛЬШЕ НЕ ШЛО
            cout << "Ошибки, файл не найден." << endl;
            bool fileExistance = false;
            system("pause");
        }
        flagChange = true;
    }
    if (fileExistance == true and flagChange == false) {

        cout << "Вопрос 1. В любой многоугольник можно вписать окружность?" << endl;
        cout << "1. Да \t 2. Нет" << endl;
        cin >> answer;
        answer = dataCheck1or2(answer);
        resultF(answer);

        cout << "Вопрос 2. Треугольник называется правильным, если все его стороны и углы равны?" << endl;
        cout << "1. Да \t 2. Нет" << endl;
        cin >> answer;
        answer = dataCheck1or2(answer);
        resultF(answer);

        cout << "Вопрос 3. Любой четырехугольник с равными сторонами является правильным?" << endl;
        cout << "1. Да \t 2. Нет" << endl;
        cin >> answer;
        answer = dataCheck1or2(answer);
        resultF(answer);

        cout << "Вопрос 4. В правильном треугольнике каждый угол равен 60 градусов?" << endl;
        cout << "1. Да \t 2. Нет" << endl;
        cin >> answer;
        answer = dataCheck1or2(answer);
        resultF(answer);

        cout << "Вопрос 5. Периметр квадрата, вписанного в окружность радиуса 2, равен 8?" << endl;
        cout << "1. Да \t 2. Нет" << endl;
        cin >> answer;
        answer = dataCheck1or2(answer);
        resultF(answer);

        cout << "Вопрос 6. Ромб –правильный четырехугольник?" << endl;
        cout << "1. Да \t 2. Нет" << endl;
        cin >> answer;
        answer = dataCheck1or2(answer);
        resultF(answer);

        cout << "Вопрос 7. Любой прямоугольник можно вписать в окружность?" << endl;
        cout << "1. Да \t 2. Нет" << endl;
        cin >> answer;
        answer = dataCheck1or2(answer);
        resultF(answer);

        cout << "Вопрос 8. Около любого правильного многоугольника можно описать окружность и притом только одну?" << endl;
        cout << "1. Да \t 2. Нет" << endl;
        cin >> answer;
        answer = dataCheck1or2(answer);
        resultF(answer);
        out.open("result");
        out << resultF(3) << endl;
        out.close();
    }

    cout << "Спасибо за использование программы, досвидание." << endl;
    return 0;
}


