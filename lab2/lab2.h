#pragma once
#include <time.h>
#include <stdlib.h>
#include <cmath>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

void create_array(float* array, int n);		//наполнение массива значениями от -10 до 10

void print_array(float* array, int n);		//вывод массива на экран

float sum_array(float* array, int n);		//сумма всех элементов массива

int imin_array(float* array, int n);		//поиск индекса минимального по модулю элемента

int imax_array(float* array, int n);		//поиск индекса максимального по модулю элемента

float mul_array(float* array, int n);		//умножение

void array_out_file(float* array, int n);	//вывод в файл