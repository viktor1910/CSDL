#include <iostream>
#define MAX 50
using namespace std;

void nhap1c(int a[], int &n)
{
    cout << "Nhap so phan tu n : ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
}

void xuat1c(int a[], int &n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

int LinearSearch(int a[], int &n, int x)
{
    int copyArray[MAX];

    copy(a, a + n, copyArray);

    int i = 0;
    copyArray[n] = x;
    while (copyArray[i] != x)
    {
        i++;
        if (i == n)
        {
            cout << "Khong tim thay X";
            return 0;
        }
        else
        {
            cout << "Tim thay X o vi tri " << i << endl;
            return 1;
        }
    }
}

int BinarySearch(int a[], int &n, int x)
{
    int copyArray[MAX];

    copy(a, a + n, copyArray);

    int left = 0;
    int right = n - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (copyArray[mid] == x)
        {
            cout << "Tim thay X : = " << a[mid];
        }
        else
        {
            if (copyArray[mid] < x)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
    }
    return 0;
}

struct ArrayResult
{
    int soPhepSS;
    int soPhepGan;
};

// Hàm đếm số phép so sánh và số phép gán của thuật toán đổi chỗ trực tiếp
//  InterchangeSort

ArrayResult interchangeSort(int a[], int n)
{
    int copyArray[MAX];

    copy(a, a + n, copyArray);

    int soPhepSS = 0;
    int soPhepGan = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            soPhepSS++;
            if (copyArray[i] > copyArray[j])
            {
                swap(copyArray[i], copyArray[j]);
                soPhepGan += 3;
            }
        }
    }
    return {
        soPhepSS,
        soPhepGan};
}

// Hàm đếm số phép so sánh và số phép gán của thuật toán chọn trực tiếp
//  selectionSort
ArrayResult selectionSort(int a[], int n)
{

    int copyArray[MAX];

    copy(a, a + n, copyArray);

    int soPhepSS = 0;
    int soPhepGan = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            soPhepSS++;
            if (copyArray[j] < copyArray[minIndex])
            {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            swap(copyArray[i], copyArray[minIndex]);
            soPhepGan += 3;
        }
    }
    return {
        soPhepSS,
        soPhepGan};
}

// Bubble Sort / Hàm sắp xếp Nổi Bọt
ArrayResult bubbleSort(int a[], int n)
{
    int copyArray[MAX];

    copy(a, a + n, copyArray);

    int soPhepSS = 0;
    int soPhepGan = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            soPhepSS++;
            if (copyArray[j] > copyArray[j + 1])
            {
                swap(copyArray[j], copyArray[j + 1]);
                soPhepGan += 3;
            }
        }
    }
    return {
        soPhepSS,
        soPhepGan};
}

// Insertion Sort / Hàm sắp xếp chèn trực tiếp
ArrayResult insertionSort(int a[], int n)
{
    int copyArray[MAX];

    copy(a, a + n, copyArray);

    int soPhepSS = 0;
    int soPhepGan = 0;
    for (int i = 1; i < n; i++)
    {
        int key = copyArray[i];
        int j = i - 1;
        while (j >= 0 && copyArray[j] > key)
        {
            soPhepSS++;
            copyArray[j + 1] = copyArray[j];
            j--;
            soPhepGan++;
        }
        copyArray[j + 1] = key;
        soPhepGan++;
    }
    return {
        soPhepSS,
        soPhepGan};
}

// Binary Insertion Sort / Hàm sắp xếp chèn nhị phân
ArrayResult binaryInsertionSort(int a[], int n)
{

    int copyArray[MAX];

    copy(a, a + n, copyArray);

    int soPhepSS = 0;
    int soPhepGan = 0;
    for (int i = 1; i < n; i++)
    {
        int key = copyArray[i];
        int left = 0, right = i - 1;
        while (left <= right)
        {
            soPhepSS++;
            int mid = left + (right - left) / 2;
            if (copyArray[mid] < key)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        for (int j = i; j > left; j--)
        {
            copyArray[j] = copyArray[j - 1];
            soPhepGan++;
        }
        copyArray[left] = key;
        soPhepGan++;
    }
    return {
        soPhepSS,
        soPhepGan};
}

int main()
{
    int originalArray[MAX];
    int originalArrayLength;

    char thuatToanNhoNhat;

    ArrayResult tempArrayResult = {
        0,
        0};

    nhap1c(originalArray, originalArrayLength);
    cout << "Mang da tao ban dau : ";
    xuat1c(originalArray, originalArrayLength);

    int copyArray[MAX];

    copy(originalArray, originalArray + originalArrayLength, copyArray);

    ArrayResult interchangeSortResult = interchangeSort(copyArray, originalArrayLength);

    cout << "Mang sau khi sap xep : ";
    for (int i = 0; i < originalArrayLength; i++)
    {
        cout << copyArray[i] << " ";
    }

    cout << "\n"
         << endl;
    cout << "Thuat toan InterchangeSort (Doi cho truc tiep)" << endl;
    cout << "\tSo phep so sanh: " << interchangeSortResult.soPhepSS << endl;
    cout << "\tSo phep gan: " << interchangeSortResult.soPhepGan << endl;

    tempArrayResult.soPhepGan = interchangeSortResult.soPhepGan;
    tempArrayResult.soPhepSS = interchangeSortResult.soPhepGan;

    ArrayResult selectionSortResult = selectionSort(originalArray, originalArrayLength);
    cout << "Thuat toan selectionSort (Chon truc tiep)" << endl;
    cout << "\tSo phep so sanh : " << selectionSortResult.soPhepSS << endl;
    cout << "\tSo phep gan : " << selectionSortResult.soPhepGan << endl;

    if (selectionSortResult.soPhepSS <= tempArrayResult.soPhepSS && selectionSortResult.soPhepGan <= tempArrayResult.soPhepGan)
    {
        tempArrayResult.soPhepGan = selectionSortResult.soPhepGan;
        tempArrayResult.soPhepSS = selectionSortResult.soPhepGan;
    };

    ArrayResult bubbleSortResult = bubbleSort(originalArray, originalArrayLength);

    cout << "Thuat toan bubbleSort (Noi bot)" << endl;
    cout << "\tSo phep so sanh : " << bubbleSortResult.soPhepSS << endl;
    cout << "\tSo phep gan : " << bubbleSortResult.soPhepGan << endl;

    if (bubbleSortResult.soPhepSS <= tempArrayResult.soPhepSS && bubbleSortResult.soPhepGan <= tempArrayResult.soPhepGan)
    {
        tempArrayResult.soPhepGan = bubbleSortResult.soPhepGan;
        tempArrayResult.soPhepSS = bubbleSortResult.soPhepGan;
    };

    ArrayResult insertionSortResult = insertionSort(originalArray, originalArrayLength);
    cout << "Thuat toan insertionSort (Chen truc tiep)" << endl;
    cout << "\tSo phep so sanh : " << insertionSortResult.soPhepSS << endl;
    cout << "\tSo phep gan : " << insertionSortResult.soPhepGan << endl;

    if (insertionSortResult.soPhepSS <= tempArrayResult.soPhepSS && insertionSortResult.soPhepGan <= tempArrayResult.soPhepGan)
    {
        tempArrayResult.soPhepGan = insertionSortResult.soPhepGan;
        tempArrayResult.soPhepSS = insertionSortResult.soPhepGan;
    };

    ArrayResult binaryInsertionSortResult = binaryInsertionSort(originalArray, originalArrayLength);

    if (binaryInsertionSortResult.soPhepSS <= tempArrayResult.soPhepSS && binaryInsertionSortResult.soPhepGan <= tempArrayResult.soPhepGan)
    {
        tempArrayResult.soPhepGan = binaryInsertionSortResult.soPhepGan;
        tempArrayResult.soPhepSS = binaryInsertionSortResult.soPhepGan;
    };

    cout << "Thuat toan binaryInsertionSort (Chen nhi phan)" << endl;
    cout << "\tSo phep so sanh : " << binaryInsertionSortResult.soPhepSS << endl;
    cout << "\tSo phep gan : " << binaryInsertionSortResult.soPhepGan << endl;

    cout << "\n\n\nSo phep so sanh nho nhat : " << tempArrayResult.soPhepSS << endl;
    cout << "So phep gan nho nhat : " << tempArrayResult.soPhepGan << endl;

    return 0;
}
