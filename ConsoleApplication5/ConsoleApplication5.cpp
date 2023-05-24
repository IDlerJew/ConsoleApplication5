// ConsoleApplication5.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <cmath>
using namespace std;

//Структура для точек
struct Point {
    int x;
    int y;
};

//Функция для вычисления расстояние между двумя точками
double dist(Point a, Point b) {
    return sqrt((b.x-a.x)*(b.x-a.x) + (b.y-a.y)*(b.y-a.y));
}

//Функция для вычисления периметра многоугольника
double perimeter(Point poly[], int n) {
    double perim = 0;
    for(int i=0; i<n; i++) {
        perim += dist(poly[i], poly[(i+1)%n]);
    }
    return perim;
}

//Функция для бектрекинга
void backtracking(Point poly[], int n, Point available[], int na, bool used[], int nu, double& curPerim, double& maxPerim) {
    //Если использованы все точки
    if(nu == n) {
        //Вычисляем периметр многоугольника
        double p = perimeter(poly, n);
        //Обновляем максимальный периметр
        maxPerim = max(maxPerim, p);
        return;
    }
    //Добавляем каждую доступную точку к многоугольнику
    for(int i=0; i<na; i++) {
        //Если точка еще не использована
        if(used[i] == false) {
            //Добавляем точку к многоугольнику
            poly[nu] = available[i];
            //Отмечаем точку как использованную
            used[i] = true;
            //Вызываем рекурсивно функцию для нового многоугольника
            backtracking(poly, n, available, na, used, nu+1, curPerim, maxPerim);
            //Отмечаем точку как доступную
            used[i] = false;
        }
    }
}

int main() {
    //Задаем множество точек
    Point points[] = {{0,0}, {1,2}, {3,1}, {2,4}, {5,3}, {6,6}};
   const  int n = sizeof(points)/sizeof(points[0]);
    
    //Создаем массивы доступных и использованных точек
    Point available[n];
    bool used[n] = {false};
    for(int i=0; i<n; i++) {
        available[i] = points[i];
    }
    
    //Создаем многоугольник
    Point poly[n];
    double curPerim = 0;
    double maxPerim = 0;
    
    //Вызываем функцию бектрекинга
    backtracking(poly, n, available, n, used, 0, curPerim, maxPerim);
    
    //Выводим наибольший периметр
    cout << "Maximum perimeter: " << maxPerim << endl;
    
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
