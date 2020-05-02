#ifndef _SDDS_LIST_H__
#define _SDDS_LIST_H__
namespace sdds{
template <typename T, unsigned N>
class List{
  T arr[N];
  unsigned int count=0u;
  public:
  size_t size() const{
    return count;
  }
const T& operator[](size_t i) const{
  return arr[i];
}
void operator+=(const T& tt){
if (count < N) arr[count++] = tt;
}
};

template <typename L, typename V, typename T, int N>
class LVList : public List<T, N> {
public:
	V accumulate(const L& label) const { 
	T a_value;
	V accumulated = a_value.SummableLVPair<L, V>::getInitialValue();

		for (size_t i = 0; i < (*this).size(); i++) {
			if (label == (*this)[i].key()) {
				accumulated = (*this)[i].sum(label, accumulated);
			}
		}
		return accumulated;
	}
};
}
#endif