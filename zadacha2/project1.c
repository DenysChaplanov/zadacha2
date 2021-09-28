#include <stdio.h>
#include <malloc.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

int kolvo(int* arr, int n) {
    int kol = 0;
    int avarange = 0, sum = 0;
    int i;;
    for (i = 0; i < n; i++) {
        sum += arr[i];
    }
    avarange = sum / n;
    printf("Среднее значение = %d\n", avarange);

    for (i = 0; i < n; i++) {
        if (arr[i] > avarange)
            kol++;
    }
    printf("Количество элементов, больших ср.знач элементов массива: %d\n", kol);
    return kol;
}

int summa(int* arr, int n) {
    int sum = 0;
    int otric, i;
    for (i = 0; i < n; i++)
        if (arr[i] < 0) {
            otric = i + 1;
            break;
        }
    for (i = otric; i < n; i++)
        sum += abs(arr[i]);
    printf("Сумма модулей, после первого отриц элемента = %d\n", sum);
    return sum;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    int* arr;
    int i, n;

    printf("Введите размер массива: ");
    scanf("%d", &n);

    arr = (int*)malloc(n * sizeof(int));

    for (i = 0; i < n; i++)
    {
        arr[i] = rand() % 30 - 20;
    }

    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    kolvo(arr, n);
    summa(arr, n);
    free(arr);
    return 0;
}