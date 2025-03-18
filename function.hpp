#pragma once
#include <string>

enum typeTest {M_INT, M_NAME, M_ADDR, M_TEL, M_UR, M_IND};

enum mainMenu {ADD_MENU = 1, MODIF, REMOV, PRINT};
enum addMenu {ADD_CLIENT = 1, ADD_COMPANI, ADD_COPY_CL, ADD_COPY_COM, ADD_UR_CLIENT, ADD_IND_CLIENT};
enum modMenu {MOD_CLIENT = 1, MOD_COMP};
enum removMenu {REMOV_CL = 1, REMOV_CL_ALL, REMOV_CM, REMOV_CM_ALL};


std::string test(typeTest magicNumber, std::string);
bool isValidInput4_5(const std::string& input);
bool isValidInput(const std::string& input);
bool isValidAddr(const std::string& input);
bool isTelNum(std::string s);

void pause();

void MainMenu();

void AddMenu();
void RemovMenu();
void PrintMenu();
void ModMenu();
void ModMenu_client();
void ModMenu_compani();

