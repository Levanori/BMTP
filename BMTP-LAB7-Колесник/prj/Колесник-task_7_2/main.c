#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void print_about() {
    printf("**********************************************\n");
    printf("*      Обробка масиву                        *\n");
    printf("*  Заміна 5-го елемента середнім значенням   *\n");
    printf("*      Розробник: Віктор Колесник            *\n");
    printf("*      Пошта: kolesnykviktor2006@gmail.com   *\n");
    printf("*      Назва ЗВО: ЦНТУ                       *\n");
    printf("**********************************************\n\n");
}

double c_average(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return (double)sum / size;
}

int main() {
    setlocale(LC_ALL, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    print_about();

    int size = 15;
    int numbers[15];

    printf("Введіть %d натуральних чисел:\n", size);
    for (int i = 0; i < size; i++) {
        printf("Число %d: ", i + 1);
        while (scanf("%d", &numbers[i]) != 1 || numbers[i] <= 0) {
            printf("Помилка! Введіть натуральне число: ");
            while (getchar() != '\n');
        }
    }

    double average = c_average(numbers, size);
    numbers[4] = average;

    printf("\nОновлений масив:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    puts("\n\nДля завершення натиснiсть Enter...");
    getch();
    return 0;
}

