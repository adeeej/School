#include "vector.h"
#include "../common/utils.h"
#include <cstdlib>
#include <cstring>

namespace structures
{
	Vector::Vector(size_t size) :
		memory_(std::calloc(size, 1)),
		size_(size)
	{	
	}

	Vector::Vector(Vector& other) :
		Vector(other.size_)
	{
		//kopirovaci konstruktor, vytvori sa druhy vektor uplne rovnaky na inej pamati
		memcpy(memory_, other.memory_, size_);
	}

	Vector::~Vector()
	{
		free(memory_);
		memory_ = nullptr;
		size_ = 0;
	}

	size_t Vector::size()
	{
		return size_;
	}

	Structure& Vector::assign(Structure& other)
	{
		//do vektora priradim hodnoty z ineho vektora
		if (this != &other) { //ked nie su rovnake robim if
			Vector& otherVector = dynamic_cast<Vector&>(other);
			size_ = otherVector.size_;
			memory_ = realloc(memory_, size_);
			memcpy(memory_, otherVector.memory_, size_);
		}

		return *this;
	}

	bool Vector::equals(Structure& other)
	{
		//ak maju rovnake prvky a velkost
		if (this == &other) {
			return true;
		}
		else
		{
			Vector* otherVector = dynamic_cast<Vector*>(&other);
			if (otherVector != nullptr) {
				return size_ == otherVector->size_ && memcmp(memory_, otherVector->memory_, size_) == 0;
			}
			else {
				return false;
			}
		}
	}

	byte& Vector::operator[](int index)
	{
		return at(index);
	}

	byte& Vector::at(int index)
	{
		return *getBytePointer(index);
	}

	void Vector::copy(Vector& src, int srcStartIndex, Vector& dest, int destStartIndex, int length)
	{
		// pomocou Utils::rangeChechExcept skontrolovat:
		Utils::rangeCheckExcept(srcStartIndex, src.size_, "Invalid srcStartIndex!");
		Utils::rangeCheckExcept(srcStartIndex + length, src.size_ + 1, "Invalid srcStartIndex + length!");
		Utils::rangeCheckExcept(destStartIndex, dest.size_, "Invalid destStartIndex!");
		Utils::rangeCheckExcept(destStartIndex + length, dest.size_ + 1, "Invalid destStartIndex + length!");

		if (&src == &dest && abs(srcStartIndex - destStartIndex) < length)
		{
			memmove(dest.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
		}
		else
		{
			memcpy(dest.getBytePointer(destStartIndex), src.getBytePointer(srcStartIndex), length);
		}
		// srcStartIndex patri do <0, src.size_)
		// srcStartIndex + length patri do <0, src.size_>
		// destStartIndex patri do <0, dest.size_)
		// destStartIndex + length patri do <0, dest.size_>

		// ak su src a dest IDENTICKE a zaroven je vzdialenost medzi srcStartIndex a destSrcIndex mensia ako length
		// tak: memmove
		// inak: memcpy
	}

	byte* Vector::getBytePointer(int index)
	{
		//memory_t je typu void* a ten sa nedokaze posuvat
		Utils::rangeCheckExcept(index, size_, "Invalid index!");
		return reinterpret_cast<byte*>(memory_) + index;
	}
}