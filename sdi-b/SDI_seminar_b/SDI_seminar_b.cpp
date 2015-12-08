// SDI_seminar_b.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DynArray.h"
#include <vector>


using std::cout;
using std::endl;


void eat_memory();


int main(int argc, char* argv[])
{
	DynArray<int> arr(3);

	cout << "Pushing initial data\n";
	arr.push_back(99);
	arr.push_back(17);
	arr.push_back(47);

	cout << "\nElements after push 99, 17 and 47:\n";
	cout << arr.get(0) << endl;
	cout << arr.get(1) << endl;
	cout << arr.get(2) << endl;
	cout << "Size: " << arr.size() << " Capacity: " << arr.capacity() << endl;

	cout << "\nPushing to trigger auto-expand. Expected new capacity: 4\n";
	arr.push_back(115);

	cout << "\nElements after push:\n";
	cout << arr.get(0) << endl;
	cout << arr.get(1) << endl;
	cout << arr.get(2) << endl;
	cout << arr.get(3) << endl;
	cout << "Size: " << arr.size() << " Capacity: " << arr.capacity() << endl;

	cout << "\nPopping 2 items\n";
	arr.pop_back();
	arr.pop_back();

	cout << "\nElements after pop:\n";
	cout << arr.get(0) << endl;
	cout << arr.get(1) << endl;
	cout << "Size: " << arr.size() << " Capacity: " << arr.capacity() << endl;

	cout << "\nPushing a few more items...\n";
	arr.push_back(115);
	arr.push_back(62);
	arr.push_back(36);
	arr.push_back(747);
	arr.push_back(86);
	arr.push_back(35);
	arr.push_back(32);
	arr.push_back(435);
	arr.push_back(67);
	arr.push_back(256);
	arr.push_back(548);

	cout << "Size: " << arr.size() << " Capacity: " << arr.capacity() << endl;

	cout << "\nEmptying array.\n";
	arr.clear();
	cout << "Calling arr.empty(), answer: " << arr.empty() << endl;
	cout << "Size: " << arr.size() << " Capacity: " << arr.capacity() << endl;

	cout << "\nResizing array for next set of tests.\n";
	arr.resize(4);
	cout << "Size: " << arr.size() << " Capacity: " << arr.capacity() << endl;

	cout << "\nNow testing set, insert and erase\n" << endl;

	arr.push_back(115);
	arr.push_back(62);
	arr.push_back(36);
	arr.push_back(747);

	cout << "\nElements after push:\n";
	cout << arr.get(0) << endl;
	cout << arr.get(1) << endl;
	cout << arr.get(2) << endl;
	cout << arr.get(3) << endl;
	cout << "Size: " << arr.size() << " Capacity: " << arr.capacity() << endl;

	arr.set(187, 2);

	cout << "\nElements after set idx 2 to 187:\n";
	cout << arr.get(0) << endl;
	cout << arr.get(1) << endl;
	cout << arr.get(2) << endl;
	cout << arr.get(3) << endl;
	cout << "Size: " << arr.size() << " Capacity: " << arr.capacity() << endl;

	arr.insert(99, 3);

	cout << "\nElements after insert 99 at 3:\n";
	cout << arr.get(0) << endl;
	cout << arr.get(1) << endl;
	cout << arr.get(2) << endl;
	cout << arr.get(3) << endl;
	cout << arr.get(4) << endl;
	cout << "Size: " << arr.size() << " Capacity: " << arr.capacity() << endl;

	arr.erase(2);

	cout << "\nElements after erase 2:\n";
	cout << arr.get(0) << endl;
	cout << arr.get(1) << endl;
	cout << arr.get(2) << endl;
	cout << arr.get(3) << endl;
	cout << "Size: " << arr.size() << " Capacity: " << arr.capacity() << endl;

	cout << arr << endl;
	DynArray<int> arr2(3);
	arr2.push_back(32);
	arr2.push_back(435);
	arr2.push_back(67);
	cout << arr2 << endl;

	arr += arr2;

	cout << arr << endl;

	cout << "idx 3: " << arr[3] << endl;

	arr += 86;

	cout << "after += 86, and inline += 5: " << (arr += 5) << endl;

	cout << "Using default value fill constructor params (10, 8.8):\n";

	DynArray<double> arr3(10, 8.8);
	cout << arr3 << endl;

	cout << "Using raw array constructor with character code array [1, 2, 3, 4, 5]\n";

	char raw[5] = {1, 2, 3, 4, 5};
	DynArray<char> arr4(raw, 5);

	cout << arr4 << endl;

	/*
		Memory leak test
	*/

	cout << "\nMemory leak test. Enter some input to start and watch the process memory usage\n";
	getchar();

	for(int i = 0; i < 1000; ++i)
	{
		eat_memory();

		printf("Allocation number %d ", i);

		for (int i = 0; i < rand() * 0.04; ++i)
			printf(" ");

		printf("nom\n");
	}

	cout << "\nTests complete! Press any key to close.\n";

	getchar();

	return 0;
}

void eat_memory()
{
	DynArray<int> arr(4);
}
