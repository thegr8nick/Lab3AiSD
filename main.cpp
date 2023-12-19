#include <algoritms.h>
#include <task.h>
#include <thread>
#include <string>

using namespace my;
int main()
{
    std::vector<int> arr = { 8,7,6,5,4,3,2,1 };
    cocktailSort(arr.begin(), arr.end());

    for (int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << " ";
    }
}