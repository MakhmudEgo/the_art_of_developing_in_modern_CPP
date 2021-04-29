//
// Created by Mahmud Jego on 1/4/21.
//

#include <iostream>
#include <memory>
void* operator new (size_t n) {
	std::cout << "bye  " << std::endl;
	return malloc(n);
}
void operator delete (void *ptr) noexcept {//
	std::cout << "hello from dea" << std::endl;//
	free(ptr);
}

void hellow(...) {
	std::cout << "hello" << std::endl;
}

#include <array>
int main() {
	/*void * h = new std::string("hello");
	delete reinterpret_cast<std::string*>(h);
	std::shared_ptr<std::string> hello(new std::string("hello"));
	std::shared_ptr<std::string> kek = std::make_shared<std::string>("hello");
	kek->insert(kek->end(), 'k');
//	std::array<char> fdd;
	char hh[]= {'q','w'};
	kek->insert(kek->begin(),*hh);

//	kek->insert(kek->end(), 5, "hell");
	std::cout << "===" << kek->back() << std::endl;
	std::string gg = "hellllllł";
	kek->insert(kek->end(), gg.begin(), gg.end());
	kek->erase(kek->begin(), kek->begin()+5+2);
	kek->erase(kek->begin()+2, kek->end());
	std::cout << "===" << *kek << std::endl;
	hellow("hello");
	std::cout << "hello, world!:)" << std::endl;*/
	std::string hello(*std::shared_ptr<std::string>(new std::string("hello")));
	return (0);
}
