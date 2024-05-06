#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>


class Address
{
private:
    std::string City, Street;
    int HouseNumber, FlatNumber;

public:
    Address() :City("UnknownCity"), Street("UnknownStreet"), HouseNumber(0), FlatNumber(0)
    {
    }

    void setAddress(std::string InputCity, std::string InputStreet, int InputHouseNumber, int InputFlatNumber)
    {
        this->City = InputCity;
        this->Street = InputStreet;
        this->HouseNumber = InputHouseNumber;
        this->FlatNumber = InputFlatNumber;
    }

    std::string getCity()
    {
        return City;
    }

    std::string getStreet()
    {
        return Street;
    }

    int getHouseNumber()
    {
        return HouseNumber;
    }

    int getFlatNumber()
    {
        return FlatNumber;
    }

    std::string DataComporator()
    {
        return getCity() + ", " + getStreet() + ", " + std::to_string(getHouseNumber()) + ", " + std::to_string(getFlatNumber());
    }
};


Address *CreateCatalog(int& c_size, std::string c_path)
{
    int InnerIndex, InputHouseNumber, InputFlatNumber;
    std::string TotalString, InputCity, InputStreet;
    std::ifstream fin(c_path);
    fin >> InnerIndex;
    c_size = InnerIndex;

    //создание массива из классов
    Address* C_AddCatalog = new Address[InnerIndex];;

    //заполнение массива из файла
    for (int i = 0; i < InnerIndex; i++)
    {
        fin >> InputCity;
        fin >> InputStreet;
        fin >> InputHouseNumber;
        fin >> InputFlatNumber;
        C_AddCatalog[i].setAddress(InputCity, InputStreet, InputHouseNumber, InputFlatNumber);
    }
    fin.close();
    return C_AddCatalog;
 }

void Output_Func(std::string path_output, int &CatalogIndex, Address* Out_AddCatalog)
{
    std::ofstream fout(path_output);
    fout << CatalogIndex << std::endl;
    for (int i = 0; i < CatalogIndex; i++)
    {
           fout << Out_AddCatalog[i].DataComporator() << std::endl;
    }
    fout.close();
}

int main()
{
    setlocale(LC_ALL, "ru"); // задать русский текст
    std::system("chcp 1251"); // настроить кодировку консоли
    std::system("cls"); // очистить экран
    int CatalogIndex = 0;
    std::string path_in = "in.txt", path_out = "out.txt";
    
    Address* AddCatalog = CreateCatalog(CatalogIndex, path_in);
    
    Output_Func(path_out, CatalogIndex, AddCatalog);
    
    // Очистить память после использования программы
    delete[] AddCatalog;
    return 1;
}
