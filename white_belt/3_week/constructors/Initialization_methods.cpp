//
// Created by Mahmud Jego on 1/7/21.
//

class Incognizable {
public:
	Incognizable()
	{
		_nNum1 = 0;
		_nNum2 = 0;
	}

	Incognizable(const int& newNum)
	{
		_nNum1 = newNum;
		_nNum2 = newNum;
	}

	Incognizable(const int& newNum1, const int& newNum2)
	{
		_nNum1 = newNum1;
		_nNum2 = newNum2;
	}

private:
	int _nNum1;
	int _nNum2;
};

int main() {
	Incognizable a;
	Incognizable b = {};
	Incognizable c = {0};
	Incognizable d = {0, 1};
	return 0;
}