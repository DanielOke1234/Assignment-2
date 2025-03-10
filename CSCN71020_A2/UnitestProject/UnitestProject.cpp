#include "pch.h"
#include "CppUnitTest.h"

extern  "C" {
#include "../BCSRec/main.h"
}

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitestProject
{
	TEST_CLASS(UnitestProject)
	{
	public:
		
		TEST_METHOD(TestgetPerimeter)
		{
			int length = 8, width = 4;
			int expected = 2 * (length * width);

			int actual = getPerimeter(&length, &width);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestgetArea)
		{
			int length = 8, width = 4;
			int expected = length * width;

			int actual = getArea(&length, &width);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(TestsetLength_NORMALCASE)
		{
			int length = 4, input = 20;
			setLength(input, &length);
		
			Assert::AreEqual(20, length);
		}

		TEST_METHOD(TestsetLength_ABNORMALCASE_BELOWZERO)
		{
			int length = 5, input = -5;
			setLength(input, &length);

			Assert::AreEqual(5, length);
		}

		TEST_METHOD(TestsetLength_NORMALCASE_ABOVE99)
		{
			int length = 6, input = 190;
			setLength(input, &length);

			Assert::AreEqual(6, length);
		}


		TEST_METHOD(TestsetWidth_NORMALCASE)
		{
			int Width = 4, input = 20;
			setWidth(input, &Width);

			Assert::AreEqual(20, Width);
		}

		TEST_METHOD(TestsetWidth_ABNORMALCASE_ZERO)
		{
			int Width = 4, input = 0;
			setWidth(input, &Width);

			Assert::AreEqual(4, Width);
		}

		TEST_METHOD(TestsetWidth_SAMEVALUES)
		{
			int Width = 20, input = 20;
			setWidth(input, &Width);

			Assert::AreEqual(20, Width);
		}
	};
}
