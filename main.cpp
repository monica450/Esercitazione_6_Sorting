#include <iostream>
#include <chrono>
#include <unistd.h>
#include <vector>
#include <numeric>
#include <algorithm>
#include <random>
#include "SortingAlgorithm.hpp"

using namespace std;

double averageTimeBS(vector<double>& v, const unsigned int & num)
{
    vector<double> time;
    double m_time = 0;
    time.reserve(num);


    for(unsigned int i = 0; i < num; i++)
    {
        std::chrono::steady_clock::time_point t_begin = std::chrono::steady_clock::now();


        SortLibrary::BubbleSort(v);


        std::chrono::steady_clock::time_point t_end = std::chrono::steady_clock::now();

        double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t_end - t_begin).count();
        time.push_back(duration);

    }

    for(unsigned int i = 0; i < time.size(); i++)
        m_time += time[i];

    m_time = m_time / time.size();

    return m_time;

}

double averageTimeMS(vector<double>& v, const unsigned int & num)
{
    vector<double> time;
    double m_time = 0;
    time.reserve(num);

    for(unsigned int i = 0; i < num; i++)
    {
        std::chrono::steady_clock::time_point t_begin = std::chrono::steady_clock::now();


        SortLibrary::MergeSort(v);


        std::chrono::steady_clock::time_point t_end = std::chrono::steady_clock::now();

        double duration = std::chrono::duration_cast<std::chrono::nanoseconds>(t_end - t_begin).count();
        time.push_back(duration);

    }

    for(unsigned int i = 0; i < time.size(); i++)
        m_time += time[i];

    m_time = m_time / time.size();

    return m_time;
}


int main(int argc, char ** argv)
{
    unsigned int num = 10;
    unsigned int n = stoi(argv[1]);
    vector<double> v(n);

    // ****************************************************************************************************************
    // CASE 1: sorted vectors

    cout << "CASE 1: sorted vectors" << endl;

    iota(v.begin(),v.end(), 0);


    /*
    for(unsigned int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
    cout << n << endl;*/


    cout << "Average time using BubbleSort in ns: " << averageTimeBS(v, num) << endl;

    cout << "Average time using MergeSort in ns: " << averageTimeMS(v, num) << endl;

    cout << endl;

    // ********************************************************************************************
    // CASE 2: random vectors

    cout << "CASE 2: random vectors" << endl;


    for(unsigned int  i = 0; i < n; i++)
    {
        v[i] = rand() % 1000;
    }

    cout << "Average time using BubbleSort in ns: " << averageTimeBS(v, num) << endl;

    cout << "Average time using MergeSort in ns: " << averageTimeMS(v, num) << endl;

    cout << endl;

    // ********************************************************************************************
    // CASE 3: small vectors

    cout << "CASE 3: small vectors" << endl;

    unsigned int small_n = 5;
    vector<double> w(n);

    for(unsigned int  i = 0; i < small_n; i++)
    {
        w[i] = rand() % 10;
    }

    cout << "Average time using BubbleSort in ns: " << averageTimeBS(w, small_n) << endl;

    cout << "Average time using MergeSort in ns: " << averageTimeMS(w, small_n) << endl;

    cout << endl;

    // ********************************************************************************************
    // CASE 4: vectors with duplicate elements

    cout << "CASE 4: vectors with duplicate elements" << endl;

    uniform_real_distribution<double> dis(0.0, 1.0);
    random_device rd;
    mt19937 gen(rd());
    double a_1 = dis(gen);
    double a_2 = dis(gen);;

    cout << a_1 << " " << a_2 << endl;

    for(unsigned int  i = 0; i < n; i++)
    {
        if(i < n/2)
            v[i] = a_1;
        else
            v[i] = a_2;
    }

    cout << "Average time using BubbleSort in ns: " << averageTimeBS(v, num) << endl;

    cout << "Average time using MergeSort in ns: " << averageTimeMS(v, num) << endl;

    cout << endl;




    return 0;
}
