// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int kol = 0;
    for (int i = 0; i < (len-1); i++) {
        for (int j = i + 1; j <= (len-1); j++) {
            if (arr[i] + arr[j] == value) {
                kol++;
            }
        }
    }
    return kol;
}
int countPairs2(int *arr, int len, int value) {
  int kol = 0;
    for (int i = 0; i < (len - 1); i++) {
        for (int j = len-1; j > i; j--) {
            if (arr[i] + arr[j] == value) {
                kol++;
            }
        }
    }
    return kol;
}
int countPairs3(int *arr, int len, int value) {
  int starting = 0;
    int ending = size - 1;
    int kol = 0;
    while (starting <= ending) {
        int i = (starting + ending) / 2;
        if (arr[i] == value) {
            kol++;
            for (int j = i + 1; j <= size && arr[j] == value; j++) {
                kol++;
            }
            for (int j = i - 1; j >= 0 && arr[j] == value; j--) {
                kol++;
            }
            return kol;
        }
        if (arr[i] > value) ending = i - 1;
        if (arr[i] < value) starting = i + 1;
    }
    return 0;
}
