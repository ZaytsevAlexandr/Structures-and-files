#include "Functions.h"

int main() {
    setlocale(LC_CTYPE, "rus");

    const string path = "mainfile.txt"; // ������ ���� ����� ����� ������ �����. ���� ������������ � � ������� �� ��������.

    Sportsmen data;

    while (true) {
        string mode;
        mode = MainMenu(data, true, true);
        if (mode == "0")
            Add(data);
        if (mode == "1")
            AddStr(data, true);
        if (mode == "2")
            EditStr(data);
        if (mode == "3")
            SearchStr(data);
        if (mode == "4")
            RemoveStr(data);
        if (mode == "5")
            ThrowData(data);
        if (mode == "q") {
            cout << "������ � ���������� ���������. ����� ��� �������." << endl;
            break;
        }

    }

    return 1;
}
