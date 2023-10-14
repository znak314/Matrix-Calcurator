#pragma once
#include"ClassLib.h"
#include<ctime>
#include<string>
#include <sstream>
#include<algorithm>
#include<iostream>
#include<iomanip>
#include<fstream>
#include <tuple>

using namespace System;


double GenerateDouble();
bool FileFormatValidator(std::string s);
bool is_number_validator(std::string s);
bool fileExists(const std::string& filename);
void processFile(std::ofstream& file, Matrix& A, int act, int it);

std::string& Convert_String_to_string(String^ s, std::string& ss); 
String^ Convert_string_to_String( std::string& ss, String^ s );    
void incrementIter();
void incrementActions();