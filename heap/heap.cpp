#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

template <typename T>
struct less : binary_function <T, T, bool>{
	bool operator()(const T& first, const T& second) const {
		return first < second;
	}
};
template <typename T>
struct greater: binary_function <T, T, bool> {
	bool operator()(const T& first, const T& second) const {
		return first > second;
	}
};

template <typename T, typename compare = greater<T>>
class heap {
private:
	int cnt;
	T arr[100];
public:
	heap() :cnt(0) {
		// 쓰레기값 보기 싫어서 초기화시킴
		//arr[0] = 0;
	}
	void insert_node(T data) {
		cnt++;
		int index = cnt;
		while (arr[index / 2] < data && index != 1) {
			arr[index] = arr[index / 2];
			index /= 2;
		}
		arr[index] = data;
	}
	void delete_node() {
		int parent = 1, child = parent * 2;
		swap(arr[parent], arr[cnt--]);

		while (child <= cnt) {
			// 오른쪽 자식노드가 더 클 때 오른쪽 자식노드로 이동
			if (child < cnt && arr[child] < arr[child + 1]) {
				child = child + 1;
			}
			if (arr[child] < arr[parent]) break;

			swap(arr[child], arr[parent]);
			parent = child;
			child = parent * 2;
		}
	}

	void sort() {
		int index = cnt;

		for (int i = 0; i < cnt; i++) {
			int parent = 1, child = parent * 2;

			swap(arr[parent], arr[index--]);
			while (child <= index) {
				if (child < index && arr[child] < arr[child + 1]) {
					child = child + 1;
				}
				if (arr[child] < arr[parent]) break;

				swap(arr[child], arr[parent]);
				parent = child;
				child = parent * 2;
			}
		}
	}
};

int main() {
	heap<string, greater<string>> h;
	h.insert_node("apple");
	h.insert_node("elephant");
	h.insert_node("donut");
	h.insert_node("banana");
	h.insert_node("candy");
	h.insert_node("zibra");
	h.insert_node("kfc");
	h.sort();
}
