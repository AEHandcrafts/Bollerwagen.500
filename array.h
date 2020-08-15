#ifndef ARRAY_H
#define ARRAY_H

template<typename T, unsigned long S>
class Array {

private:
	T data[S];

public:
	constexpr unsigned long size() const{
		return S;
	}

	T& operator[](unsigned long index){
		return this->data[index];
	}
	
	const T& operator[](unsigned long index) const{
		return this->data[index];
	}

};

#endif