#include "pch.h"
#include "CppUnitTest.h"
#include "..\lab17\matrix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestMatrix {
	TEST_CLASS(UnitTestMatrix) {
public:
	TEST_METHOD(TestConstructor) {
		matrix<int> m_1; matrix<double> m_2; matrix<char> m_3; matrix<point> m_4;
		matrix<int> m_5(4, 4); matrix<double> m_6(4, 4); matrix<char> m_7(4, 4); matrix<point> m_8(4, 4);
	}
	TEST_METHOD(TestCopyConstructor) {
		matrix<int> m_1(2, 2);
		m_1.set(9);

		matrix<int> m_2(m_1);

		Assert::AreEqual(m_1.get(0, 0), m_2.get(0, 0));
		Assert::AreEqual(m_1.get(0, 1), m_2.get(0, 1));
		Assert::AreEqual(m_1.get(1, 0), m_2.get(1, 0));
		Assert::AreEqual(m_1.get(1, 1), m_2.get(1, 1));
	}
	TEST_METHOD(TestSetOne) {
		matrix<int> m_1(2, 2);

		Assert::AreEqual(m_1.set(size_t(0), size_t(0), 69), 69);
	}
	TEST_METHOD(TestGet) {
		matrix<int> m_1(2, 2);
		m_1.set(size_t(0), size_t(0), 69);

		Assert::AreEqual(m_1.get(0, 0), 69);
	}
	TEST_METHOD(TestSetAll) {
		matrix<int> m_1(2, 2);
		m_1.set(69);

		Assert::AreEqual(m_1.get(0, 0), 69);
		Assert::AreEqual(m_1.get(0, 1), 69);
		Assert::AreEqual(m_1.get(1, 0), 69);
		Assert::AreEqual(m_1.get(1, 1), 69);
	}
	TEST_METHOD(TestRowsAndColumns) {
		matrix<int> m_1(3, 5);

		Assert::AreEqual(m_1.rows(), size_t(5));
		Assert::AreEqual(m_1.columns(), size_t(3));
	}
	TEST_METHOD(TestAssignOperator) {
		matrix<int> m_1(2, 2);
		m_1.set(9);

		matrix<int> m_2;
		m_2 = m_1;

		Assert::AreEqual(m_1.get(0, 0), m_2.get(0, 0));
		Assert::AreEqual(m_1.get(0, 1), m_2.get(0, 1));
		Assert::AreEqual(m_1.get(1, 0), m_2.get(1, 0));
		Assert::AreEqual(m_1.get(1, 1), m_2.get(1, 1));
	}
	TEST_METHOD(TestOperatorPlus) {
		matrix<int> m_1(2, 2), m_2(2, 2);
		m_1.set(34); m_2.set(35);

		Assert::AreEqual((m_1 + m_2).get(0, 0), 69);
	}
	};
}
