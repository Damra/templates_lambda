#include <iostream>
#include <vector>
#include <algorithm> // std::sort, std::for_each
#include <functional> // std::function

using namespace std;

// Veri kümesi üzerinde işlem yapan bir sınıf
template <typename T>
class DataProcessor {
private:
    vector<T> data;

public:
    // Veri ekleme
    void addData(const T& value) {
        data.push_back(value);
    }

    // Veriyi sıralama
    void sortData() {
        sort(data.begin(), data.end());
    }

    // Veriyi işleme (lambda ile özelleştirilebilir)
    void processData(const function<void(const T&)>& processor) {
        for_each(data.begin(), data.end(), processor);
    }

    // Veriyi filtreleme (lambda ile özelleştirilebilir)
    vector<T> filterData(const function<bool(const T&)>& filter) {
        vector<T> result;
        copy_if(data.begin(), data.end(), back_inserter(result), filter);
        return result;
    }

    // Veriyi ekrana yazdırma
    void printData() const {
        cout << "Data: ";
        for (const auto& item : data) {
            cout << item << " ";
        }
        cout << endl;
    }
};

int main() {
    // int veri tipi için DataProcessor örneği
    DataProcessor<int> intProcessor;

    // Veri ekleme
    intProcessor.addData(42);
    intProcessor.addData(15);
    intProcessor.addData(87);
    intProcessor.addData(23);
    intProcessor.addData(56);

    // Veriyi sıralama
    intProcessor.sortData();

    // Veriyi ekrana yazdırma
    intProcessor.printData();

    // Veriyi işleme (lambda ile)
    cout << "Processing data (squared values): ";
    intProcessor.processData([](const int& value) {
        cout << value * value << " ";
    });
    cout << endl;

    // Veriyi filtreleme (lambda ile)
    auto filteredData = intProcessor.filterData([](const int& value) {
        return value > 30;
    });

    // Filtrelenmiş veriyi ekrana yazdırma
    cout << "Filtered data (values > 30): ";
    for (const auto& item : filteredData) {
        cout << item << " ";
    }
    cout << endl;

    // string veri tipi için DataProcessor örneği
    DataProcessor<string> stringProcessor;

    // Veri ekleme
    stringProcessor.addData("apple");
    stringProcessor.addData("banana");
    stringProcessor.addData("cherry");
    stringProcessor.addData("date");

    // Veriyi sıralama
    stringProcessor.sortData();

    // Veriyi ekrana yazdırma
    stringProcessor.printData();

    // Veriyi işleme (lambda ile)
    cout << "Processing data (uppercase): ";
    stringProcessor.processData([](const string& value) {
        for (char ch : value) {
            cout << static_cast<char>(toupper(ch));
        }
        cout << " ";
    });
    cout << endl;

    return 0;
}
