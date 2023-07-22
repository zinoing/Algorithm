// bubble sort로 구현
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

class Location {
    typedef struct Pos {
        int xPos;
        int yPos;

        Pos operator=(const Pos& pos) {
            xPos = pos.xPos;
            yPos = pos.yPos;
            return *this;
        }

    }Pos;
    Pos* array;
    int size;

public:
    Location(int n = 0)
        :array(new Pos[n]), size(n) {}

    int getxPos(int idx) {
        return array[idx].xPos;
    }

    int getyPos(int idx) {
        return array[idx].yPos;
    }

    Pos getPos(int idx) {
        return array[idx];
    }

    void setPos(int idx, int xPos, int yPos) {
        array[idx].xPos = xPos;
        array[idx].yPos = yPos;
        return;
    }

    int compare(int a, int b) {
        if (a > b) {
            return 1;
        }
        if (a == b) {
            return 0;
        }
        return -1;
    }

    void sort() { // 버블정렬로 구현하였지만 시간초과가 났다.
        Pos tempPos;
        for (int i = 0; i < size - 2; i++) {
            for (int j = 0; j < size - 1 - i; j++) {
                if (compare(getyPos(j), getyPos(j + 1)) == 1) {
                    tempPos = getPos(j);
                    setPos(j, getxPos(j + 1), getyPos(j + 1));
                    setPos(j + 1, tempPos.xPos, tempPos.yPos);
                }
                else if (compare(getyPos(j), getyPos(j + 1)) == 0) {
                    if (compare(getxPos(j), getxPos(j + 1)) == 1) {
                        tempPos = getPos(j);
                        setPos(j, getxPos(j + 1), getyPos(j + 1));
                        setPos(j + 1, tempPos.xPos, tempPos.yPos);
                    }
                    else continue;
                }
                else continue;
            }
        }
    }

    void show() {
        for (int i = 0; i < size; i++) {
            printf("%d %d \n", array[i].xPos, array[i].yPos);
        }
    }

    ~Location() {
        delete[] array;
    }
};

int main(void) {
    int n = 0;
    scanf("%d", &n);

    Location locations(n);

    for (int i = 0; i < n; i++) {
        int xPos, yPos;
        scanf("%d %d", &xPos, &yPos);
        locations.setPos(i, xPos, yPos);
    }
    locations.sort();
    locations.show();

    return 0;
}

// quick sort로 구현
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

class Location {
    typedef struct Pos {
        int xPos;
        int yPos;

        Pos operator=(const Pos& pos) {
            xPos = pos.xPos;
            yPos = pos.yPos;
            return *this;
        }

    }Pos;
    Pos* array;
    int size;

public:
    Location(int n = 0)
        :array(new Pos[n]), size(n) {}

    Pos* getArray() {
        return array;
    }

    int getxPos(int idx) {
        return array[idx].xPos;
    }

    int getyPos(int idx) {
        return array[idx].yPos;
    }

    Pos getPos(int idx) {
        return array[idx];
    }

    void setPos(int idx, int xPos, int yPos) {
        array[idx].xPos = xPos;
        array[idx].yPos = yPos;
        return;
    }

    void swap(Pos& a, Pos& b) {
        Pos temp;
        temp = a;
        a = b;
        b = temp;
        return;
    }

    void quickSort(Pos* array, int head, int tail) {
        if (head >= tail)
            return;

        Pos pivot = array[tail];
        int i = head - 1;
        for (int j = head; j <= tail; j++) {

            if (j == tail) {
                i++;
                swap(array[j], array[i]);

                quickSort(array, head, i-1);
                quickSort(array, i + 1, tail);
                return;
            }


            if (array[j].yPos > pivot.yPos)
                continue;
            else if (array[j].yPos < pivot.yPos) {
                i++;
                swap(array[j], array[i]);
            }
            else { // if two yPoses are same
                if (array[j].xPos > pivot.xPos)
                    continue;
                else {
                    i++;
                    swap(array[j], array[i]);
                }
            }
        }
        return;
    }

    void show() {
        for (int i = 0; i < size; i++) {
            printf("%d %d \n", array[i].xPos, array[i].yPos);
        }
    }

    ~Location() {
        delete[] array;
    }
};

int main(void) {
    int n = 0;
    scanf("%d", &n);

    Location locations(n);

    for (int i = 0; i < n; i++) {
        int xPos, yPos;
        scanf("%d %d", &xPos, &yPos);
        locations.setPos(i, xPos, yPos);
    }
    locations.quickSort(locations.getArray(), 0, n-1);
    locations.show();
    return 0;
}

// merge sort로 구현
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

class Pos {
public:
    int xPos = 0;
    int yPos = 0;

    Pos& operator= (const Pos& pos) {
        this->xPos = pos.xPos;
        this->yPos = pos.yPos;
        return *this;
    }
};

Pos array[100001] = { 0, };
Pos* array2;

void merge(int left, int mid, int right) {
    int i, j, k;
    i = left;
    j = mid + 1;
    k = left;

    while (1) {
        if (i > mid || j > right)
            break;

        if (array[i].yPos < array[j].yPos) {
            array2[k++] = array[i++];
        }
        else if (array[i].yPos > array[j].yPos) {
            array2[k++] = array[j++];
        }
        else {
            if (array[i].xPos < array[j].xPos) {
                array2[k++] = array[i++];
            }
            else {
                array2[k++] = array[j++];
            }
        }
    }

    while (i <= mid) {
        array2[k++] = array[i++];
    }

    while (j <= right) {
        array2[k++] = array[j++];
    }

    for (int i = left; i <= right; i++) {
        array[i] = array2[i];
    }
}

void partition(int left, int right) {
    int mid = (left + right) / 2;
    if (left < right) {
        partition(left, mid);
        partition(mid + 1, right);
        merge(left, mid, right);
    }
    return;
}

int main(void) {
    int n = 0;
    scanf("%d", &n);

    array2 = new Pos[n];

    for (int i = 0; i < n; i++) {
        scanf("%d %d", &array[i].xPos, &array[i].yPos);
    }

    partition(0, n-1);
    
    for (int i = 0; i < n; i++) {
        printf("%d %d \n", array[i].xPos, array[i].yPos);
    }

    delete[] array2;
    return 0;
}
