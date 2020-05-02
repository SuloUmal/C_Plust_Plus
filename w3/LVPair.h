#ifndef _SDDS_LVPAIR_H__
#define _SDDS_LVPAIR_H__
#include <cstring>
namespace sdds{
template <typename L, typename V>
class LVPair {
  L mlabel;
  V mvalue;
  public:
  LVPair():
    mlabel(),
    mvalue(){
  }
  LVPair(const L& aa, const V& bb):
   mlabel(aa),
    mvalue(bb){
  }
  const L& key() const{
return mlabel;
  }
  const V& value() const{
return mvalue;
  }
 virtual void display(std::ostream& os) const{
os << key() << " : " << value() <<std::endl;
  }
};

template <typename L, typename V>
class SummableLVPair: public LVPair<L, V>{
static V initialValue;
 static size_t min;
public:
static const V& getInitialValue(){return initialValue;};
SummableLVPair(){};
SummableLVPair(const L& lbl, const V& val):LVPair<L, V>(lbl, val){
if(lbl.size() > min) min = lbl.size();
}
V sum(const L& lbl, const V& val) const{
  return LVPair<L, V>::value() + val;
}

void display(std::ostream& os) const{
	os << std::left;
	os.width(min);
	LVPair<L, V>::display(os);
	os << std::right;
}};
template <typename L, typename V>
size_t SummableLVPair<L, V>::min = 0u;
template<>
std::string SummableLVPair<std::string, std::string>::initialValue = "";

template<>
int SummableLVPair<std::string, int>::initialValue = 0;

template<>
std::string SummableLVPair<std::string, std::string>::sum(const std::string& lbl, const std::string& val) const { 
	return (val == "" ? LVPair<std::string, std::string>::value() : val + ", " + LVPair<std::string, std::string>::value());
}

template <typename L, typename V>
std::ostream& operator<<(std::ostream& os, const sdds::LVPair<L, V>& pair){
  pair.display(os);
  return os;
}
}
#endif