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
    for (int index = 0; index < (len-1); index++) {
        int starting = index;
        int ending = len;
        while (starting < ending-1) {
            int i = (starting + ending) / 2;
            if ((arr[i]+arr[index] == value) && i != index) {
                kol++;
                for (int j = i + 1; (j < ending) 
                     && (arr[j] + arr[index] == value) 
                     && (i != index); j++) {
                    kol++;
                }
                for (int j = i - 1; (j > starting) 
                     && (arr[j] + arr[index] == value) 
                     &&  (i != index); j--) {
                    kol++;
                }
                break;
            } 
            if (arr[i] + arr[index] > value) ending = i;
            if (arr[i] + arr[index] < value) starting = i;
        }
    }
    return kol;
}
