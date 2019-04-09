#include <stdio.h>
#include <stdlib.h>
/*
*冒泡排序 
*时间复杂度 o(n^2)
*稳定
*与输入数据无关
*/
void BubbleSort(int *arr, int len)
{
    int temp;
    for(int i = 0; i < len - 1; ++i){
        for(int j = len - 1; j > i; --j){ //j = 0； j < len -1 -i; ++j
            if(arr[j] < arr[j-1]){
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j-1] = temp;
            }
        }
    }
    return;
}

//改进的冒泡排序，没有数据交换时直接退出
//与数据的输入有关
void improveBubbleSort(int *arr, int len)
{
    int temp;
    int flag = 1;
    for(int i = 0; i < len - 1 && flag; ++i){
        flag = 0;
        for(int j = len - 1; j > i; --j){ //j = 0； j < len -1 -i; ++j
            if(arr[j] < arr[j-1]){
                flag = 1;
                temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j-1] = temp;
            }
        }
    }
    return;
}


/*
选择排序
时间复杂度 o(n^2)
不稳定
与输入数据无关
*/
void SelectSort(int *arr, int len)
{
    int minindex, temp;
    for(int i = 0; i < len; ++i){
        minindex = i;
        for(int j = i + 1; j < len; ++j){
            if(arr[j] < arr[minindex]){
                minindex = j;
            }
        }
        if(minindex != i){
            temp = arr[i];
            arr[i] = arr[minindex];
            arr[minindex] = temp;
        }
    }
    return;
}


/*
直接插入排序 o(n^2)
数据有序o(n) 数据无序o(n^2)
与输入数据有关
稳定
*/
void InsertSort(int *arr, int len)
{
    int current, preindex;
    for(int i = 1; i < len; ++i){
        preindex = i - 1;
        current = arr[i];
        while(preindex >=0 && arr[preindex] > current){
            arr[preindex + 1] = arr[preindex];
            --preindex;
        }
        arr[preindex + 1] = current;
    }
}

/*
希尔排序 插入排序的改进
稳定
*/
void ShellSort(int *arr, int len)
{
    for(int ince = len/2; ince > 0; ince/=2){
        for(int i = ince; i < len; ++i){
            int j = i;
            int current = arr[i];
            while(j-ince >= 0 && current < arr[j-ince]){
                arr[j] = arr[j-ince];
                j -= ince;
            }
            arr[j] = current;
        }
    }
    return;
}

/*归并排序
稳定
o(nlogn) 空间o(n+logn)
与输入数据无关
*/
void Merge(int *arr, int left, int mid, int right)
{
    int *tmp = (int *)malloc((right - left + 1)*sizeof(int));
    int i = left;
    int j = mid + 1;
    int k = 0;

    while(i <= mid && j <= right){
        if(arr[i] > arr[j]){
            tmp[k++] = arr[j++];
        }
        else{
            tmp[k++] = arr[i++];
        }
    }
    while(i <= mid){
        tmp[k++] = arr[i++];
    }
    while(j <= right){
        tmp[k++] = arr[j++];
    }

    for(i = 0; i < k; ++i){
        arr[left + i] = tmp[i];
    }

    free(tmp);
}
void MergeSort(int *arr, int left, int right)
{
    if(left >= right){
        return;
    }

    int mid = (left + right)/2;
    MergeSort(arr, left, mid);
    MergeSort(arr, mid + 1, right);

    Merge(arr, left, mid, right);
    return;
}

/*
快排
nlogn --- n^2
最坏的去情况：有序
不稳定
*/
void QuickSort(int *arr, int left, int right)
{
    int le, ri, tmp;
    if(left >= right){
        return;
    }

    tmp = arr[left];
    le = left;
    ri = right;
    while(le != ri){
        while(arr[ri] >= tmp && le < ri){
            --ri;
        }
        while(arr[le] <= tmp && le < ri){
            ++le;
        }
        if(le < ri){
            int cu = arr[le];
            arr[le] = arr[ri];
            arr[ri] = cu;
        }
    }
    arr[left] = arr[le];
    arr[le] = tmp;

    QuickSort(arr, left, le - 1);
    QuickSort(arr, le + 1, right);

    return;
}



int main()
{
    int test[10] = {9,1,5,8,3,7,4,6,2,6};
    //BubbleSort(test, 10);
    //improveBubbleSort(test, 10);
    //SelectSort(test, 10);
    //InsertSort(test, 10);
    //ShellSort(test, 10);
    //MergeSort(test, 0, 9);
    QuickSort(test, 0, 9);


    for(int i = 0; i < 10; ++i){
        printf("%d ", test[i]);
    }
    printf("\n");
    return 0;
}