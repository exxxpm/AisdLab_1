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

