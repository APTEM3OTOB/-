#include <stdio.h>
#include <string.h>

#define MAX_WORDS 100
#define MAX_LENGTH 100

int main() {
char str[] = "aaabb aaabb aaadd aaaaa aaafff";
char words[MAX_WORDS][MAX_LENGTH];
int count = 0;

// Разделение строки на слова
char *token = strtok(str, " ");
while (token != NULL && count < MAX_WORDS) {
strcpy(words[count], token);
count++;
token = strtok(NULL, " ");
}

// Сортировка пузырьком
for (int i = 0; i < count - 1; i++) {
for (int j = 0; j < count - i - 1; j++) {
if (strcmp(words[j], words[j + 1]) > 0) {
char temp[MAX_LENGTH];
strcpy(temp, words[j]);
strcpy(words[j], words[j + 1]);
strcpy(words[j + 1], temp);
}
}
}

// Вывод отсортированных слов
printf("Слова в алфавитном порядке:\n");
for (int i = 0; i < count; i++) {
printf("%s\n", words[i]);
}

// Пример: находим порядковый номер слова "aaadd"
char *search_word = "aaadd";
int position = -1;

for (int i = 0; i < count; i++) {
if (strcmp(words[i], search_word) == 0) {
position = i + 1; // Позиция в алфавитном порядке (начиная с 1)
break;
}
}

if (position != -1) {
printf("Слово '%s' находится на %d месте в алфавитном порядке.\n", search_word, position);
} else {
printf("Слово '%s' не найдено.\n", search_word);
}

return 0;
}