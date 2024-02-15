#include "Functions.h"

void cat() { // ������������ �����
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

string MainMenu(Sportsmen data, bool tag, bool firstTime) {

    // SetConsoleCP(1251); // ��������� ��������� ��� ���������� ������ ������� �������� � ����

    system("cls");

    string mode;

    cout << "������ �� ���������� � ������� ����." << endl;
    cout << "�� ������ ������ � ������ " << data.name.size() << " �����" << endl;
    cout << "�������� ����� ������ � ����������." << endl;
    cout << "������� �����, ����� ��������� ��������������� ����� ������:" << endl;
    cout << "0 - ��������� (������������� ������) ���� ������" << endl;
    cout << "1 - �������� ����� ������ � ���� ������" << endl;
    cout << "2 - ������������� ������������ ������ � ���� ������" << endl;
    cout << "3 - ����� ������ �� ���������� ���� � ���� ������" << endl;
    cout << "4 - ������� ������ �� ���������� ������ �� ���� ������" << endl;
    cout << "5 - ������� ��� ������� �� �����" << endl;
    cout << "������� q, ����� ��������� ������ � ����������" << endl;
    cout << "�������� ��������: ���� ��������� ������ � ���������� �������������, �������� ������ ������." << endl;
    cout << endl << endl;
    if (!firstTime) {
        if (tag) {
            cout << "��������� ��������: �������!" << endl;
            cat();
        }
        else {
            cout << "��������� ��������: ����������� ������!" << endl;
        }
    }
    else cat();


    // SetConsoleCP(866); // ������� �������� ���������

    while (true) {
        cin >> mode;

        /*if (mode == "2" || mode == "3" || mode == "4" || mode == "5") {
            if (data.name.size() == 0) {
                cout << "������ �� �� ������ ������������ ���� ����� - ���� ����. ���������� ������� ��������� ���." << endl;
                continue;
            }
        }*/
        if ((mode == "q") || ((mode >= "0") && (mode <= "5")))
            break;
        else {
            cout << "������." << endl;
        }
    }

    return mode;
}

void ThrowStr(Sportsmen data, unsigned int number) {
    //	cout << "���               �������               ����               ���             ��� ������          ���������� ������" << endl;
    cout << data.name[number] << " " << data.age[number] << " ��� " << data.height[number] << " �� "
        << data.weight[number] << " �� " << data.sport[number] << " " << data.sportRank[number] << endl;
}

void AddStr(Sportsmen data, bool typeEnter) // �������� ������
{
    cout << "������ �� ���������� � ������ ���������� ������ � ����� ������." << endl;
    cout << "����������, ������ ������������. ������ ���������� ������ �� ������� ����� ��� ���������� ������." << endl;
    cout << endl;

    cout << "������� ��� ����������: " << endl; // name
    while (true) {
        string input;
        cin.ignore(); // �������� �����
        getline(cin, input);
        if (input == "") {
            cout << "���������� ������." << endl;
            continue;
        }
        data.name.push_back(input);
        cout << "��� ������� �������." << endl;
        // cout << data.name.size() << endl;
        break;
    }

    cout << endl << "������� ������� (� �����): " << endl; // age
    while (true) {
        int input;
        cin >> input;
        if ((input <= 0) || (input > 99)) {
            cout << "���������� ������." << endl;
            continue;
        }
        data.age.push_back(input);
        cout << "������� ������� ������." << endl;
        break;
    }

    cout << endl << "������� ���� (� �����������): " << endl; // height
    while (true) {
        int input;
        cin >> input;
        if ((input <= 0) || (input > 230)) {
            cout << "���������� ������." << endl;
            continue;
        }
        data.height.push_back(input);
        cout << "���� ������� ������." << endl;
        break;
    }

    cout << endl << "������� ��� (� �����������): " << endl; // weight
    while (true) {
        int input;
        cin >> input;
        if ((input <= 0) || (input > 150)) {
            cout << "���������� ������." << endl;
            continue;
        }
        data.weight.push_back(input);
        cout << "��� ������� ������." << endl;
        break;
    }

    cout << endl << "������� �������� ������: " << endl; //  sports
    while (true) {
        string input;
        cin.ignore(); // �������� �����
        getline(cin, input);
        if (input == "") {
            cout << "���������� ������." << endl;
            continue;
        }
        data.sport.push_back(input);
        cout << "�������� ������ ������� �������." << endl;
        break;
    }

    cout << endl << "������� ���������� ������: " << endl; // rank
    while (true) {
        string input;
        getline(cin, input);
        if (input == "") {
            cout << "���������� ������." << endl;
            continue;
        }
        data.sportRank.push_back(input);
        cout << "���������� ������ ������� �������." << endl;
        break;
    }
    if (typeEnter) {
        cout << "������� � ������� ���� ���������� ����� 5 ������. ����������, ���������." << endl;
        //cout << data.name.size() << endl;
        //cout << data.age.size() << endl;
        //cout << data.height.size() << endl;
        //cout << data.weight.size() << endl;
        //cout << data.sport.size() << endl;

        Sleep(5000);
        MainMenu(data, true, false);
    }
    else {
        cout << "����� ������ ������� ���������." << endl;
    }
}

void Add(Sportsmen data) {
    cout << "������ �� � ������ ���������� ������� � ����." << endl;
    int tag = 1;
    while (tag) {
        AddStr(data, false);
        cout << "����� ������ ������ �����, ������� ����� �����. ���� �� ������ ��������� - ������� 0." << endl;
        cin >> tag;

    }
    MainMenu(data, true, false);
}

void SearchStr(Sportsmen data)
{
    cout << "������ �� ���������� � ������ ������ ������ �� ���������� ����." << endl;
    cout << "����������, �������� ����� ������:" << endl;
    cout << endl;

    int mode;
    cin >> mode;

    cout << "1 - ����� �� �����" << endl;
    cout << "2 - ����� �� ��������" << endl;
    cout << "3 - ����� �� �����" << endl;
    cout << "4 - ����� �� ����" << endl;
    cout << "5 - ����� �� ���� ������" << endl;
    cout << "6 - ����� �� ����������� ������" << endl;
    cout << "7 - �������� �����" << endl;

    while (true) {
        if (mode < 1 && mode > 7) {
            cout << "���������� �����." << endl;
            cin >> mode;
        }
        else break;
    }

    if (mode == 1) {
        cout << "����� ������ �� �����.." << endl;
        cout << "�������� ���:" << endl;

        string entered;
        getline(cin, entered);

        bool found = false;
        unsigned int counter = 0;

        cout << "���         �������          ����           ���        ��� ������      ���������� ������" << endl;

        for (auto i = 0u; i < data.name.size(); i++) {
            if (data.name[i] == entered) {
                ThrowStr(data, i);
                bool found = true;
                counter++;
            }
        }

        if (found) {
            cout << "����� �������: " << counter << endl;
        }
        else
            cout << "������ �� �������." << endl;
    }

    if (mode == 2) {
        cout << "����� ������ �� ��������.." << endl;
        cout << "�������� �������:" << endl;

        int entered;
        cin >> entered;

        bool found = false;
        unsigned int counter = 0;

        cout << "���         �������          ����           ���        ��� ������      ���������� ������" << endl;

        for (auto i = 0u; i < data.age.size(); i++) {
            if (data.age[i] == entered) {
                ThrowStr(data, i);
                bool found = true;
                counter++;
            }
        }

        if (found) {
            cout << "����� �������: " << counter << endl;
        }
        else
            cout << "������ �� �������." << endl;
    }

    if (mode == 3) {
        cout << "����� ������ �� �����.." << endl;
        cout << "�������� ����:" << endl;

        int entered;
        cin >> entered;

        bool found = false;
        unsigned int counter = 0;

        cout << "���         �������          ����           ���        ��� ������      ���������� ������" << endl;

        for (auto i = 0u; i < data.height.size(); i++) {
            if (data.height[i] == entered) {
                ThrowStr(data, i);
                bool found = true;
                counter++;
            }
        }

        if (found) {
            cout << "����� �������: " << counter << endl;
        }
        else
            cout << "������ �� �������." << endl;
    }

    if (mode == 4) {
        cout << "����� ������ �� ����.." << endl;
        cout << "�������� ���:" << endl;

        int entered;
        cin >> entered;

        bool found = false;
        unsigned int counter = 0;

        cout << "���         �������          ����           ���        ��� ������      ���������� ������" << endl;

        for (auto i = 0u; i < data.weight.size(); i++) {
            if (data.weight[i] == entered) {
                ThrowStr(data, i);
                bool found = true;
                counter++;
            }
        }

        if (found) {
            cout << "����� �������: " << counter << endl;
        }
        else
            cout << "������ �� �������." << endl;
    }

    if (mode == 5) {
        cout << "����� ������ �� ���� ������.." << endl;
        cout << "�������� ��� ������:" << endl;

        string entered;
        getline(cin, entered);

        bool found = false;
        unsigned int counter = 0;

        cout << "���         �������          ����           ���        ��� ������      ���������� ������" << endl;

        for (auto i = 0u; i < data.sport.size(); i++) {
            if (data.sport[i] == entered) {
                ThrowStr(data, i);
                bool found = true;
                counter++;
            }
        }

        if (found) {
            cout << "����� �������: " << counter << endl;
        }
        else
            cout << "������ �� �������." << endl;
    }

    if (mode == 6) {
        cout << "����� ������ �� ����������� ������.." << endl;
        cout << "�������� ���������� ������:" << endl;

        string entered;
        getline(cin, entered);

        bool found = false;
        unsigned int counter = 0;

        cout << "���         �������          ����           ���        ��� ������      ���������� ������" << endl;

        for (auto i = 0u; i < data.sportRank.size(); i++) {
            if (data.sportRank[i] == entered) {
                ThrowStr(data, i);
                bool found = true;
                counter++;
            }
        }

        if (found) {
            cout << "����� �������: " << counter << endl;
        }
        else
            cout << "������ �� �������." << endl;
    }

    if (mode == 7) {
        cout << "����� �� ������ ������ ����� 3 �������. ����������, ���������." << endl;
        Sleep(3000);
        MainMenu(data, true, false);
    }
}

void EditStr(Sportsmen data)
{
    cout << "������ �� ���������� � ������ �������������� ���������� ���� ������." << endl;
    cout << "����������, ������� ����� ������, ���� ������� ������ ���������������: " << endl;
    cout << "�� ������ ������ � ������ " << data.name.size() << " �����." << endl;

    int number;
    cin >> number;
    while (number >= data.name.size() || number < 0) {
        cout << "���������� �����." << endl;
        cin >> number;
    }

    cout << "������ �� ������������ " << number << " ������. ��� ��������� ����:" << endl;
    cout << "���         �������          ����           ���        ��� ������      ���������� ������" << endl;
    ThrowStr(data, number);

    cout << "����������, �������� ���� ��� ��������������:" << endl;
    cout << endl;

    int mode;
    cin >> mode;

    cout << "1 - �������������� �����" << endl;
    cout << "2 - �������������� ��������" << endl;
    cout << "3 - �������������� �����" << endl;
    cout << "4 - �������������� ����" << endl;
    cout << "5 - �������������� ���� ������" << endl;
    cout << "6 - �������������� ����������� ������" << endl;
    cout << "7 - �������� ��������������" << endl;

    cin >> mode;
    while (true) {
        if (mode < 1 && mode > 7) {
            cout << "���������� �����." << endl;
            cin >> mode;
        }
        else break;
    }

    if (mode == 1) {
        int tag = 0;
        while (!tag) {
            cout << "������� ����� ���.." << endl;
            string temp;
            cin >> temp;
            while (!temp.empty()) {
                cout << "���������� ������." << endl;
                cin >> temp;
            }
            data.name[number] = temp;
            cout << "��� ��� �������� ����������������� ������ ������: " << endl;
            ThrowStr(data, number);
            cout << endl << "����� ����������� ������� 1, ����� ��������������� ������ ������ ������� 0." << endl;
            while (!(tag == 1) && !(tag == 0)) {
                cout << "���������� �����." << endl;
                cin >> tag;
            }
        }

        cout << "����� �� ������ �������������� ����� 3 �������. ����������, ���������." << endl;
        Sleep(3000);
        MainMenu(data, true, false);
    }

    if (mode == 2) {
        int tag = 0;
        while (!tag) {
            cout << "������� ����� �������.." << endl;
            int temp;
            cin >> temp;
            while (temp <= 0 || temp > 99) {
                cout << "���������� �����." << endl;
                cin >> temp;
            }
            data.age[number] = temp;
            cout << "��� ��� �������� ����������������� ������ ������: " << endl;
            ThrowStr(data, number);
            cout << endl << "����� ����������� ������� 1, ����� ��������������� ������ ������ ������� 0." << endl;
            while (!(tag == 1) && !(tag == 0)) {
                cout << "���������� �����." << endl;
                cin >> tag;
            }
        }

        cout << "����� �� ������ �������������� ����� 3 �������. ����������, ���������." << endl;
        Sleep(3000);
        MainMenu(data, true, false);
    }

    if (mode == 3) {
        int tag = 0;
        while (!tag) {
            cout << "������� ����� ����.." << endl;
            int temp;
            cin >> temp;
            while (temp <= 0 || temp > 230) {
                cout << "���������� �����." << endl;
                cin >> temp;
            }
            data.height[number] = temp;
            cout << "��� ��� �������� ����������������� ������ ������: " << endl;
            ThrowStr(data, number);
            cout << endl << "����� ����������� ������� 1, ����� ��������������� ������ ������ ������� 0." << endl;
            while (!(tag == 1) && !(tag == 0)) {
                cout << "���������� �����." << endl;
                cin >> tag;
            }
        }

        cout << "����� �� ������ �������������� ����� 3 �������. ����������, ���������." << endl;
        Sleep(3000);
        MainMenu(data, true, false);
    }

    if (mode == 4) {
        int tag = 0;
        while (!tag) {
            cout << "������� ����� ���.." << endl;
            int temp;
            cin >> temp;
            while (temp <= 0 || temp > 150) {
                cout << "���������� �����." << endl;
                cin >> temp;
            }
            data.weight[number] = temp;
            cout << "��� ��� �������� ����������������� ������ ������: " << endl;
            ThrowStr(data, number);
            cout << endl << "����� ����������� ������� 1, ����� ��������������� ������ ������ ������� 0." << endl;
            while (!(tag == 1) && !(tag == 0)) {
                cout << "���������� �����." << endl;
                cin >> tag;
            }
        }

        cout << "����� �� ������ �������������� ����� 3 �������. ����������, ���������." << endl;
        Sleep(3000);
        MainMenu(data, true, false);
    }

    if (mode == 5) {
        int tag = 0;
        while (!tag) {
            cout << "������� ����� ��� ������.." << endl;
            string temp;
            cin >> temp;
            while (!temp.empty()) {
                cout << "���������� ������." << endl;
                cin >> temp;
            }
            data.sport[number] = temp;
            cout << "��� ��� �������� ����������������� ������ ������: " << endl;
            ThrowStr(data, number);
            cout << endl << "����� ����������� ������� 1, ����� ��������������� ������ ������ ������� 0." << endl;
            while (!(tag == 1) && !(tag == 0)) {
                cout << "���������� �����." << endl;
                cin >> tag;
            }
        }

        cout << "����� �� ������ �������������� ����� 3 �������. ����������, ���������." << endl;
        Sleep(3000);
        MainMenu(data, true, false);
    }

    if (mode == 6) {
        int tag = 0;
        while (!tag) {
            cout << "������� ����� ���������� ������.." << endl;
            string temp;
            cin >> temp;
            while (!temp.empty()) {
                cout << "���������� ������." << endl;
                cin >> temp;
            }
            data.sportRank[number] = temp;
            cout << "��� ��� �������� ����������������� ������ ������: " << endl;
            ThrowStr(data, number);
            cout << endl << "����� ����������� ������� 1, ����� ��������������� ������ ������ ������� 0." << endl;
            while (!(tag == 1) && !(tag == 0)) {
                cout << "���������� �����." << endl;
                cin >> tag;
            }
        }

        cout << "����� �� ������ �������������� ����� 3 �������. ����������, ���������." << endl;
        Sleep(3000);
        MainMenu(data, true, false);
    }

    if (mode == 7) {
        cout << "����� �� ������ �������������� ����� 3 �������. ����������, ���������." << endl;
        Sleep(3000);
        MainMenu(data, true, false);
    }
}

void ThrowData(Sportsmen data)
{
    cout << "���         �������          ����           ���        ��� ������      ���������� ������" << endl;
    for (auto i = 0u; i < data.name.size(); i++) {
        ThrowStr(data, i);
    }
    cout << "�� ������ ������ � ������ " << data.name.size() << " �����." << endl;

    cout << "����� ��������� � ������� ����, ������� ����� ������" << endl;
    string q;
    cin >> q;
    
    MainMenu(data, true, false);
    return;
}

void RemoveStr(Sportsmen data)
{
    cout << "������ �� ���������� � ������ �������� ��������� ������." << endl;
    cout << "����������, ������� ����� ������, ������� ������ �������: " << endl;
    cout << "����� ����� �� ������ �������� ������ ������� q" << endl;

    cout << "�� ������ ������ � ������ " << data.name.size() << " �����." << endl;

    char numberTemp;
    while (true) {
        cin >> numberTemp;

        if (numberTemp == 'q') {
            cout << "����� � ������� ���� ����� 3 �������. ����������, ���������." << endl;
            Sleep(3000);
            MainMenu(data, true, false);
            break;
        }
        int number = (int)numberTemp;
        while (number >= data.name.size() || number < 0) {
            cout << "���������� �����." << endl;
            cin >> number;
        }

        cout << "������ ����� " << number << " :" << endl;
        ThrowStr(data, number);
        cout << "����� ����������� �������� ������� 1. ����� �������� �������� � �������� ����� ������ ������� 0." << endl;
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

        cout << endl << "������ ������� �������." << endl;
        cout << "������ � ������ " << data.name.size() << "�����" << endl;
    }
}

