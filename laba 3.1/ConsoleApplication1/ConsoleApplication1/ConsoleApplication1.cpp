#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

void countWordsStartingWithA(const vector<string>& words) {
    int count = 0;
    for (const auto& w : words) {
        if (w[0] == 'а' || w[0] == 'А') {
            count++;
        }
    }
    cout << "Количество слов, начинающихся с буквы 'a': " << count << endl;
}

void findShortestWordLength(const vector<string>& words) {
    int minLength = numeric_limits<int>::max();
    for (const auto& w : words) {
        if (w.length() < minLength) {
            minLength = w.length();
        }
    }
    cout << "Длина самого короткого слова: " << minLength << endl;
}

void countAInLastWord(const vector<string>& words) {
    const string& lastWord = words.back();
    int countA = count(lastWord.begin(), lastWord.end(), 'a') +
        count(lastWord.begin(), lastWord.end(), 'A');
    cout << "Количество букв 'a' в последнем слове: " << countA << endl;
}

void convertToLowerCase(string& str) {
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    cout << "Строка с заменой всех букв в верхнем регистре на строчные: " << str << endl;
}

void countWordsWithSameFirstLastChar(const vector<string>& words) {
    int count = 0;
    for (const auto& w : words) {
        if (w.front() == w.back()) {
            count++;
        }
    }
    cout << "Количество слов, у которых первый и последний символы совпадают: " << count << endl;
}

string findShortestCommonSubstring(const string& str1, const string& str2) {
    for (size_t len = 1; len <= min(str1.size(), str2.size()); ++len) {
        for (size_t start = 0; start <= str1.size() - len; ++start) {
            string substr = str1.substr(start, len);
            if (str2.find(substr) != string::npos) {
                return substr; // Возвращаем первую найденную подстроку
            }
        }
    }
    return ""; // Если ничего не найдено
}

void findCommonSubstringBetweenWords(const vector<string>& words) {
    if (words.size() >= 2) {
        string commonSubstring = findShortestCommonSubstring(words[0], words[1]);
        cout << "Самая короткая общая подстрока между первыми двумя словами: " << commonSubstring << endl;
    }
}

int main() {
    string input;
    cout << "Введите строку из 10 слов: ";
    getline(cin, input);

    istringstream stream(input);
    vector<string> words;
    string word;

    while (stream >> word) {
        words.push_back(word);
    }

    if (words.size() != 10) {
        cerr << "Ошибка: должно быть ровно 10 слов." << endl;
        return 1;
    }

    countWordsStartingWithA(words);
    findShortestWordLength(words);
    countAInLastWord(words);

    string lowerCaseStr = input;
    convertToLowerCase(lowerCaseStr);

    countWordsWithSameFirstLastChar(words);
    findCommonSubstringBetweenWords(words);

    return 0;
}
