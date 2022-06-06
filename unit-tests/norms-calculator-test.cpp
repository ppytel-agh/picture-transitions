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
			//series may not have 0 elements
			NormsCalculator normCalc1(0);
			Assert::AreEqual(-1.0f, normCalc1.getNorm(0));
			Assert::AreEqual(-1.0f, normCalc1.getNorm(1000));
			//one element series makes amiguity in mapping normalized value to first element (i=0)
			NormsCalculator normCalc2(1);
			Assert::AreEqual(-1.0f, normCalc2.getNorm(0));
			//correct minimum number of elements, norm may not be lower than 0
			NormsCalculator normCalc3(2);
			Assert::AreNotEqual(-1.0f, normCalc3.getNorm(1));
		}

		TEST_METHOD(SimpleItemToNorm)
		{
			NormsCalculator normCalc(3);
			Assert::AreEqual(0.0f, normCalc.getNorm(0));//first element in series
			Assert::AreEqual(0.5f, normCalc.getNorm(1));//element 2nd of 3 is exactly in the middle of series
			Assert::AreEqual(1.0f, normCalc.getNorm(2));//last element in series
		}

		TEST_METHOD(SimpleItemToNormEven)
		{
			NormsCalculator normCalc(4);
			Assert::AreEqual(0.0f, normCalc.getNorm(0));//first element in series
			Assert::AreEqual(0.333f, normCalc.getNorm(1), 0.001f);//second element is at 1/3
			Assert::AreEqual(0.666f, normCalc.getNorm(2), 0.001f);//third element at 2/3
			Assert::AreEqual(1.0f, normCalc.getNorm(3));//last element in series
		}

		TEST_METHOD(ItemToNorm)
		{
			NormsCalculator normCalc(9);
			Assert::AreEqual(0.0f, normCalc.getNorm(0));//first element
			Assert::AreEqual(0.125f, normCalc.getNorm(1));
			Assert::AreEqual(0.5f, normCalc.getNorm(4));
			Assert::AreEqual(0.75f, normCalc.getNorm(6));//
			Assert::AreEqual(0.875f, normCalc.getNorm(7));//element 8th of 9
			Assert::AreEqual(1.0f, normCalc.getNorm(8));//last element
			Assert::AreEqual(1.0f, normCalc.getNorm(-1));//unsigned int overflow
		}

		TEST_METHOD(ItemToNormNumeric)
		{
			NormsCalculator normCalc(11);
			Assert::AreEqual(0.2f, normCalc.getNorm(2));
			Assert::AreEqual(0.9f, normCalc.getNorm(9), 0.01f);
			Assert::AreEqual(1.0f, normCalc.getNorm(10));
			Assert::AreEqual(1.0f, normCalc.getNorm(-1));//unsigned int overflow

			NormsCalculator normCalc2(1001);
			Assert::AreEqual(0.999f, normCalc2.getNorm(999), 0.001f);//numeric error
		}
	};
}
