#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <iostream>
#include <stdexcept>
using namespace std;
namespace sdds
{
	template<typename T>
	class Collection
	{
	private:
		string collectionName;
		T* collectionPtr = nullptr;
		size_t sizec = 0u;
		void (*ptrFunc)(const Collection<T>& col, const T& obj) = nullptr;
	public:
		Collection() {};
		Collection(string name) : collectionName{ name } {};
		Collection(const Collection&) = delete;
		Collection& operator=(const Collection&) = delete;
		virtual ~Collection()
		{
			delete[]collectionPtr;
			collectionPtr = nullptr;
		}
		const string& name() const { return collectionName; };
		size_t size() const { return sizec; };

		void setObserver(void(*observer)(const Collection<T>&, const T&))
		{
			ptrFunc = observer;
		}

		Collection<T>& operator+=(const T& item)
		{
			bool unique = true;
			for (int i = 0; i < sizec && unique; i++) {
				if (collectionPtr != nullptr && collectionPtr[i].title() == item.title()) {
					unique = false;
				}
			}
			if (unique) {
				T* temp = new T[sizec + 1];
				for (int i = 0; i < sizec; ++i) {
					temp[i] = collectionPtr[i];
				}
				temp[sizec] = item;

				delete[]collectionPtr;
				collectionPtr = temp;
				sizec++;

				if (ptrFunc != nullptr) {
					ptrFunc(*this, collectionPtr[sizec - 1]);
				}
			}
			return *this;
		}
		T& operator[](size_t idx) const {
			if (idx >= sizec) {
				std::string msg = "Bad index [";
				msg += std::to_string(idx);
				msg += "]. Collection has [";
				msg += std::to_string(sizec);
				msg += "] items.";
				throw std::out_of_range(msg);
			}
			return collectionPtr[idx];
		}
		T* operator[](std::string title) const {
			bool find = false;
			int num = 0;
			for (int i  = 0; i < sizec && (!find); i++) {
				if (collectionPtr[i].title() == title) {
					find = true;
					num = i;
				}
			}
			return find ? &(collectionPtr[num]) : nullptr;
		}
	};
	template<typename T>
	std::ostream& operator<<(std::ostream& os, const Collection<T>& col) {
		for (int i = 0; i < col.size(); i++) {
			os << col[i];
		}
		return os;
	};
}

#endif