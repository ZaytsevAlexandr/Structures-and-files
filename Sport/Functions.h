#include "Functions.h"

void cat() { // разноцветная кошка
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int color = 0;
    SetConsoleTextAttribute(hConsole, ++color);
    cout << "_____$$_____$$" << endl;
    SetConsoleTextAttribute(hConsole, ++color);
    cout << "_____$$$___$$$" << endl;
    SetConsoleTextAttribute(hConsole, ++color);
    cout << "_____$$$$$$$$$_______$$" << endl;
    SetConsoleTextAttribute(hConsole, ++color);
    cout << "______$$$$$$$_______$$$" << endl;
    SetConsoleTextAttribute(hConsole, ++color);
    cout << "_______$$$$$________$$$$" << endl;
    SetConsoleTextAttribute(hConsole, ++color);
    cout << "________$$$__________$$$$" << endl;
    SetConsoleTextAttribute(hConsole, ++color);
    cout << "________$$$$__________$$$" << endl;
    SetConsoleTextAttribute(hConsole, ++color);
    cout << "________$$$$$$$______$$$" << endl;
    SetConsoleTextAttribute(hConsole, ++color);
    cout << "________$$$$$$$$____$$$" << endl;
    SetConsoleTextAttribute(hConsole, ++color);
    cout << "_________$$$$$$$____$$" << endl;
    SetConsoleTextAttribute(hConsole, ++color);
    cout << "__________$$$$$$___$$" << endl;
    SetConsoleTextAttribute(hConsole, ++color);
    cout << "__________$$$$$_$__$$" << endl;
    SetConsoleTextAttribute(hConsole, ++color);
    cout << "__________$$$$_$$$_$$" << endl;
    SetConsoleTextAttribute(hConsole, ++color);
    cout << "__________$$$_$$$$$_$$" << endl;
    SetConsoleTextAttribute(hConsole, ++color);
    cout << "_________$$$__$$$$_$$" << endl;
}

string MainMenu(Sportsmen& data, bool tag, bool firstTime) {

    // SetConsoleCP(1251); // Изменение кодировки для корректной записи русских символов в файл

    system("cls");

    string mode;

    cout << "Сейчас вы находитесь в главном меню." << endl;
    cout << "На данный момент в списке " << data.name.size() << " строк" << endl;
    cout << "Выберете режим работы с программой." << endl;
    cout << "Нажмите цифру, чтобы запустить соответствующий режим работы:" << endl;
    cout << "0 - заполнить (перезаполнить заново) базу данных" << endl;
    cout << "1 - добавить новую запись в базу данных" << endl;
    cout << "2 - редактировать существующую запись в базе данных" << endl;
    cout << "3 - найти запись по выбранному полю в базе данных" << endl;
    cout << "4 - удалить запись по выбранному номеру из базы данных" << endl;
    cout << "5 - вывести всю таблицу на экран" << endl;
    cout << "Введите q, чтобы завершить работу с программой" << endl;
    cout << "Обратите внимание: если завершить работу с программой принудительно, возможна утрата данных." << endl;
    cout << endl << endl;
    if (!firstTime) {
        if (tag) {
            cout << "Последнее действие: Успешно!" << endl;
            cat();
        }
        else {
            cout << "Последнее действие: Неизвестная ошибка!" << endl;
        }
    }
    else cat();


    // SetConsoleCP(866); // Возврат исходной кодировки

    while (true) {
        cin >> mode;

        /*if (mode == "2" || mode == "3" || mode == "4" || mode == "5") {
            if (data.name.size() == 0) {
                cout << "Сейчас вы не можете использовать этот режим - файл пуст. Попробуйте сначала заполнить его." << endl;
                continue;
            }
        }*/
        if ((mode == "q") || ((mode >= "0") && (mode <= "5")))
            break;
        else {
            cout << "Ошибка." << endl;
        }
    }

    return mode;
}

void ThrowStr(Sportsmen& data, unsigned int number) {
    //	cout << "Имя               Возраст               Рост               Вес             Вид спорта          Спортивное звание" << endl;
    cout << data.name[number] << " " << data.age[number] << " лет " << data.height[number] << " см "
        << data.weight[number] << " кг " << data.sport[number] << " " << data.sportRank[number] << endl;
}

void AddStr(Sportsmen& data, bool typeEnter) // добавить запись
{
    cout << "Сейчас вы находитесь в режиме добавления данных в новую строку." << endl;
    cout << "Пожалуйста, будьте внимательнее. Данные необходимо ввести на русском языке для корректной работы." << endl;
    cout << endl;

    cout << "Введите имя спортсмена: " << endl; // name
    while (true) {
        string input;
        cin.ignore(); // обнулить буфер
        getline(cin, input);
        if (input == "") {
            cout << "Попробуйте заново." << endl;
            continue;
        }
        data.name.push_back(input);
        cout << "Имя успешно введено." << endl;
        // cout << data.name.size() << endl;
        break;
    }

    cout << endl << "Введите возраст (в годах): " << endl; // age
    while (true) {
        int input;
        cin >> input;
        if ((input <= 0) || (input > 99)) {
            cout << "Попробуйте заново." << endl;
            continue;
        }
        data.age.push_back(input);
        cout << "Возраст успешно введен." << endl;
        break;
    }

    cout << endl << "Введите рост (в сантиметрах): " << endl; // height
    while (true) {
        int input;
        cin >> input;
        if ((input <= 0) || (input > 230)) {
            cout << "Попробуйте заново." << endl;
            continue;
        }
        data.height.push_back(input);
        cout << "Рост успешно введен." << endl;
        break;
    }

    cout << endl << "Введите вес (в килограммах): " << endl; // weight
    while (true) {
        int input;
        cin >> input;
        if ((input <= 0) || (input > 150)) {
            cout << "Попробуйте заново." << endl;
            continue;
        }
        data.weight.push_back(input);
        cout << "Вес успешно введен." << endl;
        break;
    }

    cout << endl << "Введите название спорта: " << endl; //  sports
    while (true) {
        string input;
        cin.ignore(); // обнулить буфер
        getline(cin, input);
        if (input == "") {
            cout << "Попробуйте заново." << endl;
            continue;
        }
        data.sport.push_back(input);
        cout << "Название спорта успешно введено." << endl;
        break;
    }

    cout << endl << "Введите спортивное звание: " << endl; // rank
    while (true) {
        string input;
        getline(cin, input);
        if (input == "") {
            cout << "Попробуйте заново." << endl;
            continue;
        }
        data.sportRank.push_back(input);
        cout << "Спортивное звание успешно введено." << endl;
        break;
    }
    if (typeEnter) {
        cout << "Возврат в главное меню произойдет через 5 секунд. Пожалуйста, подождите." << endl;
        //cout << data.name.size() << endl;
        //cout << data.age.size() << endl;
        //cout << data.height.size() << endl;
        //cout << data.weight.size() << endl;
        //cout << data.sport.size() << endl;

        Sleep(5000);
        MainMenu(data, true, false);
    }
    else {
        cout << "Новая строка успешно добавлена." << endl;
    }
}

void Add(Sportsmen& data) {
    cout << "Сейчас вы в режиме заполнения массива с нуля." << endl;
    int tag = 1;
    while (tag) {
        AddStr(data, false);
        cout << "Чтобы ввести строку далее, введите любое число. Если вы хотите закончить - введите 0." << endl;
        cin >> tag;

    }
    MainMenu(data, true, false);
}

void SearchStr(Sportsmen& data)
{
    system("cls");
    cout << "Сейчас вы находитесь в режиме поиска данных по выбранному полю." << endl;
    cout << "Пожалуйста, выберете режим поиска:" << endl;
    cout << endl;

    int mode;
    cin >> mode;

    cout << "1 - поиск по имени" << endl;
    cout << "2 - поиск по возрасту" << endl;
    cout << "3 - поиск по росту" << endl;
    cout << "4 - поиск по весу" << endl;
    cout << "5 - поиск по виду спорта" << endl;
    cout << "6 - поиск по спортивному званию" << endl;
    cout << "7 - отменить поиск" << endl;

    while (true) {
        if (mode < 1 && mode > 7) {
            cout << "Попробуйте снова." << endl;
            cin >> mode;
        }
        else break;
    }

    if (mode == 1) {
        cout << "Режим поиска по имени.." << endl;
        cout << "Введитие имя:" << endl;

        string entered;
        getline(cin, entered);

        bool found = false;
        unsigned int counter = 0;

        cout << "Имя         Возраст          Рост           Вес        Вид спорта      Спортивное звание" << endl;

        for (auto i = 0u; i < data.name.size(); i++) {
            if (data.name[i] == entered) {
                ThrowStr(data, i);
                bool found = true;
                counter++;
            }
        }

        if (found) {
            cout << "Строк найдено: " << counter << endl;
        }
        else
            cout << "Ничего не найдено." << endl;
    }

    if (mode == 2) {
        cout << "Режим поиска по возрасту.." << endl;
        cout << "Введитие возраст:" << endl;

        int entered;
        cin >> entered;

        bool found = false;
        unsigned int counter = 0;

        cout << "Имя         Возраст          Рост           Вес        Вид спорта      Спортивное звание" << endl;

        for (auto i = 0u; i < data.age.size(); i++) {
            if (data.age[i] == entered) {
                ThrowStr(data, i);
                bool found = true;
                counter++;
            }
        }

        if (found) {
            cout << "Строк найдено: " << counter << endl;
        }
        else
            cout << "Ничего не найдено." << endl;
    }

    if (mode == 3) {
        cout << "Режим поиска по росту.." << endl;
        cout << "Введитие рост:" << endl;

        int entered;
        cin >> entered;

        bool found = false;
        unsigned int counter = 0;

        cout << "Имя         Возраст          Рост           Вес        Вид спорта      Спортивное звание" << endl;

        for (auto i = 0u; i < data.height.size(); i++) {
            if (data.height[i] == entered) {
                ThrowStr(data, i);
                bool found = true;
                counter++;
            }
        }

        if (found) {
            cout << "Строк найдено: " << counter << endl;
        }
        else
            cout << "Ничего не найдено." << endl;
    }

    if (mode == 4) {
        cout << "Режим поиска по весу.." << endl;
        cout << "Введитие вес:" << endl;

        int entered;
        cin >> entered;

        bool found = false;
        unsigned int counter = 0;

        cout << "Имя         Возраст          Рост           Вес        Вид спорта      Спортивное звание" << endl;

        for (auto i = 0u; i < data.weight.size(); i++) {
            if (data.weight[i] == entered) {
                ThrowStr(data, i);
                bool found = true;
                counter++;
            }
        }

        if (found) {
            cout << "Строк найдено: " << counter << endl;
        }
        else
            cout << "Ничего не найдено." << endl;
    }

    if (mode == 5) {
        cout << "Режим поиска по виду спорта.." << endl;
        cout << "Введитие вид спорта:" << endl;

        string entered;
        getline(cin, entered);

        bool found = false;
        unsigned int counter = 0;

        cout << "Имя         Возраст          Рост           Вес        Вид спорта      Спортивное звание" << endl;

        for (auto i = 0u; i < data.sport.size(); i++) {
            if (data.sport[i] == entered) {
                ThrowStr(data, i);
                bool found = true;
                counter++;
            }
        }

        if (found) {
            cout << "Строк найдено: " << counter << endl;
        }
        else
            cout << "Ничего не найдено." << endl;
    }

    if (mode == 6) {
        cout << "Режим поиска по спортивному званию.." << endl;
        cout << "Введитие спортивное звание:" << endl;

        string entered;
        getline(cin, entered);

        bool found = false;
        unsigned int counter = 0;

        cout << "Имя         Возраст          Рост           Вес        Вид спорта      Спортивное звание" << endl;

        for (auto i = 0u; i < data.sportRank.size(); i++) {
            if (data.sportRank[i] == entered) {
                ThrowStr(data, i);
                bool found = true;
                counter++;
            }
        }

        if (found) {
            cout << "Строк найдено: " << counter << endl;
        }
        else
            cout << "Ничего не найдено." << endl;
    }

    if (mode == 7) {
        cout << "Выход из режима поиска через 3 секунды. Пожалуйста, подождите." << endl;
        Sleep(3000);
        MainMenu(data, true, false);
    }
}

void EditStr(Sportsmen& data)
{
    system("cls");
    cout << "Сейчас вы находитесь в режиме редактирования выбранного поля строки." << endl;
    cout << "Пожалуйста, введите номер строки, поле которой хотите отредактировать: " << endl;
    cout << "На данный момент в списке " << data.name.size() << " строк." << endl;

    int number;
    cin >> number;
    while (number >= data.name.size() || number < 0) {
        cout << "Попробуйте снова." << endl;
        cin >> number;
    }

    cout << "Сейчас вы редактируете " << number << " строку. Она приведена ниже:" << endl;
    cout << "Имя         Возраст          Рост           Вес        Вид спорта      Спортивное звание" << endl;
    ThrowStr(data, number);

    cout << "Пожалуйста, выберете поле для редактирования:" << endl;
    cout << endl;

    int mode;
    cin >> mode;

    cout << "1 - редактирование имени" << endl;
    cout << "2 - редактирование возраста" << endl;
    cout << "3 - редактирование роста" << endl;
    cout << "4 - редактирование веса" << endl;
    cout << "5 - редактирование вида спорта" << endl;
    cout << "6 - редактирование спортивного звания" << endl;
    cout << "7 - отменить редактирование" << endl;

    cin >> mode;
    while (true) {
        if (mode < 1 && mode > 7) {
            cout << "Попробуйте снова." << endl;
            cin >> mode;
        }
        else break;
    }

    if (mode == 1) {
        int tag = 0;
        while (!tag) {
            cout << "Введите новое имя.." << endl;
            string temp;
            cin >> temp;
            while (!temp.empty()) {
                cout << "Попробуйте заново." << endl;
                cin >> temp;
            }
            data.name[number] = temp;
            cout << "Вот как выглядит отредактированная строка сейчас: " << endl;
            ThrowStr(data, number);
            cout << endl << "Чтобы подтвердить нажмите 1, чтобы отредактировать строку заново введите 0." << endl;
            while (!(tag == 1) && !(tag == 0)) {
                cout << "Попробуйте снова." << endl;
                cin >> tag;
            }
        }

        cout << "Выход из режима редактирования через 3 секунды. Пожалуйста, подождите." << endl;
        Sleep(3000);
        MainMenu(data, true, false);
    }

    if (mode == 2) {
        int tag = 0;
        while (!tag) {
            cout << "Введите новый возраст.." << endl;
            int temp;
            cin >> temp;
            while (temp <= 0 || temp > 99) {
                cout << "Попробуйте снова." << endl;
                cin >> temp;
            }
            data.age[number] = temp;
            cout << "Вот как выглядит отредактированная строка сейчас: " << endl;
            ThrowStr(data, number);
            cout << endl << "Чтобы подтвердить нажмите 1, чтобы отредактировать строку заново введите 0." << endl;
            while (!(tag == 1) && !(tag == 0)) {
                cout << "Попробуйте снова." << endl;
                cin >> tag;
            }
        }

        cout << "Выход из режима редактирования через 3 секунды. Пожалуйста, подождите." << endl;
        Sleep(3000);
        MainMenu(data, true, false);
    }

    if (mode == 3) {
        int tag = 0;
        while (!tag) {
            cout << "Введите новый рост.." << endl;
            int temp;
            cin >> temp;
            while (temp <= 0 || temp > 230) {
                cout << "Попробуйте снова." << endl;
                cin >> temp;
            }
            data.height[number] = temp;
            cout << "Вот как выглядит отредактированная строка сейчас: " << endl;
            ThrowStr(data, number);
            cout << endl << "Чтобы подтвердить нажмите 1, чтобы отредактировать строку заново введите 0." << endl;
            while (!(tag == 1) && !(tag == 0)) {
                cout << "Попробуйте снова." << endl;
                cin >> tag;
            }
        }

        cout << "Выход из режима редактирования через 3 секунды. Пожалуйста, подождите." << endl;
        Sleep(3000);
        MainMenu(data, true, false);
    }

    if (mode == 4) {
        int tag = 0;
        while (!tag) {
            cout << "Введите новый вес.." << endl;
            int temp;
            cin >> temp;
            while (temp <= 0 || temp > 150) {
                cout << "Попробуйте снова." << endl;
                cin >> temp;
            }
            data.weight[number] = temp;
            cout << "Вот как выглядит отредактированная строка сейчас: " << endl;
            ThrowStr(data, number);
            cout << endl << "Чтобы подтвердить нажмите 1, чтобы отредактировать строку заново введите 0." << endl;
            while (!(tag == 1) && !(tag == 0)) {
                cout << "Попробуйте снова." << endl;
                cin >> tag;
            }
        }

        cout << "Выход из режима редактирования через 3 секунды. Пожалуйста, подождите." << endl;
        Sleep(3000);
        MainMenu(data, true, false);
    }

    if (mode == 5) {
        int tag = 0;
        while (!tag) {
            cout << "Введите новый вид спорта.." << endl;
            string temp;
            cin >> temp;
            while (!temp.empty()) {
                cout << "Попробуйте заново." << endl;
                cin >> temp;
            }
            data.sport[number] = temp;
            cout << "Вот как выглядит отредактированная строка сейчас: " << endl;
            ThrowStr(data, number);
            cout << endl << "Чтобы подтвердить нажмите 1, чтобы отредактировать строку заново введите 0." << endl;
            while (!(tag == 1) && !(tag == 0)) {
                cout << "Попробуйте снова." << endl;
                cin >> tag;
            }
        }

        cout << "Выход из режима редактирования через 3 секунды. Пожалуйста, подождите." << endl;
        Sleep(3000);
        MainMenu(data, true, false);
    }

    if (mode == 6) {
        int tag = 0;
        while (!tag) {
            cout << "Введите новое спортивное звание.." << endl;
            string temp;
            cin >> temp;
            while (!temp.empty()) {
                cout << "Попробуйте заново." << endl;
                cin >> temp;
            }
            data.sportRank[number] = temp;
            cout << "Вот как выглядит отредактированная строка сейчас: " << endl;
            ThrowStr(data, number);
            cout << endl << "Чтобы подтвердить нажмите 1, чтобы отредактировать строку заново введите 0." << endl;
            while (!(tag == 1) && !(tag == 0)) {
                cout << "Попробуйте снова." << endl;
                cin >> tag;
            }
        }

        cout << "Выход из режима редактирования через 3 секунды. Пожалуйста, подождите." << endl;
        Sleep(3000);
        MainMenu(data, true, false);
    }

    if (mode == 7) {
        cout << "Выход из режима редактирования через 3 секунды. Пожалуйста, подождите." << endl;
        Sleep(3000);
        MainMenu(data, true, false);
    }
}

void ThrowData(Sportsmen& data)
{
    system("cls");
    cout << "Имя         Возраст          Рост           Вес        Вид спорта      Спортивное звание" << endl;
    for (auto i = 0u; i < data.name.size(); i++) {
        ThrowStr(data, i);
    }
    cout << "На данный момент в списке " << data.name.size() << " строк." << endl;

    cout << "Чтобы вернуться в главное меню, введите любой символ" << endl;
    string q;
    cin >> q;
    
    MainMenu(data, true, false);
    return;
}

void RemoveStr(Sportsmen& data)
{
    system("cls");
    cout << "Сейчас вы находитесь в режиме удаления выбранной строки." << endl;
    cout << "Пожалуйста, введите номер строки, которую хотите удалить: " << endl;
    cout << "Чтобы выйти из режима удаления строки введите q" << endl;

    cout << "На данный момент в списке " << data.name.size() << " строк." << endl;


    while (true) {
        char numberTemp;
        cin >> numberTemp;

        if (numberTemp == 'q') {
            cout << "Выход в главное меню через 3 секунды. Пожалуйста, подождите." << endl;
            Sleep(3000);
            MainMenu(data, true, false);
            break;
        }
        int number = (int)numberTemp;
        while (number >= data.name.size() || number < 0) {
            cout << "Попробуйте снова." << endl;
            cin >> number;
        }

        cout << "Строка номер " << number << " :" << endl;
        ThrowStr(data, number);
        cout << "Чтобы подтвердить удаление нажмите 1. Чтобы отменить удаление и поменять номер строки введите 0." << endl;
        int tag;
        cin >> tag;
        if (!tag)
            continue;

        data.name.erase(data.name.begin() + number - 1);
        data.age.erase(data.age.begin() + number - 1);
        data.height.erase(data.height.begin() + number - 1);
        data.weight.erase(data.weight.begin() + number - 1);
        data.sport.erase(data.sport.begin() + number - 1);
        data.sportRank.erase(data.sportRank.begin() + number - 1);

        cout << endl << "Строка успешно удалена." << endl;
        cout << "Теперь в списке " << data.name.size() << "строк" << endl;
    }
}

