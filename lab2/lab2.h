#pragma once
#include <time.h>
#include <stdlib.h>
#include <cmath>
#include <string>
#include <fstream>
#include <iostream>

using namespace std;

void create_array(float* array, int n);		//���������� ������� ���������� �� -10 �� 10

void print_array(float* array, int n);		//����� ������� �� �����

float sum_array(float* array, int n);		//����� ���� ��������� �������

int imin_array(float* array, int n);		//����� ������� ������������ �� ������ ��������

int imax_array(float* array, int n);		//����� ������� ������������� �� ������ ��������

float mul_array(float* array, int n);		//���������

void array_out_file(float* array, int n);	//����� � ����