#include <iostream>
#include <assert.h>

using namespace std;
//1_2.  Вычислить площадь выпуклого n-угольника, заданного координатами своих вершин.
// Вначале вводится количество вершин, затем последовательно целочисленные координаты всех вершин в порядке обхода против часовой стрелки.
//n < 1000, координаты < 10000.
//Указание. Для вычисления площади n-угольника можно посчитать сумму ориентированных площадей трапеций под каждой стороной многоугольника.
///12398347


void InsertPoints(int* Xarray, int* Yarray, int pointCounter) {
    for(int i = 0; i < pointCounter; ++i) {
        scanf("%d %d", &Xarray[i], &Yarray[i]);
        assert(Xarray[i] < 10000 && Yarray[i] < 10000);
    }
}

double CalculArea(int* Xarray, int* Yarray, int pointCounter) {
    int i = 0;
    int prevX = Xarray[i];
    int prevY = Yarray[i];
    double Area = 0;

    for(i = 1; i < pointCounter; ++i) {
        Area += 0.5 * (Xarray[i] - prevX) * (Yarray[i] + prevY);
        prevX = Xarray[i];
        prevY = Yarray[i];
    }
    Area += 0.5 * (Xarray[0] - prevX) * (Yarray[0] + prevY);

    return Area;
}

int main() {
    int pointCounter = 0;
    double Area = 0;

    scanf("%d", &pointCounter);
    assert(pointCounter < 1000);

    int* Xarray = new int[pointCounter];
    int* Yarray = new int[pointCounter];

    InsertPoints(Xarray, Yarray, pointCounter);

    double result = CalculArea(Xarray, Yarray, pointCounter);

    printf("%.1f", result);

    delete [] Xarray;
    delete [] Yarray;
    return 0;
}