#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <windows.h>

void print_about() {
    printf("**********************************************\n");
    printf("*      Перевірка слова                       *\n");
    printf("*      \"девелопер\" у реченні                 *\n");
    printf("*      (UTF-8, консоль CP866)                *\n");
    printf("*      Розробник: Віктор Колесник            *\n");
    printf("*      Пошта: kolesnykviktor2006@gmail.com   *\n");
    printf("*      Назва ЗВО: ЦНТУ                       *\n");
    printf("**********************************************\n\n");
}

void cp866_to_utf8(const char *src, char *dst, int dst_size) {
    wchar_t wbuffer[256];
    MultiByteToWideChar(866, 0, src, -1, wbuffer, 256);
    WideCharToMultiByte(CP_UTF8, 0, wbuffer, -1, dst, dst_size, NULL, NULL);
}

int main() {
    setlocale(LC_ALL, "C.UTF-8");
    SetConsoleCP(866);
    SetConsoleOutputCP(65001);

    print_about();

    char sentence[256];
    char utf8_sentence[256];

    printf("Введіть речення, яке закінчується на '.':\n");
    if (!fgets(sentence, sizeof(sentence), stdin)) {
        printf("Помилка вводу!\n");
        return 1;
    }
    size_t len = strlen(sentence);
    if (len > 0 && sentence[len - 1] == '\n') {
        sentence[len - 1] = '\0';
        len--;
    }
    if (len == 0 || sentence[len - 1] != '.') {
        printf("Помилка: речення повинно закінчуватися на '.'\n");
        return 1;
    }
    cp866_to_utf8(sentence, utf8_sentence, sizeof(utf8_sentence));
    if (strstr(utf8_sentence, "девелопер") != NULL) {
        printf("У введеному реченні є слово \"девелопер\".\n");
    } else {
        printf("У введеному реченні немає слова \"девелопер\".\n");
    }
    puts("\n\nДля завершення натиснiсть Enter...");
    getch();
    return 0;
}
