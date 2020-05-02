#ifndef SDDS__TEXT_
#define SDDS__TEXT_
namespace sdds{

  class Text{
    std::string* line;
     int n = 0;

    public:
    Text();
    Text(const std::string& filename);
    Text(const Text& obj);
    Text(Text&&);
    Text& operator=(Text&&);
    Text& operator=(const Text& obj);
    virtual ~Text();
    size_t size() const;
  };
}
#endif