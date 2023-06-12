#include <iostream>
#include "Shape.h"

int main () {
    system("chcp 65001");
    system("cls");

    Circle circle;
    Triangle triangle;
    Print_Points point;

    // point.WritePointsOfCircle();
    // point.SavePOC();
    point.Result(&circle);
    point.Result(&triangle);
    // point.WritePointsOfTriangle();
    // point.Result(&triangle);

    return 0;
}