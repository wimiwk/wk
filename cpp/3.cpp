#include <iostream>
#include <regex>
#include <string>
using namespace std;
class pipei {
 public:
  pipei(const string& input)
      : input_(input), pattern_("\\((\\d+)\\)\\s+([^|]+)") {}
      
  void Extract() const {
    smatch match;
    string::const_iterator searchStart(input_.cbegin());
    while (regex_search(searchStart, input_.cend(), match, pattern_)) {
      cout << "代码: " << match[1] << ", 名称: " << match[2] << endl;
      searchStart = match.suffix().first;
    }
  }

 private:
  const string& input_;
  const regex pattern_;
};

int main() {
  string input = "...|(600100) 上海银行|(600111) 中远海运|（613500）北京城建|(600100) 上海银行|(600111) 中远海运|（613500）北京城建|(600100) 上海银行|(600111) 中远海运|（613500）北京城建|...";
  pipei extractor(input);
  extractor.Extract();
  return 0;
}