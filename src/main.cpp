#include <ctime>
#include <iostream>
#include <string>
#include <vector>

#include <colorize/color.hpp>

int main() {
  struct Data {
    enum class Type { Nothing = 0, Minute, Rest, Hour, To, Past, Am, Pm };

    std::string text;
    bool highlight = false;
    Type type = Type::Nothing;
    uint8_t value = 0;
    uint8_t alt = 0;
  };

  // clang-format off
  const std::vector<Data> words{
    {".", false, Data::Type::Rest}, {"         ", false}, {".", false, Data::Type::Rest}, {"\n"},
    {"IT", true}, {"L"}, {"IS", true}, {"AS"}, {"AM", false, Data::Type::Am}, {"PM", false, Data::Type::Pm}, {"\n"},
    {"A", false, Data::Type::Minute, 15}, {"C"}, {"QUARTER", false, Data::Type::Minute, 15}, {"DC"}, {"\n"},
    {"TWENTY", false, Data::Type::Minute, 20, 25}, {"FIVE", false, Data::Type::Minute, 5, 25}, {"X"}, {"\n"},
    {"HALF", false, Data::Type::Minute, 30}, {"S"}, {"TEN", false, Data::Type::Minute, 10}, {"F"}, {"T0", false, Data::Type::To}, {"\n"},
    {"PAST", false, Data::Type::Past}, {"ERU"}, {"NINE", false, Data::Type::Hour, 9}, {"\n"},
    {"0NE", false, Data::Type::Hour, 1}, {"SIX", false, Data::Type::Hour, 6}, {"THREE", false, Data::Type::Hour, 3}, {"\n"},
    {"FOUR", false, Data::Type::Hour, 4}, {"FIVE", false, Data::Type::Hour, 5}, {"TWO", false, Data::Type::Hour, 2}, {"\n"},
    {"EIGHT", false, Data::Type::Hour, 8}, {"ELEVEN", false, Data::Type::Hour, 11}, {"\n"},
    {"SEVEN", false, Data::Type::Hour, 7}, {"TWELVE", false, Data::Type::Hour, 12}, {"\n"},
    {"TEN", false, Data::Type::Hour, 10}, {"SE"}, {"0CLOCK", false, Data::Type::Minute, 0}, {"\n"},
    {".", false, Data::Type::Rest}, {"         ", false}, {".", false, Data::Type::Rest}, {"\n"},
  };
  // clang-format on

  auto time = std::time(0);
  auto now = std::localtime(&time);

  auto past = now->tm_min < 35;
  auto hour = (now->tm_hour % 12) + (past ? 0 : 1);
  auto min = abs((past ? 0 : 60) - (now->tm_min - now->tm_min % 5));
  auto rest = now->tm_min % 5;

  std::cout << "past " << past << " hour " << hour << " min " << min << " rest " << rest << std::endl;

  for (const auto& word : words) {
    for (size_t i = 0; i < word.text.size(); ++i) {
      bool highlight = word.highlight || (word.type == Data::Type::Hour && word.value == hour) ||
                       (word.type == Data::Type::Minute && (word.value == min || word.alt == min)) ||
                       (word.type == (past ? Data::Type::Past : Data::Type::To) && min != 0) ||
                       (word.type == Data::Type::Rest && rest-- > 0);

      std::cout << " "
                << color::rize(std::string() + word.text[i], highlight ? "White" : "Black", "Default",
                               highlight ? "Bold" : "Dim");
    }
  }

  return 0;
}
