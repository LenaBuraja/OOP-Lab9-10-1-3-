#include <iostream>
#include<stack>
#include <initializer_list>

class StackOfBooks {
	std::stack<char*> stackOfBooks;
public:
	StackOfBooks() {}
	StackOfBooks(std::initializer_list<char*> l) : stackOfBooks(l) {}

	char* Pop() {
		char* result = stackOfBooks.top();
		stackOfBooks.pop();		
		return result;
	}

	void Push(char* st) {
		stackOfBooks.push(st);
	}

	char* Top() {
		return stackOfBooks.top();
	}

	bool Empty() {
		return stackOfBooks.empty();
	}

	friend std::ostream &operator<< (std::ostream& out, StackOfBooks& stackOfBooks) {
		std::stack<char*> st = stackOfBooks.stackOfBooks;
		while (!st.empty()) {
			out << st.top() << "\n";
			st.pop();
		}
		return out;
	}

	void replacement(std::initializer_list<char*> l) {
		for (char* newBooks : l) {
			Pop();
		}
		for (char* newBooks : l) {
			Push(newBooks);
		}
	}

	void complete(StackOfBooks st1) {
		std::stack<char*> st;
		while (!st1.Empty()) {
			Push(st1.Top());
			st.push(st1.Top());
			st1.Pop();
		}
		while (!st.empty()) {
			st1.Push(st.top());
			st.pop();
		}
	}
};

int main() {
	StackOfBooks stBooks = { "Theodore Dreiser", "Margaret Mitchell", "Alexandre Dumas", "Erich Maria Remarque" };
	std::cout << stBooks;
	system("pause");

	stBooks.replacement({ "Oscar Wilde", "Conan Doyle", "Ilf and Petrov" });
	std::cout << std::endl;
	std::cout << stBooks;
	system("pause");

	StackOfBooks newStBooks = {"Mark Twain", "Mikhail Bulgakov"};
	stBooks.complete(newStBooks);
	std::cout << std::endl << "The first stack:" << std::endl;
	std::cout << stBooks;
	std::cout << std::endl;
	std::cout << "The second stack:" << std::endl;
	std::cout << newStBooks;
	return 0;
}
