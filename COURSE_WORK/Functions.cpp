#include "Functions.h"


// функція для генерації дійсного числа
double GenerateDouble()
{
	double number = rand() % 100;
	number /= 100;
	number += -100 + rand() % 200;
	return number;
}

// функція для валідації строки (якщо строка представляє число, то повертаємо 1)
bool is_number_validator(std::string s)
{
    bool hasDecimalPoint = false;
    bool hasMinus = false;
    int counter = 0;

    for (char c : s) {
        if (iswdigit(c)) {
            if (counter > 300)  return false;
            counter++;
            continue;
        }
        else if (c == '-' && !hasMinus)
        {
            hasMinus = true;
        }
        else if (((c == '.' || c == ',') && !hasDecimalPoint)) {
            hasDecimalPoint = true;
        }
        else {
            return false;
        }
    }

    return true;
}

// конвертація String у string
std::string& Convert_String_to_string(String^ s, std::string& ss)
{
    using namespace Runtime::InteropServices;
    const char* chars = (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
    ss = chars;
    Marshal::FreeHGlobal(IntPtr((void*)chars));
    return ss;
}

// конвертація string у String
String^ Convert_string_to_String(std::string& ss, String^ s)
{
    s = gcnew System::String(ss.c_str());
    return s;
}


// якщо файл не підтримує формат, потрібний для матриці, то повертаємо 0
    /* формат, який підтримується програмою
    3  - розмірність матриці
    6 2 5
    7 8 1
    5 1 3
    */
bool FileFormatValidator(std::string s)
{
    std::ifstream file(s);
    if (!file.is_open()) {
        return false;
    }

    try {
        std::string str;
        int counter = 0;
        std::string word;
        double size_of_matrix = 0;

        while (getline(file, str)) {
            int counter_of_words = 0;
            std::istringstream temp(str);
            if (counter == 0) {
                while (temp >> word) {
                    counter_of_words++;
                    if (!is_number_validator(word))
                        return false;
                    if (counter_of_words > 1)
                        return false;
                    size_of_matrix = stod(word);
                    if (size_of_matrix != int(size_of_matrix))
                        return false;
                }
            }

            if (counter != 0) {
                while (temp >> word) {
                    counter_of_words++;
                    if (!is_number_validator(word))
                        return false;
                    if (counter_of_words > size_of_matrix)
                        return false;
                    if (size_of_matrix <= 0)
                        return false;
                }
            }
            if (counter > size_of_matrix)
                return false;
            counter++;
        }
        if (counter != size_of_matrix + 1)
            return false;
        return true;
    }
    finally {
        file.close();
    }
}

//перевірка існування файлу
bool fileExists(const std::string& filename) {
    std::ifstream file(filename);
    return file.good();
}

//запис матриці у файл
void processFile(std::ofstream& file, Matrix& A, int act = 0, int it = 0) {
    int size = A.GetRows();
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            file << std::left << std::setw(15) << A.GetElement(i, j);
        }
       file << std::endl;
    }
    if (act && it) {
        std::string mess = "Кількість виконаних елементарних операцій: " + std::to_string(act);
        file << std::endl << mess << std::endl;
        mess = "Кількість виконаних ітерацій: " + std::to_string(it);
        file << mess;
    }
}



