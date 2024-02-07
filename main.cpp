
#include <iostream>
#include <windows.h>
#include "DoublyLinkedList.h" //si no funciona cambiar a .h

using namespace std;


void gotoxy(auto x, auto y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void CuadroGrande(int width, int height) {
    for (int i = -2; i < width; ++i) {
        gotoxy(i, 0);
        printf("%c", 205); // Borde superior
        gotoxy(i, height - 1);
        printf("%c", 205); // Borde inferior
    }
    for (int i = 0; i < height; ++i) {
        gotoxy(0, i);
        printf("%c", 186); // Borde izquierdo
        gotoxy(width - 1, i);
        printf("%c", 186); // Borde derecho
    }
    // Esquinas
    gotoxy(0, 0);
    printf("%c", 201);
    gotoxy(width - 1, 0);
    printf("%c", 187);
    gotoxy(0, height - 1);
    printf("%c", 200);
    gotoxy(width - 1, height - 1);
    printf("%c", 188);
}

void MiniCuadro(int startX, int startY, int width, int height) {
    // Dibujar esquinas
    gotoxy(startX, startY);
    cout << char(201);
    gotoxy(startX + width - 1, startY);
    cout << char(187);
    gotoxy(startX, startY + height - 1);
    cout << char(200);
    gotoxy(startX + width - 1, startY + height - 1);
    cout << char(188);

    // Dibujar bordes horizontales
    for (int i = startX + 1; i < startX + width - 1; ++i) {
        gotoxy(i, startY);
        cout << char(205);
        gotoxy(i, startY + height - 1);
        cout << char(205);
    }

    // Dibujar bordes verticales
    for (int i = startY + 1; i < startY + height - 1; ++i) {
        gotoxy(startX, i);
        cout << char(186);
        gotoxy(startX + width - 1, i);
        cout << char(186);
    }
}

void PantallaInicial() {
    system("cls"); // Limpiamos la pantalla

    int consoleWidth = 120; // Ancho de la consola
    int consoleHeight = 30; // Altura de la consola

    CuadroGrande(consoleWidth, consoleHeight); // Dibujamos el borde grande

    // Calculamos las coordenadas para centrar el cuadro de bienvenida
    int boxWidth = 50; // Ancho del cuadro pequeño
    int boxHeight = 10; // Altura del cuadro pequeño
    int startX = (consoleWidth - boxWidth) / 2;
    int startY = 3; // Mover el cuadro más arriba

    MiniCuadro(startX, startY, boxWidth, boxHeight); // Dibujamos el cuadro pequeño

    // Posicionamos el primer texto dentro del cuadro
    string firstText = "B U S Q U E D A  S E C U E N C I A L";
    int firstStartX = startX + (boxWidth - firstText.length()) / 2;
    int firstStartY = startY + 2; // Ajustar la posición vertical del texto
    gotoxy(firstStartX, firstStartY);
    cout << firstText;

    // Posicionamos el segundo texto dentro del cuadro
    string secondText = "B I N A R I A  I T E R A T I V A";
    int secondStartX = startX + (boxWidth - secondText.length()) / 2;
    int secondStartY = startY + 4;
    gotoxy(secondStartX, secondStartY);
    cout << secondText;

    // Posicionamos el tercer texto dentro del cuadro
    string thirdText = "Y  R E C U R S I V A";
    int thirdStartX = startX + (boxWidth - thirdText.length()) / 2;
    int thirdStartY = startY + 6;
    gotoxy(thirdStartX, thirdStartY);
    cout << thirdText;

    // Posicionamos el tercer texto dentro del cuadro
    string LoadText = "CARGANDO...";
    int LoadStartX = startX + (boxWidth - LoadText.length()) / 2;
    int LoadStartY = startY + 24;
    gotoxy(LoadStartX, LoadStartY);
    cout << LoadText;

    // Calculamos las coordenadas para centrar la barra de carga
    int barStartX = startX - 15; // Ajuste horizontal para centrar la barra
    int barStartY = startY + boxHeight + 15; // Ajuste vertical para mover la barra hacia abajo

    // For para la barra de carga
    for (int i = 1; i <= 76; ++i) {
        gotoxy(barStartX + i, barStartY);
        printf("%c", 177);
    }

    for (int i = 1; i <= 76; ++i) {
        gotoxy(barStartX + i, barStartY);
        printf("%c", 219);
        Sleep(35);
    }

    system("cls");
    CuadroGrande(consoleWidth, consoleHeight);
}



int sequentialSearch(const int arr[], int size, int ref) {
    for (int i = 0; i < size; i++) {
        if (ref == arr[i]) {
            return i;
        }
    }
    return -1;
}

int binarySearch(const int arr[], int size, int ref) {

    int start = 0;
    int end = size-1;
    int mid = start + (end - start)/2;

    while(start <= end) {
        if(arr[mid] == ref) {
            return mid;
        }
        if(ref > arr[mid]) {
            start = mid + 1;
        } else{
            end = mid - 1;
        }
        mid = start + (end-start)/2;
    }

    return -1;
}

int recursiveSearch(const int arr[], int start, int end, int ref) { // NOLINT(misc-no-recursion)

    int mid = (end + start)/2;

    if (arr[mid] == ref) {
        return mid;
    }

    if (start > end) {
        return -1;
    }

    if (ref < arr[mid]) {
        return recursiveSearch(arr, start, mid - 1, ref);
    } else {
        return recursiveSearch(arr, mid + 1, end, ref);
    }
}

int main () {

    //system("COLOR E0");

    int consoleWidth = 120; // Ancho de la consola
    int consoleHeight = 30; // Altura de la consola

    // Dibujamos el cuadro grande alrededor de la consola
    for (int i = 0; i < consoleWidth; ++i) {
        gotoxy(i, 0);
        printf("%c", 205); // Borde superior
        gotoxy(i, consoleHeight - 1);
        printf("%c", 205); // Borde inferior
    }
    for (int i = 0; i < consoleHeight; ++i) {
        gotoxy(0, i);
        printf("%c", 186); // Borde izquierdo
        gotoxy(consoleWidth - 1, i);
        printf("%c", 186); // Borde derecho
    }
    // Esquinas
    gotoxy(0, 0);
    printf("%c", 201);
    gotoxy(consoleWidth - 1, 0);
    printf("%c", 187);
    gotoxy(0, consoleHeight - 1);
    printf("%c", 200);
    gotoxy(consoleWidth - 1, consoleHeight - 1);
    printf("%c", 188);


    PantallaInicial();
    system("cls");


    int busq = 10;

    int MyArray[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


    cout << "Arreglo de numeros:" << endl;

    cout << endl;

    gotoxy(2,3);
    for (int i : MyArray) {
        cout << i << " - ";
    }
    cout << endl;

    gotoxy(2,5);
    if (sequentialSearch(MyArray, 10, busq) != -1) {
        cout << "ELEMENTO " << busq << " ENCONTRADO CON EL INDICE " << sequentialSearch(MyArray, 10, busq) << endl;
    }
    else {
        cout << "ELEMENTO " << busq << " NO ENCONTRADO EN EL ARREGLO" << endl;
    }

    gotoxy(2,7);
    if (binarySearch(MyArray, 10, busq) != -1) {
        cout << "ELEMENTO " << busq << " ENCONTRADO CON EL INDICE " << binarySearch(MyArray, 10, busq) << endl;
    } else {
        cout << "ELEMENTO " << busq << " NO ENCONTRADO EN EL ARREGLO" << endl;
    }

    gotoxy(2,9);
    if (recursiveSearch(MyArray,0, 10, busq) != -1) {
        cout << "ELEMENTO " << busq << " ENCONTRADO CON EL INDICE " << recursiveSearch(MyArray, 0, 10, busq) << endl;
    } else {
        cout << "ELEMENTO " << busq << " NO ENCONTRADO EN EL ARREGLO" << endl;
    }





    DoublyLinkedList MyList = DoublyLinkedList();

    gotoxy(2,11);
    for (int i = 0; i < 10; i++) {
        MyList.insert(i + 1);
    }
    MyList.displayList();

    gotoxy(2,13);
    if (MyList.sequentialSearch(busq) != 0) {
        cout << "ELEMENTO " << busq << " ENCONTRADO EN LA POSICION " << MyList.sequentialSearch(busq) << endl;
    } else {
        cout << "ELEMENTO " << busq << " NO ENCONTRADO EN LA LISTA" << endl;
    }

    gotoxy(2,15);
    if (MyList.binarySearch(busq)) {
        cout << "ELEMENTO " << busq << " ENCONTRADO EN LA LISTA" << endl;
    } else {
        cout << "ELEMENTO " << busq << " NO ENCONTRADO EN LA LISTA" << endl;
    }

    gotoxy(2,17);
    if (MyList.recursiveSearch(busq)) {
        cout << "ELEMENTO " << busq << " ENCONTRADO EN LA LISTA" << endl;
    } else {
        cout << "ELEMENTO " << busq << " NO ENCONTRADO EN LA LISTA" << endl;
    }

    CuadroGrande(consoleWidth, consoleHeight);

    getch();
    return 0;
}


