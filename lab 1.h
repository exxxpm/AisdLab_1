#pragma once
#include <random>
#include <time.h>
#include <limits>
using namespace std;

struct image_exception {};

template <typename T>
class Image{
	private:
		int size_x;
		int size_y;
		T** image;
		const double eps = 0.0001;

	public:
		Image(int x, int y, bool flag, T fillValue);
		Image(int x, int y, bool flag);
		T& operator()(int x, int y);
		bool operator==(Image a);
		Image& operator*(const Image& a);
		Image& operator+(const Image& a);
		Image& operator+(const T a);
		Image& operator*(const T a);
		Image& operator!();
		float image_koefficient() const;



		friend std::ostream& operator<<(std::ostream& os, Image<T>& I){
			for (int i = 0; i < I.size_x; i++) {
				for (int j = 0; j < I.size_y; j++) {
					os << I.image[i][j] << " ";
				}
				os << '\n';
			}
			return os;
		}
};

template <typename T>
Image<T>::Image(int x, int y, bool flag, T fillValue){
	image = new T * [x];
	for (int i = 0; i < x; i++){
		image[i] = new T[y];
	}

	size_x = x;
	size_y = y;
	if (flag == true){
		std::random_device rd;
		std::mt19937 gen(rd());
		std::uniform_int_distribution<> dis(std::numeric_limits<T>::min(), std::numeric_limits<T>::max());
		for (int i = 0; i < x; i++){
			for (int j = 0; j < y; j++){
				image[i][j] = dis(gen);
			}
		}
	}else{
		for (int i = 0; i < x; i++){
			for (int j = 0; j < y; j++){
				image[i][j] = fillValue;
			}
		}
	}
}


Image<bool>::Image(int x, int y, bool flag){
	image = new bool* [x];
	for (int i = 0; i < x; i++){
		image[i] = new bool[y];
	}

	size_x = x;
	size_y = y;
	if (flag == true){
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				image[i][j] = rand() % 2;
			}
		}
	}else{
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				image[i][j] = 0;
			}
		}
	}
}


template <typename T>
Image<T>::Image(int x, int y, bool flag){
	image = new T * [x];
	for (int i = 0; i < x; i++){
		image[i] = new T[y];
	}

	size_x = x;
	size_y = y;
	if (flag == true){
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				image[i][j] = rand();
			}
		}
	}else{
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				image[i][j] = 0;
			}
		}
	}
}


template <typename T>
T& Image<T>::operator()(int x, int y){
	return image[x][y];
}
