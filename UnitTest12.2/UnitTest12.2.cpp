#include "pch.h"
#include "CppUnitTest.h"
#include "../Project12.2/project12.2.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest122
{
	TEST_CLASS(UnitTest122)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			bool result;
			int arr[10] = { 1,2,3,4,5,5,7,8,9,10 };
			Elem* first = new Elem;
			first->info = arr[0];
			first->link = NULL;
			Elem* last = first;
			for (int i = 1; i < 10;i++)
			{
				Elem* elem = new Elem;
				elem->info = arr[i];
				elem->link = NULL;
				last->link = elem;
				last = elem;
			}
			result = check_info(first);
			Assert::AreEqual(result, true);
		}
	};
}
