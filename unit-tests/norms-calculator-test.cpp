#include "pch.h"
#include "CppUnitTest.h"
#include "../animation-generator-lib/norm-calc.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace unittests
{
	TEST_CLASS(NormsCalculatorTests)
	{
	public:

		TEST_METHOD(InvalidConstruction)
		{
			NormsCalculator normCalc1(0);
			Assert::AreEqual(-1.0f, normCalc1.getNorm(0));
			Assert::AreEqual(-1.0f, normCalc1.getNorm(1000));
			NormsCalculator normCalc2(1);
			Assert::AreNotEqual(-1.0f, normCalc2.getNorm(0));
			NormsCalculator normCalc3(2);
			Assert::AreNotEqual(-1.0f, normCalc3.getNorm(1));
		}

		TEST_METHOD(SimpleItemToNorm)
		{
			NormsCalculator normCalc(3);
			Assert::AreEqual(0.0f, normCalc.getNorm(0));
			Assert::AreEqual(0.5f, normCalc.getNorm(1));
			Assert::AreEqual(1.0f, normCalc.getNorm(2));
		}

		TEST_METHOD(ItemToNorm)
		{
			NormsCalculator normCalc(9);
			Assert::AreEqual(0.0f, normCalc.getNorm(0));
			Assert::AreEqual(0.125f, normCalc.getNorm(1));
			Assert::AreEqual(0.5f, normCalc.getNorm(4));
			Assert::AreEqual(0.75f, normCalc.getNorm(6));//
			Assert::AreEqual(0.875f, normCalc.getNorm(7));
			Assert::AreEqual(1.0f, normCalc.getNorm(-1));//unsigned int overflow
		}

		TEST_METHOD(ItemToNormNumeric)
		{
			NormsCalculator normCalc(11);
			Assert::AreEqual(0.2f, normCalc.getNorm(2));
			Assert::AreEqual(0.9f, normCalc.getNorm(9));
			Assert::AreEqual(1.0f, normCalc.getNorm(10));
			Assert::AreEqual(1.0f, normCalc.getNorm(-1));//unsigned int overflow

			//NormsCalculator normCalc2(1001);
			//Assert::AreSame(0.999f, normCalc2.getNorm(999));//numeric error
		}
	};
}
