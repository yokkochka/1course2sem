/*
 Задача 5.20
  Функция, получив строку, в которой могут быть цифры  в конце, в начале, в середине, 
  удаляет из нее только начальные и конечные цифры. Функция  возвращает адрес строки, 
  если строку удалось преобразовать, и NULL, если не удалось.
  Приложение из введенной строки-фразы формирует два массива слов: исходный и новый массив, 
  выбирая из исходного массива только те слова, которые удалось подвергнуть модификации по 
  правилу выше описанной функции
*/



#include <iostream>

using namespace std;

char** createArrayOfWords(char* str, int& countOfWords);
int dlina(char* str);
char* poisrWord(char* str, int& len);
void output_array(char** array, int count);
char** createNewArrayOfWords(char** array, int countOfWords, int& countOfNewWords);
int isNumber(char symb);
int proverka(char* str);
char* deleteNumbers(char* slovo);

int len = 0;

int main() {
    int flag = 1;
    while (flag)
    {
        setlocale(LC_ALL, "rus");
        cout << "Введите строку из слов: ";
        char* str = new char[100];
        cin.getline(str, 100, '\n');
        //cin.ignore();
        cout << endl << "Исходная строка: " << str;

        int countOfWords = 0;
        char** arrayOfWords = createArrayOfWords(str, countOfWords);

        cout << endl << "Исходный массив слов: ";
        output_array(arrayOfWords, countOfWords);

        int countOfNewWords = 0;
        char** arrayOfNewWords = createNewArrayOfWords(arrayOfWords, countOfWords, countOfNewWords);

        cout << endl << "Новый массив слов: ";
        output_array(arrayOfNewWords, countOfNewWords);

        cout << "repeat? 1/0" << endl;
        cin >> flag;

    }
    


}

int dlina(char* str) {
    int dlina = 0;
    while (*str) {
        dlina++;
        str++;
    }
    return dlina;
}

char* poisrWord(char* str, int& len) {
    len = 0;
    char* word;

    // Пока пробел двигаю
    while (*str == ' ') str++;
    if (*str == '\0') return 0;
    // Запоминаю указатель на первое слово
    word = str;

    // Считаю длину
    while (*word != ' ' && *word != '\0') { word++; len++; }

    return str;
}

char** createArrayOfWords(char* str, int& countOfWords) {
    char** array = new char* [20];

    for (countOfWords = 0; *str; countOfWords++) {
        char* word = poisrWord(str, len);
        array[countOfWords] = new char[len];
        //word[len] = '\0';  // Обрубаю слово
        //for(int i = 0; i < len; i++) - без нее все работает
        //array[countOfWords] = word;
        for (int i = 0; i < len; i++, word++) {
            array[countOfWords][i] = *word;
        }
        str = word + 1; // Двигаю указатель на следующее слово
    }
    return array;
}


char createNewArrayOfWords(char array, int countOfWords, int& countOfNewWords) {
    char** newArray = new char* [20];
    for (int i = 0; i < countOfWords; i++) {
        char* slovo = array[i];
        if (proverka(slovo)) {
            slovo = deleteNumbers(slovo);
            int lenght = dlina(slovo);
            newArray[i] = new char[lenght];
            countOfNewWords++;
            for (int j = 0; *slovo; j++, slovo++)
            {
                newArray[i][j] = *slovo;

            }

        }
    }
    return newArray;
}

int isNumber(char symb) {
    if ((symb >= '0') && (symb <= '9')) {
        return 1;
    }
    return 0;
}


int proverka(char* str) {
    int flag = 0;
    char symbol1 = *str, symbol2 = *(str + dlina(str) - 1);
    if ((isNumber(symbol1)) || (isNumber(symbol2))) flag = 1;
    return flag;
}

char* deleteNumbers(char* slovo) {
    int lenght = dlina(slovo);
    char* start = slovo;
    //char* end = slovo+lenght;

    // Удаление слева
    while (*start) {
        char symbol = *start;
        if (isNumber(symbol)) start++;
        else break;
    }

    char* slovo1 = start;
    //slovo = start;
    int i = 1;
    char symbol = *(slovo + lenght - i);
    while (isNumber(symbol)) {
        *(slovo + lenght - i) = '\0';
        i++;
        symbol = *(slovo + lenght - i);

    }

    return slovo1;
}

void output_array(char** array, int count) {
    for (int i = 0; i < count; i++) {
        cout << array[i] << " | ";
    }
}