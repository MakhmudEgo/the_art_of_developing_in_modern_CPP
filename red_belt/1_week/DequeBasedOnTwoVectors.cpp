//
// Created by Makhmud Ego on 05.05.2021.
//

#include <iostream>
#include <vector>

#define RETURN_T \
	if (index >= dFront.size()) { \
		return dBack[index - dFront.size()]; \
	} else { \
		return dFront[dFront.size() - index - 1]; \
	}

#define FRONT_OR_BACK(x, y) \
	if (x.empty()) { \
		return y.front(); \
	} \
	return x.back(); \


template<class T>
class Deque {
public:
	bool Empty() const {
		return dFront.empty() && dBack.empty();
	}
	size_t Size() const {
		return dFront.size() + dBack.size();
	}

	T& operator[](size_t index) {
		RETURN_T;
	}
	const T& operator[](size_t index) const {
		RETURN_T;
	}

	T& At(size_t index) {
		if (index >= this->Size()) {
			throw std::out_of_range("incorrect index");
		}
		RETURN_T;
	}
	const T& At(size_t index) const {
		if (index >= this->Size()) {
			throw std::out_of_range("incorrect index");
		}
		RETURN_T;
	}
	T& Front() {
		FRONT_OR_BACK(dFront, dBack)
	}

	const T& Front() const {
		FRONT_OR_BACK(dFront, dBack)
	}

	T& Back() {
		FRONT_OR_BACK(dBack, dFront)
	}

	const T& Back() const {
		FRONT_OR_BACK(dBack, dFront)
	}

	void PushFront(const T& t) {
		dFront.push_back(t);
	}

	void PushBack(const T& t) {
		dBack.push_back(t);
	}
private:
	std::vector<T> dFront, dBack;
};


int main() {
	Deque<int> deque;

	deque.PushBack(-1);
	deque.PushBack(1);
	deque.PushBack(43);
	deque.PushFront(88);
	deque.PushFront(100);

	for (size_t i = 0; i < deque.Size(); ++i) {
		std::cout << deque[i] << ' ';
	}
	std::cout << std::endl;
	std::cout << "front " << deque.Front() << std::endl;
	std::cout << "back " << deque.Back() << std::endl;

	try {
		deque.At(5);
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}