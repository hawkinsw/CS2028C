#include <iostream>
#include <cassert>
#include "include/stack.hpp"

int main() {
	Stack<int> st{};


	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	st.pop();
	st.pop();
	st.pop();
	st.pop();

	st.push(8);
	st.push(9);
	st.push(10);
	st.push(11);
	st.push(12);

	assert(12 == st.pop());
	assert(11 == st.pop());
	assert(10 == st.pop());
	assert(9 == st.pop());
	assert(8 == st.pop());

	// This should cause an exception!
	assert(8 == st.pop());

	return 0;
}
