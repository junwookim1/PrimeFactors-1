#include <string>
#include <stdexcept>
#include <set>
using namespace std;

class SimilarityChecker
{
public:
	bool checkZero(size_t bigger, size_t smaller)
	{
		return bigger == 0 || smaller == 0 || bigger >= smaller * 2;
	}

	bool checkMax(size_t bigger, size_t smaller)
	{
		return bigger == smaller;
	}

	void checkLength(const string& a, const std::string& b)
	{
		const int MAX = 60;
		size_t bigger = a.length();
		size_t smaller = b.length();

		if (bigger < smaller) swap(bigger, smaller);

		if (checkZero(bigger, smaller)) result = 0;
		else if (checkMax(bigger, smaller)) result = MAX;
		else
		{
			result = MAX - ((bigger - smaller) * MAX / smaller);
		}
	}

	void makeSetAandB(const string& a, const std::string& b, set<char>& sa, set<char>& sb)
	{
		for (const auto& ch : a)
		{
			sa.insert(ch);
		}

		for (const auto& ch : b)
		{
			sb.insert(ch);
		}
	}

	int getSameCnt(set<char> sa, set<char> sb)
	{
		int sameCnt = 0;
		for (const auto& ch_b : sa)
		{
			auto it = sb.find(ch_b);
			if (it != sb.end()) sameCnt++;
		}
		return sameCnt;
	}

	bool isSmallLetter(const string& a, const string& b)
	{
		for (auto const& ch : a)
		{
			if (ch >= 'A' && ch <= 'Z') continue;
			return true;
		}

		for (auto const& ch : b)
		{
			if (ch >= 'A' && ch <= 'Z') continue;
			return true;
		}
		return false;
	}

	void assertSmallLetter(const string& a, const std::string& b)
	{
		if (isSmallLetter(a, b))
		{
			throw std::invalid_argument("�ҹ��� ���Ե�");
		}
	}

	void checkAlpha(const string& a, const std::string& b)
	{
		const int MAX = 40;

		assertSmallLetter(a, b);

		set<char> sa;
		set<char> sb;
		makeSetAandB(a, b, sa, sb);
		int sameCnt = getSameCnt(sa, sb);

		result = sameCnt * MAX / (sa.size() + sb.size() - sameCnt);
	}

	int getResult()
	{
		return result;
	}

private:
	int result = 0;
};
