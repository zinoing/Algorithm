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
