#include "pch.h"
#include "CppUnitTest.h"
#include "..\oppo\FIsh.h"
#include "..\oppo\Sea.h"
#include "..\oppo\FIsh.cpp"
#include "..\oppo\Sea.cpp"
#include "..\oppo\main.cpp"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(validateName) {
			std::vector<std::string> seas{
				"Black Sea"
				"Dead Sea"
				"White Sea"
			};


			for (int i = 0; i < seas.size(); i++) {
				std::istringstream ist(seas[i]);
				Sea sea;
				try {
					sea.validateName(seas[i]);
					Assert::Fail();
				}
				catch (std::runtime_error& e) {
					
					return;
				}
			}
		}
		TEST_METHOD(InvalidateName) {
			std::vector<std::string> seas{
				"Black S&ea"
				"Dead Se1a"
				"W$hite Sea"
			};


			for (int i = 0; i < seas.size(); i++) {
				std::istringstream ist(seas[i]);
				Sea sea;
				try {
					sea.validateName(seas[i]);
					Assert::Fail();
				}
				catch (std::runtime_error& e) {
					return;
				}
			}
		}
		TEST_METHOD(validateDeep) {
			int d = 150;
			try {
				Sea().validateDeep(d);
			}
			catch (std::out_of_range&) {
			}
		}
		TEST_METHOD(InvalidateDeep) {
			int d = -150;
			try {
				Sea().validateDeep(d);
				Assert::Fail();
			}
			catch (std::out_of_range&) {
				return;
			}
		}
		TEST_METHOD(InvalidateSalty) {
			int d = 70;
			try {
				Sea().validateSalty(d);
			}
			catch (std::out_of_range&) {
				Assert::Fail();
				return;
			}
		}
		TEST_METHOD(InvalidateSaltyMinus) {
			int d = -150;
			try {
				Sea().validateSalty(d);
				Assert::Fail();
				
			}
			catch (std::out_of_range&) {
				return;
			}
		}
		TEST_METHOD(InvalidateSaltyOutOfRange) {
			int d = 150;
			try {
				Sea().validateSalty(d);
				Assert::Fail();
			}
			catch (std::out_of_range&) {
				return;
			}
		}
		TEST_METHOD(validName) {
			std::vector<std::string> fishes{
				"Okun"
				"Som"
				"Plotva"
			};


			for (int i = 0; i < fishes.size(); i++) {
				std::istringstream ist(fishes[i]);
				Fish fish;
				try {
					fish.validName(fishes[i]);
				}
				catch (std::runtime_error& e) {
					Assert::Fail();
				}
			}
		}
		TEST_METHOD(InvalidName) {
			std::vector<std::string> fishes{
				"Oku_n",
				"So@m",
				"Pl1243otva"
			};


			for (int i = 0; i < fishes.size(); i++) {
				std::istringstream ist(fishes[i]);
				try {
					Fish::validName(fishes[i]);
					Assert::Fail();
					
				}
				catch (std::runtime_error& e) {
					return;
				}
			}
		}
	};
}
		
	
