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
  int kol = 0;
    for (int index = 0; index <= (len-1); index++) {
        int starting = 0;
        int ending = len-1;
        while (starting <= ending) {
            int i = (starting + ending) / 2;
            if ((arr[i]+arr[index] == value) && i!=index) {
                kol++;
                for (int j = i + 1; (j <= len-1) && (arr[j] + arr[index] == value) && (i != index); j++) {
                    kol++;
                }
                for (int j = i - 1; (arr[j] + arr[index] == value) && (j >= 0) &&  (i != index); j--) {
                    kol++;
                }
                break;
            } 
            if (arr[i] + arr[index] > value) ending = i - 1;
            else if (arr[i] + arr[index] < value) starting = i + 1;
        }
    }
    kol = kol / 2;
    return kol;
}
