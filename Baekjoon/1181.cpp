#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#define STR_LENGTH 50
using namespace std;

void merge(char**& sorted, char**& str, int left, int mid, int right) {
    int i, j, k, l;
    i = left;
    j = mid + 1;
    k = left;

     while (i <= mid && j <= right) {
        if (strlen(str[i]) > strlen(str[j])) {
            sorted[k++] = str[j++];
        }
        else if (strlen(str[i]) == strlen(str[j])) { // 두 문자열 길이가 같다면
            if (strcmp(str[i], str[j]) > 0) { 
                sorted[k++] = str[j++];
            }
            else {
                sorted[k++] = str[i++];
            }
        }
        else {
            sorted[k++] = str[i++];
        }
    }

    if (i > mid) {
        for (l = j; l <= right; l++)
            sorted[k++] = str[l];
    }
    else {
        for (l = i; l <= mid; l++)
            sorted[k++] = str[l];
    }

    for (l = left; l <= right; l++) {
        str[l] = sorted[l];
    }
}

void merge_sort(char**& sorted, char**& str, int left, int right) {
    int mid;
    if (left < right) {
        mid = (left + right) / 2;
        merge_sort(sorted, str, left, mid);
        merge_sort(sorted, str, mid+1, right);
        merge(sorted, str, left, mid, right);
    }
}

void print(char** str, int size) {
    for (int i = 0; i < size; i++) {
        if (i != size-1 && strcmp(str[i], str[i + 1]) == 0)
            continue;
        cout << str[i] << endl;
    }
}

int main()
{
    int num_words;
    cin >> num_words;

    char** str = new char*[num_words];
    for (int i = 0; i < num_words; i++) {
        str[i] = new char[STR_LENGTH];
    }

    char** sorted = new char* [num_words];
    for (int i = 0; i < num_words; i++) {
        sorted[i] = new char[STR_LENGTH];
    }

    for (int i = 0; i < num_words; i++) {
        cin >> str[i];
    }

    merge_sort(sorted, str, 0, num_words - 1);

    print(str, num_words);

    for (int i = 0; i < num_words; i++) {
         delete[] str[i];
    }
    delete[] str;
}
