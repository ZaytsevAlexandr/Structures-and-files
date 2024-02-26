#include "Functions.h"

int main() {
    setlocale(LC_CTYPE, "rus");
    system("chcp 1251");
    Sportsmen data;

    const string path = "mainfile.txt"; // Задать путь файла
    UpdateStructureFromFile(path, data);

    while (true) {
        string mode;
        mode = MainMenu(data);
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
            cout << "Работа с программой заверешна. Всего вам доброго." << endl;
            UpdateFileFromStructure(path, data);
            break;
        }
        UpdateFileFromStructure(path, data);
    }
    return 1;
}
