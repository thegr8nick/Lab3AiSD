//#include <algoritms.h>
#include <random>
#include <chrono>
#include <fstream>
using namespace my;


template <typename SortFunction>
void to_sort_helper_sorted(const std::vector<int> &range, SortFunction sortFunc, const std::string &sortName)
{
    for (int length : range)
    {
        auto start = std::chrono::steady_clock::now();
        size_t totalComparisonCount = 0;
        size_t totalCopyCount = 0;
        for (int i = 0; i < 100; ++i)
        {
            std::vector<int> arr(length);
            for (int j = 0; j < length; ++j)
            {
                arr[j] = j + 1; // Заполняем массив от 1 до length, чтобы он был полностью отсортирован
            }
            Stats stats = sortFunc(arr.begin(), arr.end());
            totalComparisonCount += stats.comparison_count;
            totalCopyCount += stats.copy_count;
        }
        double averageComparisonCount = static_cast<double>(totalComparisonCount) / 100;
        double averageCopyCount = static_cast<double>(totalCopyCount) / 100;
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::string filePath = "/home/gripulia/Desktop/lab3/src/" + sortName + ".txt";
        std::ofstream outputFile(filePath, std::ios::app);
        if (outputFile.is_open())
        {
            outputFile << "Длина массива: " << length << std::endl;
            outputFile << "Среднее число сравнений: " << averageComparisonCount << std::endl;
            outputFile << "Среднее число копирований: " << averageCopyCount << std::endl;
            outputFile << "Время выполнения: " << duration.count() << " секунд" << std::endl;
            outputFile << "----------------------------------------" << std::endl;
            outputFile.close();
        }
        else
        {
            std::cerr << "Не удалось открыть файл для записи!" << std::endl;
            return;
        }
    }
}

template <typename SortFunction>
void to_sort_helper_random(int seed, const std::vector<int> &range, SortFunction sortFunc, const std::string &sortName)
{
    for (int length : range)
    {
        auto start = std::chrono::steady_clock::now();
        size_t totalComparisonCount = 0;
        size_t totalCopyCount = 0;
        for (int i = 0; i < 100; ++i)
        {
            std::mt19937 generator(seed + i);
            std::vector<int> arr(length);
            std::uniform_int_distribution<int> distribution(1, length);
            for (int j = 0; j < length; ++j)
            {
                arr[j] = distribution(generator);
            }
            Stats stats = sortFunc(arr.begin(), arr.end()); // Вызов переданной функции сортировки
            totalComparisonCount += stats.comparison_count;
            totalCopyCount += stats.copy_count;
        }
        double averageComparisonCount = static_cast<double>(totalComparisonCount) / 100;
        double averageCopyCount = static_cast<double>(totalCopyCount) / 100;
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::string filePath = "/home/gripulia/Desktop/lab3/src/" + sortName + ".txt";
        std::ofstream outputFile(filePath, std::ios::app);
        if (outputFile.is_open())
        {
            outputFile << "Длина массива: " << length << std::endl;
            outputFile << "Среднее число сравнений: " << averageComparisonCount << std::endl;
            outputFile << "Среднее число копирований: " << averageCopyCount << std::endl;
            outputFile << "Время выполнения: " << duration.count() << " секунд" << std::endl;
            outputFile << "----------------------------------------" << std::endl;
            outputFile.close();
        }
        else
        {
            std::cerr << "Не удалось открыть файл для записи!" << std::endl;
            return;
        }
    }
}

template <typename SortFunction>
void to_sort_helper_reverse(const std::vector<int> &range, SortFunction sortFunc, const std::string &sortName)
{
    for (int length : range)
    {
        auto start = std::chrono::steady_clock::now();
        size_t totalComparisonCount = 0;
        size_t totalCopyCount = 0;
        for (int i = 0; i < 100; ++i)
        {
            std::vector<int> arr(length);
            for (int j = 0; j < length; ++j)
            {
                arr[j] = length - j; // Заполняем массив от length до 1 , чтобы он был обратно отсортирован
            }
            Stats stats = sortFunc(arr.begin(), arr.end());
            totalComparisonCount += stats.comparison_count;
            totalCopyCount += stats.copy_count;
        }
        double averageComparisonCount = static_cast<double>(totalComparisonCount) / 100;
        double averageCopyCount = static_cast<double>(totalCopyCount) / 100;
        auto end = std::chrono::steady_clock::now();
        std::chrono::duration<double> duration = end - start;
        std::string filePath = "/home/gripulia/Desktop/lab3/src/" + sortName + ".txt";
        std::ofstream outputFile(filePath, std::ios::app);
        if (outputFile.is_open())
        {
            outputFile << "Длина массива: " << length << std::endl;
            outputFile << "Среднее число сравнений: " << averageComparisonCount << std::endl;
            outputFile << "Среднее число копирований: " << averageCopyCount << std::endl;
            outputFile << "Время выполнения: " << duration.count() << " секунд" << std::endl;
            outputFile << "----------------------------------------" << std::endl;
            outputFile.close();
        }
        else
        {
            std::cerr << "Не удалось открыть файл для записи!" << std::endl;
            return;
        }
    }
}