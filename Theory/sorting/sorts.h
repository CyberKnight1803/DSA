void swap(int *x, int *y){
    int t = *x;
    *x = *y;
    *y = t;
}

void bubbleSort(int n, int arr[]){
    for(int i = 0; i < n - 1; ++i){
        for(int j = 0; j < n - i - 1; ++j){
            if(arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void selectionSort(int n, int arr[]){
    for(int i = 0; i < n - 1; ++i){
        int idx = i;
        for(int j = i + 1; j < n; ++j){
            if(arr[j] < arr[idx]){
                idx = j;
            }
        }
        swap(&arr[idx], &arr[i]);
    }
}

void insertionSort(int n, int arr[]){
    int key, j;
    for(int i = 1; i < n; ++i){
        key = arr[i];
        j = i - 1;

        while(arr[j] > key && j >= 0){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


void merge(int *arr, int start, int mid, int end){
    int t[end - start + 1];             // Temporary array
    int p = start, q = mid + 1, k = 0;  // Checkpoints and counters

    for(int i = start; i <= end; ++i){
        if(p > mid){
            t[k++] = arr[q++];
        }
        else if(q > end){
            t[k++] = arr[p++];
        }
        else if(arr[p] < arr[q]){
            t[k++] = arr[p++];
        }
        else{
            t[k++] = arr[q++];
        }
    }

    for(int i = 0; i < k; ++i){
        arr[start++] = t[i];
    }
}

 

void mergeSort(int *arr, int start, int end){
    if(start < end){
        int mid = (start + end) / 2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid + 1, end);

        merge(arr, start, mid, end);
    }
}

