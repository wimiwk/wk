#include <iostream>
using namespace std;
template<typename T>
class ArrayOps {
public:
    // 在数组中查找元素
    static int search(const T* arr, int size, const T& target) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == target) {
                return i;
            }
        }
        return -1;
    }
    // 使用冒泡排序将数组按升序排序
    static void sort(T* arr, int size) {
        for (int i = 0; i < size - 1; i++) {
            for (int j = 0; j < size - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    T temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    // 使用线性插值插值给定索引处的值
    static T interpolate(const T* arr, int size, double index) {
        int lowerIndex = static_cast<int>(index);
        int upperIndex = lowerIndex + 1;
        double fraction = index - lowerIndex;
        T lowerValue = arr[lowerIndex];
        T upperValue = arr[upperIndex];
        return lowerValue + fraction * (upperValue - lowerValue);
    }
};

int main(){
    int intArray[] = { 3, 1, 4, 1, 5, 9, 2, 6, 5, 3 };
    double doubleArray[] = { 3.14, 2.71, 1.41, 1.62, 0.62, 0.99 };

    ArrayOps<int>::sort(intArray, 10);
    for (int i = 0; i < 10; i++)
    {
        cout<<intArray[i]<<" ";
    }
    cout<<endl;
    int intIndex = ArrayOps<int>::search(intArray, 10, 5);
    cout<<intIndex<<endl;
    int intValue = ArrayOps<int>::interpolate(intArray, 10, 3.5);
    cout<<intValue<<endl;
    ArrayOps<double>::sort(doubleArray, 6);
    int doubleIndex = ArrayOps<double>::search(doubleArray, 6, 1.41);
    cout<<doubleIndex<<endl;
    double doubleValue = ArrayOps<double>::interpolate(doubleArray, 6, 2.5);
    cout<<doubleValue<<endl;
    return 0;
}