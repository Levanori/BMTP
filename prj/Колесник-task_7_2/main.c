#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void print_about() {
    printf("**********************************************\n");
    printf("*      ������� ������                        *\n");
    printf("*  ����� 5-�� �������� ������� ���������   *\n");
    printf("*      ���������: ³���� ��������            *\n");
    printf("*      �����: kolesnykviktor2006@gmail.com   *\n");
    printf("*      ����� ���: ����                       *\n");
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

    printf("������ %d ����������� �����:\n", size);
    for (int i = 0; i < size; i++) {
        printf("����� %d: ", i + 1);
        while (scanf("%d", &numbers[i]) != 1 || numbers[i] <= 0) {
            printf("�������! ������ ���������� �����: ");
            while (getchar() != '\n');
        }
    }

    double average = c_average(numbers, size);
    numbers[4] = average;

    printf("\n��������� �����:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    puts("\n\n��� ���������� ������i��� Enter...");
    getch();
    return 0;
}

