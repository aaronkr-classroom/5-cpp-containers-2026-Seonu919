#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <cctype>

using namespace std;

struct Rotation {
    string left;
    string right;

    // 대소문자 무시하고 비교하기 위한 함수
    bool operator<(const Rotation& other) const {
        string s1 = right, s2 = other.right;
        // 모두 소문자로 변환하여 비교
        for (char& c : s1) c = tolower(c);
        for (char& c : s2) c = tolower(c);
        return s1 < s2;
    }
};

int main() {
    string line;
    vector<Rotation> all_rotations;

    // 1. 입력 받기 (Ctrl+Z 또는 빈 줄 입력 시 종료)
    while (getline(cin, line) && !line.empty()) {
        stringstream ss(line);
        vector<string> words;
        string word;
        while (ss >> word) words.push_back(word);

        for (size_t i = 0; i < words.size(); ++i) {
            string left_part = "", right_part = "";
            for (size_t j = 0; j < i; ++j)
                left_part += words[j] + (j == i - 1 ? "" : " ");
            for (size_t j = i; j < words.size(); ++j)
                right_part += words[j] + (j == words.size() - 1 ? "" : " ");

            all_rotations.push_back({ left_part, right_part });
        }
    }

    // 2. 대소문자 무시 정렬
    sort(all_rotations.begin(), all_rotations.end());

    // 3. 이미지와 동일한 서식 출력
    for (const auto& rot : all_rotations) {
        // 이미지의 간격을 맞추기 위해 왼쪽 문맥에 너비 20 부여
        cout << setw(20) << right << rot.left;
        cout << "   ";
        cout << left << rot.right << endl;
    }

    return 0;
}
