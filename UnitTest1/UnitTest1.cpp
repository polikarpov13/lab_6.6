#include "pch.h"
#include "CppUnitTest.h"
#include "../../../../../політех/ооп/6/lab_6.6/lab_6.6/lab_6.6.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Queue q;

			q.push(4);
			q.push(3);
			q.push(9);

			Assert::AreEqual(q.pop(), 4);
			Assert::AreEqual(q.pop(), 3);
			Assert::AreEqual(q.pop(), 9);
		}
	};
}
