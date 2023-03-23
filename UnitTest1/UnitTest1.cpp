#include "pch.h"
#include "CppUnitTest.h"
#include "../PR12.2.IT/PR12.2.IT.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Elem* first = NULL, * last = NULL;
			for (int i = 0; i < 5; i++) {
				Elem* tmp = new Elem;
				tmp->info = i;
				tmp->link = NULL;
				if (last != NULL)
					last->link = tmp;
				last = tmp;
				if (first == NULL)
					first = tmp;
			}
			int t = Count(first);
			Assert::AreEqual(t, 2);
		}
	};
}
